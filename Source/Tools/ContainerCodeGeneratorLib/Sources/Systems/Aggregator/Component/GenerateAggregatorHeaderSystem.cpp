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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent
{
    void TGenerateAggregatorHeaderSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.componentImpl.impl.fileName + ".h");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddPragmaOnce();
        txtGen.AddEmpty();
        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.parent.fileName + ".h");
        txtGen.AddEmpty();
        txtGen.AddNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        auto type = fmt::format("{} {}", configComponent->value.projectConfig.exportDeclaration,
            configComponent->value.aggregator.componentImpl.impl.typeName);

        auto parent = fmt::format("public {}::{}", 
            configComponent->value.coreConfig.nameSpace, configComponent->value.aggregator.componentImpl.parent.typeName);

        txtGen.AddStruct(type, { parent });
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddCtorDecl(configComponent->value.aggregator.componentImpl.impl.typeName);
        txtGen.AddVirtualDtorDecl(configComponent->value.aggregator.componentImpl.impl.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight(true);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}