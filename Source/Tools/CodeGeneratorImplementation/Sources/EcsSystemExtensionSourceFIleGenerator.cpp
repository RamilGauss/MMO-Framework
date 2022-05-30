/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EcsSystemExtensionSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsCodeGeneratorImplementation;

void TEcsSystemExtensionSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddInclude("SingletonManager.h");
    AddInclude("RunTimeTypeIndex.h");

    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if ( namespaceName.length() )
        AddUsingNamespace(namespaceName);

    AddEmptyLine();

    auto defVector = fmt::format("std::vector<{}::{}> {}::{};",
        mSerializer->className, s_Data, mSerializer->className, s_mDataVector);
    Add(defVector);

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsSystemExtensionSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsSystemExtensionSourceFileGenerator::AddInit()
{
    std::list<std::string> paramList;
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_Init, paramList);
    AddLeftBrace();
    IncrementTabs();

    Add("static bool isNeedInit = true;");
    Add("if ( !isNeedInit )");
    AddLeftBrace();
    IncrementTabs();
    Add("return;");
    DecrementTabs();
    AddRightBrace();

    Add("isNeedInit = false;");
    AddEmptyLine();

    Add("auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();");
    AddEmptyLine();

    auto str = fmt::format("std::map<int, {}> m;", s_Data);
    Add(str);
    AddEmptyLine();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();

    for ( auto& type : forGen) {
        auto pTypeInfo = mTypeManager->Get(type.GetFullType());

        auto t = pTypeInfo->GetTypeNameWithNameSpace();

        auto var = fmt::format("{}_{}", pTypeInfo->GetTypeNameWithNameSpaceAsVar(), s_Data);

        auto str = fmt::format("{} {};", s_Data, var);
        Add(str);

        str = fmt::format("{}.{} = [](void* p){{ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<{}*>(p)); }};",
            var, s_castFunc, t);
        Add(str);

        auto typeNameWithNameSpace = pTypeInfo->GetTypeNameWithNameSpace();

        str = fmt::format("auto rtti_{} = globalTypeIdentifier->Type<{}>();", var, typeNameWithNameSpace);
        Add(str);
        AddEmptyLine();

        str = fmt::format("m.insert({{ rtti_{}, {} }});", var, var);
        Add(str);

        AddEmptyLine();
    }

    Add("int max = 0;");
    str = fmt::format("for (auto& vt : m) {{");
    Add(str);
    IncrementTabs();

    Add("max = std::max(vt.first, max);");
    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    str = fmt::format("{}.resize(max + 1);", s_mDataVector);
    Add(str);
    str = fmt::format("for (auto& vt : m) {{");
    Add(str);
    IncrementTabs();
    str = fmt::format("{}[vt.first] = vt.second;", s_mDataVector);
    Add(str);
    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsSystemExtensionSourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList =
    {
        "void* p", 
        fmt::format("int {}", s_rtti),
    };

    std::string ret = "nsECSFramework::TSystem*";
    AddMethodImplementationBegin(ret, mSerializer->className, s_DynamicCast, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}(p);", s_mDataVector, s_rtti, s_castFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------