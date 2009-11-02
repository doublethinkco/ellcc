//===--- Lexer.cpp - C Language Family Lexer ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file implements the Lexer and Token interfaces.
//
//===----------------------------------------------------------------------===//
//
// TODO: GCC Diagnostics emitted by the lexer:
// PEDWARN: (form feed|vertical tab) in preprocessing directive
//
// Universal characters, unicode, char mapping:
// WARNING: `%.*s' is not in NFKC
// WARNING: `%.*s' is not in NFC
//
// Other:
// TODO: Options to support:
//    -fexec-charset,-fwide-exec-charset
//
//===----------------------------------------------------------------------===//

#include "Lexer.h"
#include "Preprocessor.h"
#include "LexDiagnostic.h"
#include "SourceManager.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/MemoryBuffer.h"
#include <cctype>
using namespace ellcc;

static void InitCharacterInfo();

//===----------------------------------------------------------------------===//
// Lexer Class Implementation
//===----------------------------------------------------------------------===//

void Lexer::InitLexer(const char *BufStart, const char *BufPtr, 
                      const char *BufEnd) {
  InitCharacterInfo();
  
  BufferStart = BufStart;
  BufferPtr = BufPtr;
  BufferEnd = BufEnd;
  
  assert(BufEnd[0] == 0 &&
         "We assume that the input buffer has a null character at the end"
         " to simplify lexing!");
  
  Is_PragmaLexer = false;

  // Start of the file is a start of line.
  IsAtStartOfLine = true;
  
  // We are not after parsing a #.
  ParsingPreprocessorDirective = false;
  
  // We are not after parsing #include.
  ParsingFilename = false;
  
  // We are not in raw mode.  Raw mode disables diagnostics and interpretation
  // of tokens (e.g. identifiers, thus disabling macro expansion).  It is used
  // to quickly lex the tokens of the buffer, e.g. when handling a "#if 0" block
  // or otherwise skipping over tokens.
  LexingRawMode = false;
  
  // Default to not keeping comments.
  ExtendedTokenMode = 0;
}

/// Lexer constructor - Create a new lexer object for the specified buffer
/// with the specified preprocessor managing the lexing process.  This lexer
/// assumes that the associated file buffer and Preprocessor objects will
/// outlive it, so it doesn't take ownership of either of them.
Lexer::Lexer(FileID FID, Preprocessor &PP)
  : PreprocessorLexer(&PP, FID),
    FileLoc(PP.getSourceManager().getLocForStartOfFile(FID)),
    Features(PP.getLangOptions()) {
  
  const llvm::MemoryBuffer *InputFile = PP.getSourceManager().getBuffer(FID);
  
  InitLexer(InputFile->getBufferStart(), InputFile->getBufferStart(),
            InputFile->getBufferEnd());
  
  // Default to keeping comments if the preprocessor wants them.
  SetCommentRetentionState(PP.getCommentRetentionState());
}

/// Lexer constructor - Create a new raw lexer object.  This object is only
/// suitable for calls to 'LexRawToken'.  This lexer assumes that the text
/// range will outlive it, so it doesn't take ownership of it.
Lexer::Lexer(SourceLocation fileloc, const LangOptions &features,
             const char *BufStart, const char *BufPtr, const char *BufEnd)
  : FileLoc(fileloc), Features(features) {

  InitLexer(BufStart, BufPtr, BufEnd);
  
  // We *are* in raw mode.
  LexingRawMode = true;
}

/// Lexer constructor - Create a new raw lexer object.  This object is only
/// suitable for calls to 'LexRawToken'.  This lexer assumes that the text
/// range will outlive it, so it doesn't take ownership of it.
Lexer::Lexer(FileID FID, const SourceManager &SM, const LangOptions &features)
  : FileLoc(SM.getLocForStartOfFile(FID)), Features(features) {
  const llvm::MemoryBuffer *FromFile = SM.getBuffer(FID);

  InitLexer(FromFile->getBufferStart(), FromFile->getBufferStart(), 
            FromFile->getBufferEnd());
  
  // We *are* in raw mode.
  LexingRawMode = true;
}

/// Create_PragmaLexer: Lexer constructor - Create a new lexer object for
/// _Pragma expansion.  This has a variety of magic semantics that this method
/// sets up.  It returns a new'd Lexer that must be delete'd when done.
///
/// On entrance to this routine, TokStartLoc is a macro location which has a
/// spelling loc that indicates the bytes to be lexed for the token and an
/// instantiation location that indicates where all lexed tokens should be
/// "expanded from".
///
/// FIXME: It would really be nice to make _Pragma just be a wrapper around a
/// normal lexer that remaps tokens as they fly by.  This would require making
/// Preprocessor::Lex virtual.  Given that, we could just dump in a magic lexer
/// interface that could handle this stuff.  This would pull GetMappedTokenLoc
/// out of the critical path of the lexer!
///
Lexer *Lexer::Create_PragmaLexer(SourceLocation SpellingLoc, 
                                 SourceLocation InstantiationLocStart,
                                 SourceLocation InstantiationLocEnd,
                                 unsigned TokLen, Preprocessor &PP) {
  SourceManager &SM = PP.getSourceManager();

  // Create the lexer as if we were going to lex the file normally.
  FileID SpellingFID = SM.getFileID(SpellingLoc);
  Lexer *L = new Lexer(SpellingFID, PP);
  
  // Now that the lexer is created, change the start/end locations so that we
  // just lex the subsection of the file that we want.  This is lexing from a
  // scratch buffer.
  const char *StrData = SM.getCharacterData(SpellingLoc);
  
  L->BufferPtr = StrData;
  L->BufferEnd = StrData+TokLen;
  assert(L->BufferEnd[0] == 0 && "Buffer is not nul terminated!");

  // Set the SourceLocation with the remapping information.  This ensures that
  // GetMappedTokenLoc will remap the tokens as they are lexed.
  L->FileLoc = SM.createInstantiationLoc(SM.getLocForStartOfFile(SpellingFID),
                                         InstantiationLocStart,
                                         InstantiationLocEnd, TokLen);
  
  // Ensure that the lexer thinks it is inside a directive, so that end \n will
  // return an EOM token.
  L->ParsingPreprocessorDirective = true;
  
  // This lexer really is for _Pragma.
  L->Is_PragmaLexer = true;
  return L;
}


/// Stringify - Convert the specified string into a C string, with surrounding
/// ""'s, and with escaped \ and " characters.
std::string Lexer::Stringify(const std::string &Str, bool Charify) {
  std::string Result = Str;
  char Quote = Charify ? '\'' : '"';
  for (unsigned i = 0, e = Result.size(); i != e; ++i) {
    if (Result[i] == '\\' || Result[i] == Quote) {
      Result.insert(Result.begin()+i, '\\');
      ++i; ++e;
    }
  }
  return Result;
}

/// Stringify - Convert the specified string into a C string by escaping '\'
/// and " characters.  This does not add surrounding ""'s to the string.
void Lexer::Stringify(llvm::SmallVectorImpl<char> &Str) {
  for (unsigned i = 0, e = Str.size(); i != e; ++i) {
    if (Str[i] == '\\' || Str[i] == '"') {
      Str.insert(Str.begin()+i, '\\');
      ++i; ++e;
    }
  }
}


/// MeasureTokenLength - Relex the token at the specified location and return
/// its length in bytes in the input file.  If the token needs cleaning (e.g.
/// includes a trigraph or an escaped newline) then this count includes bytes
/// that are part of that.
unsigned Lexer::MeasureTokenLength(SourceLocation Loc,
                                   const SourceManager &SM,
                                   const LangOptions &LangOpts) {
  // TODO: this could be special cased for common tokens like identifiers, ')',
  // etc to make this faster, if it mattered.  Just look at StrData[0] to handle
  // all obviously single-char tokens.  This could use 
  // Lexer::isObviouslySimpleCharacter for example to handle identifiers or
  // something.

  // If this comes from a macro expansion, we really do want the macro name, not
  // the token this macro expanded to.
  Loc = SM.getInstantiationLoc(Loc);
  std::pair<FileID, unsigned> LocInfo = SM.getDecomposedLoc(Loc);
  std::pair<const char *,const char *> Buffer = SM.getBufferData(LocInfo.first);
  const char *StrData = Buffer.first+LocInfo.second;

  // Create a lexer starting at the beginning of this token.
  Lexer TheLexer(Loc, LangOpts, Buffer.first, StrData, Buffer.second);
  Token TheTok;
  TheLexer.LexFromRawLexer(TheTok);
  return TheTok.getLength();
}

