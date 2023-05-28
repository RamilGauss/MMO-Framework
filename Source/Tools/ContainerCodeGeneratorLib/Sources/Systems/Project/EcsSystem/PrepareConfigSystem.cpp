/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrepareConfigSystem.h"

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ProjectConfigComponent.h"
#include "Components/HandlerListComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator::nsProject::nsEcsSystem
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_ECS_SYSTEM_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.projectConfig.targetDirectory, fileName);

        auto inheritances = TConstants::GetSystemInheritances();
        for (auto& inheritance : inheritances) {
            conf.filter.inheritances.push_back({ inheritance });
        }

        conf.targetForParsing.recursive = true;

        auto absBase = configComponent->value.projectConfig.targetDirectory;
        auto abs = configComponent->value.projectConfig.parseDirectory;

        std::string rel;
        auto relPathResult = nsBase::TPathOperations::GetRelativePath(absBase, abs, rel);

        if (!relPathResult) {
            auto msg = fmt::format("Attempt get relative path from {} to {} has been fail.", absBase, abs);
            throw TMessageException(msg);
        }

        conf.targetForParsing.directories.push_back(rel);

        abs = configComponent->value.projectConfig.ecsSystemConfig.ecsDirectory;

        relPathResult = nsBase::TPathOperations::GetRelativePath(absBase, abs, rel);

        if (!relPathResult) {
            auto msg = fmt::format("Attempt get relative path from {} to {} has been fail.", absBase, abs);
            throw TMessageException(msg);
        }

        conf.targetForParsing.directories.push_back(rel);

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Project Ecs System";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.projectConfig.ecsSystemConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.projectConfig.ecsSystemConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.ecsSystemConfig.includeListFileName;
        conf.targetForCodeGeneration.includeListParams.dirToInclude.push_back(rel);

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}