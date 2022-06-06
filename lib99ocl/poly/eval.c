#ifndef _EVAL_C_
#define _EVAL_C_

#include "eval.h"

/*
 * Evaluates polynomial of degree N:
 *
 *                     2          N
 * y  =  C  + C x + C x  +...+ C x
 *        0    1     2          N
 *
 * Coefficients are stored in reverse order:
 *
 * coef[0] = C  , ..., coef[N] = C  .
 *            N                   0
 *
 */
WITHIN_KERNEL
ftype polyeval(ftype x, ftype *coef, const int N) {
  ftype ans;
  int i;
  ftype *p;

  p = coef;
  ans = *p++;
  i = N;

  do {
    ans = ans * x + *p++;
  } while (--i);

  return ans;
}

/*
 * Evaluate polynomial when coefficient of x  is 1.0.
 * Otherwise same as polevl.
 */
WITHIN_KERNEL
ftype pol1eval(ftype x, ftype *coef, const int N) {
  ftype ans;
  ftype *p;
  int i;

  p = coef;
  ans = x + *p++;
  i = N - 1;

  do {
    ans = ans * x + *p++;
  } while (--i);

  return ans;
}

#endif // _EVAL_C_

// vim: fdm=marker ts=2 sw=2 sts=2 sr noet
