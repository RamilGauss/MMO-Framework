/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "FeatureManager.h"
#include "IModule.h"

namespace nsTornadoEngine
{
    class DllExport TLogicWrapperModule : public IModule
    {
        std::list<nsECSFramework::TBaseReactiveSystem*> mInstantReactiveSystems;
        std::list<nsECSFramework::TBaseCollectReactiveSystem*> mCollectReactiveSystems;

    protected:
        TFeatureManager mBeginLogicSlotManager;
        TFeatureManager mEndLogicSlotManager;

        double mLastExecutionTime = 0;

    public:
        TFeatureManager* GetBeginLogicSlotManager();
        TFeatureManager* GetEndLogicSlotManager();

        double GetLastExecutionTime() const;

        bool StartEvent() override final;
        void Work() override final;
    protected:
        virtual void ModuleWork() = 0;
        virtual bool ModuleStartEvent() = 0;

    private:
        void BlockBeginReactives();
        void UnblockBeginReactives();
        void ClearBeginReactives();
    };
}