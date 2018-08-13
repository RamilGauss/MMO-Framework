#pragma once
#include <vector>
#include <entt/entt.hpp>

#include "System.h"
#include "VectorRise.h"
#include "ConnectTypeManager.h"
#include "SortedThinningRestoreOrder.h"
#include "SingletonManager.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TBaseReactiveSystem : public TSystem
    {
      bool mMoreThanOneEvent;
      int mEventCounter = 0;
      void IncrementAndCheckEventCount();
      void AddConnectTypeManager( IConnectTypeManager* p );
    protected:
      TSortedThinningRestoreOrder<TEntity> mSTRO;
      std::vector<IConnectTypeManager*> mConTypeMngPtrVec;
    public:
      TBaseReactiveSystem( bool moreThanOneEvent );
      virtual bool Filter( TEntity& entity ) = 0;
      virtual void Reactive( std::vector<TEntity>& entities, size_t count ) = 0;
    protected:
      // Additional events
      template<typename Component>
      void Add()
      {
        Connect<Component, true>();
      }
      template<typename C0, typename C1, typename ... Components>
      void Add()
      {
        Add<C0>();
        Add<C1, Components ... >();
      }

      // Subtraction events
      template<typename Component>
      void Sub()
      {
        Connect<Component, false>();
      }
      template<typename C0, typename C1, typename ... Components>
      void Sub()
      {
        Sub<C0>();
        Sub<C1, Components ... >();
      }

      template<typename Component, bool add_or_sub>
      void Connect();
      void Filter( TVectorRise<TEntity> *pEntities );
    };
    //-----------------------------------------------------------------------------
    template<typename Component, bool add_or_sub>
    void TBaseReactiveSystem::Connect()
    {
      auto pConTypeMng = SingletonManager()->Get<TConnectTypeManager<Component, add_or_sub>>();

      pConTypeMng->SetRegistry( GetRegistry() );
      pConTypeMng->Connect( this );

      AddConnectTypeManager( pConTypeMng );

      IncrementAndCheckEventCount();
    }
    //-----------------------------------------------------------------------------
  }
}