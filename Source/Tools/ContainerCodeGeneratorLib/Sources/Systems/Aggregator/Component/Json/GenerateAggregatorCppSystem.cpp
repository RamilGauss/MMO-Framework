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

#include "ECS/Include/Helper.h"

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsJson
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::nsCommon::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ CORE_JSON_FILE_NAME }}.h\""},
            {0, "#include \"{{ PROJECT_JSON_FILE_NAME }}.h\""},
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
            {0, "void {{ IMPL_TYPE_NAME }}::Init()"},
            {0, "{"},
            {1, "{{ PROJECT_JSON_TYPE_NAME }}::Init();"},
            {0, "{{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Init();"},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void {{ IMPL_TYPE_NAME }}::Serialize(void* p, std::string & json, int rtti)"},
            {0, "{"},
            {1, "if ({{ PROJECT_JSON_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ PROJECT_JSON_TYPE_NAME }}::Serialize(p, json, rtti);"},
            {0, "return;"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Has(rtti)) {"},
            {1, "{{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Serialize(p, json, rtti);"},
            {-1,"}"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "bool {{ IMPL_TYPE_NAME }}::Deserialize(void* p, const std::string & json, int rtti, std::string & err)"},
            {0, "{"},
            {1, "if ({{ PROJECT_JSON_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ PROJECT_JSON_TYPE_NAME }}::Deserialize(p, json, rtti, err);"},
            {-1,"}"},
            {0, "if ({{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Has(rtti)) {"},
            {1, "return {{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Deserialize(p, json, rtti, err);"},
            {-1,"}"},
            {0, "return false;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = projectConfigComponent->value.aggregator.componentImpl.jsonImpl;

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

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= projectConfigComponent->value.projectConfig.componentConfig.json.fileName;

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= coreConfigComponent->value.coreConfig.componentConfig.json.fileName;

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;

        data["CORE_JSON_FILE_NAME"] = pathRelToCoreSources.string();
        data["PROJECT_JSON_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_JSON_TYPE_NAME"] = coreConfigComponent->value.coreConfig.componentConfig.json.typeName;
        data["PROJECT_JSON_TYPE_NAME"] = projectConfigComponent->value.projectConfig.componentConfig.json.typeName;

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