/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "TypeDef.h"
#include "BL_Debug.h"

// работает только для НЕИЗМЕНЯЕМЫХ компонентов!!! без replace, get, each
// значения компонента в течение срока жизни entity должны оставаться ПОСТОЯННЫМИ
// MappedGroup создавать до создания всех entity в System::Init()
template<typename Component, bool map_or_multimap>
class DllExport TBaseMappedGroup
{
  struct TConnectionCounter// гарантированно уникальный синглтон
  {
    int value;
  };
protected:
  typedef std::unordered_map<Component, nsECSFramework::TEntity> TComponentEntityMap;
  typedef std::unordered_multimap<Component, nsECSFramework::TEntity> TComponentEntityMMap;

  struct IMap
  {
  };
protected:
  struct TMap : public IMap
  {
    TComponentEntityMap value;
  };
  struct TMMap : public IMap
  {
    TComponentEntityMMap value;
  };

  static TConnectionCounter* g_ConnectionCounter;
protected:
  static IMap* g_CompEntityMap;
  static TMap* Map()
  {
    return (TMap*) g_CompEntityMap;
  }
  static TMMap* MMap()
  {
    return (TMMap*) g_CompEntityMap;
  }
public:
  TBaseMappedGroup( nsECSFramework::THugeRegistry* registry )
  {
    if ( g_ConnectionCounter == nullptr )
      g_ConnectionCounter = SingletonManager()->Get<TConnectionCounter>();
    if ( g_CompEntityMap == nullptr )
    {
      if ( map_or_multimap )
        g_CompEntityMap = SingletonManager()->Get<TMap>();
      else
        g_CompEntityMap = SingletonManager()->Get<TMMap>();
    }

    if ( g_ConnectionCounter->value > 0 )
      return;

    g_ConnectionCounter->value++;

    // садится на события компонента
    nsECSFramework::THugeRegistry::sink_type constrSig = registry->construction<Component>();
    constrSig.connect<TBaseMappedGroup, &TBaseMappedGroup::Add>( this );
    // садится на события компонента
    nsECSFramework::THugeRegistry::sink_type destrSig = registry->destruction<Component>();
    destrSig.connect<TBaseMappedGroup, &TBaseMappedGroup::Remove>( this );
  }

  virtual ~TBaseMappedGroup()
  {
    g_ConnectionCounter->value--;
    BL_ASSERT( g_ConnectionCounter->value >= 0 );
  }
private:
  inline void Add( nsECSFramework::THugeRegistry& registry, const nsECSFramework::TEntity entity )
  {
    if ( map_or_multimap )
      Map()->value.insert( {registry.get<Component>( entity ), entity} );
    else
      MMap()->value.insert( {registry.get<Component>( entity ), entity} );
  }
  inline void Remove( nsECSFramework::THugeRegistry& registry, const nsECSFramework::TEntity entity )
  {
    if ( map_or_multimap )
      Map()->value.erase( registry.get<Component>( entity ) );
    else
      MMap()->value.erase( registry.get<Component>( entity ) );
  }
};
//---------------------------------------------------------------------------------------------------------------------------------------------
template<typename Component, bool map_or_multimap>
typename TBaseMappedGroup<Component, map_or_multimap>::TConnectionCounter* TBaseMappedGroup<Component, map_or_multimap>::g_ConnectionCounter = nullptr;
//---------------------------------------------------------------------------------------------------------------------------------------------
template<typename Component, bool map_or_multimap>
typename TBaseMappedGroup<Component, map_or_multimap>::IMap* TBaseMappedGroup<Component, map_or_multimap>::g_CompEntityMap = nullptr;
//---------------------------------------------------------------------------------------------------------------------------------------------
template<typename Component>
class DllExport TMappedSingleEntityGroup :
  public TBaseMappedGroup<Component, true>
{
public:
  TMappedSingleEntityGroup( nsECSFramework::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, true>( registry )
  {
  }
  inline nsECSFramework::TEntity Get( Component& c )
  {
    auto fit = TBaseMappedGroup<Component, true>::Map()->value.find( c );
    if ( fit == TBaseMappedGroup<Component, true>::Map()->value.end() )
      return entt::null;
    return fit->second;
  }
};
//---------------------------------------------------------------------------------------------------------------------------------------------
template<typename Component>
class DllExport TMappedMultiEntityGroup :
  public TBaseMappedGroup<Component, false>
{
public:
  TMappedMultiEntityGroup( nsECSFramework::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, false>( registry )
  {
  }
  inline void Get( Component& c, std::list<nsECSFramework::TEntity>& entList )
  {
    auto range = TBaseMappedGroup<Component, false>::MMap()->value.equal_range( c );
    for ( auto it = range.first; it != range.second; ++it )
      entList.push_back( it->second );
  }
};
//---------------------------------------------------------------------------------------------------------------------------------------------
