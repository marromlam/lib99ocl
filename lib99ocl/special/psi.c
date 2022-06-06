#ifndef _PSI_C_
#define _PSI_C_

#include "psi.h"
#include "lib99ocl/machine.h"
// #include "../poly/eval.c"

// WITHIN_KERNEL
// ftype psi(ftype x) {
//
//   const ftype GAMMA = 0.577215664901532860606512090082;
//   const ftype GAMMA_MINX = 1.e-12;
//   const ftype DIGAMMA_MINNEGX = -1250;
//   const ftype C_LIMIT = 49;
//   const ftype S_LIMIT = 1e-5;
//
//   if (x == floor(x)) {
//     // mtherr_with_arg("psi", CEPHES_SING, x);
// 		if ( x < 0)
// 			return NaN;
// 		else if (floor(x) == 0)
// 			return -MAXNUM;
// 		// else
//
//   }
//   ftype value = 0;
//
//   while (1) {
//
//     if (x >= 0 && x < GAMMA_MINX) {
//       x = GAMMA_MINX;
//     }
//     if (x < DIGAMMA_MINNEGX) {
//       x = DIGAMMA_MINNEGX + GAMMA_MINX;
//       continue;
//     }
//     if (x > 0 && x <= S_LIMIT) {
//       return value + -GAMMA - 1 / x;
//     }
//
//     if (x >= C_LIMIT) {
//       ftype inv = 1 / (x * x);
//       return value + log(x) - 0.5 / x - inv * ((1.0 / 12) + inv * (1.0 / 120 - inv / 252));
//     }
//
//     value -= 1 / x;
//     x = x + 1;
//   }
// }




// WITHIN_KERNEL
// ftype psi(ftype x) {
//   ftype p, q, nz, s, w, y, z;
//   int i, n, negative = 0;
// 	ftype A[] = {
// 		8.33333333333333333333E-2, -2.10927960927960927961E-2,
// 		7.57575757575757575758E-3, -4.16666666666666666667E-3,
// 		3.96825396825396825397E-3, -8.33333333333333333333E-3,
// 		8.33333333333333333333E-2
// 	};
//
//   nz = 0.0;
//
//   if (x <= 0.0) {
//     negative = 1;
//     q = x;
//     p = floor(q);
//     if (p == q) {
//       // mtherr_with_arg("psi", CEPHES_SING, x);
//       return MAXNUM;
//     }
//     /* Remove the zeros of tan(PI x) by subtracting the nearest
//        integer from x
//      */
//     nz = q - p;
//     if (nz != 0.5) {
//       if (nz > 0.5) {
//         p += 1.0;
//         nz = q - p;
//       }
//       nz = M_PI / tan(M_PI * nz);
//     } else {
//       nz = 0.0;
//     }
//     x = 1.0 - x;
//   }
//
//   /* check for positive integer up to 10 */
//   if (x <= 10.0 && x == floor(x)) {
//     y = 0.0;
//     n = x;
//     for (i = 1; i < n; i++) {
//       w = i;
//       y += 1.0 / w;
//     }
//     y -= M_EULER;
//     if (negative) {
//       y -= nz;
//     }
//     return y;
//   }
//
//   s = x;
//   w = 0.0;
//   while (s < 10.0) {
//     w += 1.0 / s;
//     s += 1.0;
//   }
//
//   if (s < 1.0e17) {
//     z = 1.0 / (s * s);
//     y = z * polyeval(z, A, 6);
//   } else {
//     y = 0.0;
//   }
//
//   y = log(s) - (0.5 / s) - y - w;
//
//   return y;
// }

#endif // _PSI_C_

// vim: fdm=marker ts=2 sw=2 sts=2 sr noet
