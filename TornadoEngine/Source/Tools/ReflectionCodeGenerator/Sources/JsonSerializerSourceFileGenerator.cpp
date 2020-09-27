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
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mJsonSerializer->fileName + ".h");
    AddInclude("JsonPopMaster.h");
    AddInclude("JsonPushMaster.h");
    AddEmptyLine();

    auto namespaceName = mJsonSerializer->nameSpaceName;
    if ( namespaceName.length() ) {
        AddUsingNamespace(namespaceName);
    }

    AddEmptyLine();

    AddUsing(s_POM + " = TJsonPopMaster");
    AddUsing(s_PUM + " = TJsonPushMaster");

    AddEmptyLine();
    Add(fmt::format("std::map<std::string, {}::TypeFunc> {}::{};", mJsonSerializer->className, mJsonSerializer->className, s_TypeNameFuncsMap));
    Add(fmt::format("std::list<std::string> {}::{};", mJsonSerializer->className, s_TypeNameList));
    AddEmptyLine();

    AddInit();
    AddCommentedLongLine();

    AddConstContentMethods();

    AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddInit()
{
    auto className = mJsonSerializer->className;
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

    for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto pTypeInfo = filenameType.second.get();

            auto typeNameWithNameSpace = pTypeInfo->GetTypeNameWithNameSpace();

            auto typeNameObject = fmt::format("_{}TypeFunc", typeNameWithNameSpace);

            boost::replace_all(typeNameObject, "::", "_");

            Add(fmt::format("TypeFunc {};", typeNameObject));

            Add(fmt::format("{}.serializeFunc = [] (void* p, std::string& str) {{", typeNameObject));
            Add(fmt::format("Serialize<{}>(({}*) p, str);", typeNameWithNameSpace, typeNameWithNameSpace));
            Add("};");
            Add(fmt::format("{}.deserializeFunc = [] (void*& p, const std::string& str) {{", typeNameObject));
            Add(fmt::format("    Deserialize<{}>(({}*&) p, str);", typeNameWithNameSpace, typeNameWithNameSpace));
            Add("};");
            Add(fmt::format("{}.fillFunc = [] (void* p, const std::string& str) {{", typeNameObject));
            Add(fmt::format("    Fill<{}>(({}*) p, str);", typeNameWithNameSpace, typeNameWithNameSpace));
            Add("};");

            Add(fmt::format("{}.insert({{\"{}\", {} }});", s_TypeNameFuncsMap, typeNameWithNameSpace, typeNameObject));
            Add(fmt::format("{}.push_back(\"{}\");", s_TypeNameList, typeNameWithNameSpace));
            AddEmptyLine();
        }
    }

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddConstContentMethods()
{
    auto className = mJsonSerializer->className;

    Add(fmt::format("const std::list<std::string>& {}::{}()", className, s_GetTypeNameList));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("return {};", s_TypeNameList));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //======================
    Add(fmt::format("void {}::{}(void* p, std::string & str, const std::string & typeName)", className, s_SerializeByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("{}[typeName].serializeFunc(p, str);", s_TypeNameFuncsMap));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //======================
    Add(fmt::format("void {}::{}(void*& p, const std::string & str, const std::string & typeName)", className, s_DeserializeByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("{}[typeName].deserializeFunc(p, str);", s_TypeNameFuncsMap));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
    //======================
    Add(fmt::format("void {}::{}(void* p, const std::string & str, const std::string & typeName)", className, s_FillByTypeMethod));
    AddLeftBrace();
    IncrementTabs();

    Add(fmt::format("{}();", s_Init));
    Add(fmt::format("{}[typeName].fillFunc(p, str);", s_TypeNameFuncsMap));

    DecrementTabs();
    AddRightBrace();
    AddCommentedLongLine();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddImplementations()
{
    for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto pTypeInfo = filenameType.second.get();
            AddSerializeMethodImplementation(pTypeInfo);
            AddCommentedLongLine();
            AddDeserializeMethodImplementation(pTypeInfo);
            AddCommentedLongLine();
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddSerializeMethodImplementation(TTypeInfo* p)
{
    auto className = mJsonSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForSerialize(namespaceWithType);
    AddMethodImplementationBegin("void", className, sSerializeMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this] (const std::string& s) {AddCallingSerializeParent(s); });

    AddCallingMethod(p, [this] (TMemberInfo* mi) {AddPushByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddDeserializeMethodImplementation(TTypeInfo* p)
{
    auto className = mJsonSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForDeserialize(namespaceWithType);
    AddMethodImplementationBegin("void", className, sDeserializeMethod, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this] (const std::string& s) { AddCallingDeserializeParent(s); });

    AddCallingMethod(p, [this] (TMemberInfo* mi) {AddPopByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushByMemberInfo(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::vector<TMemberTypeExtendedInfo> extArr;
    if ( pExtArr == nullptr ) {
        if ( pExtArr == nullptr ) {
            pMemberInfo->CreateExtArray(extArr);
            pExtArr = &extArr;
        }
    }

    auto category = pExtArr->at(depth).mCategory;
    if ( pExtArr->at(depth).IsContainer() ) { // Continue
        switch ( category ) {
            case TMemberTypeExtendedInfo::Set:
                AddBeginPushListOrSet(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushListOrSet(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::List:
                AddBeginPushListOrSet(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushListOrSet(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Vector:
                AddBeginPushVector(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushVector(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Map:
                AddBeginPushMap(pMemberInfo, pExtArr, depth);
                AddPushByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPushMap(pMemberInfo, pExtArr, depth);
                break;
        }
    } else { // Dead end
        switch ( category ) {
            case TMemberTypeExtendedInfo::BuiltIn:
            case TMemberTypeExtendedInfo::String:
                AddPush(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Reflection:
                AddPushReflection(pMemberInfo, pExtArr, depth);
                break;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPush(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    if ( depth == 0 ) {
        AddPushZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPushDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr)
{
    auto str = fmt::format("{}::{}( {}, \"{}\", {}->{} );",
        s_PUM, s_Push, s_Obj, pMemberInfo->mName, s_TypeObject, pMemberInfo->mName);

    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string str;

    auto prevExt = &(pExtArr->at(depth - 1));
    auto curE = ElementName(pMemberInfo->mName, depth - 1);
    auto curC = CollectorName(pMemberInfo->mName, depth - 1);
    auto curA = ArrayName(pMemberInfo->mName, depth - 1);

    if ( prevExt->mCategory == TMemberTypeExtendedInfo::Map ) {
        str = fmt::format("{}::{}( {}, {}::{}({}.{}).data(), {}.{} );",
            s_PUM, s_Push, curC, s_PUM, s_ConvertToString, curE, s_First, curE, s_Second);
    } else {
        str = fmt::format("{}::{}( {}, {} );", s_PUM, s_PushToArray, curA, curE);
    }
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflection(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    if ( depth == 0 ) {
        AddPushReflectionZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPushReflectionDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr)
{
    std::string str;

    auto addObject = fmt::format("auto {}_o = {}::{}( {}, \"{}\");", pMemberInfo->mName, s_PUM, s_AddObject, s_Obj, pMemberInfo->mName);

    auto access = pMemberInfo->mExtendedInfo.mAccessMethod;
    if ( access == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        Add(addObject);
        str = fmt::format("{}( &({}->{}), {}_o );", sSerializeMethod, s_TypeObject, pMemberInfo->mName, pMemberInfo->mName);
        Add(str);
    } else {
        std::string ptr;
        if ( access == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
            ptr = fmt::format("{}->{}.get()", s_TypeObject, pMemberInfo->mName);
        } else {
            ptr = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
        }

        str = fmt::format("if ( {} == {} ) {{", ptr, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}::{}( {}, \"{}\");", s_PUM, s_PushNull, s_Obj, pMemberInfo->mName);
        Add(str);
        DecrementTabs();
        Add("} else {");
        IncrementTabs();
        Add(addObject);
        str = fmt::format("{}( {}, {}_o );", sSerializeMethod, ptr, pMemberInfo->mName);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto prevExt = &(pExtArr->at(depth - 1));
    switch ( prevExt->mCategory ) {
        case TMemberTypeExtendedInfo::Set:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Vector:
            AddPushReflectionDepthSetListVector(pMemberInfo, pExtArr, depth);
            break;
        case TMemberTypeExtendedInfo::Map:
            AddPushReflectionDepthMap(pMemberInfo, pExtArr, depth);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string str;
    std::string prevObj;
    if ( depth == 1 ) {
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
    if ( access == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kObjectType);
        Add(str);
        str = fmt::format("auto {} = {}.{}();", curC, curA, s_GetObject);
        Add(str);
        str = fmt::format("{}( &{}, {} );", sSerializeMethod, curE, curC);
        Add(str);
        str = fmt::format("{}::{}( {}, {} );", s_PUM, s_PushToArray, prevA, curA);
        Add(str);
    } else {
        std::string ptr;
        if ( access == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
            ptr = fmt::format("{}.get()", curE);
        } else {
            ptr = fmt::format("{}", curE);
        }

        str = fmt::format("if ( {} == {} ) {{", ptr, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}::{}( {} );", s_PUM, s_PushToArrayNull, prevA);
        Add(str);
        DecrementTabs();
        Add("} else {");
        IncrementTabs();
        str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kObjectType);
        Add(str);
        str = fmt::format("auto {} = {}.{}();", curC, curA, s_GetObject);
        Add(str);
        str = fmt::format("{}( {}, {} );", sSerializeMethod, ptr, curC);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushReflectionDepthMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string str;
    std::string prevObj;
    if ( depth == 1 ) {
        prevObj = s_Obj;
    } else {
        prevObj = CollectorName(pMemberInfo->mName, depth - 1);
    }

    auto curE = ElementName(pMemberInfo->mName, depth - 1);
    auto prevC = CollectorName(pMemberInfo->mName, depth - 1);

    auto curA = ArrayName(pMemberInfo->mName, depth - 1);

    auto access = pExtArr->at(depth).mAccessMethod;
    if ( access == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        str = fmt::format("auto {} = {}::{}( {}, {}::{}({}.first).data() );", curA, s_PUM, s_AddObject, prevC,
            s_PUM, s_ConvertToString, curE);
        Add(str);
        str = fmt::format("{}( &({}.second), {} );", sSerializeMethod, curE, curA);
        Add(str);
    } else {
        std::string ptr;
        if ( access == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
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
        str = fmt::format("auto {} = {}::{}( {}, {}::{}({}.first).data() );",
            curA, s_PUM, s_AddObject, prevObj, s_PUM, s_ConvertToString, curE);
        Add(str);
        str = fmt::format("{}( {}, {} );", sSerializeMethod, ptr, prevObj);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPushListOrSet(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kArrayType);
    Add(str);

    auto curI = IndexName(pMemberInfo->mName, depth);

    std::string prevE;
    if ( depth == 0 ) {
        prevE = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
            accessToElement = ".second";
        }
        prevE = ElementName(pMemberInfo->mName, depth - 1) + accessToElement;
    }
    auto curE = ElementName(pMemberInfo->mName, depth);
    str = fmt::format("for( auto& {} : {} ) {{", curE, prevE);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushListOrSet(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);

    if ( depth == 0 ) {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        str = fmt::format("{}::{}({}, \"{}\", {});", s_PUM, s_Push, s_Obj, pMemberInfo->mName, curA);
        Add(str);
    } else {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
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
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto str = fmt::format("{}::{} {}({});", s_PUM, s_Value, curA, s_kArrayType);
    Add(str);

    auto curI = IndexName(pMemberInfo->mName, depth);

    std::string prevE;
    if ( depth == 0 ) {
        prevE = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
            accessToElement = ".second";
        }
        prevE = ElementName(pMemberInfo->mName, depth - 1) + accessToElement;
    }
    str = fmt::format("for( size_t {} = 0 ; {} < {}.size() ; {}++ ) {{", curI, curI, prevE, curI);
    Add(str);

    IncrementTabs();
    auto curE = ElementName(pMemberInfo->mName, depth);
    str = fmt::format("auto& {} = {}[{}];", curE, prevE, curI);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);

    if ( depth == 0 ) {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        str = fmt::format("{}::{}({}, \"{}\", {});", s_PUM, s_Push, s_Obj, pMemberInfo->mName, curA);
        Add(str);
    } else {
        auto curA = ArrayName(pMemberInfo->mName, depth);
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
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
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string curSrc;
    std::string prevObj;
    std::string prevKey;
    if ( depth == 0 ) {
        curSrc = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
        prevObj = s_Obj;
        prevKey = fmt::format("\"{}\"", pMemberInfo->mName);
    } else {
        std::string accessToSrc;
        std::string accessToElement;
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
            accessToSrc = ".second";
            accessToElement = ".first";
        }
        curSrc = fmt::format("{}", ElementName(pMemberInfo->mName, depth - 1)) + accessToSrc;
        prevObj = CollectorName(pMemberInfo->mName, depth - 1);
        prevKey = fmt::format("{}::{}({}{}).data()", s_PUM, s_ConvertToString, ElementName(pMemberInfo->mName, depth - 1), accessToElement);
    }
    auto curC = CollectorName(pMemberInfo->mName, depth);
    std::string str;
    if ( depth == 0 ) {
        str = fmt::format("auto {} = {}::{}({}, {});", curC, s_PUM, s_AddObject, prevObj, prevKey);
        Add(str);
    } else {
        auto prevCategory = pExtArr->at(depth - 1).mCategory;
        if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
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
    str = fmt::format("for( auto& {} : {} ) {{", curE, curSrc);
    Add(str);

    IncrementTabs();

    auto curCategory = pExtArr->at(depth).mCategory;
    if ( curCategory != TMemberTypeExtendedInfo::TypeCategory::Map ) {
        auto nextC = CollectorName(pMemberInfo->mName, depth + 1);
        str = fmt::format("auto& {} = {};", nextC, curC);
        Add(str);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPushMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    DecrementTabs();

    std::string str = "}";
    Add(str);

    auto prevCategory = pExtArr->at(depth).mCategory;
    if ( prevCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
        return;
    }

    if ( depth == 0 ) {
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
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::vector<TMemberTypeExtendedInfo> extArr;
    if ( pExtArr == nullptr ) {
        if ( pExtArr == nullptr ) {
            pMemberInfo->CreateExtArray(extArr);
            pExtArr = &extArr;
        }
    }

    auto category = pExtArr->at(depth).mCategory;
    if ( pExtArr->at(depth).IsContainer() ) { // Continue
        switch ( category ) {
            case TMemberTypeExtendedInfo::Set:
                AddBeginPopListSetVector(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::List:
                AddBeginPopListSetVector(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Vector:
                AddBeginPopListSetVector(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Map:
                AddBeginPopMap(pMemberInfo, pExtArr, depth);
                AddPopByMemberInfo(pMemberInfo, pExtArr, depth + 1);
                AddEndPop(pMemberInfo, pExtArr, depth);
                break;
        }
    } else { // Dead end
        switch ( category ) {
            case TMemberTypeExtendedInfo::BuiltIn:
            case TMemberTypeExtendedInfo::String:
                AddPop(pMemberInfo, pExtArr, depth);
                break;
            case TMemberTypeExtendedInfo::Reflection:
                AddPopReflection(pMemberInfo, pExtArr, depth);
                break;
        }
    }

}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPop(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    if ( depth == 0 ) {
        AddPopZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPopDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr)
{
    std::string pop;

    auto category = pExtArr->at(0).mCategory;
    switch ( category ) {
        case TMemberTypeExtendedInfo::TypeCategory::BuiltIn:
            if ( pExtArr->at(0).IsBool() ) {
                pop = s_PopBool;
            } else {
                pop = s_PopNum;
            }
            break;
        case TMemberTypeExtendedInfo::TypeCategory::String:
            pop = s_PopStr;
            break;
    }
    auto str = fmt::format("{}::{}( {}, \"{}\", {}->{} );",
        s_POM, pop, s_Obj, pMemberInfo->mName, s_TypeObject, pMemberInfo->mName);

    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string str;

    auto prevExt = &(pExtArr->at(depth - 1));
    auto curExt = &(pExtArr->at(depth));
    auto curE = ElementName(pMemberInfo->mName, depth - 1);

    std::string curC;
    if ( depth == 1 ) {
        curC = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        curC = CollectorName(pMemberInfo->mName, depth - 1);
    }

    if ( prevExt->mCategory == TMemberTypeExtendedInfo::Map ) {
        auto get = s_GetInt64;
        if ( curExt->mCategory == TMemberTypeExtendedInfo::TypeCategory::BuiltIn ) {
            if ( curExt->IsFloatingPoint() ) {
                get = s_GetDouble;
            } else if ( curExt->IsBool() ) {
                get = s_GetBool;
            }
        } else {
            get = s_GetString;
        }

        std::string key = fmt::format("{}.name.{}()", curE, s_GetString);
        auto keyExt = prevExt->mTemplateChildArr.at(0);
        if ( keyExt.mCategory != TMemberTypeExtendedInfo::TypeCategory::String ) {
            key = fmt::format("{}({})", s_StrToNum, key);
        }

        str = fmt::format("{}.{}({{ {}, {}.value.{}() }});", curC, s_Insert, key, curE, get);
    } else {

        auto add = s_PushBack;
        if ( prevExt->mCategory == TMemberTypeExtendedInfo::Set ) {
            add = s_Insert;
        }
        auto get = s_GetInt64;
        if ( curExt->mCategory == TMemberTypeExtendedInfo::TypeCategory::BuiltIn ) {
            if ( curExt->IsFloatingPoint() ) {
                get = s_GetDouble;
            } else if ( curExt->IsBool() ) {
                get = s_GetBool;
            }
        } else {
            get = s_GetString;
        }
        str = fmt::format("{}.{}({}.{}());", curC, add, curE, get);
    }
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflection(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    if ( depth == 0 ) {
        AddPopReflectionZeroDepth(pMemberInfo, pExtArr);
    } else {
        AddPopReflectionDepth(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionZeroDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr)
{
    auto curO = ObjectName(pMemberInfo->mName, 0);
    auto accessMethod = pExtArr->at(0).mAccessMethod;
    if ( accessMethod == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        auto str = fmt::format("auto {} = {}::{}({}, \"{}\");", curO, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
        Add(str);
        str = fmt::format("{}(&({}->{}), {});",
            sDeserializeMethod, s_TypeObject, pMemberInfo->mName, curO);
        Add(str);
    } else {

        std::string get = pMemberInfo->mName;
        std::string reset;
        if ( accessMethod == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
            reset = fmt::format("{}.reset(new {}())", pMemberInfo->mName, pMemberInfo->mExtendedInfo.GetTypeNameWithNameSpace());
            get += ".get()";
        } else {
            reset = fmt::format("{} = new {}()", pMemberInfo->mName, pMemberInfo->mExtendedInfo.GetTypeNameWithNameSpace());
        }

        auto str = fmt::format("if ( !{}::{}({}, \"{}\") ) {{", s_POM, s_IsNull, s_Obj, pMemberInfo->mName);
        Add(str);
        IncrementTabs();
        str = fmt::format("if ( {}->{} == {} ) {{", s_TypeObject, get, s_Nullptr);
        Add(str);
        IncrementTabs();
        str = fmt::format("{}->{};", s_TypeObject, reset);
        Add(str);
        DecrementTabs();
        Add("}");

        str = fmt::format("auto {} = {}::{}({}, \"{}\");",
            curO, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
        Add(str);

        str = fmt::format("{}( {}->{}, {});", sDeserializeMethod, s_TypeObject, get, curO);
        Add(str);
        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepth(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto prevExt = &(pExtArr->at(depth - 1));
    switch ( prevExt->mCategory ) {
        case TMemberTypeExtendedInfo::Set:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Vector:
            AddPopReflectionDepthSetListVector(pMemberInfo, pExtArr, depth);
            break;
        case TMemberTypeExtendedInfo::Map:
            AddPopReflectionDepthMap(pMemberInfo, pExtArr, depth);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curC = CollectorName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    auto category = pExtArr->at(depth).mAccessMethod;
    auto type = pExtArr->at(depth).GetTypeNameWithNameSpace();
    auto sptype = pExtArr->at(depth).mSmartPtrType;

    auto dst = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    if ( depth != 1 ) {
        dst = CollectorName(pMemberInfo->mName, depth - 1);
    }

    if ( category == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        auto str = fmt::format("auto {} = {}.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("{} {};", type, curC);
        Add(str);
        str = fmt::format("{}(&{}, {});", sDeserializeMethod, curC, curO);
        Add(str);
        str = fmt::format("{}.{}({});", dst, s_PushBack, curC);
        Add(str);
    } else {
        std::string access;
        std::string newExp;
        if ( category == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
            access = ".get()";
            newExp = fmt::format("{}{}<{}>(new {}())", s_STD_, sptype, type, type);
        } else {
            newExp = fmt::format("new {}", type);
        }

        auto str = fmt::format("if (!{}.{}() ) {{", prevE, s_IsNull);
        Add(str);
        IncrementTabs();
        str = fmt::format("auto {} = {}.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("auto {} = {};", curC, newExp);
        Add(str);
        str = fmt::format("{}({}{}, {});", sDeserializeMethod, curC, access, curO);
        Add(str);
        str = fmt::format("{}.{}({});", dst, s_PushBack, curC);
        Add(str);

        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopReflectionDepthMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curC = CollectorName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    auto category = pExtArr->at(depth).mAccessMethod;
    auto type = pExtArr->at(depth).GetTypeNameWithNameSpace();
    auto sptype = pExtArr->at(depth).mSmartPtrType;

    auto curExt = &(pExtArr->at(depth));

    auto get = s_GetInt64;
    if ( curExt->mCategory == TMemberTypeExtendedInfo::TypeCategory::BuiltIn ) {
        if ( curExt->IsFloatingPoint() ) {
            get = s_GetDouble;
        } else if ( curExt->IsBool() ) {
            get = s_GetBool;
        }
    } else {
        get = s_GetString;
    }

    std::string key = fmt::format("{}.name.{}()", prevE, s_GetString);
    auto keyExt = pExtArr->at(depth-1).mTemplateChildArr.at(0);
    if ( keyExt.mCategory != TMemberTypeExtendedInfo::TypeCategory::String ) {
        key = fmt::format("{}({})", s_StrToNum, key);
    }

    auto dst = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    if ( depth != 1 ) {
        dst = CollectorName(pMemberInfo->mName, depth - 1);
    }

    if ( category == TMemberTypeExtendedInfo::AccessMethod::Object ) {
        auto str = fmt::format("auto {} = {}.value.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("{} {};", type, curC);
        Add(str);
        str = fmt::format("{}(&{}, {});", sDeserializeMethod, curC, curO);
        Add(str);
        str = fmt::format("{}.{}({{ {}, {} }});", dst, s_Insert, key, curC);
        Add(str);
    } else {
        std::string access;
        std::string newExp;
        if ( category == TMemberTypeExtendedInfo::AccessMethod::SmartPointer ) {
            access = ".get()";
            newExp = fmt::format("{}{}<{}>(new {}())", s_STD_, sptype, type, type);
        } else {
            newExp = fmt::format("new {}", type);
        }

        auto str = fmt::format("if (!{}.value.{}() ) {{", prevE, s_IsNull);
        Add(str);
        IncrementTabs();
        str = fmt::format("auto {} = {}.value.{}();", curO, prevE, s_GetObject);
        Add(str);
        str = fmt::format("auto {} = {};", curC, newExp);
        Add(str);
        str = fmt::format("{}({}{}, {});", sDeserializeMethod, curC, access, curO);
        Add(str);
        str = fmt::format("{}.{}({{ {}, {} }});", dst, s_Insert, key, curC);
        Add(str);

        DecrementTabs();
        Add("}");
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddBeginPopListSetVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    std::string curName;
    std::string str;
    if ( depth == 0 ) {

        str = fmt::format("auto {} = {}::{}({}, \"{}\");", curA, s_POM, s_FindArray, s_Obj, pMemberInfo->mName);
        Add(str);
    } else {
        std::string access;
        if ( pExtArr->at(depth - 1).mCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
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

    str = fmt::format("for( auto& {} : {} ) {{", curE, curA);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPopListSetVector(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string add;
    if ( pExtArr->at(depth - 1).mCategory == TMemberTypeExtendedInfo::TypeCategory::Set ) {
        add = s_Insert;
    } else {
        add = s_PushBack;
    }

    std::string access;
    if ( depth == 1 ) {
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
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    auto curA = ArrayName(pMemberInfo->mName, depth);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto curO = ObjectName(pMemberInfo->mName, depth);

    std::string curName;
    std::string str;
    if ( depth == 0 ) {

        str = fmt::format("auto {} = {}::{}({}, \"{}\");", curA, s_POM, s_FindObject, s_Obj, pMemberInfo->mName);
        Add(str);
    } else {

        std::string access;
        if ( pExtArr->at(depth - 1).mCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
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

    str = fmt::format("for( auto& {} : {} ) {{", curE, curA);
    Add(str);

    IncrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPop(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    DecrementTabs();
    Add("}");

    if ( depth == 0 ) {
        return;
    }

    if ( pExtArr->at(depth - 1).mCategory == TMemberTypeExtendedInfo::TypeCategory::Map ) {
        AddEndPopMap(pMemberInfo, pExtArr, depth);
    } else {
        AddEndPopListSetVector(pMemberInfo, pExtArr, depth);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddEndPopMap(TMemberInfo* pMemberInfo,
    std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth)
{
    std::string access;
    if ( depth == 1 ) {
        access = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
    } else {
        access = CollectorName(pMemberInfo->mName, depth - 1);
    }
    auto nextC = CollectorName(pMemberInfo->mName, depth);

    std::string getKey = s_GetString;
    auto keyInfo = pExtArr->at(depth - 1).mTemplateChildArr.at(0);
    if ( keyInfo.mCategory == TMemberTypeExtendedInfo::TypeCategory::BuiltIn ) {
        if ( keyInfo.IsFloatingPoint() ) {
            getKey = s_GetDouble;
        } else if ( keyInfo.IsBool() ) {
            getKey = s_GetBool;
        } else {
            getKey = s_GetInt64;
        }
    }

    auto prevE = ElementName(pMemberInfo->mName, depth - 1);
    auto curE = ElementName(pMemberInfo->mName, depth);
    auto key = fmt::format("{}.name.{}()", prevE, getKey);

    auto str = fmt::format("{}.{}({{ {}, {} }});", access, s_Insert, key, nextC);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingSerializeParent(const std::string& parentTypeName)
{
    auto str = fmt::format("{}( ({}*){}, {});// Inheritances", sSerializeMethod, parentTypeName, s_TypeObject, s_Obj);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingDeserializeParent(const std::string& parentTypeName)
{
    auto str = fmt::format("{}( ({}*){}, {});// Inheritances", sDeserializeMethod, parentTypeName, s_TypeObject, s_Obj);
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
