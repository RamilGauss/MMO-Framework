/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BoundingBoxH
#define BoundingBoxH

#include "TypeDef.h"
#include "Struct3D.h"


#if defined( WIN32 )
#pragma pack(push, 1)
#endif


class SHARE_EI TBoundingBox
{
protected:
  nsStruct3D::TVector3 mMin;
  nsStruct3D::TVector3 mMax;

public:

  TBoundingBox();
  ~TBoundingBox();

  void SetBound(nsStruct3D::TVector3& min,nsStruct3D::TVector3& max);
  void AddBound(nsStruct3D::TVector3& min,nsStruct3D::TVector3& max);

  nsStruct3D::TVector3& Min(){return mMin;};
  nsStruct3D::TVector3& Max(){return mMax;};

  bool IsCorrect();

  bool Contains(nsStruct3D::TVector3& point);
  bool Collision(TBoundingBox& bb);
  float VolumeCollision(TBoundingBox& bb);// у.е. в кубе
};

#if defined( WIN32 )
#pragma pack(pop)
#endif


#endif