//===----------------------------------------------------------------------===//
// Character information.
//===----------------------------------------------------------------------===//

static unsigned char CharInfo[256];

enum {
  CHAR_HORZ_WS  = 0x01,  // ' ', '\t', '\f', '\v'.  Note, no '\0'
  CHAR_VERT_WS  = 0x02,  // '\r', '\n'
  CHAR_LETTER   = 0x04,  // a-z,A-Z
  CHAR_NUMBER   = 0x08,  // 0-9
  CHAR_UNDER    = 0x10,  // _
  CHAR_PERIOD   = 0x20   // .
};

static void InitCharacterInfo() {
  static bool isInited = false;
  if (isInited) return;
  isInited = true;
  
  // Intiialize the CharInfo table.
  // TODO: statically initialize this.
  CharInfo[(int)' '] = CharInfo[(int)'\t'] = 
  CharInfo[(int)'\f'] = CharInfo[(int)'\v'] = CHAR_HORZ_WS;
  CharInfo[(int)'\n'] = CharInfo[(int)'\r'] = CHAR_VERT_WS;
  
  CharInfo[(int)'_'] = CHAR_UNDER;
  CharInfo[(int)'.'] = CHAR_PERIOD;
  for (unsigned i = 'a'; i <= 'z'; ++i)
    CharInfo[i] = CharInfo[i+'A'-'a'] = CHAR_LETTER;
  for (unsigned i = '0'; i <= '9'; ++i)
    CharInfo[i] = CHAR_NUMBER;
}

/// isIdentifierBody - Return true if this is the body character of an
/// identifier, which is [a-zA-Z0-9_].
static inline bool isIdentifierBody(unsigned char c) {
  return (CharInfo[c] & (CHAR_LETTER|CHAR_NUMBER|CHAR_UNDER)) ? true : false;
}

/// isHorizontalWhitespace - Return true if this character is horizontal
/// whitespace: ' ', '\t', '\f', '\v'.  Note that this returns false for '\0'.
static inline bool isHorizontalWhitespace(unsigned char c) {
  return (CharInfo[c] & CHAR_HORZ_WS) ? true : false;
}

/// isWhitespace - Return true if this character is horizontal or vertical
/// whitespace: ' ', '\t', '\f', '\v', '\n', '\r'.  Note that this returns false
/// for '\0'.
static inline bool isWhitespace(unsigned char c) {
  return (CharInfo[c] & (CHAR_HORZ_WS|CHAR_VERT_WS)) ? true : false;
}

/// isNumberBody - Return true if this is the body character of an
/// preprocessing number, which is [a-zA-Z0-9_.].
static inline bool isNumberBody(unsigned char c) {
  return (CharInfo[c] & (CHAR_LETTER|CHAR_NUMBER|CHAR_UNDER|CHAR_PERIOD)) ? 
    true : false;
}


//===----------------------------------------------------------------------===//
// Diagnostics forwarding code.
//===----------------------------------------------------------------------===//

/// GetMappedTokenLoc - If lexing out of a 'mapped buffer', where we pretend the
/// lexer buffer was all instantiated at a single point, perform the mapping.
/// This is currently only used for _Pragma implementation, so it is the slow
/// path of the hot getSourceLocation method.  Do not allow it to be inlined.
static SourceLocation GetMappedTokenLoc(Preprocessor &PP,
                                        SourceLocation FileLoc,
                                        unsigned CharNo,
                                        unsigned TokLen) DISABLE_INLINE;
static SourceLocation GetMappedTokenLoc(Preprocessor &PP,
                                        SourceLocation FileLoc,
                                        unsigned CharNo, unsigned TokLen) {
  assert(FileLoc.isMacroID() && "Must be an instantiation");
  
  // Otherwise, we're lexing "mapped tokens".  This is used for things like
  // _Pragma handling.  Combine the instantiation location of FileLoc with the
  // spelling location.
  SourceManager &SM = PP.getSourceManager();
  
  // Create a new SLoc which is expanded from Instantiation(FileLoc) but whose
  // characters come from spelling(FileLoc)+Offset.
  SourceLocation SpellingLoc = SM.getSpellingLoc(FileLoc);
  SpellingLoc = SpellingLoc.getFileLocWithOffset(CharNo);
  
  // Figure out the expansion loc range, which is the range covered by the
  // original _Pragma(...) sequence.
  std::pair<SourceLocation,SourceLocation> II =
    SM.getImmediateInstantiationRange(FileLoc);
  
  return SM.createInstantiationLoc(SpellingLoc, II.first, II.second, TokLen);
}

/// getSourceLocation - Return a source location identifier for the specified
/// offset in the current file.
SourceLocation Lexer::getSourceLocation(const char *Loc,
                                        unsigned TokLen) const {
  assert(Loc >= BufferStart && Loc <= BufferEnd &&
         "Location out of range for this buffer!");

  // In the normal case, we're just lexing from a simple file buffer, return
  // the file id from FileLoc with the offset specified.
  unsigned CharNo = Loc-BufferStart;
  if (FileLoc.isFileID())
    return FileLoc.getFileLocWithOffset(CharNo);
  
  // Otherwise, this is the _Pragma lexer case, which pretends that all of the
  // tokens are lexed from where the _Pragma was defined.
  assert(PP && "This doesn't work on raw lexers");
  return GetMappedTokenLoc(*PP, FileLoc, CharNo, TokLen);
}

/// Diag - Forwarding function for diagnostics.  This translate a source
/// position in the current buffer into a SourceLocation object for rendering.
DiagnosticBuilder Lexer::Diag(const char *Loc, unsigned DiagID) const {
  return PP->Diag(getSourceLocation(Loc), DiagID);
}

//===----------------------------------------------------------------------===//
// Trigraph and Escaped Newline Handling Code.
//===----------------------------------------------------------------------===//

/// GetTrigraphCharForLetter - Given a character that occurs after a ?? pair,
/// return the decoded trigraph letter it corresponds to, or '\0' if nothing.
static char GetTrigraphCharForLetter(char Letter) {
  switch (Letter) {
  default:   return 0;
  case '=':  return '#';
  case ')':  return ']';
  case '(':  return '[';
  case '!':  return '|';
  case '\'': return '^';
  case '>':  return '}';
  case '/':  return '\\';
  case '<':  return '{';
  case '-':  return '~';
  }
}

/// DecodeTrigraphChar - If the specified character is a legal trigraph when
/// prefixed with ??, emit a trigraph warning.  If trigraphs are enabled,
/// return the result character.  Finally, emit a warning about trigraph use
/// whether trigraphs are enabled or not.
static char DecodeTrigraphChar(const char *CP, Lexer *L) {
  char Res = GetTrigraphCharForLetter(*CP);
  if (!Res || !L) return Res;
  
  if (!L->getFeatures().Trigraphs) {
    if (!L->isLexingRawMode())
      L->Diag(CP-2, diag::trigraph_ignored);
    return 0;
  }
    
  if (!L->isLexingRawMode())
    L->Diag(CP-2, diag::trigraph_converted) << std::string()+Res;
  return Res;
}

/// getEscapedNewLineSize - Return the size of the specified escaped newline,
/// or 0 if it is not an escaped newline. P[-1] is known to be a "\" or a
/// trigraph equivalent on entry to this function.  
unsigned Lexer::getEscapedNewLineSize(const char *Ptr) {
  unsigned Size = 0;
  while (isWhitespace(Ptr[Size])) {
    ++Size;
    
    if (Ptr[Size-1] != '\n' && Ptr[Size-1] != '\r')
      continue;

    // If this is a \r\n or \n\r, skip the other half.
    if ((Ptr[Size] == '\r' || Ptr[Size] == '\n') &&
        Ptr[Size-1] != Ptr[Size])
      ++Size;
      
    return Size;
  } 
  
  // Not an escaped newline, must be a \t or something else.
  return 0;
}

