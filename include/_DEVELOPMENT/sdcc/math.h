
// automatically generated by m4 from headers in proto subdir


#ifndef __MATH_H__
#define __MATH_H__

// THE SELECTED FLOATING POINT PACKAGE MAY NOT SUPPORT ALL LISTED FUNCTIONS

#ifndef _FLOAT_T_DEFINED
#define _FLOAT_T_DEFINED

   #ifdef __CLANG
   
   typedef float float_t;
   
   #endif

   #ifdef __SDCC
   
   typedef float float_t;
   
   #endif
   
   #ifdef __SCCZ80
   
   typedef double float_t;
   
   #endif
   
#endif

#ifndef _DOUBLE_T_DEFINED
#define _DOUBLE_T_DEFINED

   #ifdef __CLANG
   
   typedef float double_t;
   
   #endif

   #ifdef __SDCC
   
   typedef float double_t;
   
   #endif
   
   #ifdef __SCCZ80
   
   typedef double double_t;
   
   #endif
   
#endif

#ifndef _HALF_FLOAT_T
#define _HALF_FLOAT_T

typedef short half_t;           /* IEEE16 half float type */

#endif

// XSI EXTENSION
// temporary : math lib should supply these via func call

#define M_E                    2.718281828459
#define M_LOG2E                1.442695040889
#define M_LOG10E               0.4342944819033
#define M_LN2                  0.693147180560
#define M_LN10                 2.302585092994
#define M_PI                   3.141592653590
#define M_PI_2                 1.570796326795
#define M_PI_4                 0.7853981633974
#define M_1_PI                 0.3183098861838
#define M_2_PI                 0.6366197723676
#define M_2_SQRTPI             1.128379167096
#define M_SQRT2                1.414213562373
#define M_SQRT1_2              0.7071067811865

//

#define FLT_EVAL_METHOD        1
#define MATH_ERRNO             1
#define MATH_ERREXCEPT         2
#define math_errhandling       1

#ifdef __CLANG

#define HUGE_VAL               1.7014117331E+38
#define HUGE_VALF              1.7014117331E+38
#define INFINITY               1.7014117331E+38

#endif

#ifdef __SDCC

#define HUGE_VAL               1.7014117331E+38
#define HUGE_VALF              1.7014117331E+38
#define INFINITY               1.7014117331E+38

#endif

#ifdef __SCCZ80

#define HUGE_VAL               1.7014118346E+38
#define HUGE_VALF              1.7014118346E+38
#define INFINITY               1.7014118346E+38

#endif

#ifdef __MATH_MATH32

#define HUGE_POS_F             (float)+3.4028234664E+38
#define TINY_POS_F             (float)+1.1754943508E−38
#define HUGE_NEG_F             (float)-1.7014118346E+38
#define TINY_NEG_F             (float)-1.1754943508E-38

#define INFINITY_POS_F         ((unsigned long)0x7F800000)
#define INFINITY_NEG_F         ((unsigned long)0xFF800000)

#define MAXL2_F                ((float)+127.999999914)
#define MINL2_F                ((float)-126.0)
#define MAXLOG_F               ((float)+88.722839052)
#define MINLOG_F               ((float)−87.336544751)
#define MAXL10_F               ((float)+38.230809449)
#define MINL10_F               ((float)−37.929779454)

#endif

#ifdef __MATH_MATH16

#define HUGE_POS_HF            (short)0x7BFF        /*  +6.5504E+4 */
#define TINY_POS_HF            (short)0x0400        /*  +6.1035E-5 */
#define HUGE_NEG_HF            (short)0xFBFF        /*  -6.5504E+4 */
#define TINY_NEG_HF            (short)0x8400        /*  -6.1035E-5 */

#define INFINITY_POS_HF        (short)0x7C00
#define INFINITY_NEG_HF        (short)0xFC00

#define MAXL2_HF               (short)0x4BFF        /*  +15.99    */
#define MINL2_HF               (short)0xCB00        /*  -14.00    */
#define MAXLOG_HF              (short)0x498B        /*  +11.086   */
#define MINLOG_HF              (short)0xC8DA        /*  -9.700    */       
#define MAXL10_HF              (short)0x44D1        /*  +4.816    */
#define MINL10_HF              (short)0xC437        /*  -4.215    */

