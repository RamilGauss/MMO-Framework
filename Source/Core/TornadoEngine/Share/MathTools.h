/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "MathStructs.h"

#define INDEX_I(M,k,n,I) \
M I m(k,n)

// M1 and M2 - TMatrix16 or D3DXMATRIX
// OP - operation, for example -=, +
// I1 and I2 - how access, by . or ->
// k and n - indexes in matrix
#define BASE_MATRIX_OP(M1,M2,OP,I1,I2,k,n) \
INDEX_I(M1,k,n,I1) OP INDEX_I(M2,k,n,I2)

#define MATRIX_ALL(M1,M2,OP,I1,I2,Ck,Cn) \
for(int counter_k = 0 ; counter_k < Ck ; counter_k++) \
for(int counter_n = 0 ; counter_n < Cn ; counter_n++) \
BASE_MATRIX_OP(M1,M2,OP,I1,I2,counter_k,counter_n);

#define MATRIX16_OP(M1,M2,OP,I1,I2) \
MATRIX_ALL(M1,M2,OP,I1,I2,4,4)

//----------------------------------------------------------------------
#define BASE_MATRIX_OP_VALUE(M,VALUE,OP,I,k,n) \
INDEX_I(M,k,n,I) OP VALUE

#define MATRIX_ALL_VALUE(M,VALUE,OP,I,Ck,Cn) \
for(int k = 0 ; k < Ck ; k++) \
for(int n = 0 ; n < Cn ; n++) \
BASE_MATRIX_OP_VALUE(M,VALUE,OP,I,k,n);

#define MATRIX16_OP_V(M,VALUE,OP,I) \
MATRIX_ALL_VALUE(M,VALUE,OP,I,4,4)

//----------------------------------------------------------------------
// Macros for use
// OP - operation, for example, a *= b; M1 = "a", M2 = "b", OP = "*="
// MATRIX16_OP_M_M( a, b, *= )
//----------------------------------------------------------------------
// матрица - матрица
#define MATRIX16_OP_M_M(M1,M2,OP) \
MATRIX16_OP(M1,M2,OP, . , .)

#define MATRIX16_OP_M_P(M1,M2,OP) \
MATRIX16_OP(M1,M2,OP, . , ->)

#define MATRIX16_OP_P_M(M1,M2,OP) \
MATRIX16_OP(M1,M2,OP, -> , .)

#define MATRIX16_OP_P_P(M1,M2,OP) \
MATRIX16_OP(M1,M2,OP, -> , ->)
//----------------------------------------------------------------------
// матрица - float/double
#define MATRIX16_OP_M(M,VALUE,OP) \
MATRIX16_OP_V(M,VALUE,OP, . )

#define MATRIX16_OP_P(M,VALUE,OP) \
MATRIX16_OP_V(M,VALUE,OP, ->)
//----------------------------------------------------------------------
// 
#define MATRIX16_EQUAL_M_M(a,b) \
CopyMatrix16((float*)&b,(float*)&a);

#define MATRIX16_EQUAL_M_P(a,b) \
CopyMatrix16((float*)b,(float*)&a);

#define MATRIX16_EQUAL_P_M(a,b) \
CopyMatrix16((float*)&b,(float*)a);

#define MATRIX16_EQUAL_P_P(a,b) \
CopyMatrix16((float*)b,(float*)a);
//----------------------------------------------------------------------

DllExport extern float GetMathToolsEpsilon();

DllExport extern void CopyMatrix16(float* pSrc, float* pDst);

DllExport extern float CalcDist(const nsMathTools::TMatrix16* m1, const nsMathTools::TMatrix16* m2);

DllExport extern nsMathTools::TMatrix16* SetMatrixIdentity(nsMathTools::TMatrix16* pV);
DllExport extern nsMathTools::TMatrix9* SetMatrixIdentity(nsMathTools::TMatrix9* pV);

DllExport extern nsMathTools::TMatrix16* SetMatrixTranslation(nsMathTools::TMatrix16* pOut,
    float x, float y, float z);

DllExport extern nsMathTools::TMatrix16* SetMatrixRotateX(nsMathTools::TMatrix16* pV, float angle);
DllExport extern nsMathTools::TMatrix16* SetMatrixRotateY(nsMathTools::TMatrix16* pV, float angle);
DllExport extern nsMathTools::TMatrix16* SetMatrixRotateZ(nsMathTools::TMatrix16* pV, float angle);

DllExport extern nsMathTools::TMatrix16* SetMatrixRotationYawPitchRoll(nsMathTools::TMatrix16* pV,
    float Yaw,
    float Pitch,
    float Roll);

DllExport extern nsMathTools::TMatrix16* SetMatrixRotationAxis(nsMathTools::TMatrix16* pOut,
    const nsMathTools::TVector3* pV, float Angle);

DllExport extern void SetMatrixToAxisAngle(const nsMathTools::TMatrix16* pM,
    nsMathTools::TVector3* pVOut, float* pAngleOut);

DllExport extern void SetMatrixToQuaternion(const nsMathTools::TMatrix16* pM,
    nsMathTools::TQuaternion* pQOut, bool correctPI = true);

DllExport extern nsMathTools::TMatrix16* SetMatrixMultiply(nsMathTools::TMatrix16* pOut,
    const nsMathTools::TMatrix16* pM1,
    const nsMathTools::TMatrix16* pM2);

