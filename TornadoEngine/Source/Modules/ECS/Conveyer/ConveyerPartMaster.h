#pragma once
#include "ConveyerPartWithGlobalAccess.h"


namespace MWorks
{
  namespace ECS
  {
    class TInitSystem;
    class TBaseReactiveSystem;
    class TExecuteSystem;
    class TFeature;

    class DllExport TConveyerPartMaster : public TConveyerPartWithGlobalAccess
    {
    protected:
      std::vector<IConveyerPart*> mInitVector;
      std::vector<IConveyerPart*> mUpdateVector;
    public:
      template<typename T>
      void AddToConveyer()
      {
        auto registry = GetRegistry();
        auto t = new T();
        t->SetRegistry(registry);

        mInitVector.push_back(t);// Init вызовется всегда
        if (IsTypeFeature<T>())
        {
          mUpdateVector.push_back(t);
          t->PrepareFeature();
        }
        else
        {
          // если чистый InitSystem, то Update не вызовется
          if (IsTypeExecute<T>() || IsTypeReactive<T>())
            mUpdateVector.push_back(t);
        }
#ifdef _DEBUG
        if (IsTypeInit<T>())
          assert(!IsTypeExecute<T>() && !IsTypeReactive<T>());
#endif
      }

      virtual void Init() final;
      virtual void Update() final;
    private:
      template<typename T>
      bool IsTypeInit() { return std::is_base_of<TInitSystem, T>::value; }
      template<typename T>
      bool IsTypeReactive() { return std::is_base_of<TBaseReactiveSystem, T>::value; }
      template<typename T>
      bool IsTypeExecute() { return std::is_base_of<TExecuteSystem, T>::value; }
      template<typename T>
      bool IsTypeFeature() { return std::is_base_of<TFeature, T>::value; }
    };
  }
}