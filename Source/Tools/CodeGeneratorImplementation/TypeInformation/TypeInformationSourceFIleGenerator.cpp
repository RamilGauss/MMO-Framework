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
    str = fmt::format("std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> {}::{};", mSerializer->className, s_mTypeInfoVector),
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

   /* auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
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
    Add(str);*/

    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeInformationSourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList =
    {
        fmt::format("int {}", s_rtti),
    };

    std::string ret = "const nsCppParser::TTypeInfo*";

    AddMethodImplementationBegin(ret, mSerializer->className, s_Get, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].get();", s_mTypeInfoVector, s_rtti);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //=============================================================
}
//-----------------------------------------------------------------------------------------------------------
