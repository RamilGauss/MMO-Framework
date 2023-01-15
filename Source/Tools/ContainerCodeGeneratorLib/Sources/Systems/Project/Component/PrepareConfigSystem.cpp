/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrepareConfigSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ConfigComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator::nsProject::nsComponent
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        const auto& componentConfig = configComponent->value.projectConfig.componentConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_COMPONENT_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.projectConfig.targetDirectory, fileName);

        conf.filter.inheritances.push_back({ componentConfig.inheritanceFilter });

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

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Project Component";

        // Json
        nsReflectionCodeGenerator::TSerializer json;
        json.className = configComponent->value.projectConfig.componentConfig.json.typeName;
        json.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        json.fileName = configComponent->value.projectConfig.componentConfig.json.fileName;
        json.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        json.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string jsonInFileName = std::string("./") + TConstants::CORE_COMPONENT_JSON_OUT;
        std::string absJsonInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, jsonInFileName);
        json.externalSources->inFileList.push_back(absJsonInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::JSON, json });

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.projectConfig.componentConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.projectConfig.componentConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        typeInfo.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string typeInfoInFileName = std::string("./") + TConstants::CORE_COMPONENT_TYPE_INFO_OUT;
        std::string absTypeInfoInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, typeInfoInFileName);
        typeInfo.externalSources->inFileList.push_back(absTypeInfoInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // EcsExtensions
        nsReflectionCodeGenerator::TSerializer entMng;
        entMng.className = configComponent->value.projectConfig.componentConfig.entMng.typeName;
        entMng.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        entMng.fileName = configComponent->value.projectConfig.componentConfig.entMng.fileName;
        entMng.nameSpaceName = configComponent->value.projectConfig.nameSpace;
        entMng.keyValueMap.insert({ nsCodeGeneratorImplementation::TConstants::s_EntityManagerHeaderPath, configComponent->value.entityManagerHeaderPath });

        entMng.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string entMngInFileName = std::string("./") + TConstants::CORE_COMPONENT_ECS_OUT;
        std::string absEntMngInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, entMngInFileName);
        entMng.externalSources->inFileList.push_back(absEntMngInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::ECS_COMPONENT_EXTENSION, entMng });

        // Dynamic caster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.projectConfig.componentConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string dynamicCasterInFileName = std::string("./") + TConstants::CORE_COMPONENT_DYNAMIC_CASTER_OUT;
        std::string absDynamicCasterInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, dynamicCasterInFileName);
        dynamicCaster.externalSources->inFileList.push_back(absDynamicCasterInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        // TODO: Add
        // ImGui

        // Binary


        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.componentConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}