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

#include "Components/ProjectConfigComponent.h"
#include "Components/HandlerListComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator::nsProject::nsHandler
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto coreHandlerListComponent = nsECSFramework::SingleComponent<THandlerListComponent>(mEntMng);

        const auto& handlerConfig = configComponent->value.projectConfig.handlerConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_HANDLER_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(configComponent->value.projectConfig.targetDirectory, fileName);

        for (auto& handler : coreHandlerListComponent->value) {
            conf.filter.inheritances.push_back({ handler });
        }

        conf.targetForParsing.recursive = true;

        auto absBase = configComponent->value.projectConfig.targetDirectory;
        auto abs = configComponent->value.projectConfig.parseDirectory;

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
        conf.targetForCodeGeneration.header = "Project Handler";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.projectConfig.handlerConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.projectConfig.handlerConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // rtti
        nsReflectionCodeGenerator::TSerializer rtti;
        rtti.className = configComponent->value.projectConfig.handlerConfig.rtti.typeName;
        rtti.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        rtti.fileName = configComponent->value.projectConfig.handlerConfig.rtti.fileName;
        rtti.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::RUN_TIME_TYPE_INFORMATION, rtti });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.projectConfig.handlerConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.projectConfig.handlerConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.handlerConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}