/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ConveyerPartWithGlobalAccess.h"
#include "GlobalSystemInitializer.h"
#include "BaseReactiveSystem.h"
#include "IConveyerPart.h"
#include "GlobalSystemUpdater.h"

namespace nsECSFramework
{
    class TInitSystem;
    class TExecuteSystem;
    class TFeature;

    class DllExport TConveyerPartMaster : public TConveyerPartWithGlobalAccess
    {
    protected:
        TGlobalSystemInitializer<TBaseReactiveSystem>* mReactiveInitializer = nullptr;// реактивные системы
        TGlobalSystemInitializer<IConveyerPart>* mInitAndExecuteInitializer = nullptr;

        TGlobalSystemUpdater* mSystemUpdater = nullptr;

    public:
        template<typename T, typename ... Args>
        void AddToConveyer(Args && ... args);

        virtual void Init() final;
        virtual void Update() final;
    private:
        template<typename T>
        bool IsTypeInit()
        {
            return std::is_base_of<TInitSystem, T>::value;
        }
        template<typename T>
        bool IsTypeReactive()
        {
            return std::is_base_of<TBaseReactiveSystem, T>::value;
        }
        template<typename T>
        bool IsTypeExecute()
        {
            return std::is_base_of<TExecuteSystem, T>::value;
        }
        template<typename T>
        bool IsTypeFeature()
        {
            return std::is_base_of<TFeature, T>::value;
        }
    };
    //---------------------------------------------------------------------------------------
    template<typename T, typename ... Args>
    void TConveyerPartMaster::AddToConveyer(Args && ... args)
    {
        mReactiveInitializer = SingletonManager()->Get<TGlobalSystemInitializer<TBaseReactiveSystem>>();
        mInitAndExecuteInitializer = SingletonManager()->Get<TGlobalSystemInitializer<IConveyerPart>>();
        mSystemUpdater = SingletonManager()->Get<TGlobalSystemUpdater>();

        auto registry = GetEntityManager();
        auto t = new T(std::forward<Args>(args)...);
        t->SetEntityManager(registry);

        // списки для инициализации
        if (IsTypeReactive<T>()) {
            mReactiveInitializer->Add(t);// реактивные системы
        } else
            if (IsTypeFeature<T>() == false)
                mInitAndExecuteInitializer->Add(t);// execute и обычные init системы

        if (IsTypeFeature<T>()) {
            t->PrepareFeature();// итеративно продолжить дальше
        } else {
            // если чистый InitSystem, то Update не вызовется
            if (IsTypeExecute<T>() || IsTypeReactive<T>()) {
                mSystemUpdater->Add(t);
            }
        }
#ifdef _DEBUG
        if (IsTypeInit<T>()) {
            assert(!IsTypeExecute<T>() && !IsTypeReactive<T>());
        }
#endif
    }
}
