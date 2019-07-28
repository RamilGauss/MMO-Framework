/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

using namespace nsECSFramework;

namespace dll = boost::dll;

const std::string typeIndex = "TypeIndex";
const std::string templateBegin = "<";
const std::string templateEnd = ">";
const std::string methodName = "GetByValue";// "GetByHas"
const std::string classBegin = methodName + templateBegin;
const std::string classLiteral = "class";

TEntityManager::TEntityManager( int entityCount )
{
  mEntities.mVec.resize( entityCount );
  mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();

  mTypeIndex = SingletonManager()->Get<TTypeIdentifier<TEntityManager>>();
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Setup( std::string libName )
{
  // для разделения пространства имен классов, на случай когда более чем один EntityManager
  auto className = typeid( *this ).name();

  dll::experimental::smart_library lib( libName );

  auto symbolStorage = lib.symbol_storage().get_storage();
  std::list<std::string> classList;
  std::list<std::string> funcList;
  for ( auto s : symbolStorage )
  {
    auto demangled = s.demangled;
    auto beginFound = demangled.find( classBegin );
    if ( beginFound == std::string::npos )
      continue;
    auto endFound = demangled.find( templateEnd );
    std::string className = demangled.data() + beginFound + classBegin.size();
    className = className.substr( 0, endFound - beginFound - classBegin.size() );

    classList.push_back( className );
  }
  for ( auto s : symbolStorage )
  {
    auto demangled = s.demangled;
    auto typeIndexFound = demangled.find( typeIndex );
    if ( typeIndexFound == std::string::npos )
      continue;
    for ( auto className : classList )
    {
      auto classNameFound = demangled.find( templateBegin + className + templateEnd );
      if ( classNameFound == std::string::npos )
        continue;
      printf( "%s : TypeIndex = %s\n", className.data(), demangled.data() );
      funcList.push_back( s.demangled );
    }
  }

  typedef std::map <std::string, unsigned int> TStrUIntMap;
  TStrUIntMap funcMap;
  try
  {
    using TypeIndexFunc = unsigned int( TEntityManager::* )( void );

    for ( auto funcName : funcList )
    {
      auto func = lib.get_function<unsigned int( void )>( funcName.data() );
      auto pFunc = ( TypeIndexFunc*) & func;
      auto tiFunc = std::bind( *pFunc, this );
      auto typeIndexFunc = tiFunc();

      funcMap.insert( { funcName , typeIndexFunc } );
    }
  }
  catch ( std::exception e )
  {
    printf( e.what() );
  }

  // 1. парсинг <class A, class B, class C, ...>
  // 2. Разбор кто в каких комбинациях встречается
  // => A ->{A,B,C}
  // => B ->{A,B,C}
  // => C ->{A,B,C}
}
//-------------------------------------------------------------------------------------------------------
TEntityID TEntityManager::CreateEntity()
{
  const TEntityID id = ( const TEntityID) mEntities.mCounter;

  auto newEntity = mEntityMemoryPool->Pop();
  if ( mReserverIndexInEntities.size() > 0 )
  {
    auto entityIndex = mReserverIndexInEntities.back();
    mReserverIndexInEntities.pop_back();
    mEntities.mVec[entityIndex] = newEntity;
  }
  else
    mEntities.Append( newEntity );
  return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( TEntityID id )
{
  auto pEntity = mEntities.mVec[id];

  pEntity->Done();
  mEntityMemoryPool->Push( pEntity );

  mReserverIndexInEntities.push_back( id );
  mEntities.mVec[id] = nullptr;
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity( TEntityID id ) const
{
  return mEntities.mVec[id];
}
//----------------------------------------------------------------------------------------------------
