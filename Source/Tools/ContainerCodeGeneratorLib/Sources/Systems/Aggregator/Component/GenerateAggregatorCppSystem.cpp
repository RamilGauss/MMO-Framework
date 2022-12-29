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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.componentImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddLine(TConstants::GetHeader());
        txtGen.AddEmpty();
        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.impl.fileName + ".h");
        txtGen.AddEmpty();

        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.jsonImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.entMngImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.componentImpl.typeInfoImpl.impl.fileName + ".h");


        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        txtGen.AddCtorDef(configComponent->value.aggregator.componentImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("mJson = new {}();", configComponent->value.aggregator.componentImpl.jsonImpl.impl.typeName);
        txtGen.AddFormatLine("mEntMng = new {}();", configComponent->value.aggregator.componentImpl.entMngImpl.impl.typeName);
        txtGen.AddFormatLine("mTypeInfo = new {}();", configComponent->value.aggregator.componentImpl.typeInfoImpl.impl.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddLongLine();

        txtGen.AddDtorDef(configComponent->value.aggregator.componentImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddLine("delete mJson;");
        txtGen.AddLine("delete mEntMng;");
        txtGen.AddLine("delete mTypeInfo;");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}