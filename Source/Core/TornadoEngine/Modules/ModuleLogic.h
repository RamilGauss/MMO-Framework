/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>

#include "DstModule.h"
#include <ECS/include/Feature.h>

namespace nsTornadoEngine
{
    class DllExport TModuleLogic : public TDstModule
    {
        nsECSFramework::TFeature mMainFeature;

    public:
        bool StartEvent() override;
        void Work() override;
        void StopEvent() override;

        void AddFeature(nsECSFramework::TFeature* p);
        void RemoveFeature(nsECSFramework::TFeature* p);
    };
}