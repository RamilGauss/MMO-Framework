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

#include "Components/InputOutput/ArgumentComponent.h"
#include "Components/InputOutput/ConfigComponent.h"
#include "Components/InputOutput/ResultComponent.h"
#include "Components/InputOutput/PathsComponent.h"

namespace nsContainerCodeGenerator
{
    void TResolvePathesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto& config = configComponent->value;

        ResolvePath(config.reflectionCodeGeneratorFileName);

        ResolvePath(config.coreConfig.parseDirectory);
        ResolvePath(config.coreConfig.targetDirectory);
        ResolvePath(config.coreConfig.ecsSystemConfig.ecsDirectory);

        ResolvePath(config.projectConfig.parseDirectory);
        ResolvePath(config.projectConfig.targetDirectory);
    }
    //------------------------------------------------------------------------------------------------------
    void TResolvePathesSystem::ResolvePath(std::string& path)
    {
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        path = nsBase::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, path);
    }
}