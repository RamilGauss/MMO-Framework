/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"
#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Component/PrepareConfigSystem.h"

namespace nsContainerCodeGenerator::nsProject::nsComponent
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        const auto& componentConfig = projectConfigComponent->value.projectConfig.componentConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_COMPONENT_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.projectConfig.targetDirectory, fileName);

        conf.filter.inheritances.push_back({ componentConfig.inheritances });

        conf.targetForParsing.recursive = true;


        auto absBase = projectConfigComponent->value.projectConfig.targetDirectory;
        auto abs = projectConfigComponent->value.projectConfig.parseDirectory;

        std::string rel;
        auto relPathResult = nsBase::nsCommon::TPathOperations::GetRelativePath(absBase, abs, rel);

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
        json.className = projectConfigComponent->value.projectConfig.componentConfig.json.typeName;
        json.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        json.fileName = projectConfigComponent->value.projectConfig.componentConfig.json.fileName;
        json.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        json.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string jsonInFileName = std::string("./") + TConstants::CORE_COMPONENT_JSON_OUT;
        std::string absJsonInFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(coreConfigComponent->value.coreConfig.targetDirectory, jsonInFileName);
        json.externalSources->inFileList.push_back(absJsonInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::JSON, json });

        // Rtti
        nsReflectionCodeGenerator::TSerializer rtti;
        rtti.className = projectConfigComponent->value.projectConfig.componentConfig.rtti.typeName;
        rtti.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        rtti.fileName = projectConfigComponent->value.projectConfig.componentConfig.rtti.fileName;
        rtti.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        rtti.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string typeInfoInFileName = std::string("./") + TConstants::CORE_COMPONENT_RTTI_OUT;
        std::string absTypeInfoInFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(coreConfigComponent->value.coreConfig.targetDirectory, typeInfoInFileName);
        rtti.externalSources->inFileList.push_back(absTypeInfoInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::RUN_TIME_TYPE_INFORMATION, rtti });

        // EcsExtensions
        nsReflectionCodeGenerator::TSerializer entMng;
        entMng.className = projectConfigComponent->value.projectConfig.componentConfig.entMng.typeName;
        entMng.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        entMng.fileName = projectConfigComponent->value.projectConfig.componentConfig.entMng.fileName;
        entMng.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;
        entMng.keyValueMap.insert({ nsCodeGeneratorImplementation::TConstants::s_EntityManagerHeaderPath, coreConfigComponent->value.entityManagerHeaderPath });

        entMng.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string entMngInFileName = std::string("./") + TConstants::CORE_COMPONENT_ECS_OUT;
        std::string absEntMngInFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(coreConfigComponent->value.coreConfig.targetDirectory, entMngInFileName);
        entMng.externalSources->inFileList.push_back(absEntMngInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::ECS_COMPONENT_EXTENSION, entMng });

        // Dynamic caster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = projectConfigComponent->value.projectConfig.componentConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        dynamicCaster.fileName = projectConfigComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string dynamicCasterInFileName = std::string("./") + TConstants::CORE_COMPONENT_DYNAMIC_CASTER_OUT;
        std::string absDynamicCasterInFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(coreConfigComponent->value.coreConfig.targetDirectory, dynamicCasterInFileName);
        dynamicCaster.externalSources->inFileList.push_back(absDynamicCasterInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = projectConfigComponent->value.projectConfig.componentConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = projectConfigComponent->value.projectConfig.exportDeclaration;
        typeFactory.fileName = projectConfigComponent->value.projectConfig.componentConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = projectConfigComponent->value.projectConfig.nameSpace;

        typeFactory.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());

        std::string typeFactoryInFileName = std::string("./") + TConstants::CORE_COMPONENT_TYPE_FACTORY_OUT;
        std::string absTypeFactoryInFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(coreConfigComponent->value.coreConfig.targetDirectory, typeFactoryInFileName);
        rtti.externalSources->inFileList.push_back(typeFactoryInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });
        // TODO: Add
        // ImGui

        // Binary


        conf.targetForCodeGeneration.includeListParams.includeListFileName = projectConfigComponent->value.projectConfig.componentConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}