/// SkipEscapedNewLines - If P points to an escaped newline (or a series of
/// them), skip over them and return the first non-escaped-newline found,
/// otherwise return P.
const char *Lexer::SkipEscapedNewLines(const char *P) {
  while (1) {
    const char *AfterEscape;
    if (*P == '\\') {
      AfterEscape = P+1;
    } else if (*P == '?') {
      // If not a trigraph for escape, bail out.
      if (P[1] != '?' || P[2] != '/')
        return P;
      AfterEscape = P+3;
    } else {
      return P;
    }
    
    unsigned NewLineSize = Lexer::getEscapedNewLineSize(AfterEscape);
    if (NewLineSize == 0) return P;
    P = AfterEscape+NewLineSize;
  }
}


/// getCharAndSizeSlow - Peek a single 'character' from the specified buffer,
/// get its size, and return it.  This is tricky in several cases:
///   1. If currently at the start of a trigraph, we warn about the trigraph,
///      then either return the trigraph (skipping 3 chars) or the '?',
///      depending on whether trigraphs are enabled or not.
///   2. If this is an escaped newline (potentially with whitespace between
///      the backslash and newline), implicitly skip the newline and return
///      the char after it.
///   3. If this is a UCN, return it.  FIXME: C++ UCN's?
///
/// This handles the slow/uncommon case of the getCharAndSize method.  Here we
/// know that we can accumulate into Size, and that we have already incremented
/// Ptr by Size bytes.
///
/// NOTE: When this method is updated, getCharAndSizeSlowNoWarn (below) should
/// be updated to match.
///
char Lexer::getCharAndSizeSlow(const char *Ptr, unsigned &Size,
                               Token *Tok) {
  // If we have a slash, look for an escaped newline.
  if (Ptr[0] == '\\') {
    ++Size;
    ++Ptr;
Slash:
    // Common case, backslash-char where the char is not whitespace.
    if (!isWhitespace(Ptr[0])) return '\\';
    
    // See if we have optional whitespace characters followed by a newline.
    if (unsigned EscapedNewLineSize = getEscapedNewLineSize(Ptr)) {
      // Remember that this token needs to be cleaned.
      if (Tok) Tok->setFlag(Token::NeedsCleaning);

      // Warn if there was whitespace between the backslash and newline.
      if (EscapedNewLineSize != 1 && Tok && !isLexingRawMode())
        Diag(Ptr, diag::backslash_newline_space);
        
      // Found backslash<whitespace><newline>.  Parse the char after it.
      Size += EscapedNewLineSize;
      Ptr  += EscapedNewLineSize;
      // Use slow version to accumulate a correct size field.
      return getCharAndSizeSlow(Ptr, Size, Tok);
    }
      
    // Otherwise, this is not an escaped newline, just return the slash.
    return '\\';
  }
  
  // If this is a trigraph, process it.
  if (Ptr[0] == '?' && Ptr[1] == '?') {
    // If this is actually a legal trigraph (not something like "??x"), emit
    // a trigraph warning.  If so, and if trigraphs are enabled, return it.
    if (char C = DecodeTrigraphChar(Ptr+2, Tok ? this : 0)) {
      // Remember that this token needs to be cleaned.
      if (Tok) Tok->setFlag(Token::NeedsCleaning);

      Ptr += 3;
      Size += 3;
      if (C == '\\') goto Slash;
      return C;
    }
  }
  
  // If this is neither, return a single character.
  ++Size;
  return *Ptr;
}


/// getCharAndSizeSlowNoWarn - Handle the slow/uncommon case of the
/// getCharAndSizeNoWarn method.  Here we know that we can accumulate into Size,
/// and that we have already incremented Ptr by Size bytes.
///
/// NOTE: When this method is updated, getCharAndSizeSlow (above) should
/// be updated to match.
char Lexer::getCharAndSizeSlowNoWarn(const char *Ptr, unsigned &Size,
                                     const LangOptions &Features) {
  // If we have a slash, look for an escaped newline.
  if (Ptr[0] == '\\') {
    ++Size;
    ++Ptr;
Slash:
    // Common case, backslash-char where the char is not whitespace.
    if (!isWhitespace(Ptr[0])) return '\\';
    
    // See if we have optional whitespace characters followed by a newline.
    if (unsigned EscapedNewLineSize = getEscapedNewLineSize(Ptr)) {
      // Found backslash<whitespace><newline>.  Parse the char after it.
      Size += EscapedNewLineSize;
      Ptr  += EscapedNewLineSize;
      
      // Use slow version to accumulate a correct size field.
      return getCharAndSizeSlowNoWarn(Ptr, Size, Features);
    }
    
    // Otherwise, this is not an escaped newline, just return the slash.
    return '\\';
  }
  
  // If this is a trigraph, process it.
  if (Features.Trigraphs && Ptr[0] == '?' && Ptr[1] == '?') {
    // If this is actually a legal trigraph (not something like "??x"), return
    // it.
    if (char C = GetTrigraphCharForLetter(Ptr[2])) {
      Ptr += 3;
      Size += 3;
      if (C == '\\') goto Slash;
      return C;
    }
  }
  
  // If this is neither, return a single character.
  ++Size;
  return *Ptr;
}

//===----------------------------------------------------------------------===//
// Helper methods for lexing.
//===----------------------------------------------------------------------===//

void Lexer::LexIdentifier(Token &Result, const char *CurPtr) {
  // Match [_A-Za-z0-9]*, we have already matched [_A-Za-z$]
  unsigned Size;
  unsigned char C = *CurPtr++;
  while (isIdentifierBody(C)) {
    C = *CurPtr++;
  }
  --CurPtr;   // Back up over the skipped character.

  // Fast path, no $,\,? in identifier found.  '\' might be an escaped newline
  // or UCN, and ? might be a trigraph for '\', an escaped newline or UCN.
  // FIXME: UCNs.
  if (C != '\\' && C != '?' && (C != '$' || !Features.DollarIdents)) {
FinishIdentifier:
    const char *IdStart = BufferPtr;
    FormTokenWithChars(Result, CurPtr, tok::identifier);
    
    // If we are in raw mode, return this identifier raw.  There is no need to
    // look up identifier information or attempt to macro expand it.
    if (LexingRawMode) return;
    
    // Fill in Result.IdentifierInfo, looking up the identifier in the
    // identifier table.
    IdentifierInfo *II = PP->LookUpIdentifierInfo(Result, IdStart);
    
    // Change the kind of this identifier to the appropriate token kind, e.g.
    // turning "for" into a keyword.
    Result.setKind(II->getTokenID());
    
    // Finally, now that we know we have an identifier, pass this off to the
    // preprocessor, which may macro expand it or something.
    if (II->isHandleIdentifierCase())
      PP->HandleIdentifier(Result);
    return;
  }
  
  // Otherwise, $,\,? in identifier found.  Enter slower path.
  
  C = getCharAndSize(CurPtr, Size);
  while (1) {
    if (C == '$') {
      // If we hit a $ and they are not supported in identifiers, we are done.
      if (!Features.DollarIdents) goto FinishIdentifier;
      
      // Otherwise, emit a diagnostic and continue.
      if (!isLexingRawMode())
        Diag(CurPtr, diag::ext_dollar_in_identifier);
      CurPtr = ConsumeChar(CurPtr, Size, Result);
      C = getCharAndSize(CurPtr, Size);
      continue;
    } else if (!isIdentifierBody(C)) { // FIXME: UCNs.
      // Found end of identifier.
      goto FinishIdentifier;
    }

    // Otherwise, this character is good, consume it.
    CurPtr = ConsumeChar(CurPtr, Size, Result);

    C = getCharAndSize(CurPtr, Size);
    while (isIdentifierBody(C)) { // FIXME: UCNs.
      CurPtr = ConsumeChar(CurPtr, Size, Result);
      C = getCharAndSize(CurPtr, Size);
    }
  }
}


