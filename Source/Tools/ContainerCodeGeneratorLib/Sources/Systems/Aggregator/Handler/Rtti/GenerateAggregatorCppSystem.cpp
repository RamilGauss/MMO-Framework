/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include <filesystem>

#include "Base/Common/TextGenerator.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/GeneratedFilesComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/Rtti/GenerateAggregatorCppSystem.h"

namespace nsContainerCodeGenerator::nsAggregator::nsHandler::nsRtti
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::nsCommon::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ PROJECT_RTTI_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "auto typeNameList = {{ PROJECT_RTTI_TYPE_NAME }}::GetTypeNameList();"},
            {0, "mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());"},
            {0, ""},
            {0, "auto rttiList = {{ PROJECT_RTTI_TYPE_NAME }}::GetRttiList();"},
            {0, "mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {0, ""},
            {0, "}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "void {{ IMPL_TYPE_NAME }}::Init()"},
            {0, "{"},
            {1, "{{ PROJECT_RTTI_TYPE_NAME }}::Init();"},
            {-1, "}"},
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
            {1, "auto pTypeName = {{ PROJECT_RTTI_TYPE_NAME }}::ConvertRttiToName(rtti);"},
            {0, "if (pTypeName != nullptr) {"},
            {1, "typeName = *pTypeName;"},
            {0, "return true;"},
            {-1,"}"},
            {0, "return false;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "bool {{ IMPL_TYPE_NAME }}::ConvertNameToType(const std::string & typeName, int& rtti)"},
            {0, "{"},
            {1, "return {{ PROJECT_RTTI_TYPE_NAME }}::ConvertNameToRtti(typeName, rtti);;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = projectConfigComponent->value.aggregator.handlerImpl.rttiImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        auto absBase = projectConfigComponent->value.absCorePath;
        auto abs = coreConfigComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::nsCommon::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        absBase = projectConfigComponent->value.projectConfig.relPathToSources;
        abs = projectConfigComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::nsCommon::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= projectConfigComponent->value.projectConfig.handlerConfig.rtti.fileName;

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = impl.impl.fileName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;

        data["CORE_RTTI_FILE_NAME"] = pathRelToProjectSources.string();
        data["CORE_RTTI_TYPE_NAME"] = projectConfigComponent->value.projectConfig.handlerConfig.rtti.typeName;

        data["PROJECT_RTTI_FILE_NAME"] = pathRelToProjectSources.string();
        data["PROJECT_RTTI_TYPE_NAME"] = projectConfigComponent->value.projectConfig.handlerConfig.rtti.typeName;

        try {
            txtGen.Apply(data);
            generatedFile.content = txtGen.Render();
        } catch (...) {
            std::string msg = "Render error";
            throw TMessageException(msg);
        }

        generatedFilesComponent->value.push_back(generatedFile);
    }
}