#endif

extern double_t acos(double_t x);
extern double_t acos_fastcall(double_t x) __z88dk_fastcall;
#define acos(a) acos_fastcall(a)


extern double_t asin(double_t x);
extern double_t asin_fastcall(double_t x) __z88dk_fastcall;
#define asin(a) asin_fastcall(a)


extern double_t atan(double_t x);
extern double_t atan_fastcall(double_t x) __z88dk_fastcall;
#define atan(a) atan_fastcall(a)


extern double_t atan2(double_t y,double_t x);
extern double_t atan2_callee(double_t y,double_t x) __z88dk_callee;
#define atan2(a,b) atan2_callee(a,b)



extern double_t cos(double_t x);
extern double_t cos_fastcall(double_t x) __z88dk_fastcall;
#define cos(a) cos_fastcall(a)


extern double_t sin(double_t x);
extern double_t sin_fastcall(double_t x) __z88dk_fastcall;
#define sin(a) sin_fastcall(a)


extern double_t tan(double_t x);
extern double_t tan_fastcall(double_t x) __z88dk_fastcall;
#define tan(a) tan_fastcall(a)



extern double_t acosh(double_t x);
extern double_t acosh_fastcall(double_t x) __z88dk_fastcall;
#define acosh(a) acosh_fastcall(a)


extern double_t asinh(double_t x);
extern double_t asinh_fastcall(double_t x) __z88dk_fastcall;
#define asinh(a) asinh_fastcall(a)


extern double_t atanh(double_t x);
extern double_t atanh_fastcall(double_t x) __z88dk_fastcall;
#define atanh(a) atanh_fastcall(a)



extern double_t cosh(double_t x);
extern double_t cosh_fastcall(double_t x) __z88dk_fastcall;
#define cosh(a) cosh_fastcall(a)


extern double_t sinh(double_t x);
extern double_t sinh_fastcall(double_t x) __z88dk_fastcall;
#define sinh(a) sinh_fastcall(a)


extern double_t tanh(double_t x);
extern double_t tanh_fastcall(double_t x) __z88dk_fastcall;
#define tanh(a) tanh_fastcall(a)



extern double_t exp(double_t x);
extern double_t exp_fastcall(double_t x) __z88dk_fastcall;
#define exp(a) exp_fastcall(a)


extern double_t exp2(double_t x);
extern double_t exp2_fastcall(double_t x) __z88dk_fastcall;
#define exp2(a) exp2_fastcall(a)


extern double_t expm1(double_t x);
extern double_t expm1_fastcall(double_t x) __z88dk_fastcall;
#define expm1(a) expm1_fastcall(a)


extern double_t frexp(double_t value,int *exp);
extern double_t frexp_callee(double_t value,int *exp) __z88dk_callee;
#define frexp(a,b) frexp_callee(a,b)


extern int ilogb(double_t x);
extern int ilogb_fastcall(double_t x) __z88dk_fastcall;
#define ilogb(a) ilogb_fastcall(a)


extern double_t ldexp(double_t x,int exp);
extern double_t ldexp_callee(double_t x,int exp) __z88dk_callee;
#define ldexp(a,b) ldexp_callee(a,b)


#define scalbn(x,pw2) ldexp(x,pw2)

extern double_t log(double_t x);
extern double_t log_fastcall(double_t x) __z88dk_fastcall;
#define log(a) log_fastcall(a)


extern double_t log10(double_t x);
extern double_t log10_fastcall(double_t x) __z88dk_fastcall;
#define log10(a) log10_fastcall(a)


extern double_t log1p(double_t x);
extern double_t log1p_fastcall(double_t x) __z88dk_fastcall;
#define log1p(a) log1p_fastcall(a)


extern double_t log2(double_t x);
extern double_t log2_fastcall(double_t x) __z88dk_fastcall;
#define log2(a) log2_fastcall(a)


