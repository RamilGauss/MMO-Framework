/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FactoryBehaviourPattern_EoWM.h"

#include "Pattern_Model.h"
#include "Pattern_Tank.h"
#include "Pattern_Gun.h"
#include "Pattern_Turret.h"
#include "Pattern_Hull.h"
#include "Pattern_Chassis.h"

TFactoryBehaviourPattern_EoWM::TFactoryBehaviourPattern_EoWM()
{
  mCB_Tank.   Register(&TFactoryBehaviourPattern_EoWM::MakeTank, this);
  mCB_Gun.    Register(&TFactoryBehaviourPattern_EoWM::MakeGun, this);
  mCB_Turret. Register(&TFactoryBehaviourPattern_EoWM::MakeTurret, this);
  mCB_Hull.   Register(&TFactoryBehaviourPattern_EoWM::MakeHull, this);
  mCB_Chassis.Register(&TFactoryBehaviourPattern_EoWM::MakeChassis, this);
  
  AddPattern(TMapStrCBVT("Tank",    &mCB_Tank));
  AddPattern(TMapStrCBVT("Hull",    &mCB_Hull));
  AddPattern(TMapStrCBVT("Turret",  &mCB_Turret));
  AddPattern(TMapStrCBVT("Chassis", &mCB_Chassis));
  AddPattern(TMapStrCBVT("Gun",     &mCB_Gun));
}
//-----------------------------------------------------------------------------------
TFactoryBehaviourPattern_EoWM::~TFactoryBehaviourPattern_EoWM()
{

}
//-----------------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeTank(TBehaviourPattern*& p)
{
  p = new TPattern_Tank();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeGun(TBehaviourPattern*& p)
{
  p = new TPattern_Gun();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeTurret(TBehaviourPattern*& p)
{
  p = new TPattern_Turret();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeHull(TBehaviourPattern*& p)
{
  p = new TPattern_Hull();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeChassis(TBehaviourPattern*& p)
{
  p = new TPattern_Chassis();
}
//----------------------------------------------------------------------------
