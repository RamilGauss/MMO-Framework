/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"
#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ReflectionConfigComponent.h"

#include "CodeGeneratorImplementation/GeneratorList.h"
#include "CodeGeneratorImplementation/Constants.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/System/PrepareConfigSystem.h"

namespace nsContainerCodeGenerator::nsProject::nsSystem
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::PROJECT_SYSTEM_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::nsCommon::TPathOperations::CalculatePathBy(configComponent->value.projectConfig.targetDirectory, fileName);

        auto inheritances = TConstants::GetSystemInheritances();
        for (auto& inheritance : inheritances) {
            conf.filter.inheritances.push_back({ inheritance });
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
        conf.targetForCodeGeneration.header = "Project System";

        // TypeFactory
        nsReflectionCodeGenerator::TSerializer typeFactory;
        typeFactory.className = configComponent->value.projectConfig.systemConfig.typeFactory.typeName;
        typeFactory.exportDeclaration = configComponent->value.projectConfig.exportDeclaration;
        typeFactory.fileName = configComponent->value.projectConfig.systemConfig.typeFactory.fileName;
        typeFactory.nameSpaceName = configComponent->value.projectConfig.nameSpace;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::TYPE_FACTORY, typeFactory });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.projectConfig.systemConfig.includeListFileName;

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}