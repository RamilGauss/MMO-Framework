/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <algorithm>

#include "EntityManagerSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsCodeGeneratorImplementation;

void TEntityManagerSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if ( namespaceName.length() )
        AddUsingNamespace(namespaceName);

    AddUsingNamespace(s_nsECSFramework);
    AddEmptyLine();

    auto defMap = fmt::format("std::map<std::string, {}::{}> {}::{};",
        mSerializer->className, s_Data, mSerializer->className, s_mTypeNameMap);
    Add(defMap);


    AddEmptyLine();
    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TEntityManagerSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TEntityManagerSourceFileGenerator::AddInit()
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
            str = fmt::format("{}.{} = []({}* {}, {} {}, {}* {}){{ {}->{}({}, *(({}*) {})); }};",
                var, s_setFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid, s_Void, s_Ptr,
                s_pEntMng, s_SetComponent, s_eid, t, s_Ptr);
            Add(str);
            str = fmt::format("{}.{} = []({}* {}, {} {}){{ return ({}*) {}->{}<{}>({}); }};",
                var, s_viewFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
                s_Void, s_pEntMng, s_ViewComponent, t, s_eid);
            Add(str);
            str = fmt::format("{}.{} = []({}* {}, {} {}, {}*& {}){{ return {}->{}<{}>({}, *(({}*) {})); }};",
                var, s_getFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid, s_Void, s_Ptr,
                s_pEntMng, s_GetComponent, t, s_eid, t, s_Ptr);
            Add(str);
            str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
                var, s_hasFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
                s_pEntMng, s_HasComponent, t, s_eid);
            Add(str);
            str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
                var, s_removeFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
                s_pEntMng, s_RemoveComponent, t, s_eid);
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
void TEntityManagerSourceFileGenerator::AddMethodDeinitions()
{
    // set
    std::list<std::string> paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("{}* {}", s_Void, s_Ptr),
        fmt::format("const std::string& {}", s_typeName),
    };
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_SetComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}({}, {}, {});", s_mTypeNameMap, s_typeName, s_setFunc, s_pEntMng, s_eid, s_Ptr);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // view
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("const std::string& {}", s_typeName),
    };
    std::string ret = s_Void + "*";
    AddMethodImplementationBegin(ret, mSerializer->className, s_ViewComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {});", s_mTypeNameMap, s_typeName, s_viewFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // get
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("{}*& {}", s_Void, s_Ptr),
        fmt::format("const std::string& {}", s_typeName),
    };
    AddMethodImplementationBegin(s_Bool, mSerializer->className, s_GetComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {}, {});", s_mTypeNameMap, s_typeName, s_getFunc, s_pEntMng, s_eid, s_Ptr);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // has
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("const std::string& {}", s_typeName),
    };
    AddMethodImplementationBegin(s_Bool, mSerializer->className, s_HasComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {});", s_mTypeNameMap, s_typeName, s_hasFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // remove
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("const std::string& {}", s_typeName),
    };
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_RemoveComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}({}, {});", s_mTypeNameMap, s_typeName, s_removeFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------