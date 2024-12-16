/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerSourceFileGenerator.h"
#include <boost/algorithm/string/replace.hpp>
#include "fmt/core.h"
#include "Base/Common/BL_Debug.h"

using namespace nsCodeGeneratorImplementation;
using namespace nsCppParser;

void TJsonSerializerSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");
    AddInclude("Base/Common/JsonPopMaster.h");
    AddInclude("Base/Common/JsonPushMaster.h");

    AddInclude("Base/Common/SingletonManager.h");
    AddInclude("Base/Common/RunTimeTypeIndex.h");

    AddIncludeForExternalSources();

    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if (namespaceName.length()) {
        AddUsingNamespace(namespaceName);
    }

    AddEmptyLine();

    AddUsing(s_POM + " = TJsonPopMaster");
    AddUsing(s_PUM + " = TJsonPushMaster");

    AddEmptyLine();
    Add(fmt::format("std::vector<{}::TypeFunc> {}::{};", mSerializer->className, mSerializer->className, s_TypeFuncVector));
    AddEmptyLine();

    AddInit();
    AddCommentedLongLine();

    AddConstContentMethods();

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddInit()
{
    auto className = mSerializer->className;
    std::string initMethod = fmt::format("void {}::{}()", className, s_Init);
    Add(initMethod);

    AddLeftBrace();
    IncrementTabs();

    Add("static bool isNeedInit = true;");
    Add("if ( !isNeedInit ) {");
    Add("    return;");
    Add("}");
    Add("isNeedInit = false;");
    AddEmptyLine();
    Add("auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();");
    AddEmptyLine();

    auto str = fmt::format("std::list<TypeFunc> funcs;");
    Add(str);
    AddEmptyLine();

    auto& forGen = mTypeNameDbPtr->GetForGenerate();
    for (auto& typeInfo : forGen) {

        auto type = mTypeManager->Get(typeInfo.GetFullType());
        if (type->mType == DeclarationType::ENUM) {
            continue;
        }

        auto typeNameWithNameSpace = type->GetTypeNameWithNameSpace();

        auto typeNameObject = fmt::format("_{}TypeFunc", typeNameWithNameSpace);

        boost::replace_all(typeNameObject, "::", "_");

        Add(fmt::format("TypeFunc {};", typeNameObject));

        Add(fmt::format("{}.serializeFunc = [] (void* p, std::string& str) {{", typeNameObject));
        Add(fmt::format("Serialize<{}>(({}*) p, str);", typeNameWithNameSpace, typeNameWithNameSpace));
        Add("};");
        Add(fmt::format("{}.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {{", typeNameObject));
        Add(fmt::format("    return Deserialize<{}>(({}*) p, str, err);", typeNameWithNameSpace, typeNameWithNameSpace));
        Add("};");

        AddEmptyLine();

        str = fmt::format("{}.rtti = globalTypeIdentifier->Type<{}>();", typeNameObject, typeNameWithNameSpace);
        Add(str);
        AddEmptyLine();

        str = fmt::format("funcs.push_back({});", typeNameObject);
        Add(str);
        AddEmptyLine();
    }

    Add("int max = 0;");
    str = fmt::format("for (auto& f : funcs) {{");
    Add(str);
    IncrementTabs();

    Add("max = std::max(f.rtti, max);");
    DecrementTabs();
    AddRightBrace();

    AddEmptyLine();
    str = fmt::format("{}.resize(max + 1);", s_TypeFuncVector);
    Add(str);
    str = fmt::format("for (auto& f : funcs) {{");
    Add(str);
    IncrementTabs();
    str = fmt::format("{}[f.rtti] = f;", s_TypeFuncVector);
    Add(str);
    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddConstContentMethods()
{
    auto className = mSerializer->className;

    //====================== run-time type index
    Add(fmt::format("void {}::{}(void* p, std::string& str, int rtti)", className, s_SerializeByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("{}[rtti].serializeFunc(p, str);", s_TypeFuncVector));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //======================
    Add(fmt::format("bool {}::{}(void* p, const std::string& str, int rtti, std::string& err)", className, s_DeserializeByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("return {}[rtti].deserializeFunc(p, str, err);", s_TypeFuncVector));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //======================
    Add(fmt::format("bool {}::{}(int rtti)", className, s_HasByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("if (rtti < 0 || rtti >= {}.size()) {{", s_TypeFuncVector));
    IncrementTabs();
    Add("return false;");
    DecrementTabs();
    AddRightBrace();
    Add(fmt::format("return {}[rtti].serializeFunc != nullptr;", s_TypeFuncVector));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddImplementations()
{
    auto& forGen = mTypeNameDbPtr->GetForGenerate();
    for (auto& typeInfo : forGen) {

        auto type = mTypeManager->Get(typeInfo.GetFullType());

        mCurrentTypeInfo = type;

        if (type->mType == DeclarationType::ENUM) {
            AddSerializeEnumMethodImplementation(type);
            AddCommentedLongLine();
            AddDeserializeEnumMethodImplementation(type);
            AddCommentedLongLine();
        } else {
            AddSerializeMethodImplementation(type);
            AddCommentedLongLine();
            AddDeserializeMethodImplementation(type);
            AddCommentedLongLine();
        }
        mCurrentTypeInfo = nullptr;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddSerializeMethodImplementation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForSerialize(namespaceWithType);
    AddMethodImplementationBegin("void", className, sSerializeMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this](TInheritanceInfo* pInheritanceInfo) { AddCallingSerializeParent(pInheritanceInfo); });
    AddCallingMethod(p, [this](TMemberInfo* mi) { AddPushByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddDeserializeMethodImplementation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForDeserialize(namespaceWithType);
    AddMethodImplementationBegin("void", className, sDeserializeMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this](TInheritanceInfo* pInheritanceInfo) { AddCallingDeserializeParent(pInheritanceInfo); });
    AddCallingMethod(p, [this](TMemberInfo* mi) { AddPopByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddSerializeEnumMethodImplementation(nsCppParser::TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForSerializeEnum(namespaceWithType);
    AddMethodImplementationBegin("std::string", className, sSerializeEnumMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    std::string str = fmt::format("*{}", s_TypeObject);
    AddSwitch(str);
    IncrementTabs();
    for (auto value : p->mEnumKeys) {
        str = fmt::format("{}::{}", p->GetTypeNameWithNameSpace(), value);
        AddCase(str);

        IncrementTabs();
        str = fmt::format("return \"{}\";", value);
        Add(str);
        DecrementTabs();
    }
    AddDefault();

    DecrementTabs();
    AddRightBrace();

    str = fmt::format("return \"\";");
    Add(str);

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddDeserializeEnumMethodImplementation(nsCppParser::TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForDeserializeEnum(namespaceWithType);
    AddMethodImplementationBegin("void", className, sDeserializeEnumMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    std::string str = fmt::format("std::map<std::string, {}> m;", p->GetTypeNameWithNameSpace());
    Add(str);

    for (auto value : p->mEnumKeys) {
        str = fmt::format("m.{}({{\"{}\", {}::{}}});", s_Insert, value, p->GetTypeNameWithNameSpace(), value);
        Add(str);
    }

    str = fmt::format("*{} = m[str];", s_TypeObject);
    Add(str);

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushByMemberInfo(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::vector<TMemberExtendedTypeInfo> extArr;
    if (pExtArr == nullptr) {
        if (pExtArr == nullptr) {
            pMemberInfo->CreateExtArray(extArr);
            pExtArr = &extArr;
        }
    }

    auto category = pExtArr->at(depth).mCategory;

    if (pExtArr->at(depth).IsContainer()) { // Continue
        switch (category) {
            case TypeCategory::SET:
            case TypeCategory::LIST:
                AddBeginPushListOrSet(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushListOrSet(pMemberInfo, pExtArr, depth);
                break;
            case TypeCategory::VECTOR:
                AddBeginPushVector(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushVector(pMemberInfo, pExtArr, depth);
                break;
            case TypeCategory::MAP:
                AddBeginPushMap(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushMap(pMemberInfo, pExtArr, depth);
                break;
        }
    } else { // Dead end
        switch (category) {
            case TypeCategory::NUMBER:
            case TypeCategory::CEIL_NUMBER:
            case TypeCategory::BOOL:
            case TypeCategory::STRING:
                AddPush(pMemberInfo, pExtArr, depth);
                break;
            case TypeCategory::REFLECTION:
                AddPushReflection(pMemberInfo, pExtArr, depth);
                break;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPush(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    if (depth == 0) {
        AddPushZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPushDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr)
{
    auto str = fmt::format("{}::{}({}, \"{}\", {}->{});",
        s_PUM, s_Push, s_Obj, pMemberInfo->mName, s_TypeObject, pMemberInfo->mName);

    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::string str;

    auto prevExt = &(pExtArr->at(depth - 1));
    auto curE = ElementName(pMemberInfo->mName, depth - 1);
    auto curC = CollectorName(pMemberInfo->mName, depth - 1);
    auto curA = ArrayName(pMemberInfo->mName, depth - 1);

    if (prevExt->mCategory == TypeCategory::MAP) {
        str = fmt::format("{}::{}({}, {}::{}({}.{}).data(), {}.{});",
            s_PUM, s_Push, curC, s_PUM, s_ConvertToString, curE, s_First, curE, s_Second);
    } else {
        str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, curA, curE);
    }
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflection(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    if (depth == 0) {
        AddPushReflectionZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPushReflectionDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr)
{
    std::list<std::string> withinClassTypeNameList;

    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetTypeNameWithNameSpace());

    auto methodStr = GetSerializeMethod(&(pMemberInfo->mExtendedInfo), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    std::string str;

    auto addObject = fmt::format("auto {}_o = {}::{}({}, \"{}\");", pMemberInfo->mName, s_PUM, s_AddObject, s_Obj, pMemberInfo->mName);

    auto access = pMemberInfo->mExtendedInfo.mAccessMethod;
    if (access == AccessMethod::OBJECT) {

        TTypeInfo* type;
        Find(&(pMemberInfo->mExtendedInfo), withinClassTypeNameList, type);
        if (type->mType == DeclarationType::ENUM) {
            std::string collector = CollectorName(pMemberInfo->mName, 0);
            str = fmt::format("auto {} = {}(&({}->{}));", collector, methodStr, s_TypeObject, pMemberInfo->mName);
            Add(str);
            str = fmt::format("{}::{}({}, \"{}\", {});", s_PUM, s_Push, s_Obj, pMemberInfo->mName, collector);
            Add(str);
        } else {
            Add(addObject);
            str = fmt::format("{}(&({}->{}), {}_o);", methodStr, s_TypeObject, pMemberInfo->mName, pMemberInfo->mName);
            Add(str);
        }
    } else {
        std::string ptr;
        if (access == AccessMethod::SMART_POINTER) {
            ptr = fmt::format("{}->{}.get()", s_TypeObject, pMemberInfo->mName);
        } else {
            ptr = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
        }

        str = fmt::format("if ({} == {}) {{", ptr, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}::{}({}, \"{}\");", s_PUM, s_PushNull, s_Obj, pMemberInfo->mName);
        Add(str);
        DecrementTabs();
        Add("} else {");
        IncrementTabs();
        Add(addObject);
        str = fmt::format("{}({}, {}_o);", methodStr, ptr, pMemberInfo->mName);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto prevExt = &(pExtArr->at(depth - 1));

    switch (prevExt->mCategory) {
        case TypeCategory::SET:
        case TypeCategory::LIST:
        case TypeCategory::VECTOR:
            AddPushReflectionDepthSetListVector(pMemberInfo, pExtArr, depth);
            break;
        case TypeCategory::MAP:
            AddPushReflectionDepthMap(pMemberInfo, pExtArr, depth);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());

    auto methodStr = GetSerializeMethod(&(pExtArr->at(depth)), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    std::string str;
    std::string prevObj;
    if (depth == 1) {
        prevObj = s_Obj;
    } else {
        prevObj = CollectorName(pMemberInfo->mName, depth - 1);
    }

    auto curE = ElementName(pMemberInfo->mName, depth - 1);
    auto prevC = CollectorName(pMemberInfo->mName, depth - 1);
    auto curC = CollectorName(pMemberInfo->mName, depth);
    auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
    auto curA = ArrayName(pMemberInfo->mName, depth);

    auto access = pExtArr->at(depth).mAccessMethod;

    if (access == AccessMethod::OBJECT) {

        TTypeInfo* type = nullptr;
        Find(&(pExtArr->at(depth)), withinClassTypeNameList, type);
        // No need check the type on nullptr, cause methodStr is exist
        if (type->mType == DeclarationType::ENUM) {
            str = fmt::format("auto {} = {}(&{});", curC, sSerializeEnumMethod, curE);
            Add(str);
            str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curC);
            Add(str);
        } else {
            str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kObjectType);
            Add(str);
            str = fmt::format("auto {} = {}.{}();", curC, curA, s_GetObject);
            Add(str);
            str = fmt::format("{}(&{}, {});", methodStr, curE, curC);
            Add(str);
            str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curA);
            Add(str);
        }
    } else {
        std::string ptr;
        if (access == AccessMethod::SMART_POINTER) {
            ptr = fmt::format("{}.get()", curE);
        } else {
            ptr = fmt::format("{}", curE);
        }

        str = fmt::format("if ({} == {}) {{", ptr, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}::{}({});", s_PUM, s_PushToArrayNull, prevA);
        Add(str);
        DecrementTabs();
        Add("} else {");
        IncrementTabs();
        str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kObjectType);
        Add(str);
        str = fmt::format("auto {} = {}.{}();", curC, curA, s_GetObject);
        Add(str);
        str = fmt::format("{}({}, {});", methodStr, ptr, curC);
        Add(str);
        str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curA);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepthMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());

    auto methodStr = GetSerializeMethod(&(pExtArr->at(depth)), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    std::string str;
    std::string prevObj;
    if (depth == 1) {
        prevObj = s_Obj;
    } else {
        prevObj = CollectorName(pMemberInfo->mName, depth - 1);
    }

    auto curE = ElementName(pMemberInfo->mName, depth - 1);
    auto prevC = CollectorName(pMemberInfo->mName, depth - 1);

    auto curA = ArrayName(pMemberInfo->mName, depth - 1);

    auto access = pExtArr->at(depth).mAccessMethod;

    if (access == AccessMethod::OBJECT) {
        TTypeInfo* type = nullptr;
        Find(&(pExtArr->at(depth)), withinClassTypeNameList, type);
        if (type->mType == DeclarationType::ENUM) {

            auto curC = CollectorName(pMemberInfo->mName, depth);
            str = fmt::format("auto {} = {}(&{}.{});", curC, methodStr, curE, s_Second);
            Add(str);
            str = fmt::format("{}::{}({}, {}::{}({}.{}).data(), {});",
                s_PUM, s_Push, prevC, s_PUM, s_ConvertToString, curE, s_First, curC);
            Add(str);
        } else {
            str = fmt::format("auto {} = {}::{}({}, {}::{}({}.first).data());", curA, s_PUM, s_AddObject, prevC,
                s_PUM, s_ConvertToString, curE);
            Add(str);
            str = fmt::format("{}(&({}.second), {});", methodStr, curE, curA);
            Add(str);
        }
    } else {
        std::string ptr;
        if (access == AccessMethod::SMART_POINTER) {
            ptr = fmt::format("{}.second.get()", curE);
        } else {
            ptr = fmt::format("{}.second", curE);
        }

        str = fmt::format("if ( {} == {} ) {{", ptr, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}::{}({}, {}::{}({}.first).data());", s_PUM, s_PushNull, prevObj, s_PUM, s_ConvertToString, curE);
        Add(str);
        DecrementTabs();
        Add("} else {");
        IncrementTabs();
        str = fmt::format("auto {} = {}::{}({}, {}::{}({}.first).data());",
            curA, s_PUM, s_AddObject, prevC, s_PUM, s_ConvertToString, curE);
        Add(str);
        str = fmt::format("{}({}, {});", methodStr, ptr, curA);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPushListOrSet(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kArrayType);
    Add(str);

    auto curI = IndexName(pMemberInfo->mName, depth);

    std::string prevE;

    if (depth == 0) {
        prevE = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            accessToElement = ".second";
        }
        prevE = ElementName(pMemberInfo->mName, depth - 1) + accessToElement;
    }

    auto curE = ElementName(pMemberInfo->mName, depth);

    auto refStr = "&";
    if (pMemberInfo->mExtendedInfo.mCategory == TypeCategory::SET) {
        refStr = "";
    }

    str = fmt::format("for(auto{} {} : {}) {{", refStr, curE, prevE);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushListOrSet(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);


    if (depth == 0) {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        str = fmt::format("{}::{}({}, \"{}\", {});", s_PUM, s_Push, s_Obj, pMemberInfo->mName, curA);
        Add(str);
    } else {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            auto prevC = CollectorName(pMemberInfo->mName, depth - 1);
            auto prevE = ElementName(pMemberInfo->mName, depth - 1);

            str = fmt::format("{}::{}({}, {}::{}({}.first).data(), {});",
                s_PUM, s_Push, prevC, s_PUM, s_ConvertToString, prevE, curA);
            Add(str);
        } else {
            auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
            str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curA);
            Add(str);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPushVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kArrayType);
    Add(str);

    auto curI = IndexName(pMemberInfo->mName, depth);

    std::string prevE;

    if (depth == 0) {
        prevE = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            accessToElement = ".second";
        }
        prevE = ElementName(pMemberInfo->mName, depth - 1) + accessToElement;
    }
    str = fmt::format("for(size_t {} = 0 ; {} < {}.size() ; {}++) {{", curI, curI, prevE, curI);
    Add(str);

    IncrementTabs();
    auto curE = ElementName(pMemberInfo->mName, depth);

    std::string elementType = "auto&";
    if (pExtArr->at(depth + 1).mCategory == TypeCategory::BOOL) {
        elementType = s_Bool;
    }

    str = fmt::format("{} {} = {}[{}];", elementType, curE, prevE, curI);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);

    if (depth == 0) {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        str = fmt::format("{}::{}({}, \"{}\", {});", s_PUM, s_Push, s_Obj, pMemberInfo->mName, curA);
        Add(str);
    } else {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            auto prevC = CollectorName(pMemberInfo->mName, depth - 1);
            auto prevE = ElementName(pMemberInfo->mName, depth - 1);

            str = fmt::format("{}::{}({}, {}::{}({}.first).data(), {});",
                s_PUM, s_Push, prevC, s_PUM, s_ConvertToString, prevE, curA);
            Add(str);
        } else {
            auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
            str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curA);
            Add(str);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPushMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::string curSrc;
    std::string prevObj;
    std::string prevKey;

    if (depth == 0) {
        curSrc = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
        prevObj = s_Obj;
        prevKey = fmt::format("\"{}\"", pMemberInfo->mName);
    } else {
        std::string accessToSrc;
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            accessToSrc = ".second";
            accessToElement = ".first";
        }
        curSrc = fmt::format("{}", ElementName(pMemberInfo->mName, depth - 1)) + accessToSrc;
        prevObj = CollectorName(pMemberInfo->mName, depth - 1);
        prevKey = fmt::format("{}::{}({}{}).data()",
            s_PUM, s_ConvertToString, ElementName(pMemberInfo->mName, depth - 1), accessToElement);
    }
    auto curC = CollectorName(pMemberInfo->mName, depth);
    std::string str;
    if (depth == 0) {
        str = fmt::format("auto {} = {}::{}({}, {});", curC, s_PUM, s_AddObject, prevObj, prevKey);
        Add(str);
    } else {
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if (prevCategory == TypeCategory::MAP) {
            str = fmt::format("auto {} = {}::{}({}, {});", curC, s_PUM, s_AddObject, prevObj, prevKey);
            Add(str);
        } else {
            auto curA = ArrayName(pMemberInfo->mName, depth);
            str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kObjectType);
            Add(str);
            str = fmt::format("auto {} = {}.{}();", curC, curA, s_GetObject);
            Add(str);
        }
    }

    auto index = IndexName(pMemberInfo->mName, depth);
    auto curE = ElementName(pMemberInfo->mName, depth);
    str = fmt::format("for(auto& {} : {}) {{", curE, curSrc);
    Add(str);

    IncrementTabs();

    auto curCategory = pExtArr->at(depth).mCategory;
    if (curCategory != TypeCategory::MAP) {
        auto nextC = CollectorName(pMemberInfo->mName, depth + 1);
        str = fmt::format("auto& {} = {};", nextC, curC);
        Add(str);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);

    auto prevCategory = pExtArr->at(depth).mCategory;
    if (prevCategory == TypeCategory::MAP) {
        return;
    }

    if (depth == 0) {
        return;
    }

    auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
    auto curA = ArrayName(pMemberInfo->mName, depth);
    str = fmt::format("{}::{}({}, {});", s_PUM, s_PushToArray, prevA, curA);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopByMemberInfo(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::vector<TMemberExtendedTypeInfo> extArr;
    if (pExtArr == nullptr) {
        pMemberInfo->CreateExtArray(extArr);
        pExtArr = &extArr;
    }

    auto category = pExtArr->at(depth).mCategory;
    if (pExtArr->at(depth).IsContainer()) { // Continue
        switch (category) {
            case TypeCategory::SET:
            case TypeCategory::LIST:
            case TypeCategory::VECTOR:
                AddBeginPopListSetVector(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
            case TypeCategory::MAP:
                AddBeginPopMap(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
        }
    } else { // Dead end
        switch (category) {
            case TypeCategory::BOOL:
            case TypeCategory::NUMBER:
            case TypeCategory::CEIL_NUMBER:
            case TypeCategory::STRING:
                AddPop(pMemberInfo, pExtArr, depth);
                break;
            case TypeCategory::REFLECTION:
                AddPopReflection(pMemberInfo, pExtArr, depth);
                break;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPop(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    if (depth == 0) {
        AddPopZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPopDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr)
{
    std::string pop;

    auto category = pExtArr->at(0).mCategory;

    switch (category) {
        case TypeCategory::BOOL:
            pop = s_PopBool;
            break;
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            pop = s_PopNum;
            break;
        case TypeCategory::STRING:
            pop = s_PopStr;
            break;
    }

    auto str = fmt::format("{}::{}({}, \"{}\", {}->{});",
        s_POM, pop, s_Obj, pMemberInfo->mName, s_TypeObject, pMemberInfo->mName);

    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::string str;

    auto prevExt = &(pExtArr->at(depth - 1));
    auto curExt = &(pExtArr->at(depth));
    auto curE = ElementName(pMemberInfo->mName, depth - 1);

    std::string curC;
    if (depth == 1) {
        curC = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        curC = CollectorName(pMemberInfo->mName, depth - 1);
    }

    if (prevExt->mCategory == TypeCategory::MAP) {
        auto get = s_GetInt64;
        if (curExt->mCategory == TypeCategory::BOOL) {
            get = s_GetBool;
        } else if (curExt->mCategory == TypeCategory::NUMBER) {
            get = s_GetDouble;
        } else if (curExt->mCategory == TypeCategory::CEIL_NUMBER) {
            get = s_GetInt64;
        } else {
            get = s_GetString;
        }

        std::string key = fmt::format("{}.name.{}()", curE, s_GetString);
        auto keyExt = prevExt->mTemplateChildArr.at(0);
        if (keyExt.mCategory != TypeCategory::STRING) {
            key = fmt::format("({}){}({})", keyExt.GetTypeNameWithNameSpace(), s_StrToNum, key);
        }

        str = fmt::format("{}.{}({{ {}, {}.value.{}() }});", curC, s_Insert, key, curE, get);
    } else {

        auto add = s_PushBack;
        if (prevExt->mCategory == TypeCategory::SET) {
            add = s_Insert;
        }
        auto get = s_GetInt64;
        if (curExt->mCategory == TypeCategory::BOOL) {
            get = s_GetBool;
        } else if (curExt->mCategory == TypeCategory::NUMBER) {
            get = s_GetDouble;
        } else if (curExt->mCategory == TypeCategory::CEIL_NUMBER) {
            get = s_GetInt64;
        } else {
            get = s_GetString;
        }

        str = fmt::format("{}.{}({}.{}());", curC, add, curE, get);
    }

    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflection(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    if (depth == 0) {
        AddPopReflectionZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPopReflectionDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetTypeNameWithNameSpace());

    auto methodStr = GetDeserializeMethod(&(pMemberInfo->mExtendedInfo), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    auto curO = ObjectName(pMemberInfo->mName, 0);
    auto accessMethod = pExtArr->at(0).mAccessMethod;

    if (accessMethod == AccessMethod::OBJECT) {

        TTypeInfo* type = nullptr;
        Find(&(pMemberInfo->mExtendedInfo), withinClassTypeNameList, type);

        std::string str;
        if (type->mType == DeclarationType::ENUM) {
            std::string collector = CollectorName(pMemberInfo->mName, 0);

            str = fmt::format("std::string {};", collector);
            Add(str);
            str = fmt::format("{}::{}({}, \"{}\", {});", s_POM, s_PopStr, s_Obj, pMemberInfo->mName, collector);
            Add(str);
            str = fmt::format("{}({}, &({}->{}));", methodStr, collector, s_TypeObject, pMemberInfo->mName);
            Add(str);
        } else {
            str = fmt::format("auto {} = {}::{}({}, \"{}\");", curO, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
            Add(str);
            str = fmt::format("{}(&({}->{}), {});", methodStr, s_TypeObject, pMemberInfo->mName, curO);
            Add(str);
        }
    } else {

        std::string get = pMemberInfo->mName;
        std::string reset;
        if (accessMethod == AccessMethod::SMART_POINTER) {
            reset = fmt::format("{}.reset(new {}())", pMemberInfo->mName, pMemberInfo->mExtendedInfo.GetTypeNameWithNameSpace());
            get += ".get()";
        } else {
            reset = fmt::format("{} = new {}()", pMemberInfo->mName, pMemberInfo->mExtendedInfo.GetTypeNameWithNameSpace());
        }

        auto str = fmt::format("if ({}::{}({}, \"{}\") && !{}::{}({}, \"{}\" ) ) {{",
            s_POM, s_IsExist, s_Obj, pMemberInfo->mName, s_POM, s_IsNull, s_Obj, pMemberInfo->mName);
        Add(str);
        IncrementTabs();
        str = fmt::format("if ({}->{} == {}) {{", s_TypeObject, get, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}->{};", s_TypeObject, reset);
        Add(str);
        DecrementTabs();
        Add("}");

        str = fmt::format("auto {} = {}::{}({}, \"{}\");",
            curO, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
        Add(str);

        str = fmt::format("{}({}->{}, {});", methodStr, s_TypeObject, get, curO);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto prevExt = &(pExtArr->at(depth - 1));

    switch (prevExt->mCategory) {
        case TypeCategory::SET:
        case TypeCategory::LIST:
        case TypeCategory::VECTOR:
            AddPopReflectionDepthSetListVector(pMemberInfo, pExtArr, depth);
            break;
        case TypeCategory::MAP:
            AddPopReflectionDepthMap(pMemberInfo, pExtArr, depth);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetTypeNameWithNameSpace());

    auto methodStr = GetDeserializeMethod(&(pExtArr->at(depth)), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curC = CollectorName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    auto category = pExtArr->at(depth).mAccessMethod;
    auto sptype = pExtArr->at(depth).mSmartPtrType;

    auto dst = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    if (depth != 1) {
        dst = CollectorName(pMemberInfo->mName, depth - 1);
    }

    TTypeInfo* type = nullptr;
    Find(&(pExtArr->at(depth)), withinClassTypeNameList, type);
    auto typeE = type->GetTypeNameWithNameSpace();

    auto addMethod = s_PushBack;
    if (pMemberInfo->mExtendedInfo.mCategory == TypeCategory::SET) {
        addMethod = s_Insert;
    }

    if (category == AccessMethod::OBJECT) {
        std::string str;
        if (type->mType == DeclarationType::ENUM) {
            str = fmt::format("std::string {} = {}.{}();", curO, prevE, s_GetString);
            Add(str);
            str = fmt::format("{} {};", typeE, curC);
            Add(str);
            str = fmt::format("{}({}, &{});", methodStr, curO, curC);
            Add(str);
            str = fmt::format("{}.{}({});", dst, addMethod, curC);
            Add(str);
        } else {
            str = fmt::format("auto {} = {}.{}();", curO, prevE, s_GetObject);
            Add(str);
            str = fmt::format("{} {};", typeE, curC);
            Add(str);
            str = fmt::format("{}(&{}, {});", methodStr, curC, curO);
            Add(str);
            str = fmt::format("{}.{}({});", dst, addMethod, curC);
            Add(str);
        }
    } else {
        std::string access;
        std::string newExp;
        if (category == AccessMethod::SMART_POINTER) {
            access = ".get()";
            newExp = fmt::format("{}<{}>(new {}())", sptype, typeE, typeE);
        } else {
            newExp = fmt::format("new {}()", typeE);
        }

        auto str = fmt::format("if (!{}.{}()) {{", prevE, s_IsNull);
        Add(str);
        IncrementTabs();
        str = fmt::format("auto {} = {}.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("auto {} = {};", curC, newExp);
        Add(str);
        str = fmt::format("{}({}{}, {});", methodStr, curC, access, curO);
        Add(str);
        str = fmt::format("{}.{}({});", dst, addMethod, curC);
        Add(str);

        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepthMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetTypeNameWithNameSpace());

    auto methodStr = GetDeserializeMethod(&(pExtArr->at(depth)), withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curC = CollectorName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    auto category = pExtArr->at(depth).mAccessMethod;
    auto sptype = pExtArr->at(depth).mSmartPtrType;

    auto curExt = &(pExtArr->at(depth));

    std::string key = fmt::format("{}.name.{}()", prevE, s_GetString);
    auto keyExt = pExtArr->at(depth - 1).mTemplateChildArr.at(0);

    if (keyExt.mCategory != TypeCategory::STRING) {
        key = fmt::format("({}){}({})", keyExt.GetTypeNameWithNameSpace(), s_StrToNum, key);
    }

    auto dst = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    if (depth != 1) {
        dst = CollectorName(pMemberInfo->mName, depth - 1);
    }

    TTypeInfo* type = nullptr;
    Find(&(pExtArr->at(depth)), withinClassTypeNameList, type);
    auto typeE = type->GetTypeNameWithNameSpace();

    if (category == AccessMethod::OBJECT) {
        if (type->mType == DeclarationType::ENUM) {
            auto str = fmt::format("std::string {} = {}.value.{}();", curO, prevE, s_GetString);
            Add(str);
            str = fmt::format("{} {};", typeE, curC);
            Add(str);
            str = fmt::format("{}({}, &{});", methodStr, curO, curC);
            Add(str);
            str = fmt::format("{}.{}({{ {}, {} }});", dst, s_Insert, key, curC);
            Add(str);
        } else {
            auto str = fmt::format("auto {} = {}.value.{}();", curO, prevE, s_GetObject);
            Add(str);
            str = fmt::format("{} {};", typeE, curC);
            Add(str);
            str = fmt::format("{}(&{}, {});", methodStr, curC, curO);
            Add(str);
            str = fmt::format("{}.{}({{ {}, {} }});", dst, s_Insert, key, curC);
            Add(str);
        }
    } else {
        std::string access;
        std::string newExp;
        if (category == AccessMethod::SMART_POINTER) {
            access = ".get()";
            newExp = fmt::format("{}<{}>(new {}())", sptype, typeE, typeE);
        } else {
            newExp = fmt::format("new {}()", typeE);
        }

        auto str = fmt::format("if (!{}.value.{}() ) {{", prevE, s_IsNull);
        Add(str);
        IncrementTabs();
        str = fmt::format("auto {} = {}.value.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("auto {} = {};", curC, newExp);
        Add(str);
        str = fmt::format("{}({}{}, {});", methodStr, curC, access, curO);
        Add(str);
        str = fmt::format("{}.{}({{ {}, {} }});", dst, s_Insert, key, curC);
        Add(str);

        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPopListSetVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    std::string curName;
    std::string str;

    // If next is not array. 
    // Excpected: { "name" : [0, 1] }, but: { "name" : 1 }
    // Excpected: [ [0, 1], [2, 3] ], but: [ [0, 1], 42 ]
    if (pExtArr->size() == depth + 2 &&
        (pExtArr->at(depth + 1).mCategory != TypeCategory::REFLECTION)) {

        std::string condition;
        if (depth == 0) {
            condition = fmt::format("{}::{}({}, \"{}\")", s_POM, s_IsArray, s_Obj, pMemberInfo->mName);
        } else {
            auto prevE = ElementName(pMemberInfo->mName, depth - 1);
            std::string access;
            if (pExtArr->at(depth - 1).mCategory == TypeCategory::MAP) {
                access = ".value";
            }
            condition = fmt::format("{}{}.{}()", prevE, access, s_IsArray);
        }

        str = fmt::format("if ({}) {{", condition);
        Add(str);
        IncrementTabs();
    }

    if (depth == 0) {
        str = fmt::format("auto {} = {}::{}({}, \"{}\");", curA, s_POM, s_FindArray, s_Obj, pMemberInfo->mName);
        Add(str);
    } else {
        std::string access;
        if (pExtArr->at(depth - 1).mCategory == TypeCategory::MAP) {
            access = ".value";
        }

        auto type = pExtArr->at(depth).GetCollectSubType();

        auto curC = CollectorName(pMemberInfo->mName, depth);
        str = fmt::format("{} {};", type, curC);
        Add(str);

        auto prevE = ElementName(pMemberInfo->mName, depth - 1);
        auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
        str = fmt::format("auto {} = {}{}.{}();", curA, prevE, access, s_GetArray);
        Add(str);
    }

    str = fmt::format("for(auto& {} : {}) {{", curE, curA);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPopListSetVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::string add;
    if (pExtArr->at(depth - 1).mCategory == TypeCategory::SET) {
        add = s_Insert;
    } else {
        add = s_PushBack;
    }

    std::string access;
    if (depth == 1) {
        access = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        access = CollectorName(pMemberInfo->mName, depth - 1);
    }
    auto nextC = CollectorName(pMemberInfo->mName, depth);
    auto str = fmt::format("{}.{}({});", access, add, nextC);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPopMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    std::string curName;
    std::string str;
    if (depth == 0) {

        str = fmt::format("auto {} = {}::{}({}, \"{}\");", curA, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
        Add(str);
    } else {

        std::string access;
        if (pExtArr->at(depth - 1).mCategory == TypeCategory::MAP) {
            access = ".value";
        }

        auto type = pExtArr->at(depth).GetCollectSubType();

        auto curC = CollectorName(pMemberInfo->mName, depth);
        str = fmt::format("{} {};", type, curC);
        Add(str);

        auto prevE = ElementName(pMemberInfo->mName, depth - 1);
        auto prevA = ArrayName(pMemberInfo->mName, depth - 1);
        str = fmt::format("auto {} = {}{}.{}();", curA, prevE, access, s_GetObject);
        Add(str);
    }

    str = fmt::format("for(auto& {} : {}) {{", curE, curA);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPop(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    DecrementTabs();
    Add("}");

    if (depth > 0) {

        if (pExtArr->at(depth - 1).mCategory == TypeCategory::MAP) {
            AddEndPopMap(pMemberInfo, pExtArr, depth);
        } else {
            AddEndPopListSetVector(pMemberInfo, pExtArr, depth);
        }
    }

    if (pExtArr->at(depth).mCategory != TypeCategory::MAP) {
        if (pExtArr->at(depth + 1).mCategory != TypeCategory::REFLECTION) {
            if (pExtArr->size() == depth + 2) {
                DecrementTabs();
                auto str = "} else {";
                Add(str);
                IncrementTabs();

                AddPopLastElementListSetVector(pMemberInfo, pExtArr, depth);

                DecrementTabs();
                str = "}";
                Add(str);
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopLastElementListSetVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    auto curT = TempName(pMemberInfo->mName, depth);
    auto lastIndex = pExtArr->size() - 1;

    auto category = pExtArr->at(lastIndex).mCategory;
    std::string popMethod;
    if (category == TypeCategory::STRING) {
        popMethod = s_PopStr;
    } else if (category == TypeCategory::BOOL) {
        popMethod = s_PopBool;
    } else {
        popMethod = s_PopNum;
    }

    auto curExt = &pExtArr->at(depth);
    std::string addMethod;
    if (curExt->mCategory == TypeCategory::SET) {
        addMethod = s_Insert;
    } else {
        addMethod = s_PushBack;
    }

    auto type = pExtArr->at(lastIndex).GetTypeNameWithNameSpace();
    if (depth == 0) {
        auto str = fmt::format("{} {};", type, curT);
        Add(str);
        str = fmt::format("{}::{}({}, \"{}\", {});", s_POM, popMethod, s_Obj, pMemberInfo->mName, curT);
        Add(str);
        str = fmt::format("{}->{}.{}({});", s_TypeObject, pMemberInfo->mName, addMethod, curT);
        Add(str);
    } else {
        auto prevExt = &pExtArr->at(depth - 1);
        std::string access;
        std::string prevAddMethod;
        if (prevExt->mCategory == TypeCategory::SET ||
            prevExt->mCategory == TypeCategory::MAP) {
            prevAddMethod = s_Insert;
            access = ".value";
        } else {
            prevAddMethod = s_PushBack;
        }

        std::string getMethod;
        if (category == TypeCategory::STRING) {
            getMethod = s_GetString;
        } else if (category == TypeCategory::BOOL) {
            getMethod = s_GetBool;
        } else if (category == TypeCategory::NUMBER) {
            getMethod = s_GetDouble;
        } else {
            getMethod = s_GetInt64;
        }

        auto prevType = pExtArr->at(lastIndex - 1).GetCollectSubType();
        auto prevE = ElementName(pMemberInfo->mName, depth - 1);
        auto curC = CollectorName(pMemberInfo->mName, depth);
        std::string curD;
        if (depth == 1) {
            curD = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
        } else {
            curD = CollectorName(pMemberInfo->mName, depth - 1);
        }

        auto str = fmt::format("auto {} = {}{}.{}();", curT, prevE, access, getMethod);
        Add(str);
        str = fmt::format("{} {};", prevType, curC);
        Add(str);
        if (depth > 0) {
            str = fmt::format("{}.{}({});", curC, addMethod, curT);
            Add(str);
        }
        std::string added;
        if (prevExt->mCategory == TypeCategory::MAP) {

            auto toValue = fmt::format("{}.name.{}()", prevE, s_GetString);

            auto keyCategory = prevExt->mTemplateChildArr.at(0).mCategory;

            if (keyCategory == TypeCategory::NUMBER ||
                keyCategory == TypeCategory::CEIL_NUMBER) {
                toValue = fmt::format("{}({})", s_StrToNum, toValue);
            }

            added = fmt::format("{{ {}, {} }}", toValue, curC);
        } else {
            added = curC;
        }
        str = fmt::format("{}.{}({});", curD, prevAddMethod, added);
        Add(str);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPopMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberExtendedTypeInfo>* pExtArr, int depth)
{
    std::string access;
    if (depth == 1) {
        access = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        access = CollectorName(pMemberInfo->mName, depth - 1);
    }
    auto nextC = CollectorName(pMemberInfo->mName, depth);

    auto keyInfo = pExtArr->at(depth - 1).mTemplateChildArr.at(0);

    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curE = ElementName(pMemberInfo->mName, depth);

    std::string key;
    if (keyInfo.mCategory == TypeCategory::NUMBER ||
        keyInfo.mCategory == TypeCategory::CEIL_NUMBER) {
        key = fmt::format("{}({}.name.{}())", s_StrToNum, prevE, s_GetString);
    } else {
        key = fmt::format("{}.name.{}()", prevE, s_GetString);
    }

    auto str = fmt::format("{}.{}({{ {}, {} }});", access, s_Insert, key, nextC);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingSerializeParent(TInheritanceInfo* pInheritanceInfo)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());

    TMemberExtendedTypeInfo extInfo;
    extInfo.mNameSpace = pInheritanceInfo->mOriginalNameSpace;
    extInfo.mShortType = pInheritanceInfo->mShortTypeName;

    auto methodStr = GetSerializeMethod(&extInfo, withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    TTypeInfo* type = nullptr;
    auto refType = Find(&extInfo, withinClassTypeNameList, type);

    auto str = fmt::format("{}(({}*){}, {});// Inheritances", methodStr, type->GetTypeNameWithNameSpace(), s_TypeObject, s_Obj);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingDeserializeParent(TInheritanceInfo* pInheritanceInfo)
{
    std::list<std::string> withinClassTypeNameList;
    withinClassTypeNameList.push_back(mCurrentTypeInfo->GetNameSpace());

    TMemberExtendedTypeInfo extInfo;
    extInfo.mNameSpace = pInheritanceInfo->mOriginalNameSpace;
    extInfo.mShortType = pInheritanceInfo->mShortTypeName;

    auto methodStr = GetDeserializeMethod(&extInfo, withinClassTypeNameList);
    if (methodStr.length() == 0) {
        return;
    }

    TTypeInfo* type = nullptr;
    auto refType = Find(&extInfo, withinClassTypeNameList, type);

    auto str = fmt::format("{}(({}*){}, {});// Inheritances", methodStr, type->GetTypeNameWithNameSpace(), s_TypeObject, s_Obj);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::CollectorName(const std::string& name, int depth)
{
    return fmt::format("{}_c{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::ElementName(const std::string& name, int depth)
{
    return fmt::format("{}_e{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::IndexName(const std::string& name, int depth)
{
    return fmt::format("{}_i{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::SourceName(const std::string& name, int depth)
{
    return fmt::format("{}_src{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::ArrayName(const std::string& name, int depth)
{
    return fmt::format("{}_a{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::ObjectName(const std::string& name, int depth)
{
    return fmt::format("{}_o{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::TempName(const std::string& name, int depth)
{
    return fmt::format("{}_t{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
