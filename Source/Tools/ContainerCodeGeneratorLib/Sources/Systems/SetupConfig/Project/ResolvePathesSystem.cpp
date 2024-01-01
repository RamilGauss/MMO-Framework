/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResolvePathesSystem.h"

#include <ECS/include/ExecuteSystem.h>
#include <ECS/include/Helper.h>

#include "Base/Common/PathOperations.h"

#include "Components/ProjectConfigComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TResolvePathesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        ResolvePath(configComponent->value.projectConfig.relPathToSources);
        ResolvePath(configComponent->value.projectConfig.parseDirectory);
        ResolvePath(configComponent->value.projectConfig.targetDirectory);

        ResolvePath(configComponent->value.aggregator.targetDirectory);
    }
    //------------------------------------------------------------------------------------------------------
    void TResolvePathesSystem::ResolvePath(std::string& path)
    {
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        path = nsBase::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, path);
    }
}