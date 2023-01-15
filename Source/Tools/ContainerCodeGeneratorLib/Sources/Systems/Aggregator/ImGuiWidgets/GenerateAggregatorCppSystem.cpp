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
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddInclude(configComponent->value.aggregator.imGuiWidgetsImpl.impl.fileName + ".h");
        txtGen.AddEmpty();

        txtGen.AddInclude(configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.fileName + ".h");

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        txtGen.AddCtorDef(configComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("mTypeInfo = new {}();", configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl.impl.typeName);
        txtGen.AddFormatLine("mDynamicCaster = new {}();", configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl.impl.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddLongLine();

        txtGen.AddDtorDef(configComponent->value.aggregator.imGuiWidgetsImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddLine("delete mTypeInfo;");
        txtGen.AddLine("delete mDynamicCaster;");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}