extern double_t logb(double_t x);
extern double_t logb_fastcall(double_t x) __z88dk_fastcall;
#define logb(a) logb_fastcall(a)



extern double_t fabs(double_t x);
extern double_t fabs_fastcall(double_t x) __z88dk_fastcall;
#define fabs(a) fabs_fastcall(a)


extern double_t hypot(double_t x,double_t y);
extern double_t hypot_callee(double_t x,double_t y) __z88dk_callee;
#define hypot(a,b) hypot_callee(a,b)



extern double_t pow(double_t x,double_t y);
extern double_t pow_callee(double_t x,double_t y) __z88dk_callee;
#define pow(a,b) pow_callee(a,b)


extern double_t sqrt(double_t x);
extern double_t sqrt_fastcall(double_t x) __z88dk_fastcall;
#define sqrt(a) sqrt_fastcall(a)


extern double_t cbrt(double_t x);
extern double_t cbrt_fastcall(double_t x) __z88dk_fastcall;
#define cbrt(a) cbrt_fastcall(a)



extern double_t erf(double_t x);
extern double_t erf_fastcall(double_t x) __z88dk_fastcall;
#define erf(a) erf_fastcall(a)


extern double_t erfc(double_t x);
extern double_t erfc_fastcall(double_t x) __z88dk_fastcall;
#define erfc(a) erfc_fastcall(a)


extern double_t lgamma(double_t x);
extern double_t lgamma_fastcall(double_t x) __z88dk_fastcall;
#define lgamma(a) lgamma_fastcall(a)


extern double_t tgamma(double_t x);
extern double_t tgamma_fastcall(double_t x) __z88dk_fastcall;
#define tgamma(a) tgamma_fastcall(a)



extern double_t ceil(double_t x);
extern double_t ceil_fastcall(double_t x) __z88dk_fastcall;
#define ceil(a) ceil_fastcall(a)


extern double_t floor(double_t x);
extern double_t floor_fastcall(double_t x) __z88dk_fastcall;
#define floor(a) floor_fastcall(a)


extern double_t nearbyint(double_t x);
extern double_t nearbyint_fastcall(double_t x) __z88dk_fastcall;
#define nearbyint(a) nearbyint_fastcall(a)


extern double_t rint(double_t x);
extern double_t rint_fastcall(double_t x) __z88dk_fastcall;
#define rint(a) rint_fastcall(a)


extern long lrint(double_t x);
extern long lrint_fastcall(double_t x) __z88dk_fastcall;
#define lrint(a) lrint_fastcall(a)


extern double_t round(double_t x);
extern double_t round_fastcall(double_t x) __z88dk_fastcall;
#define round(a) round_fastcall(a)


extern long lround(double_t x);
extern long lround_fastcall(double_t x) __z88dk_fastcall;
#define lround(a) lround_fastcall(a)


extern double_t trunc(double_t x);
extern double_t trunc_fastcall(double_t x) __z88dk_fastcall;
#define trunc(a) trunc_fastcall(a)



extern double_t modf(double_t value,double_t *iptr);
extern double_t modf_callee(double_t value,double_t *iptr) __z88dk_callee;
#define modf(a,b) modf_callee(a,b)


extern double_t fmod(double_t x,double_t y);
extern double_t fmod_callee(double_t x,double_t y) __z88dk_callee;
#define fmod(a,b) fmod_callee(a,b)


extern double_t remainder(double_t x,double_t y);
extern double_t remainder_callee(double_t x,double_t y) __z88dk_callee;
#define remainder(a,b) remainder_callee(a,b)


extern double_t remquo(double_t x,double_t y,int *quo);
extern double_t remquo_callee(double_t x,double_t y,int *quo) __z88dk_callee;
#define remquo(a,b,c) remquo_callee(a,b,c)



extern double_t copysign(double_t x,double_t y);
extern double_t copysign_callee(double_t x,double_t y) __z88dk_callee;
#define copysign(a,b) copysign_callee(a,b)


extern double_t nan(const char *tagp);
extern double_t nan_fastcall(const char *tagp) __z88dk_fastcall;
#define nan(a) nan_fastcall(a)



