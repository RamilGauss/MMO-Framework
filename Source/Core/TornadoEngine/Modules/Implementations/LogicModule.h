/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <vector>
#include <list>

#include "TornadoEngine/Modules/Interfaces/ILogicModule.h"

#include "TornadoEngine/Features/Logic/Begin/BeginLogicFeature.h"
#include "TornadoEngine/Features/Logic/End/EndLogicFeature.h"

namespace nsTornadoEngine
{
    class DllExport TLogicModule : public ILogicModule
    {
        TFeatureManager mWorkSlots;

        nsLogicWrapper::TBeginLogicFeature mBeginFeature;
        nsLogicWrapper::TEndLogicFeature mEndFeature;
    public:
        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;

        TFeatureManager* GetWorkSlots() override;
        void SetWorkSlots(TFeatureManager* pLSM) override;
    };
}