/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorHeaderSystem.h"

#include <fmt/core.h>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsHandler
{
    void TGenerateAggregatorHeaderSystem::Execute()
    {
        std::list<nsBase::TLine> lines =
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
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(projectConfigComponent->value.aggregator.targetDirectory,
            projectConfigComponent->value.aggregator.handlerImpl.impl.fileName + ".h");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["PARENT_FILE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.parent.fileName;
        data["PROJECT_NAMESPACE"] = projectConfigComponent->value.projectConfig.nameSpace;
        data["DLL_EXPORT"] = projectConfigComponent->value.projectConfig.exportDeclaration;
        data["CORE_NAMESPACE"] = coreConfigComponent->value.coreConfig.nameSpace;
        data["PARENT_TYPE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.parent.typeName;
        data["IMPL_TYPE_NAME"] = projectConfigComponent->value.aggregator.handlerImpl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}