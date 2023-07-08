#ifndef RD_MATRIX_H
#define RD_MATRIX_H

#include "rdVector.h"
#include "types.h"

#define rdMatrix_Multiply44_ADDR (0x0042fb70)
#define rdMatrix_Multiply44Acc_ADDR (0x0042ff80)
#define rdMatrix_Unk1_ADDR (0x00430310)
#define rdMatrix_Multiply3_ADDR (0x00430980)
#define rdMatrix_Transform3_ADDR (0x00430a00)
#define rdMatrix_Multiply4_ADDR (0x00430ab0)
#define rdMatrix_Unk2_ADDR (0x00430b80)
#define rdMatrix_BuildRotation44_ADDR (0x00430e00)
#define rdMatrix_BuildRotation33_ADDR (0x00430f10)
#define rdMatrix_SetRotation44_ADDR (0x00431020)
#define rdMatrix_SetTransform44_ADDR (0x00431060)
#define rdMatrix_SetDiagonal44_ADDR (0x004310b0)
#define rdMatrix_SetTranslation44_ADDR (0x00431100)
#define rdMatrix_BuildFromVectorAngle44_ADDR (0x00431150)
#define rdMatrix_AddRotationFromVectorAngle44Before_ADDR (0x00431390)
#define rdMatrix_SetIdentity44_ADDR (0x004313d0)
#define rdMatrix_AddRotationFromVectorAngle44After_ADDR (0x00431410)
#define rdMatrix_ScaleBasis44_ADDR (0x00431450)
// address gap
#define rdMatrix_TransformPoint44_ADDR (0x00480690)
#define rdMatrix_Unk0_ADDR (0x00480730)

void rdMatrix_Multiply44(rdMatrix44* out, rdMatrix44* mat1, rdMatrix44* mat2);
void rdMatrix_Multiply44Acc(rdMatrix44* out, rdMatrix44* mat2);
void rdMatrix_Unk1(rdMatrix44* m1, rdMatrix44* m2);
void rdMatrix_Multiply3(rdVector3* out, rdVector3* in, rdMatrix44* mat);
void rdMatrix_Transform3(rdVector3* out, rdVector3* in, rdMatrix44* mat);
void rdMatrix_Multiply4(rdVector4* out, rdVector4* in, rdMatrix44* mat);
void rdMatrix_Unk2(rdMatrix44* param_1, float* param_2);
void rdMatrix_BuildRotation44(rdMatrix44* out, float gamma, float alpha, float beta);
void rdMatrix_BuildRotation33(rdMatrix33* out, float gamma, float alpha, float beta);
void rdMatrix_SetRotation44(rdMatrix44* out, float gamma, float alpha, float beta);
void rdMatrix_SetTransform44(rdMatrix44* mat, swr_translation_rotation* v);
void rdMatrix_SetDiagonal44(rdMatrix44* mat, float x, float y, float z);
void rdMatrix_SetTranslation44(rdMatrix44* mat, float x, float y, float z);
void rdMatrix_BuildFromVectorAngle44(rdMatrix44* mat, float angle, float x, float y, float z);
void rdMatrix_AddRotationFromVectorAngle44Before(rdMatrix44* mat_out, float angle, float x, float y, float z, rdMatrix44* mat_in);
void rdMatrix_SetIdentity44(rdMatrix44* mat);
void rdMatrix_AddRotationFromVectorAngle44After(rdMatrix44* mat_out, rdMatrix44* mat_in, float angle, float x, float y, float z);
void rdMatrix_ScaleBasis44(rdMatrix44* out, float scale_right, float scale_forward, float scale_up, rdMatrix44* in);

void rdMatrix_TransformPoint44(rdVector4* a1, const rdVector4* a2, const rdMatrix44* a3);
void rdMatrix_Unk0(rdMatrix44* mat, rdVector3* out_vec1, rdMatrix44* out_mat, rdVector3* out_vec2);

#endif // RD_MATRIX_H
