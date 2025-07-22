/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "BootstrapperSystem.h"

namespace nsTornadoEditor
{
    class DllExport TBootstrapperFeature : public nsECSFramework::TFeature
    {
        TBootstrapperSystem mBootstrapperSystem;
    public:
        void InitConveyor() override;
    };
}