extern double_t nextafter(double_t x,double_t y);
extern double_t nextafter_callee(double_t x,double_t y) __z88dk_callee;
#define nextafter(a,b) nextafter_callee(a,b)


extern double_t nexttoward(double_t x,double_t y);
extern double_t nexttoward_callee(double_t x,double_t y) __z88dk_callee;
#define nexttoward(a,b) nexttoward_callee(a,b)



extern double_t fdim(double_t x,double_t y);
extern double_t fdim_callee(double_t x,double_t y) __z88dk_callee;
#define fdim(a,b) fdim_callee(a,b)



extern double_t fmax(double_t x,double_t y);
extern double_t fmax_callee(double_t x,double_t y) __z88dk_callee;
#define fmax(a,b) fmax_callee(a,b)


extern double_t fmin(double_t x,double_t y);
extern double_t fmin_callee(double_t x,double_t y) __z88dk_callee;
#define fmin(a,b) fmin_callee(a,b)



extern double_t fma(double_t x,double_t y,double_t z);
extern double_t fma_callee(double_t x,double_t y,double_t z) __z88dk_callee;
#define fma(a,b,c) fma_callee(a,b,c)



extern int isgreater(double_t x,double_t y);
extern int isgreater_callee(double_t x,double_t y) __z88dk_callee;
#define isgreater(a,b) isgreater_callee(a,b)


extern int isgreaterequal(double_t x,double_t y);
extern int isgreaterequal_callee(double_t x,double_t y) __z88dk_callee;
#define isgreaterequal(a,b) isgreaterequal_callee(a,b)


extern int isless(double_t x,double_t y);
extern int isless_callee(double_t x,double_t y) __z88dk_callee;
#define isless(a,b) isless_callee(a,b)


extern int islessequal(double_t x,double_t y);
extern int islessequal_callee(double_t x,double_t y) __z88dk_callee;
#define islessequal(a,b) islessequal_callee(a,b)


extern int islessgreater(double_t x,double_t y);
extern int islessgreater_callee(double_t x,double_t y) __z88dk_callee;
#define islessgreater(a,b) islessgreater_callee(a,b)


extern int isunordered(double_t x,double_t y);
extern int isunordered_callee(double_t x,double_t y) __z88dk_callee;
#define isunordered(a,b) isunordered_callee(a,b)



#ifdef __MATH_MATH32

extern double_t sqr(double_t x);
extern double_t sqr_fastcall(double_t x) __z88dk_fastcall;
#define sqr(a) sqr_fastcall(a)


extern double_t inv(double_t x);
extern double_t inv_fastcall(double_t x) __z88dk_fastcall;
#define inv(a) inv_fastcall(a)


extern double_t invsqrt(double_t x);
extern double_t invsqrt_fastcall(double_t x) __z88dk_fastcall;
#define invsqrt(a) invsqrt_fastcall(a)


extern double_t div2(double_t x);
extern double_t div2_fastcall(double_t x) __z88dk_fastcall;
#define div2(a) div2_fastcall(a)


extern double_t mul2(double_t x);
extern double_t mul2_fastcall(double_t x) __z88dk_fastcall;
#define mul2(a) mul2_fastcall(a)


extern double_t mul10u(double_t x);
extern double_t mul10u_fastcall(double_t x) __z88dk_fastcall;
#define mul10u(a) mul10u_fastcall(a)


extern double_t exp10(double_t x);
extern double_t exp10_fastcall(double_t x) __z88dk_fastcall;
#define exp10(a) exp10_fastcall(a)


extern double_t poly(const float x,const float d[],unsigned int n);
extern double_t poly_callee(const float x,const float d[],unsigned int n) __z88dk_callee;
#define poly(a,b,c) poly_callee(a,b,c)



#endif

#ifdef __MATH_MATH16

extern half_t f16_add(half_t y,half_t x);
extern half_t f16_add_callee(half_t y,half_t x) __z88dk_callee;
#define f16_add(a,b) f16_add_callee(a,b)


