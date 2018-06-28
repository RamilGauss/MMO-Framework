#pragma once
#include <entt/entt.hpp>

#include "System.h"
#include "VectorRise.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TBaseReactiveSystem : public TSystem
    {
      bool mMoreThanOneEvent;
      int mEventCounter = 0;
      void IncrementAndCheckEventCount()
      {
        mEventCounter++;
        if (mMoreThanOneEvent == false)
        {
          assert(mEventCounter == 1);
        }
      }
    public:
      TBaseReactiveSystem(bool moreThanOneEvent) { mMoreThanOneEvent = moreThanOneEvent; }
      virtual bool Filter(TEntity& entity) = 0;
      virtual void Reactive(std::vector<TEntity>& entities, size_t count) = 0;
    protected:
      virtual void Reaction(THugeRegistry& registry, const TEntity entity) = 0;

      void Connect(THugeRegistry::sink_type& sig)
      {
        sig.connect<TBaseReactiveSystem, &TBaseReactiveSystem::Reaction>(this);
      }

      // Additional events
      template<typename Component>
      void Add()
      {
        THugeRegistry::sink_type sig = GetRegistry()->construction<Component>();
        Connect(sig);
        IncrementAndCheckEventCount();
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
        THugeRegistry::sink_type sig = GetRegistry()->destruction<Component>();
        Connect(sig);
        IncrementAndCheckEventCount();
      }
      template<typename C0, typename C1, typename ... Components>
      void Sub()
      {
        Sub<C0>();
        Sub<C1, Components ... >();
      }
    };
  }
}