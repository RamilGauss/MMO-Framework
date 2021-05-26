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
    if (namespaceName.length()) {
        AddUsingNamespace(namespaceName);
    }

    AddUsingNamespace(s_nsECSFramework);
    AddEmptyLine();

    auto defMap = fmt::format("std::vector<{}::{}> {}::{};",
        mSerializer->className, s_Data, mSerializer->className, s_mRttiVector);
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
    Add("if (!isNeedInit) {");
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

    for (auto& typeInfo : forGen) {

        auto type = mTypeManager->Get(typeInfo.GetFullType());

        auto typeNameWithNameSpace = type->GetTypeNameWithNameSpace();

        auto var = fmt::format("{}_{}", type->GetTypeNameWithNameSpaceAsVar(), s_Data);

        auto str = fmt::format("{} {};", s_Data, var);
        Add(str);

        str = fmt::format("{}.{} = []({}* {}, {} {}, {}* {}){{ {}->{}({}, *(({}*) {})); }};",
            var, s_setFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid, s_Void, s_Ptr,
            s_pEntMng, s_SetComponent, s_eid, typeNameWithNameSpace, s_Ptr);
        Add(str);
        
        str = fmt::format("{}.{} = []({}* {}, {} {}){{ return ({}*) {}->{}<{}>({}); }};",
            var, s_viewFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
            s_Void, s_pEntMng, s_ViewComponent, typeNameWithNameSpace, s_eid);
        Add(str);
        
        str = fmt::format("{}.{} = []({}* {}, {} {}, {}*& {}){{ return {}->{}<{}>({}, *(({}*) {})); }};",
            var, s_getFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid, s_Void, s_Ptr,
            s_pEntMng, s_GetComponent, typeNameWithNameSpace, s_eid, typeNameWithNameSpace, s_Ptr);
        Add(str);
        
        str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
            var, s_hasFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
            s_pEntMng, s_HasComponent, typeNameWithNameSpace, s_eid);
        Add(str);
        
        str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
            var, s_removeFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
            s_pEntMng, s_RemoveComponent, typeNameWithNameSpace, s_eid);
        Add(str);

        str = fmt::format("auto rtti_{} = globalTypeIdentifier->type<{}>();", var, typeNameWithNameSpace);
        Add(str);
        AddEmptyLine();

        str = fmt::format("m.{}({{ rtti_{}, {} }});", s_Insert, var, var);
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
    str = fmt::format("{}.resize(max + 1);", s_mRttiVector);
    Add(str);
    str = fmt::format("for (auto& vt : m) {{");
    Add(str);
    IncrementTabs();
    str = fmt::format("{}[vt.first] = vt.second;", s_mRttiVector);
    Add(str);
    DecrementTabs();
    AddRightBrace();

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
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_SetComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}({}, {}, {});", s_mRttiVector, s_rtti, s_setFunc, s_pEntMng, s_eid, s_Ptr);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // view
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("int {}", s_rtti),
    };
    std::string ret = s_Void + "*";
    AddMethodImplementationBegin(ret, mSerializer->className, s_ViewComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {});", s_mRttiVector, s_rtti, s_viewFunc, s_pEntMng, s_eid);
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
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin(s_Bool, mSerializer->className, s_GetComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {}, {});", s_mRttiVector, s_rtti, s_getFunc, s_pEntMng, s_eid, s_Ptr);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // has
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin(s_Bool, mSerializer->className, s_HasComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({}, {});", s_mRttiVector, s_rtti, s_hasFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // remove
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_RemoveComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}({}, {});", s_mRttiVector, s_rtti, s_removeFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------