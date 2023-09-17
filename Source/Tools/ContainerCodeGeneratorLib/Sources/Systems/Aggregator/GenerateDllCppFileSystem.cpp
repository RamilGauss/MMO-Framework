/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateDllCppFileSystem.h"

#include <fmt/core.h>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TGenerateDllCppFileSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ DLL_HEADER_FILE_NAME }}\""},
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ CORE_NAMESPACE }};"},
            {0, ""},
            {0, "{{ DLL_EXPORT_C }} {{ PARENT_FILE_NAME }}* {{ GET_FUNC_NAME }}()"},
            {0, "{"},
            {1, "return new {{ PROJECT_NAMESPACE }}::{{ IMPL_TYPE_NAME }}();"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ DLL_EXPORT_C }} void {{ FREE_FUNC_NAME }}({{ PARENT_FILE_NAME }} * p)"},
            {0, "{"},
            {1, "delete p;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------" },
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.dllCppFileName);

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["DLL_HEADER_FILE_NAME"] = projectConfigComponent->value.aggregator.dllHeaderFileName;
        data["IMPL_FILE_NAME"] = projectConfigComponent->value.aggregator.impl.fileName;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["DLL_EXPORT_C"] = projectConfigComponent->value.aggregator.cExportDeclaration;
        data["PARENT_FILE_NAME"] = projectConfigComponent->value.aggregator.parent.typeName;
        data["GET_FUNC_NAME"] = projectConfigComponent->value.aggregator.getFuncName;
        data["FREE_FUNC_NAME"] = projectConfigComponent->value.aggregator.freeFuncName;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.impl.typeName;

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