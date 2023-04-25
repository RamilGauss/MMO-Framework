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

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets::nsTypeInfo
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ CORE_TYPE_INFO_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "auto typeNameList = {{ CORE_NAMESPACE }}::{{ CORE_TYPE_FACTORY_TYPE_NAME }}::GetTypeNameList();"},
            {0, "mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());"},
            {0, ""},
            {0, "auto rttiList = {{ CORE_NAMESPACE }}::{{ CORE_TYPE_FACTORY_TYPE_NAME }}::GetRttiList();"},
            {0, "mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "const std::list<std::string>* {{ IMPL_TYPE_NAME }}::GetTypeNameList()"},
            {0, "{"},
            {1, "return &mTypeNameList;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "const std::list<int>* {{ IMPL_TYPE_NAME }}::GetRunTimeTypeIndexList()"},
            {0, "{"},
            {1, "return &mRttiList;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "bool {{ IMPL_TYPE_NAME }}::ConvertTypeToName(int rtti, std::string & typeName)"},
            {0, "{"},
            {1, "auto pTypeName = {{ CORE_NAMESPACE }}::{{ CORE_TYPE_FACTORY_TYPE_NAME }}::ConvertRttiToName(rtti);"},
            {0, "if (pTypeName != nullptr) {"},
            {1, "typeName = *pTypeName;"},
            {0, "return true;"},
            {-1,"}"},
            {0, "return false;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "bool {{ IMPL_TYPE_NAME }}::ConvertNameToType(const std::string & typeName, int& rtti)"},
            {0, "{"},
            {1, "return {{ CORE_NAMESPACE }}::{{ CORE_TYPE_FACTORY_TYPE_NAME }}::ConvertNameToRtti(typeName, rtti);"},
            {-1, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = configComponent->value.projectConfig.pathToCore;
        auto abs = configComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.coreConfig.imGuiWidgetsConfig.typeInfo.fileName;

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;

        data["CORE_TYPE_INFO_FILE_NAME"] = pathRelToCoreSources.string();
        data["CORE_TYPE_INFO_TYPE_NAME"] = configComponent->value.coreConfig.imGuiWidgetsConfig.typeInfo.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}