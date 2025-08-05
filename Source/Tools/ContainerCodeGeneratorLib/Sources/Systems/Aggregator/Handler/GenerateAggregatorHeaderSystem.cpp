/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "Base/Common/TextGenerator.h"
#include "Base/Common/PathOperations.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/GeneratedFilesComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/GenerateAggregatorHeaderSystem.h"

namespace nsContainerCodeGenerator::nsAggregator::nsHandler
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
            {0, "    struct {{ DLL_EXPORT }} {{ IMPL_TYPE_NAME }} : public {{ CORE_NAMESPACE }}::{{ PARENT_TYPE_NAME }}"},
            {0, "    {"},
            {0, "        {{ IMPL_TYPE_NAME }}();"},
            {0, "        virtual ~{{ IMPL_TYPE_NAME }}();"},
            {0, "    };"},
            {0, "}"},
            {0, ""},
        };

        auto coreConfigComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::nsCommon::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.handlerImpl.impl.fileName + ".h");

        nsBase::nsCommon::TTextGenerator txtGen(lines);

        inja::json data;

        data["PARENT_FILE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.parent.fileName;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        data["DLL_EXPORT"] = projectConfigComponent->value.projectConfig.exportDeclaration;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PARENT_TYPE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.parent.typeName;
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.impl.typeName;

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