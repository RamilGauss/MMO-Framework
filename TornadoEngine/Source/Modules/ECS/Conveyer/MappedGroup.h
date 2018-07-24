#pragma once
#include "TypeDef.h"

// работает только для НЕИЗМЕНЯЕМЫХ компонентов!!! без replace, get, each
// значения компонента в течение срока жизни entity должны оставаться ПОСТОЯННЫМИ
// MappedGroup создавать до создания всех entity в System::Init()
template<typename Component, typename TComponentEntityMap>
class DllExport TBaseMappedGroup
{
protected:
  static inline TComponentEntityMap* g_CompEntityMap = nullptr;
  static inline int g_ConnectionCounter = 0;
public:
  TBaseMappedGroup( MWorks::ECS::THugeRegistry* registry )
  {
    if( g_ConnectionCounter > 0 )
      return;

    if( g_CompEntityMap == nullptr )
      g_CompEntityMap = new TComponentEntityMap();

    g_ConnectionCounter++;

    // садится на события компонента
    MWorks::ECS::THugeRegistry::sink_type constrSig = registry->construction<Component>();
    constrSig.connect<TBaseMappedGroup, &TBaseMappedGroup::Add>( this );
    // садится на события компонента
    MWorks::ECS::THugeRegistry::sink_type destrSig = registry->destruction<Component>();
    destrSig.connect<TBaseMappedGroup, &TBaseMappedGroup::Remove>( this );
  }

  virtual ~TBaseMappedGroup()
  {
    g_ConnectionCounter--;
    if( g_ConnectionCounter == 0 )
    {
      delete g_CompEntityMap;
      g_CompEntityMap = nullptr;
    }
  }
private:
  inline void Add( MWorks::ECS::THugeRegistry& registry, const MWorks::ECS::TEntity entity )
  {
    g_CompEntityMap->insert( TComponentEntityMap::value_type( registry.get<Component>( entity ), entity ) );
  }
  inline void Remove( MWorks::ECS::THugeRegistry& registry, const MWorks::ECS::TEntity entity )
  {
    g_CompEntityMap->erase( registry.get<Component>( entity ) );
  }
};

template<typename Component>
class DllExport TMappedSingleEntityGroup : 
  public TBaseMappedGroup<Component, std::unordered_map<Component, MWorks::ECS::TEntity> >
{
public:
  TMappedSingleEntityGroup( MWorks::ECS::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, std::unordered_map<Component, MWorks::ECS::TEntity> >( registry )  {}
  inline MWorks::ECS::TEntity Get( Component& c )
  {
    auto fit = TBaseMappedGroup<Component, std::unordered_map<Component, MWorks::ECS::TEntity> >::g_CompEntityMap->find( c );
    if( TBaseMappedGroup<Component, std::unordered_map<Component, MWorks::ECS::TEntity> >::g_CompEntityMap->end() == fit )
      return entt::null;
    return fit->second;
  }
};

template<typename Component>
class DllExport TMappedMultiEntityGroup : 
  public TBaseMappedGroup<Component, std::unordered_multimap<Component, MWorks::ECS::TEntity> >
{
public:
  TMappedMultiEntityGroup( MWorks::ECS::THugeRegistry* registry ) :
    TBaseMappedGroup<Component, std::unordered_multimap<Component, MWorks::ECS::TEntity> >( registry )  {}
  inline void Get( Component& c, std::list<MWorks::ECS::TEntity>& entList )
  {
    auto range = TBaseMappedGroup<Component, std::unordered_multimap<Component, MWorks::ECS::TEntity> >::g_CompEntityMap->equal_range( c );
    for( auto it = range.first; it != range.second; ++it )
      entList.push_back( it->second );
  }
};