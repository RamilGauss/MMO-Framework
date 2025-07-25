/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResolvePathesSystem.h"

#include "ECS/Include/ExecuteSystem.h"
#include "ECS/Include/Helper.h"

#include "Base/Common/PathOperations.h"

#include "Components/CoreConfigComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsCore
{
    void TResolvePathesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        ResolvePath(configComponent->value.reflectionCodeGeneratorFileName);

        ResolvePath(configComponent->value.coreConfig.parseDirectory);
        ResolvePath(configComponent->value.coreConfig.targetDirectory);
        ResolvePath(configComponent->value.coreConfig.imGuiWidgetsConfig.imGuiWidgetsDirectory);
        ResolvePath(configComponent->value.engineSourcePath);
    }
    //------------------------------------------------------------------------------------------------------
    void TResolvePathesSystem::ResolvePath(std::string& path)
    {
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        path = nsBase::nsCommon::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, path);
    }
}