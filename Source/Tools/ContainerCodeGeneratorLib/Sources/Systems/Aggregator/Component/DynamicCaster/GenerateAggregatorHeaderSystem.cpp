/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorHeaderSystem.h"

#include <fmt/core.h>

#include "Base/Common/TextGenerator.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "Constants.h"
#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"

#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsDynamicCaster
{
    void TGenerateAggregatorHeaderSystem::Execute()
    {
        std::list<nsBase::nsCommon::TLine> lines =
        {
            {0, "#pragma once"},
            {0, ""},
            {0, "#include \"{{ PARENT_FILE_NAME }}.h\""},
            {0, ""},
            {0, "namespace {{ PROJECT_NAMESPACE }}"},
            {0, "{"},
            {1, "struct {{ DLL_EXPORT }} {{ IMPL_TYPE_NAME }} : public {{ CORE_NAMESPACE }}::{{ PARENT_TYPE_NAME }}"},
            {0, "{"},
            {1, "{{ IMPL_TYPE_NAME }}();"},
            {0, "virtual ~{{ IMPL_TYPE_NAME }}();"},
            {0, ""},
            {0, "void Init() override;"},
            {0, "void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;"},
            {-1,"};"},
            {-1,"}"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = projectConfigComponent->value.aggregator.componentImpl.dynamicCasterImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".h");

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["PARENT_FILE_NAME"] = impl.parent.fileName;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        data["DLL_EXPORT"] = projectConfigComponent->value.projectConfig.exportDeclaration;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PARENT_TYPE_NAME"] = impl.parent.typeName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;

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