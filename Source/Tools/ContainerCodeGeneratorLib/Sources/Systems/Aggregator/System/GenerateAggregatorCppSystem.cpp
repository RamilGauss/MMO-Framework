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

namespace nsContainerCodeGenerator::nsAggregator::nsSystem
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            configComponent->value.aggregator.systemImpl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddInclude(configComponent->value.aggregator.systemImpl.impl.fileName + ".h");
        txtGen.AddEmpty();

        txtGen.AddInclude(configComponent->value.aggregator.systemImpl.typeFactoryImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.systemImpl.dynamicCasterImpl.impl.fileName + ".h");
        txtGen.AddInclude(configComponent->value.aggregator.systemImpl.typeInfoImpl.impl.fileName + ".h");


        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        txtGen.AddCtorDef(configComponent->value.aggregator.systemImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("mTypeFactory = new {}();", configComponent->value.aggregator.systemImpl.typeFactoryImpl.impl.typeName);
        txtGen.AddFormatLine("mDynamicCaster = new {}();", configComponent->value.aggregator.systemImpl.dynamicCasterImpl.impl.typeName);
        txtGen.AddFormatLine("mTypeInfo = new {}();", configComponent->value.aggregator.systemImpl.typeInfoImpl.impl.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddLongLine();

        txtGen.AddDtorDef(configComponent->value.aggregator.systemImpl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddLine("delete mTypeFactory;");
        txtGen.AddLine("delete mDynamicCaster;");
        txtGen.AddLine("delete mTypeInfo;");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}