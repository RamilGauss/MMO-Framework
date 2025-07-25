/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrepareConfigSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"
#include "ECS/Include/Helper.h"

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator::nsCore::nsComponent
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TCoreConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        const auto& componentConfig = configComponent->value.coreConfig.componentConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::CORE_COMPONENT_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, fileName);

        conf.filter.inheritances.push_back({ componentConfig.inheritances });

        conf.targetForParsing.recursive = true;

        auto absBase = configComponent->value.coreConfig.targetDirectory;
        auto abs = configComponent->value.coreConfig.parseDirectory;

        std::string rel;
        auto relPathResult = nsBase::nsCommon::TPathOperations::GetRelativePath(absBase, abs, rel);

        if (!relPathResult) {
            auto msg = fmt::format("Attempt get relative path from {} to {} has been fail.", absBase, abs);
            throw MSG_EXCEPTION(msg);
        }

        conf.targetForParsing.directories.push_back(rel);

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Core Component";

        // Json
        nsReflectionCodeGenerator::TSerializer json;
        json.className = configComponent->value.coreConfig.componentConfig.json.typeName;
        json.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        json.fileName = configComponent->value.coreConfig.componentConfig.json.fileName;
        json.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        json.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        json.externalSources->outFile = TConstants::CORE_COMPONENT_JSON_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::JSON, json });

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer rtti;
        rtti.className = configComponent->value.coreConfig.componentConfig.rtti.typeName;
        rtti.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        rtti.fileName = configComponent->value.coreConfig.componentConfig.rtti.fileName;
        rtti.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        rtti.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        rtti.externalSources->outFile = TConstants::CORE_COMPONENT_RTTI_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::RUN_TIME_TYPE_INFORMATION, rtti });

        // EcsExtensions
        nsReflectionCodeGenerator::TSerializer entMng;
        entMng.className = configComponent->value.coreConfig.componentConfig.entMng.typeName;
        entMng.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        entMng.fileName = configComponent->value.coreConfig.componentConfig.entMng.fileName;
        entMng.nameSpaceName = configComponent->value.coreConfig.nameSpace;
        entMng.keyValueMap.insert({ nsCodeGeneratorImplementation::TConstants::s_EntityManagerHeaderPath, configComponent->value.entityManagerHeaderPath });

        entMng.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        entMng.externalSources->outFile = TConstants::CORE_COMPONENT_ECS_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::ECS_COMPONENT_EXTENSION, entMng });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.coreConfig.componentConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.coreConfig.componentConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        dynamicCaster.externalSources->outFile = TConstants::CORE_COMPONENT_DYNAMIC_CASTER_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.coreConfig.componentConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.coreConfig.componentConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        typeFactory.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeFactory.externalSources->outFile = TConstants::CORE_COMPONENT_TYPE_FACTORY_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });


        // TODO: Add
        // ImGui

        // Binary


        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.coreConfig.componentConfig.includeListFileName;


        auto sourceAbsPath = configComponent->value.engineSourcePath;
        sourceAbsPath += "\\";

        conf.targetForCodeGeneration.includeListParams.dirToInclude.push_back(sourceAbsPath);

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}

