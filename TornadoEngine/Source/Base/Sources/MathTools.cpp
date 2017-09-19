/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

// Some parts of source code from http://wine.sourcearchive.com.
// Thank you, Wine! Viva GPL!


#define _USE_MATH_DEFINES
#include <cmath>

#include "MathTools.h"
#include <memory.h>
#include <stddef.h>
#include "BL_Debug.h"

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
  memcpy(pDst,pSrc,sizeof(TMatrix16));
}
//-------------------------------------------------------------------------
float CalcDist(const TMatrix16* m1, const TMatrix16* m2)
{
  TVector3 dist;
  dist.x = m1->s._41 - m2->s._41;
  dist.y = m1->s._42 - m2->s._42;
  dist.z = m1->s._43 - m2->s._43;
  return dist.length();
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixIdentity(TMatrix16* pV)
{
  pV->s._11 = 1.0f; pV->s._12 = 0.0f; pV->s._13 = 0.0f; pV->s._14 = 0.0f;
  pV->s._21 = 0.0f; pV->s._22 = 1.0f; pV->s._23 = 0.0f; pV->s._24 = 0.0f;
  pV->s._31 = 0.0f; pV->s._32 = 0.0f; pV->s._33 = 1.0f; pV->s._34 = 0.0f;
  pV->s._41 = 0.0f; pV->s._42 = 0.0f; pV->s._43 = 0.0f; pV->s._44 = 1.0f;
  return pV;
}
//-------------------------------------------------------------------------
TMatrix9* SetMatrixIdentity(TMatrix9* pV)
{
  pV->s._11 = 1.0f;  pV->s._12 = 0.0f;  pV->s._13 = 0.0f;
  pV->s._21 = 0.0f;  pV->s._22 = 1.0f;  pV->s._23 = 0.0f;
  pV->s._31 = 0.0f;  pV->s._32 = 0.0f;  pV->s._33 = 1.0f;
  return pV;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixTranslation(TMatrix16 *pOut, float x, float y, float z )
{
  pOut->s._11 = 1.0f; pOut->s._12 = 0.0f; pOut->s._13 = 0.0f; pOut->s._14 = 0.0f;
  pOut->s._21 = 0.0f; pOut->s._22 = 1.0f; pOut->s._23 = 0.0f; pOut->s._24 = 0.0f;
  pOut->s._31 = 0.0f; pOut->s._32 = 0.0f; pOut->s._33 = 1.0f; pOut->s._34 = 0.0f;
  pOut->s._41 = x;    pOut->s._42 = y;    pOut->s._43 = z;    pOut->s._44 = 1.0f;
  return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateX(TMatrix16* pOut, float angle)
{
  float sin = sinf(angle); 
  float cos = cosf(angle);

  pOut->s._11 = 1.0f; pOut->s._12 =  0.0f; pOut->s._13 = 0.0f; pOut->s._14 = 0.0f;
  pOut->s._21 = 0.0f; pOut->s._22 =  cos;  pOut->s._23 = sin;  pOut->s._24 = 0.0f;
  pOut->s._31 = 0.0f; pOut->s._32 = -sin;  pOut->s._33 = cos;  pOut->s._34 = 0.0f;
  pOut->s._41 = 0.0f; pOut->s._42 =  0.0f; pOut->s._43 = 0.0f; pOut->s._44 = 1.0f;

  return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateY(TMatrix16* pOut, float angle)
{
  float sin = sinf(angle), 
        cos = cosf(angle);

  pOut->s._11 = cos;  pOut->s._12 =  0.0f; pOut->s._13 = -sin; pOut->s._14 = 0.0f;
  pOut->s._21 = 0.0f; pOut->s._22 =  1.0f; pOut->s._23 = 0.0f; pOut->s._24 = 0.0f;
  pOut->s._31 = sin;  pOut->s._32 =  0.0f; pOut->s._33 = cos;  pOut->s._34 = 0.0f;
  pOut->s._41 = 0.0f; pOut->s._42 =  0.0f; pOut->s._43 = 0.0f; pOut->s._44 = 1.0f;

  return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotateZ(TMatrix16* pOut, float angle)
{
  float sin = sinf(angle), 
        cos = cosf(angle);

  pOut->s._11 = cos;  pOut->s._12 =  sin;  pOut->s._13 = 0.0f; pOut->s._14 = 0.0f;
  pOut->s._21 = -sin; pOut->s._22 =  cos;  pOut->s._23 = 0.0f; pOut->s._24 = 0.0f;
  pOut->s._31 = 0.0f; pOut->s._32 =  0.0f; pOut->s._33 = 1.0f; pOut->s._34 = 0.0f;
  pOut->s._41 = 0.0f; pOut->s._42 =  0.0f; pOut->s._43 = 0.0f; pOut->s._44 = 1.0f;

  return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixRotationYawPitchRoll(TMatrix16* pOut,
                                         float Yaw,
                                         float Pitch,
                                         float Roll )
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
TMatrix16* SetMatrixRotationAxis(TMatrix16 *pOut,
                                 const TVector3 *pV,
                                 float Angle)
{
	if(pOut==NULL)
		return pOut;

	TVector3 v;

	float cosA = cos(Angle);
	float sinA = sin(Angle);

	float _1_cosA = 1.0f - cosA;

	SetVec3Normalize(&v, pV);
	SetMatrixIdentity(pOut);
	pOut->m[0][0] = _1_cosA * v.x * v.x + cosA;
	pOut->m[1][0] = _1_cosA * v.x * v.y - sinA * v.z;
	pOut->m[2][0] = _1_cosA * v.x * v.z + sinA * v.y;
	pOut->m[0][1] = _1_cosA * v.y * v.x + sinA * v.z;
	pOut->m[1][1] = _1_cosA * v.y * v.y + cosA;
	pOut->m[2][1] = _1_cosA * v.y * v.z - sinA * v.x;
	pOut->m[0][2] = _1_cosA * v.z * v.x - sinA * v.y;
	pOut->m[1][2] = _1_cosA * v.z * v.y + sinA * v.x;
	pOut->m[2][2] = _1_cosA * v.z * v.z + cosA;
	return pOut;
}
//-------------------------------------------------------------------------
void SetMatrixToAxisAngle(const TMatrix16 *pM, TVector3 *pVOut, float* pAngleOut)
{
	float cosA = ( pM->m[0][0] + pM->m[1][1] + pM->m[2][2] - 1)/2;
	float _21_12 = (pM->m[2][1] - pM->m[1][2]);
	float _02_20 = (pM->m[0][2] - pM->m[2][0]);
	float _10_01 = (pM->m[1][0] - pM->m[0][1]);
	float sinA = sqrt(_21_12*_21_12+_02_20*_02_20+_10_01*_10_01);

	// возможно два варианта
	float plusAngle  =  atan2(sinA/2.0f,cosA);
	// проверка на ноль о окрестности Пи
	if( plusAngle <= msEpsilon )
	{
		*pAngleOut = 0;
		pVOut->x = 1;// не имеет значения какая ось
		pVOut->y = 0;
		pVOut->z = 0;
		return;
	}

	if( plusAngle >= M_PI - msEpsilon )
	{// в окрестностях ПИ
		// численный метод, конкурс на лучший результат.
		const int countCheckAxis = 14;
		TVector3 checkAxis[countCheckAxis];
		// орто
		checkAxis[0] = TVector3(1,0,0);
		checkAxis[1] = TVector3(0,1,0);		
		checkAxis[2] = TVector3(0,0,1);
		checkAxis[3] = TVector3(-1,0,0);
		checkAxis[4] = TVector3(0,-1,0);
		checkAxis[5] = TVector3(0,0,-1);
		// по углам
		checkAxis[6] = TVector3(1,1,1);
		checkAxis[7] = TVector3(1,1,-1);
		checkAxis[8] = TVector3(1,-1,1);
		checkAxis[9] = TVector3(1,-1,-1);
		checkAxis[10] = TVector3(-1,1,1);
		checkAxis[11] = TVector3(-1,1,-1);
		checkAxis[12] = TVector3(-1,-1,1);
		checkAxis[13] = TVector3(-1,-1,-1);

		float diffDelta = 10000.0f;
		TVector3 searchDelta;
		int searchIndexAxis = -1;
		for( int iCheckAxis = 0 ; iCheckAxis < countCheckAxis ; iCheckAxis++ )
		{
			TVector3 rotPoint;
			SetVec3TransformCoord(&rotPoint, &checkAxis[iCheckAxis], pM);
			TVector3 d = rotPoint - checkAxis[iCheckAxis];// куда повернулись?
			if( diffDelta > d.length() )
			{
				searchDelta = d;
				diffDelta = d.length();
				searchIndexAxis = iCheckAxis;
			}
		}
		if( searchIndexAxis==-1 )
		{
			BL_FIX_BUG();
			return;
		}
		*pVOut = checkAxis[searchIndexAxis] + searchDelta/2.0f;
		*pAngleOut = float(M_PI);
		return;
	}

	float plusX = (pM->m[2][1] - pM->m[1][2])/sinA;
	float plusY = (pM->m[0][2] - pM->m[2][0])/sinA;
	float plusZ = (pM->m[1][0] - pM->m[0][1])/sinA;

	float minusX 		 = -plusX;
	float minusY 	 	 = -plusY;
	float minusZ 	 	 = -plusZ;

	const int countVariant = 8;
	TVector3 axis[countVariant];
	axis[0] = TVector3(plusX, plusY,  plusZ);
	axis[1] = TVector3(plusX, plusY,  minusZ);
	axis[2] = TVector3(plusX, minusY, plusZ);
	axis[3] = TVector3(plusX, minusY, minusZ);

	axis[4] = TVector3(minusX, plusY,  plusZ);
	axis[5] = TVector3(minusX, plusY,  minusZ);
	axis[6] = TVector3(minusX, minusY, plusZ);
	axis[7] = TVector3(minusX, minusY, minusZ);

	float diff = 1000.0f;
	int searchIndex = -1;
	for( int i = 0 ; i < countVariant ; i++ )
	{
		TMatrix16 maybeM;
		SetMatrixRotationAxis(&maybeM, &axis[i], plusAngle);

		float sumDiff = 0;
		for( int iColumn = 0 ; iColumn < 3 ; iColumn++ )
		{
			for( int iRow = 0 ; iRow < 3 ; iRow++ )
				sumDiff += abs(pM->m[iColumn][iRow] - maybeM.m[iColumn][iRow]);
		}
		if( diff > sumDiff )
		{
			diff = sumDiff;
			searchIndex = i;
		}
	}
	if( searchIndex==-1 )
	{
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
void SetMatrixToQuaternion(const TMatrix16 *pM, TQuaternion *pQOut, bool correctPI)
{
	TVector3 axis;
	float angle;
	SetMatrixToAxisAngle(pM, &axis, &angle);
	if( correctPI )// коррекция в окрестностях
	{
		float broad = float(M_PI - msEpsilon);
		float setAngle = float(M_PI - 2*msEpsilon);
		if( angle > broad )
			angle = setAngle;
		else if( angle < -broad )
			angle = -setAngle;
	}
	
	SetQuaternionRotationAxis(pQOut, &axis, angle);
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixMultiply(TMatrix16 *pOut,
                             const TMatrix16 *pM1,
                             const TMatrix16 *pM2)
{
	if(pOut==NULL)
		return pOut;

  TMatrix16 resM;
	for(int i = 0 ; i < 4 ; i++)
	{
 		for( int j = 0 ; j < 4 ; j++)
		{
			resM.m[i][j] = pM1->m[i][0] * pM2->m[0][j] + 
			               pM1->m[i][1] * pM2->m[1][j] + 
								  	 pM1->m[i][2] * pM2->m[2][j] + 
					 			  	 pM1->m[i][3] * pM2->m[3][j];
		}
	}
  *pOut = resM;
	return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Subtract(TVector3* pOut, 
													const TVector3* pV1, 
													const TVector3* pV2)
{
	if(pOut==NULL)
		return pOut;

	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;
	return pOut;
}
//-------------------------------------------------------------------------
TVector3*  SetVec3TransformCoord(TVector3* pOut,
                                 const TVector3* pV,
                                 const TMatrix16* pM)
{
	float norm;

	norm = pM->m[0][3] * pV->x + pM->m[1][3] * pV->y + pM->m[2][3] *pV->z + pM->m[3][3];

	if( norm )
	{
		const TVector3 v = *pV;
		pOut->x = (pM->m[0][0] * v.x + pM->m[1][0] * v.y + pM->m[2][0] * v.z + pM->m[3][0]) / norm;
		pOut->y = (pM->m[0][1] * v.x + pM->m[1][1] * v.y + pM->m[2][1] * v.z + pM->m[3][1]) / norm;
		pOut->z = (pM->m[0][2] * v.x + pM->m[1][2] * v.y + pM->m[2][2] * v.z + pM->m[3][2]) / norm;
	}
	else
	{
		pOut->x = 0.0f;
		pOut->y = 0.0f;
		pOut->z = 0.0f;
	}
	return pOut;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Cross( TVector3* pOut,
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
float SetVec3Dot( const TVector3* pV1,
                 const TVector3* pV2)
{
  float res = pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
  return res;
}
//-------------------------------------------------------------------------
float SetVec3Angle( const nsMathTools::TVector3* pV1,
										const nsMathTools::TVector3* pV2)
{
	float len1 = pV1->length();
	float len2 = pV2->length();
	if( len1 <= msEpsilon || len2<=msEpsilon )
		return 0;
	float dot = SetVec3Dot(pV1,pV2);
	float cosAngle = dot/(len1*len2);
	if( cosAngle > 1.0f )// может возникать как правило как погрешность вычисления
		cosAngle = 1.0f;
	if( cosAngle < -1.0f )// может возникать как правило как погрешность вычисления
		cosAngle = -1.0f;
	float angle = acos(cosAngle);
	return angle;
}
//-------------------------------------------------------------------------
TVector3* SetVec3Normalize(TVector3* pOut,
                           const TVector3* pV)
{
  if(pOut==NULL)
    return NULL;

  *pOut = *pV;
  float len = pOut->length();
  if(len > 0.0f)
    pOut->operator /= (len);

  return pOut;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixPerspectiveFovLH( TMatrix16* pOut, 
                                      float fovy, 
                                      float Aspect, 
                                      float zn, float zf )
{
	if((Aspect==0.0f) ||
		 (fovy  ==0.0f) ||
	   (zn==zf))
	  return NULL;

	float tan_fovy_2 = tan(fovy/2.0f);
  float _11 = 1.0f / (Aspect * tan_fovy_2);
  float _22 = 1.0f / tan_fovy_2;

  pOut->s._11 = _11;    pOut->s._12 =  0.0f;   pOut->s._13 = 0.0f;           pOut->s._14 = 0.0f;
  pOut->s._21 = 0.0f;   pOut->s._22 = _22;     pOut->s._23 = 0.0f;           pOut->s._24 = 0.0f;
  pOut->s._31 = 0.0f;   pOut->s._32 =  0.0f;   pOut->s._33 = zf/(zf-zn);     pOut->s._34 = 1.0f;
  pOut->s._41 = 0.0f;   pOut->s._42 =  0.0f;   pOut->s._43 = -zn*zf/(zf-zn); pOut->s._44 = 0.0f;

  return pOut;
}
//-------------------------------------------------------------------------
float SetMatrixfDeterminant(const nsMathTools::TMatrix16 *pm)
{
	TVector4 minor, v1, v2, v3;
	float det;

	v1.x = pm->m[0][0]; v1.y = pm->m[1][0]; v1.z = pm->m[2][0]; v1.w = pm->m[3][0];
	v2.x = pm->m[0][1]; v2.y = pm->m[1][1]; v2.z = pm->m[2][1]; v2.w = pm->m[3][1];
	v3.x = pm->m[0][2]; v3.y = pm->m[1][2]; v3.z = pm->m[2][2]; v3.w = pm->m[3][2];
	SetVec4Cross(&minor,&v1,&v2,&v3);
	det =  - (pm->m[0][3] * minor.x + pm->m[1][3] * minor.y + pm->m[2][3] * minor.z + pm->m[3][3] * minor.w);
	return det;
}
//-------------------------------------------------------------------------
TMatrix16* SetMatrixInverse(TMatrix16* pout,
                            float* pdeterminant,
                            const TMatrix16* pm )
{
	int a, i, j;
	TVector4 v, vec[3];
	float det;

	det = SetMatrixfDeterminant(pm);
	if ( !det ) return NULL;
	if ( pdeterminant ) *pdeterminant = det;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			if (j != i )
			{
				a = j;
				if ( j > i ) a = a-1;
				vec[a].x = pm->m[j][0];
				vec[a].y = pm->m[j][1];
				vec[a].z = pm->m[j][2];
				vec[a].w = pm->m[j][3];
			}
		}
		SetVec4Cross(&v, &vec[0], &vec[1], &vec[2]);
		pout->m[0][i] = pow(-1.0f, i) * v.x / det;
		pout->m[1][i] = pow(-1.0f, i) * v.y / det;
		pout->m[2][i] = pow(-1.0f, i) * v.z / det;
		pout->m[3][i] = pow(-1.0f, i) * v.w / det;
	}
	return pout;
}
//-------------------------------------------------------------------------
TVector4* SetVec4Cross(TVector4 *pout, 
											 const TVector4 *pv1, 
											 const TVector4 *pv2, 
											 const TVector4 *pv3)
{
	TVector4 out;
	out.x = pv1->y * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->y * pv3->w - pv3->y * pv2->w) + pv1->w * (pv2->y * pv3->z - pv2->z *pv3->y);
	out.y = -(pv1->x * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->x * pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->z - pv3->x * pv2->z));
	out.z = pv1->x * (pv2->y * pv3->w - pv3->y * pv2->w) - pv1->y * (pv2->x *pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->y - pv3->x * pv2->y);
	out.w = -(pv1->x * (pv2->y * pv3->z - pv3->y * pv2->z) - pv1->y * (pv2->x * pv3->z - pv3->x *pv2->z) + pv1->z * (pv2->x * pv3->y - pv3->x * pv2->y));
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
TPlane* SetPlaneFromPoints( TPlane* pOut,
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
TVector3* SetPlaneIntersectLine( TVector3* pOut,
                                const TPlane*   pP,
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
	if ( !dot ) return NULL;
	temp = ( pP->d + SetVec3Dot(&normal, pV1) ) / dot;
	pOut->x = pV1->x - temp * direction.x;
	pOut->y = pV1->y - temp * direction.y;
	pOut->z = pV1->z - temp * direction.z;
	return pOut;
}
//-------------------------------------------------------------------------
TPlane* SetPlaneTransform( TPlane* pOut,
                          const TPlane*    pP,
                          const TMatrix16* pM)
{
	const TPlane plane = *pP;
	pOut->a = pM->m[0][0] * plane.a + pM->m[1][0] * plane.b + pM->m[2][0] * plane.c + pM->m[3][0] * plane.d;
	pOut->b = pM->m[0][1] * plane.a + pM->m[1][1] * plane.b + pM->m[2][1] * plane.c + pM->m[3][1] * plane.d;
	pOut->c = pM->m[0][2] * plane.a + pM->m[1][2] * plane.b + pM->m[2][2] * plane.c + pM->m[3][2] * plane.d;
	pOut->d = pM->m[0][3] * plane.a + pM->m[1][3] * plane.b + pM->m[2][3] * plane.c + pM->m[3][3] * plane.d;
	return pOut;
}
//-------------------------------------------------------------------------
TQuaternion * SetQuaternionMultiply(TQuaternion *pOut,
                                    const TQuaternion *pQ1,
                                    const TQuaternion *pQ2)
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
TQuaternion * SetQuaternionIdentity(TQuaternion *pOut)
{
  pOut->x = 0.0f;
  pOut->y = 0.0f;
  pOut->z = 0.0f;
  pOut->w = 1.0f;
  return pOut;
}
//-------------------------------------------------------------------------
TQuaternion* SetQuaternionRotationAxis(TQuaternion* pOut,
                                       const TVector3 *pV,
                                       float Angle)
{
  pOut->w = cos(Angle/2);
  float sinAngle_2 = sin(Angle/2);
  pOut->x = sinAngle_2*pV->x;
  pOut->y = sinAngle_2*pV->y;
  pOut->z = sinAngle_2*pV->z;
  return pOut;
}
//-------------------------------------------------------------------------
void SetQuaternionToAxisAngle(const TQuaternion *pQ,
                              TVector3 *pAxis,
                              float *pAngle)
{
  float angle = atan2(sqrt(pQ->x*pQ->x + pQ->y*pQ->y + pQ->z*pQ->z), pQ->w);
  float sinAngle = sin(angle);
  if( fabs(sinAngle) >= msEpsilon )// Gauss 26.07.2017
  {
    pAxis->x = pQ->x/sinAngle;
    pAxis->y = pQ->y/sinAngle;
    pAxis->z = pQ->z/sinAngle;
  }
  else
  {
		// correct angle
		// Pi or 0
		float cosAngle = cos(angle);
		if( cosAngle < 0 )
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
														 nsMathTools::TVector3* pUpTo,   nsMathTools::TVector3* pForwardTo,
														 nsMathTools::TVector3* pUpFrom, nsMathTools::TVector3* pForwardFrom)
{
	SetMatrixIdentity(pM);

	// найти угол между векторами
	float angleForward = SetVec3Angle(pForwardTo,pForwardFrom);
	BL_ASSERT( angleForward >= 0.0f );
	nsMathTools::TVector3 normalForward;
	if( angleForward > M_PI - msEpsilon )
	{
		angleForward = float(M_PI);
		normalForward = *pUpFrom;
	}
	else
	{
		SetVec3Cross(&normalForward, pForwardFrom, pForwardTo);
	}
	SetVec3Normalize(&normalForward,&normalForward);

	nsMathTools::TMatrix16 calcMatrixForward;
	SetMatrixRotationAxis(&calcMatrixForward, &normalForward, angleForward);

	nsMathTools::TVector3 rotUpFrom;
	SetVec3TransformCoord(&rotUpFrom, pUpFrom, &calcMatrixForward);

	float angleUp = SetVec3Angle(&rotUpFrom,pUpTo);
	nsMathTools::TVector3 normalUp;
	if( angleUp > M_PI - msEpsilon )
	{
		angleUp = float(M_PI);
		normalUp = *pForwardTo;
	}
	else
	{
		SetVec3Cross(&normalUp, &rotUpFrom, pUpTo);
	}
	SetVec3Normalize(&normalUp,&normalUp);
	nsMathTools::TMatrix16 calcMatrixUp;
	SetMatrixRotationAxis(&calcMatrixUp, &normalUp, angleUp);

	*pM = calcMatrixForward*calcMatrixUp;
}
//-------------------------------------------------------------------------
void CalcMatrix(nsMathTools::TMatrix16* pOut, 
							  nsMathTools::TMatrix16* pTo, nsMathTools::TMatrix16* pFrom)
{
	nsMathTools::TVector3 Up(0,1,0);
	nsMathTools::TVector3 Forward(1,0,0);

	nsMathTools::TVector3 UpTo;
	nsMathTools::TVector3 ForwardTo;
	nsMathTools::TVector3 UpFrom;
	nsMathTools::TVector3 ForwardFrom;

	SetVec3TransformCoord(&UpTo,        &Up,      pTo);
	SetVec3TransformCoord(&ForwardTo,   &Forward, pTo);
	SetVec3TransformCoord(&UpFrom,      &Up,      pFrom);
	SetVec3TransformCoord(&ForwardFrom, &Forward, pFrom);

	CalcMatrixByMoveVectors(pOut, &UpTo, &ForwardTo, &UpFrom, &ForwardFrom);
}
//-------------------------------------------------------------------------
float SetQuaternionLength(const TQuaternion *pQ)
{
	return sqrt(pQ->x*pQ->x + pQ->y*pQ->y + pQ->z*pQ->z + pQ->w*pQ->w);
}
//-------------------------------------------------------------------------
TMatrix16::TMatrix16()
{
	SetMatrixIdentity(this);
}
//-------------------------------------------------------------------------
TMatrix16::TMatrix16( float _11, float _12, float _13, float _14,
                      float _21, float _22, float _23, float _24,
                      float _31, float _32, float _33, float _34,
                      float _41, float _42, float _43, float _44 )
{
  this->s._11 = _11; this->s._12 = _12; this->s._13 = _13; this->s._14 = _14;
  this->s._21 = _21; this->s._22 = _22; this->s._23 = _23; this->s._24 = _24;
  this->s._31 = _31; this->s._32 = _32; this->s._33 = _33; this->s._34 = _34;
  this->s._41 = _41; this->s._42 = _42; this->s._43 = _43; this->s._44 = _44;
}
//-------------------------------------------------------------------------
// assignment operators
TMatrix16& TMatrix16::operator += ( const TMatrix16& v)
{
  MATRIX16_OP_P_M(this,v, += )
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator -= ( const TMatrix16& v)
{
  MATRIX16_OP_P_M(this,v, -= )
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator *= ( float v)
{
  MATRIX16_OP_P(this,v,*=)
    return *this;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator /= ( float v)
{
  MATRIX16_OP_P(this,v,/=)
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
TMatrix16 TMatrix16::operator + ( const TMatrix16& v) const
{
  TMatrix16 res = *this;
  MATRIX16_OP_M_M(res,v,+=)  
    return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator - ( const TMatrix16& v) const
{
  TMatrix16 res = *this;
  MATRIX16_OP_M_M(res,v,-=)
    return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator * ( float v) const
{
  TMatrix16 res = *this;
  MATRIX16_OP_M(res,v,*=)

    return res;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator / ( float v) const
{
  TMatrix16 res = *this;
  MATRIX16_OP_M(res,v,/=)

    return res;
}
//-------------------------------------------------------------------------
bool TMatrix16::operator == ( const TMatrix16& v) const
{
  for(int k = 0 ; k < 4 ; k++)
    for(int n = 0 ; n < 4 ; n++)
      if(BASE_MATRIX_OP(this,v,!=,->,.,k,n))
        return false;
  return true;
}
//-------------------------------------------------------------------------
bool TMatrix16::operator != ( const TMatrix16& v) const
{
  for(int k = 0 ; k < 4 ; k++)
    for(int n = 0 ; n < 4 ; n++)
      if(BASE_MATRIX_OP(this,v,==,->,.,k,n))
        return false;
  return true;
}
//-------------------------------------------------------------------------
TMatrix16& TMatrix16::operator *= ( const TMatrix16& v)
{
  SetMatrixMultiply(this, this, &v);
  return *this;
}
//-------------------------------------------------------------------------
TMatrix16 TMatrix16::operator * ( const TMatrix16& v) const
{
  TMatrix16 res;
  SetMatrixMultiply(&res, this, &v);
  return res;
}
//-------------------------------------------------------------------------
void TMatrix16::CalcAxisAngle()
{
	SetMatrixToAxisAngle(this, &axis, &angle);
}
//-------------------------------------------------------------------------
TVector2::operator float* ()
{
  return (float*)this;
}
//-------------------------------------------------------------------------
TVector2::operator const float* () const
{
  return (const float*)this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator += ( const TVector2& v)
{
  x += v.x;
  y += v.y;
  return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator -= ( const TVector2& v)
{
  x -= v.x;
  y -= v.y;
  return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator *= ( float v)
{
  x *= v;
  y *= v;
  return *this;
}
//-------------------------------------------------------------------------
TVector2& TVector2::operator /= ( float v)
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
TVector2 TVector2::operator + ( const TVector2& v) const
{
  TVector2 res;
  res.x = x + v.x;
  res.y = y + v.y;
  return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator - ( const TVector2& v) const
{
  TVector2 res;
  res.x = x - v.x;
  res.y = y - v.y;
  return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator * ( float v) const
{
  TVector2 res;
  res.x = x * v;
  res.y = y * v;
  return res;
}
//-------------------------------------------------------------------------
TVector2 TVector2::operator / ( float v) const
{
  TVector2 res;
  res.x = x / v;
  res.y = y / v;
  return res;
}
//-------------------------------------------------------------------------
bool TVector2::operator == ( const TVector2& v) const
{
  return ((v.x==x)&&(v.y==y));
}
//-------------------------------------------------------------------------
bool TVector2::operator != ( const TVector2& v) const
{
  return ((v.x!=x)||(v.y!=y));
}
//-------------------------------------------------------------------------
bool TVector2::operator > ( const TVector2& v) const
{
  if(x>v.x) return true;// высший
  else if(x<v.x) return false;
  //
  if(y>v.y) 
    return true;// низший

  return false;
}
//-------------------------------------------------------------------------
bool TVector2::operator < ( const TVector2& v) const
{
  if(x<v.x) return true;// высший
  else if(x>v.x) return false;
  //
  if(y<v.y) 
    return true;// низший

  return false;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator += ( const TVector3& pV)
{
  x += pV.x;
  y += pV.y;
  z += pV.z;
  return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator -= ( const TVector3& pV)
{
  x -= pV.x;
  y -= pV.y;
  z -= pV.z;
  return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator *= ( float v)
{
  x *= v;
  y *= v;
  z *= v;
  return *this;
}
//-------------------------------------------------------------------------
TVector3& TVector3::operator /= ( float v)
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
TVector3 TVector3::operator + ( const TVector3& pV) const
{
  TVector3 res;
  res.x = x + pV.x;
  res.y = y + pV.y;
  res.z = z + pV.z;
  return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator - ( const TVector3& pV) const
{
  TVector3 res;
  res.x = x - pV.x;
  res.y = y - pV.y;
  res.z = z - pV.z;
  return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator * ( float v) const
{
  TVector3 res;
  res.x = x * v;
  res.y = y * v;
  res.z = z * v;
  return res;
}
//-------------------------------------------------------------------------
TVector3 TVector3::operator / ( float v) const
{
  TVector3 res;
  res.x = x / v;
  res.y = y / v;
  res.z = z / v;
  return res;
}
//-------------------------------------------------------------------------
bool TVector3::operator == ( const TVector3& pV) const
{
  return ((pV.x==x)&&(pV.y==y)&&(pV.z==z));
}
//-------------------------------------------------------------------------
bool TVector3::operator != ( const TVector3& pV) const
{
  return ((pV.x!=x)||(pV.y!=y)||(pV.z!=z));
}
//-------------------------------------------------------------------------
bool TVector3::operator > ( const TVector3& v) const
{
  if(x>v.x) return true; // high assign,  высший разряд
  else if(x<v.x) return false;
  //---------------------------------
  if(y>v.y) return true;
  else if(y<v.y) return false;
  //---------------------------------
  if(z>v.z)// low assign, низший разряд
    return true;
  return false;
}
//-------------------------------------------------------------------------
bool TVector3::operator < ( const TVector3& v) const
{
  if(x<v.x) return true; // high assign, высший разряд
  else if(x>v.x) return false;
  //---------------------------------
  if(y<v.y) return true;
  else if(y>v.y) return false;
  //---------------------------------
  if(z<v.z)// low assign, низший разряд
    return true;
  return false;
}
//-------------------------------------------------------------------------
float TVector3::length() const
{
  return sqrt(x*x+y*y+z*z);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
TPlane::TPlane( const float* pF)
{
  a = pF[0];
  b = pF[1];
  c = pF[2];
  d = pF[3];
}
//-------------------------------------------------------------------------
TPlane::TPlane( float _a, float _b, float _c, float _d )
{
  a = _a;
  b = _b;
  c = _c;
  d = _d;
}
//-------------------------------------------------------------------------
TPlane::operator float* ()
{
  return (float*)this;
}
//-------------------------------------------------------------------------
TPlane::operator const float* () const
{
  return (const float*)this;
}
//-------------------------------------------------------------------------
TPlane& TPlane::operator *= ( float v)
{
  a *= v;
  b *= v;
  c *= v;
  d *= v;
  return *this;
}
//-------------------------------------------------------------------------
TPlane& TPlane::operator /= ( float v)
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
TPlane TPlane::operator * ( float v) const
{
  TPlane res;
  res.a *= v;
  res.b *= v;
  res.c *= v;
  res.d *= v;
  return res;
}
//-------------------------------------------------------------------------
TPlane TPlane::operator / ( float v) const
{
  TPlane res;
  res.a /= v;
  res.b /= v;
  res.c /= v;
  res.d /= v;
  return res;
}
//-------------------------------------------------------------------------
bool TPlane::operator == ( const TPlane& p) const
{
  return ((p.a==a)&&(p.b==b)&&(p.c==c)&&(p.d==d));
}
//-------------------------------------------------------------------------
bool TPlane::operator != ( const TPlane& p) const
{
  return ((p.a!=a)||(p.b!=b)||(p.c!=c)||(p.d!=d));
}
//-------------------------------------------------------------------------
bool TLine::FindAndSetIntersect(TPlane* pP1,TPlane* pP2)
{
  //1 найдем тип прямой (зависит от того равны ли коэффициенты плоскости нулю)
  // find type of line (determinate by equal coefficient of plane equal zero)
  if((*pP1==*pP2)           ||// line will plane, линия выродилась в плоскость
    (*pP1==TPlane(0,0,0,0))||// will zero equal, вырожденное уравнение
    (*pP2==TPlane(0,0,0,0)))
  {
    SetType(eUndef);
    return false;
  }
  //  by X, через Х
  if(pP1->c*pP2->b!=pP2->c*pP1->b)
  {
    float div = pP1->c*pP2->b - pP1->b*pP2->c;// c1*b2-b1*c2
    a = (pP1->a*pP2->c - pP1->c*pP2->a)/div;// a1*c2-c1*a2
    b = (pP1->d*pP2->c - pP1->c*pP2->d)/div;// d1*c2-d2*c1
    c = (pP1->b*pP2->a - pP1->a*pP2->b)/div;// b1*a2-b2*a1
    d = (pP1->b*pP2->d - pP1->d*pP2->b)/div;// b1*d2-b2*d1
    SetType(eX);
  }// by Z, через Z
  else if(pP1->a*pP2->b!=pP2->a*pP1->b)
  {
    float div = pP1->b*pP2->a - pP1->a*pP2->b;// b1*a2-a1*b2 
    a = (pP1->c*pP2->b - pP1->b*pP2->c)/div;// c1*b2-b1*c2 
    b = (pP1->d*pP2->b - pP1->b*pP2->d)/div;// d1*b2-d2*b1
    div *= -1.0f;;// b2*a1-a2*b1 
    c = (pP1->c*pP2->a - pP1->a*pP2->c)/div;// c1*a2-a1*c2
    d = (pP1->d*pP2->a - pP1->a*pP2->d)/div;// d1*a2-a1*d2
    SetType(eZ);
  }// by Y, через Y
  else
  {
    float div = pP1->a*pP2->c - pP1->c*pP2->a;// a1*c2-c1*a2
    a = (pP1->c*pP2->b - pP1->b*pP2->c)/div;// c1*b2-b1*c2
    b = (pP1->c*pP2->d - pP1->d*pP2->c)/div;// c1*d2-d1*c2
    div *= -1.0f;// c1*a2-a1*c2
    c = (pP1->a*pP2->b - pP1->b*pP2->a)/div;// a1*b2-b1*a2
    d = (pP1->a*pP2->d - pP1->d*pP2->a)/div;// a1*d2-d1*a2
    SetType(eY);    
  }
  return true;
}
//-------------------------------------------------------------------------
bool TLine::FindVector(TVector3* pOut1, TVector3* pOut2, bool do_normal)
{
  if(mType==eUndef)
    return false;

  TVector3 betweenPoint;
  switch(mType)
  {
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

  if(do_normal)
  {
    SetVec3Normalize(pOut1,pOut1);
    SetVec3Normalize(pOut2,pOut2);
  }
  return true;
}
//-------------------------------------------------------------------------
void TLine::Calc(float arg, float* res1, float* res2)
{
  BL_ASSERT(res1);
  BL_ASSERT(res2);
  *res1 = a*arg + b;
  *res2 = c*arg + d;
}
//-------------------------------------------------------------------------
TQuaternion::TQuaternion( const float * pF)
{
  x = pF[0];
  y = pF[1];
  z = pF[2];
  w = pF[3];
}
//-------------------------------------------------------------------------
TQuaternion::TQuaternion( float _x, float _y, float _z, float _w )
{
  x = _x;
  y = _y;
  z = _z;
  w = _w;
}
//-------------------------------------------------------------------------
TQuaternion::operator float* ()
{
  return (float*)this;
}
//-------------------------------------------------------------------------
TQuaternion::operator const float* () const
{
  return (const float*)this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator += ( const TQuaternion& q)
{
  *this = *this + q;
  return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator -= ( const TQuaternion& q)
{
  *this = *this - q;
  return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator *= ( const TQuaternion& q)
{
  *this = *this * q;
  return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator *= ( float v)
{
  *this = *this * v;
  return *this;
}
//-------------------------------------------------------------------------
TQuaternion& TQuaternion::operator /= ( float v)
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
TQuaternion TQuaternion::operator + ( const TQuaternion& q) const
{
  TQuaternion res;
  res.x = x + q.x;
  res.y = y + q.y;
  res.z = z + q.z;
  res.w = w + q.w;
  return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator - ( const TQuaternion& q) const
{
  TQuaternion res;
  res.x = x - q.x;
  res.y = y - q.y;
  res.z = z - q.z;
  res.w = w - q.w;
  return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator * ( const TQuaternion& q) const
{
  TQuaternion res;
  SetQuaternionMultiply(&res,this,&q);
  return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator * ( float v) const
{
  TQuaternion res;
  res.x = x * v;
  res.y = y * v;
  res.z = z * v;
  res.w = w * v;
  return res;
}
//-------------------------------------------------------------------------
TQuaternion TQuaternion::operator / ( float v) const
{
  TQuaternion res;
  res.x = x / v;
  res.y = y / v;
  res.z = z / v;
  res.w = w / v;
  return res;
}
//-------------------------------------------------------------------------
bool TQuaternion::operator == ( const TQuaternion& q) const
{
  return ((q.x==x)&&(q.y==y)&&(q.z==z)&&(q.w==w));
}
//-------------------------------------------------------------------------
bool TQuaternion::operator != ( const TQuaternion& q) const
{
  return ((q.x!=x)||(q.y!=y)||(q.z!=z)||(q.w!=w));
}
//-------------------------------------------------------------------------
TOrientation::TOrientation() 
{
	angle = 0;
}
//-------------------------------------------------------------------------
TOrientation::TOrientation( float x, float y, float z, float a ):
axis(x,y,z), angle(a)
{

}
//-------------------------------------------------------------------------