extern half_t f16_sub(half_t y,half_t x);
extern half_t f16_sub_callee(half_t y,half_t x) __z88dk_callee;
#define f16_sub(a,b) f16_sub_callee(a,b)


extern half_t f16_mul(half_t y,half_t x);
extern half_t f16_mul_callee(half_t y,half_t x) __z88dk_callee;
#define f16_mul(a,b) f16_mul_callee(a,b)


extern half_t f16_div(half_t y,half_t x);
extern half_t f16_div_callee(half_t y,half_t x) __z88dk_callee;
#define f16_div(a,b) f16_div_callee(a,b)



extern half_t f16_acos(half_t x);
extern half_t f16_acos_fastcall(half_t x) __z88dk_fastcall;
#define f16_acos(a) f16_acos_fastcall(a)


extern half_t f16_asin(half_t x);
extern half_t f16_asin_fastcall(half_t x) __z88dk_fastcall;
#define f16_asin(a) f16_asin_fastcall(a)


extern half_t f16_atan(half_t x);
extern half_t f16_atan_fastcall(half_t x) __z88dk_fastcall;
#define f16_atan(a) f16_atan_fastcall(a)


extern half_t f16_atan2(half_t y,half_t x);
extern half_t f16_atan2_callee(half_t y,half_t x) __z88dk_callee;
#define f16_atan2(a,b) f16_atan2_callee(a,b)



extern half_t f16_cos(half_t x);
extern half_t f16_cos_fastcall(half_t x) __z88dk_fastcall;
#define f16_cos(a) f16_cos_fastcall(a)


extern half_t f16_sin(half_t x);
extern half_t f16_sin_fastcall(half_t x) __z88dk_fastcall;
#define f16_sin(a) f16_sin_fastcall(a)


extern half_t f16_tan(half_t x);
extern half_t f16_tan_fastcall(half_t x) __z88dk_fastcall;
#define f16_tan(a) f16_tan_fastcall(a)



extern half_t f16_acosh(half_t x);
extern half_t f16_acosh_fastcall(half_t x) __z88dk_fastcall;
#define f16_acosh(a) f16_acosh_fastcall(a)


extern half_t f16_asinh(half_t x);
extern half_t f16_asinh_fastcall(half_t x) __z88dk_fastcall;
#define f16_asinh(a) f16_asinh_fastcall(a)


extern half_t f16_atanh(half_t x);
extern half_t f16_atanh_fastcall(half_t x) __z88dk_fastcall;
#define f16_atanh(a) f16_atanh_fastcall(a)



extern half_t f16_cosh(half_t x);
extern half_t f16_cosh_fastcall(half_t x) __z88dk_fastcall;
#define f16_cosh(a) f16_cosh_fastcall(a)


extern half_t f16_sinh(half_t x);
extern half_t f16_sinh_fastcall(half_t x) __z88dk_fastcall;
#define f16_sinh(a) f16_sinh_fastcall(a)


extern half_t f16_tanh(half_t x);
extern half_t f16_tanh_fastcall(half_t x) __z88dk_fastcall;
#define f16_tanh(a) f16_tanh_fastcall(a)



extern half_t f16_exp(half_t x);
extern half_t f16_exp_fastcall(half_t x) __z88dk_fastcall;
#define f16_exp(a) f16_exp_fastcall(a)


extern half_t f16_exp2(half_t x);
extern half_t f16_exp2_fastcall(half_t x) __z88dk_fastcall;
#define f16_exp2(a) f16_exp2_fastcall(a)


extern half_t f16_expm1(half_t x);
extern half_t f16_expm1_fastcall(half_t x) __z88dk_fastcall;
#define f16_expm1(a) f16_expm1_fastcall(a)


extern half_t f16_frexp(half_t value,int *exp);
extern half_t f16_frexp_callee(half_t value,int *exp) __z88dk_callee;
#define f16_frexp(a,b) f16_frexp_callee(a,b)


extern int f16_ilogb(half_t x);
extern int f16_ilogb_fastcall(half_t x) __z88dk_fastcall;
#define f16_ilogb(a) f16_ilogb_fastcall(a)


