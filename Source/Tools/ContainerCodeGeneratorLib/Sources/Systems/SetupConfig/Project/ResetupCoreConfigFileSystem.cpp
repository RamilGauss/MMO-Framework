/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResetupCoreConfigFileSystem.h"

#include <fmt/core.h>

#include "Base/Common/TextFile.h"
#include "Base/Common/PathOperations.h"

#include <ECS/include/Helper.h>

#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/FilePathComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TResetupCoreConfigFileSystem::Execute()
    {
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto filePathComponent = nsECSFramework::SingleComponent<TFilePathComponent>(mEntMng);

        filePathComponent->value = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.absCorePath, 
            projectConfigComponent->value.relCoreConfigPath);
    }
}