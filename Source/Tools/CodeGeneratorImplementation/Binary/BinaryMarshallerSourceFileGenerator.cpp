/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerSourceFileGenerator.h"

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/compile.h>

using namespace nsCodeGeneratorImplementation;
using namespace nsCppParser;

void TBinaryMarshallerSourceFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddInclude(mSerializer->fileName + ".h");

    AddIncludeForExternalSources();
    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if (namespaceName.length()) {
        AddUsingNamespace(namespaceName);
    }

    AddEmptyLine();

    AddList(GetBinaryImplementation());
    AddCommentedLongLine();

    AddPackImplentation();
    AddImplementations();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPackImplentation()
{
    auto s = fmt::format("void {}::{}( char* packedData, int size )", mSerializer->className, s_Unpack);
    Add(s);
    AddLeftBrace();
    IncrementTabs();

    s = fmt::format("auto type = {}( packedData, size );", s_PrepareForUnpackPopMaster);
    Add(s);
    Add("switch( type )");
    AddLeftBrace();
    IncrementTabs();

    //for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
    //    auto namespaceName = namespaceTypeInfo.first;
    //    auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
    //    for ( auto filenameType : filenameTypeMap ) {
    //        auto p = filenameType.second.get();
    //        AddCase(p);
    //    }
    //}

    DecrementTabs();
    AddRightBrace();

    DecrementTabs();
    AddRightBrace();

    AddCommentedLongLine();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddImplementations()
{
    //for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
    //    auto namespaceName = namespaceTypeInfo.first;
    //    auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
    //    for ( auto filenameType : filenameTypeMap ) {
    //        auto p = filenameType.second.get();

    //        mCurrentTypeInfo = p;

    //        AddImplementation(p);

    //        mCurrentTypeInfo = nullptr;
    //    }
    //}
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCase(TTypeInfo* p)
{
    auto enumName = MakeEnumName(p);
    IFileGenerator::AddCase(enumName);
    AddLeftBrace();
    IncrementTabs();

    auto sAllocate = fmt::format("auto p = Allocate<{}>();", p->GetTypeNameWithNameSpace());
    Add(sAllocate);
    auto sDeser = fmt::format("{}( p );", s_Deserialize);
    Add(sDeser);

    //if (mBinaryMarshaller->unpackHandler.get() != nullptr) {
    //    auto sHandle = fmt::format("{}::{}( p );", mBinaryMarshaller->unpackHandler->className,
    //        mBinaryMarshaller->unpackHandler->method);
    //    Add(sHandle);
    //}

    DecrementTabs();
    AddRightBrace();

    AddBreak();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddImplementation(TTypeInfo* p)
{
    AddSerializeImplementation(p);
    AddCommentedLongLine();
    AddDeserializeImplementation(p);
    AddCommentedLongLine();
    AddGetTypeIDImplementation(p);
    AddCommentedLongLine();
    AddDeallocateImplentation(p);
    AddCommentedLongLine();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddSerializeImplementation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForSerialize(namespaceWithType);
    AddMethodImplementationBegin(s_Void, className, s_Serialize, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this](TInheritanceInfo* pInheritanceInfo) { AddCallingSerializeParent(pInheritanceInfo); });

    AddCallingMethod(p, [this](TMemberInfo* mi) { AddPushByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddDeserializeImplementation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForDeserialize(namespaceWithType);
    AddMethodImplementationBegin(s_Void, className, s_Deserialize, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethodForParent(p, [this](TInheritanceInfo* pInheritanceInfo) { AddCallingDeserializeParent(pInheritanceInfo); });

    AddCallingMethod(p, [this](TMemberInfo* mi) { AddPopByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddGetTypeIDImplementation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForGetID(namespaceWithType);
    AddMethodImplementationBegin(className + s_CC + s_TypeID, className, s_GetTypeID, strList);
    AddLeftBrace();
    IncrementTabs();

    auto enumName = MakeEnumName(p);
    auto s = fmt::format("return {};", enumName);
    Add(s);

    DecrementTabs();
    AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddDeallocateImplentation(TTypeInfo* p)
{
    auto className = mSerializer->className;
    auto namespaceWithType = p->GetTypeNameWithNameSpace();
    auto strList = GetParamListForGetID(namespaceWithType);
    AddMethodImplementationBegin(s_Void, className, s_Deallocate, strList);
    AddLeftBrace();
    IncrementTabs();

    AddCallingMethod(p, [this](TMemberInfo* mi) { AddDeallocateByMemberInfo(mi); });

    DecrementTabs();
    AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCallingSerializeParent(TInheritanceInfo* pInheritanceInfo)
{
    auto str = fmt::format("{}( ({}*){} );", s_Serialize, pInheritanceInfo->mLongTypeName, s_TypeObject);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCallingDeserializeParent(TInheritanceInfo* pInheritanceInfo)
{
    auto str = fmt::format("{}( ({}*){} );", s_Deserialize, pInheritanceInfo->mLongTypeName, s_TypeObject);
    Add(str);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushByMemberInfo(TMemberInfo* pMemberInfo)
{

    switch (pMemberInfo->mExtendedInfo.mCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            HandlePushBuiltIn(pMemberInfo);
            break;
        case TypeCategory::STRING:
            AddPushStr(pMemberInfo->mName);
            break;
        case TypeCategory::REFLECTION:
            HandleReflectionForPush(pMemberInfo);
            break;
        case TypeCategory::SET:
            HandlePushArray(pMemberInfo);
            break;
        case TypeCategory::VECTOR:
        case TypeCategory::LIST:
        case TypeCategory::MAP:
            {
                AddEmptyLine();
                std::vector<TMemberExtendedTypeInfo> extArr;
                pMemberInfo->CreateExtArray(extArr);
                HandleComplexPushZeroDepth(extArr, pMemberInfo->mName);
            }
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopByMemberInfo(TMemberInfo* pMemberInfo)
{
    switch (pMemberInfo->mExtendedInfo.mCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            HandlePopBuiltIn(pMemberInfo);
            break;
        case TypeCategory::STRING:
            AddPopStr(pMemberInfo->mName);
            break;
        case TypeCategory::REFLECTION:
            HandlePopReflection(pMemberInfo);
            break;
        case TypeCategory::SET:
            HandlePopSet(pMemberInfo);
            break;
        case TypeCategory::VECTOR:
        case TypeCategory::LIST:
        case TypeCategory::MAP:
            {
                AddEmptyLine();
                std::vector<TMemberExtendedTypeInfo> extArr;
                pMemberInfo->CreateExtArray(extArr);
                AddCleanerArrayOrMap(extArr, pMemberInfo->mName);
                HandleComplexPopZeroDepth(extArr, pMemberInfo->mName);
            }
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddDeallocateByMemberInfo(TMemberInfo* pMemberInfo)
{
    switch (pMemberInfo->mExtendedInfo.mCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
        case TypeCategory::STRING:
            break;
        case TypeCategory::REFLECTION:
            HandleDeallocateReflection(pMemberInfo);
            break;
        case TypeCategory::SET:
            //( pMemberInfo );
            break;
        case TypeCategory::VECTOR:
        case TypeCategory::LIST:
        case TypeCategory::MAP:
            {
                std::vector<TMemberExtendedTypeInfo> extArr;
                pMemberInfo->CreateExtArray(extArr);
                AddCleanerArrayOrMap(extArr, pMemberInfo->mName);
            }
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushBuiltIn(TMemberInfo* pMemberInfo)
{
    if (pMemberInfo->mExtendedInfo.mCategory == TypeCategory::BOOL) {
        AddPushBool(pMemberInfo->mName);
    } else {
        AddPushNum(pMemberInfo->mName);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushBool(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PushMaster, s_PushBool, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushNum(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PushMaster, s_PushNum, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushStr(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PushMaster, s_PushStr, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushArray(TMemberInfo* pMemberInfo)
{
    auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto templateCategory = templateType.mCategory;
    switch (templateCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            HandleAddPushBuiltInArray(pMemberInfo);
            break;
        case TypeCategory::STRING:
            AddPushStrArray(pMemberInfo->mName);
            break;
        case TypeCategory::REFLECTION:
            HandlePushSerArray(pMemberInfo);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushMap(TMemberInfo* pMemberInfo)
{
    auto& valueType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
    auto valueCategory = valueType.mCategory;
    if (valueCategory == TypeCategory::REFLECTION) {
        HandleAddPushValueAsReflectionMap(pMemberInfo);
    } else {
        HandleAddPushNotReflectionMap(pMemberInfo);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleReflectionForPush(TMemberInfo* pMemberInfo)
{
    auto& type = pMemberInfo->mExtendedInfo.mShortType;
    switch (pMemberInfo->mExtendedInfo.mAccessMethod) {
        case AccessMethod::OBJECT:
            AddPushSerObj(type, pMemberInfo->mName);
            break;
        case AccessMethod::POINTER:
            AddPushSerPtr(type, pMemberInfo->mName);
            break;
        case AccessMethod::SMART_POINTER:
            AddPushSerSmartPtr(type, pMemberInfo->mName);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushBuiltInArray(TMemberInfo* pMemberInfo)
{
    auto category = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mCategory;
    if (category == TypeCategory::BOOL) {
        AddPushBoolArray(pMemberInfo->mName);
    } else {
        auto& type = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mShortType;
        AddPushNumArray(type, pMemberInfo->mName);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushBoolArray(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PushMaster, s_PushBoolArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushNumArray(const std::string& type, const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList = {type};

    AddCallObjMethod(s_PushMaster, s_PushNumArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushStrArray(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PushMaster, s_PushStrArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushSerArray(TMemberInfo* pMemberInfo)
{
    auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto templateCategory = templateType.mCategory;

    //auto typeName = templateType.mType;
    auto typeName = templateType.GetTypeNameWithNameSpace();

    auto withinClassTypeName = mCurrentTypeInfo->GetTypeNameWithNameSpace();

    auto pTypeInfo = mTypeManager->Get(typeName);
    if (pTypeInfo == nullptr) {
        return;
    }

    auto type = pTypeInfo->GetTypeNameWithNameSpace();
    switch (templateType.mAccessMethod) {
        case AccessMethod::OBJECT:
            AddPushSerObjArray(type, pMemberInfo->mName);
            break;
        case AccessMethod::POINTER:
            AddPushSerPtrArray(type, pMemberInfo->mName);
            break;
        case AccessMethod::SMART_POINTER:
            AddPushSerSmartPtrArray(type, templateType.mSmartPtrType, pMemberInfo->mName);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObjArray(const std::string& type, const std::string& name)
{
    General_AddPushSerArray(type, "", name, s_PushSerObjArray);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtrArray(const std::string& type, const std::string& name)
{
    General_AddPushSerArray(type, "", name, s_PushSerPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name)
{
    auto fullType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, type);
    General_AddPushSerArray(type, fullType, name, s_PushSerSmartPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushNotReflectionMap(TMemberInfo* pMemberInfo)
{
    std::string methodName;
    std::string type[2];

    auto& templateArr = pMemberInfo->mExtendedInfo.mTemplateChildArr;
    //auto keyType = templateArr[0].mType;
    //auto valueType = templateArr[1].mType;
    //auto keyCategory = templateArr[0].mCategory;
    //auto valueCategory = templateArr[1].mCategory;

    /*if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
        valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        type[0] = keyType;
        if ( valueType == s_Bool )
            methodName = s_PushNumBoolMap;
        else {
            methodName = s_PushNumNumMap;
            type[1] = valueType;
        }
    }
    if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
        valueCategory == TMemberTypeExtendedInfo::String ) {
        type[0] = keyType;
        methodName = s_PushNumStrMap;
    }
    if ( keyCategory == TMemberTypeExtendedInfo::String &&
        valueCategory == TMemberTypeExtendedInfo::String )
        methodName = s_PushStrStrMap;
    if ( keyCategory == TMemberTypeExtendedInfo::String &&
        valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        if ( valueType == s_Bool )
            methodName = s_PushStrBoolMap;
        else {
            methodName = s_PushStrNumMap;
            type[0] = valueType;
        }
    }*/

    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName)
    };
    std::list<std::string> templateList = {type[0], type[1]};

    AddCallObjMethod(s_PushMaster, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushValueAsReflectionMap(TMemberInfo* pMemberInfo)
{
    auto& keyExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto& valueExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];

    std::string keyType;
    /*if ( keyExtType.mCategory == TMemberTypeExtendedInfo::BuiltIn )
        keyType = keyExtType.mType;

    auto withinClassTypeName = mCurrentTypeInfo->GetTypeNameWithNameSpace();

    auto typeName = valueExtType.mType;
    auto pTypeInfo = mTypeMng->FindTypeInfoBy(typeName, withinClassTypeName);
    if ( pTypeInfo == nullptr )
        return;

    auto valueType = pTypeInfo->GetTypeNameWithNameSpace();

    switch ( valueExtType.mAccessMethod ) {
        case TMemberTypeExtendedInfo::Object:
            AddPushSerObjMap(keyType, valueType, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::Pointer:
            AddPushSerPtrMap(keyType, valueType, pMemberInfo->mName);
            break;
        case TMemberTypeExtendedInfo::SmartPointer:
            AddPushSerSmartPtrMap(keyType, valueType, valueExtType.mSmartPtrType, pMemberInfo->mName);
            break;
        default:
            break;
    }*/
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObjMap(const std::string& keyType, const std::string& valueType, const std::string& name)
{
    std::string methodName = s_PushStrSerObjMap;
    if (keyType.length())
        methodName = s_PushNumSerObjMap;

    General_AddPushSerMap(keyType, valueType, "", name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtrMap(const std::string& keyType, const std::string& valueType, const std::string& name)
{
    std::string methodName = s_PushStrSerPtrMap;
    if (keyType.length())
        methodName = s_PushNumSerPtrMap;

    General_AddPushSerMap(keyType, valueType, "", name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtrMap(const std::string& keyType, const std::string& valueType,
    const std::string& smartPtrType, const std::string& name)
{
    std::string methodName = s_PushStrSerSmartPtrMap;
    if (keyType.length())
        methodName = s_PushNumSerSmartPtrMap;

    auto smartPtrTypeWithType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, valueType);
    General_AddPushSerMap(keyType, valueType, smartPtrTypeWithType, name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObj(const std::string& type, const std::string& name)
{
    auto ptrName = fmt::format("{}_p", name);
    auto getAddress = fmt::format("&({}->{})", s_TypeObject, name);
    General_AddPushReflection(ptrName, getAddress);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtr(const std::string& type, const std::string& name)
{
    auto ptrName = fmt::format("{}_p", name);
    auto getAddress = fmt::format("{}->{}", s_TypeObject, name);
    General_AddPushReflection(ptrName, getAddress);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtr(const std::string& type, const std::string& name)
{
    auto ptrName = fmt::format("{}_p", name);
    auto getAddress = fmt::format("{}->{}.get()", s_TypeObject, name);
    General_AddPushReflection(ptrName, getAddress);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopBuiltIn(TMemberInfo* pMemberInfo)
{
    if (pMemberInfo->mExtendedInfo.mCategory == TypeCategory::BOOL) {
        AddPopBool(pMemberInfo->mName);
    } else {
        AddPopNum(pMemberInfo->mName);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopBool(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopBool, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNum(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopNum, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStr(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopStr, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopArray(TMemberInfo* pMemberInfo)
{
    switch (pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            HandlePopBuiltInArray(pMemberInfo);
            break;
        case TypeCategory::STRING:
            AddPopStrArray(pMemberInfo->mName);
            break;
        case TypeCategory::REFLECTION:
            HandlePopReflectionArray(pMemberInfo);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopSet(TMemberInfo* pMemberInfo)
{
    auto ext = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    switch (ext.mCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            AddPopNumSet(ext.mShortType, pMemberInfo->mName);
            break;
        case TypeCategory::STRING:
            AddPopStrSet(pMemberInfo->mName);
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopMap(TMemberInfo* pMemberInfo)
{
    auto& valueType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
    auto valueCategory = valueType.mCategory;
    if (valueCategory == TypeCategory::REFLECTION) {
        HandleAddPopValueAsReflectionMap(pMemberInfo);
    } else {
        HandleAddPopNotReflectionMap(pMemberInfo);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPopValueAsReflectionMap(TMemberInfo* pMemberInfo)
{
    auto& keyExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto& valueExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];

    std::string keyType;
    if (keyExtType.mCategory == TypeCategory::BOOL || 
        keyExtType.mCategory == TypeCategory::NUMBER ||
        keyExtType.mCategory == TypeCategory::CEIL_NUMBER) {
        keyType = keyExtType.mShortType;
    }

    //auto withinClassTypeName = mCurrentTypeInfo->GetTypeNameWithNameSpace();

    auto typeName = valueExtType.GetTypeNameWithNameSpace();
    auto pTypeInfo = mTypeManager->Get(typeName);
    if (pTypeInfo == nullptr) {
        return;
    }
    auto valueType = pTypeInfo->GetTypeNameWithNameSpace();

    switch ( valueExtType.mAccessMethod ) {
        case AccessMethod::OBJECT:
            AddPopSerObjMap(keyType, valueType, pMemberInfo->mName);
            break;
        case AccessMethod::POINTER:
            AddPopSerPtrMap(keyType, valueType, pMemberInfo->mName);
            break;
        case AccessMethod::SMART_POINTER:
            AddPopSerSmartPtrMap(keyType, valueType, valueExtType.mSmartPtrType, pMemberInfo->mName);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPopNotReflectionMap(TMemberInfo* pMemberInfo)
{
    std::string methodName;
    std::string type[2];

    auto& templateArr = pMemberInfo->mExtendedInfo.mTemplateChildArr;
    /*auto keyType = templateArr[0].mType;
    auto valueType = templateArr[1].mType;
    auto keyCategory = templateArr[0].mCategory;
    auto valueCategory = templateArr[1].mCategory;

    if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
        valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        type[0] = keyType;
        if ( valueType == s_Bool )
            methodName = s_PopNumBoolMap;
        else {
            methodName = s_PopNumNumMap;
            type[1] = valueType;
        }
    }
    if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
        valueCategory == TMemberTypeExtendedInfo::String ) {
        type[0] = keyType;
        methodName = s_PopNumStrMap;
    }
    if ( keyCategory == TMemberTypeExtendedInfo::String &&
        valueCategory == TMemberTypeExtendedInfo::String )
        methodName = s_PopStrStrMap;
    if ( keyCategory == TMemberTypeExtendedInfo::String &&
        valueCategory == TMemberTypeExtendedInfo::BuiltIn ) {
        if ( valueType == s_Bool )
            methodName = s_PopStrBoolMap;
        else {
            methodName = s_PopStrNumMap;
            type[0] = valueType;
        }
    }*/

    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, pMemberInfo->mName)
    };
    std::list<std::string> templateList = {type[0], type[1]};

    AddCallObjMethod(s_PopMaster, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleComplexPushZeroDepth(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name)
{
    int depth = 0;
    auto sizeName = SizeName(name, depth);
    auto sizeExpression = fmt::format("{0} {1} = ({0})({2}->{3}.size());", s_BinaryMaster_SizeType, sizeName, s_TypeObject, name);
    Add(sizeExpression);

    auto pushSizeExpression = fmt::format("{}.{}( {} );", s_PushMaster, s_PushNum, sizeName);
    Add(pushSizeExpression);

    General_ComplexPush(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleComplexPush(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto prevElementName = ElementName(name, depth - 1);
    std::string srcName;
    auto accessName = GetAccessName(extArr, name, depth - 1);
    if (accessName.length())
        accessName = fmt::format(".{}", accessName);
    srcName = fmt::format("{}{}", prevElementName, accessName);

    auto sizeName = SizeName(name, depth);
    auto sizeExpression = fmt::format("{0} {1} = ({0})({2}.size());", s_BinaryMaster_SizeType, sizeName, srcName);
    Add(sizeExpression);

    auto pushSizeExpression = fmt::format("{}.{}( {} );", s_PushMaster, s_PushNum, sizeName);
    Add(pushSizeExpression);

    if (extArr[depth - 1].mCategory == TypeCategory::MAP) {
        AddPushKey(extArr, name, depth);
    }

    General_ComplexPush(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_ComplexPush(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto elementName = ElementName(name, depth);
    std::string srcName;
    if (depth == 0)
        srcName = fmt::format("{}->{}", s_TypeObject, name);
    else {
        auto prevElementName = ElementName(name, depth - 1);
        auto accessName = GetAccessName(extArr, name, depth - 1);
        if (accessName.length())
            accessName = fmt::format(".{}", accessName);
        srcName = fmt::format("{}{}", prevElementName, accessName);
    }

    auto forExpression = fmt::format("for ( auto& {} : {} )", elementName, srcName);
    Add(forExpression);

    AddLeftBrace();
    IncrementTabs();

    auto& valueType = extArr[depth].mTemplateChildArr.back();
    auto valueCategory = valueType.mCategory;
    switch (valueCategory) {
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
        case TypeCategory::STRING:
            HandleBuiltInComplexPush(extArr, name, depth + 1);
            break;
        case TypeCategory::REFLECTION:
            HandleReflectionComplexPush(extArr, name, depth + 1);
            break;
        case TypeCategory::SET:
            break;
        case TypeCategory::VECTOR:
        case TypeCategory::LIST:
        case TypeCategory::MAP:
            HandleComplexPush(extArr, name, depth + 1);
            break;
    }

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleBuiltInComplexPush(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    if (extArr[depth - 1].mCategory == TypeCategory::MAP) {
        AddPushKey(extArr, name, depth);
        AddPushValue(extArr, name, depth);
    } else
        AddPushElement(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleStringComplexPush(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{

}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleReflectionComplexPush(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto& ext = extArr[depth - 1];
    if (ext.mCategory == TypeCategory::MAP) {
        AddPushKey(extArr, name, depth);
    }

    // PUSH
    auto isNotNullName = fmt::format("{}_isNotNull", name);
    auto isElementNotNull = GetIsElementNotNull(extArr, name, depth);
    auto isNotNullExpression = fmt::format("{} {} = {};", s_Bool, isNotNullName, isElementNotNull);
    Add(isNotNullExpression);

    auto pushisNotNullExpression = fmt::format("{}.{}( {} );", s_PushMaster, s_PushBool, isNotNullName);
    Add(pushisNotNullExpression);

    AddIf(isNotNullName);
    IncrementTabs();

    if (ext.mCategory == TypeCategory::MAP) {
        AddPushSerializeValue(extArr, name, depth);
    } else {
        AddPushSerializeElement(extArr, name, depth);
    }

    DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetTemplateForGetAddress(AccessMethod accessMethod)
{
    switch (accessMethod) {
        case AccessMethod::OBJECT:
            return "&({})";
        case AccessMethod::POINTER:
            return "{}";
        case AccessMethod::SMART_POINTER:
            return "{}.get()";
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetIsElementNotNull(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    std::string getAddress;
    auto elementName = ElementName(name, depth - 1);

    if (extArr[depth - 1].mCategory == TypeCategory::MAP) {
        auto templateForGetAddress = GetTemplateForGetAddress(extArr[depth - 1].mTemplateChildArr[1].mAccessMethod);
        auto keyName = fmt::format("{}.{}", elementName, s_Second);
        getAddress = fmt::format(fmt::runtime(templateForGetAddress), keyName);
    } else {
        auto templateForGetAddress = GetTemplateForGetAddress(extArr[depth - 1].mTemplateChildArr[0].mAccessMethod);
        getAddress = fmt::format(fmt::runtime(templateForGetAddress), elementName);
    }
    return fmt::format("{} != {}", getAddress, s_Nullptr);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerializeValue(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto templateForGetAddress = GetTemplateForGetAddress(extArr[depth - 1].mTemplateChildArr[1].mAccessMethod);
    auto elementName = ElementName(name, depth - 1);
    auto keyName = fmt::format("{}.{}", elementName, s_Second);

    auto getAddress = fmt::format(fmt::runtime(templateForGetAddress), keyName);

    auto pushExpression = fmt::format("{}( {} );", s_Serialize, getAddress);
    Add(pushExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerializeElement(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto templateForGetAddress = GetTemplateForGetAddress(extArr[depth - 1].mTemplateChildArr[0].mAccessMethod);
    auto elementName = ElementName(name, depth - 1);
    auto getAddress = fmt::format(fmt::runtime(templateForGetAddress), elementName);

    auto pushExpression = fmt::format("{}( {} );", s_Serialize, getAddress);
    Add(pushExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushKey(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto elementName = ElementName(name, depth - 1);
    auto pushMethod = GetPushMethodBy(extArr[depth - 1].mTemplateChildArr[0]);
    auto keyName = fmt::format("{}.{}", elementName, s_First);

    auto pushExpression = fmt::format("{}.{}( {} );", s_PushMaster, pushMethod, keyName);
    Add(pushExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushValue(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto elementName = ElementName(name, depth - 1);
    auto pushMethod = GetPushMethodBy(extArr[depth - 1].mTemplateChildArr[1]);
    auto valueName = fmt::format("{}.{}", elementName, s_Second);

    auto pushExpression = fmt::format("{}.{}( {} );", s_PushMaster, pushMethod, valueName);
    Add(pushExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushElement(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto elementName = ElementName(name, depth - 1);
    auto pushMethod = GetPushMethodBy(extArr[depth - 1].mTemplateChildArr[0]);

    auto pushExpression = fmt::format("{}.{}( {} );", s_PushMaster, pushMethod, elementName);
    Add(pushExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleDeallocateReflection(TMemberInfo* pMemberInfo)
{
    switch (pMemberInfo->mExtendedInfo.mAccessMethod) {
        case AccessMethod::OBJECT:
            break;
        case AccessMethod::POINTER:
            {
                auto deallocExpression = fmt::format("{}( {}->{} );", s_Deallocate, s_TypeObject, pMemberInfo->mName);
                Add(deallocExpression);
                auto nullExpression = fmt::format("{}->{} = {};", s_TypeObject, pMemberInfo->mName, s_Nullptr);
                Add(nullExpression);
            }
            break;
        case AccessMethod::SMART_POINTER:
            {
                auto resetExpression = fmt::format("{}->{}.reset();", s_TypeObject, pMemberInfo->mName);
                Add(resetExpression);
            }
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCleanerArrayOrMap(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name)
{
    auto& ext = extArr.back();
    //if ( ext.mCategory == TMemberTypeExtendedInfo::Reflection &&
    //    ext.mAccessMethod == TMemberTypeExtendedInfo::Pointer ) {
    //    int size = extArr.size() - 1;// consider template childs
    //    auto prevElementName = fmt::format("{}->{}", s_TypeObject, name);
    //    // open braces
    //    for ( int i = 0; i < size; i++ ) {
    //        auto elementName = ElementName(name, i);

    //        auto forExpression = fmt::format("for ( auto& {} : {} )", elementName, prevElementName);
    //        Add(forExpression);
    //        AddLeftBrace();
    //        IncrementTabs();

    //        prevElementName = elementName;
    //        if ( extArr[i].mCategory == TMemberTypeExtendedInfo::Map )
    //            prevElementName = fmt::format("{}.{}", prevElementName, s_Second);

    //        if ( i == size - 1 ) {
    //            auto pointerStr = elementName;
    //            if ( extArr[i].mCategory == TMemberTypeExtendedInfo::Map )
    //                pointerStr = fmt::format("{}.{}", elementName, s_Second);

    //            auto deallocateExpression = fmt::format("{}( {} );", s_GeneralDeallocate, pointerStr);
    //            Add(deallocateExpression);
    //        }
    //    }
    //    // close braces
    //    for ( int i = 0; i < size; i++ ) {
    //        DecrementTabs();
    //        AddRightBrace();
    //    }
    //}
    auto clearExpression = fmt::format("{}->{}.clear();", s_TypeObject, name);
    Add(clearExpression);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleComplexPopZeroDepth(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name)
{
    int depth = 0;
    auto sizeName = SizeName(name, depth);
    auto sizeExpression = fmt::format("{} {};", s_BinaryMaster_SizeType, sizeName, s_TypeObject, name);
    Add(sizeExpression);

    auto popSizeExpression = fmt::format("{}.{}( {} );", s_PopMaster, s_PopNum, sizeName);
    Add(popSizeExpression);

    General_ComplexPop(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleComplexPop(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto sizeName = SizeName(name, depth);
    auto sizeExpression = fmt::format("{} {};", s_BinaryMaster_SizeType, sizeName, s_TypeObject, name);
    Add(sizeExpression);

    auto popSizeExpression = fmt::format("{}.{}( {} );", s_PopMaster, s_PopNum, sizeName);
    Add(popSizeExpression);

    //if ( extArr[depth - 1].mCategory == TMemberTypeExtendedInfo::Map ) {
    //    auto keyExtInfo = extArr[depth - 1].mTemplateChildArr[0];

    //    auto keyType = keyExtInfo.GetCollectSubType();
    //    auto keyName = KeyName(name, depth - 1);
    //    auto keyExpression = fmt::format("{} {};", keyType, keyName);
    //    Add(keyExpression);

    //    auto popMethod = GetPopMethodBy(keyExtInfo);
    //    auto getKeyExpression = fmt::format("{}.{}( {} );", s_PopMaster, popMethod, keyName);
    //    Add(getKeyExpression);
    //}

    auto collectorName = CollectorName(name, depth - 1);
    auto collectorType = extArr[depth].GetCollectSubType();
    auto collectorExpression = fmt::format("{} {};", collectorType, collectorName);
    Add(collectorExpression);

    General_ComplexPop(extArr, name, depth);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_ComplexPop(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto sizeName = SizeName(name, depth);
    auto indexName = IndexName(name, depth);

    auto forExpression = fmt::format("for ( {0} {1} = 0 ; {1} < {2} ; {1}++ ) ", s_BinaryMaster_SizeType, indexName, sizeName);
    Add(forExpression);

    AddLeftBrace();
    IncrementTabs();

    auto& valueType = extArr[depth].mTemplateChildArr.back();
    auto valueCategory = valueType.mCategory;
    //switch ( valueCategory ) {
    //    case TMemberTypeExtendedInfo::BuiltIn:
    //    case TMemberTypeExtendedInfo::String:
    //        HandleBuiltInComplexPop(extArr, name, depth + 1);
    //        break;
    //    case TMemberTypeExtendedInfo::Reflection:
    //        HandleReflectionComplexPop(extArr, name, depth + 1);
    //        break;
    //    case TMemberTypeExtendedInfo::Set:
    //        break;
    //    case TMemberTypeExtendedInfo::Vector:
    //    case TMemberTypeExtendedInfo::List:
    //    case TMemberTypeExtendedInfo::Map:
    //        HandleComplexPop(extArr, name, depth + 1);
    //        break;
    //}

    //if ( extArr.size() > 2 ) {
    //    if ( depth == 0 ) {
    //        auto addMethod = GetAddMethodByCategory(extArr[depth].mCategory);
    //        auto param = GetFusionForAdd(extArr[depth], name, depth);
    //        auto addExpression = fmt::format("{}->{}.{}( {} );", s_TypeObject, name, addMethod, param);
    //        Add(addExpression);
    //    } else if ( depth < extArr.size() - 2 ) {
    //        auto prevCollectorName = CollectorName(name, depth - 1);
    //        auto addMethod = GetAddMethodByCategory(extArr[depth].mCategory);
    //        auto param = GetFusionForAdd(extArr[depth], name, depth);
    //        auto addExpression = fmt::format("{}.{}( {} );", prevCollectorName, addMethod, param);
    //        Add(addExpression);
    //    }
    //}

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleBuiltInComplexPop(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto ext = extArr[depth - 1];

    auto keyExtInfo = ext.mTemplateChildArr[0];

    auto keyType = keyExtInfo.GetCollectSubType();
    auto keyName = KeyName(name, depth - 1);
    auto keyExpression = fmt::format("{} {};", keyType, keyName);
    Add(keyExpression);

    auto popMethod = GetPopMethodBy(keyExtInfo);
    auto getKeyExpression = fmt::format("{}.{}( {} );", s_PopMaster, popMethod, keyName);
    Add(getKeyExpression);

    auto param = keyName;

    //if ( ext.mCategory == TMemberTypeExtendedInfo::Map ) {
    //    auto valueExtInfo = ext.mTemplateChildArr[1];

    //    auto valueType = valueExtInfo.GetCollectSubType();
    //    auto valueName = ValueName(name, depth - 1);
    //    auto valueExpression = fmt::format("{} {};", valueType, valueName);
    //    Add(valueExpression);

    //    auto popMethod = GetPopMethodBy(valueExtInfo);
    //    auto getValueExpression = fmt::format("{}.{}( {} );", s_PopMaster, popMethod, valueName);
    //    Add(getValueExpression);

    //    param = fmt::format("{{ {}, {} }}", keyName, valueName);
    //}

    //auto addMethod = GetAddMethodByCategory(ext.mCategory);
    //if ( depth == 1 ) {
    //    auto addExpression = fmt::format("{}->{}.{}( {} );", s_TypeObject, name, addMethod, param);
    //    Add(addExpression);
    //} else {
    //    auto prevCollectorName = CollectorName(name, depth - 2);
    //    auto addExpression = fmt::format("{}.{}( {} );", prevCollectorName, addMethod, param);
    //    Add(addExpression);
    //}
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleReflectionComplexPop(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto ext = extArr[depth - 1];

    auto keyName = KeyName(name, depth - 1);
    int indexReflection = 0;
    if (ext.mCategory == TypeCategory::MAP) {
        indexReflection = 1;
        auto keyExtInfo = ext.mTemplateChildArr[0];
        auto keyType = keyExtInfo.GetCollectSubType();
        auto keyExpression = fmt::format("{} {};", keyType, keyName);
        Add(keyExpression);

        auto popMethod = GetPopMethodBy(keyExtInfo);
        auto getKeyExpression = fmt::format("{}.{}( {} );", s_PopMaster, popMethod, keyName);
        Add(getKeyExpression);
    }

    auto elementName = ElementName(name, depth - 1);
    auto elementType = ext.mTemplateChildArr[indexReflection].GetCollectSubType();

    auto reflectionExt = ext.mTemplateChildArr[indexReflection];
    auto nullElementExpression = GetNullExpression(reflectionExt);
    auto elementExpression = fmt::format("{} {}{};", elementType, elementName, nullElementExpression);
    Add(elementExpression);

    auto isNotNullName = fmt::format("{}_IsNotNull", name);
    auto isNotNullExpression = fmt::format("{} {};", s_Bool, isNotNullName);
    Add(isNotNullExpression);

    auto popIsNotNullExpression = fmt::format("{}.{}( {} );", s_PopMaster, s_PopBool, isNotNullName);
    Add(popIsNotNullExpression);

    AddIf(isNotNullName);

    AddLeftBrace();
    IncrementTabs();

    auto initElementExpression = GetInitExpression(reflectionExt);
    if (initElementExpression.length()) {
        auto allocateExpression = fmt::format("{}{};", elementName, initElementExpression);
        Add(allocateExpression);
    }

    //auto templatePtr = GetTemplateForGetAddress(reflectionExt.mAccessMethod);
    //auto getAddress = fmt::format(templatePtr, elementName);

    //auto deserExpression = fmt::format("{}( {} );", s_Deserialize, getAddress);
    //Add(deserExpression);

    //DecrementTabs();
    //AddRightBrace();

    //std::string param = elementName;
    //if ( ext.mCategory == TMemberTypeExtendedInfo::Map )
    //    param = fmt::format("{{ {}, {} }}", keyName, elementName);

    //auto addMethod = GetAddMethodByCategory(ext.mCategory);
    //if ( depth == 1 ) {
    //    auto addExpression = fmt::format("{}->{}.{}( {} );", s_TypeObject, name, addMethod, param);
    //    Add(addExpression);
    //} else {
    //    auto prevCollectorName = CollectorName(name, depth - 2);
    //    auto addExpression = fmt::format("{}.{}( {} );", prevCollectorName, addMethod, param);
    //    Add(addExpression);
    //}
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetInitExpression(TMemberExtendedTypeInfo& ext)
{
    auto typeName = ext.GetTypeNameWithNameSpace();
    switch (ext.mAccessMethod) {
        case AccessMethod::OBJECT:
            return "";
        case AccessMethod::POINTER:
            return fmt::format(" = {}<{}>()", s_GeneralAllocate, typeName);
        case AccessMethod::SMART_POINTER:
            return fmt::format(".reset( new {}() )", typeName);
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetFusionForAdd(TMemberExtendedTypeInfo& ext, const std::string& name, int depth)
{
    switch (ext.mCategory) {
        case TypeCategory::MAP:
            {
                auto keyName = KeyName(name, depth);
                auto collectorName = CollectorName(name, depth);
                return fmt::format("{{ {}, {} }}", keyName, collectorName);
            }
        case TypeCategory::LIST:
        case TypeCategory::VECTOR:
            {
                return CollectorName(name, depth);
            }
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
//std::string TBinaryMarshallerSourceFileGenerator::GetAddMethodByCategory(TMemberExtendedTypeInfo::TypeCategory& category)
//{
    //switch ( category ) {
    //    case TMemberTypeExtendedInfo::Map:
    //        return s_Insert;
    //    case TMemberTypeExtendedInfo::List:
    //    case TMemberTypeExtendedInfo::Vector:
    //        return s_PushBack;
    //}
//}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::ElementName(const std::string& name, int depth)
{
    return fmt::format("{}_e{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::SizeName(const std::string& name, int depth)
{
    return fmt::format("{}_size{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::IndexName(const std::string& name, int depth)
{
    return fmt::format("{}_i{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::KeyName(const std::string& name, int depth)
{
    return fmt::format("{}_key{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::ValueName(const std::string& name, int depth)
{
    return fmt::format("{}_value{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::CollectorName(const std::string& name, int depth)
{
    return fmt::format("{}_c{}", name, depth);
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetPushMethodBy(TMemberExtendedTypeInfo& ext)
{
    switch (ext.mCategory) {
        case TypeCategory::BOOL:
            return s_PushBool;
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            return s_PushNum;
        case TypeCategory::STRING:
            return s_PushStr;
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetPopMethodBy(TMemberExtendedTypeInfo& ext)
{
    switch (ext.mCategory) {
        case TypeCategory::BOOL:
            return s_PopBool;
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
            return s_PopNum;
        case TypeCategory::STRING:
            return s_PopStr;
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
std::string TBinaryMarshallerSourceFileGenerator::GetAccessName(std::vector<TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth)
{
    auto& ext = extArr[depth];
    switch (ext.mCategory) {
        case TypeCategory::MAP:
            return s_Second;
    }
    return "";
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObjMap(const std::string& keyType, const std::string& valueType, const std::string& name)
{
    std::string methodName = s_PopStrSerObjMap;
    if (keyType.length())
        methodName = s_PopNumSerObjMap;

    General_AddPopSerMap(keyType, valueType, "", name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtrMap(const std::string& keyType, const std::string& valueType, const std::string& name)
{
    std::string methodName = s_PopStrSerPtrMap;
    if (keyType.length())
        methodName = s_PopNumSerPtrMap;

    General_AddPopSerMap(keyType, valueType, "", name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtrMap(const std::string& keyType, const std::string& valueType,
    const std::string& smartPtrType, const std::string& name)
{
    std::string methodName = s_PopStrSerSmartPtrMap;
    if (keyType.length())
        methodName = s_PopNumSerSmartPtrMap;

    auto smartPtrTypeWithType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, valueType);
    General_AddPopSerMap(keyType, valueType, smartPtrTypeWithType, name, methodName);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopReflection(TMemberInfo* pMemberInfo)
{
    auto typeName = pMemberInfo->mExtendedInfo.GetTypeNameWithNameSpace();
    auto pTypeInfo = mTypeManager->Get(typeName);
    if (pTypeInfo == nullptr) {
        return;
    }

    auto type = pTypeInfo->mName;

    switch (pMemberInfo->mExtendedInfo.mAccessMethod) {
        case AccessMethod::OBJECT:
            AddPopSerObj(pMemberInfo->mName);
            break;
        case AccessMethod::POINTER:
            AddPopSerPtr(type, pMemberInfo->mName);
            break;
        case AccessMethod::SMART_POINTER:
            AddPopSerSmartPtr(type, pMemberInfo->mName);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObj(const std::string& name)
{
    auto ptrName = fmt::format("&({}->{})", s_TypeObject, name);
    General_AddPopReflection(ptrName, "", "");
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtr(const std::string& type, const std::string& name)
{
    auto ptrName = fmt::format("{}->{}", s_TypeObject, name);
    auto checkOnNullCondition = fmt::format("{}->{} == {} ", s_TypeObject, name, s_Nullptr);
    auto newPtrExpression = fmt::format("{}->{} = {}<{}>();", s_TypeObject, name, s_GeneralAllocate, type);
    General_AddPopReflection(ptrName, checkOnNullCondition, newPtrExpression);

    AddElse();
    AddLeftBrace();
    IncrementTabs();

    auto deallocateExpression = fmt::format("{}( {}->{} );", s_GeneralDeallocate, s_TypeObject, name);
    Add(deallocateExpression);

    auto setNullExpression = fmt::format("{}->{} = {};", s_TypeObject, name, s_Nullptr);
    Add(setNullExpression);

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtr(const std::string& type, const std::string& name)
{
    auto ptrName = fmt::format("{}->{}.get()", s_TypeObject, name);
    auto checkOnNullCondition = fmt::format("{}->{}.get() == nullptr ", s_TypeObject, name);
    auto newPtrExpression = fmt::format("{}->{}.reset( new {}() );", s_TypeObject, name, type);
    General_AddPopReflection(ptrName, checkOnNullCondition, newPtrExpression);

    AddElse();
    IncrementTabs();

    auto resetExpression = fmt::format("{}->{}.reset();", s_TypeObject, name);
    Add(resetExpression);

    DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNumSet(const std::string& type, const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList = {type};

    AddCallObjMethod(s_PopMaster, s_PopNumSet, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStrSet(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopStrSet, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopBuiltInArray(TMemberInfo* pMemberInfo)
{
    auto category = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mCategory;
    if (category == TypeCategory::BOOL) {
        AddPopBoolArray(pMemberInfo->mName);
    } else {
        auto& type = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mShortType;
        AddPopNumArray(type, pMemberInfo->mName);
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopBoolArray(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopBoolArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNumArray(const std::string& type, const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList = {type};

    AddCallObjMethod(s_PopMaster, s_PopNumArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStrArray(const std::string& name)
{
    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name)
    };
    std::list<std::string> templateList;

    AddCallObjMethod(s_PopMaster, s_PopStrArray, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopReflectionArray(TMemberInfo* pMemberInfo)
{
    auto withinClassTypeName = mCurrentTypeInfo->GetTypeNameWithNameSpace();

    auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
    auto pTypeInfo = mTypeManager->Get(templateType.GetTypeNameWithNameSpace());
    if (pTypeInfo == nullptr) {
        return;
    }
    auto type = pTypeInfo->GetTypeNameWithNameSpace();

    auto templateCategory = templateType.mCategory;
    switch (templateType.mAccessMethod) {
        case AccessMethod::OBJECT:
            AddPopSerObjArray(type, pMemberInfo->mName);
            break;
        case AccessMethod::POINTER:
            AddPopSerPtrArray(type, pMemberInfo->mName);
            break;
        case AccessMethod::SMART_POINTER:
            AddPopSerSmartPtrArray(type, templateType.mSmartPtrType, pMemberInfo->mName);
            break;
        default:
            break;
    }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObjArray(const std::string& type, const std::string& name)
{
    General_AddPopSerArray(type, "", name, s_PopSerObjArray);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtrArray(const std::string& type, const std::string& name)
{
    General_AddPopSerArray(type, "", name, s_PopSerPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name)
{
    auto fullType = fmt::format("{}{}<{}>", s_STD_, smartPtrType, type);
    General_AddPopSerArray(type, fullType, name, s_PopSerSmartPtrArray);
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerArray(const std::string& keyType,
    const std::string& smartPtrType, const std::string& name, const std::string& methodName)
{
    General_AddPushSerArrayOrMap(keyType, "", smartPtrType, name, methodName, true);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerMap(const std::string& keyType,
    const std::string& valueType, const std::string& smartPtrType,
    const std::string& name, const std::string& methodName)
{
    General_AddPushSerArrayOrMap(keyType, valueType, smartPtrType, name, methodName, false);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerArrayOrMap(const std::string& keyType,
    const std::string& valueType, const std::string& smartPtrType,
    const std::string& name, const std::string& methodName, bool arrayOrMap)
{
    auto strList = GetParamListForSerialize(arrayOrMap ? keyType : valueType);
    auto paramStr = EnumerateParamToStr(strList);

    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name),
        fmt::format("[this]( {0} ) {{ {1}( {2} ); }}", paramStr, s_Serialize, s_TypeObject)
    };
    std::list<std::string> templateList = {keyType, valueType, smartPtrType};

    AddCallObjMethod(s_PushMaster, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushReflection(const std::string& ptrName, const std::string& getAddress)
{
    auto getAddressExp = fmt::format("auto {} = {};", ptrName, getAddress);
    Add(getAddressExp);

    auto pushIsNotNullptr = fmt::format("{}( {} );", s_PushIsNotNullptr, ptrName);
    Add(pushIsNotNullptr);

    AddIf(ptrName);
    IncrementTabs();

    auto ser = fmt::format("{}( {} );", s_Serialize, ptrName);
    Add(ser);

    DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerArray(const std::string& keyType,
    const std::string& smartPtrType, const std::string& name, const std::string& methodName)
{
    General_AddPopSerArrayOrMap(keyType, "", smartPtrType, name, methodName, true);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerMap(const std::string& keyType,
    const std::string& valueType, const std::string& smartPtrType,
    const std::string& name, const std::string& methodName)
{
    General_AddPopSerArrayOrMap(keyType, valueType, smartPtrType, name, methodName, false);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerArrayOrMap(const std::string& keyType,
    const std::string& valueType, const std::string& smartPtrType,
    const std::string& name, const std::string& methodName, bool arrayOrMap)
{
    auto strList = GetParamListForSerialize(arrayOrMap ? keyType : valueType);
    auto paramStr = EnumerateParamToStr(strList);

    std::list<std::string> argList =
    {
        fmt::format("{}->{}", s_TypeObject, name),
        fmt::format("[this]( {0} ) {{ {1}( {2} ); }}", paramStr, s_Deserialize, s_TypeObject)
    };
    std::list<std::string> templateList = {keyType, valueType, smartPtrType};

    AddCallObjMethod(s_PopMaster, methodName, templateList, argList);
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopReflection(const std::string& ptrName, const std::string& checkOnNullCondition, const std::string& newPtrExpression)
{
    auto conditionIsNotNullptr = fmt::format("{}()", s_PopIsNotNullptr);
    AddIf(conditionIsNotNullptr);

    AddLeftBrace();
    IncrementTabs();

    if (checkOnNullCondition.length()) {
        AddIf(checkOnNullCondition);
        IncrementTabs();
        Add(newPtrExpression);
        DecrementTabs();
    }

    auto ser = fmt::format("{}( {} );", s_Deserialize, ptrName);
    Add(ser);

    DecrementTabs();
    AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
const std::list<std::string> TBinaryMarshallerSourceFileGenerator::GetBinaryImplementation()
{
    return
    {
      fmt::format("void {}::{}( int binarySize )", mSerializer->className, s_SetLimitForCompression),
      "{",
      "  mSetLimitForCompression = binarySize;",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format("{0}::{1} {0}::{2}( char* packedData, int size )", mSerializer->className, s_TypeID, s_GetID),
      "{",
      fmt::format("  auto pHeader = ({}*) packedData;", s_THeader),
      "  return pHeader->type;",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format("void {}::{}( void* p )", mSerializer->className, s_PushIsNotNullptr),
      "{",
      "  unsigned char isNullptr = p == nullptr ? 0 : 1;",
      fmt::format("  {}.PushNum( isNullptr );", s_PushMaster),
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format("bool {}::{}()", mSerializer->className, s_PopIsNotNullptr),
      "{",
      "  unsigned char isNullptr;",
      fmt::format("  {}.PopNum( isNullptr );", s_PopMaster),
      "  return ( isNullptr != 0 );",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format("{0}::{1} {0}::{2}( char* packedData, int size )", mSerializer->className, s_TypeID, s_PrepareForUnpackPopMaster),
      "{",
      fmt::format("  int headerSize = sizeof( {} );", s_THeader),
      fmt::format("  {} header;", s_THeader),
      "  memcpy( &header, packedData, headerSize );",
      "  char* pObj = packedData + headerSize;",
      "  int objSize = size - headerSize;",
      "",
      "  // decompression",
      "  if ( header.useCompression )",
      "  {",
      "    mBuffer.Clear();",
      "    mBuffer.Shift( objSize * header.ratio );// расширить для запаса под декомпрессию",
      "    int decompressedRes = LZ4_decompress_safe( pObj, mBuffer.GetPtr(), objSize, mBuffer.GetSize() );",
      "    mBuffer.Clear();",
      "    mBuffer.Shift( decompressedRes );",
      "  }",
      "  else",
      "  {",
      "    mBuffer.Clear();",
      "    mBuffer.Append( objSize, pObj );",
      "  }",
      fmt::format("  {}.SetBuffer( &mBuffer, 0 );", s_PopMaster),
      "  return header.type;",
      "}",
      "//-----------------------------------------------------------------------------",
    };
}
//-----------------------------------------------------------------------------------------------------------
