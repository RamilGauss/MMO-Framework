/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeInformationSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;
using namespace nsCppParser;

void TTypeInformationSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddEmptyLine();

    AddInclude("SingletonManager.h");
    AddInclude("TypeIdentifier.h");

    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if ( namespaceName.length() )
        AddUsingNamespace(namespaceName);

    AddEmptyLine();

    std::string str;
    str = fmt::format("std::list<std::string> {}::{};", mSerializer->className, s_mTypeNameList);
    Add(str);
    str = fmt::format("std::list<int> {}::{};", mSerializer->className, s_mTypeIdentifierList);
    Add(str);

    AddEmptyLine();

    str = fmt::format("std::map<int, std::string> {}::{};", mSerializer->className, s_mIdentifierNameMap);
    Add(str);
    str = fmt::format("std::map<std::string, int> {}::{};", mSerializer->className, s_mNameIdentifierMap);
    Add(str);

    AddEmptyLine();

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeInformationSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeInformationSourceFileGenerator::AddInit()
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

    std::string globalTypeIdentifier = "globalTypeIdentifier";

    auto str = fmt::format("auto {} = SingletonManager()->Get<TTypeIdentifier<>>();", globalTypeIdentifier);
    Add(str);

    AddEmptyLine();

    auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
    for (auto& type : forGenerate) {
        auto pTypeInfo = mTypeManager->Get(type.GetFullType());

        auto t = pTypeInfo->GetTypeNameWithNameSpace();

        auto identifier = fmt::format("{}_i", pTypeInfo->GetTypeNameWithNameSpaceAsVar());
        auto typeName = fmt::format("{}_n", pTypeInfo->GetTypeNameWithNameSpaceAsVar());


        str = fmt::format("int {} = {}->type<{}>();", identifier, globalTypeIdentifier, t);
        Add(str);
        str = fmt::format("std::string {} = \"{}\";", typeName, t);
        Add(str);

        str = fmt::format("{}.push_back({});", s_mTypeIdentifierList, identifier);
        Add(str);
        str = fmt::format("{}.push_back({});", s_mTypeNameList, typeName);
        Add(str);

        str = fmt::format("{}.insert({{ _TFloat3Identifier, _TFloat3Name }});", s_mIdentifierNameMap, identifier, typeName);
        Add(str);
        str = fmt::format("{}.insert({{ _TFloat3Name, _TFloat3Identifier }});", s_mNameIdentifierMap, typeName, identifier);
        Add(str);

        AddEmptyLine();
    }

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeInformationSourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList;
    std::string ret = "const std::list<std::string>*";

    AddMethodImplementationBegin(ret, mSerializer->className, s_GetTypeNameList, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return &{};", s_mTypeNameList);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
    ret = "const std::list<int>*";

    AddMethodImplementationBegin(ret, mSerializer->className, s_GetTypeIdentifierList, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return &{};", s_mTypeIdentifierList);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
    paramList = 
    {
        fmt::format("int {}", s_typeIdentifier),
        fmt::format("std::string& {}", s_typeName)
    };
    ret = s_Bool;

    AddMethodImplementationBegin(ret, mSerializer->className, s_ConvertTypeToName, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("auto fit = {}.find({});", s_mIdentifierNameMap, s_typeIdentifier);
    Add(str);
    str = fmt::format("if ( fit == {}.end() ) {{", s_mIdentifierNameMap);
    Add(str);
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();
    str = fmt::format("{} = fit->second;", s_typeName);
    Add(str);
    Add("return true;");

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
    paramList =
    {
        fmt::format("const std::string& {}", s_typeName),
        fmt::format("int& {}", s_typeIdentifier)
    };
    ret = s_Bool;

    AddMethodImplementationBegin(ret, mSerializer->className, s_ConvertNameToType, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("auto fit = {}.find({});", s_mNameIdentifierMap, s_typeName);
    Add(str);
    str = fmt::format("if ( fit == {}.end() ) {{", s_mNameIdentifierMap);
    Add(str);
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();

    Add("return true;");

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
