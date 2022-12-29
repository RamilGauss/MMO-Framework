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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsJson
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.componentImpl.jsonImpl;

        TGeneratedFile generatedFile;
        generatedFile.absPath = nsBase::TPathOperations::CalculatePathBy(configComponent->value.aggregator.targetDirectory,
            impl.impl.fileName + ".cpp");

        nsBase::TTextGenerator txtGen(generatedFile.content);

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
        pathRelToProjectSources /= configComponent->value.projectConfig.componentConfig.json.fileName + ".h";

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.coreConfig.componentConfig.json.fileName + ".h";

        txtGen.AddInclude(pathRelToProjectSources.string());
        txtGen.AddInclude(pathRelToCoreSources.string());

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        txtGen.AddCtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddEmpty();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        txtGen.AddDtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddEmpty();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // Serialize
        std::list<std::string> args = { "void* p",
                "std::string& json",
                "int rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "Serialize", "void", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.json.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::Serialize(p, json, rtti);",
            configComponent->value.projectConfig.componentConfig.json.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.json.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::{}::Serialize(p, json, rtti);",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.json.typeName);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // Deserialize
        args = { "void* p",
            "const std::string& json",
            "int rtti",
            "std::string& err" };

        txtGen.AddMethodDef(impl.impl.typeName, "Deserialize", "bool", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.json.typeName);
        txtGen.IncrementTabs();

        auto deserializeRet = fmt::format("{}::Deserialize(p, json, rtti, err);",
            configComponent->value.projectConfig.componentConfig.json.typeName);
        txtGen.AddRet(deserializeRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.json.typeName);
        txtGen.IncrementTabs();

        deserializeRet = fmt::format("{}::{}::Deserialize(p, json, rtti, err);",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.json.typeName);
        txtGen.AddRet(deserializeRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddRet("false");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}