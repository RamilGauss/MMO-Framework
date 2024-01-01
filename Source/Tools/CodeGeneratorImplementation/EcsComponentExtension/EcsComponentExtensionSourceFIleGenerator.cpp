/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <algorithm>

#include "EcsComponentExtensionSourceFileGenerator.h"
#include "fmt/core.h"
#include "Base/Common/BL_Debug.h"

using namespace nsCodeGeneratorImplementation;

void TEcsComponentExtensionSourceFileGenerator::Work()
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
void TEcsComponentExtensionSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsComponentExtensionSourceFileGenerator::AddInit()
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

    auto str = fmt::format("std::list<{}> datas;", s_Data);
    Add(str);
    AddEmptyLine();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();

    for (auto& typeInfo : forGen) {
        AddType(typeInfo);
    }

    Add("int max = 0;");
    str = fmt::format("for (auto& d : datas) {{");
    Add(str);
    IncrementTabs();

    Add("max = std::max(d.rtti, max);");
    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    str = fmt::format("{}.resize(max + 1);", s_mRttiVector);
    Add(str);
    str = fmt::format("for (auto& d : datas) {{");
    Add(str);
    IncrementTabs();
    str = fmt::format("{}[d.rtti] = d;", s_mRttiVector);
    Add(str);
    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsComponentExtensionSourceFileGenerator::AddMethodDeinitions()
{
    // has
    std::list<std::string> paramList =
    {
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin(s_Bool, mSerializer->className, s_Has, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    Add(fmt::format("if (rtti < 0 || rtti >= {}.size()) {{", s_mRttiVector));
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();
    str = fmt::format("return {}[{}].{} != nullptr;", s_mRttiVector, s_rtti, s_setFunc, s_pEntMng, s_eid);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    // set
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("{} {}", s_TEntityID, s_eid),
        fmt::format("int {}", s_rtti),
        fmt::format("{}* p", s_Void),
    };
    auto ret = s_Void;
    AddMethodImplementationBegin(ret, mSerializer->className, s_SetComponent, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}({}, {}, p);", s_mRttiVector, s_rtti, s_setFunc, s_pEntMng, s_eid);
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
    ret = "const " + s_Void + "*";
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
    // getByHas
    paramList =
    {
        fmt::format("{}* {}", s_TEntityManager, s_pEntMng),
        fmt::format("int {}", s_rtti),
    };
    AddMethodImplementationBegin("nsECSFramework::TEntityList", mSerializer->className, s_GetByHas, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}({});", s_mRttiVector, s_rtti, s_getByHasFunc, s_pEntMng);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TEcsComponentExtensionSourceFileGenerator::AddType(const nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo& typeInfo)
{
    auto type = mTypeManager->Get(typeInfo.GetFullType());
    
    auto componentItem = std::find_if(type->mInheritanceVec.begin(), type->mInheritanceVec.end(), 
        [this](const nsCppParser::TInheritanceInfo& inheritance) { return inheritance.mOriginalName == s_IComponent; });
    auto isComponent = (type->mInheritanceVec.end() != componentItem);
    if (!isComponent) {
        return;
    }

    auto typeNameWithNameSpace = type->GetTypeNameWithNameSpace();

    auto var = fmt::format("{}_{}", type->GetTypeNameWithNameSpaceAsVar(), s_Data);

    auto str = fmt::format("{} {};", s_Data, var);
    Add(str);

    // Too long
    str = fmt::format("{}.{} = []({}* {}, {} {}, void* p){{ {}->{}({}, *(({}*)p)); }};",
        var, s_setFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
        s_pEntMng, s_SetComponent, s_eid, typeNameWithNameSpace);
    Add(str);

    str = fmt::format("{}.{} = []({}* {}, {} {}){{ return ({}*) {}->{}<{}>({}); }};",
        var, s_viewFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
        s_Void, s_pEntMng, s_ViewComponent, typeNameWithNameSpace, s_eid);
    Add(str);

    str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
        var, s_hasFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
        s_pEntMng, s_HasComponent, typeNameWithNameSpace, s_eid);
    Add(str);

    str = fmt::format("{}.{} = []({}* {}, {} {}){{ return {}->{}<{}>({}); }};",
        var, s_removeFunc, s_TEntityManager, s_pEntMng, s_TEntityID, s_eid,
        s_pEntMng, s_RemoveComponent, typeNameWithNameSpace, s_eid);
    Add(str);


    str = fmt::format("{}.{} = []({}* {}){{ return {}->{}Copy<{}>(); }};",
        var, s_getByHasFunc, s_TEntityManager, s_pEntMng, s_pEntMng, s_GetByHas, typeNameWithNameSpace);
    Add(str);

    str = fmt::format("{}.rtti = globalTypeIdentifier->Type<{}>();", var, typeNameWithNameSpace);
    Add(str);
    AddEmptyLine();

    str = fmt::format("datas.{}({});", s_PushBack, var);
    Add(str);

    AddEmptyLine();
}
//-----------------------------------------------------------------------------------------------------------