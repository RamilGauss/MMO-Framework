/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/SetupConfig/Common/ResolveJsonPathSystem.h"

#include "Systems/SetupConfig/Project/TryLoadConfigSystem.h"
#include "Systems/SetupConfig/Project/ResolvePathesSystem.h"

#include "Systems/SetupConfig/Core/ValidateConfigSystem.h"
#include "Systems/SetupConfig/Project/ValidateConfigSystem.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    class DllExport TConfigFeature : public nsECSFramework::TFeature
    {
        nsCommon::TResolveJsonPathSystem mResolveJsonPathSystem;
        TTryLoadConfigSystem   mTryLoadConfigSystem;
        TResolvePathesSystem   mResolvePathesSystem;

        nsCore::TValidateConfigSystem mValidateCoreConfigSystem;
        TValidateConfigSystem mValidateProjectConfigSystem;

    public:

        void InitConveyor() override;
    };
}