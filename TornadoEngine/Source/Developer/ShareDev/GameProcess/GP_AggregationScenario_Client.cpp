/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_AggregationScenario_Client.h"
#include "IGP_Scenario_General.h"

TGP_AggregationScenario_Client::TGP_AggregationScenario_Client()
{
  mPtrScene = NULL;
}
//---------------------------------------------------------------------------------------------
TGP_AggregationScenario_Client::~TGP_AggregationScenario_Client()
{

}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP)
{

}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::LoadMap(std::string nameMap)
{
  // перейти в состояние загрузки карты
  End();
  mBuilder.LoadMap(nameMap);
  Begin(&mBuilder);
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::AddGameObject(TMapItem::TObject& desc)
{
  return true;
}
//---------------------------------------------------------------------------------------------
int TGP_AggregationScenario_Client::GetPhysicWorldID()
{
  return mBuilder.GetPhysicWorldID();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::SetEnable(int id, bool v)
{

}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::UpdateGameObjectFromGameItem(int id, std::string type, std::string name)
{
  return true;
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::UpdateGameObjectFromPattern(int id, TContainer internalState)
{
  return true;
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::UnloadAll()
{

}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::DeleteGameObject(int id)
{
  return true;
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::SetScene(TScene* pScene)
{
  mPtrScene = pScene;
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Thread_Bullet()
{
  GetCurrentScGeneral()->Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Thread_Ogre()
{
  GetCurrentScGeneral()->Thread_Ogre();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Thread_Logic()
{
  // проверка на новые задания
  GetCurrentScGeneral()->Thread_Logic();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Thread_OpenAL()
{
  GetCurrentScGeneral()->Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::Activate(nsGameProcess::GP_TypeScenario type)
{
  return true;
}
//---------------------------------------------------------------------------------------------
