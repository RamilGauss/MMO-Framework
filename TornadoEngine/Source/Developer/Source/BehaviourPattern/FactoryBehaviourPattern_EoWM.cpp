/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryBehaviourPattern_EoWM.h"

TFactoryBehaviourPattern_EoWM::TFactoryBehaviourPattern_EoWM()
{

}
//-----------------------------------------------------------------------------------
TFactoryBehaviourPattern_EoWM::~TFactoryBehaviourPattern_EoWM()
{

}
//-----------------------------------------------------------------------------------
int TFactoryBehaviourPattern_EoWM::GetCount()
{
  return 0;
}
//-----------------------------------------------------------------------------------
std::string TFactoryBehaviourPattern_EoWM::GetPatternNameByIndex(int index)
{
  return std::string();
}
//-----------------------------------------------------------------------------------
IBehaviourPattern* TFactoryBehaviourPattern_EoWM::MakePatternByName(std::string name)
{
  return NULL;
}
//-----------------------------------------------------------------------------------
