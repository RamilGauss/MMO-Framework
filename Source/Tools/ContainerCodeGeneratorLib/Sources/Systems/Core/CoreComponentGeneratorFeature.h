/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Core/CorePreparingConfigurationForGenerationForComponentsSystem.h"
#include "Systems/Common/GenerationForComponentsSystem.h"
#include "Systems/Common/DestroyConfigurationForGenerationForComponentsSystem.h"

namespace nsContainerCodeGenerator
{
    class DllExport TCoreComponentGeneratorFeature : public nsECSFramework::TFeature
    {
        TCorePreparingConfigurationForGenerationForComponentsSystem mCorePreparingConfigurationForGenerationForComponentsSystem;
        TGenerationForComponentsSystem mGenerationForComponentsSystem;
        TDestroyConfigurationForGenerationForComponentsSystem mDestroyConfigurationForGenerationForComponentsSystem;

    public:
        void InitConveyor() override;
    };
}