DllExport extern nsMathTools::TMatrix16* SetMatrixPerspectiveFovLH(nsMathTools::TMatrix16* pOut,
    float fovy,
    float Aspect,
    float zn, float zf);

DllExport extern float SetMatrixfDeterminant(const nsMathTools::TMatrix16* pm);

DllExport extern nsMathTools::TMatrix16* SetMatrixInverse(nsMathTools::TMatrix16* pOut,
    float* pDeterminant,
    const nsMathTools::TMatrix16* pM);

DllExport extern nsMathTools::TVector4* SetVec4Cross(nsMathTools::TVector4* pout,
    const nsMathTools::TVector4* pv1,
    const nsMathTools::TVector4* pv2,
    const nsMathTools::TVector4* pv3);

DllExport extern nsMathTools::TVector3* SetVec3Subtract(nsMathTools::TVector3* pOut,
    const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2);

DllExport extern nsMathTools::TVector3* SetVec3TransformCoord(nsMathTools::TVector3* pOut,
    const nsMathTools::TVector3* pV,
    const nsMathTools::TMatrix16* pM);

DllExport extern nsMathTools::TVector3* SetVec3Cross(nsMathTools::TVector3* pOut,
    const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2);

DllExport extern float SetVec3Dot(const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2);

DllExport extern float SetVec3Angle(const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2);

DllExport extern nsMathTools::TVector3* SetVec3Normalize(nsMathTools::TVector3* pOut,
    const nsMathTools::TVector3* pV);

DllExport extern nsMathTools::TPlane* SetPlaneFromPointNormal(nsMathTools::TPlane* pOut,
    const nsMathTools::TVector3* pPoint,
    const nsMathTools::TVector3* pNormal);

DllExport extern nsMathTools::TPlane* SetPlaneFromPoints(nsMathTools::TPlane* pOut,
    const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2,
    const nsMathTools::TVector3* pV3);

DllExport extern nsMathTools::TVector3* SetPlaneIntersectLine(nsMathTools::TVector3* pOut,
    const nsMathTools::TPlane* pP,
    const nsMathTools::TVector3* pV1,
    const nsMathTools::TVector3* pV2);

DllExport extern nsMathTools::TPlane* SetPlaneTransform(nsMathTools::TPlane* pOut,
    const nsMathTools::TPlane* pP,
    const nsMathTools::TMatrix16* pM);

DllExport extern bool SetBoxBoundProbe(const nsMathTools::TVector3* pMin,
    const nsMathTools::TVector3* pMax,
    const nsMathTools::TVector3* pRayPosition,
    const nsMathTools::TVector3* pRayDirection);

DllExport extern bool SetComputeBoundingBox(const nsMathTools::TVector3* pFirstPosition,
    unsigned int NumVertices,
    unsigned int dwStride,
    nsMathTools::TVector3* pMin,
    nsMathTools::TVector3* pMax);

DllExport extern bool SetIntersectTri(const nsMathTools::TVector3* p0,
    const nsMathTools::TVector3* p1,
    const nsMathTools::TVector3* p2,
    const nsMathTools::TVector3* pRayPos,
    const nsMathTools::TVector3* pRayDir,
    float* pU,
    float* pV,
    float* pDist);

DllExport extern bool SetComputeBoundingSphere(const nsMathTools::TVector3* pFirstPosition,
    unsigned int NumVertices,
    unsigned int dwStride,
    nsMathTools::TVector3* pCenter,
    float* pRadius);

DllExport extern bool SetSphereBoundProbe(const nsMathTools::TVector3* pCenter,
    float Radius,
    const nsMathTools::TVector3* pRayPosition,
    const nsMathTools::TVector3* pRayDirection);

DllExport extern nsMathTools::TQuaternion* SetQuaternionMultiply(nsMathTools::TQuaternion* pOut,
    const nsMathTools::TQuaternion* pQ1,
    const nsMathTools::TQuaternion* pQ2);

DllExport extern nsMathTools::TQuaternion* SetQuaternionIdentity(nsMathTools::TQuaternion* pOut);

DllExport extern nsMathTools::TQuaternion* SetQuaternionRotationAxis(nsMathTools::TQuaternion* pOut,
    const nsMathTools::TVector3* pV,
    float Angle);

DllExport extern void SetQuaternionToAxisAngle(const nsMathTools::TQuaternion* pQ,
    nsMathTools::TVector3* pAxis,
    float* pAngle);

DllExport extern float SetQuaternionLength(const nsMathTools::TQuaternion* pQ);

DllExport extern void SetRotatePoint(nsMathTools::TOrientation* pO,
    nsMathTools::TVector3* pPointIn, nsMathTools::TVector3* pPointOut);

DllExport extern void CalcMatrix(nsMathTools::TMatrix16* pOut,
    nsMathTools::TMatrix16* pTo, nsMathTools::TMatrix16* pFrom);

DllExport extern void CalcMatrixByMoveVectors(nsMathTools::TMatrix16* pM,
    nsMathTools::TVector3* pUpTo, nsMathTools::TVector3* pForwardTo,
    nsMathTools::TVector3* pUpFrom, nsMathTools::TVector3* pForwardFrom);

