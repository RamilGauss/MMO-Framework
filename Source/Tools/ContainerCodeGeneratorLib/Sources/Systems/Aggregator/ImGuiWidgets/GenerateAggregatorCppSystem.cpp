/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include "Base/Common/TextGenerator.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        std::list<nsBase::nsCommon::TLine> lines =
        {
            {0, "#include \"{{ IMPL_FILE_NAME }}.h\""},
            {0, ""},
            {0, "#include \"{{ DYNAMIC_CASTER_FILE_NAME }}.h\""},
            {0, "#include \"{{ RTTI_FILE_NAME }}.h\""},
            {0, ""},
            {0, "using namespace {{ PROJECT_NAMESPACE }};"},
            {0, ""},
            {0, "{{ IMPL_TYPE_NAME }}::{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "mRtti = new {{ RTTI_TYPE_NAME }}();"},
            {0, "mDynamicCaster = new {{ DYNAMIC_CASTER_TYPE_NAME }}();"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, "{{ IMPL_TYPE_NAME }}::~{{ IMPL_TYPE_NAME }}()"},
            {0, "{"},
            {1, "delete mRtti;"},
            {0, "delete mDynamicCaster;"},
            {-1,"}"},
            {0, "//--------------------------------------------------------------------------------------------------"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName + ".cpp");

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        
        data["IMPL_FILE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName;
        data["DYNAMIC_CASTER_FILE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.fileName;
        data["RTTI_FILE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.rttiImpl.impl.fileName;
        
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName;
        data["DYNAMIC_CASTER_TYPE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.typeName;
        data["RTTI_TYPE_NAME"] = projectConfigComponent->value.aggregator.imGuiWidgetsImpl.rttiImpl.impl.typeName;

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