/// LexNumericConstant - Lex the remainder of a integer or floating point
/// constant. From[-1] is the first character lexed.  Return the end of the
/// constant.
void Lexer::LexNumericConstant(Token &Result, const char *CurPtr) {
  unsigned Size;
  char C = getCharAndSize(CurPtr, Size);
  char PrevCh = 0;
  while (isNumberBody(C)) { // FIXME: UCNs?
    CurPtr = ConsumeChar(CurPtr, Size, Result);
    PrevCh = C;
    C = getCharAndSize(CurPtr, Size);
  }
  
  // If we fell out, check for a sign, due to 1e+12.  If we have one, continue.
  if ((C == '-' || C == '+') && (PrevCh == 'E' || PrevCh == 'e'))
    return LexNumericConstant(Result, ConsumeChar(CurPtr, Size, Result));

  // If we have a hex FP constant, continue.
  if ((C == '-' || C == '+') && (PrevCh == 'P' || PrevCh == 'p'))
    return LexNumericConstant(Result, ConsumeChar(CurPtr, Size, Result));
  
  // Update the location of token as well as BufferPtr.
  const char *TokStart = BufferPtr;
  FormTokenWithChars(Result, CurPtr, tok::numeric_constant);
  Result.setLiteralData(TokStart);
}

/// LexStringLiteral - Lex the remainder of a string literal, after having lexed
/// either " or L".
void Lexer::LexStringLiteral(Token &Result, const char *CurPtr, bool Wide) {
  const char *NulCharacter = 0; // Does this string contain the \0 character?
  
  char C = getAndAdvanceChar(CurPtr, Result);
  while (C != '"') {
    // Skip escaped characters.
    if (C == '\\') {
      // Skip the escaped character.
      C = getAndAdvanceChar(CurPtr, Result);
    } else if (C == '\n' || C == '\r' ||             // Newline.
               (C == 0 && CurPtr-1 == BufferEnd)) {  // End of file.
      if (!isLexingRawMode() && !Features.AsmPreprocessor)
        Diag(BufferPtr, diag::err_unterminated_string);
      FormTokenWithChars(Result, CurPtr-1, tok::unknown);
      return;
    } else if (C == 0) {
      NulCharacter = CurPtr-1;
    }
    C = getAndAdvanceChar(CurPtr, Result);
  }
  
  // If a nul character existed in the string, warn about it.
  if (NulCharacter && !isLexingRawMode())
    Diag(NulCharacter, diag::null_in_string);

  // Update the location of the token as well as the BufferPtr instance var.
  const char *TokStart = BufferPtr;
  FormTokenWithChars(Result, CurPtr,
                     Wide ? tok::wide_string_literal : tok::string_literal);
  Result.setLiteralData(TokStart);
}

/// LexAngledStringLiteral - Lex the remainder of an angled string literal,
/// after having lexed the '<' character.  This is used for #include filenames.
void Lexer::LexAngledStringLiteral(Token &Result, const char *CurPtr) {
  const char *NulCharacter = 0; // Does this string contain the \0 character?
  const char *AfterLessPos = CurPtr;
  char C = getAndAdvanceChar(CurPtr, Result);
  while (C != '>') {
    // Skip escaped characters.
    if (C == '\\') {
      // Skip the escaped character.
      C = getAndAdvanceChar(CurPtr, Result);
    } else if (C == '\n' || C == '\r' ||             // Newline.
               (C == 0 && CurPtr-1 == BufferEnd)) {  // End of file.
      // If the filename is unterminated, then it must just be a lone <
      // character.  Return this as such.
      FormTokenWithChars(Result, AfterLessPos, tok::less);
      return;
    } else if (C == 0) {
      NulCharacter = CurPtr-1;
    }
    C = getAndAdvanceChar(CurPtr, Result);
  }
  
  // If a nul character existed in the string, warn about it.
  if (NulCharacter && !isLexingRawMode())
    Diag(NulCharacter, diag::null_in_string);
  
  // Update the location of token as well as BufferPtr.
  const char *TokStart = BufferPtr;
  FormTokenWithChars(Result, CurPtr, tok::angle_string_literal);
  Result.setLiteralData(TokStart);
}


/// LexCharConstant - Lex the remainder of a character constant, after having
/// lexed either ' or L'.
void Lexer::LexCharConstant(Token &Result, const char *CurPtr) {
  const char *NulCharacter = 0; // Does this character contain the \0 character?

  // Handle the common case of 'x' and '\y' efficiently.
  char C = getAndAdvanceChar(CurPtr, Result);
  if (C == '\'') {
    if (!isLexingRawMode() && !Features.AsmPreprocessor)
      Diag(BufferPtr, diag::err_empty_character);
    const char *TokStart = BufferPtr;
    FormTokenWithChars(Result, CurPtr, tok::char_constant);
    Result.setLiteralData(TokStart);
    return;
  } else if (C == '\\') {
    // Skip the escaped character.
    // FIXME: UCN's.
    C = getAndAdvanceChar(CurPtr, Result);
  }
  
  if (C && C != '\n' && C != '\r' && CurPtr[0] == '\'') {
    ++CurPtr;
  } else {
    // Fall back on generic code for embedded nulls, newlines, wide chars.
    do {
      // Skip escaped characters.
      if (C == '\\') {
        // Skip the escaped character.
        C = getAndAdvanceChar(CurPtr, Result);
      } else if (C == '\n' || C == '\r' ||               // Newline.
                 (C == 0 && CurPtr-1 == BufferEnd)) {    // End of file.
        if (!isLexingRawMode() && !Features.AsmPreprocessor)
          Diag(BufferPtr, diag::err_unterminated_char);
        FormTokenWithChars(Result, CurPtr-1, tok::unknown);
        return;
      } else if (C == 0) {
        NulCharacter = CurPtr-1;
      }
      C = getAndAdvanceChar(CurPtr, Result);
    } while (C != '\'');
  }
  
  if (NulCharacter && !isLexingRawMode())
    Diag(NulCharacter, diag::null_in_char);

  // Update the location of token as well as BufferPtr.
  const char *TokStart = BufferPtr;
  FormTokenWithChars(Result, CurPtr, tok::char_constant);
  Result.setLiteralData(TokStart);
}

/// SkipWhitespace - Efficiently skip over a series of whitespace characters.
/// Update BufferPtr to point to the next non-whitespace character and return.
///
/// This method forms a token and returns true if KeepWhitespaceMode is enabled.
///
bool Lexer::SkipWhitespace(Token &Result, const char *CurPtr) {
  // Whitespace - Skip it, then return the token after the whitespace.
  unsigned char Char = *CurPtr;  // Skip consequtive spaces efficiently.
  while (1) {
    // Skip horizontal whitespace very aggressively.
    while (isHorizontalWhitespace(Char))
      Char = *++CurPtr;
    
    // Otherwise if we have something other than whitespace, we're done.
    if (Char != '\n' && Char != '\r')
      break;
    
    if (ParsingPreprocessorDirective) {
      // End of preprocessor directive line, let LexTokenInternal handle this.
      BufferPtr = CurPtr;
      return false;
    }
    
    // ok, but handle newline.
    // The returned token is at the start of the line.
    Result.setFlag(Token::StartOfLine);
    // No leading whitespace seen so far.
    Result.clearFlag(Token::LeadingSpace);
    Char = *++CurPtr;
  }

  // If this isn't immediately after a newline, there is leading space.
  char PrevChar = CurPtr[-1];
  if (PrevChar != '\n' && PrevChar != '\r')
    Result.setFlag(Token::LeadingSpace);

  // If the client wants us to return whitespace, return it now.
  if (isKeepWhitespaceMode()) {
    FormTokenWithChars(Result, CurPtr, tok::unknown);
    return true;
  }
  
  BufferPtr = CurPtr;
  return false;
}

