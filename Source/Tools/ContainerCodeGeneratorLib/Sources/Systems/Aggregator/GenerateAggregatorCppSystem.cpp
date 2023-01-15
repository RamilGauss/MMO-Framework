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
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddInclude(configComponent->value.aggregator.impl.fileName + ".h");
        txtGen.AddEmpty();

        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.handlerImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.systemImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName + ".h");

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        txtGen.AddCtorDef(configComponent->value.aggregator.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("mComponents = new {}();", configComponent->value.aggregator.componentImpl.impl.typeName);
        txtGen.AddFormatLine("mHandlers = new {}();", configComponent->value.aggregator.handlerImpl.impl.typeName);
        txtGen.AddFormatLine("mSystems = new {}();", configComponent->value.aggregator.systemImpl.impl.typeName);
        txtGen.AddFormatLine("mImGuiWidgets = new {}();", configComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddLongLine();

        txtGen.AddDtorDef(configComponent->value.aggregator.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddLine("delete mComponents;");
        txtGen.AddLine("delete mHandlers;");
        txtGen.AddLine("delete mSystems;");
        txtGen.AddLine("delete mImGuiWidgets;");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}