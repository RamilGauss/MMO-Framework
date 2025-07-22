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

namespace nsContainerCodeGenerator::nsCore::nsImGuiWidgets
{
    void TPrepareConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TCoreConfigComponent>(mEntMng);

        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        const auto& imGuiWidgetsConfig = configComponent->value.coreConfig.imGuiWidgetsConfig;

        TReflectionConfigComponent reflectionConfigComponent;

        auto& conf = reflectionConfigComponent.value;

        std::string fileName = std::string("./") + TConstants::CORE_IMGUI_WIDGETS_CONFIG;
        reflectionConfigComponent.absFileName =
            nsBase::TPathOperations::CalculatePathBy(configComponent->value.coreConfig.targetDirectory, fileName);

        conf.targetForParsing.recursive = true;

        auto absBase = configComponent->value.coreConfig.targetDirectory;
        auto abs = imGuiWidgetsConfig.imGuiWidgetsDirectory;

        std::string rel;
        auto relPathResult = nsBase::TPathOperations::GetRelativePath(absBase, abs, rel);

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

        // rtti
        nsReflectionCodeGenerator::TSerializer rtti;
        rtti.className = configComponent->value.coreConfig.imGuiWidgetsConfig.rtti.typeName;
        rtti.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        rtti.fileName = configComponent->value.coreConfig.imGuiWidgetsConfig.rtti.fileName;
        rtti.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        rtti.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        rtti.externalSources->outFile = TConstants::CORE_IMGUI_WIDGETS_RTTI_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::RUN_TIME_TYPE_INFORMATION, rtti });

        // DynamicCaster
        nsReflectionCodeGenerator::TSerializer dynamicCaster;
        dynamicCaster.className = configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.typeName;
        dynamicCaster.exportDeclaration = configComponent->value.coreConfig.exportDeclaration;
        dynamicCaster.fileName = configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.fileName;
        dynamicCaster.nameSpaceName = configComponent->value.coreConfig.nameSpace;

        dynamicCaster.externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        dynamicCaster.externalSources->outFile = TConstants::CORE_IMGUI_WIDGETS_DYNAMIC_CASTER_OUT;

        conf.targetForCodeGeneration.implementations.insert({ nsCodeGeneratorImplementation::TGeneratorList::DYNAMIC_CASTER, dynamicCaster });

        conf.targetForCodeGeneration.includeListParams.includeListFileName = configComponent->value.coreConfig.imGuiWidgetsConfig.includeListFileName;

        conf.targetForCodeGeneration.includeListParams.dirToInclude = { configComponent->value.coreConfig.imGuiWidgetsConfig.imGuiWidgetsDirectory };

        mEntMng->SetComponent(eid, reflectionConfigComponent);
    }
}