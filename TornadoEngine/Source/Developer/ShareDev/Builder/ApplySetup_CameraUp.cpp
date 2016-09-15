/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ApplySetup_CameraUp.h"
#include <OgreCamera.h>
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

TApplySetup_CameraUp::TApplySetup_CameraUp()
{

}
//------------------------------------------------------------------------
TApplySetup_CameraUp::~TApplySetup_CameraUp()
{

}
//------------------------------------------------------------------------
void TApplySetup_CameraUp::Set(nsMathTools::TVector3& vCameraUp)
{
  mVCameraUp = vCameraUp;
}
//------------------------------------------------------------------------
void TApplySetup_CameraUp::WorkFromThread_Ogre()
{
  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
  nsMathTools::TVector3 point(0,0,0);
  pCamera->setPosition(point.x, point.y, point.z);
  pCamera->lookAt(mVCameraUp.x, mVCameraUp.y, mVCameraUp.z);
  Ogre::Degree degree;
  degree = 90;
  Ogre::Radian rad;
  rad = degree.valueRadians();
  pCamera->pitch(rad);
}
//------------------------------------------------------------------------
