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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            { 0, "#include \"{{ IMPL_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "#include \"{{ CORE_DYNAMIC_CASTER_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ PROJECT_DYNAMIC_CASTER_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "using namespace {{ PROJECT_NAMESPACE }};" },
            { 0, "" },
            { 0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 0, "" },
            { 0, "}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 0, "" },
            { 0, "}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "void* {{ IMPL_TYPE_NAME }}::Cast(int srcRtti, void* srcPtr, int dstRtti)" },
            { 0, "{" },
            { 1, "auto& m = {{ PROJECT_DYNAMIC_CASTER_TYPE_NAME }}::GetRttiCombinations();" },
            { 0, "" },
            { 0, "auto fit = m.find(srcRtti);" },
            { 0, "auto isFound = (fit != m.end());" },
            { 0, "if (isFound) {" },
            { 1, "isFound = (fit->second.find(dstRtti) != fit->second.end());" },
            { 0, "if (isFound) {" },
            { 1, "return {{ PROJECT_DYNAMIC_CASTER_TYPE_NAME }}::Cast(srcRtti, srcPtr, dstRtti);" },
            { -1,"}" },
            { -1,"}" },
            { 0, "" },
            { 0, "auto& coreM = {{ CORE_NAMESPACE }}::{{ CORE_DYNAMIC_CASTER_TYPE_NAME }}::GetRttiCombinations();" },
            { 0, "" },
            { 0, "auto coreFit = coreM.find(srcRtti);" },
            { 0, "isFound = (coreFit != coreM.end());" },
            { 0, "if (isFound) {" },
            { 1, "isFound = (coreFit->second.find(dstRtti) != coreFit->second.end());" },
            { 0, "if (isFound) {" },
            { 1, "return {{ CORE_NAMESPACE }}::{{ CORE_DYNAMIC_CASTER_TYPE_NAME }}::Cast(srcRtti, srcPtr, dstRtti);" },
            { -1,"}" },
            { -1,"}" },
            { 0, "return nullptr;" },
            { 0, "}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "" },
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.componentImpl.dynamicCasterImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = configComponent->value.projectConfig.pathToCore;
        auto abs = configComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        absBase = configComponent->value.projectConfig.absPathToProject;
        abs = configComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= configComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;

        data["CORE_DYNAMIC_CASTER_FILE_NAME"] = pathRelToCoreSources.string();
        data["PROJECT_DYNAMIC_CASTER_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_DYNAMIC_CASTER_TYPE_NAME"] = configComponent->value.coreConfig.componentConfig.dynamicCaster.typeName;
        data["PROJECT_DYNAMIC_CASTER_TYPE_NAME"] = configComponent->value.projectConfig.componentConfig.dynamicCaster.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}