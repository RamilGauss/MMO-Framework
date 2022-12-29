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

namespace nsContainerCodeGenerator::nsAggregator::nsSystem::nsDynamicCaster
{
    void TGenerateAggregatorHeaderSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.systemImpl.dynamicCasterImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".h");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddPragmaOnce();
        txtGen.AddEmpty();
        txtGen.AddInclude(impl.parent.fileName + ".h");
        txtGen.AddEmpty();
        txtGen.AddNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        auto type = fmt::format("{} {}", configComponent->value.projectConfig.exportDeclaration,
            impl.impl.typeName);

        auto parent = fmt::format("public {}::{}",
            configComponent->value.coreConfig.nameSpace, impl.parent.typeName);

        txtGen.AddStruct(type, { parent });
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddCtorDecl(impl.impl.typeName);
        txtGen.AddVirtualDtorDecl(impl.impl.typeName);
        txtGen.AddEmpty();

        txtGen.AddMethodDecl("Cast", "void*", { "int srcRtti", "void* srcPtr", "int dstRtti" }, " override");

        txtGen.DecrementTabs();
        txtGen.AddRight(true);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}