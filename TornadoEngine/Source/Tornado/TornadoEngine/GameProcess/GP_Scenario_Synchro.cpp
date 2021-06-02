/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GP_Scenario_Synchro.h"
#include "Scene.h"
#include "BL_Debug.h"
#include "GameObject.h"
#include "BehaviourPattern.h"

#include "ModuleLogic.h"
#include "FactoryGameItem.h"
#include "StorageGameItem_XML.h"

TGP_Scenario_Synchro::TGP_Scenario_Synchro()
{

}
//----------------------------------------------------------------------------------
TGP_Scenario_Synchro::~TGP_Scenario_Synchro()
{

}
//----------------------------------------------------------------------------------
TGameObject* TGP_Scenario_Synchro::AddGameObject(TMapItem::TObject* pObject)
{
  return NULL;
}
//----------------------------------------------------------------------------------
bool TGP_Scenario_Synchro::DeleteGameObject(int id)
{
  return false;
}
//----------------------------------------------------------------------------------
void TGP_Scenario_Synchro::SaveMap(std::string nameMap)
{
  // карта может и не существовать
  // тогда нужно создать в FGI
  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
  TMapItem* pMapITem = (TMapItem*)pFGI->Get(TFactoryGameItem::Map, nameMap);
  if( pMapITem==NULL )
  {
    pMapITem = (TMapItem*)pFGI->Add(TFactoryGameItem::Map, nameMap);
    if( pMapITem==NULL )
    {
      BL_FIX_BUG();
      return;
    }
  }
  
  pMapITem->mListObject.clear();

  // сброс данных всех объектов на HDD
  int cnt = mPtrScene->GetCount();
  for( int i = 0 ; i < cnt ; i++ )
  {
    TGameObject* pGO = mPtrScene->GetByIndex(i);
    if( pGO==NULL )
    {
      BL_FIX_BUG();
      continue;
    }
    TBehaviourPattern* pPattern = pGO->GetPattern();
    if( pPattern==NULL )
      continue;

    if( pPattern->UpdateGameItem(TFactoryGameItem::PatternConfig) )
    {
      pPattern->SaveGameItemOnHDD(TFactoryGameItem::PatternConfig);
      pPattern->SaveOutDataOnHDD(TFactoryGameItem::PatternConfig);
    }
    if( pPattern->GetBaseType()==TPatternNameManager::eTerrain )
    {
      if( pPattern->UpdateGameItem(TFactoryGameItem::Terrain) )
      {
        pPattern->SaveGameItemOnHDD(TFactoryGameItem::Terrain);
        pPattern->SaveOutDataOnHDD(TFactoryGameItem::Terrain);
      }
    }

    TMapItem::TObject object;
    object.id                        = pGO->GetID();
    object.namePattern               = pPattern->GetName();
    object.patternConfig.name        = pPattern->GetNamePatternConfig();
    object.patternConfig.nameVariant = pPattern->GetNameVariantPatternConfig();
    pPattern->GetPosition(object.position);
    pPattern->GetOrientation(object.orientation);

    pMapITem->mListObject.push_back(object);
  }

  pFGI->GetStorage_XML()->Save(pMapITem);
}
//----------------------------------------------------------------------------------
void TGP_Scenario_Synchro::Work()
{
  int cnt = mPtrScene->GetCountUsing();
  for( int i = 0 ; i < cnt ; i++ )
  {
    TGameObject* pGO = mPtrScene->GetUsingByIndex(i);
    if( pGO==NULL )
    {
      BL_FIX_BUG();
      continue;
    }
    TBehaviourPattern* pPattern = pGO->GetPattern();
    if( pPattern==NULL )
      continue;

    pPattern->SynchroByModule_Logic();
    if( UsePhysic() )
      pPattern->SynchroByModule_Physic();
    if( UseGraphic() )
      pPattern->SynchroByModule_Graphic();
    if( UseSound() )  
      pPattern->SynchroByModule_Sound();
  }
}
//----------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_Synchro::GetType()
{
  return nsGameProcess::eSynchro;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Synchro::Activate()
{

}
//-----------------------------------------------------------------------------
void TGP_Scenario_Synchro::Deactivate()
{

}
//-----------------------------------------------------------------------------
