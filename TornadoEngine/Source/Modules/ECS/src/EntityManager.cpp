/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

//#define SHOW_STAT

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

using namespace nsECSFramework;

namespace dll = boost::dll;
namespace bexp = boost::dll::experimental;

// const 
const std::string templateBegin = "<";

const char leftCornerLiteral = '<';
const char rightCornerLiteral = '>';
const char commaLiteral = ',';
const char spaceLiteral = ' ';

const std::string typeIndexMethodName = "TypeIndex";

const std::string getByUniqueMethodName = "GetByUnique";
const std::string getByHasMethodName = "GetByHas";
const std::string getByValueMethodName = "GetByValue";


//----------------------------------------------------------------------------------------------------
TEntityManager::TEntityManager( int entityCount )
{
  mEntities.mVec.resize( entityCount );
  mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();
  mComplexTypeMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexType>>();
  mLinkToListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TLinkToList<TEntityID>>>();
  mEntityListMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntityList>>();
  mUniqueMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TUniqueMap>>();
  mComplexTypePtrListPtrMapMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComplexTypePtrListPtrMap>>();

  mTypeIndex = SingletonManager()->Get<TTypeIdentifier<TEntityManager>>();
}
//----------------------------------------------------------------------------------------------------
TEntityManager::~TEntityManager()
{

}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Fill( const std::string& methodName, std::string& demangled, TStrSet& strSet )
{
  auto beginFound = demangled.find( methodName );

  auto pData = demangled.data();
  auto argsBeginIndex = demangled.find( templateBegin, beginFound );
  auto beginTypesIndex = argsBeginIndex + templateBegin.size();
  auto offset = beginTypesIndex;

  // функция для добавления
  auto addFunc = [&]( int index )
  {
    // конец template
    auto type = demangled.substr( offset, index - offset );
    strSet.insert( type );
    offset = index;
  };

  auto cornerBalance = 0;
  for ( int i = argsBeginIndex; i < demangled.size(); i++ )
  {
    auto symbol = pData[i];
    switch ( symbol )
    {
      case leftCornerLiteral:
        cornerBalance++;
        break;
      case rightCornerLiteral:
        cornerBalance--;
        break;
      case commaLiteral:
        if ( cornerBalance == 1 )
        {
          addFunc( i );
          offset += sizeof( commaLiteral );
          if ( pData[i + 1] == spaceLiteral )
            offset += sizeof( spaceLiteral );
        }
        break;
    }

    if ( cornerBalance == 0 )
    {
      // конец template
      addFunc( i );
      break;
    }
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::FindTypesOfMethod( const std::string& methodName, TStrSetList& resultList )
{
  auto symbolStorage = mLib.symbol_storage().get_storage();
  TStrList classList;
  for ( auto s : symbolStorage )
  {
    auto demangled = s.demangled;
    auto pData = demangled.data();

    auto beginFound = demangled.find( methodName );
    if ( beginFound == std::string::npos )
      continue;

    TStrSet strSet;
    Fill( methodName, demangled, strSet );

    if ( strSet.size() > 0 )
      resultList.push_back( strSet );
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::FindTypeIndex( const std::string& methodName, TStrSetStrMap& resultMap )
{
  auto symbolStorage = mLib.symbol_storage().get_storage();
  TStrList classList;
  for ( auto s : symbolStorage )
  {
    auto demangled = s.demangled;

    auto beginFound = demangled.find( methodName );
    if ( beginFound == std::string::npos )
      continue;

    TStrSet strSet;
    Fill( methodName, demangled, strSet );

    if ( strSet.size() > 0 )
      resultMap.insert( {strSet, demangled} );
  }
}
//----------------------------------------------------------------------------------------------------
// рефлексия (boost::dll), поиск применения функций фильтрации для подготовки к накоплению карт кэширования использования компонентов
// reflection magic
void TEntityManager::Setup( std::string libName )
{
  mLib.load( libName );
  // для разделения пространства имен классов, на случай когда более чем один EntityManager
  auto entMngClassName = typeid( *this ).name();

  FindTypesOfMethod( getByUniqueMethodName, mUniqueSet );
  FindTypesOfMethod( getByHasMethodName, mHasComponentList );
  FindTypesOfMethod( getByValueMethodName, mValueComponentList );

  FindTypeIndex( typeIndexMethodName, mTypeIndexNameFuncMap );

  auto showWarning = mUniqueSet.size() == 0 && mHasComponentList.size() == 0 && mValueComponentList.size() == 0 && mTypeIndexNameFuncMap.size() == 0;
  if ( showWarning )
    printf( "Warning! TEntityManager Setup not found reflection info.\n" );
#ifdef SHOW_STAT
  printf( "uniqueCnt = %u, hasCnt = %u, valueCnt = %u, typeIndexCount = %u\n",
    mUniqueSet.size(), mHasComponentList.size(), mValueComponentList.size(), mTypeIndexNameFuncMap.size() );
#endif

  using TypeIndexFunc = unsigned int( TEntityManager::* )( void );
  try
  {
    for ( auto strSetFunc : mTypeIndexNameFuncMap )
    {
      auto& demangled = strSetFunc.second;

      auto beginFound = demangled.find( typeIndexMethodName );
      if ( beginFound == std::string::npos )
        continue;

      auto endFound = demangled.find( "(" );
      if ( endFound == std::string::npos )
        continue;

      auto funcName = demangled.substr( beginFound, endFound - beginFound );

      auto func = bexp::import_mangled<nsECSFramework::TEntityManager, unsigned int( void )>( mLib, funcName.data() );
      auto typeIndexFunc = func( this );

//      printf( "%s => %u\n", funcName.data(), typeIndexFunc );

      mCompnentsTypeIndexMap.insert( {strSetFunc.first, typeIndexFunc} );
    }
  }
  catch ( std::exception e )
  {
    printf( e.what() );
  }

  for ( auto& strSet : mUniqueSet )
  {
    auto fit = mCompnentsTypeIndexMap.find( strSet );
    if ( fit == mCompnentsTypeIndexMap.end() )
    {
      BL_FIX_BUG();
      continue;
    }
    auto index = fit->second;
    mUniqueMapVec[index] = mUniqueMapMemoryPool->Pop();
  }

  // все типы изо всех коллекций
  TStrSet hasSet;
  TStrSet valueSet;

  for ( auto& strSet : mHasComponentList )
  {
    auto fit = mCompnentsTypeIndexMap.find( strSet );
    if ( fit == mCompnentsTypeIndexMap.end() )
    {
      BL_FIX_BUG();
      continue;
    }
    auto index = fit->second;
    mHasCollectionVec[index] = mEntityListMemoryPool->Pop();

    TShortList typeList;
    for ( auto type : strSet )
    {
      hasSet.insert( type );

      TStrSet forSearch;
      forSearch.insert( type );
      auto typeIndexIt = mCompnentsTypeIndexMap.find( forSearch );
      typeList.push_back( typeIndexIt->second );
    }
    mHasCollectionWithTypes[index] = typeList;
  }

  for ( auto& strSet : mValueComponentList )
  {
    auto fit = mCompnentsTypeIndexMap.find( strSet );
    if ( fit == mCompnentsTypeIndexMap.end() )
    {
      BL_FIX_BUG();
      continue;
    }
    auto index = fit->second;
    mValueCollectionVec[index] = mComplexTypePtrListPtrMapMemoryPool->Pop();

    TShortList typeList;
    for ( auto type : strSet )
    {
      valueSet.insert( type );

      TStrSet forSearch;
      forSearch.insert( type );
      auto typeIndexIt = mCompnentsTypeIndexMap.find( forSearch );
      typeList.push_back( typeIndexIt->second );
    }
    mValueCollectionWithTypes[index] = typeList;
  }

  // выяснить в каких коллекциях учавствует тип
  for ( auto type : hasSet )
  {
    TShortList typeList;
    for ( auto collectionType : mHasComponentList )
    {
      if ( collectionType.find( type ) == collectionType.end() )
        continue;
      auto collectionIndex = mCompnentsTypeIndexMap.find( collectionType );
      typeList.push_back( collectionIndex->second );
    }

    BL_ASSERT( typeList.size() > 0 );

    TStrSet forSearchIndex;
    forSearchIndex.insert( type );
    auto typeIndexIt = mCompnentsTypeIndexMap.find( forSearchIndex );

    mHasTypeInCollection[typeIndexIt->second] = typeList;
  }

  for ( auto type : valueSet )
  {
    TShortList typeList;
    for ( auto collectionType : mValueComponentList )
    {
      if ( collectionType.find( type ) == collectionType.end() )
        continue;
      auto collectionIndex = mCompnentsTypeIndexMap.find( collectionType );
      typeList.push_back( collectionIndex->second );
    }

    BL_ASSERT( typeList.size() > 0 );

    TStrSet forSearchIndex;
    forSearchIndex.insert( type );
    auto typeIndexIt = mCompnentsTypeIndexMap.find( forSearchIndex );

    mValueTypeInCollection[typeIndexIt->second] = typeList;
  }
}
//-------------------------------------------------------------------------------------------------------
TEntityID TEntityManager::CreateEntity()
{
  auto id = (TEntityID)mEntities.mCounter;

  auto newEntity = mEntityMemoryPool->Pop();
  if ( mReserverIndexInEntities.size() > 0 )
  {
    id = mReserverIndexInEntities.back();
    mReserverIndexInEntities.pop_back();
    mEntities.mVec[id] = newEntity;
  }
  else
    mEntities.Append( newEntity );
  return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( TEntityID eid )
{
  auto pEntity = GetEntity( eid );
  if ( pEntity == nullptr )
  {
    BL_FIX_BUG();
    return;
  }

  auto index = pEntity->GetFirstComponentIndex();
  while ( index != TEntity::NoneIndex )
  {
    RemoveComponent( eid, pEntity, index );
    index = pEntity->GetFirstComponentIndex();
  }

  mEntityMemoryPool->Push( pEntity );

  mReserverIndexInEntities.push_back( eid );
  mEntities.mVec[eid] = nullptr;
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity( TEntityID id ) const
{
  return mEntities.mVec[id];
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::RemoveComponent( TEntityID eid, TEntity* pEntity, int index )
{
  auto pC = (IComponent*)pEntity->GetComponent( index );

  TryRemoveFromUnique( eid, pC, index );
  TryRemoveFromHas( eid, index, pEntity );
  TryRemoveFromValue( eid, index, pEntity );

  pEntity->RemoveComponent( index );
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInUnique( TEntityID eid, IComponent* pC, int index )
{
  auto pMap = mUniqueMapVec[index];
  if ( pMap == nullptr )
    return;
#ifdef _DEBUG
  if ( pMap->end() != pMap->find( pC ) )
  {
    BL_FIX_BUG();
    return;
  }
#endif
  pMap->insert( {pC, eid} );

}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInHas( TEntityID eid, int index, TEntity* pEntity )
{
  auto& collectionList = mHasTypeInCollection[index];
  for ( auto& collectionIndex : collectionList )
  {
    auto hasList = mHasCollectionVec[collectionIndex];
    if ( hasList == nullptr )
    {
      BL_FIX_BUG();
      continue;
    }

    auto hasAllTypes = true;
    auto& typesInCollection = mHasCollectionWithTypes[collectionIndex];
    for ( auto& typeInCollection : typesInCollection )
    {
      if ( pEntity->HasComponent( typeInCollection ) == false )
      {
        hasAllTypes = false;
        break;
      }
    }

    if ( hasAllTypes == false )
      continue;
    hasList->push_front( eid );
    auto frontIt = hasList->begin();

    auto pLTL = mLinkToListMemoryPool->Pop();
    pLTL->Set( *hasList, frontIt );
    pEntity->AddHasCollectionInfo( pLTL, collectionIndex );
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryAddInValue( TEntityID eid, int index, TEntity* pEntity )
{
  auto& collectionList = mValueTypeInCollection[index];
  for ( auto& collectionIndex : collectionList )
  {
    auto ctListMap = mValueCollectionVec[collectionIndex];
    if ( ctListMap == nullptr )
    {
      BL_FIX_BUG();
      continue;
    }

    auto hasAllTypes = true;
    auto pComplexType = mComplexTypeMemoryPool->Pop();

    auto& typesInCollection = mValueCollectionWithTypes[collectionIndex];
    for ( auto& typeInCollection : typesInCollection )
    {
      auto pC = pEntity->GetComponent( typeInCollection );
      if ( pC == nullptr )
      {
        hasAllTypes = false;
        break;
      }
      pComplexType->parts[typeInCollection] = pC;
      pComplexType->mComponentTypeIdentifierList.push_back( typeInCollection );
    }

    if ( hasAllTypes == false )
    {
      pComplexType->Done();
      mComplexTypeMemoryPool->Push( pComplexType );
      continue;
    }

    TEntityList* pList = nullptr;
    auto fit = ctListMap->find( pComplexType );
    if ( fit == ctListMap->end() )
    {
      pList = mEntityListMemoryPool->Pop();
      pList->push_front( eid );// original
      ctListMap->insert( {pComplexType, pList} );
    }
    else
    {
      pComplexType->Done();
      mComplexTypeMemoryPool->Push( pComplexType );

      pList = fit->second;
      pList->push_front( eid );
    }

    auto frontIt = pList->begin();

    auto pLTL = mLinkToListMemoryPool->Pop();
    pLTL->Set( *pList, frontIt );
    pEntity->AddValueCollectionInfo( pLTL, collectionIndex );
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromUnique( TEntityID eid, IComponent* pC, int index )
{
  auto pMap = mUniqueMapVec[index];
  if ( pMap == nullptr )
    return;
#ifdef _DEBUG
  if ( pMap->end() == pMap->find( pC ) )
  {
    BL_FIX_BUG();
    return;
  }
#endif
  pMap->erase( pC );
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromHas( TEntityID eid, int index, TEntity* pEntity )
{
  auto& collectionList = mHasTypeInCollection[index];
  for ( auto& collectionIndex : collectionList )
  {
    auto& hasList = mHasCollectionVec[collectionIndex];
    if ( hasList == nullptr )
    {
      BL_FIX_BUG();
      continue;
    }

    auto pLTL = pEntity->RemoveHasCollectionInfo( collectionIndex );
    if ( pLTL == nullptr )
      continue;
    pLTL->Erase();
    mLinkToListMemoryPool->Push( pLTL );
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::TryRemoveFromValue( TEntityID eid, int index, TEntity* pEntity )
{
  auto& collectionList = mValueTypeInCollection[index];
  for ( auto& collectionIndex : collectionList )
  {
    auto pLTL = pEntity->RemoveValueCollectionInfo( collectionIndex );
    if ( pLTL == nullptr )
      continue;
    auto ctListMap = mValueCollectionVec[collectionIndex];
    if ( ctListMap == nullptr )
    {
      BL_FIX_BUG();
      continue;
    }
    // найти удаляется ли оригинал (back()) из листа, если оригинал, то занести следующий из списка
    auto pList = pLTL->GetList();
    auto isBackEntity = ( pList->back() == eid );
    pLTL->Erase();
    mLinkToListMemoryPool->Push( pLTL );

    if ( isBackEntity == false )
      continue;
    auto& typesInCollection = mValueCollectionWithTypes[collectionIndex];
    auto pComplexType = mComplexTypeMemoryPool->Pop();// сформировать для поиска в map
    for ( auto& typeInCollection : typesInCollection )
    {
      auto pC = pEntity->GetComponent( typeInCollection );
      if ( pC == nullptr )
      {
        BL_FIX_BUG();
        break;
      }
      pComplexType->parts[typeInCollection] = pC;
      pComplexType->mComponentTypeIdentifierList.push_back( typeInCollection );
    }
    auto fit = ctListMap->find( pComplexType );
    if ( fit == ctListMap->end() )
    {
      BL_FIX_BUG();
      continue;
    }
    auto pOriginalComplexType = fit->first;
    pComplexType->Done();
    mComplexTypeMemoryPool->Push( pComplexType );
    pOriginalComplexType->Done();
    ctListMap->erase( fit );
    if ( pList->size() == 0 )// удаляется оригинал
    {
      mEntityListMemoryPool->Push( pList );
      mComplexTypeMemoryPool->Push( pOriginalComplexType );
      continue;
    }

    // pList->size() > 0
    auto nextEid = pList->back();
    auto pNextEntity = GetEntity( nextEid );

    for ( auto& typeInCollection : typesInCollection )
    {
      auto pC = pNextEntity->GetComponent( typeInCollection );
      if ( pC == nullptr )
      {
        BL_FIX_BUG();
        break;
      }
      pOriginalComplexType->parts[typeInCollection] = pC;
      pOriginalComplexType->mComponentTypeIdentifierList.push_back( typeInCollection );
    }
    ctListMap->insert( {pOriginalComplexType, pList} );
  }
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::NotifyOnRemoveComponent( int index, TEntityID entity, IComponent* pC )
{
  auto pCB = mRemoveCBVector.Begin() + index;
  if ( pCB[0] == nullptr )
    return;
  pCB[0]->Notify( entity, pC );
}
//---------------------------------------------------------------------------------------
