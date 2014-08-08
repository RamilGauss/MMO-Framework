/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BoundingBoxH
#define BoundingBoxH

#include "TypeDef.h"
#include "MathTools.h"


#if defined( WIN32 )
#pragma pack(push, 1)
#endif


class DllExport TBoundingBox
{
protected:
  nsMathTools::TVector3 mMin;
  nsMathTools::TVector3 mMax;

public:

  TBoundingBox();
  ~TBoundingBox();

  void SetBound(nsMathTools::TVector3& min,nsMathTools::TVector3& max);
  void AddBound(nsMathTools::TVector3& min,nsMathTools::TVector3& max);

  nsMathTools::TVector3& Min(){return mMin;};
  nsMathTools::TVector3& Max(){return mMax;};

  bool IsCorrect();

  bool Contains(nsMathTools::TVector3& point);
  bool Collision(TBoundingBox& bb);
  float VolumeCollision(TBoundingBox& bb);// у.е. в кубе
};

#if defined( WIN32 )
#pragma pack(pop)
#endif


#endif