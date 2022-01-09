/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <vector>
#include <set>

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

        std::set<TSystem*> mSystems;
    public:
        virtual ~TFeature();

        void SetEntMng(TEntityManager* entMng) override final;
        virtual void InitConveyor() {}

        bool IsFeature() const override final;

        bool Add(TSystem* system);
        void Remove(TSystem* system);
        bool Has(TSystem* system) const;

        const std::set<TSystem*>* GetSystems();

        void Clear();

        void Execute() override final;
        void TearDown() override final;
    };
}
