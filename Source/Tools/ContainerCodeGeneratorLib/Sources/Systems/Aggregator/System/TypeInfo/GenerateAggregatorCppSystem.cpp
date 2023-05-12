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

namespace nsContainerCodeGenerator::nsAggregator::nsSystem::nsTypeInfo
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            { 0, "#include \"{{ IMPL_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "#include \"{{ PROJECT_TYPE_INFO_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "using namespace {{ PROJECT_NAMESPACE }};" },
            { 0, "" },
            { 0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 1, "auto typeNameList = {{ PROJECT_TYPE_INFO_TYPE_NAME }}::GetTypeNameList();" },
            { 0, "mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());" },
            { -1,"" },
            { 1, "auto rttiList = {{ PROJECT_TYPE_INFO_TYPE_NAME }}::GetRttiList();" },
            { 0, "mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 0, "" },
            { 0, "}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "const std::list<std::string>* {{ IMPL_TYPE_NAME }}::GetTypeNameList()" },
            { 0, "{" },
            { 1, "return &mTypeNameList;" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "const std::list<int>* {{ IMPL_TYPE_NAME }}::GetRunTimeTypeIndexList()" },
            { 0, "{" },
            { 1, "return &mRttiList;" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "bool {{ IMPL_TYPE_NAME }}::ConvertTypeToName(int rtti, std::string& typeName)" },
            { 0, "{" },
            { 1, "auto pTypeName = {{ PROJECT_TYPE_INFO_TYPE_NAME }}::ConvertRttiToName(rtti);" },
            { 0, "if (pTypeName != nullptr) {" },
            { 1, "typeName = *pTypeName;" },
            { 0, "return true;" },
            { -1,"}" },
            { 0, "return false;" },
            { -1, "}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "bool {{ IMPL_TYPE_NAME }}::ConvertNameToType(const std::string& typeName, int& rtti)" },
            { 0, "{" },
            { 1, "return {{ PROJECT_TYPE_INFO_TYPE_NAME }}::ConvertNameToRtti(typeName, rtti);" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "" },
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.systemImpl.typeInfoImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = configComponent->value.projectConfig.absPathToProject;
        auto abs = configComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= configComponent->value.projectConfig.ecsSystemConfig.typeInfo.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;

        data["PROJECT_TYPE_INFO_FILE_NAME"] = pathRelToProjectSources.string();
        data["PROJECT_TYPE_INFO_TYPE_NAME"] = configComponent->value.projectConfig.ecsSystemConfig.typeInfo.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}