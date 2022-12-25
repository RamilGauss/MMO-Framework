/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProjectPrepareSystemConfigSystem.h"

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ConfigComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator
{
    void TProjectPrepareSystemConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_SYSTEM_CONFIG;
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

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());
        conf.filter.memberIgnore = TConstants::IGNORE_ATTRIBUTE;

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Project System";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.projectConfig.systemConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.projectConfig.systemConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        typeInfo.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeInfo.externalSources->outFile = TConstants::PROJECT_SYSTEM_TYPE_INFO_OUT;

        std::string typeInfoInFileName = std::string("./") + TConstants::CORE_ECS_SYSTEM_TYPE_INFO_OUT;
        std::string absTypeInfoInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, typeInfoInFileName);
        typeInfo.externalSources->inFileList.push_back(absTypeInfoInFileName);

        typeInfoInFileName = std::string("./") + TConstants::CORE_SYSTEM_TYPE_INFO_OUT;
        absTypeInfoInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, typeInfoInFileName);
        typeInfo.externalSources->inFileList.push_back(absTypeInfoInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.projectConfig.systemConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.projectConfig.systemConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        dynamicCaster.externalSources->outFile = TConstants::PROJECT_SYSTEM_DYNAMIC_CASTER_OUT;

        std::string dynamicCasterInFileName = std::string("./") + TConstants::CORE_ECS_SYSTEM_DYNAMIC_CASTER_OUT;
        std::string absDynamicCasterInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, dynamicCasterInFileName);
        dynamicCaster.externalSources->inFileList.push_back(absDynamicCasterInFileName);

        dynamicCasterInFileName = std::string("./") + TConstants::CORE_SYSTEM_DYNAMIC_CASTER_OUT;
        absDynamicCasterInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, dynamicCasterInFileName);
        dynamicCaster.externalSources->inFileList.push_back(absDynamicCasterInFileName);

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.projectConfig.systemConfig.typeInfo.typeName;
        typeFactory.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.projectConfig.systemConfig.typeInfo.fileName;
        typeFactory.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        typeFactory.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeFactory.externalSources->outFile = TConstants::PROJECT_SYSTEM_TYPE_FACTORY_OUT;

        std::string typeFactoryInFileName = std::string("./") + TConstants::CORE_SYSTEM_TYPE_FACTORY_OUT;
        std::string absTypeFactoryInFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, typeFactoryInFileName);
        typeFactory.externalSources->inFileList.push_back(absTypeFactoryInFileName);


        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.systemConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}