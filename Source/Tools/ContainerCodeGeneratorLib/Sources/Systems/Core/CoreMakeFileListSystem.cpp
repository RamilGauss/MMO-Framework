/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CoreMakeFileListSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/FileListComponent.h"

namespace nsContainerCodeGenerator
{
    void TCoreMakeFileListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        auto targetDir = configComponent->value.coreConfig.parseDirectory;

        TFileListComponent fileListComponent;

        nsBase::TPathOperations::AddAbsPathsByDirectory(targetDir, TConstants::GetHeaderExtensions(), fileListComponent.value, true);

        mEntMng->SetComponent(eid, fileListComponent);
    }
}