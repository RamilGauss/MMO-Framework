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

namespace nsContainerCodeGenerator::nsAggregator::nsSystem::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ PROJECT_DYNAMIC_CASTER_FILE_NAME }}.h\""},
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
            {1, "auto& m = {{ PROJECT_DYNAMIC_CASTER_TYPE_NAME }}::GetRttiCombinations();"},
            {0, ""},
            {0, "auto fit = m.find(srcRtti);"},
            {0, "auto notFound = (fit == m.end());"},
            {0, "if (notFound) {"},
            {1, "return nullptr;"},
            {-1,"}"},
            {0, "notFound = (fit->second.find(dstRtti) == fit->second.end());"},
            {0, "if (notFound) {"},
            {1, "return nullptr;"},
            {-1,"}"},
            {0, "return {{ PROJECT_DYNAMIC_CASTER_TYPE_NAME }}::Cast(srcRtti, srcPtr, dstRtti);"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.systemImpl.dynamicCasterImpl;

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

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["PARENT_FILE_NAME"] = impl.parent.fileName;
        data["PROJECT_DYNAMIC_CASTER_FILE_NAME"] = pathRelToProjectSources.string();
        data["PROJECT_DYNAMIC_CASTER_TYPE_NAME"] = configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.typeName;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}