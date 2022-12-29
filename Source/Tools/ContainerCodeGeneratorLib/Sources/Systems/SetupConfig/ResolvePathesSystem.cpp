/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResolvePathesSystem.h"

#include <ECS/include/ExecuteSystem.h>
#include <ECS/include/Helper.h>

#include "PathOperations.h"

#include "Components/ArgumentComponent.h"
#include "Components/ConfigComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig
{
    void TResolvePathesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        ResolvePath(configComponent->value.reflectionCodeGeneratorFileName);

        ResolvePath(configComponent->value.coreConfig.parseDirectory);
        ResolvePath(configComponent->value.coreConfig.targetDirectory);

        ResolvePath(configComponent->value.projectConfig.pathToCore);
        // TODO: delete
        ResolvePath(configComponent->value.projectConfig.parseDirectory);
        ResolvePath(configComponent->value.projectConfig.targetDirectory);
        ResolvePath(configComponent->value.projectConfig.ecsSystemConfig.ecsDirectory);

        ResolvePath(configComponent->value.aggregator.targetDirectory);
    }
    //------------------------------------------------------------------------------------------------------
    void TResolvePathesSystem::ResolvePath(std::string& path)
    {
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        path = nsBase::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, path);
    }
}