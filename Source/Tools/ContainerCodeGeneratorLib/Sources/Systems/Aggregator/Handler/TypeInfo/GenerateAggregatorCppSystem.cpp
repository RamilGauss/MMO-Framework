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

namespace nsContainerCodeGenerator::nsAggregator::nsHandler::nsTypeInfo
{
    void TGenerateAggregatorCppSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        auto& impl = configComponent->value.aggregator.handlerImpl.typeInfoImpl;

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
        pathRelToProjectSources /= configComponent->value.projectConfig.handlerConfig.typeInfo.fileName + ".h";

        txtGen.AddInclude(pathRelToProjectSources.string());

        txtGen.AddEmpty();
        txtGen.AddUsingNamespace(configComponent->value.projectConfig.nameSpace);
        txtGen.AddEmpty();

        // Ctor
        txtGen.AddCtorDef(impl.impl.typeName);

        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("auto typeNameList = {}::GetTypeNameList();",
            configComponent->value.projectConfig.handlerConfig.typeInfo.typeName);
        txtGen.AddLine("mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());");
        txtGen.AddEmpty();

        txtGen.AddFormatLine("auto rttiList = {}::GetRttiList();",
            configComponent->value.projectConfig.handlerConfig.typeInfo.typeName);
        txtGen.AddLine("mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());");

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
        std::list<std::string> args = { "int rtti", "std::string& typeName" };

        txtGen.AddMethodDef(impl.impl.typeName, "ConvertTypeToName", "bool", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        txtGen.AddFormatLine("auto pTypeName = {}::ConvertRttiToName(rtti);",
            configComponent->value.projectConfig.handlerConfig.typeInfo.typeName);

        txtGen.AddLine("if (pTypeName != nullptr) {");
        txtGen.IncrementTabs();
        txtGen.AddLine("typeName = *pTypeName;");
        txtGen.AddRet("true");
        txtGen.DecrementTabs();
        txtGen.AddRight();

        txtGen.AddRet("false");

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        // ConvertNameToType
        args = { "const std::string& typeName", "int& rtti" };

        txtGen.AddMethodDef(impl.impl.typeName, "ConvertNameToType", "bool", args);
        txtGen.AddLeft();
        txtGen.IncrementTabs();

        auto cnvrtNameRet = fmt::format("{}::ConvertNameToRtti(typeName, rtti);",
            configComponent->value.projectConfig.handlerConfig.typeInfo.typeName);

        txtGen.AddRet(cnvrtNameRet);

        txtGen.DecrementTabs();
        txtGen.AddRight();
        txtGen.AddLongLine();

        generatedFilesComponent->value.push_back(generatedFile);
    }
}