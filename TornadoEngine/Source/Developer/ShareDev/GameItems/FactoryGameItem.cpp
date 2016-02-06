/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FactoryGameItem.h"
#include "MakerXML.h"

#include "MaterialItem.h"
#include "ShapeItem.h"
#include "ModelItem.h"
#include "TerrainItem.h"
#include "MapItem.h"
#include "TableSoundItem.h"
#include "BL_Debug.h"
#include "IXML.h"
#include <boost/foreach.hpp>

#include "ManagerSerializerItem.h"
#include "ManagerCacheItemXML.h"

TFactoryGameItem::TFactoryGameItem()
{
  TMakerXML makerXML;
  mXML = makerXML.New();

  MakeStr_Map();
}
//-----------------------------------------------------------------------------
TFactoryGameItem::~TFactoryGameItem()
{
  TMakerXML makerXML;
  makerXML.Delete(mXML);

  BOOST_FOREACH(TBaseItem* pItem, mListItems)
    delete pItem;
  mListItems.clear();
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::Init(std::string& name_file)
{
  bool resLoad = mXML->Load(name_file.data());
  BL_ASSERT(resLoad);

  mMngSerializer.reset(new TManagerSerializerItem);
  mMngCache.reset(new TManagerCacheItemXML);

  mMngSerializer->Init(mXML);
  mMngCache->Init(mXML);
  return resLoad;
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::Add(Type type, std::string& name)
{
  TBaseItem* pItem = NewItem(type, name);
  if(mMngSerializer->Save(type, pItem)==false)
  {
    delete pItem;
    return NULL;
  }

  mListItems.push_back(pItem);
  mMngCache->Init(mXML);// перезагрузить кэш (происходит редко, поэтому просто перезагрузить кэш)
  return pItem;
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::FindItemInMapByName(std::string& name, TMapStrPtrItem* pMap)
{
  TMapStrPtrItemIt fit = pMap->find(name);
  if(fit==pMap->end())
    return NULL;
  return fit->second;
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::AddItemInMap(TBaseItem* pItem, TMapStrPtrItem* pMap)
{
  pMap->insert(TMapStrPtrItemVT(pItem->mName, pItem));
}
//-----------------------------------------------------------------------------
int TFactoryGameItem::GetCount(Type type)
{
  std::string sType = mMngSerializer->StrByType(type);
  return mMngCache->GetCountByStrType(sType);
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::GetName(Type type, int index, std::string& name)
{
  std::string sType = mMngSerializer->StrByType(type);
  return mMngCache->GetNameByIndex(sType, index, name);
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::Get(Type type, std::string& name)
{
  TMapStrPtrItem* pMap = FindMap(type);
  TBaseItem* pItem = FindItemInMapByName(name, pMap);
  if(pItem)
    return pItem;
  
  pItem = NewItem(type, name);
  if(mMngSerializer->Load(type, pItem)==false)
  {
    delete pItem;
    return NULL;
  }
  mListItems.push_back(pItem);
  AddItemInMap(pItem, pMap);
  return pItem;
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::NewItem(Type type, std::string& name)
{
  TBaseItem* pItem = NULL;
  switch(type)
  {
    case Material:
      pItem = new TMaterialItem(name);
      break;
    case Shape:
      pItem = new TShapeItem(name);
      break;
    case Model:
      pItem = new TModelItem(name);
      break;
    case Map:
      pItem = new TMapItem(name);
      break;
    case Terrain:
      pItem = new TTerrainItem(name);
      break;
		case TableSound:
			pItem = new TTableSoundItem(name);
			break;
  }
  return pItem;
}
//-----------------------------------------------------------------------------
TFactoryGameItem::TMapStrPtrItem* TFactoryGameItem::FindMap(Type type)
{
  TMapInt_PtrMapStrPtrIt fit = mMapType_StrName_pItem.find(type);
  if(fit==mMapType_StrName_pItem.end())
    return NULL;

  return fit->second;
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::FullLoad()
{
  for( int iType = 0 ; iType < CountType ; iType++ )
  {
    std::string sType = mMngSerializer->StrByType(iType);
    int cntItem = mMngCache->GetCountByStrType(sType);
    for( int iItem = 0 ; iItem < cntItem ; iItem++ )
    {
      std::string name;
      mMngCache->GetNameByIndex(sType, iItem, name);
      Get((Type)iType, name);
    }
  }
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::MakeStr_Map()
{
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(Material,	 &mMapNameMaterial	));
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(Shape,   	 &mMapNameShape   	));
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(Model,   	 &mMapNameModel   	));
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(Terrain, 	 &mMapNameTerrain 	));
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(Map,     	 &mMapNameMap     	));
  mMapType_StrName_pItem.insert(TMapInt_PtrMapStrPtrVT(TableSound, &mMapNameTableSound));
}
//-----------------------------------------------------------------------------
