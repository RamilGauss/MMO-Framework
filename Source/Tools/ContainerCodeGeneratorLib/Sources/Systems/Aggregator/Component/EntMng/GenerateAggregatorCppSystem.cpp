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

namespace nsContainerCodeGenerator::nsAggregator::nsComponent::nsEntMng
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.componentImpl.entMngImpl;

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
        pathRelToProjectSources /= configComponent->value.projectConfig.componentConfig.entMng.fileName + ".h";

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.coreConfig.componentConfig.entMng.fileName + ".h";

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

        // CreateComponent
        std::list<std::string> args = 
        { 
            "nsECSFramework::TEntityID eid",
            "int rtti",
            "std::function<void(void*)> onAfterCreation",
            "bool isNotify" 
        };

        txtGen.AddMethodDef(impl.impl.typeName, "CreateComponent", "void", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::CreateComponent(mEntMng, eid, rtti, onAfterCreation, isNotify);", 
            configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{", 
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::{}::CreateComponent(mEntMng, eid, rtti, onAfterCreation, isNotify);",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");
        
        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // SetComponent
        args = 
        { 
            "nsECSFramework::TEntityID eid",
            "int rtti",
            "void* p",
            "bool isNotify" 
        };

        txtGen.AddMethodDef(impl.impl.typeName, "SetComponent", "void", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::SetComponent(mEntMng, eid, rtti, p, isNotify);",
            configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::{}::SetComponent(mEntMng, eid, rtti, p, isNotify);",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // ViewComponent
        args = { "nsECSFramework::TEntityID eid", "int rtti"};

        txtGen.AddMethodDef(impl.impl.typeName, "ViewComponent", "const void*", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        auto viewRet = fmt::format("{}::ViewComponent(mEntMng, eid, rtti)",
            configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.AddRet(viewRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        viewRet = fmt::format("{}::{}::ViewComponent(mEntMng, eid, rtti)",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.AddRet(viewRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddRet("nullptr");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // HasComponent
        args = { "nsECSFramework::TEntityID eid", "int rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "HasComponent", "bool", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        auto hasRet = fmt::format("{}::HasComponent(mEntMng, eid, rtti)",
            configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.AddRet(hasRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        hasRet = fmt::format("{}::{}::HasComponent(mEntMng, eid, rtti)",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.AddRet(hasRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddRet("false");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // RemoveComponent
        args = { "nsECSFramework::TEntityID eid", "int rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "RemoveComponent", "void", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("if ({}::Has(rtti)) {{", configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::RemoveComponent(mEntMng, eid, rtti);",
            configComponent->value.projectConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddFormatLine("if ({}::{}::Has(rtti)) {{",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("{}::{}::RemoveComponent(mEntMng, eid, rtti);",
            configComponent->value.coreConfig.nameSpace,
            configComponent->value.coreConfig.componentConfig.entMng.typeName);
        txtGen.AddRet("");

        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}