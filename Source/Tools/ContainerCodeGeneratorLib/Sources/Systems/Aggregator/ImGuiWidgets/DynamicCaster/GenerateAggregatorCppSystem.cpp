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

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets::nsDynamicCaster
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.imGuiWidgetsImpl.dynamicCasterImpl;

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

        std::filesystem::path pathRelToProjectSources(relToCoreSources);
        pathRelToProjectSources /= configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.fileName + ".h";

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

        std::list<std::string> lines =
        {
            "auto& coreM = %CoreNameSpace%::%CoreType%::GetRttiCombinations();",
            "",
            "auto coreFit = coreM.find(srcRtti);",
            "auto isFound = (coreFit != coreM.end());",
            "if (isFound) {",
            "    isFound = (coreFit->second.find(dstRtti) != coreFit->second.end());",
            "    if (isFound) {",
            "        return %CoreNameSpace%::%CoreType%::Cast(srcRtti, srcPtr, dstRtti);",
            "    }",
            "}",
            "return nullptr;"
        };

        std::map<std::string, std::string> namedArgs =
        {
            {"CoreType", configComponent->value.coreConfig.imGuiWidgetsConfig.dynamicCaster.typeName},
            {"CoreNameSpace", configComponent->value.coreConfig.nameSpace}
        };

        txtGen.AddFormatted(lines, namedArgs);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}