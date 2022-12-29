/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateDllCppFileSystem.h"

#include <fmt/core.h>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TGenerateDllCppFileSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory, 
            configComponent->value.aggregator.dllCppFileName);

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddInclude(configComponent->value.aggregator.dllHeaderFileName);
        txtGen.AddInclude(configComponent->value.aggregator.impl.fileName + ".h");
        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.coreConfig.nameSpace);
        txtGen.AddEmpty();

        auto getFuncRet = fmt::format("{} {}*", configComponent->value.aggregator.cExportDeclaration,
            configComponent->value.aggregator.parent.typeName);

        txtGen.AddFuncDef(configComponent->value.aggregator.getFuncName, getFuncRet);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        auto retStr = fmt::format("new {}::{}()", configComponent->value.projectConfig.nameSpace,
            configComponent->value.aggregator.impl.typeName);
        txtGen.AddRet(retStr);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        auto arg = fmt::format("{}* p", configComponent->value.aggregator.parent.typeName);

        auto freeFuncRet = fmt::format("{} void", configComponent->value.aggregator.cExportDeclaration);

        txtGen.AddFuncDef(configComponent->value.aggregator.freeFuncName, freeFuncRet, { arg });
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddLine("delete p;");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}