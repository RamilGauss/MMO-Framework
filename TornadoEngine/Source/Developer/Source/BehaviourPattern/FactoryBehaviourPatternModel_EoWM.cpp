/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPatternModel_EoWM.h"
#include "PatternModel_Model.h"

TFactoryBehaviourPatternModel_EoWM::TFactoryBehaviourPatternModel_EoWM()
{
  mCB_Tank.Register(&TFactoryBehaviourPatternModel_EoWM::MakeTank, this);
  mCB_Gear.Register(&TFactoryBehaviourPatternModel_EoWM::MakeGear, this);
  
  AddPattern(TMapStrCBVT("tank", &mCB_Tank));
  AddPattern(TMapStrCBVT("Gear", &mCB_Gear));
}
//-----------------------------------------------------------------------------------
TFactoryBehaviourPatternModel_EoWM::~TFactoryBehaviourPatternModel_EoWM()
{

}
//-----------------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeTank(TBehaviourPatternModel*& p)
{
  //p = new TPattern_Tank();
  p = new TPatternModel_Model();
}
//----------------------------------------------------------------------------
void TFactoryBehaviourPatternModel_EoWM::MakeGear(TBehaviourPatternModel*& p)
{
  p = new TPatternModel_Model();
}
//----------------------------------------------------------------------------