extern half_t f16_ldexp(half_t x,int exp);
extern half_t f16_ldexp_callee(half_t x,int exp) __z88dk_callee;
#define f16_ldexp(a,b) f16_ldexp_callee(a,b)


#define scalbn(x,pw2) ldexp(x,pw2)

extern half_t f16_log(half_t x);
extern half_t f16_log_fastcall(half_t x) __z88dk_fastcall;
#define f16_log(a) f16_log_fastcall(a)


extern half_t f16_log10(half_t x);
extern half_t f16_log10_fastcall(half_t x) __z88dk_fastcall;
#define f16_log10(a) f16_log10_fastcall(a)


extern half_t f16_log1p(half_t x);
extern half_t f16_log1p_fastcall(half_t x) __z88dk_fastcall;
#define f16_log1p(a) f16_log1p_fastcall(a)


extern half_t f16_log2(half_t x);
extern half_t f16_log2_fastcall(half_t x) __z88dk_fastcall;
#define f16_log2(a) f16_log2_fastcall(a)


extern half_t f16_logb(half_t x);
extern half_t f16_logb_fastcall(half_t x) __z88dk_fastcall;
#define f16_logb(a) f16_logb_fastcall(a)



extern half_t f16_fabs(half_t x);
extern half_t f16_fabs_fastcall(half_t x) __z88dk_fastcall;
#define f16_fabs(a) f16_fabs_fastcall(a)


extern half_t f16_hypot(half_t x,half_t y);
extern half_t f16_hypot_callee(half_t x,half_t y) __z88dk_callee;
#define f16_hypot(a,b) f16_hypot_callee(a,b)



extern half_t f16_pow(half_t x,half_t y);
extern half_t f16_pow_callee(half_t x,half_t y) __z88dk_callee;
#define f16_pow(a,b) f16_pow_callee(a,b)


extern half_t f16_sqrt(half_t x);
extern half_t f16_sqrt_fastcall(half_t x) __z88dk_fastcall;
#define f16_sqrt(a) f16_sqrt_fastcall(a)


extern half_t f16_cbrt(half_t x);
extern half_t f16_cbrt_fastcall(half_t x) __z88dk_fastcall;
#define f16_cbrt(a) f16_cbrt_fastcall(a)



extern half_t f16_erf(half_t x);
extern half_t f16_erf_fastcall(half_t x) __z88dk_fastcall;
#define f16_erf(a) f16_erf_fastcall(a)


extern half_t f16_erfc(half_t x);
extern half_t f16_erfc_fastcall(half_t x) __z88dk_fastcall;
#define f16_erfc(a) f16_erfc_fastcall(a)


extern half_t f16_lgamma(half_t x);
extern half_t f16_lgamma_fastcall(half_t x) __z88dk_fastcall;
#define f16_lgamma(a) f16_lgamma_fastcall(a)


extern half_t f16_tgamma(half_t x);
extern half_t f16_tgamma_fastcall(half_t x) __z88dk_fastcall;
#define f16_tgamma(a) f16_tgamma_fastcall(a)



extern half_t f16_ceil(half_t x);
extern half_t f16_ceil_fastcall(half_t x) __z88dk_fastcall;
#define f16_ceil(a) f16_ceil_fastcall(a)


extern half_t f16_floor(half_t x);
extern half_t f16_floor_fastcall(half_t x) __z88dk_fastcall;
#define f16_floor(a) f16_floor_fastcall(a)


extern half_t f16_nearbyint(half_t x);
extern half_t f16_nearbyint_fastcall(half_t x) __z88dk_fastcall;
#define f16_nearbyint(a) f16_nearbyint_fastcall(a)


extern half_t f16_rint(half_t x);
extern half_t f16_rint_fastcall(half_t x) __z88dk_fastcall;
#define f16_rint(a) f16_rint_fastcall(a)


extern int f16_lrint(half_t x);
extern int f16_lrint_fastcall(half_t x) __z88dk_fastcall;
#define f16_lrint(a) f16_lrint_fastcall(a)


extern double_t f16_round(half_t x);
extern double_t f16_round_fastcall(half_t x) __z88dk_fastcall;
#define f16_round(a) f16_round_fastcall(a)