// SkipBCPLComment - We have just read the // characters from input.  Skip until
// we find the newline character thats terminate the comment.  Then update
/// BufferPtr and return.  If we're in KeepCommentMode, this will form the token
/// and return true.
bool Lexer::SkipBCPLComment(Token &Result, const char *CurPtr) {
  // If BCPL comments aren't explicitly enabled for this language, emit an
  // extension warning.
  if (!Features.BCPLComment && !isLexingRawMode()) {
    Diag(BufferPtr, diag::ext_bcpl_comment);
    
    // Mark them enabled so we only emit one warning for this translation
    // unit.
    Features.BCPLComment = true;
  }
  
  // Scan over the body of the comment.  The common case, when scanning, is that
  // the comment contains normal ascii characters with nothing interesting in
  // them.  As such, optimize for this case with the inner loop.
  char C;
  do {
    C = *CurPtr;
    // FIXME: Speedup BCPL comment lexing.  Just scan for a \n or \r character.
    // If we find a \n character, scan backwards, checking to see if it's an
    // escaped newline, like we do for block comments.
    
    // Skip over characters in the fast loop.
    while (C != 0 &&                // Potentially EOF.
           C != '\\' &&             // Potentially escaped newline.
           C != '?' &&              // Potentially trigraph.
           C != '\n' && C != '\r')  // Newline or DOS-style newline.
      C = *++CurPtr;

    // If this is a newline, we're done.
    if (C == '\n' || C == '\r')
      break;  // Found the newline? Break out!
    
    // Otherwise, this is a hard case.  Fall back on getAndAdvanceChar to
    // properly decode the character.  Read it in raw mode to avoid emitting
    // diagnostics about things like trigraphs.  If we see an escaped newline,
    // we'll handle it below.
    const char *OldPtr = CurPtr;
    bool OldRawMode = isLexingRawMode();
    LexingRawMode = true;
    C = getAndAdvanceChar(CurPtr, Result);
    LexingRawMode = OldRawMode;

    // If the char that we finally got was a \n, then we must have had something
    // like \<newline><newline>.  We don't want to have consumed the second
    // newline, we want CurPtr, to end up pointing to it down below.
    if (C == '\n' || C == '\r') {
      --CurPtr;
      C = 'x'; // doesn't matter what this is.
    }
    
    // If we read multiple characters, and one of those characters was a \r or
    // \n, then we had an escaped newline within the comment.  Emit diagnostic
    // unless the next line is also a // comment.
    if (CurPtr != OldPtr+1 && C != '/' && CurPtr[0] != '/') {
      for (; OldPtr != CurPtr; ++OldPtr)
        if (OldPtr[0] == '\n' || OldPtr[0] == '\r') {
          // Okay, we found a // comment that ends in a newline, if the next
          // line is also a // comment, but has spaces, don't emit a diagnostic.
          if (isspace(C)) {
            const char *ForwardPtr = CurPtr;
            while (isspace(*ForwardPtr))  // Skip whitespace.
              ++ForwardPtr;
            if (ForwardPtr[0] == '/' && ForwardPtr[1] == '/')
              break;
          }
          
          if (!isLexingRawMode())
            Diag(OldPtr-1, diag::ext_multi_line_bcpl_comment);
          break;
        }
    }
    
    if (CurPtr == BufferEnd+1) { --CurPtr; break; }
  } while (C != '\n' && C != '\r');

  // Found but did not consume the newline.
    
  // If we are returning comments as tokens, return this comment as a token.
  if (inKeepCommentMode())
    return SaveBCPLComment(Result, CurPtr);

  // If we are inside a preprocessor directive and we see the end of line,
  // return immediately, so that the lexer can return this as an EOM token.
  if (ParsingPreprocessorDirective || CurPtr == BufferEnd) {
    BufferPtr = CurPtr;
    return false;
  }
  
  // Otherwise, eat the \n character.  We don't care if this is a \n\r or
  // \r\n sequence.  This is an efficiency hack (because we know the \n can't
  // contribute to another token), it isn't needed for correctness.  Note that
  // this is ok even in KeepWhitespaceMode, because we would have returned the
  /// comment above in that mode.
  ++CurPtr;
    
  // The next returned token is at the start of the line.
  Result.setFlag(Token::StartOfLine);
  // No leading whitespace seen so far.
  Result.clearFlag(Token::LeadingSpace);
  BufferPtr = CurPtr;
  return false;
}

/// SaveBCPLComment - If in save-comment mode, package up this BCPL comment in
/// an appropriate way and return it.
bool Lexer::SaveBCPLComment(Token &Result, const char *CurPtr) {
  // If we're not in a preprocessor directive, just return the // comment
  // directly.
  FormTokenWithChars(Result, CurPtr, tok::comment);
  
  if (!ParsingPreprocessorDirective)
    return true;
  
  // If this BCPL-style comment is in a macro definition, transmogrify it into
  // a C-style block comment.
  std::string Spelling = PP->getSpelling(Result);
  assert(Spelling[0] == '/' && Spelling[1] == '/' && "Not bcpl comment?");
  Spelling[1] = '*';   // Change prefix to "/*".
  Spelling += "*/";    // add suffix.
  
  Result.setKind(tok::comment);
  PP->CreateString(&Spelling[0], Spelling.size(), Result,
                   Result.getLocation());
  return true;
}

/// isBlockCommentEndOfEscapedNewLine - Return true if the specified newline
/// character (either \n or \r) is part of an escaped newline sequence.  Issue a
/// diagnostic if so.  We know that the newline is inside of a block comment.
static bool isEndOfBlockCommentWithEscapedNewLine(const char *CurPtr, 
                                                  Lexer *L) {
  assert(CurPtr[0] == '\n' || CurPtr[0] == '\r');
  
  // Back up off the newline.
  --CurPtr;
  
  // If this is a two-character newline sequence, skip the other character.
  if (CurPtr[0] == '\n' || CurPtr[0] == '\r') {
    // \n\n or \r\r -> not escaped newline.
    if (CurPtr[0] == CurPtr[1])
      return false;
    // \n\r or \r\n -> skip the newline.
    --CurPtr;
  }
  
  // If we have horizontal whitespace, skip over it.  We allow whitespace
  // between the slash and newline.
  bool HasSpace = false;
  while (isHorizontalWhitespace(*CurPtr) || *CurPtr == 0) {
    --CurPtr;
    HasSpace = true;
  }
  
  // If we have a slash, we know this is an escaped newline.
  if (*CurPtr == '\\') {
    if (CurPtr[-1] != '*') return false;
  } else {
    // It isn't a slash, is it the ?? / trigraph?
    if (CurPtr[0] != '/' || CurPtr[-1] != '?' || CurPtr[-2] != '?' ||
        CurPtr[-3] != '*')
      return false;
    
    // This is the trigraph ending the comment.  Emit a stern warning!
    CurPtr -= 2;

    // If no trigraphs are enabled, warn that we ignored this trigraph and
    // ignore this * character.
    if (!L->getFeatures().Trigraphs) {
      if (!L->isLexingRawMode())
        L->Diag(CurPtr, diag::trigraph_ignored_block_comment);
      return false;
    }
    if (!L->isLexingRawMode())
      L->Diag(CurPtr, diag::trigraph_ends_block_comment);
  }
  
  // Warn about having an escaped newline between the */ characters.
  if (!L->isLexingRawMode())
    L->Diag(CurPtr, diag::escaped_newline_block_comment_end);
  
  // If there was space between the backslash and newline, warn about it.
  if (HasSpace && !L->isLexingRawMode())
    L->Diag(CurPtr, diag::backslash_newline_space);
  
  return true;
}

#ifdef __SSE2__
#include <emmintrin.h>
#elif __ALTIVEC__
#include <altivec.h>
#undef bool
#endif

