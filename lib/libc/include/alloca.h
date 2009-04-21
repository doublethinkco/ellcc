/* libc/include/alloca.h - Allocate memory on stack */

/* Written 2000 by Werner Almesberger */
/* Rearranged for general inclusion by stdlib.h.
   2001, Corinna Vinschen <vinschen@redhat.com> */

#ifndef _ALLOCA_H_
#define _ALLOCA_H_

#include "_ansi.h"
#include <sys/reent.h>

#undef alloca
#define alloca(size) __builtin_alloca(size)

#endif