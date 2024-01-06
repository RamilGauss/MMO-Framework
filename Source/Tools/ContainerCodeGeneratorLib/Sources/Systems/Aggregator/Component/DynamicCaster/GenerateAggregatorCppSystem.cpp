/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <filesystem>

#include "Base/Common/TextGenerator.h"
#include "Base/Common/PathOperations.h"

#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::nsCommon::TLine> lines =
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
            { 0, "void {{ IMPL_TYPE_NAME }}::Init()" },
            { 0, "{" },
            { 1, "{{ PROJECT_DYNAMIC_CASTER_TYPE_NAME }}::Init();" },
            { 0, "{{ CORE_NAMESPACE }}::{{ CORE_DYNAMIC_CASTER_TYPE_NAME }}::Init();" },
            { -1, "}" },
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

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = projectConfigComponent->value.aggregator.componentImpl.dynamicCasterImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = projectConfigComponent->value.absCorePath;
        auto abs = coreConfigComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        absBase = projectConfigComponent->value.projectConfig.relPathToSources;
        abs = projectConfigComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= projectConfigComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= projectConfigComponent->value.projectConfig.componentConfig.dynamicCaster.fileName;

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;

        data["CORE_DYNAMIC_CASTER_FILE_NAME"] = pathRelToCoreSources.string();
        data["PROJECT_DYNAMIC_CASTER_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_DYNAMIC_CASTER_TYPE_NAME"] = coreConfigComponent->value.coreConfig.componentConfig.dynamicCaster.typeName;
        data["PROJECT_DYNAMIC_CASTER_TYPE_NAME"] = projectConfigComponent->value.projectConfig.componentConfig.dynamicCaster.typeName;

        try {
            txtGen.Apply(data);
            generatedFile.content = txtGen.Render();
        } catch (...) {
            std::string msg = "Render error";
            throw MSG_EXCEPTION(msg);
        }

        generatedFilesComponent->value.push_back(generatedFile);
    }
}