/// SkipBlockComment - We have just read the /* characters from input.  Read
/// until we find the */ characters that terminate the comment.  Note that we
/// don't bother decoding trigraphs or escaped newlines in block comments,
/// because they cannot cause the comment to end.  The only thing that can
/// happen is the comment could end with an escaped newline between the */ end
/// of comment.
///
/// If KeepCommentMode is enabled, this forms a token from the comment and
/// returns true.
bool Lexer::SkipBlockComment(Token &Result, const char *CurPtr) {
  // Scan one character past where we should, looking for a '/' character.  Once
  // we find it, check to see if it was preceeded by a *.  This common
  // optimization helps people who like to put a lot of * characters in their
  // comments.

  // The first character we get with newlines and trigraphs skipped to handle
  // the degenerate /*/ case below correctly if the * has an escaped newline
  // after it.
  unsigned CharSize;
  unsigned char C = getCharAndSize(CurPtr, CharSize);
  CurPtr += CharSize;
  if (C == 0 && CurPtr == BufferEnd+1) {
    if (!isLexingRawMode())
      Diag(BufferPtr, diag::err_unterminated_block_comment);
    --CurPtr;
    
    // KeepWhitespaceMode should return this broken comment as a token.  Since
    // it isn't a well formed comment, just return it as an 'unknown' token.
    if (isKeepWhitespaceMode()) {
      FormTokenWithChars(Result, CurPtr, tok::unknown);
      return true;
    }
    
    BufferPtr = CurPtr;
    return false;
  }
  
  // Check to see if the first character after the '/*' is another /.  If so,
  // then this slash does not end the block comment, it is part of it.
  if (C == '/')
    C = *CurPtr++;
  
  while (1) {
    // Skip over all non-interesting characters until we find end of buffer or a
    // (probably ending) '/' character.
    if (CurPtr + 24 < BufferEnd) {
      // While not aligned to a 16-byte boundary.
      while (C != '/' && ((intptr_t)CurPtr & 0x0F) != 0)
        C = *CurPtr++;
      
      if (C == '/') goto FoundSlash;

#ifdef __SSE2__
      __m128i Slashes = _mm_set_epi8('/', '/', '/', '/', '/', '/', '/', '/',
                                     '/', '/', '/', '/', '/', '/', '/', '/');
      while (CurPtr+16 <= BufferEnd &&
             _mm_movemask_epi8(_mm_cmpeq_epi8(*(__m128i*)CurPtr, Slashes)) == 0)
        CurPtr += 16;
#elif __ALTIVEC__
      __vector unsigned char Slashes = {
        '/', '/', '/', '/',  '/', '/', '/', '/', 
        '/', '/', '/', '/',  '/', '/', '/', '/'
      };
      while (CurPtr+16 <= BufferEnd &&
             !vec_any_eq(*(vector unsigned char*)CurPtr, Slashes))
        CurPtr += 16;
#else    
      // Scan for '/' quickly.  Many block comments are very large.
      while (CurPtr[0] != '/' &&
             CurPtr[1] != '/' &&
             CurPtr[2] != '/' &&
             CurPtr[3] != '/' &&
             CurPtr+4 < BufferEnd) {
        CurPtr += 4;
      }
#endif
      
      // It has to be one of the bytes scanned, increment to it and read one.
      C = *CurPtr++;
    }
    
    // Loop to scan the remainder.
    while (C != '/' && C != '\0')
      C = *CurPtr++;
    
  FoundSlash:
    if (C == '/') {
      if (CurPtr[-2] == '*')  // We found the final */.  We're done!
        break;
      
      if ((CurPtr[-2] == '\n' || CurPtr[-2] == '\r')) {
        if (isEndOfBlockCommentWithEscapedNewLine(CurPtr-2, this)) {
          // We found the final */, though it had an escaped newline between the
          // * and /.  We're done!
          break;
        }
      }
      if (CurPtr[0] == '*' && CurPtr[1] != '/') {
        // If this is a /* inside of the comment, emit a warning.  Don't do this
        // if this is a /*/, which will end the comment.  This misses cases with
        // embedded escaped newlines, but oh well.
        if (!isLexingRawMode())
          Diag(CurPtr-1, diag::warn_nested_block_comment);
      }
    } else if (C == 0 && CurPtr == BufferEnd+1) {
      if (!isLexingRawMode())
        Diag(BufferPtr, diag::err_unterminated_block_comment);
      // Note: the user probably forgot a */.  We could continue immediately
      // after the /*, but this would involve lexing a lot of what really is the
      // comment, which surely would confuse the parser.
      --CurPtr;
      
      // KeepWhitespaceMode should return this broken comment as a token.  Since
      // it isn't a well formed comment, just return it as an 'unknown' token.
      if (isKeepWhitespaceMode()) {
        FormTokenWithChars(Result, CurPtr, tok::unknown);
        return true;
      }
      
      BufferPtr = CurPtr;
      return false;
    }
    C = *CurPtr++;
  }
  
  // If we are returning comments as tokens, return this comment as a token.
  if (inKeepCommentMode()) {
    FormTokenWithChars(Result, CurPtr, tok::comment);
    return true;
  }

  // It is common for the tokens immediately after a /**/ comment to be
  // whitespace.  Instead of going through the big switch, handle it
  // efficiently now.  This is safe even in KeepWhitespaceMode because we would
  // have already returned above with the comment as a token.
  if (isHorizontalWhitespace(*CurPtr)) {
    Result.setFlag(Token::LeadingSpace);
    SkipWhitespace(Result, CurPtr+1);
    return false;
  }

  // Otherwise, just return so that the next character will be lexed as a token.
  BufferPtr = CurPtr;
  Result.setFlag(Token::LeadingSpace);
  return false;
}

//===----------------------------------------------------------------------===//
// Primary Lexing Entry Points
//===----------------------------------------------------------------------===//

/// ReadToEndOfLine - Read the rest of the current preprocessor line as an
/// uninterpreted string.  This switches the lexer out of directive mode.
std::string Lexer::ReadToEndOfLine() {
  assert(ParsingPreprocessorDirective && ParsingFilename == false &&
         "Must be in a preprocessing directive!");
  std::string Result;
  Token Tmp;

  // CurPtr - Cache BufferPtr in an automatic variable.
  const char *CurPtr = BufferPtr;
  while (1) {
    char Char = getAndAdvanceChar(CurPtr, Tmp);
    switch (Char) {
    default:
      Result += Char;
      break;
    case 0:  // Null.
      // Found end of file?
      if (CurPtr-1 != BufferEnd) {
        // Nope, normal character, continue.
        Result += Char;
        break;
      }
      // FALL THROUGH.
    case '\r':
    case '\n':
      // Okay, we found the end of the line. First, back up past the \0, \r, \n.
      assert(CurPtr[-1] == Char && "Trigraphs for newline?");
      BufferPtr = CurPtr-1;
      
      // Next, lex the character, which should handle the EOM transition.
      Lex(Tmp);
      assert(Tmp.is(tok::eom) && "Unexpected token!");
      
      // Finally, we're done, return the string we found.
      return Result;
    }
  }
}

/// LexEndOfFile - CurPtr points to the end of this file.  Handle this
/// condition, reporting diagnostics and handling other edge cases as required.
/// This returns true if Result contains a token, false if PP.Lex should be
/// called again.
bool Lexer::LexEndOfFile(Token &Result, const char *CurPtr) {
  // If we hit the end of the file while parsing a preprocessor directive,
  // end the preprocessor directive first.  The next token returned will
  // then be the end of file.
  if (ParsingPreprocessorDirective) {
    // Done parsing the "line".
    ParsingPreprocessorDirective = false;
    // Update the location of token as well as BufferPtr.
    FormTokenWithChars(Result, CurPtr, tok::eom);
    
    // Restore comment saving mode, in case it was disabled for directive.
    SetCommentRetentionState(PP->getCommentRetentionState());
    return true;  // Have a token.
  }        

  // If we are in raw mode, return this event as an EOF token.  Let the caller
  // that put us in raw mode handle the event.
  if (isLexingRawMode()) {
    Result.startToken();
    BufferPtr = BufferEnd;
    FormTokenWithChars(Result, BufferEnd, tok::eof);
    return true;
  }
  
  // Otherwise, issue diagnostics for unterminated #if and missing newline.

  // If we are in a #if directive, emit an error.
  while (!ConditionalStack.empty()) {
    PP->Diag(ConditionalStack.back().IfLoc,
             diag::err_pp_unterminated_conditional);
    ConditionalStack.pop_back();
  }
  
  // C99 5.1.1.2p2: If the file is non-empty and didn't end in a newline, issue
  // a pedwarn.
  if (CurPtr != BufferStart && (CurPtr[-1] != '\n' && CurPtr[-1] != '\r'))
    Diag(BufferEnd, diag::ext_no_newline_eof)
      << CodeModificationHint::CreateInsertion(getSourceLocation(BufferEnd),
                                               "\n");
  
  BufferPtr = CurPtr;

  // Finally, let the preprocessor handle this.
  return PP->HandleEndOfFile(Result);
}

/// isNextPPTokenLParen - Return 1 if the next unexpanded token lexed from
/// the specified lexer will return a tok::l_paren token, 0 if it is something
/// else and 2 if there are no more tokens in the buffer controlled by the
/// lexer.
unsigned Lexer::isNextPPTokenLParen() {
  assert(!LexingRawMode && "How can we expand a macro from a skipping buffer?");
  
  // Switch to 'skipping' mode.  This will ensure that we can lex a token
  // without emitting diagnostics, disables macro expansion, and will cause EOF
  // to return an EOF token instead of popping the include stack.
  LexingRawMode = true;
  
  // Save state that can be changed while lexing so that we can restore it.
  const char *TmpBufferPtr = BufferPtr;
  bool inPPDirectiveMode = ParsingPreprocessorDirective;
  
  Token Tok;
  Tok.startToken();
  LexTokenInternal(Tok);
  
  // Restore state that may have changed.
  BufferPtr = TmpBufferPtr;
  ParsingPreprocessorDirective = inPPDirectiveMode;
  
  // Restore the lexer back to non-skipping mode.
  LexingRawMode = false;
  
  if (Tok.is(tok::eof))
    return 2;
  return Tok.is(tok::l_paren);
}


