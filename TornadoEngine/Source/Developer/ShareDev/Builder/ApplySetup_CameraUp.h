/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ApplySetup_CameraUpH
#define ApplySetup_CameraUpH

#include "TypeDef.h"
#include "MathTools.h"

class DllExport TApplySetup_CameraUp
{
  nsMathTools::TVector3 mVCameraUp;
public:
  TApplySetup_CameraUp();
  virtual ~TApplySetup_CameraUp();

  void Set(nsMathTools::TVector3& vCameraUp);
  
  void WorkFromThread_Ogre();
};

#endif
