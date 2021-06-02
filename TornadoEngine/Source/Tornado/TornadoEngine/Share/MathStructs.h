/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsMathTools
{
#ifdef WIN32 
#pragma pack(push, 1)
#endif
    //----------------------------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPoint2
    {
        unsigned int x = 0;
        unsigned int y = 0;
    }_PACKED;
    //----------------------------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TVector2
    {
        float x = 0;
        float y = 0;

        TVector2()
        {
        }
        TVector2(float _x, float _y)
        {
            x = _x; y = _y;
        }

        // casting
        operator float* ();
        operator const float* () const;

        // assignment operators
        TVector2& operator += (const TVector2&);
        TVector2& operator -= (const TVector2&);
        TVector2& operator *= (float);
        TVector2& operator /= (float);

        // unary operators
        TVector2 operator + () const;
        TVector2 operator - () const;

        // binary operators
        TVector2 operator + (const TVector2&) const;
        TVector2 operator - (const TVector2&) const;
        TVector2 operator * (float) const;
        TVector2 operator / (float) const;

        bool operator == (const TVector2&) const;
        bool operator != (const TVector2&) const;

        bool operator > (const TVector2&) const;
        bool operator < (const TVector2&) const;
    }_PACKED;
    //-------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TVector3
    {
        float x = 0;
        float y = 0;
        float z = 0;
        TVector3() {}
        TVector3(float _x, float _y, float _z)
        {
            x = _x; y = _y; z = _z;
        }

        // assignment operators
        TVector3& operator += (const TVector3&);
        TVector3& operator -= (const TVector3&);
        TVector3& operator *= (float);
        TVector3& operator /= (float);

        // unary operators
        TVector3 operator + () const;
        TVector3 operator - () const;

        // binary operators
        TVector3 operator + (const TVector3&) const;
        TVector3 operator - (const TVector3&) const;
        TVector3 operator * (float) const;
        TVector3 operator / (float) const;

        bool operator == (const TVector3&) const;
        bool operator != (const TVector3&) const;

        bool operator > (const TVector3&) const;
        bool operator < (const TVector3&) const;

        float length() const;
    }_PACKED;
    //-----------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TVector4
    {
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;
        TVector4() {}

        TVector4(float _x, float _y, float _z, float _w)
        {
            x = _x; y = _y; z = _z; w = _w;
        }
    }_PACKED;
    //-----------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TMatrix9
    {
    private:
        float* pThis = (float*) ((unsigned char*) this + sizeof(float*));
    public:

        float _11 = 0; float _12 = 0; float _13 = 0;
        float _21 = 0; float _22 = 0; float _23 = 0;
        float _31 = 0; float _32 = 0; float _33 = 0;

        inline float& m(const unsigned char i, const unsigned char j) const
        {
            return pThis[i + j * 3];
        }
    }_PACKED;
    //-----------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    class DllExport TMatrix16
    {
        float* pThis = (float*) ((unsigned char*) this + sizeof(float*));
    public:
        float _11 = 0; float _12 = 0; float _13 = 0; float _14 = 0;
        float _21 = 0; float _22 = 0; float _23 = 0; float _24 = 0;
        float _31 = 0; float _32 = 0; float _33 = 0; float _34 = 0;
        float _41 = 0; float _42 = 0; float _43 = 0; float _44 = 0;

        inline float& m(const unsigned char i, const unsigned char j) const
        {
            return pThis[i + j * 4];
        }

        TMatrix16();
        TMatrix16(float _11, float _12, float _13, float _14,
            float _21, float _22, float _23, float _24,
            float _31, float _32, float _33, float _34,
            float _41, float _42, float _43, float _44);

        // assignment operators
        TMatrix16& operator += (const TMatrix16&);
        TMatrix16& operator -= (const TMatrix16&);
        TMatrix16& operator *= (float);
        TMatrix16& operator /= (float);

        TMatrix16& operator *= (const TMatrix16&);
        //TMatrix16& operator /= ( const TMatrix16& );

        // unary operators
        TMatrix16 operator + () const;
        TMatrix16 operator - () const;

        // binary operators
        TMatrix16 operator + (const TMatrix16&) const;
        TMatrix16 operator - (const TMatrix16&) const;

        TMatrix16 operator * (const TMatrix16&) const;
        //TMatrix16 operator / ( const TMatrix16& ) const;

        TMatrix16 operator * (float) const;
        TMatrix16 operator / (float) const;

        bool operator == (const TMatrix16&) const;
        bool operator != (const TMatrix16&) const;

        void CalcAxisAngle();

    protected:
        nsMathTools::TVector3 axis;
        float                 angle = 0;
    }_PACKED;
    //----------------------------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPlane
    {
        float a = 0;
        float b = 0;
        float c = 0;
        float d = 0;

        TPlane() {}
        TPlane(const float*);
        TPlane(float a, float b, float c, float d);

        // casting
        operator float* ();
        operator const float* () const;

        // assignment operators
        TPlane& operator *= (float);
        TPlane& operator /= (float);

        // unary operators
        TPlane operator + () const;
        TPlane operator - () const;

        // binary operators
        TPlane operator * (float) const;
        TPlane operator / (float) const;

        //friend TPlane operator * ( float, const TPlane& );

        bool operator == (const TPlane&) const;
        bool operator != (const TPlane&) const;
    }_PACKED;
    //----------------------------------------------------------------------------------------
  //#pragma REFLECTION_ATTRIBUTE
    class DllExport TLine
    {
        enum
        {
            eX,// a = ky, b = by, c = kz, d = bz
            eY,// a = kx, b = bx, c = kz, d = bz
            eZ,// a = kx, b = bx, c = ky, d = by
            eUndef,
        };

        int mType = eUndef;
        float a = 0;
        float b = 0;
        float c = 0;
        float d = 0;

    public:
        // forms equation of line, when intersect of 2 planes, 
        // сформировать уравнение прямой при пересечении 2-ух плоскостей
        bool FindAndSetIntersect(TPlane* pP1, TPlane* pP2);
        // find 2 vectors(normal) on line from point
        // найти 2 вектора(нормальные) на прямой от точки
        bool FindVector(TVector3* pOut1, TVector3* pOut2, bool do_normal = false);

    protected:
        void SetType(int v);
        void Calc(float arg, float* res1, float* res2);
    }_PACKED;
    //----------------------------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TQuaternion
    {
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 1;

        TQuaternion()
        {
        }
        TQuaternion(const float*);
        TQuaternion(float x, float y, float z, float w);

        // casting
        operator float* ();
        operator const float* () const;

        // assignment operators
        TQuaternion& operator += (const TQuaternion&);
        TQuaternion& operator -= (const TQuaternion&);
        TQuaternion& operator *= (const TQuaternion&);
        TQuaternion& operator *= (float);
        TQuaternion& operator /= (float);

        // unary operators
        TQuaternion  operator + () const;
        TQuaternion  operator - () const;

        // binary operators
        TQuaternion operator + (const TQuaternion&) const;
        TQuaternion operator - (const TQuaternion&) const;
        TQuaternion operator * (const TQuaternion&) const;
        TQuaternion operator * (float) const;
        TQuaternion operator / (float) const;

        //friend TQuaternion operator * (FLOAT, CONST D3DXQUATERNION& );

        bool operator == (const TQuaternion&) const;
        bool operator != (const TQuaternion&) const;
    }_PACKED;
    //----------------------------------------------------------------------------------------
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TOrientation
    {
        TVector3 axis;
        float angle = 0;
        TOrientation();
        TOrientation(float x, float y, float z, float a);
    }_PACKED;
#ifdef WIN32 
#pragma pack(pop)
#endif
}
