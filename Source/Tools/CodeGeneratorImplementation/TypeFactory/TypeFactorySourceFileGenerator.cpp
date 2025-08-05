/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeFactorySourceFileGenerator.h"
#include "fmt/core.h"
#include "Base/Common/BL_Debug.h"

using namespace nsCodeGeneratorImplementation;

void TTypeFactorySourceFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    AddTimeHeader();

    AddInclude(mSerializer->filePathForInclude + ".h");
    AddInclude("Base/Common/SingletonManager.h");
    AddInclude("Base/Common/RunTimeTypeIndex.h");

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
void TTypeFactorySourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeFactorySourceFileGenerator::AddInit()
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

    auto str = fmt::format("std::list<{}> datas;", s_Data);
    Add(str);
    AddEmptyLine();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();

    for ( auto& type : forGen) {
        auto pTypeInfo = mTypeManager->Get(type.GetFullType());

        if (pTypeInfo->mTemplateArgs.size() > 0) {
            continue;
        }

        auto t = pTypeInfo->GetTypeNameWithNameSpace();

        auto var = fmt::format("{}_{}", pTypeInfo->GetTypeNameWithNameSpaceAsVar(), s_Data);

        auto str = fmt::format("{} {};", s_Data, var);
        Add(str);

        str = fmt::format("{}.{} = [](){{ return new {}(); }};",
            var, s_newFunc, t);
        Add(str);

        str = fmt::format("{}.{} = [](void* p){{ delete ({}*)p; }};",
            var, s_deleteFunc, t);
        Add(str);

        auto typeNameWithNameSpace = pTypeInfo->GetTypeNameWithNameSpace();

        str = fmt::format("{}.rtti = globalTypeIdentifier->Type<{}>();", var, typeNameWithNameSpace);
        Add(str);
        AddEmptyLine();

        str = fmt::format("datas.push_back({});", var);
        Add(str);

        AddEmptyLine();
    }

    Add("int max = 0;");
    str = fmt::format("for (auto& d : datas) {{");
    Add(str);
    IncrementTabs();

    Add("max = std::max(d.rtti, max);");
    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    str = fmt::format("{}.resize(max + 1);", s_mDataVector);
    Add(str);
    str = fmt::format("for (auto& d : datas) {{");
    Add(str);
    IncrementTabs();
    str = fmt::format("{}[d.rtti] = d;", s_mDataVector);
    Add(str);
    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TTypeFactorySourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList =
    {
        fmt::format("int {}", s_rtti),
    };

    std::string ret = s_Void + "*";
    AddMethodImplementationBegin(ret, mSerializer->className, s_New, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}].{}();", s_mDataVector, s_rtti, s_newFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //---------------------------------------------
    paramList =
    {
        fmt::format("void* p"),
        fmt::format("int {}", s_rtti),
    };

    ret = s_Void;
    AddMethodImplementationBegin(ret, mSerializer->className, s_Delete, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("{}[{}].{}(p);", s_mDataVector, s_rtti, s_deleteFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //---------------------------------------------
    paramList =
    {
        fmt::format("int {}", s_rtti),
    };

    ret = s_Bool;
    AddMethodImplementationBegin(ret, mSerializer->className, s_Has, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    Add(fmt::format("if (rtti < 0 || rtti >= {}.size()) {{", s_mDataVector));
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();
    str = fmt::format("return {}[{}].{} != nullptr;", s_mDataVector, s_rtti, s_deleteFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------