#pragma once
#include "TypeDef.h"
#include "BL_Debug.h"

// работает только дл€ Ќ≈»«ћ≈Ќя≈ћџ’ компонентов!!! без replace, get, each
// значени€ компонента в течение срока жизни entity должны оставатьс€ ѕќ—“ќяЌЌџћ»
// MappedGroup создавать до создани€ всех entity в System::Init()
template<typename Component, bool map_or_multimap>
class DllExport TBaseMappedGroup
{
  struct TConnectionCounter// гарантированно уникальный синглтон
  {
    int value;
  };
protected:
  typedef std::unordered_map<Component, nsECSFramework::TEntity> TComponentEntityMap;
  typename typedef TComponentEntityMap::value_type TComponentEntityMapVT;

  typedef std::unordered_multimap<Component, nsECSFramework::TEntity> TComponentEntityMMap;
  typename typedef TComponentEntityMMap::value_type TComponentEntityMMapVT;

  struct IMap
  {
  };
  struct TMap : public IMap
  {
    TComponentEntityMap value;
  };
  struct TMMap : public IMap
  {
    TComponentEntityMMap value;
  };

  static inline TConnectionCounter* g_ConnectionCounter = nullptr;
protected:
  static inline IMap* g_CompEntityMap = nullptr;
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
    if( g_ConnectionCounter == nullptr )
      g_ConnectionCounter = SingletonManager()->Get<TConnectionCounter>();
    if( g_CompEntityMap == nullptr )
    {
      if( map_or_multimap )
        g_CompEntityMap = SingletonManager()->Get<TMap>();
      else
        g_CompEntityMap = SingletonManager()->Get<TMMap>();
    }

    if( g_ConnectionCounter->value > 0 )
      return;

    g_ConnectionCounter->value++;

    // садитс€ на событи€ компонента
    nsECSFramework::THugeRegistry::sink_type constrSig = registry->construction<Component>();
    constrSig.connect<TBaseMappedGroup, &TBaseMappedGroup::Add>( this );
    // садитс€ на событи€ компонента
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
    if( map_or_multimap )
      Map()->value.insert( TComponentEntityMap::value_type( registry.get<Component>( entity ), entity ) );
    else
      MMap()->value.insert( TComponentEntityMap::value_type( registry.get<Component>( entity ), entity ) );
  }
  inline void Remove( nsECSFramework::THugeRegistry& registry, const nsECSFramework::TEntity entity )
  {
    if( map_or_multimap )
      Map()->value.erase( registry.get<Component>( entity ) );
    else
      MMap()->value.erase( registry.get<Component>( entity ) );
  }
};

template<typename Component>
class DllExport TMappedSingleEntityGroup :
  public TBaseMappedGroup<Component, true>
{
public:
  TMappedSingleEntityGroup( nsECSFramework::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, true>( registry )
  {}
  inline nsECSFramework::TEntity Get( Component& c )
  {
    auto fit = TBaseMappedGroup<Component, true>::Map()->value.find( c );
    if( fit == TBaseMappedGroup<Component, true>::Map()->value.end() )
      return entt::null;
    return fit->second;
  }
};

template<typename Component>
class DllExport TMappedMultiEntityGroup :
  public TBaseMappedGroup<Component, false>
{
public:
  TMappedMultiEntityGroup( nsECSFramework::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, false>( registry )
  {}
  inline void Get( Component& c, std::list<nsECSFramework::TEntity>& entList )
  {
    auto range = TBaseMappedGroup<Component, false>::MMap()->value.equal_range( c );
    for( auto it = range.first; it != range.second; ++it )
      entList.push_back( it->second );
  }
};