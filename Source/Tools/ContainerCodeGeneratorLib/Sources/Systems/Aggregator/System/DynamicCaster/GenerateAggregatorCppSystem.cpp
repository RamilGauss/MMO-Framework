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

namespace nsContainerCodeGenerator::nsAggregator::nsSystem::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.systemImpl.dynamicCasterImpl;

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
        pathRelToProjectSources /= configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.fileName + ".h";

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

        // Cast
        std::list<std::string> args = { "int srcRtti", "void* srcPtr", "int dstRtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "Cast", "void*", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("auto& m = {}::GetRttiCombinations();", 
            configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.typeName);
        txtGen.AddEmpty();

        txtGen.AddLine("auto fit = m.find(srcRtti);");
        txtGen.AddLine("auto notFound = (fit == m.end());");
        txtGen.AddLine("if (notFound) {");
        txtGen.IncrementTabs();
        txtGen.AddRet("nullptr");
        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddLine("notFound = (fit->second.find(dstRtti) == fit->second.end());");
        txtGen.AddLine("if (notFound) {");
        txtGen.IncrementTabs();
        txtGen.AddRet("nullptr");
        txtGen.DecrementTabs();
        txtGen.AddRight();

        auto newRet = fmt::format("{}::Cast(srcRtti, srcPtr, dstRtti)", 
            configComponent->value.projectConfig.ecsSystemConfig.dynamicCaster.typeName);
        txtGen.AddRet(newRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}