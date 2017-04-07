/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_AggregationScenario_GameMap.h"

TGP_AggregationScenario_GameMap::TGP_AggregationScenario_GameMap()
{
  RegisterScenarioOnEvent(&mSynchro);
  RegisterScenarioOnEvent(&mDestructor);

	mBuilder.GetCB_Progress()->Register(&TGP_AggregationScenario_GameMap::Progress_BuildGameMap, this);
	mBuilder.GetCB_End()->Register(&TGP_AggregationScenario_GameMap::End_BuildGameMap, this);
	mID_World = -1;
}
//---------------------------------------------------------------------------------------------
TGP_AggregationScenario_GameMap::~TGP_AggregationScenario_GameMap()
{

}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::LoadMap(std::string nameMap)
{
  if( IsActive(nsGameProcess::eBuilder)==false )
    return;
  // перейти в состояние загрузки карты
  mBuilder.LoadMap(nameMap);
}
//---------------------------------------------------------------------------------------------
TGameObject* TGP_AggregationScenario_GameMap::AddGameObject(TMapItem::TObject* pObject)
{
	if(IsActive(nsGameProcess::eSynchro)==false)
		return NULL;
	return mSynchro.AddGameObject(pObject);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::UpdateGameObjectByGameItem(int id, bool force)
{

}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::UpdateGameMapParam()
{

}
//---------------------------------------------------------------------------------------------
bool TGP_AggregationScenario_GameMap::DeleteGameObject(int id)
{
	return false;
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::UnloadAll()
{
  if(IsActive(nsGameProcess::eDestructor)==false)
    return;
  mDestructor.UnloadAll();
}
//---------------------------------------------------------------------------------------------
IGP_Scenario* TGP_AggregationScenario_GameMap::GetByType(nsGameProcess::GP_TypeScenario type)
{
	IGP_Scenario* pScenario = NULL;
  switch(type)
  {
    case nsGameProcess::eBuilder:
      pScenario = &mBuilder;
      break;
    case nsGameProcess::eSynchro:
      pScenario = &mSynchro;
      break;
    case nsGameProcess::eDestructor:
      pScenario = &mDestructor;
      break;
  }
	return pScenario;
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::End_BuildGameMap(nsGameProcess::GP_TypeScenario type)
{
	if( type!=nsGameProcess::eBuilder )
		return;

	EndEventScenario(type);
}
//---------------------------------------------------------------------------------------------
void TGP_AggregationScenario_GameMap::Progress_BuildGameMap(nsGameProcess::GP_TypeScenario type, int progress)
{
	if( type!=nsGameProcess::eBuilder )
		return;

	ProgressEventScenario(type, progress);
}
//---------------------------------------------------------------------------------------------
