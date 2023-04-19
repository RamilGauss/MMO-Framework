/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            { 0, "#include \"{{ IMPL_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "#include \"{{ COMPONENT_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ HANDLER_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ SYSTEM_FILE_NAME }}.h\"" },
            { 0, "#include \"{{ IMGUI_WIDGETS_FILE_NAME }}.h\"" },
            { 0, "" },
            { 0, "using namespace {{ PROJECT_NAMESPACE }};" },
            { 0, "" },
            { 0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 1, "mComponents = new {{ COMPONENT_TYPE_NAME }}();" },
            { 0, "mHandlers = new {{ HANDLER_TYPE_NAME }}();" },
            { 0, "mSystems = new {{ SYSTEM_TYPE_NAME }}();" },
            { 0, "mImGuiWidgets = new {{ IMGUI_WIDGETS_TYPE_NAME }}();" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()" },
            { 0, "{" },
            { 1, "delete mComponents;" },
            { 0, "delete mHandlers;" },
            { 0, "delete mSystems;" },
            { 0, "delete mImGuiWidgets;" },
            { -1,"}" },
            { 0, "//--------------------------------------------------------------------------------------------------" },
            { 0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["IMPL_FILE_NAME"] = configComponent->value.aggregator.impl.fileName;
        data["COMPONENT_FILE_NAME"] = configComponent->value.aggregator.componentImpl.impl.fileName;
        data["HANDLER_FILE_NAME"] = configComponent->value.aggregator.handlerImpl.impl.fileName;
        data["SYSTEM_FILE_NAME"] = configComponent->value.aggregator.systemImpl.impl.fileName;
        data["IMGUI_WIDGETS_FILE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;
        data["IMPL_TYPE_NAME"] = configComponent->value.aggregator.impl.typeName;
        data["COMPONENT_TYPE_NAME"] = configComponent->value.aggregator.componentImpl.impl.typeName;
        data["HANDLER_TYPE_NAME"] = configComponent->value.aggregator.handlerImpl.impl.typeName;
        data["SYSTEM_TYPE_NAME"] = configComponent->value.aggregator.systemImpl.impl.typeName;
        data["IMGUI_WIDGETS_TYPE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}