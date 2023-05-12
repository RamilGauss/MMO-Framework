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

#include "Components/ConfigComponent.h"

#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsHandler::nsTypeFactory
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
            {1, "struct {{ DLL_EXPORT }} {{ IMPL_TYPE_NAME }} : public {{ CORE_NAMESPACE }}::{{ PARENT_TYPE_NAME }}"},
            {0, "{"},
            {1, "{{ IMPL_TYPE_NAME }}();"},
            {0, "virtual ~{{ IMPL_TYPE_NAME }}();"},
            {0, ""},
            {0, "void* New(int rtti) override;"},
            {0, "void Delete(void* p, int rtti) override;"},
            {-1,"};"},
            {-1,"}"},
            {0, ""},
        };

        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.handlerImpl.typeFactoryImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".h");

        nsBase::TTextGenerator txtGen(lines);

        inja::json data;

        data["PARENT_FILE_NAME"] = impl.parent.fileName;
        data["PROJECT_NAMESPACE"] = configComponent->value.projectConfig.nameSpace;
        data["DLL_EXPORT"] = configComponent->value.projectConfig.exportDeclaration;
        data["CORE_NAMESPACE"] = configComponent->value.coreConfig.nameSpace;
        data["PARENT_TYPE_NAME"] = impl.parent.typeName;
        data["IMPL_TYPE_NAME"] = impl.impl.typeName;

        txtGen.Apply(data);
        generatedFile.content = txtGen.Render();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}