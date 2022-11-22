/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DynamicCasterSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsCodeGeneratorImplementation;
using namespace nsReflectionCodeGenerator;

void TDynamicCasterSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddInclude("SingletonManager.h");
    AddInclude("RunTimeTypeIndex.h");

    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if (namespaceName.length())
        AddUsingNamespace(namespaceName);

    AddEmptyLine();

    auto defVector = fmt::format("std::vector<std::vector<{}::{}>> {}::{};",
        mSerializer->className, s_Data, mSerializer->className, s_mDataVector);
    Add(defVector);
    auto defCombinations = fmt::format("std::map<int, std::set<int>> {}::{};",
        mSerializer->className, s_mRttiCombinations);
    Add(defCombinations);

    AddEmptyLine();

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::AddImplementations()
{
    AddInit();

    AddMethodDeinitions();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::AddInit()
{
    std::list<std::string> paramList;
    AddMethodImplementationBegin(s_Void, mSerializer->className, s_Init, paramList);
    AddLeftBrace();
    IncrementTabs();

    Add("static bool isNeedInit = true;");
    Add("if ( !isNeedInit ) {");
    IncrementTabs();
    Add("return;");
    DecrementTabs();
    AddRightBrace();

    Add("isNeedInit = false;");
    AddEmptyLine();

    Add("auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();");
    AddEmptyLine();

    auto str = fmt::format("std::map<int, std::map<int, {}>> m;", s_Data);
    Add(str);
    AddEmptyLine();

    AddCasters();

    Add("int srcMax = 0;");
    Add("for (auto& vt : m) {");
    IncrementTabs();
    Add("srcMax = std::max(vt.first, srcMax);");

    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();

    str = fmt::format("{}.resize(srcMax + 1);", s_mDataVector);
    Add(str);
    str = fmt::format("for (auto& vt : m) {{");
    Add(str);
    IncrementTabs();

    Add("std::vector<Data> vecData;");
    Add("int dstMax = 0;");

    Add("for (auto& vtDst : vt.second) {");
    IncrementTabs();
    Add("dstMax = std::max(vtDst.first, dstMax);");

    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    Add("vecData.resize(dstMax + 1);");
    Add("std::set<int> rttis;");

    Add("for (auto& vtDst : vt.second) {");
    IncrementTabs();
    Add("vecData[vtDst.first] = vtDst.second;");

    Add("rttis.insert(vtDst.first);");

    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    str = fmt::format("{}.insert({{ vt.first, rttis }});", s_mRttiCombinations);
    Add(str);

    AddEmptyLine();
    str = fmt::format("{}[vt.first] = vecData;", s_mDataVector);
    Add(str);

    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();

    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::PrepareTasks()
{
    mTasks.clear();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();
    for (auto& type : forGen) {
        std::set<nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo> dstTypes;
        GetParents(type, dstTypes);

        auto typeFit = mTasks.find(type);
        if (typeFit == mTasks.end()) {
            mTasks.insert({ type , {} });
            typeFit = mTasks.find(type);
        }

        for (auto& dstType : dstTypes) {
            auto pDstTypeInfo = mTypeManager->Get(dstType.GetFullType());
            if (pDstTypeInfo->mTemplateArgs.size() > 0) {
                continue;
            }

            typeFit->second.push_back(dstType);

            auto dstFit = mTasks.find(dstType);
            if (dstFit == mTasks.end()) {
                mTasks.insert({ dstType , {} });
                dstFit = mTasks.find(dstType);
            }

            dstFit->second.push_back(type);
        }
    }

    auto taskCopy = mTasks;

    for (auto& task : taskCopy) {
        if (task.second.size() == 0) {
            mTasks.erase(task.first);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::AddCasters()
{
    PrepareTasks();
    GenerateByPairs();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::GenerateByPairs()
{
    for (auto& task : mTasks) {
        auto pTypeInfo = mTypeManager->Get(task.first.GetFullType());

        auto srcTypeStr = pTypeInfo->GetTypeNameWithNameSpace();

        auto srcVar = pTypeInfo->GetTypeNameWithNameSpaceAsVar();
        auto typeNameWithNameSpace = pTypeInfo->GetTypeNameWithNameSpace();

        auto str = fmt::format("std::map<int, {}> {}_Map;", s_Data, srcVar);
        Add(str);
        AddEmptyLine();

        for (auto& dstType : task.second) {

            auto pDstTypeInfo = mTypeManager->Get(dstType.GetFullType());

            auto dstTypeStr = pDstTypeInfo->GetTypeNameWithNameSpace();
            auto dstVar = pDstTypeInfo->GetTypeNameWithNameSpaceAsVar();

            auto src_dst = fmt::format("{}_{}", srcVar, dstVar);
            auto src_dst_Data = fmt::format("{}_{}", src_dst, s_Data);

            str = fmt::format("{} {};", s_Data, src_dst_Data);
            Add(str);

            str = fmt::format("{}.{} = [](void* p){{ return dynamic_cast<{}*>(static_cast<{}*>(p)); }};",
                src_dst_Data, s_castFunc, dstTypeStr, srcTypeStr);
            Add(str);

            str = fmt::format("auto {}_rtti = globalTypeIdentifier->Type<{}>();", src_dst, dstTypeStr);
            Add(str);
            AddEmptyLine();

            str = fmt::format("{}_Map.insert({{ {}_rtti, {} }});", srcVar, src_dst, src_dst_Data);
            Add(str);
            AddEmptyLine();
        }

        str = fmt::format("auto {}_rtti = globalTypeIdentifier->Type<{}>();", srcVar, typeNameWithNameSpace);
        Add(str);
        AddEmptyLine();

        str = fmt::format("m.insert({{ {}_rtti, {}_Map }});", srcVar, srcVar);
        Add(str);
        AddEmptyLine();
    }
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::AddMethodDeinitions()
{
    std::list<std::string> paramList =
    {
        fmt::format("int {}", s_SrcRtti),
        "void* p",
        fmt::format("int {}", s_DstRtti),
    };

    std::string ret = "void*";
    AddMethodImplementationBegin(ret, mSerializer->className, s_Cast, paramList);
    AddLeftBrace();
    IncrementTabs();

    auto str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {}[{}][{}].{}(p);", s_mDataVector, s_SrcRtti, s_DstRtti, s_castFunc);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();

    //---------------------------------------------------------------------------
    paramList = {};

    ret = "const std::map<int, std::set<int>>&";
    AddMethodImplementationBegin(ret, mSerializer->className, s_GetRttiCombinations, paramList);
    AddLeftBrace();
    IncrementTabs();

    str = fmt::format("{}();", s_Init);
    Add(str);
    str = fmt::format("return {};", s_mRttiCombinations);
    Add(str);

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::GetParents(const TTypeNameDataBase::TTypeInfo& type,
    std::set<TTypeNameDataBase::TTypeInfo>& parents)
{
    auto pTypeInfo = mTypeManager->Get(type.GetFullType());

    if (pTypeInfo == nullptr) {
        return;
    }

    for (auto& parent : pTypeInfo->mInheritanceVec) {
        auto pParent = mTypeManager->Get(parent.mLongTypeName);
        if (pParent == nullptr) {
            pParent = mTypeManager->Get(parent.mOriginalTypeName);
        }

        if (pParent == nullptr) {
            continue;
        }

        TTypeNameDataBase::TTypeInfo parentTypeInfo;
        parentTypeInfo.typeName = pParent->mName;
        parentTypeInfo.nameSpace = pParent->GetNameSpace();
        parents.insert(parentTypeInfo);

        GetParents(parentTypeInfo, parents);
    }
}
//-----------------------------------------------------------------------------------------------------------
