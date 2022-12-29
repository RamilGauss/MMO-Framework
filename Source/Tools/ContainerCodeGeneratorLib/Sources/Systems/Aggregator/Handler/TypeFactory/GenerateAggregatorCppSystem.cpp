/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateAggregatorCppSystem.h"

#include <fmt/core.h>

#include <filesystem>

#include <TextGenerator.h>
#include <PathOperations.h>

#include <ECS/include/Helper.h>

#include "Constants.h"

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator::nsHandler::nsTypeFactory
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.handlerImpl.typeFactoryImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

        txtGen.AddLine(TConstants::GetHeader());
        txtGen.AddEmpty();
        txtGen.AddInclude(impl.impl.fileName + ".h");
        txtGen.AddEmpty();

        auto absBase = configComponent->value.projectConfig.pathToCore;
        auto abs = configComponent->value.coreConfig.targetDirectory;

        std::string relToCoreSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToCoreSources);

        absBase = configComponent->value.projectConfig.absPathToProject;
        abs = configComponent->value.projectConfig.targetDirectory;

        std::string relToProjectSources;
        nsBase::TPathOperations::GetRelativePath(absBase, abs, relToProjectSources);

        std::filesystem::path pathRelToProjectSources(relToProjectSources);
        pathRelToProjectSources /= configComponent->value.projectConfig.handlerConfig.typeFactory.fileName + ".h";

        txtGen.AddInclude(pathRelToProjectSources.string());

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        // Ctor
        txtGen.AddCtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddEmpty();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // Dtor
        txtGen.AddDtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddEmpty();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // New
        std::list<std::string> args = { "int rtti"};

        txtGen.AddMethodDef(impl.impl.typeName, "New", "void*", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("auto has = {}::Has(rtti);",
            configComponent->value.projectConfig.handlerConfig.typeFactory.typeName);

        txtGen.AddLine("if (has) {");
        txtGen.IncrementTabs();
        auto newRet = fmt::format("{}::New(rtti)", configComponent->value.projectConfig.handlerConfig.typeFactory.typeName);
        txtGen.AddRet(newRet);
        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddRet("nullptr");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // Delete
        args = { "void* p", "int rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "Delete", "void", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("auto has = {}::Has(rtti);",
            configComponent->value.projectConfig.handlerConfig.typeFactory.typeName);

        txtGen.AddLine("if (has) {");
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::Delete(p, rtti);", configComponent->value.projectConfig.handlerConfig.typeFactory.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}