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

    auto str = fmt::format("std::map<int, std::map<int, {}>> m;", s_Data);
    Add(str);
    AddEmptyLine();

    CreateInheritanceGraph();
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
    AddEmptyLine();

    Add("dstMax = std::max(vtDst.first, dstMax);");

    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    Add("vecData.resize(dstMax + 1);");

    Add("for (auto& vtDst : vt.second) {");
    IncrementTabs();
    Add("vecData[vtDst.first] = vtDst.second;");

    DecrementTabs();
    AddRightBrace();

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
void TDynamicCasterSourceFileGenerator::PreparePairs()
{
    mTasks.clear();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();
    for (auto& type : forGen) {
        std::set<nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo> dstTypes;
        GetParents(type, dstTypes);
        GetChilds(type, dstTypes);

        TPair pair;
        pair.srcType = type;

        for (auto& dstType : dstTypes) {
            auto pDstTypeInfo = mTypeManager->Get(dstType.GetFullType());
            if (pDstTypeInfo->mTemplateArgs.size() > 0) {
                continue;
            }

            pair.dstTypes.push_back(dstType);
        }

        if (pair.dstTypes.size() > 0) {
            mTasks.push_back(pair);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::AddCasters()
{
    PreparePairs();
    GenerateByPairs();
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::GenerateByPairs()
{
    for (auto& task : mTasks) {
        auto pTypeInfo = mTypeManager->Get(task.srcType.GetFullType());

        auto srcTypeStr = pTypeInfo->GetTypeNameWithNameSpace();

        auto srcVar = pTypeInfo->GetTypeNameWithNameSpaceAsVar();
        auto typeNameWithNameSpace = pTypeInfo->GetTypeNameWithNameSpace();

        auto str = fmt::format("std::map<int, {}> {}_Map;", s_Data, srcVar);
        Add(str);
        AddEmptyLine();

        for (auto& dstType : task.dstTypes) {

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
}
//-----------------------------------------------------------------------------------------------------------
void TDynamicCasterSourceFileGenerator::CreateInheritanceGraph()
{
    auto& forGen = mTypeNameDbPtr->GetForGenerate();
    for (auto& typeInfo : forGen) {
        auto pTypeInfo = mTypeManager->Get(typeInfo.GetFullType());
        if (pTypeInfo == nullptr) {
            break;
        }

        for (auto& parent : pTypeInfo->mInheritanceVec) {
            auto pParent = mTypeManager->Get(parent.mLongTypeName);
            if (pParent == nullptr) {
                pParent = mTypeManager->Get(parent.mOriginalTypeName);
            }
            if (pParent == nullptr) {
                continue;
            }

            auto fit = mChildsMap.find(pParent->GetTypeNameWithNameSpace());
            if (fit == mChildsMap.end()) {
                mChildsMap.insert({ pParent->GetTypeNameWithNameSpace(), {} });
                fit = mChildsMap.find(pParent->GetTypeNameWithNameSpace());
            }

            fit->second.push_back(pTypeInfo);
        }
    }
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
void TDynamicCasterSourceFileGenerator::GetChilds(const TTypeNameDataBase::TTypeInfo& type,
    std::set<TTypeNameDataBase::TTypeInfo>& childs)
{
    auto fit = mChildsMap.find(type.GetFullType());
    if (fit == mChildsMap.end()) {
        return;
    }

    for (auto& pChildTypeInfo : fit->second) {
        TTypeNameDataBase::TTypeInfo childTypeInfo;
        childTypeInfo.typeName = pChildTypeInfo->mName;
        childTypeInfo.nameSpace = pChildTypeInfo->GetNameSpace();
        childs.insert(childTypeInfo);

        GetChilds(childTypeInfo, childs);
    }
}
//-----------------------------------------------------------------------------------------------------------