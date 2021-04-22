/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;

void TReflectionSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mReflectionConfig->fileName + ".h");
    AddEmptyLine();

    auto namespaceName = mReflectionConfig->nameSpaceName;
    if ( namespaceName.length() )
        AddUsingNamespace(namespaceName);

    AddEmptyLine();

    auto defMap = fmt::format("std::map<std::string, {}::{}> {}::{};",
        mReflectionConfig->className, s_Data, mReflectionConfig->className, s_mTypeNameMap);
    Add(defMap);

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TReflectionSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TReflectionSourceFileGenerator::AddInit()
{
    std::list<std::string> paramList;
    AddMethodImplementationBegin(s_Void, mReflectionConfig->className, s_Init, paramList);
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

    /*for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto pTypeInfo = filenameType.second.get();

            auto t = pTypeInfo->GetTypeNameWithNameSpace();

            auto var = fmt::format("{}_{}", pTypeInfo->GetTypeNameWithNameSpaceAsVar(), s_Data);

            auto str = fmt::format("{} {};", s_Data, var);
            Add(str);
            str = fmt::format("{}.{} = \"{}\";", var, s_typeName, t);

            Add(str);

            str = fmt::format("{}.{} = [](){{ return new {}(); }};",
                var, s_newFunc, t);
            Add(str);

            str = fmt::format("{}.{}({{ {}.{}, {} }});", s_mTypeNameMap, s_Insert, var, s_typeName, var);
            Add(str);

            AddEmptyLine();
        }
    }*/

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TReflectionSourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList =
    {
        fmt::format("const std::string& {}", s_typeName),
    };

    std::string ret = s_Void + "*";
    AddMethodImplementationBegin(ret, mReflectionConfig->className, s_New, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}();", s_mTypeNameMap, s_typeName, s_newFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------