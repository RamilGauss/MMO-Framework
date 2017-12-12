/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderGameMap.h"
#include <boost/foreach.hpp>

#include "MapItem.h"

#include "FactoryBehaviourPattern.h"

TBuilderGameMap::TBuilderGameMap()
{
  mMapItem = NULL;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Init(std::set<int>& useID_Module, 
           TFactoryBehaviourPattern* pFBP, int id_world)
{
  mUseID_Module            = useID_Module;
  mFactoryBehaviourPattern = pFBP;
  mPhysicWorldID           = id_world;

  mBuilderGameObject.Init(mUseID_Module, mFactoryBehaviourPattern, mPhysicWorldID);
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{
  // прежде чем уничтожать мир, деструктор должен уничтожить все объекты, связанные с ним!
  //TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->DeleteWorld(mPhysicWorldID);
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildMap( TMapItem* pMI )
{
  mListGameObject.clear();

  mMapItem = pMI;
  if( mMapItem==NULL )
    return false;

  mBeginIteratorMapObject = mMapItem->mListObject.begin();

  mBuilderGameObject.SetNameMap(mMapItem->mName);
  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Build()
{
  // создание и настройка игровых объектов
  TMapItem::TListObject::iterator eit = mMapItem->mListObject.end();
  if( mBeginIteratorMapObject!=eit )
  {
    TMapItem::TObject* pObject = &(*mBeginIteratorMapObject);
    int id = mBuilderGameObject.Begin(pObject);
    mListID_BuiltObject.push_back(id);
    mBeginIteratorMapObject++;
  }
  if( mListID_BuiltObject.size()==0 )
    return;
  TListIntIt bitID = mListID_BuiltObject.begin();
  TGameObject* pGO = mBuilderGameObject.Build(*bitID);
  if( pGO )
  {
    mListGameObject.push_back(pGO);
    mListID_BuiltObject.pop_front();
  }
}
//--------------------------------------------------------------------------------------------
int TBuilderGameMap::GetProgress()
{
  return (mListGameObject.size()*100)/mMapItem->mListObject.size();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::GetResult(TListPtrGameObject& listPtrGameObject)
{
  listPtrGameObject = mListGameObject;
}
//--------------------------------------------------------------------------------------------
