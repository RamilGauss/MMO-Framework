/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPatternModel_EoWM.h"

#include "PatternModel_Model.h"
#include "PatternModel_Tank.h"
#include "PatternModel_Gun.h"
#include "PatternModel_Turret.h"
#include "PatternModel_Hull.h"
#include "PatternModel_Chassis.h"

TFactoryBehaviourPatternModel_EoWM::TFactoryBehaviourPatternModel_EoWM()
{
  mCB_Tank.   Register(&TFactoryBehaviourPatternModel_EoWM::MakeTank, this);
  mCB_Gun.    Register(&TFactoryBehaviourPatternModel_EoWM::MakeGun, this);
  mCB_Turret. Register(&TFactoryBehaviourPatternModel_EoWM::MakeTurret, this);
  mCB_Hull.   Register(&TFactoryBehaviourPatternModel_EoWM::MakeHull, this);
  mCB_Chassis.Register(&TFactoryBehaviourPatternModel_EoWM::MakeChassis, this);
  
  AddPattern(TMapStrCBVT("Tank",    &mCB_Tank));
  AddPattern(TMapStrCBVT("Hull",    &mCB_Hull));
  AddPattern(TMapStrCBVT("Turret",  &mCB_Turret));
  AddPattern(TMapStrCBVT("Chassis", &mCB_Chassis));
  AddPattern(TMapStrCBVT("Gun",     &mCB_Gun));
}
//-----------------------------------------------------------------------------------
TFactoryBehaviourPatternModel_EoWM::~TFactoryBehaviourPatternModel_EoWM()
{

}
//-----------------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeTank(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Tank();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeGun(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Gun();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeTurret(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Turret();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeHull(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Hull();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeChassis(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Chassis();
}
//----------------------------------------------------------------------------
