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

  RegisterScenarioOnEvent(&mBuilder);
  RegisterScenarioOnEvent(&mSynchro);
  RegisterScenarioOnEvent(&mDestructor);
}
//---------------------------------------------------------------------------------------------
TGP_AggregationScenario_Client::~TGP_AggregationScenario_Client()
{
  // форсированно
  if(GetCurrentSc())
    GetCurrentSc()->Deactivate();// синхронизация и остановка всех потоков
  End();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP)
{
  if(IsActive(nsGameProcess::eBuilder)==false)
    return;
  mBuilder.Setup(pUsePattern, pFBP);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::LoadMap(std::string nameMap)
{
  if(IsActive(nsGameProcess::eBuilder)==false)
    return;
  // перейти в состояние загрузки карты
  mBuilder.LoadMap(nameMap);
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::AddGameObject(TMapItem::TObject& desc)
{
  if(IsActive(nsGameProcess::eBuilder)==false)
    return false;
  return mBuilder.AddGameObject(desc);
}
//---------------------------------------------------------------------------------------------
int TGP_AggregationScenario_Client::GetPhysicWorldID()
{
  return mBuilder.GetPhysicWorldID();
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::SetEnable(int id, bool v)
{
  if(IsActive(nsGameProcess::eSynchroClient)==false)
    return;
  mSynchro.SetEnable(id,v);
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::UpdateGameObjectFromGameItem(int id, std::string type, std::string name)
{
  if(IsActive(nsGameProcess::eSynchroClient)==false)
    return false;
  return mSynchro.UpdateGameObjectFromGameItem(id,type,name);
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::UpdateGameObjectFromPattern(int id, TContainer internalState)
{
  if(IsActive(nsGameProcess::eSynchroClient)==false)
    return false;
  return mSynchro.UpdateGameObjectFromPattern(id,internalState);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::UnloadAll()
{
  if(IsActive(nsGameProcess::eDestructor)==false)
    return;
  mDestructor.UnloadAll();
}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_Client::DeleteGameObject(int id)
{
  if(IsActive(nsGameProcess::eDestructor)==false)
    return false;
  return mDestructor.DeleteGameObject(id);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::SetScene(TScene* pScene)
{
  mPtrScene = pScene;
  mBuilder.   SetScene(pScene);
  mSynchro.   SetScene(pScene);
  mDestructor.SetScene(pScene);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_Client::GetByType(nsGameProcess::GP_TypeScenario type, 
    IGP_Scenario_General*& pGeneral, TGP_Scenario*& pScenario )
{
  switch(type)
  {
    case nsGameProcess::eBuilder:
      pGeneral = &mBuilder;
      pScenario = &mBuilder;
      break;
    case nsGameProcess::eSynchroClient:
      pGeneral = &mSynchro;
      pScenario = &mSynchro;
      break;
    case nsGameProcess::eDestructor:
      pGeneral = &mDestructor;
      pScenario = &mDestructor;
      break;
  }
}
//---------------------------------------------------------------------------------------------