extern long f16_lround(half_t x);
extern long f16_lround_fastcall(half_t x) __z88dk_fastcall;
#define f16_lround(a) f16_lround_fastcall(a)


extern half_t f16_trunc(half_t x);
extern half_t f16_trunc_fastcall(half_t x) __z88dk_fastcall;
#define f16_trunc(a) f16_trunc_fastcall(a)



extern half_t f16_modf(half_t value,half_t *iptr);
extern half_t f16_modf_callee(half_t value,half_t *iptr) __z88dk_callee;
#define f16_modf(a,b) f16_modf_callee(a,b)


extern half_t f16_fmod(half_t x,half_t y);
extern half_t f16_fmod_callee(half_t x,half_t y) __z88dk_callee;
#define f16_fmod(a,b) f16_fmod_callee(a,b)


extern half_t f16_remainder(half_t x,half_t y);
extern half_t f16_remainder_callee(half_t x,half_t y) __z88dk_callee;
#define f16_remainder(a,b) f16_remainder_callee(a,b)


extern half_t f16_remquo(half_t x,half_t y,int *quo);
extern half_t f16_remquo_callee(half_t x,half_t y,int *quo) __z88dk_callee;
#define f16_remquo(a,b,c) f16_remquo_callee(a,b,c)



extern half_t f16_copysign(half_t x,half_t y);
extern half_t f16_copysign_callee(half_t x,half_t y) __z88dk_callee;
#define f16_copysign(a,b) f16_copysign_callee(a,b)


extern half_t f16_nan(const char *tagp);
extern half_t f16_nan_fastcall(const char *tagp) __z88dk_fastcall;
#define f16_nan(a) f16_nan_fastcall(a)



extern half_t f16_nextafter(half_t x,half_t y);
extern half_t f16_nextafter_callee(half_t x,half_t y) __z88dk_callee;
#define f16_nextafter(a,b) f16_nextafter_callee(a,b)


extern half_t f16_nexttoward(half_t x,half_t y);
extern half_t f16_nexttoward_callee(half_t x,half_t y) __z88dk_callee;
#define f16_nexttoward(a,b) f16_nexttoward_callee(a,b)



extern half_t f16_fdim(half_t x,half_t y);
extern half_t f16_fdim_callee(half_t x,half_t y) __z88dk_callee;
#define f16_fdim(a,b) f16_fdim_callee(a,b)



extern half_t f16_fmax(half_t x,half_t y);
extern half_t f16_fmax_callee(half_t x,half_t y) __z88dk_callee;
#define f16_fmax(a,b) f16_fmax_callee(a,b)


extern half_t f16_fmin(half_t x,half_t y);
extern half_t f16_fmin_callee(half_t x,half_t y) __z88dk_callee;
#define f16_fmin(a,b) f16_fmin_callee(a,b)



extern half_t f16_fma(half_t x,half_t y,half_t z);
extern half_t f16_fma_callee(half_t x,half_t y,half_t z) __z88dk_callee;
#define f16_fma(a,b,c) f16_fma_callee(a,b,c)



extern int f16_isgreater(half_t x,half_t y);
extern int f16_isgreater_callee(half_t x,half_t y) __z88dk_callee;
#define f16_isgreater(a,b) f16_isgreater_callee(a,b)


extern int f16_isgreaterequal(half_t x,half_t y);
extern int f16_isgreaterequal_callee(half_t x,half_t y) __z88dk_callee;
#define f16_isgreaterequal(a,b) f16_isgreaterequal_callee(a,b)


extern int f16_isless(half_t x,half_t y);
extern int f16_isless_callee(half_t x,half_t y) __z88dk_callee;
#define f16_isless(a,b) f16_isless_callee(a,b)


extern int f16_islessequal(half_t x,half_t y);
extern int f16_islessequal_callee(half_t x,half_t y) __z88dk_callee;
#define f16_islessequal(a,b) f16_islessequal_callee(a,b)


