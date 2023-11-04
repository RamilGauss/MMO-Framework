/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MakeFileListSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/FileListComponent.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TMakeFileListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TCoreConfigComponent>(mEntMng);

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        // Search in core sources!
        auto targetDir = coreConfigComponent->value.coreConfig.parseDirectory;

        TFileListComponent fileListComponent;

        nsBase::TPathOperations::AddAbsPathsByDirectory(targetDir, TConstants::GetHeaderExtensions(), fileListComponent.value, true);

        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        targetDir = projectConfigComponent->value.projectConfig.parseDirectory;

        nsBase::TPathOperations::AddAbsPathsByDirectory(targetDir, TConstants::GetHeaderExtensions(), fileListComponent.value, true);

        mEntMng->SetComponent(eid, fileListComponent);
    }
}