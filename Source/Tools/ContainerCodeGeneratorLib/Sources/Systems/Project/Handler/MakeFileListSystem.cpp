/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/FileListComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/MakeFileListSystem.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TMakeFileListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TCoreConfigComponent>(mEntMng);

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        // Search in core sources!
        auto targetDir = coreConfigComponent->value.coreConfig.parseDirectory;

        TFileListComponent fileListComponent;

        nsBase::nsCommon::TPathOperations::AddAbsPathsByDirectory(targetDir, TConstants::GetHeaderExtensions(), fileListComponent.value, true);

        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        targetDir = projectConfigComponent->value.projectConfig.parseDirectory;

        nsBase::nsCommon::TPathOperations::AddAbsPathsByDirectory(targetDir, TConstants::GetHeaderExtensions(), fileListComponent.value, true);

        mEntMng->SetComponent(eid, fileListComponent);
    }
}
