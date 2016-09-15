/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ApplySetup_GravityVector.h"
#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"

TApplySetup_GravityVector::TApplySetup_GravityVector()
{

}
//-----------------------------------------------------------------------
TApplySetup_GravityVector::~TApplySetup_GravityVector()
{

}
//-----------------------------------------------------------------------
void TApplySetup_GravityVector::Set(nsMathTools::TVector3& vGravity, int id_PhysicWorld)
{
  mVGravity = vGravity;
  mID_PhysicWorld = id_PhysicWorld;
}
//-----------------------------------------------------------------------
void TApplySetup_GravityVector::WorkFromThread_Bullet()
{
  btDiscreteDynamicsWorld* dynamicsWorld = 
    TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(mID_PhysicWorld);
  btVector3 vectorBullet(mVGravity.x, mVGravity.y, mVGravity.z);
  dynamicsWorld->setGravity(vectorBullet);
}
//-----------------------------------------------------------------------
