/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Core/CorePreparingConfigurationForGenerationForHandlersSystem.h"
#include "Systems/Common/ParsingHandlerTypesSystem.h"

namespace nsContainerCodeGenerator
{
    class DllExport TCoreHandlerGeneratorFeature : public nsECSFramework::TFeature
    {
        TCorePreparingConfigurationForGenerationForHandlersSystem mCorePreparingConfigurationForGenerationForHandlersSystem;

        TParsingHandlerTypesSystem mParsingHandlerTypesSystem;

    public:
        void InitConveyor() override;
    };
}