extern int f16_islessgreater(half_t x,half_t y);
extern int f16_islessgreater_callee(half_t x,half_t y) __z88dk_callee;
#define f16_islessgreater(a,b) f16_islessgreater_callee(a,b)


extern int f16_isunordered(half_t x,half_t y);
extern int f16_isunordered_callee(half_t x,half_t y) __z88dk_callee;
#define f16_isunordered(a,b) f16_isunordered_callee(a,b)



extern half_t f16_neg(half_t x);
extern half_t f16_neg_fastcall(half_t x) __z88dk_fastcall;
#define f16_neg(a) f16_neg_fastcall(a)


extern half_t f16_sqr(half_t x);
extern half_t f16_sqr_fastcall(half_t x) __z88dk_fastcall;
#define f16_sqr(a) f16_sqr_fastcall(a)


extern half_t f16_inv(half_t x);
extern half_t f16_inv_fastcall(half_t x) __z88dk_fastcall;
#define f16_inv(a) f16_inv_fastcall(a)


extern half_t f16_invsqrt(half_t x);
extern half_t f16_invsqrt_fastcall(half_t x) __z88dk_fastcall;
#define f16_invsqrt(a) f16_invsqrt_fastcall(a)


extern half_t f16_div2(half_t x);
extern half_t f16_div2_fastcall(half_t x) __z88dk_fastcall;
#define f16_div2(a) f16_div2_fastcall(a)


extern half_t f16_mul2(half_t x);
extern half_t f16_mul2_fastcall(half_t x) __z88dk_fastcall;
#define f16_mul2(a) f16_mul2_fastcall(a)


extern half_t f16_mul10u(half_t x);
extern half_t f16_mul10u_fastcall(half_t x) __z88dk_fastcall;
#define f16_mul10u(a) f16_mul10u_fastcall(a)


extern half_t f16_exp10(half_t x);
extern half_t f16_exp10_fastcall(half_t x) __z88dk_fastcall;
#define f16_exp10(a) f16_exp10_fastcall(a)


extern double_t f16_poly(const half_t x,const half_t d[],unsigned int n);
extern double_t f16_poly_callee(const half_t x,const half_t d[],unsigned int n) __z88dk_callee;
#define f16_poly(a,b,c) f16_poly_callee(a,b,c)



#endif

// NO DISTINCTION BETWEEN FLOAT AND DOUBLE

#define acosf        acos
#define asinf        asin
#define atanf        atan
#define atan2f       atan2

#define cosf         cos
#define sinf         sin
#define tanf         tan

#define acoshf       acosh
#define asinhf       asinh
#define atanhf       atanh

#define coshf        cosh
#define sinhf        sinh
#define tanhf        tanh

#define expf         exp
#define exp2f        exp2
#define expm1f       expm1
#define frexpf       frexp
#define ilogbf       ilogb
#define ldexpf       ldexp

#define logf         log
#define log10f       log10
#define log1pf       log1p
#define log2f        log2
#define logbf        logb

#define scalbnf      scalbn
#define scalblnf     scalbln

#define fabsf        fabs
#define hypotf       hypot

#define powf         pow
#define sqrtf        sqrt
#define cbrtf        cbrt

#define erff         erf
#define erfcf        erfc
#define lgammaf      lgamma
#define tgammaf      tgamma

#define ceilf        ceil
#define floorf       floor
#define nearbyintf   nearbyint
#define rintf        rint
#define lrintf       lrint
#define llrintf      llrint
#define roundf       round
#define lroundf      lround
#define llroundf     llround
#define truncf       trunc

#define modff        modf
#define fmodf        fmod
#define remainderf   remainder
#define remquof      remquo

#define copysignf    copysign
#define nanf         nan

#define nextafterf   nextafter
#define nexttowardf  nexttoward

#define fdimf        fdim

#define fmaxf        fmax
#define fminf        fmin

#define fmaf         fma

#ifdef __MATH_MATH32

#define sqrf         sqr
#define invf         inv
#define invsqrtf     insqrt
#define div2f        div2
#define mul2f        mul2
#define mul10uf      mul10u
#define exp10f       exp10
#define polyf        poly

#endif

#endif
