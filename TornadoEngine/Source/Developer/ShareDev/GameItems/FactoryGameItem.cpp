/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FactoryGameItem.h"
#include "BL_Debug.h"

#include "PatternConfigItem.h"
#include "MaterialItem.h"
#include "ShapeItem.h"
#include "ModelItem.h"
#include "TerrainItem.h"
#include "MapItem.h"
#include "TableSoundItem.h"

#include "StorageGameItem_XML.h"
#include "ManagerSerializerItem_Binary.h"

TFactoryGameItem::TFactoryGameItem()
{
  mMngSerBin.reset( new TManagerSerializerItem_Binary );
  MakeStr_Map();
}
//-----------------------------------------------------------------------------
TFactoryGameItem::~TFactoryGameItem()
{
  Done();
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::Done()
{
  Clear();
  mMapType_StrName_pItem.clear();
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::Init_XML( std::string& name_file_xml )
{
  mStorageGameItem_XML.reset( new TStorageGameItem_XML );
  return mStorageGameItem_XML->Init( name_file_xml );
}
//-----------------------------------------------------------------------------
TStorageGameItem_XML* TFactoryGameItem::GetStorage_XML()
{
  return mStorageGameItem_XML.get();
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::Add( TypeGameItem type, std::string& name )
{
  TBaseItem* pItem = FindItemByTypeByName( type, name );
  if( pItem )
    Delete( pItem );
  pItem = MakeNewItem( type, name );
  if( pItem == NULL )
    return NULL;
  AddItemInMap( pItem );
  return pItem;
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::AddFromBinary( void* pIn, int sizeIn )
{
  int type;
  if( TBaseSerializerItem_Binary::ResolveType( pIn, sizeIn, type ) == false )
    return NULL;
  std::string name = "";
  TBaseItem* pItem = MakeNewItem( type, name );
  if( pItem == NULL )
    return NULL;
  if( mMngSerBin->Unpack( pItem, pIn, sizeIn ) == false )
  {
    delete pItem;
    return NULL;
  }
  TBaseItem* pFindItem = FindItemByTypeByName( pItem->mType, pItem->mName );
  if( pFindItem )
    Delete( pFindItem );
  AddItemInMap( pItem );
  return pItem;
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::MakeBinary( TypeGameItem type, std::string& name, TContainerRise& cBinOut )
{
  TBaseItem* pItem = Get( type, name );
  if( pItem == NULL )
    return false;
  return MakeBinary( pItem, cBinOut );
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::MakeBinary( TBaseItem* pItem, TContainerRise& cBinOut )
{
  mMngSerBin->Pack( pItem, cBinOut );
  return true;
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::Delete( TypeGameItem type, std::string& name )
{
  TMapStrPtrItem* pMap = FindMap( type );
  if( pMap == NULL )
    return false;
  TMapStrPtrItemIt fit = pMap->find( name );
  if( fit == pMap->end() )
    return false;
  delete fit->second;
  pMap->erase( name );
  return true;
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::Delete( TBaseItem* pItem )
{
  if( pItem == NULL )
    return false;
  return Delete( (TypeGameItem) pItem->mType, pItem->mName );
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::Get( TypeGameItem type, std::string& name )
{
  TBaseItem* pItem = FindItemByTypeByName( type, name );
  if( pItem )
    return pItem;

  if( mStorageGameItem_XML->IsExist( type, name ) == false )
    return NULL;

  pItem = MakeNewItem( type, name );
  if( mStorageGameItem_XML->Load( pItem ) == false )
  {
    delete pItem;
    return NULL;
  }
  AddItemInMap( pItem );
  return pItem;
}
//-----------------------------------------------------------------------------
int TFactoryGameItem::GetCountByType( TypeGameItem type )
{
  TMapStrPtrItem* pMap = FindMap( type );
  if( pMap == NULL )
    return 0;
  return pMap->size();
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::GetNameByType( TypeGameItem type, int index, std::string& name )
{
  TMapStrPtrItem* pMap = FindMap( type );
  if( pMap == NULL )
    return false;
  if( int( pMap->size() ) <= index )
    return false;
  TMapStrPtrItemIt bit = pMap->begin();
  for( int i = 0; i < index; i++ )
    bit++;
  name = bit->second->mName;
  return true;
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::ReloadFromStorageAll_XML()
{
  for( int iType = FirstType; iType < CountType; iType++ )
    ReloadFromStorageByType_XML( (TypeGameItem) iType );
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::ReloadFromStorageByType_XML( TypeGameItem type )
{
  int cntItem = mStorageGameItem_XML->GetCountByType( type );
  for( int iItem = 0; iItem < cntItem; iItem++ )
  {
    std::string nameItem;
    if( mStorageGameItem_XML->GetNameByType( type, iItem, nameItem ) == false )
      continue;
    TBaseItem* pItem = FindItemByTypeByName( type, nameItem );
    if( pItem )// если с таким именем уже есть - не создавать
      continue;
    pItem = MakeNewItem( type, nameItem );
    if( pItem == NULL )
      continue;
    if( mStorageGameItem_XML->Load( pItem ) == false )
    {
      delete pItem;
      continue;
    }
    if( AddItemInMap( pItem ) == false )
      delete pItem;
  }
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::Clear()
{
  for( auto& vtType_PtrMap : mMapType_StrName_pItem )
  {
    TMapStrPtrItemIt bit = vtType_PtrMap.second->begin();
    TMapStrPtrItemIt eit = vtType_PtrMap.second->end();
    while( bit != eit )
    {
      delete bit->second;
      bit++;
    }
    vtType_PtrMap.second->clear();
  }
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::FindItemByTypeByName( int type, std::string& name )
{
  TMapStrPtrItem* pMap = FindMap( type );
  if( pMap == NULL )
    return NULL;
  TMapStrPtrItemIt fit = pMap->find( name );
  if( fit == pMap->end() )
    return NULL;
  return fit->second;
}
//-----------------------------------------------------------------------------
bool TFactoryGameItem::AddItemInMap( TBaseItem* pItem )
{
  TMapStrPtrItem* pMap = FindMap( pItem->mType );
  if( pMap == NULL )
  {
    BL_FIX_BUG();
    return false;
  }
  pMap->insert( TMapStrPtrItemVT( pItem->mName, pItem ) );
  return true;
}
//-----------------------------------------------------------------------------
TBaseItem* TFactoryGameItem::MakeNewItem( int type, std::string& name )
{
  TBaseItem* pItem = NULL;
  switch( type )
  {
    case PatternConfig:
      pItem = new TPatternConfigItem( name );
      break;
    case Material:
      pItem = new TMaterialItem( name );
      break;
    case Shape:
      pItem = new TShapeItem( name );
      break;
    case Model:
      pItem = new TModelItem( name );
      break;
    case Map:
      pItem = new TMapItem( name );
      break;
    case Terrain:
      pItem = new TTerrainItem( name );
      break;
    case TableSound:
      pItem = new TTableSoundItem( name );
      break;
  }
  return pItem;
}
//-----------------------------------------------------------------------------
TFactoryGameItem::TMapStrPtrItem* TFactoryGameItem::FindMap( int type )
{
  TMapInt_PtrMapStrPtrIt fit = mMapType_StrName_pItem.find( type );
  if( fit == mMapType_StrName_pItem.end() )
    return NULL;

  return fit->second;
}
//-----------------------------------------------------------------------------
void TFactoryGameItem::MakeStr_Map()
{
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( PatternConfig, &mMapNamePatternConfig ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( Material, &mMapNameMaterial ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( Shape, &mMapNameShape ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( Model, &mMapNameModel ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( Terrain, &mMapNameTerrain ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( Map, &mMapNameMap ) );
  mMapType_StrName_pItem.insert( TMapInt_PtrMapStrPtrVT( TableSound, &mMapNameTableSound ) );
}
//-----------------------------------------------------------------------------
