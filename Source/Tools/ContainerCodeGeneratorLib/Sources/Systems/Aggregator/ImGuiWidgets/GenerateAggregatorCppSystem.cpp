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

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ DYNAMIC_CASTER_FILE_NAME }}.h\""},
            {0, "#include \"{{ TYPE_INFO_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "mTypeInfo = new {{ TYPE_INFO_TYPE_NAME }}();"},
            {0, "mDynamicCaster = new {{ DYNAMIC_CASTER_TYPE_NAME }}();"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "delete mTypeInfo;"},
            {0, "delete mDynamicCaster;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;
        
        data["IMPL_FILE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName;
        data["DYNAMIC_CASTER_FILE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.fileName;
        data["TYPE_INFO_FILE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl.impl.fileName;
        
        data["IMPL_TYPE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName;
        data["DYNAMIC_CASTER_TYPE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.typeName;
        data["TYPE_INFO_TYPE_NAME"] = configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}