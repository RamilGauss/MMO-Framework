/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProjectPrepareHandlerConfSystem.h"

#include <filesystem>

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
    void TProjectPrepareHandlerConfSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto coreHandlerListComponent = nsECSFramework::SingleComponent<THandlerListComponent>(mEntMng);

        const auto& handlerConfig = configComponent->value.projectConfig.handlerConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_HANDLER_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.projectConfig.targetDirectory, fileName);

        for (auto& handler : coreHandlerListComponent->value) {
            conf.filter.inheritances.push_back({ handler });
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
        conf.targetForCodeGeneration.header = "Project Handler";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.projectConfig.handlerConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.projectConfig.handlerConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        typeInfo.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeInfo.externalSources->outFile = TConstants::PROJECT_HANDLER_TYPE_INFO_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.projectConfig.handlerConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.projectConfig.handlerConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        typeFactory.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeFactory.externalSources->outFile = TConstants::PROJECT_HANDLER_TYPE_FACTORY_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.handlerConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}