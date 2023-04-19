/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <filesystem>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h"},
            {0, ""},
            {0, "#include \"{{ CORE_DYNAMIC_CASTER_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void* {{ IMPL_TYPE_NAME }}::Cast(int srcRtti, void* srcPtr, int dstRtti)"},
            {0, "{"},
            {1, "auto& coreM = {{ CORE_NAMESPACE }}::{{ CORE_DYNAMIC_CASTER_TYPE_NAME }}::GetRttiCombinations();"},
            {0, ""},
            {0, "auto coreFit = coreM.find(srcRtti);"},
            {0, "auto isFound = (coreFit != coreM.end());"},
            {0, "if (isFound) {"},
            {1, "isFound = (coreFit->second.find(dstRtti) != coreFit->second.end());"},
            {0, "if (isFound) {"},
            {1, "return {{ CORE_NAMESPACE }}::{{ CORE_DYNAMIC_CASTER_TYPE_NAME }}::Cast(srcRtti, srcPtr, dstRtti);"},
            {-1,"}"},
            {-1,"}"},
            {0, "return nullptr;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = configComponent->value.projectConfig.pathToCore;
        auto abs = configComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        std::filesystem::path pathRelToProjectSources(relToCoreSources);
        pathRelToProjectSources /= configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;

        data["CORE_DYNAMIC_CASTER_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_DYNAMIC_CASTER_TYPE_NAME"] = configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}