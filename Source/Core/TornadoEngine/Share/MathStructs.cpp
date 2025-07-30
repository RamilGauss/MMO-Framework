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

#include "Base/Common/BL_Debug.h"

#include "TornadoEngine/Share/MathStructs.h"
#include "TornadoEngine/Share/MathTools.h"

using namespace nsMathTools;


//-------------------------------------------------------------------------
TMatrix16::TMatrix16()
{
    SetMatrixIdentity( this );
}
//-------------------------------------------------------------------------
TMatrix16::TMatrix16(
    float _11, float _12, float _13, float _14,
    float _21, float _22, float _23, float _24,
    float _31, float _32, float _33, float _34,
    float _41, float _42, float _43, float _44)
{
    this->_11 = _11; this->_12 = _12; this->_13 = _13; this->_14 = _14;
    this->_21 = _21; this->_22 = _22; this->_23 = _23; this->_24 = _24;
    this->_31 = _31; this->_32 = _32; this->_33 = _33; this->_34 = _34;
    this->_41 = _41; this->_42 = _42; this->_43 = _43; this->_44 = _44;
}
//-------------------------------------------------------------------------
// assignment operators
TMatrix16& TMatrix16::operator += (const TMatrix16& v)
{
    MATRIX16_OP_P_M(this, v, +=)
        return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator -= (const TMatrix16& v)
{
    MATRIX16_OP_P_M(this, v, -=)
        return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator *= (float v)
{
    MATRIX16_OP_P(this, v, *=)
        return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator /= (float v)
{
    MATRIX16_OP_P(this, v, /=)
        return *this;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator + () const
{
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator - () const
{
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator + (const TMatrix16& v) const
{
    TMatrix16 res = *this;
    MATRIX16_OP_M_M(res, v, +=)
        return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator - (const TMatrix16& v) const
{
    TMatrix16 res = *this;
    MATRIX16_OP_M_M(res, v, -=)
        return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator * (float v) const
{
    TMatrix16 res = *this;
    MATRIX16_OP_M(res, v, *=)

        return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator / (float v) const
{
    TMatrix16 res = *this;
    MATRIX16_OP_M(res, v, /=)

        return res;
}
//-------------------------------------------------------------------------
bool TMatrix16::operator == (const TMatrix16& v) const
{
    for ( int k = 0; k < 4; k++ )
        for ( int n = 0; n < 4; n++ )
            if ( BASE_MATRIX_OP(this, v, != , ->, ., k, n) )
                return false;
    return true;
}
//-------------------------------------------------------------------------
bool TMatrix16::operator != (const TMatrix16& v) const
{
    for ( int k = 0; k < 4; k++ )
        for ( int n = 0; n < 4; n++ )
            if ( BASE_MATRIX_OP(this, v, == , ->, ., k, n) )
                return false;
    return true;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator *= (const TMatrix16& v)
{
    //SetMatrixMultiply( this, this, &v );
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator * (const TMatrix16& v) const
{
    TMatrix16 res;
    SetMatrixMultiply( &res, this, &v );
    return res;
}
//-------------------------------------------------------------------------
void TMatrix16::CalcAxisAngle()
{
    SetMatrixToAxisAngle( this, &axis, &angle );
}
//-------------------------------------------------------------------------
TVector2::operator float* ()
{
    return (float*) this;
}
//-------------------------------------------------------------------------
TVector2::operator const float* () const
{
    return (const float*) this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator += (const TVector2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator -= (const TVector2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator *= (float v)
{
    x *= v;
    y *= v;
    return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator /= (float v)
{
    x /= v;
    y /= v;
    return *this;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator + () const
{
    return *this;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator - () const
{
    return *this;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator + (const TVector2& v) const
{
    TVector2 res;
    res.x = x + v.x;
    res.y = y + v.y;
    return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator - (const TVector2& v) const
{
    TVector2 res;
    res.x = x - v.x;
    res.y = y - v.y;
    return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator * (float v) const
{
    TVector2 res;
    res.x = x * v;
    res.y = y * v;
    return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator / (float v) const
{
    TVector2 res;
    res.x = x / v;
    res.y = y / v;
    return res;
}
//-------------------------------------------------------------------------
bool TVector2::operator == (const TVector2& v) const
{
    return ((v.x == x) && (v.y == y));
}
//-------------------------------------------------------------------------
bool TVector2::operator != (const TVector2& v) const
{
    return ((v.x != x) || (v.y != y));
}
//-------------------------------------------------------------------------
bool TVector2::operator > (const TVector2& v) const
{
    if ( x > v.x ) return true;// высший
    else if ( x < v.x ) return false;
    //
    if ( y > v.y )
        return true;// низший

    return false;
}
//-------------------------------------------------------------------------
bool TVector2::operator < (const TVector2& v) const
{
    if ( x < v.x )
        return true;// высший
    else if ( x > v.x )
        return false;
    //
    if ( y < v.y )
        return true;// низший

    return false;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator += (const TVector3& pV)
{
    x += pV.x;
    y += pV.y;
    z += pV.z;
    return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator -= (const TVector3& pV)
{
    x -= pV.x;
    y -= pV.y;
    z -= pV.z;
    return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator *= (float v)
{
    x *= v;
    y *= v;
    z *= v;
    return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator /= (float v)
{
    x /= v;
    y /= v;
    z /= v;
    return *this;
}
//-------------------------------------------------------------------------
// unary operators
TVector3 TVector3::operator + () const
{
    return *this;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator - () const
{
    return *this;
}
//-------------------------------------------------------------------------
// binary operators
TVector3 TVector3::operator + (const TVector3& pV) const
{
    TVector3 res;
    res.x = x + pV.x;
    res.y = y + pV.y;
    res.z = z + pV.z;
    return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator - (const TVector3& pV) const
{
    TVector3 res;
    res.x = x - pV.x;
    res.y = y - pV.y;
    res.z = z - pV.z;
    return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator * (float v) const
{
    TVector3 res;
    res.x = x * v;
    res.y = y * v;
    res.z = z * v;
    return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator / (float v) const
{
    TVector3 res;
    res.x = x / v;
    res.y = y / v;
    res.z = z / v;
    return res;
}
//-------------------------------------------------------------------------
bool TVector3::operator == (const TVector3& pV) const
{
    return ((pV.x == x) && (pV.y == y) && (pV.z == z));
}
//-------------------------------------------------------------------------
bool TVector3::operator != (const TVector3& pV) const
{
    return ((pV.x != x) || (pV.y != y) || (pV.z != z));
}
//-------------------------------------------------------------------------
bool TVector3::operator > (const TVector3& v) const
{
    if ( x > v.x ) return true; // high assign,  высший разряд
    else if ( x < v.x ) return false;
    //---------------------------------
    if ( y > v.y ) return true;
    else if ( y < v.y ) return false;
    //---------------------------------
    if ( z > v.z )// low assign, низший разряд
        return true;
    return false;
}
//-------------------------------------------------------------------------
bool TVector3::operator < (const TVector3& v) const
{
    if ( x < v.x ) return true; // high assign, высший разряд
    else if ( x > v.x ) return false;
    //---------------------------------
    if ( y < v.y ) return true;
    else if ( y > v.y ) return false;
    //---------------------------------
    if ( z < v.z )// low assign, низший разряд
        return true;
    return false;
}
//-------------------------------------------------------------------------
float TVector3::length() const
{
    return sqrt(x * x + y * y + z * z);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
TPlane::TPlane(const float* pF)
{
    a = pF[0];
    b = pF[1];
    c = pF[2];
    d = pF[3];
}
//-------------------------------------------------------------------------
TPlane::TPlane(float _a, float _b, float _c, float _d)
{
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}
//-------------------------------------------------------------------------
TPlane::operator float* ()
{
    return (float*) this;
}
//-------------------------------------------------------------------------
TPlane::operator const float* () const
{
    return (const float*) this;
}
//-------------------------------------------------------------------------
TPlane& TPlane::operator *= (float v)
{
    a *= v;
    b *= v;
    c *= v;
    d *= v;
    return *this;
}
//-------------------------------------------------------------------------
TPlane& TPlane::operator /= (float v)
{
    a /= v;
    b /= v;
    c /= v;
    d /= v;
    return *this;
}
//-------------------------------------------------------------------------
TPlane TPlane::operator + () const
{
    TPlane res = *this;
    res.a += a;
    res.b += b;
    res.c += c;
    res.d += d;
    return res;
}
//-------------------------------------------------------------------------
TPlane TPlane::operator - () const
{
    TPlane res = *this;
    res.a -= a;
    res.b -= b;
    res.c -= c;
    res.d -= d;
    return res;
}
//-------------------------------------------------------------------------
TPlane TPlane::operator * (float v) const
{
    TPlane res;
    res.a *= v;
    res.b *= v;
    res.c *= v;
    res.d *= v;
    return res;
}
//-------------------------------------------------------------------------
TPlane TPlane::operator / (float v) const
{
    TPlane res;
    res.a /= v;
    res.b /= v;
    res.c /= v;
    res.d /= v;
    return res;
}
//-------------------------------------------------------------------------
bool TPlane::operator == (const TPlane& p) const
{
    return ((p.a == a) && (p.b == b) && (p.c == c) && (p.d == d));
}
//-------------------------------------------------------------------------
bool TPlane::operator != (const TPlane& p) const
{
    return ((p.a != a) || (p.b != b) || (p.c != c) || (p.d != d));
}
//-------------------------------------------------------------------------
bool TLine::FindAndSetIntersect(TPlane* pP1, TPlane* pP2)
{
    //1 найдем тип прямой (зависит от того равны ли коэффициенты плоскости нулю)
    // find type of line (determinate by equal coefficient of plane equal zero)
    if ( (*pP1 == *pP2) ||// line will plane, линия выродилась в плоскость
        (*pP1 == TPlane(0, 0, 0, 0)) ||// will zero equal, вырожденное уравнение
        (*pP2 == TPlane(0, 0, 0, 0)) ) {
        SetType(eUndef);
        return false;
    }
    //  by X, через Х
    if ( pP1->c * pP2->b != pP2->c * pP1->b ) {
        float div = pP1->c * pP2->b - pP1->b * pP2->c;// c1*b2-b1*c2
        a = (pP1->a * pP2->c - pP1->c * pP2->a) / div;// a1*c2-c1*a2
        b = (pP1->d * pP2->c - pP1->c * pP2->d) / div;// d1*c2-d2*c1
        c = (pP1->b * pP2->a - pP1->a * pP2->b) / div;// b1*a2-b2*a1
        d = (pP1->b * pP2->d - pP1->d * pP2->b) / div;// b1*d2-b2*d1
        SetType(eX);
    }// by Z, через Z
    else if ( pP1->a * pP2->b != pP2->a * pP1->b ) {
        float div = pP1->b * pP2->a - pP1->a * pP2->b;// b1*a2-a1*b2 
        a = (pP1->c * pP2->b - pP1->b * pP2->c) / div;// c1*b2-b1*c2 
        b = (pP1->d * pP2->b - pP1->b * pP2->d) / div;// d1*b2-d2*b1
        div *= -1.0f;;// b2*a1-a2*b1 
        c = (pP1->c * pP2->a - pP1->a * pP2->c) / div;// c1*a2-a1*c2
        d = (pP1->d * pP2->a - pP1->a * pP2->d) / div;// d1*a2-a1*d2
        SetType(eZ);
    }// by Y, через Y
    else {
        float div = pP1->a * pP2->c - pP1->c * pP2->a;// a1*c2-c1*a2
        a = (pP1->c * pP2->b - pP1->b * pP2->c) / div;// c1*b2-b1*c2
        b = (pP1->c * pP2->d - pP1->d * pP2->c) / div;// c1*d2-d1*c2
        div *= -1.0f;// c1*a2-a1*c2
        c = (pP1->a * pP2->b - pP1->b * pP2->a) / div;// a1*b2-b1*a2
        d = (pP1->a * pP2->d - pP1->d * pP2->a) / div;// a1*d2-d1*a2
        SetType(eY);
    }
    return true;
}
//-------------------------------------------------------------------------
bool TLine::FindVector(TVector3* pOut1, TVector3* pOut2, bool do_normal)
{
    if ( mType == eUndef )
        return false;

    TVector3 betweenPoint;
    switch ( mType ) {
        case eX:
            betweenPoint.x = 0.0f;
            Calc(betweenPoint.x, &betweenPoint.y, &betweenPoint.z);

            pOut1->x = 1.0f;
            Calc(pOut1->x, &pOut1->y, &pOut1->z);
            pOut2->x = -1.0f;
            Calc(pOut2->x, &pOut2->y, &pOut2->z);
            break;
        case eY:
            betweenPoint.y = 0.0f;
            Calc(betweenPoint.y, &betweenPoint.x, &betweenPoint.z);

            pOut1->y = 1.0f;
            Calc(pOut1->y, &pOut1->x, &pOut1->z);
            pOut2->y = -1.0f;
            Calc(pOut2->y, &pOut2->x, &pOut2->z);
            break;
        case eZ:
            betweenPoint.z = 0.0f;
            Calc(betweenPoint.z, &betweenPoint.x, &betweenPoint.y);

            pOut1->z = 1.0f;
            Calc(pOut1->z, &pOut1->x, &pOut1->y);
            pOut2->z = -1.0f;
            Calc(pOut2->z, &pOut2->x, &pOut2->y);
            break;
    }

    *pOut1 -= betweenPoint;
    *pOut2 -= betweenPoint;

    if ( do_normal ) {
        SetVec3Normalize( pOut1, pOut1 );
        SetVec3Normalize( pOut2, pOut2 );
    }
    return true;
}
//-------------------------------------------------------------------------
void TLine::SetType(int v)
{
    mType = v;
}
//-------------------------------------------------------------------------
void TLine::Calc(float arg, float* res1, float* res2)
{
    BL_ASSERT(res1);
    BL_ASSERT(res2);
    *res1 = a * arg + b;
    *res2 = c * arg + d;
}
//-------------------------------------------------------------------------
TQuaternion::TQuaternion(const float* pF)
{
    x = pF[0];
    y = pF[1];
    z = pF[2];
    w = pF[3];
}
//-------------------------------------------------------------------------
TQuaternion::TQuaternion(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
//-------------------------------------------------------------------------
TQuaternion::operator float* ()
{
    return (float*) this;
}
//-------------------------------------------------------------------------
TQuaternion::operator const float* () const
{
    return (const float*) this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator += (const TQuaternion& q)
{
    *this = *this + q;
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator -= (const TQuaternion& q)
{
    *this = *this - q;
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator *= (const TQuaternion& q)
{
    *this = *this * q;
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator *= (float v)
{
    *this = *this * v;
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator /= (float v)
{
    *this = *this / v;
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion  TQuaternion::operator + () const
{
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator - () const
{
    return *this;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator + (const TQuaternion& q) const
{
    TQuaternion res;
    res.x = x + q.x;
    res.y = y + q.y;
    res.z = z + q.z;
    res.w = w + q.w;
    return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator - (const TQuaternion& q) const
{
    TQuaternion res;
    res.x = x - q.x;
    res.y = y - q.y;
    res.z = z - q.z;
    res.w = w - q.w;
    return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator * (const TQuaternion& q) const
{
    TQuaternion res;
    SetQuaternionMultiply( &res, this, &q );
    return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator * (float v) const
{
    TQuaternion res;
    res.x = x * v;
    res.y = y * v;
    res.z = z * v;
    res.w = w * v;
    return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator / (float v) const
{
    TQuaternion res;
    res.x = x / v;
    res.y = y / v;
    res.z = z / v;
    res.w = w / v;
    return res;
}
//-------------------------------------------------------------------------
bool TQuaternion::operator == (const TQuaternion& q) const
{
    return ((q.x == x) && (q.y == y) && (q.z == z) && (q.w == w));
}
//-------------------------------------------------------------------------
bool TQuaternion::operator != (const TQuaternion& q) const
{
    return ((q.x != x) || (q.y != y) || (q.z != z) || (q.w != w));
}
//-------------------------------------------------------------------------
TOrientation::TOrientation()
{
}
//-------------------------------------------------------------------------
TOrientation::TOrientation(float x, float y, float z, float a) :
    axis(x, y, z), angle(a)
{

}
//-------------------------------------------------------------------------