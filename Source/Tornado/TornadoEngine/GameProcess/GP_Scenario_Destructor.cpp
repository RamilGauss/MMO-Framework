/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GP_Scenario_Destructor.h"

TGP_Scenario_Destructor::TGP_Scenario_Destructor()
{

}
//---------------------------------------------------------------------------------
TGP_Scenario_Destructor::~TGP_Scenario_Destructor()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Destructor::UnloadAll()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Destructor::Work()
{

}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Destructor::IsActive()
{
  // меняется во времени!
  return true;
}
//-------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_Destructor::GetType()
{
  return nsGameProcess::eDestructor;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Destructor::Activate()
{

}
//-----------------------------------------------------------------------------
void TGP_Scenario_Destructor::Deactivate()
{

}
//-----------------------------------------------------------------------------
