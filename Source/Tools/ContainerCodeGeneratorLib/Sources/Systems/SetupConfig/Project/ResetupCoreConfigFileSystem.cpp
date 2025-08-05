/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <fmt/core.h>

#include "Base/Common/TextFile.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/MessageException.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/ResetupCoreConfigFileSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/FilePathComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TResetupCoreConfigFileSystem::Execute()
    {
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto filePathComponent = nsECSFramework::SingleComponent<TFilePathComponent>(mEntMng);

        filePathComponent->value = nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.absCorePath,
            projectConfigComponent->value.relCoreConfigPath);
    }
}