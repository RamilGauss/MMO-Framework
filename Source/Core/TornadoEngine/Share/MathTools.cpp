/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// Some parts of source code from http://wine.sourcearchive.com.
// Thank you, Wine! Viva GPL!


#define _USE_MATH_DEFINES
#include <cmath>

#include <memory.h>
#include <stddef.h>
#include <stdlib.h>

#include "Base/Common/BL_Debug.h"

#include "TornadoEngine/Share/MathTools.h"

namespace nsMathTools
{
    const float msEpsilon = 1e-05f;// максимальная погрешность
}

using namespace nsMathTools;

float GetMathToolsEpsilon()
{
    return msEpsilon;
}
//-------------------------------------------------------------------------
void CopyMatrix16(float* pSrc, float* pDst)
{
    memcpy(pDst, pSrc, sizeof(TMatrix16));
}
//-------------------------------------------------------------------------
float CalcDist(const TMatrix16* m1, const TMatrix16* m2)
{
    TVector3 dist;
    dist.x = m1->_41 - m2->_41;
    dist.y = m1->_42 - m2->_42;
    dist.z = m1->_43 - m2->_43;
    return dist.length();
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixIdentity(TMatrix16* pV)
{
    pV->_11 = 1.0f; pV->_12 = 0.0f; pV->_13 = 0.0f; pV->_14 = 0.0f;
    pV->_21 = 0.0f; pV->_22 = 1.0f; pV->_23 = 0.0f; pV->_24 = 0.0f;
    pV->_31 = 0.0f; pV->_32 = 0.0f; pV->_33 = 1.0f; pV->_34 = 0.0f;
    pV->_41 = 0.0f; pV->_42 = 0.0f; pV->_43 = 0.0f; pV->_44 = 1.0f;
    return pV;
}
//-------------------------------------------------------------------------
TMatrix9* SetMatrixIdentity(TMatrix9* pV)
{
    pV->_11 = 1.0f;  pV->_12 = 0.0f;  pV->_13 = 0.0f;
    pV->_21 = 0.0f;  pV->_22 = 1.0f;  pV->_23 = 0.0f;
    pV->_31 = 0.0f;  pV->_32 = 0.0f;  pV->_33 = 1.0f;
    return pV;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixTranslation(TMatrix16* pOut, float x, float y, float z)
{
    pOut->_11 = 1.0f; pOut->_12 = 0.0f; pOut->_13 = 0.0f; pOut->_14 = 0.0f;
    pOut->_21 = 0.0f; pOut->_22 = 1.0f; pOut->_23 = 0.0f; pOut->_24 = 0.0f;
    pOut->_31 = 0.0f; pOut->_32 = 0.0f; pOut->_33 = 1.0f; pOut->_34 = 0.0f;
    pOut->_41 = x;    pOut->_42 = y;    pOut->_43 = z;    pOut->_44 = 1.0f;
    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateX(TMatrix16* pOut, float angle)
{
    float sin = sinf(angle);
    float cos = cosf(angle);

    pOut->_11 = 1.0f; pOut->_12 = 0.0f; pOut->_13 = 0.0f; pOut->_14 = 0.0f;
    pOut->_21 = 0.0f; pOut->_22 = cos;  pOut->_23 = sin;  pOut->_24 = 0.0f;
    pOut->_31 = 0.0f; pOut->_32 = -sin; pOut->_33 = cos;  pOut->_34 = 0.0f;
    pOut->_41 = 0.0f; pOut->_42 = 0.0f; pOut->_43 = 0.0f; pOut->_44 = 1.0f;

    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateY(TMatrix16* pOut, float angle)
{
    float sin = sinf(angle),
        cos = cosf(angle);

    pOut->_11 = cos;  pOut->_12 = 0.0f; pOut->_13 = -sin; pOut->_14 = 0.0f;
    pOut->_21 = 0.0f; pOut->_22 = 1.0f; pOut->_23 = 0.0f; pOut->_24 = 0.0f;
    pOut->_31 = sin;  pOut->_32 = 0.0f; pOut->_33 = cos;  pOut->_34 = 0.0f;
    pOut->_41 = 0.0f; pOut->_42 = 0.0f; pOut->_43 = 0.0f; pOut->_44 = 1.0f;

    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateZ(TMatrix16* pOut, float angle)
{
    float sin = sinf(angle),
        cos = cosf(angle);

    pOut->_11 = cos;  pOut->_12 = sin;  pOut->_13 = 0.0f; pOut->_14 = 0.0f;
    pOut->_21 = -sin; pOut->_22 = cos;  pOut->_23 = 0.0f; pOut->_24 = 0.0f;
    pOut->_31 = 0.0f; pOut->_32 = 0.0f; pOut->_33 = 1.0f; pOut->_34 = 0.0f;
    pOut->_41 = 0.0f; pOut->_42 = 0.0f; pOut->_43 = 0.0f; pOut->_44 = 1.0f;

    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotationYawPitchRoll(TMatrix16* pOut, float Yaw, float Pitch, float Roll)
{
    TMatrix16 m;

    SetMatrixIdentity(pOut);
    SetMatrixRotateZ(&m, Roll);
    SetMatrixMultiply(pOut, pOut, &m);
    SetMatrixRotateX(&m, Pitch);
    SetMatrixMultiply(pOut, pOut, &m);
    SetMatrixRotateY(&m, Yaw);
    SetMatrixMultiply(pOut, pOut, &m);
    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotationAxis(TMatrix16* pOut, const TVector3* pV, float Angle)
{
    if ( pOut == nullptr )
        return pOut;

    TVector3 v;

    float cosA = cos(Angle);
    float sinA = sin(Angle);

    float _1_cosA = 1.0f - cosA;

    SetVec3Normalize(&v, pV);
    SetMatrixIdentity(pOut);
    pOut->m(0,0) = _1_cosA * v.x * v.x + cosA;
    pOut->m(1,0) = _1_cosA * v.x * v.y - sinA * v.z;
    pOut->m(2,0) = _1_cosA * v.x * v.z + sinA * v.y;
    pOut->m(0,1) = _1_cosA * v.y * v.x + sinA * v.z;
    pOut->m(1,1) = _1_cosA * v.y * v.y + cosA;
    pOut->m(2,1) = _1_cosA * v.y * v.z - sinA * v.x;
    pOut->m(0,2) = _1_cosA * v.z * v.x - sinA * v.y;
    pOut->m(1,2) = _1_cosA * v.z * v.y + sinA * v.x;
    pOut->m(2,2) = _1_cosA * v.z * v.z + cosA;
    return pOut;
}
//-------------------------------------------------------------------------
void SetMatrixToAxisAngle(const TMatrix16* pM, TVector3* pVOut, float* pAngleOut)
{
    float cosA   = (pM->m(0,0) + pM->m(1,1) + pM->m(2,2) - 1) / 2;
    float _21_12 = (pM->m(2,1) - pM->m(1,2));
    float _02_20 = (pM->m(0,2) - pM->m(2,0));
    float _10_01 = (pM->m(1,0) - pM->m(0,1));
    float sinA = sqrt(_21_12 * _21_12 + _02_20 * _02_20 + _10_01 * _10_01);

    // возможно два варианта
    float plusAngle = atan2(sinA / 2.0f, cosA);
    // проверка на ноль о окрестности Пи
    if ( plusAngle <= msEpsilon ) {
        *pAngleOut = 0;
        pVOut->x = 1;// не имеет значения какая ось
        pVOut->y = 0;
        pVOut->z = 0;
        return;
    }

    if ( plusAngle >= M_PI - msEpsilon ) {// в окрестностях ПИ
      // численный метод, конкурс на лучший результат.
        const int countCheckAxis = 14;
        TVector3 checkAxis[countCheckAxis];
        // орто
        checkAxis[0] = TVector3(1, 0, 0);
        checkAxis[1] = TVector3(0, 1, 0);
        checkAxis[2] = TVector3(0, 0, 1);
        checkAxis[3] = TVector3(-1, 0, 0);
        checkAxis[4] = TVector3(0, -1, 0);
        checkAxis[5] = TVector3(0, 0, -1);
        // по углам
        checkAxis[6] = TVector3(1, 1, 1);
        checkAxis[7] = TVector3(1, 1, -1);
        checkAxis[8] = TVector3(1, -1, 1);
        checkAxis[9] = TVector3(1, -1, -1);
        checkAxis[10] = TVector3(-1, 1, 1);
        checkAxis[11] = TVector3(-1, 1, -1);
        checkAxis[12] = TVector3(-1, -1, 1);
        checkAxis[13] = TVector3(-1, -1, -1);

        float diffDelta = 10000.0f;
        TVector3 searchDelta;
        int searchIndexAxis = -1;
        for ( int iCheckAxis = 0; iCheckAxis < countCheckAxis; iCheckAxis++ ) {
            TVector3 rotPoint;
            SetVec3TransformCoord(&rotPoint, &checkAxis[iCheckAxis], pM);
            TVector3 d = rotPoint - checkAxis[iCheckAxis];// куда повернулись?
            if ( diffDelta > d.length() ) {
                searchDelta = d;
                diffDelta = d.length();
                searchIndexAxis = iCheckAxis;
            }
        }
        if ( searchIndexAxis == -1 ) {
            BL_FIX_BUG();
            return;
        }
        *pVOut = checkAxis[searchIndexAxis] + searchDelta / 2.0f;
        *pAngleOut = float(M_PI);
        return;
    }

    float plusX = (pM->m(2,1) - pM->m(1,2)) / sinA;
    float plusY = (pM->m(0,2) - pM->m(2,0)) / sinA;
    float plusZ = (pM->m(1,0) - pM->m(0,1)) / sinA;

    float minusX = -plusX;
    float minusY = -plusY;
    float minusZ = -plusZ;

    const int countVariant = 8;
    TVector3 axis[countVariant];
    axis[0] = TVector3(plusX, plusY, plusZ);
    axis[1] = TVector3(plusX, plusY, minusZ);
    axis[2] = TVector3(plusX, minusY, plusZ);
    axis[3] = TVector3(plusX, minusY, minusZ);

    axis[4] = TVector3(minusX, plusY, plusZ);
    axis[5] = TVector3(minusX, plusY, minusZ);
    axis[6] = TVector3(minusX, minusY, plusZ);
    axis[7] = TVector3(minusX, minusY, minusZ);

    float diff = 1000.0f;
    int searchIndex = -1;
    for ( int i = 0; i < countVariant; i++ ) {
        TMatrix16 maybeM;
        SetMatrixRotationAxis(&maybeM, &axis[i], plusAngle);

        float sumDiff = 0;
        for ( int iColumn = 0; iColumn < 3; iColumn++ ) {
            for ( int iRow = 0; iRow < 3; iRow++ )
                sumDiff += abs(pM->m(iColumn,iRow) - maybeM.m(iColumn,iRow));
        }
        if ( diff > sumDiff ) {
            diff = sumDiff;
            searchIndex = i;
        }
    }
    if ( searchIndex == -1 ) {
        // не нашли
        BL_FIX_BUG();
        return;
    }
    *pVOut = axis[searchIndex];
    *pAngleOut = plusAngle;
    /*
      from Martin Baker

      angle = ( m00 + m11 + m22 - 1)/2;
      x = (m21 - m12)/sqrt((m21 - m12)2+(m02 - m20)2+(m10 - m01)2);
      y = (m02 - m20)/√((m21 - m12)2+(m02 - m20)2+(m10 - m01)2);
      z = (m10 - m01)/√((m21 - m12)2+(m02 - m20)2+(m10 - m01)2);
    */
}
//-------------------------------------------------------------------------
void SetMatrixToQuaternion(const TMatrix16* pM, TQuaternion* pQOut, bool correctPI)
{
    TVector3 axis;
    float angle;
    SetMatrixToAxisAngle(pM, &axis, &angle);
    if ( correctPI )// коррекция в окрестностях
    {
        float broad = float(M_PI - msEpsilon);
        float setAngle = float(M_PI - 2 * msEpsilon);
        if ( angle > broad )
            angle = setAngle;
        else if ( angle < -broad )
            angle = -setAngle;
    }

    SetQuaternionRotationAxis(pQOut, &axis, angle);
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixMultiply(TMatrix16* pOut, const TMatrix16* pM1, const TMatrix16* pM2)
{
    if ( pOut == nullptr )
        return pOut;

    TMatrix16 resM;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            resM.m(i,j) = pM1->m(i,0) * pM2->m(0,j) +
                          pM1->m(i,1) * pM2->m(1,j) +
                          pM1->m(i,2) * pM2->m(2,j) +
                          pM1->m(i,3) * pM2->m(3,j);
        }
    }
    *pOut = resM;
    return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Subtract(TVector3* pOut, const TVector3* pV1, const TVector3* pV2)
{
    if ( pOut == nullptr )
        return pOut;

    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetVec3TransformCoord(TVector3* pOut, const TVector3* pV, const TMatrix16* pM)
{
    float norm;

    norm = pM->m(0,3) * pV->x + pM->m(1,3) * pV->y + pM->m(2,3) * pV->z + pM->m(3,3);

    if ( norm ) {
        const TVector3 v = *pV;
        pOut->x = (pM->m(0,0) * v.x + pM->m(1,0) * v.y + pM->m(2,0) * v.z + pM->m(3,0)) / norm;
        pOut->y = (pM->m(0,1) * v.x + pM->m(1,1) * v.y + pM->m(2,1) * v.z + pM->m(3,1)) / norm;
        pOut->z = (pM->m(0,2) * v.x + pM->m(1,2) * v.y + pM->m(2,2) * v.z + pM->m(3,2)) / norm;
    } else {
        pOut->x = 0.0f;
        pOut->y = 0.0f;
        pOut->z = 0.0f;
    }
    return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Cross(TVector3* pOut,
    const TVector3* pV1,
    const TVector3* pV2)
{
    TVector3 v;

    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

    *pOut = v;
    return pOut;
}
//-------------------------------------------------------------------------
float SetVec3Dot(const TVector3* pV1, const TVector3* pV2)
{
    float res = pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
    return res;
}
//-------------------------------------------------------------------------
float SetVec3Angle(const nsMathTools::TVector3* pV1, const nsMathTools::TVector3* pV2)
{
    float len1 = pV1->length();
    float len2 = pV2->length();
    if ( len1 <= msEpsilon || len2 <= msEpsilon )
        return 0;
    float dot = SetVec3Dot(pV1, pV2);
    float cosAngle = dot / (len1 * len2);
    if ( cosAngle > 1.0f )// может возникать как правило как погрешность вычисления
        cosAngle = 1.0f;
    if ( cosAngle < -1.0f )// может возникать как правило как погрешность вычисления
        cosAngle = -1.0f;
    float angle = acos(cosAngle);
    return angle;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Normalize(TVector3* pOut, const TVector3* pV)
{
    if ( pOut == nullptr )
        return nullptr;

    *pOut = *pV;
    float len = pOut->length();
    if ( len > 0.0f )
        pOut->operator /= (len);

    return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixPerspectiveFovLH(TMatrix16* pOut, float fovy, float Aspect, float zn, float zf)
{
    if ( (Aspect == 0.0f) ||
        (fovy == 0.0f) ||
        (zn == zf) )
        return nullptr;

    float tan_fovy_2 = tan(fovy / 2.0f);
    float _11 = 1.0f / (Aspect * tan_fovy_2);
    float _22 = 1.0f / tan_fovy_2;

    pOut->_11 = _11;    pOut->_12 = 0.0f;   pOut->_13 = 0.0f;                 pOut->_14 = 0.0f;
    pOut->_21 = 0.0f;   pOut->_22 = _22;    pOut->_23 = 0.0f;                 pOut->_24 = 0.0f;
    pOut->_31 = 0.0f;   pOut->_32 = 0.0f;   pOut->_33 = zf / (zf - zn);       pOut->_34 = 1.0f;
    pOut->_41 = 0.0f;   pOut->_42 = 0.0f;   pOut->_43 = -zn * zf / (zf - zn); pOut->_44 = 0.0f;

    return pOut;
}
//-------------------------------------------------------------------------
float SetMatrixfDeterminant(const nsMathTools::TMatrix16* pm)
{
    TVector4 minor, v1, v2, v3;
    float det;

    v1.x = pm->m(0,0); v1.y = pm->m(1,0); v1.z = pm->m(2,0); v1.w = pm->m(3,0);
    v2.x = pm->m(0,1); v2.y = pm->m(1,1); v2.z = pm->m(2,1); v2.w = pm->m(3,1);
    v3.x = pm->m(0,2); v3.y = pm->m(1,2); v3.z = pm->m(2,2); v3.w = pm->m(3,2);
    SetVec4Cross(&minor, &v1, &v2, &v3);
    det = -(pm->m(0,3) * minor.x + pm->m(1,3) * minor.y + pm->m(2,3) * minor.z + pm->m(3,3) * minor.w);
    return det;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixInverse(TMatrix16* pout,
    float* pdeterminant,
    const TMatrix16* pm)
{
    int a, i, j;
    TVector4 v, vec[3];
    float det;

    det = SetMatrixfDeterminant(pm);
    if ( !det ) return NULL;
    if ( pdeterminant ) *pdeterminant = det;
    for ( i = 0; i < 4; i++ ) {
        for ( j = 0; j < 4; j++ ) {
            if ( j != i ) {
                a = j;
                if ( j > i ) a = a - 1;
                vec[a].x = pm->m(j,0);
                vec[a].y = pm->m(j,1);
                vec[a].z = pm->m(j,2);
                vec[a].w = pm->m(j,3);
            }
        }
        SetVec4Cross(&v, &vec[0], &vec[1], &vec[2]);
        pout->m(0,i) = pow(-1.0f, i) * v.x / det;
        pout->m(1,i) = pow(-1.0f, i) * v.y / det;
        pout->m(2,i) = pow(-1.0f, i) * v.z / det;
        pout->m(3,i) = pow(-1.0f, i) * v.w / det;
    }
    return pout;
}
//-------------------------------------------------------------------------
TVector4* SetVec4Cross(TVector4* pout,
    const TVector4* pv1,
    const TVector4* pv2,
    const TVector4* pv3)
{
    TVector4 out;
    out.x = pv1->y * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->y * pv3->w - pv3->y * pv2->w) + pv1->w * (pv2->y * pv3->z - pv2->z * pv3->y);
    out.y = -(pv1->x * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->x * pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->z - pv3->x * pv2->z));
    out.z = pv1->x * (pv2->y * pv3->w - pv3->y * pv2->w) - pv1->y * (pv2->x * pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->y - pv3->x * pv2->y);
    out.w = -(pv1->x * (pv2->y * pv3->z - pv3->y * pv2->z) - pv1->y * (pv2->x * pv3->z - pv3->x * pv2->z) + pv1->z * (pv2->x * pv3->y - pv3->x * pv2->y));
    *pout = out;
    return pout;
}
//-------------------------------------------------------------------------
TPlane* SetPlaneFromPointNormal(TPlane* pOut,
    const TVector3* pPoint,
    const TVector3* pNormal)
{
    pOut->a = pNormal->x;
    pOut->b = pNormal->y;
    pOut->c = pNormal->z;
    pOut->d = -SetVec3Dot(pPoint, pNormal);
    return pOut;
}
//-------------------------------------------------------------------------
TPlane* SetPlaneFromPoints(TPlane* pOut,
    const TVector3* pV1,
    const TVector3* pV2,
    const TVector3* pV3)
{
    TVector3 edge1, edge2, normal, Nnormal;

    edge1.x = 0.0f; edge1.y = 0.0f; edge1.z = 0.0f;
    edge2.x = 0.0f; edge2.y = 0.0f; edge2.z = 0.0f;
    SetVec3Subtract(&edge1, pV2, pV1);
    SetVec3Subtract(&edge2, pV3, pV1);
    SetVec3Cross(&normal, &edge1, &edge2);
    SetVec3Normalize(&Nnormal, &normal);
    SetPlaneFromPointNormal(pOut, pV1, &Nnormal);
    return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetPlaneIntersectLine(TVector3* pOut,
    const TPlane* pP,
    const TVector3* pV1,
    const TVector3* pV2)
{
    TVector3 direction, normal;
    float dot, temp;

    normal.x = pP->a;
    normal.y = pP->b;
    normal.z = pP->c;
    direction.x = pV2->x - pV1->x;
    direction.y = pV2->y - pV1->y;
    direction.z = pV2->z - pV1->z;
    dot = SetVec3Dot(&normal, &direction);
    if ( !dot )
        return nullptr;
    temp = (pP->d + SetVec3Dot(&normal, pV1)) / dot;
    pOut->x = pV1->x - temp * direction.x;
    pOut->y = pV1->y - temp * direction.y;
    pOut->z = pV1->z - temp * direction.z;
    return pOut;
}
//-------------------------------------------------------------------------
TPlane* SetPlaneTransform(TPlane* pOut, const TPlane* pP, const TMatrix16* pM)
{
    const TPlane plane = *pP;
    pOut->a = pM->m(0,0) * plane.a + pM->m(1,0) * plane.b + pM->m(2,0) * plane.c + pM->m(3,0) * plane.d;
    pOut->b = pM->m(0,1) * plane.a + pM->m(1,1) * plane.b + pM->m(2,1) * plane.c + pM->m(3,1) * plane.d;
    pOut->c = pM->m(0,2) * plane.a + pM->m(1,2) * plane.b + pM->m(2,2) * plane.c + pM->m(3,2) * plane.d;
    pOut->d = pM->m(0,3) * plane.a + pM->m(1,3) * plane.b + pM->m(2,3) * plane.c + pM->m(3,3) * plane.d;
    return pOut;
}
//-------------------------------------------------------------------------
TQuaternion* SetQuaternionMultiply(TQuaternion* pOut, const TQuaternion* pQ1, const TQuaternion* pQ2)
{
    TQuaternion out;
    out.x = pQ2->w * pQ1->x + pQ2->x * pQ1->w + pQ2->y * pQ1->z - pQ2->z * pQ1->y;
    out.y = pQ2->w * pQ1->y - pQ2->x * pQ1->z + pQ2->y * pQ1->w + pQ2->z * pQ1->x;
    out.z = pQ2->w * pQ1->z + pQ2->x * pQ1->y - pQ2->y * pQ1->x + pQ2->z * pQ1->w;
    out.w = pQ2->w * pQ1->w - pQ2->x * pQ1->x - pQ2->y * pQ1->y - pQ2->z * pQ1->z;
    *pOut = out;
    return pOut;
}
//-------------------------------------------------------------------------
TQuaternion* SetQuaternionIdentity(TQuaternion* pOut)
{
    pOut->x = 0.0f;
    pOut->y = 0.0f;
    pOut->z = 0.0f;
    pOut->w = 1.0f;
    return pOut;
}
//-------------------------------------------------------------------------
TQuaternion* SetQuaternionRotationAxis(TQuaternion* pOut, const TVector3* pV, float Angle)
{
    pOut->w = cos(Angle / 2);
    float sinAngle_2 = sin(Angle / 2);
    pOut->x = sinAngle_2 * pV->x;
    pOut->y = sinAngle_2 * pV->y;
    pOut->z = sinAngle_2 * pV->z;
    return pOut;
}
//-------------------------------------------------------------------------
void SetQuaternionToAxisAngle(const TQuaternion* pQ, TVector3* pAxis, float* pAngle)
{
    float angle = atan2(sqrt(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z), pQ->w);
    float sinAngle = sin(angle);
    if ( fabs(sinAngle) >= msEpsilon )// Gauss 26.07.2017
    {
        pAxis->x = pQ->x / sinAngle;
        pAxis->y = pQ->y / sinAngle;
        pAxis->z = pQ->z / sinAngle;
    } else {
        // correct angle
        // Pi or 0
        float cosAngle = cos(angle);
        if ( cosAngle < 0 )
            angle = float(M_PI);// но точно ось вращения не найти (полный бред)
        else
            angle = 0.0f;
        pAxis->x = 0;
        pAxis->y = 0;
        pAxis->z = 0;
    }
    *pAngle = angle;
}
//-------------------------------------------------------------------------
void SetRotatePoint(nsMathTools::TOrientation* pO,
    nsMathTools::TVector3* pPointIn, nsMathTools::TVector3* pPointOut)
{
    TMatrix16 m16;
    SetMatrixRotationAxis(&m16, &(pO->axis), pO->angle);
    SetVec3TransformCoord(pPointOut, pPointIn, &m16);
}
//-------------------------------------------------------------------------
void CalcMatrixByMoveVectors(nsMathTools::TMatrix16* pM,
    nsMathTools::TVector3* pUpTo, nsMathTools::TVector3* pForwardTo,
    nsMathTools::TVector3* pUpFrom, nsMathTools::TVector3* pForwardFrom)
{
    SetMatrixIdentity(pM);

    // найти угол между векторами
    float angleForward = SetVec3Angle(pForwardTo, pForwardFrom);
    BL_ASSERT(angleForward >= 0.0f);
    nsMathTools::TVector3 normalForward;
    if ( angleForward > M_PI - msEpsilon ) {
        angleForward = float(M_PI);
        normalForward = *pUpFrom;
    } else {
        SetVec3Cross(&normalForward, pForwardFrom, pForwardTo);
    }
    SetVec3Normalize(&normalForward, &normalForward);

    nsMathTools::TMatrix16 calcMatrixForward;
    SetMatrixRotationAxis(&calcMatrixForward, &normalForward, angleForward);

    nsMathTools::TVector3 rotUpFrom;
    SetVec3TransformCoord(&rotUpFrom, pUpFrom, &calcMatrixForward);

    float angleUp = SetVec3Angle(&rotUpFrom, pUpTo);
    nsMathTools::TVector3 normalUp;
    if ( angleUp > M_PI - msEpsilon ) {
        angleUp = float(M_PI);
        normalUp = *pForwardTo;
    } else {
        SetVec3Cross(&normalUp, &rotUpFrom, pUpTo);
    }
    SetVec3Normalize(&normalUp, &normalUp);
    nsMathTools::TMatrix16 calcMatrixUp;
    SetMatrixRotationAxis(&calcMatrixUp, &normalUp, angleUp);

    *pM = calcMatrixForward * calcMatrixUp;
}
//-------------------------------------------------------------------------
void CalcMatrix(nsMathTools::TMatrix16* pOut, nsMathTools::TMatrix16* pTo, nsMathTools::TMatrix16* pFrom)
{
    nsMathTools::TVector3 Up(0, 1, 0);
    nsMathTools::TVector3 Forward(1, 0, 0);

    nsMathTools::TVector3 UpTo;
    nsMathTools::TVector3 ForwardTo;
    nsMathTools::TVector3 UpFrom;
    nsMathTools::TVector3 ForwardFrom;

    SetVec3TransformCoord(&UpTo, &Up, pTo);
    SetVec3TransformCoord(&ForwardTo, &Forward, pTo);
    SetVec3TransformCoord(&UpFrom, &Up, pFrom);
    SetVec3TransformCoord(&ForwardFrom, &Forward, pFrom);

    CalcMatrixByMoveVectors(pOut, &UpTo, &ForwardTo, &UpFrom, &ForwardFrom);
}
//-------------------------------------------------------------------------
float SetQuaternionLength(const TQuaternion* pQ)
{
    return sqrt(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
}
//-------------------------------------------------------------------------
