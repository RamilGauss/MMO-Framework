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
    class DllExport TFeature : public TExecuteSystem
    {
    protected:
        std::list<TInitSystem*> mInitSystems;
        std::list<TExecuteSystem*> mExecuteSystems;
        std::list<TTearDownSystem*> mTearDownSystems;

        std::set<TSystem*> mSystems;
    public:
        bool Add(TSystem* system);
        void Remove(TSystem* system);
        const std::set<TSystem*>* GetSystems();

        void Execute() override final;
    };
}
