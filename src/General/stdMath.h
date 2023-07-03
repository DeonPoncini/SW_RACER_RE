#ifndef STD_MATH_H
#define STD_MATH_H

#include <math.h>
#include <stdbool.h>

#ifndef PI
#define PI (3.141592653589793)
#endif // PI

#define stdMath_SinCos_ADDR (0x0042f380)
#define stdMath_Tan_ADDR (0x0042f3b0)
#define stdMath_ArcSin_ADDR (0x0042f3e0)
#define stdMath_ArcCos_ADDR (0x0042f540)
#define stdMath_ArcTan2_ADDR (0x0042f560)
// address gap
#define stdMath_Unk0_ADDR (0x00480650)
#define stdMath_Sqrt_ADDR (0x00480670)

void stdMath_SinCos(float angle, float* pSinOut, float* pCosOut);
float stdMath_Tan(float angle);
float stdMath_ArcSin(float angle);
float stdMath_ArcCos(float angle);
float stdMath_ArcTan2(float x1, float x2);

float stdMath_Unk0(float param_1, float param_2);
float stdMath_Sqrt(float a);

#endif // STD_MATH_H
