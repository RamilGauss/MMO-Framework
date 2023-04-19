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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsJson
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
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
            {0, "void {{ IMPL_TYPE_NAME }}::Serialize(void* p, std::string & json, int rtti)"}, 
            {0, "{"}, 
            {0, "    if ({{ PROJECT_JSON_TYPE_NAME }}::Has(rtti)) {"}, 
            {0, "        {{ PROJECT_JSON_TYPE_NAME }}::Serialize(p, json, rtti);"}, 
            {0, "        return;"}, 
            {0, "    }"}, 
            {0, "    if ({{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Has(rtti)) {"}, 
            {0, "        {{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Serialize(p, json, rtti);"}, 
            {0, "    }"}, 
            {0, "}"}, 
            {0, "//--------------------------------------------------------------------------------------------------"}, 
            {0, "bool {{ IMPL_TYPE_NAME }}::Deserialize(void* p, const std::string & json, int rtti, std::string & err)"}, 
            {0, "{"}, 
            {0, "    if ({{ PROJECT_JSON_TYPE_NAME }}::Has(rtti)) {"}, 
            {0, "        return {{ PROJECT_JSON_TYPE_NAME }}::Deserialize(p, json, rtti, err);"}, 
            {0, "    }"}, 
            {0, "    if ({{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Has(rtti)) {"}, 
            {0, "        return {{ CORE_NAMESPACE }}::{{ CORE_JSON_TYPE_NAME }}::Deserialize(p, json, rtti, err);"}, 
            {0, "    }"}, 
            {0, "    return false;"}, 
            {0, "}"}, 
            {0, "//--------------------------------------------------------------------------------------------------"}, 
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.componentImpl.jsonImpl;

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
        pathRelToProjectSources /= configComponent->value.projectConfig.componentConfig.json.fileName;

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.coreConfig.componentConfig.json.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;

        data["CORE_JSON_FILE_NAME"] = pathRelToCoreSources.string();
        data["PROJECT_JSON_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_JSON_TYPE_NAME"] = configComponent->value.coreConfig.componentConfig.json.typeName;
        data["PROJECT_JSON_TYPE_NAME"] = configComponent->value.projectConfig.componentConfig.json.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}