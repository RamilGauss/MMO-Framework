/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ApplySetup_GravityVectorH
#define ApplySetup_GravityVectorH

#include "TypeDef.h"
#include "MathTools.h"

class DllExport TApplySetup_GravityVector
{
  nsMathTools::TVector3 mVGravity;
  int mID_PhysicWorld;
public:
  TApplySetup_GravityVector();
  virtual ~TApplySetup_GravityVector();

  void Set(nsMathTools::TVector3& vGravity, int id_PhysicWorld);

  void WorkByModule_Physic();
};

#endif
