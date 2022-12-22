/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CorePrepareHandlerConfSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/CoreHandlerListComponent.h"
#include "Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

namespace nsContainerCodeGenerator
{
    void TCorePrepareHandlerConfSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto coreHandlerListComponent = nsECSFramework::SingleComponent<TCoreHandlerListComponent>(mEntMng);

        const auto& handlerConfig = configComponent->value.coreConfig.handlerConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::CORE_HANDLER_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, fileName);

        for (auto& handler : coreHandlerListComponent->value) {
            conf.filter.inheritances.push_back({ handler });
        }

        conf.targetForParsing.recursive = true;
        conf.targetForParsing.directories = { configComponent->value.coreConfig.parseDirectory };

        auto ext = TConstants::GetHeaderExtensions();
        conf.filter.extensions = std::vector<std::string>(ext.begin(), ext.end());

        conf.targetForCodeGeneration.directory = ".";
        conf.targetForCodeGeneration.header = "Core Handler";

        // TypeInformation
        nsReflectionCodeGenerator::TSerializer typeInfo;
        typeInfo.className = configComponent->value.coreConfig.handlerConfig.typeInfo.typeName;
        typeInfo.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        typeInfo.fileName = configComponent->value.coreConfig.handlerConfig.typeInfo.fileName;
        typeInfo.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        typeInfo.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeInfo.externalSources->outFile = TConstants::CORE_HANDLER_TYPE_INFO_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_INFORMATION, typeInfo });

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.coreConfig.handlerConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.coreConfig.handlerConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        typeFactory.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        typeFactory.externalSources->outFile = TConstants::CORE_HANDLER_TYPE_FACTORY_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}