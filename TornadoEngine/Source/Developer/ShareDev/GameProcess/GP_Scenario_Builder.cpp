/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_Scenario_Builder.h"

TGP_Scenario_Builder::TGP_Scenario_Builder()
{

}
//---------------------------------------------------------------------------------
TGP_Scenario_Builder::~TGP_Scenario_Builder()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::LoadMap(std::string nameMap)
{

}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::AddGameObject(TMapItem::TObject& desc)
{
  return false;
}
//---------------------------------------------------------------------------------
int TGP_Scenario_Builder::GetPhysicWorldID()
{
  return mBuilder.GetPhysicWorldID();
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP)
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::SetScene(TScene* pScene)
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Bullet()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Ogre()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Logic()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_OpenAL()
{

}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsBlock()
{
  return true;
}
//-------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_Builder::GetType()
{
  return nsGameProcess::eBuilder;
}
//-----------------------------------------------------------------------------
