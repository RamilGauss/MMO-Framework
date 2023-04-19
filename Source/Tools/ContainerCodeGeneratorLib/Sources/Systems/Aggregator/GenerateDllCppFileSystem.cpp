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

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TGenerateDllCppFileSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ DLL_HEADER_FILE_NAME }}.h\""},
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

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.dllCppFileName);

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["DLL_HEADER_FILE_NAME"] = configComponent->value.aggregator.dllHeaderFileName;
        data["IMPL_FILE_NAME"] = configComponent->value.aggregator.impl.fileName;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["DLL_EXPORT_C"] = configComponent->value.aggregator.cExportDeclaration;
        data["PARENT_FILE_NAME"] = configComponent->value.aggregator.parent.typeName;
        data["GET_FUNC_NAME"] = configComponent->value.aggregator.getFuncName;
        data["FREE_FUNC_NAME"] = configComponent->value.aggregator.freeFuncName;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;
        data["IMPL_TYPE_NAME"] = configComponent->value.aggregator.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}