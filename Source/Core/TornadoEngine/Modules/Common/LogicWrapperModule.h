/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IModule.h"
#include "FeatureManager.h"
#include "DstEvent.h"

namespace nsTornadoEngine
{
    class DllExport TLogicWrapperModule : public IModule, public TDstEvent
    {
        TFeatureManager mBeginLogicSlotManager;
        TFeatureManager mEndLogicSlotManager;
    public:
        void Work() override final;

        TFeatureManager* GetBeginLogicSlotManager();
        TFeatureManager* GetEndLogicSlotManager();
    protected:
        virtual void ModuleWork() = 0;
    };
}