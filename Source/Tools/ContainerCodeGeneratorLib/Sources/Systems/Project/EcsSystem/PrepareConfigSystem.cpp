/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrepareConfigSystem.h"

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
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

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_ECS_SYSTEM_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.projectConfig.targetDirectory, fileName);

        auto inheritances = TConstants::GetSystemInheritances();
        for (auto& inheritance : inheritances) {
            conf.filter.inheritances.push_back({ inheritance });
        }

        conf.targetForParsing.recursive = true;

        auto absBase = projectConfigComponent->value.projectConfig.targetDirectory;
        auto abs = projectConfigComponent->value.projectConfig.parseDirectory;

        std::string rel;
        auto relPathResult = nsBase::TPathOperations::GetRelativePath(absBase, abs, rel);

        if (!relPathResult) {
            auto msg = fmt::format("Attempt get relative path from {} to {} has been fail.", absBase, abs);
            throw MSG_EXCEPTION(msg);
        }

        conf.targetForParsing.directories.push_back(rel);

        auto absCorePath = projectConfigComponent->value.absCorePath;
        auto absCoreConfigFilePath = nsBase::TPathOperations::CalculatePathBy(absCorePath, projectConfigComponent->value.relCoreConfigPath);
        auto absCoreConfigDirPath = nsBase::TPathOperations::FileDirPath(absCoreConfigFilePath);

        auto ecsRel = coreConfigComponent->value.ecsDirectory;
        auto ecsAbsPath = nsBase::TPathOperations::CalculatePathBy(absCoreConfigDirPath, ecsRel);

        conf.targetForParsing.directories.push_back(ecsAbsPath);

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Project Ecs System";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer rtti;
        rtti.className = projectConfigComponent->value.projectConfig.ecsSystemConfig.rtti.typeName;
        rtti.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        rtti.fileName = projectConfigComponent->value.projectConfig.ecsSystemConfig.rtti.fileName;
        rtti.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::RUN_TIME_TYPE_INFORMATION, rtti });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = projectConfigComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        dynamicCaster.fileName = projectConfigComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = projectConfigComponent->value.projectConfig.ecsSystemConfig.includeListFileName;
        conf.targetForCodeGeneration.includeListParams.dirToInclude.push_back(ecsAbsPath);

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}