/// LexTokenInternal - This implements a simple C family lexer.  It is an
/// extremely performance critical piece of code.  This assumes that the buffer
/// has a null character at the end of the file.  Return true if an error
/// occurred and compilation should terminate, false if normal.  This returns a
/// preprocessing token, not a normal token, as such, it is an internal
/// interface.  It assumes that the Flags of result have been cleared before
/// calling this.
void Lexer::LexTokenInternal(Token &Result) {
LexNextToken:
  // New token, can't need cleaning yet.
  Result.clearFlag(Token::NeedsCleaning);
  Result.setIdentifierInfo(0);
  
  // CurPtr - Cache BufferPtr in an automatic variable.
  const char *CurPtr = BufferPtr;

  // Small amounts of horizontal whitespace is very common between tokens.
  if ((*CurPtr == ' ') || (*CurPtr == '\t')) {
    ++CurPtr;
    while ((*CurPtr == ' ') || (*CurPtr == '\t'))
      ++CurPtr;
    
    // If we are keeping whitespace and other tokens, just return what we just
    // skipped.  The next lexer invocation will return the token after the
    // whitespace.
    if (isKeepWhitespaceMode()) {
      FormTokenWithChars(Result, CurPtr, tok::unknown);
      return;
    }
    
    BufferPtr = CurPtr;
    Result.setFlag(Token::LeadingSpace);
  }
  
  unsigned SizeTmp, SizeTmp2;   // Temporaries for use in cases below.
  
  // Read a character, advancing over it.
  char Char = getAndAdvanceChar(CurPtr, Result);
  tok::TokenKind Kind;
  
  switch (Char) {
  case 0:  // Null.
    // Found end of file?
    if (CurPtr-1 == BufferEnd) {
      // Read the PP instance variable into an automatic variable, because
      // LexEndOfFile will often delete 'this'.
      Preprocessor *PPCache = PP;
      if (LexEndOfFile(Result, CurPtr-1))  // Retreat back into the file.
        return;   // Got a token to return.
      assert(PPCache && "Raw buffer::LexEndOfFile should return a token");
      return PPCache->Lex(Result);
    }
    
    if (!isLexingRawMode())
      Diag(CurPtr-1, diag::null_in_file);
    Result.setFlag(Token::LeadingSpace);
    if (SkipWhitespace(Result, CurPtr))
      return; // KeepWhitespaceMode
      
    goto LexNextToken;   // GCC isn't tail call eliminating.
  case '\n':
  case '\r':
    // If we are inside a preprocessor directive and we see the end of line,
    // we know we are done with the directive, so return an EOM token.
    if (ParsingPreprocessorDirective) {
      // Done parsing the "line".
      ParsingPreprocessorDirective = false;
      
      // Restore comment saving mode, in case it was disabled for directive.
      SetCommentRetentionState(PP->getCommentRetentionState());
      
      // Since we consumed a newline, we are back at the start of a line.
      IsAtStartOfLine = true;
      
      Kind = tok::eom;
      break;
    }
    // The returned token is at the start of the line.
    Result.setFlag(Token::StartOfLine);
    // No leading whitespace seen so far.
    Result.clearFlag(Token::LeadingSpace);
      
    if (SkipWhitespace(Result, CurPtr))
      return; // KeepWhitespaceMode
    goto LexNextToken;   // GCC isn't tail call eliminating.
  case ' ':
  case '\t':
  case '\f':
  case '\v':
  SkipHorizontalWhitespace:
    Result.setFlag(Token::LeadingSpace);
    if (SkipWhitespace(Result, CurPtr))
      return; // KeepWhitespaceMode

  SkipIgnoredUnits:
    CurPtr = BufferPtr;
    
    // If the next token is obviously a // or /* */ comment, skip it efficiently
    // too (without going through the big switch stmt).
    if (CurPtr[0] == '/' && CurPtr[1] == '/' && !inKeepCommentMode() &&
        Features.BCPLComment) {
      SkipBCPLComment(Result, CurPtr+2);
      goto SkipIgnoredUnits;
    } else if (CurPtr[0] == '/' && CurPtr[1] == '*' && !inKeepCommentMode()) {
      SkipBlockComment(Result, CurPtr+2);
      goto SkipIgnoredUnits;
    } else if (isHorizontalWhitespace(*CurPtr)) {
      goto SkipHorizontalWhitespace;
    }
    goto LexNextToken;   // GCC isn't tail call eliminating.

  // C99 6.4.4.1: Integer Constants.
  // C99 6.4.4.2: Floating Constants.
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    // Notify MIOpt that we read a non-whitespace/non-comment token.
    MIOpt.ReadToken();
    return LexNumericConstant(Result, CurPtr);
    
  case 'L':   // Identifier (Loony) or wide literal (L'x' or L"xyz").
    // Notify MIOpt that we read a non-whitespace/non-comment token.
    MIOpt.ReadToken();
    Char = getCharAndSize(CurPtr, SizeTmp);

    // Wide string literal.
    if (Char == '"')
      return LexStringLiteral(Result, ConsumeChar(CurPtr, SizeTmp, Result),
                              true);

    // Wide character constant.
    if (Char == '\'')
      return LexCharConstant(Result, ConsumeChar(CurPtr, SizeTmp, Result));
    // FALL THROUGH, treating L like the start of an identifier.
    
  // C99 6.4.2: Identifiers.
  case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
  case 'H': case 'I': case 'J': case 'K':    /*'L'*/case 'M': case 'N':
  case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
  case 'V': case 'W': case 'X': case 'Y': case 'Z':
  case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
  case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
  case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
  case 'v': case 'w': case 'x': case 'y': case 'z':
  case '_':
    // Notify MIOpt that we read a non-whitespace/non-comment token.
    MIOpt.ReadToken();
    return LexIdentifier(Result, CurPtr);

  case '$':   // $ in identifiers.
    if (Features.DollarIdents) {
      if (!isLexingRawMode())
        Diag(CurPtr-1, diag::ext_dollar_in_identifier);
      // Notify MIOpt that we read a non-whitespace/non-comment token.
      MIOpt.ReadToken();
      return LexIdentifier(Result, CurPtr);
    }
    
    Kind = tok::unknown;
    break;
    
  // C99 6.4.4: Character Constants.
  case '\'':
    // Notify MIOpt that we read a non-whitespace/non-comment token.
    MIOpt.ReadToken();
    return LexCharConstant(Result, CurPtr);

  // C99 6.4.5: String Literals.
  case '"':
    // Notify MIOpt that we read a non-whitespace/non-comment token.
    MIOpt.ReadToken();
    return LexStringLiteral(Result, CurPtr, false);

  // C99 6.4.6: Punctuators.
  case '?':
    Kind = tok::question;
    break;
  case '[':
    Kind = tok::l_square;
    break;
  case ']':
    Kind = tok::r_square;
    break;
  case '(':
    Kind = tok::l_paren;
    break;
  case ')':
    Kind = tok::r_paren;
    break;
  case '{':
    Kind = tok::l_brace;
    break;
  case '}':
    Kind = tok::r_brace;
    break;
  case '.':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char >= '0' && Char <= '9') {
      // Notify MIOpt that we read a non-whitespace/non-comment token.
      MIOpt.ReadToken();

      return LexNumericConstant(Result, ConsumeChar(CurPtr, SizeTmp, Result));
    } else if (Features.CPlusPlus && Char == '*') {
      Kind = tok::periodstar;
      CurPtr += SizeTmp;
    } else if (Char == '.' &&
               getCharAndSize(CurPtr+SizeTmp, SizeTmp2) == '.') {
      Kind = tok::ellipsis;
      CurPtr = ConsumeChar(ConsumeChar(CurPtr, SizeTmp, Result),
                           SizeTmp2, Result);
    } else {
      Kind = tok::period;
    }
    break;
  case '&':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '&') {
      Kind = tok::ampamp;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else if (Char == '=') {
      Kind = tok::ampequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {
      Kind = tok::amp;
    }
    break;
  case '*': 
    if (getCharAndSize(CurPtr, SizeTmp) == '=') {
      Kind = tok::starequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {
      Kind = tok::star;
    }
    break;
  case '+':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '+') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::plusplus;
    } else if (Char == '=') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::plusequal;
    } else {
      Kind = tok::plus;
    }
    break;
  case '-':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '-') {      // --
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::minusminus;
    } else if (Char == '>' && Features.CPlusPlus && 
               getCharAndSize(CurPtr+SizeTmp, SizeTmp2) == '*') {  // C++ ->*
      CurPtr = ConsumeChar(ConsumeChar(CurPtr, SizeTmp, Result),
                           SizeTmp2, Result);
      Kind = tok::arrowstar;
    } else if (Char == '>') {   // ->
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::arrow;
    } else if (Char == '=') {   // -=
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::minusequal;
    } else {
      Kind = tok::minus;
    }
    break;
  case '~':
    Kind = tok::tilde;
    break;
  case '!':
    if (getCharAndSize(CurPtr, SizeTmp) == '=') {
      Kind = tok::exclaimequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {
      Kind = tok::exclaim;
    }
    break;
  case '/':
    // 6.4.9: Comments
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '/') {         // BCPL comment.
      // Even if BCPL comments are disabled (e.g. in C89 mode), we generally
      // want to lex this as a comment.  There is one problem with this though,
      // that in one particular corner case, this can change the behavior of the
      // resultant program.  For example, In  "foo //**/ bar", C89 would lex
      // this as "foo / bar" and langauges with BCPL comments would lex it as
      // "foo".  Check to see if the character after the second slash is a '*'.
      // If so, we will lex that as a "/" instead of the start of a comment.
      if (Features.BCPLComment ||
          getCharAndSize(CurPtr+SizeTmp, SizeTmp2) != '*') {
        if (SkipBCPLComment(Result, ConsumeChar(CurPtr, SizeTmp, Result)))
          return; // KeepCommentMode
      
        // It is common for the tokens immediately after a // comment to be
        // whitespace (indentation for the next line).  Instead of going through
        // the big switch, handle it efficiently now.
        goto SkipIgnoredUnits;
      }
    }
      
    if (Char == '*') {  // /**/ comment.
      if (SkipBlockComment(Result, ConsumeChar(CurPtr, SizeTmp, Result)))
        return; // KeepCommentMode
      goto LexNextToken;   // GCC isn't tail call eliminating.
    }
      
    if (Char == '=') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::slashequal;
    } else {
      Kind = tok::slash;
    }
    break;
  case '%':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '=') {
      Kind = tok::percentequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else if (Features.Digraphs && Char == '>') {
      Kind = tok::r_brace;                             // '%>' -> '}'
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else if (Features.Digraphs && Char == ':') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Char = getCharAndSize(CurPtr, SizeTmp);
      if (Char == '%' && getCharAndSize(CurPtr+SizeTmp, SizeTmp2) == ':') {
        Kind = tok::hashhash;                          // '%:%:' -> '##'
        CurPtr = ConsumeChar(ConsumeChar(CurPtr, SizeTmp, Result),
                             SizeTmp2, Result);
      } else {                                         // '%:' -> '#'
        // We parsed a # character.  If this occurs at the start of the line,
        // it's actually the start of a preprocessing directive.  Callback to
        // the preprocessor to handle it.
        // FIXME: -fpreprocessed mode??
        if (Result.isAtStartOfLine() && !LexingRawMode && !Is_PragmaLexer) {
          FormTokenWithChars(Result, CurPtr, tok::hash);
          PP->HandleDirective(Result);
          
          // As an optimization, if the preprocessor didn't switch lexers, tail
          // recurse.
          if (PP->isCurrentLexer(this)) {
            // Start a new token. If this is a #include or something, the PP may
            // want us starting at the beginning of the line again.  If so, set
            // the StartOfLine flag.
            if (IsAtStartOfLine) {
              Result.setFlag(Token::StartOfLine);
              IsAtStartOfLine = false;
            }
            goto LexNextToken;   // GCC isn't tail call eliminating.
          }
          
          return PP->Lex(Result);
        }
        
        Kind = tok::hash;
      }
    } else {
      Kind = tok::percent;
    }
    break;
  case '<':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (ParsingFilename) {
      return LexAngledStringLiteral(Result, CurPtr);
    } else if (Char == '<' &&
               getCharAndSize(CurPtr+SizeTmp, SizeTmp2) == '=') {
      Kind = tok::lesslessequal;
      CurPtr = ConsumeChar(ConsumeChar(CurPtr, SizeTmp, Result),
                           SizeTmp2, Result);
    } else if (Char == '<') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::lessless;
    } else if (Char == '=') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::lessequal;
    } else if (Features.Digraphs && Char == ':') {     // '<:' -> '['
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::l_square;
    } else if (Features.Digraphs && Char == '%') {     // '<%' -> '{'
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::l_brace;
    } else if (Features.GNUMode && Char == '?') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::min;
    } else {
      Kind = tok::less;
    }
    break;
  case '>':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '=') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::greaterequal;
    } else if (Char == '>' && 
               getCharAndSize(CurPtr+SizeTmp, SizeTmp2) == '=') {
      CurPtr = ConsumeChar(ConsumeChar(CurPtr, SizeTmp, Result),
                           SizeTmp2, Result);
      Kind = tok::greatergreaterequal;
    } else if (Char == '>') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::greatergreater;
    } else if (Features.GNUMode && Char == '?') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::max;
    } else {
      Kind = tok::greater;
    }
    break;
  case '^':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '=') {
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
      Kind = tok::caretequal;
    } else {
      Kind = tok::caret;
    }
    break;
  case '|':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '=') {
      Kind = tok::pipeequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else if (Char == '|') {
      Kind = tok::pipepipe;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {
      Kind = tok::pipe;
    }
    break;
  case ':':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Features.Digraphs && Char == '>') {
      Kind = tok::r_square; // ':>' -> ']'
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else if (Features.CPlusPlus && Char == ':') {
      Kind = tok::coloncolon;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {    
      Kind = tok::colon;
    }
    break;
  case ';':
    Kind = tok::semi;
    break;
  case '=':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '=') {
      Kind = tok::equalequal;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {      
      Kind = tok::equal;
    }
    break;
  case ',':
    Kind = tok::comma;
    break;
  case '#':
    Char = getCharAndSize(CurPtr, SizeTmp);
    if (Char == '#') {
      Kind = tok::hashhash;
      CurPtr = ConsumeChar(CurPtr, SizeTmp, Result);
    } else {
      // We parsed a # character.  If this occurs at the start of the line,
      // it's actually the start of a preprocessing directive.  Callback to
      // the preprocessor to handle it.
      // FIXME: -fpreprocessed mode??
      if (Result.isAtStartOfLine() && !LexingRawMode && !Is_PragmaLexer) {
        FormTokenWithChars(Result, CurPtr, tok::hash);
        PP->HandleDirective(Result);
        
        // As an optimization, if the preprocessor didn't switch lexers, tail
        // recurse.
        if (PP->isCurrentLexer(this)) {
          // Start a new token.  If this is a #include or something, the PP may
          // want us starting at the beginning of the line again.  If so, set
          // the StartOfLine flag.
          if (IsAtStartOfLine) {
            Result.setFlag(Token::StartOfLine);
            IsAtStartOfLine = false;
          }
          goto LexNextToken;   // GCC isn't tail call eliminating.
        }
        return PP->Lex(Result);
      }
      
      Kind = tok::hash;
    }
    break;

  case '@':
    Kind = tok::unknown;
    break;
    
  case '\\':
    // FIXME: UCN's.
    // FALL THROUGH.
  default:
    Kind = tok::unknown;
    break;
  }
  
  // Notify MIOpt that we read a non-whitespace/non-comment token.
  MIOpt.ReadToken();

  // Update the location of token as well as BufferPtr.
  FormTokenWithChars(Result, CurPtr, Kind);
}