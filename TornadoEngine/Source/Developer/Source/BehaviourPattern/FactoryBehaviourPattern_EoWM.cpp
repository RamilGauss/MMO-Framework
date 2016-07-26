/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPattern_EoWM.h"

TFactoryBehaviourPattern_EoWM::TFactoryBehaviourPattern_EoWM()
{
  mCB_Tank.Register(&TFactoryBehaviourPattern_EoWM::MakeTank, this);
  
  AddPattern(TMapStrCBVT("tank", &mCB_Tank));
}
//-----------------------------------------------------------------------------------
TFactoryBehaviourPattern_EoWM::~TFactoryBehaviourPattern_EoWM()
{

}
//-----------------------------------------------------------------------------------
void TFactoryBehaviourPattern_EoWM::MakeTank(TBehaviourPattern*& p)
{
  //p = new TPattern_Tank();
}
//----------------------------------------------------------------------------
