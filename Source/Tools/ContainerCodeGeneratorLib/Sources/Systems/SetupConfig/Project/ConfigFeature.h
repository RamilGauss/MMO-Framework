/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Common/ResolveJsonPathSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/TryLoadConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/ResolvePathesSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/ValidateConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/ResetupCoreConfigFileSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Core/TryLoadConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Core/ResolvePathesSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Core/ValidateConfigSystem.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    class DllExport TConfigFeature : public nsECSFramework::TFeature
    {
        nsCommon::TResolveJsonPathSystem mResolveJsonPathSystem;
        TTryLoadConfigSystem             mTryLoadConfigSystem;
        TResolvePathesSystem             mResolvePathesSystem;
        TResetupCoreConfigFileSystem     mResetupCoreConfigFileSystem;

        nsCommon::TResolveJsonPathSystem mCoreResolveJsonPathSystem;
        nsCore::TTryLoadConfigSystem     mCoreTryLoadConfigSystem;
        nsCore::TResolvePathesSystem     mCoreResolvePathesSystem;
        nsCore::TValidateConfigSystem    mCoreValidateConfigSystem;

    public:

        void InitConveyor() override;
    };
}