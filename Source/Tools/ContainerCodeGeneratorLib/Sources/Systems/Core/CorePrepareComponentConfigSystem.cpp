/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CorePrepareComponentConfigSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator
{
    void TCorePrepareComponentConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        const auto& componentConfig = configComponent->value.coreConfig.componentConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        reflectionConfigComponent.absFileName = configComponent->value.coreConfig.targetDirectory + nsContainerCodeGenerator::TConstants::CORE_COMPONENT_CONFIG;

        conf.filter.inheritances.push_back({ componentConfig.inheritanceFilter });

        conf.targetForParsing.recursive = true;
        conf.targetForParsing.directories = { configComponent->value.coreConfig.parseDirectory };

        conf.filter.extensions = std::vector<std::string>(TConstants::HEADER_EXTENSIONS.begin(), TConstants::HEADER_EXTENSIONS.end());

        conf.targetForCodeGeneration.directory = configComponent->value.coreConfig.targetDirectory;
        conf.targetForCodeGeneration.header = "Core Component";

        // Json
        nsReflectionCodeGenerator::TSerializer json;
        json.className = configComponent->value.coreConfig.componentConfig.json.typeName;
        json.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        json.fileName = configComponent->value.coreConfig.componentConfig.json.fileName;
        json.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::JSON, json });

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.coreConfig.componentConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.coreConfig.componentConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // EcsExtensions
        nsReflectionCodeGenerator::TSerializer entMng;
        entMng.className = configComponent->value.coreConfig.componentConfig.entMng.typeName;
        entMng.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        entMng.fileName = configComponent->value.coreConfig.componentConfig.entMng.fileName;
        entMng.nameSpaceName = configComponent->value.coreConfig.nameSpace;
        entMng.keyValueMap.insert({ nsCodeGeneratorImplementation::TConstants::s_EntityManagerHeaderPath, configComponent->value.entityManagerHeaderPath });

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::ECS_COMPONENT_EXTENSION, entMng });

        // TODO: Add
        // ImGui

        // Binary


        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}

