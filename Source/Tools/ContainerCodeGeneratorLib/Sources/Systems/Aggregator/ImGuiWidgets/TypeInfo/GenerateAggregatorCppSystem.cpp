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

namespace nsContainerCodeGenerator::nsAggregator::nsImGuiWidgets::nsTypeInfo
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.imGuiWidgetsImpl.typeInfoImpl;

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

        std::filesystem::path pathRelToCoreSources(relToCoreSources);
        pathRelToCoreSources /= configComponent->value.coreConfig.imGuiWidgetsConfig.typeInfo.fileName + ".h";

        txtGen.AddInclude(pathRelToCoreSources.string());

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        // Ctor
        txtGen.AddCtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        std::list<std::string> lines =
        {
            "auto typeNameList = %CoreNameSpace%::%CoreTypeName%::GetTypeNameList();",
            "mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());",
            "",
            "auto rttiList = %CoreNameSpace%::%CoreTypeName%::GetRttiList();",
            "mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());"
        };

        std::map<std::string, std::string> args =
        {
            {"CoreNameSpace", configComponent->value.coreConfig.nameSpace},
            {"CoreTypeName", configComponent->value.coreConfig.imGuiWidgetsConfig.typeInfo.typeName}
        };

        txtGen.AddFormatted(lines, args);

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

        // GetTypeNameList
        txtGen.AddMethodDef(impl.impl.typeName, "GetTypeNameList", "const std::list<std::string>*", {});
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddRet("&mTypeNameList");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // GetRunTimeTypeIndexList
        txtGen.AddMethodDef(impl.impl.typeName, "GetRunTimeTypeIndexList", "const std::list<int>*", {});
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddRet("&mRttiList");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // ConvertTypeToName
        std::list<std::string> methodArgs = { "int rtti", "std::string& typeName" };

        txtGen.AddMethodDef(impl.impl.typeName, "ConvertTypeToName", "bool", methodArgs);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        lines =
        {
            "auto pTypeName = %CoreNameSpace%::%CoreTypeName%::ConvertRttiToName(rtti);",
            "if (pTypeName != nullptr) {",
            "    typeName = *pTypeName;",
            "    return true;",
            "}",
            "return false;"
        };

        txtGen.AddFormatted(lines, args);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // ConvertNameToType
        methodArgs = { "const std::string& typeName", "int& rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "ConvertNameToType", "bool", methodArgs);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        lines =
        {
            "return %CoreNameSpace%::%CoreTypeName%::ConvertNameToRtti(typeName, rtti);"
        };

        txtGen.AddFormatted(lines, args);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}