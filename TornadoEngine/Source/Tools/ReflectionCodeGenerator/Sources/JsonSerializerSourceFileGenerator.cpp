/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mJsonSerializer->fileName + ".h");
    //AddInclude("fmt/core.h");
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
    AddImplementations();
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
void TJsonSerializerSourceFileGenerator::AddPushByMemberInfo(TMemberInfo* pMemberInfo)
{
    switch ( pMemberInfo->mExtendedInfo.mCategory ) {
        case TMemberTypeExtendedInfo::BuiltIn:
        case TMemberTypeExtendedInfo::String:
        case TMemberTypeExtendedInfo::Set:
            AddPush(pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Vector:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Map:
        {
            AddEmptyLine();
            auto extArr = pMemberInfo->CreateExtArray();
            HandleComplexPushZeroDepth(extArr, pMemberInfo->mName);
        }
        break;
        case TMemberTypeExtendedInfo::Reflection:
            HandleReflectionForPush(pMemberInfo);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopByMemberInfo(TMemberInfo* pMemberInfo)
{
    switch ( pMemberInfo->mExtendedInfo.mCategory ) {
        case TMemberTypeExtendedInfo::BuiltIn:
            HandlePopBuiltIn(pMemberInfo);
            break;
        case TMemberTypeExtendedInfo::String:
            AddPopStr(pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Set:
            HandlePopSet(pMemberInfo);
            break;
        case TMemberTypeExtendedInfo::Vector:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Map:
        {
            AddEmptyLine();
            auto extArr = pMemberInfo->CreateExtArray();
            HandleComplexPopZeroDepth(extArr, pMemberInfo->mName);
        }
        break;
        case TMemberTypeExtendedInfo::Reflection:
            HandlePopReflection(pMemberInfo);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPush(const std::string& name)
{
    std::list<std::string> argList =
    {
        s_Obj,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallFunction(s_PUM, s_Push, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingSerializeParent(const std::string& parentTypeName)
{
    auto str = fmt::format("{}( ({}*){}, {});", sSerializeMethod, parentTypeName, s_TypeObject, s_Obj);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingDeserializeParent(const std::string& parentTypeName)
{
    auto str = fmt::format("{}( ({}*){}, {});", sDeserializeMethod, parentTypeName, s_TypeObject, s_Json);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleComplexPushZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name)
{
    int depth = 0;

    std::string pushMethod = s_Push;
    std::string collectorType = s_Jarr;

    auto category = extArr[depth].mCategory;

    if ( category == TMemberTypeExtendedInfo::Map ) {
        pushMethod = s_PushMap;
        collectorType = s_Jobj;
    }

    auto collectorName = CollectorName(name, depth);
    auto collectorDeclaration = fmt::format("{} {};", collectorType, collectorName);
    Add(collectorDeclaration);

    auto srcArray = fmt::format("{}->{}", s_TypeObject, name);

    auto elementName = ElementName(name, depth);
    auto forExpression = fmt::format("for ( auto& {} : {} )", elementName, srcArray);

    Add(forExpression);

    General_HandleComplexPush(extArr, name, depth);

    // summarize all
    std::list<std::string> argList =
    {
        s_Obj,
        fmt::format("\"{}\"", name),
        fmt::format("{}", collectorName),
    };
    std::list<std::string> templList;
    AddCallFunction(s_PUM, pushMethod, templList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleComplexPush(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    if ( depth == 0 ) {
        BL_FIX_BUG();
        return;
    }

    std::string collectorType = s_Jarr;
    auto category = extArr[depth].mCategory;

    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map )
        collectorType = s_Jobj;

    auto collectorName = CollectorName(name, depth);
    auto collectorDeclaration = fmt::format("{} {};", collectorType, collectorName);
    Add(collectorDeclaration);

    auto prevElementName = ElementName(name, depth - 1);

    std::string srcArray;
    if ( extArr[depth - 1].mCategory == TMemberTypeExtendedInfo::Map )
        srcArray = fmt::format("{}.{}", prevElementName, s_Second);
    else
        srcArray = prevElementName;

    auto elementName = ElementName(name, depth);

    auto forExpression = fmt::format("for ( auto& {} : {} )", elementName, srcArray);
    Add(forExpression);

    General_HandleComplexPush(extArr, name, depth);

    AddPushByElementName(extArr, name, depth - 1, collectorName);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_HandleComplexPush(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    AddLeftBrace();
    IncrementTabs();

    auto& templateType = extArr[depth].mTemplateChildArr.back();// use last, cause if array - first, map - second 
    auto templateCategory = templateType.mCategory;
    switch ( templateCategory ) {
        case TMemberTypeExtendedInfo::BuiltIn:
        case TMemberTypeExtendedInfo::String:
            HandlePushSimple(extArr, name, depth);
            break;
        case TMemberTypeExtendedInfo::Vector:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Set:
            HandleComplexPush(extArr, name, depth + 1);
            break;
        case TMemberTypeExtendedInfo::Map:
            HandleComplexPush(extArr, name, depth + 1);
            break;
        case TMemberTypeExtendedInfo::Reflection:
            HandlePushReflection(extArr, name, depth);
            break;
    }
    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePushSimple(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto elementName = ElementName(name, depth);
    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map )
        elementName = fmt::format("{}.{}", elementName, s_Second);

    AddPushByElementName(extArr, name, depth, elementName);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePushReflection(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto objForSer = fmt::format("{}_e{}_{}", name, depth, s_Obj);
    auto objForSerDeclaration = fmt::format("{} {};", s_Jobj, objForSer);
    Add(objForSerDeclaration);

    auto elementName = ElementName(name, depth);

    auto accessDecl = elementName;
    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map )
        accessDecl = fmt::format("{}.{}", elementName, s_Second);

    auto valueName = fmt::format("{}_value", elementName);
    auto elementFromDecl = fmt::format("auto& {} = {};", valueName, accessDecl);
    Add(elementFromDecl);

    auto ptrName = fmt::format("{}_ptr", elementName);
    auto ptrDecl = fmt::format("auto {} = ", ptrName);
    std::string ptrDeclExpression;

    auto& templateType = extArr[depth].mTemplateChildArr.back();// use last, cause if array - first, map - second 
    switch ( templateType.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            ptrDeclExpression = fmt::format("{}&{};", ptrDecl, valueName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
            ptrDeclExpression = fmt::format("{}{};", ptrDecl, valueName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            ptrDeclExpression = fmt::format("{}{}.get();", ptrDecl, valueName);
            break;
    }
    Add(ptrDeclExpression);

    AddIf(ptrName);

    AddLeftBrace();
    IncrementTabs();
    auto callSerExpression = fmt::format("{}( {}, {} );", sSerializeMethod, ptrName, objForSer);
    Add(callSerExpression);
    AddPushByElementName(extArr, name, depth, objForSer);
    DecrementTabs();
    AddRightBrace();
    AddElse();

    IncrementTabs();
    AddPushByElementName(extArr, name, depth, s_Nullptr);
    DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushByElementName(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth, std::string elementNameFirstOrSecond)
{
    auto collectorName = CollectorName(name, depth);
    auto elementName = ElementName(name, depth);
    std::string addExpression;
    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map ) {
        auto first = fmt::format("{}.{}", elementName, s_First);

        auto firstExpression = fmt::format("{}::{}( {} )", s_PUM, s_ConvertToString, first);
        addExpression = fmt::format("{}.{}( {{ {}, {} }} );", collectorName, s_Insert, firstExpression, elementNameFirstOrSecond);
    } else {
        addExpression = fmt::format("{}.{}( {} );", collectorName, s_PushBack, elementNameFirstOrSecond);
    }
    Add(addExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleComplexPopZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name)
{
    int depth = 0;

    auto sourceJsonName = SourceName(name, depth);
    std::string itemsAccess = s_Array_items;
    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map )
        itemsAccess = s_Object_items;

    auto collectorDeclExpression = fmt::format("auto& {} = {}[\"{}\"].{}();", sourceJsonName, s_Json, name, itemsAccess);
    Add(collectorDeclExpression);

    auto elementName = ElementName(name, depth);
    auto forExpression = fmt::format("for ( auto& {} : {} )", elementName, sourceJsonName);
    Add(forExpression);

    General_HandleComplexPop(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleComplexPop(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto collectorType = fmt::format("{}", extArr[depth].GetCollectSubType());
    auto collectorName = CollectorName(name, depth);
    auto collectorDeclaration = fmt::format("{} {};", collectorType, collectorName);
    Add(collectorDeclaration);

    auto itemMethod = s_Array_items;
    if ( extArr[depth].mCategory == TMemberTypeExtendedInfo::Map )
        itemMethod = s_Object_items;

    auto elementName = ElementName(name, depth - 1);
    std::string elementAccess;
    if ( extArr[depth - 1].mCategory == TMemberTypeExtendedInfo::Map )
        elementAccess = fmt::format(".{}", s_Second);

    auto itemContainerName = SourceName(name, depth);
    auto itemContainerExpression = fmt::format("auto& {} = {}{}.{}();", itemContainerName, elementName, elementAccess, itemMethod);
    Add(itemContainerExpression);

    auto forElementName = ElementName(name, depth);
    auto forExpression = fmt::format("for ( auto& {} : {} )", forElementName, itemContainerName);
    Add(forExpression);

    General_HandleComplexPop(extArr, name, depth);

    if ( depth == 1 ) {
        auto popStr = GetPopStrForComplex(extArr, name, depth);

        auto addExpression = fmt::format("{}->{}.{};", s_TypeObject, name, popStr);
        Add(addExpression);
    } else {
        auto prevCollectorName = CollectorName(name, depth - 1);
        auto popStr = GetPopStrForComplex(extArr, name, depth);

        auto addExpression = fmt::format("{}.{};", prevCollectorName, popStr);
        Add(addExpression);
    }
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::GetPopStrForComplex(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto collectorName = CollectorName(name, depth);
    auto elementName = ElementName(name, depth - 1);

    auto addParam = collectorName;
    auto addMethod = s_PushBack;
    if ( extArr[depth - 1].mCategory == TMemberTypeExtendedInfo::Map ) {
        addMethod = s_Insert;
        auto& keyExt = extArr[depth - 1].mTemplateChildArr[0];

        std::string itemAccess;
        auto key = fmt::format("{}.{}", elementName, s_First);
        if ( keyExt.mCategory == TMemberTypeExtendedInfo::BuiltIn )
            key = fmt::format("{}( {} )", s_StrToNum, key);

        auto conversion = GetConversionBuiltIn(keyExt);
        if ( conversion.length() > 0 )
            key = fmt::format("({})({})", conversion, key);

        auto value = collectorName;
        addParam = fmt::format("{{ {}, {} }}", key, value);
    }

    auto addExpression = fmt::format("{}( {} )", addMethod, addParam);
    return addExpression;
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_HandleComplexPop(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    AddLeftBrace();
    IncrementTabs();

    auto templateCategory = extArr[depth + 1].mCategory;
    switch ( templateCategory ) {
        case TMemberTypeExtendedInfo::BuiltIn:
        case TMemberTypeExtendedInfo::String:
            if ( depth > 0 )
                HandlePopSimple(extArr, name, depth);
            else
                HandlePopSimpleZeroDepth(extArr, name);
            break;
        case TMemberTypeExtendedInfo::Vector:
        case TMemberTypeExtendedInfo::List:
        case TMemberTypeExtendedInfo::Set:
            HandleComplexPop(extArr, name, depth + 1);
            break;
        case TMemberTypeExtendedInfo::Map:
            HandleComplexPop(extArr, name, depth + 1);
            break;
        case TMemberTypeExtendedInfo::Reflection:
            HandlePopReflection(extArr, name, depth);
            break;
    }

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopSimple(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto collectorName = CollectorName(name, depth);
    auto elementName = ElementName(name, depth);

    std::string addMethod;
    std::string param;
    auto& ext = extArr[depth];
    auto& keyExt = ext.mTemplateChildArr[0];
    if ( ext.mCategory == TMemberTypeExtendedInfo::Map ) {
        addMethod = s_Insert;

        auto key = fmt::format("{}.{}", elementName, s_First);
        if ( keyExt.mCategory == TMemberTypeExtendedInfo::BuiltIn )
            key = fmt::format("{}( {} )", s_StrToNum, key);

        auto conversion = GetConversionBuiltIn(keyExt);
        if ( conversion.length() > 0 )
            key = fmt::format("({})({})", conversion, key);

        auto& valueExt = ext.mTemplateChildArr[1];
        auto valueItemAccess = ItemAccessByCategory(valueExt);
        auto value = fmt::format("{}.{}.{}()", elementName, s_Second, valueItemAccess);
        conversion = GetConversionBuiltIn(valueExt);
        if ( conversion.length() > 0 )
            value = fmt::format("({})({})", conversion, value);

        param = fmt::format("{{ {}, {} }}", key, value);
    } else {
        addMethod = s_PushBack;
        auto keyItemAccess = ItemAccessByCategory(keyExt);
        param = fmt::format("{}.{}()", elementName, keyItemAccess);

        auto conversion = GetConversionBuiltIn(keyExt);
        if ( conversion.length() > 0 )
            param = fmt::format("({})({})", conversion, param);
    }

    auto addExpression = fmt::format("{}.{}( {} );", collectorName, addMethod, param);
    Add(addExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopSimpleZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name)
{
    auto ext = extArr[0];
    auto& keyExt = ext.mTemplateChildArr[0];

    auto elementName = ElementName(name, 0);

    auto addMethod = s_PushBack;
    auto itemAccess = ItemAccessByCategory(keyExt);
    std::string addParam = fmt::format("{}.{}()", elementName, itemAccess);
    auto conversion = GetConversionBuiltIn(keyExt);
    if ( conversion.length() > 0 )
        addParam = fmt::format("({})({})", conversion, addParam);
    if ( ext.mCategory == TMemberTypeExtendedInfo::Map ) {
        addMethod = s_Insert;
        auto key = fmt::format("{}.{}", elementName, s_First);
        if ( keyExt.mCategory == TMemberTypeExtendedInfo::BuiltIn )
            key = fmt::format("{}( {} )", s_StrToNum, key);

        conversion = GetConversionBuiltIn(keyExt);
        if ( conversion.length() > 0 )
            key = fmt::format("({})({})", conversion, key);

        auto& valueExt = ext.mTemplateChildArr[1];
        itemAccess = ItemAccessByCategory(valueExt);
        conversion = GetConversionBuiltIn(valueExt);
        auto value = fmt::format("{}.{}.{}()", elementName, s_Second, itemAccess);
        if ( conversion.length() > 0 )
            value = fmt::format("({})({})", conversion, value);
        addParam = fmt::format("{{ {}, {} }}", key, value);
    }

    auto popExpression = fmt::format("{}( {} )", addMethod, addParam);

    auto addExpression = fmt::format("{}->{}.{};", s_TypeObject, name, popExpression);
    Add(addExpression);
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::GetConversionBuiltIn(const TMemberTypeExtendedInfo& ext)
{
    if ( ext.mCategory != TMemberTypeExtendedInfo::BuiltIn )
        return "";
    if ( ext.mType == s_Bool )
        return "";
    return ext.mType;
}
//-----------------------------------------------------------------------------------------------------------
std::string TJsonSerializerSourceFileGenerator::ItemAccessByCategory(const TMemberTypeExtendedInfo& ext)
{
    std::string itemAccess;
    if ( ext.mCategory == TMemberTypeExtendedInfo::String )
        itemAccess = s_String_value;
    else if ( ext.mCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        if ( ext.mType == s_Bool )
            itemAccess = s_Bool_value;
        else
            itemAccess = s_Number_value;
    }
    return itemAccess;
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
void TJsonSerializerSourceFileGenerator::HandlePopReflection(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth)
{
    auto& ext = extArr[depth];
    auto elementName = ElementName(name, depth);

    auto firstElement = ElementName(s_First, depth);
    auto secondElement = ElementName(s_Second, depth);

    auto& reflectionExt = ext.mTemplateChildArr.back();
    auto reflectionType = reflectionExt.GetCollectSubType();
    auto reflectionName = fmt::format("{}_newObj{}", name, depth);

    std::string elementWithReflection;
    std::string addMethod;
    std::string param;

    if ( ext.mCategory == TMemberTypeExtendedInfo::Map ) {
        auto firstDeclaration = fmt::format("auto& {} = {}.{};", firstElement, elementName, s_First);
        auto secondDeclaration = fmt::format("auto& {} = {}.{};", secondElement, elementName, s_Second);
        Add(firstDeclaration);
        Add(secondDeclaration);

        elementWithReflection = secondElement;
        addMethod = s_Insert;

        auto& keyExt = ext.mTemplateChildArr[0];
        auto key = fmt::format("{}.{}", elementName, s_First);
        if ( keyExt.mCategory == TMemberTypeExtendedInfo::BuiltIn )
            key = fmt::format("{}( {} )", s_StrToNum, key);

        auto conversion = GetConversionBuiltIn(keyExt);
        if ( conversion.length() > 0 )
            key = fmt::format("({})({})", conversion, key);

        auto value = reflectionName;
        param = fmt::format("{{ {}, {} }}", key, value);
    } else {
        auto firstDeclaration = fmt::format("auto& {} = {};", firstElement, elementName);
        Add(firstDeclaration);

        elementWithReflection = firstElement;
        addMethod = s_PushBack;

        param = reflectionName;
    }

    auto nullExpression = GetNullExpression(reflectionExt);
    auto reflectionDecl = fmt::format("{} {}{};", reflectionType, reflectionName, nullExpression);
    Add(reflectionDecl);

    auto condition = fmt::format("{}.{}() == false", elementWithReflection, s_IsNull);
    AddIf(condition);
    AddLeftBrace();
    IncrementTabs();

    auto collectorName = CollectorName(name, depth);

    auto& templateType = ext.mTemplateChildArr.back();// use last, cause if array - first, map - second 
    auto typeName = templateType.GetTypeNameWithNameSpace();
    std::string newExpression;
    std::string getPtr;
    switch ( templateType.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            getPtr = fmt::format("&{}", reflectionName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
            newExpression = fmt::format("{} = new {}();", reflectionName, typeName);
            getPtr = fmt::format("{}", reflectionName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            newExpression = fmt::format("{}.reset( new {}() );", reflectionName, typeName);
            getPtr = fmt::format("{}.get()", reflectionName);
            break;
    }

    if ( newExpression.length() > 0 )
        Add(newExpression);

    auto deser = fmt::format("{}( {}, {} );", sDeserializeMethod, getPtr, elementWithReflection);
    Add(deser);

    DecrementTabs();
    AddRightBrace();

    std::string addExpression;
    if ( depth == 0 )
        addExpression = fmt::format("{}->{}.{}( {} );", s_TypeObject, name, addMethod, param);
    else
        addExpression = fmt::format("{}.{}( {} );", collectorName, addMethod, param);
    Add(addExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePushReflectionArray(TMemberInfo* pMemberInfo)
{
    auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto typeWithNamespace = templateType.GetTypeNameWithNameSpace();
    switch ( templateType.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            AddPushSerObjArray(typeWithNamespace, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
            AddPushSerPtrArray(typeWithNamespace, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            AddPushSerSmartPtrArray(typeWithNamespace, templateType.mSmartPtrType, pMemberInfo->mName);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerObjArray(const std::string& type, const std::string& name)
{
    General_AddPushSerArrayOrMap(type, "", name, s_PushSerObjArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrArray(const std::string& type, const std::string& name)
{
    General_AddPushSerArrayOrMap(type, "", name, s_PushSerPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name)
{
    auto fullType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, type);
    General_AddPushSerArrayOrMap(type, fullType, name, s_PushSerSmartPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleReflectionForPush(TMemberInfo* pMemberInfo)
{
    auto objName = fmt::format("{}_obj", pMemberInfo->mName);

    std::string getAddrOfMember;
    switch ( pMemberInfo->mExtendedInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            getAddrOfMember = fmt::format("&({}->{})", s_TypeObject, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
        case TMemberTypeExtendedInfo::SmartPointer:
            HandleSmartPtrOrPtrReflectionForPush(pMemberInfo);
            return;
        default:
            break;
    }

    AddVarDeclaration(s_Jobj, objName);

    std::list<std::string> argList = { getAddrOfMember, objName };
    std::list<std::string> templateList;

    AddCallFunction("", sSerializeMethod, templateList, argList);

    argList =
    {
        s_Obj,
        fmt::format("\"{}\"", pMemberInfo->mName, objName),
        fmt::format("{}", objName)
    };
    AddCallFunction(s_PUM, s_Push, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleSmartPtrOrPtrReflectionForPush(TMemberInfo* pMemberInfo)
{
    auto objName = fmt::format("{}_obj", pMemberInfo->mName);
    auto pointerToObjName = fmt::format("p_{}", pMemberInfo->mName);

    std::string getAddrOfMember;
    switch ( pMemberInfo->mExtendedInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Pointer:
            getAddrOfMember = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            getAddrOfMember = fmt::format("{}->{}.get()", s_TypeObject, pMemberInfo->mName);
            break;
        default:
            break;
    }

    auto expressionGetAddress = fmt::format("auto {} = {};", pointerToObjName, getAddrOfMember);

    AddVarDeclaration(s_Jobj, objName);
    Add(expressionGetAddress);
    AddIf(pointerToObjName);
    AddLeftBrace();
    IncrementTabs();

    std::list<std::string> argList = { pointerToObjName, objName };
    std::list<std::string> templateList;

    AddCallFunction("", sSerializeMethod, templateList, argList);

    argList =
    {
        s_Obj,
        fmt::format("\"{}\"", pMemberInfo->mName, objName),
        fmt::format("{}", objName)
    };
    AddCallFunction(s_PUM, s_Push, templateList, argList);

    DecrementTabs();
    AddRightBrace();
    AddElse();
    IncrementTabs();

    argList =
    {
        s_Obj,
        fmt::format("\"{}\"", pMemberInfo->mName, objName),
    };
    AddCallFunction(s_PUM, s_PushNull, templateList, argList);

    DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushMap(const std::string& name)
{
    std::list<std::string> argList =
    {
        s_Obj,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templList;

    AddCallFunction(s_PUM, s_PushMap, templList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePushBuiltInOrStringSerMap(TMemberInfo* pMemberInfo)
{
    auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
    auto accessMethod = templateType.mAccessMethod;
    auto valueType = templateType.GetTypeNameWithNameSpace();
    switch ( accessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            AddPushSerObjMap(valueType, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
            AddPushSerPtrMap(valueType, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            AddPushSerSmartPtrMap(valueType, pMemberInfo->mExtendedInfo.mTemplateChildArr[1].mSmartPtrType, pMemberInfo->mName);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerObjMap(const std::string& type, const std::string& name)
{
    General_AddPushSerArrayOrMap(type, "", name, s_PushSerObjMap);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrMap(const std::string& type, const std::string& name)
{
    General_AddPushSerArrayOrMap(type, "", name, s_PushSerPtrMap);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrMap(const std::string& type, const std::string& smartPtrType, const std::string& name)
{
    auto fullType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, type);
    General_AddPushSerArrayOrMap(type, fullType, name, s_PushSerSmartPtrMap);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltIn(TMemberInfo* pMemberInfo)
{
    if ( pMemberInfo->mExtendedInfo.mType == s_Bool )
        AddPopBool(pMemberInfo->mName);
    else
        AddPopNum(pMemberInfo->mName);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStr(const std::string& name)
{
    General_AddPop(name, s_PopStr);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBool(const std::string& name)
{
    General_AddPop(name, s_PopBool);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNum(const std::string& name)
{
    General_AddPop(name, s_PopNum);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopSet(TMemberInfo* pMemberInfo)
{
    auto& templateInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    switch ( templateInfo.mCategory ) {
        case TMemberTypeExtendedInfo::BuiltIn:
            if ( templateInfo.mType == s_Bool )
                AddPopBoolSet(pMemberInfo->mName);
            else
                AddPopNumSet(pMemberInfo->mName, templateInfo.mType);
            break;
        case TMemberTypeExtendedInfo::String:
            AddPopStrSet(pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Reflection:
            HandlePopReflectionSet(pMemberInfo);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflection(TMemberInfo* pMemberInfo)
{
    auto jsonName = fmt::format("{}_{}", pMemberInfo->mName, s_Json);
    switch ( pMemberInfo->mExtendedInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            break;
        case TMemberTypeExtendedInfo::Pointer:
        case TMemberTypeExtendedInfo::SmartPointer:
            HandleSmartPtrOrPtrPopReflection(pMemberInfo);
            return;
        default:
            break;
    }
    auto expression = fmt::format("auto& {} = {}[\"{}\"];", jsonName, s_Json, pMemberInfo->mName);
    Add(expression);

    std::list<std::string> argList =
    {
        fmt::format("&({}->{})", s_TypeObject, pMemberInfo->mName),
        fmt::format("{}", jsonName)
    };
    std::list<std::string> templateList;

    AddCallFunction("", sDeserializeMethod, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleSmartPtrOrPtrPopReflection(TMemberInfo* pMemberInfo)
{
    auto& templateType = pMemberInfo->mExtendedInfo;
    auto typeWithNamespace = templateType.GetTypeNameWithNameSpace();
    auto jsonName = fmt::format("{}_{}", pMemberInfo->mName, s_Json);

    std::string newObject;
    std::string getAddrOfMember;
    switch ( pMemberInfo->mExtendedInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Pointer:
            getAddrOfMember = fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName);
            newObject = fmt::format("{}->{} = new {}();", s_TypeObject, pMemberInfo->mName, typeWithNamespace);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            getAddrOfMember = fmt::format("{}->{}.get()", s_TypeObject, pMemberInfo->mName);
            newObject = fmt::format("{}->{}.reset( new {}() );", s_TypeObject, pMemberInfo->mName, typeWithNamespace);
            break;
        default:
            break;
    }
    auto expression = fmt::format("auto& {} = {}[\"{}\"];", jsonName, s_Json, pMemberInfo->mName);
    Add(expression);
    AddIf(fmt::format("{}.is_null() == false", jsonName));
    AddLeftBrace();
    IncrementTabs();
    AddIf(fmt::format("{} == {}", getAddrOfMember, s_Nullptr));
    IncrementTabs();
    Add(newObject);
    DecrementTabs();

    std::list<std::string> argList =
    {
        getAddrOfMember,
        fmt::format("{}", jsonName)
    };
    std::list<std::string> templateList;

    AddCallFunction("", sDeserializeMethod, templateList, argList);
    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumArray(const std::string& name, const std::string& type)
{
    General_AddPopArrayOrSet(name, type, s_PopNumArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBoolArray(const std::string& name)
{
    General_AddPopArrayOrSet(name, "", s_PopBoolArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrArray(const std::string& name)
{
    General_AddPopArrayOrSet(name, "", s_PopStrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumSet(const std::string& name, const std::string& type)
{
    General_AddPopArrayOrSet(name, type, s_PopNumSet);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBoolSet(const std::string& name)
{
    General_AddPopArrayOrSet(name, "", s_PopBoolSet);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrSet(const std::string& name)
{
    General_AddPopArrayOrSet(name, "", s_PopStrSet);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflectionArray(TMemberInfo* pMemberInfo)
{
    auto& extMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto keyType = extMemberInfo.GetTypeNameWithNameSpace();

    std::string fullType;
    std::string methodName;
    switch ( extMemberInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            methodName = s_PopSerObjArray;
            break;
        case TMemberTypeExtendedInfo::Pointer:
            methodName = s_PopSerPtrArray;
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            methodName = s_PopSerSmartPtrArray;
            fullType = fmt::format("{}{}<{}>", s_STD_, extMemberInfo.mSmartPtrType, keyType);
            break;
        default:
            break;
    }
    General_AddPopSerArrayOrMap(keyType, "", keyType, fullType, pMemberInfo->mName, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflectionSet(TMemberInfo* pMemberInfo)
{
    auto str = fmt::format("Prohibition of use of type {}!", pMemberInfo->mTypeName);
    BL_MessageBug(str.data());
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltInOrStringMap(TMemberInfo* pMemberInfo)
{
    auto name = pMemberInfo->mName;
    auto& templateList = pMemberInfo->mExtendedInfo.mTemplateChildArr;
    auto& keyInfo = templateList[0];
    auto& valueInfo = templateList[1];

    auto keyCategory = keyInfo.mCategory;
    auto valueCategory = valueInfo.mCategory;

    if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        if ( valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
            if ( valueInfo.mType == s_Bool )
                AddPopNumBoolMap(name);
            else
                AddPopNumNumMap(name);
        }
        if ( valueCategory == TMemberTypeExtendedInfo::String )
            AddPopNumStrMap(name);
    } else if ( keyCategory == TMemberTypeExtendedInfo::String ) {
        if ( valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
            if ( valueInfo.mType == s_Bool )
                AddPopStrBoolMap(name);
            else
                AddPopStrNumMap(name);
        }
        if ( valueCategory == TMemberTypeExtendedInfo::String )
            AddPopStrStrMap(name);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltInOrStringSerMap(TMemberInfo* pMemberInfo)
{
    auto& keyExtMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto& valueExtMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
    auto valueType = valueExtMemberInfo.GetTypeNameWithNameSpace();

    std::string fullType;
    std::string methodName;
    switch ( valueExtMemberInfo.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
                methodName = s_PopStrSerObjMap;
            else
                methodName = s_PopNumSerObjMap;
            break;
        case TMemberTypeExtendedInfo::Pointer:
            if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
                methodName = s_PopStrSerPtrMap;
            else
                methodName = s_PopNumSerPtrMap;
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
                methodName = s_PopStrSerSmartPtrMap;
            else
                methodName = s_PopNumSerSmartPtrMap;
            fullType = fmt::format("{}{}<{}>", s_STD_, valueExtMemberInfo.mSmartPtrType, valueType);
            break;
        default:
            break;
    }
    std::string keyType;
    if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::BuiltIn )
        keyType = keyExtMemberInfo.mType;

    General_AddPopSerArrayOrMap(keyType, valueType, valueType, fullType, pMemberInfo->mName, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumBoolMap(const std::string& name)
{
    AddPopMap(s_PopNumBoolMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumNumMap(const std::string& name)
{
    AddPopMap(s_PopNumNumMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumStrMap(const std::string& name)
{
    AddPopMap(s_PopNumStrMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrBoolMap(const std::string& name)
{
    AddPopMap(s_PopStrBoolMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrNumMap(const std::string& name)
{
    AddPopMap(s_PopStrNumMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrStrMap(const std::string& name)
{
    AddPopMap(s_PopStrStrMap, name);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopMap(const std::string& methodName, const std::string& name)
{
    std::list<std::string> argList =
    {
        s_Json,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name),
    };
    std::list<std::string> templateList;

    AddCallFunction(s_POM, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPushSerArrayOrMap(const std::string& type, const std::string& fullType,
    const std::string& name, const std::string& methodName)
{
    auto strList = GetParamListForSerialize(type);
    auto paramStr = EnumerateParamToStr(strList);

    std::list<std::string> argList =
    {
        s_Obj,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name),
        fmt::format("[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sSerializeMethod, s_TypeObject, s_Obj)
    };
    std::list<std::string> templateList = { type, fullType };

    AddCallFunction(s_PUM, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPop(const std::string& name, const std::string& methodName)
{
    std::list<std::string> argList =
    {
        s_Json,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallFunction(s_POM, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------    
void TJsonSerializerSourceFileGenerator::General_AddPopArrayOrSet(const std::string& name, const std::string& type, const std::string& methodName)
{
    std::list<std::string> argList =
    {
        s_Json,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;
    if ( type.length() > 0 )
        templateList = { type };

    AddCallFunction(s_POM, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPopSerArrayOrMap(const std::string& keyType, const std::string& valueType,
    const std::string& typeForLambda,
    const std::string& fullType, const std::string& name, const std::string& methodName)
{
    auto strList = GetParamListForDeserialize(typeForLambda);
    auto paramStr = EnumerateParamToStr(strList);

    std::list<std::string> argList =
    {
        s_Json,
        fmt::format("\"{}\"", name),
        fmt::format("{}->{}", s_TypeObject, name),
        fmt::format("[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sDeserializeMethod, s_TypeObject, s_Json)
    };

    std::list<std::string> templateList;
    if ( keyType.length() )
        templateList.push_back(keyType);
    if ( valueType.length() )
        templateList.push_back(valueType);
    if ( fullType.length() )
        templateList.push_back(fullType);

    AddCallFunction(s_POM, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
