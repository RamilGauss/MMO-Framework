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

using namespace nsCodeGeneratorImplementation;
using namespace nsCppParser;

void TTypeInformationSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddEmptyLine();

    AddInclude("SingletonManager.h");
    AddInclude("RunTimeTypeIndex.h");

    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if ( namespaceName.length() )
        AddUsingNamespace(namespaceName);

    AddEmptyLine();

    std::string str;
    str = fmt::format("std::list<std::string> {}::{};", mSerializer->className, s_mTypeNameList);
    Add(str);
    str = fmt::format("std::list<int> {}::{};", mSerializer->className, s_mRttiList);
    Add(str);

    AddEmptyLine();

    str = fmt::format("std::vector<std::string> {}::{};", mSerializer->className, s_mNameVector);
    Add(str);
    str = fmt::format("std::unordered_map<std::string, int> {}::{};", mSerializer->className, s_mNameRttiMap);
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
    Add("if (!isNeedInit) {");
    IncrementTabs();
    Add("return;");
    DecrementTabs();
    AddRightBrace();

    Add("isNeedInit = false;");
    AddEmptyLine();

    std::string globalTypeIdentifier = "globalTypeIdentifier";

    auto str = fmt::format("auto {} = SingletonManager()->Get<TRunTimeTypeIndex<>>();", globalTypeIdentifier);
    Add(str);

    AddEmptyLine();

    auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
    for (auto& type : forGenerate) {
        auto pTypeInfo = mTypeManager->Get(type.GetFullType());

        if (pTypeInfo->mTemplateArgs.size() > 0) {
            continue;
        }

        auto t = pTypeInfo->GetTypeNameWithNameSpace();

        auto rtti = fmt::format("{}_i", pTypeInfo->GetTypeNameWithNameSpaceAsVar());
        auto typeName = fmt::format("{}_n", pTypeInfo->GetTypeNameWithNameSpaceAsVar());


        str = fmt::format("int {} = {}->Type<{}>();", rtti, globalTypeIdentifier, t);
        Add(str);
        str = fmt::format("std::string {} = \"{}\";", typeName, t);
        Add(str);

        str = fmt::format("{}.push_back({});", s_mTypeNameList, typeName);
        Add(str);

        str = fmt::format("{}.push_back({});", s_mRttiList, rtti);
        Add(str);

        str = fmt::format("{}.insert({{ {}, {} }});", s_mNameRttiMap, typeName, rtti);
        Add(str);

        AddEmptyLine();
    }

    str = fmt::format("int max = 0;");
    Add(str);

    str = fmt::format("for (auto& nameRtti : {}) {{", s_mNameRttiMap);
    Add(str);

    IncrementTabs();

    str = fmt::format("max = std::max(max, nameRtti.second);", s_mNameRttiMap);
    Add(str);

    DecrementTabs();
    AddRightBrace();

    str = fmt::format("{}.resize(max + 1);", s_mNameVector);
    Add(str);

    str = fmt::format("for (auto& nameRtti : {}) {{", s_mNameRttiMap);
    Add(str);

    IncrementTabs();

    str = fmt::format("{}[nameRtti.second] = nameRtti.first;", s_mNameVector);
    Add(str);

    DecrementTabs();
    AddRightBrace();

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
    paramList = 
    {
    };
    ret = "const std::list<int>*";

    AddMethodImplementationBegin(ret, mSerializer->className, s_GetRttiList, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return &{};", s_mRttiList);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
    paramList =
    {
        fmt::format("int {}", s_rtti),
    };
    ret = "const std::string*";

    AddMethodImplementationBegin(ret, mSerializer->className, s_ConvertTypeToName, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    AddEmptyLine();
    str = fmt::format("if (rtti < 0 || rtti >= {}.size()) {{", s_mNameVector);
    Add(str);
    Add("    return nullptr;");
    AddRightBrace();
    str = fmt::format("auto pStr = &({}[{}]);", s_mNameVector, s_rtti);
    Add(str);
    Add("if (pStr->size() == 0) {");
    Add("    return nullptr;");
    AddRightBrace();
    Add("return pStr;");

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
    paramList =
    {
        fmt::format("const std::string& {}", s_typeName),
        fmt::format("int& {}", s_rtti)
    };
    ret = s_Bool;

    AddMethodImplementationBegin(ret, mSerializer->className, s_ConvertNameToType, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("auto fit = {}.find({});", s_mNameRttiMap, s_typeName);
    Add(str);
    str = fmt::format("if (fit == {}.end()) {{", s_mNameRttiMap);
    Add(str);
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();

    Add(fmt::format("{} = fit->second;", s_rtti));
    Add("return true;");

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
