/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <map>

#include "VectorRise.h"

namespace nsECSFramework
{
  class IConnectTypeManager
  {
  public:
    // after has been used have to call entities->Clear()
    virtual TVectorRise<TEntity>* GetEntities( void* pReactiveSystem ) = 0;
  };
  //-------------------------------------------------------------------------------------------------------
  template<typename Component, bool add_or_sub = true>
  class TConnectTypeManager : public IConnectTypeManager
  {
    //THugeRegistry* mRegistry = nullptr;

    typedef TVectorRise<TEntity> TVecEnt;

    typedef std::map<void*, TVecEnt*> TPtrVecEntMap;
    TPtrVecEntMap mReacSys_EntMap;

    bool mFlgConnected = false;
  public:
    //void SetRegistry( THugeRegistry* registry );
    void Connect( void* pReactiveSystem );
    // after has been used have to call entities->Clear()
    //TVectorRise<TEntity>* GetEntities( void* pReactiveSystem ) override;
  private:
    //void Connect( THugeRegistry::sink_type& sig );
    //void Reaction( THugeRegistry& registry, const TEntity entity );
  };
  //-------------------------------------------------------------------------------------------------------
  /*template<typename Component, bool add_or_sub >
  void TConnectTypeManager<Component, add_or_sub>::SetRegistry( THugeRegistry* registry )
  {
    mRegistry = registry;
  }*/
  //-------------------------------------------------------------------------------------------------------
  template<typename Component, bool add_or_sub >
  void TConnectTypeManager<Component, add_or_sub>::Connect( void* pReactiveSystem )
  {
    mReacSys_EntMap.insert( TPtrVecEntMap::value_type( pReactiveSystem, new TVecEnt() ) );
    if ( mFlgConnected )
      return;
    if ( add_or_sub )
    {
      //THugeRegistry::sink_type sig = mRegistry->construction<Component>();
      //Connect( sig );
    }
    else
    {
      //THugeRegistry::sink_type sig = mRegistry->destruction<Component>();
      //Connect( sig );
    }

    mFlgConnected = true;
  }
  //-------------------------------------------------------------------------------------------------------
  //template<typename Component, bool add_or_sub >
  //TVectorRise<TEntity>* TConnectTypeManager<Component, add_or_sub>::GetEntities( void* pReactiveSystem )
  //{
  //  return mReacSys_EntMap [pReactiveSystem];
  //};
  ////-------------------------------------------------------------------------------------------------------
  //template<typename Component, bool add_or_sub >
  //void TConnectTypeManager<Component, add_or_sub>::Connect( THugeRegistry::sink_type& sig )
  //{
  //  sig.connect<TConnectTypeManager<Component, add_or_sub>, &TConnectTypeManager<Component, add_or_sub>::Reaction>( this );
  //}
  ////-------------------------------------------------------------------------------------------------------
  //template<typename Component, bool add_or_sub >
  //void TConnectTypeManager<Component, add_or_sub>::Reaction( THugeRegistry& registry, const TEntity entity )
  //{
  //  for ( auto reactSys_Ent : mReacSys_EntMap )
  //  {
  //    auto entities = reactSys_Ent.second;
  //    entities->Append( entity );
  //  }
  //}
  ////-------------------------------------------------------------------------------------------------------
}
