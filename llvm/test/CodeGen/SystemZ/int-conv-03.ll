; Test sign extensions from a byte to an i64.
;
; RUN: llc < %s -mtriple=s390x-linux-gnu | FileCheck %s

; Test register extension, starting with an i32.
define i64 @f1(i32 %a) {
; CHECK: f1:
; CHECK: lgbr %r2, %r2
; CHECk: br %r14
  %byte = trunc i32 %a to i8
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; ...and again with an i64.
define i64 @f2(i64 %a) {
; CHECK: f2:
; CHECK: lgbr %r2, %r2
; CHECk: br %r14
  %byte = trunc i64 %a to i8
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check LGB with no displacement.
define i64 @f3(i8 *%src) {
; CHECK: f3:
; CHECK: lgb %r2, 0(%r2)
; CHECK: br %r14
  %byte = load i8 *%src
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check the high end of the LGB range.
define i64 @f4(i8 *%src) {
; CHECK: f4:
; CHECK: lgb %r2, 524287(%r2)
; CHECK: br %r14
  %ptr = getelementptr i8 *%src, i64 524287
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check the next byte up, which needs separate address logic.
; Other sequences besides this one would be OK.
define i64 @f5(i8 *%src) {
; CHECK: f5:
; CHECK: agfi %r2, 524288
; CHECK: lgb %r2, 0(%r2)
; CHECK: br %r14
  %ptr = getelementptr i8 *%src, i64 524288
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check the high end of the negative LGB range.
define i64 @f6(i8 *%src) {
; CHECK: f6:
; CHECK: lgb %r2, -1(%r2)
; CHECK: br %r14
  %ptr = getelementptr i8 *%src, i64 -1
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check the low end of the LGB range.
define i64 @f7(i8 *%src) {
; CHECK: f7:
; CHECK: lgb %r2, -524288(%r2)
; CHECK: br %r14
  %ptr = getelementptr i8 *%src, i64 -524288
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check the next byte down, which needs separate address logic.
; Other sequences besides this one would be OK.
define i64 @f8(i8 *%src) {
; CHECK: f8:
; CHECK: agfi %r2, -524289
; CHECK: lgb %r2, 0(%r2)
; CHECK: br %r14
  %ptr = getelementptr i8 *%src, i64 -524289
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}

; Check that LGB allows an index
define i64 @f9(i64 %src, i64 %index) {
; CHECK: f9:
; CHECK: lgb %r2, 524287(%r3,%r2)
; CHECK: br %r14
  %add1 = add i64 %src, %index
  %add2 = add i64 %add1, 524287
  %ptr = inttoptr i64 %add2 to i8 *
  %byte = load i8 *%ptr
  %ext = sext i8 %byte to i64
  ret i64 %ext
}
