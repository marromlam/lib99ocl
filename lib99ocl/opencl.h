#ifndef _OPENCL_H_
#define _OPENCL_H_

/*
-------------------------------------------------------------------------------
openCL standard math functions
-------------------------------------------------------------------------------

acos      acosh       acospi    asin
asinh	    asinpi      atan      atan2
atanh	    atanpi	    atan2pi	  cbrt
ceil	    copysign	  cos	      cosh
cospi	    erfc	      erf	      exp
exp2	    exp10	      expm1	    fabs
fdim	    floor	      fma	      fmax
fmin	    fmod	      fract	    frexp
hypot	    ilogb	      ldexp	    lgamma
lgamma_r  log	        log2	    log10
log1p	    logb	      mad	      maxmag
minmag	  modf	      nan	      nextafter
pow	      pown	      powr	    remainder
remquo	  rint	      rootn	    round
rsqrt	    sin	        sincos	  sinh
sinpi	    sqrt	      tan	      tanh
tanpi	    tgamma	    trunc

see www.khronos.org/registry/OpenCL/sdk/1.1/docs/man/xhtml/mathFunctions.html
*/


#ifndef LOCAL_BARRIER
#define LOCAL_BARRIER barrier(CLK_LOCAL_MEM_FENCE)
#endif

// 'static' helps to avoid the "no previous prototype for function" warning
#ifndef WITHIN_KERNEL
	#if __OPENCL_VERSION__ >= 120
    #define WITHIN_KERNEL static
	#else
    #define WITHIN_KERNEL
	#endif
#endif

#define KERNEL __kernel
#define GLOBAL_MEM __global
#define GLOBAL_MEM_ARG __global
#define LOCAL_MEM __local
#define LOCAL_MEM_DYNAMIC __local
#define LOCAL_MEM_ARG __local
#define CONSTANT_MEM __constant
#define CONSTANT_MEM_ARG __constant
// INLINE is already defined in Beignet driver
#ifndef INLINE
#define INLINE inline
#endif
#define SIZE_T size_t
#define VSIZE_T size_t

// used to align fields in structures
#define ALIGN(bytes) __attribute__ ((aligned(bytes)))

#if defined(cl_khr_fp64)
#pragma OPENCL EXTENSION cl_khr_fp64: enable
#elif defined(cl_amd_fp64)
#pragma OPENCL EXTENSION cl_amd_fp64: enable
#endif




#define COMPLEX_CTR(T) (T)




#endif // _OPENCL_H_


// vim: fdm=marker ts=2 sw=2 sts=2 sr et
