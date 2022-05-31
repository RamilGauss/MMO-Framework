/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <vector>

#include "InitSystem.h"
#include "TearDownSystem.h"
#include "ExecuteSystem.h"

namespace nsECSFramework
{
    class DllExport TFeature : public TExecuteSystem, public TTearDownSystem
    {
    protected:
        std::list<TInitSystem*> mInitSystems;
        std::list<TExecuteSystem*> mExecuteSystems;

        std::list<TSystem*> mSystems;
    public:
        virtual ~TFeature();

        void SetEntMng(TEntityManager* entMng) override final;
        virtual void InitConveyor() {}

        bool IsFeature() const override final;

        template <typename T>
        bool Add(T* system) { return AddSystem(dynamic_cast<TSystem*>(system)); }

        template <typename T>
        void Remove(T* system) { RemoveSystem(dynamic_cast<TSystem*>(system)); }

        template <typename T>
        bool Has(T* system) const { return HasSystem(dynamic_cast<TSystem*>(system)); }


        const std::list<TSystem*>& GetSystems() const;

        void Clear();

        void Execute() override final;
        void TearDown() override final;

    private:
        bool AddSystem(TSystem* system);
        void RemoveSystem(TSystem* system);
        bool HasSystem(TSystem* system) const;
    };
}
