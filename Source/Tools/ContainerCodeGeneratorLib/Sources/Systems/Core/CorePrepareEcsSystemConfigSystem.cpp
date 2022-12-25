/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CorePrepareEcsSystemConfigSystem.h"

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ConfigComponent.h"
#include "Components/HandlerListComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator
{
    void TCorePrepareEcsSystemConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        const auto& ecsSystemConfig = configComponent->value.coreConfig.ecsSystemConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::CORE_ECS_SYSTEM_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, fileName);

        auto inheritances = TConstants::GetSystemInheritances();
        for (auto& inheritance : inheritances) {
            conf.filter.inheritances.push_back({ inheritance });
        }

        conf.targetForParsing.recursive = true;

        auto absBase = configComponent->value.coreConfig.targetDirectory;
        auto abs = ecsSystemConfig.ecsDirectory;

        std::string rel;
        auto relPathResult = nsBase::TPathOperations::GetRelativePath(absBase, abs, rel);

        if (!relPathResult) {
            auto msg = fmt::format("Attempt get relative path from {} to {} has been fail.", absBase, abs);
            throw TMessageException(msg);
        }

        conf.targetForParsing.directories.push_back(rel);

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Core Ecs System";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.coreConfig.ecsSystemConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.coreConfig.ecsSystemConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        typeInfo.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeInfo.externalSources->outFile = TConstants::CORE_ECS_SYSTEM_TYPE_INFO_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.coreConfig.ecsSystemConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.coreConfig.ecsSystemConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        dynamicCaster.externalSources->outFile = TConstants::CORE_ECS_SYSTEM_DYNAMIC_CASTER_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.coreConfig.ecsSystemConfig.includeListFileName;
        conf.targetForCodeGeneration.includeListParams.dirToInclude.push_back(rel);

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}