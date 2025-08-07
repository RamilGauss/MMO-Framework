/*
	Parser
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "Parser/Sources/GeneratedFiles/JsonSerializer.h"

using namespace nsCppParser;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TJsonSerializer::TypeFunc> TJsonSerializer::mTypeFuncVector;

void TJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<TypeFunc> funcs;
    
    TypeFunc _nsCppParser_TInheritanceInfoTypeFunc;
    _nsCppParser_TInheritanceInfoTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCppParser::TInheritanceInfo>((nsCppParser::TInheritanceInfo*) p, str);
    };
    _nsCppParser_TInheritanceInfoTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCppParser::TInheritanceInfo>((nsCppParser::TInheritanceInfo*) p, str, err);
    };
    
    _nsCppParser_TInheritanceInfoTypeFunc.rtti = globalTypeIdentifier->Type<nsCppParser::TInheritanceInfo>();
    
    funcs.push_back(_nsCppParser_TInheritanceInfoTypeFunc);
    
    TypeFunc _nsCppParser_TMemberExtendedTypeInfoTypeFunc;
    _nsCppParser_TMemberExtendedTypeInfoTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCppParser::TMemberExtendedTypeInfo>((nsCppParser::TMemberExtendedTypeInfo*) p, str);
    };
    _nsCppParser_TMemberExtendedTypeInfoTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCppParser::TMemberExtendedTypeInfo>((nsCppParser::TMemberExtendedTypeInfo*) p, str, err);
    };
    
    _nsCppParser_TMemberExtendedTypeInfoTypeFunc.rtti = globalTypeIdentifier->Type<nsCppParser::TMemberExtendedTypeInfo>();
    
    funcs.push_back(_nsCppParser_TMemberExtendedTypeInfoTypeFunc);
    
    TypeFunc _nsCppParser_TMemberInfoTypeFunc;
    _nsCppParser_TMemberInfoTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCppParser::TMemberInfo>((nsCppParser::TMemberInfo*) p, str);
    };
    _nsCppParser_TMemberInfoTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCppParser::TMemberInfo>((nsCppParser::TMemberInfo*) p, str, err);
    };
    
    _nsCppParser_TMemberInfoTypeFunc.rtti = globalTypeIdentifier->Type<nsCppParser::TMemberInfo>();
    
    funcs.push_back(_nsCppParser_TMemberInfoTypeFunc);
    
    TypeFunc _nsCppParser_TTypeInfoTypeFunc;
    _nsCppParser_TTypeInfoTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCppParser::TTypeInfo>((nsCppParser::TTypeInfo*) p, str);
    };
    _nsCppParser_TTypeInfoTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCppParser::TTypeInfo>((nsCppParser::TTypeInfo*) p, str, err);
    };
    
    _nsCppParser_TTypeInfoTypeFunc.rtti = globalTypeIdentifier->Type<nsCppParser::TTypeInfo>();
    
    funcs.push_back(_nsCppParser_TTypeInfoTypeFunc);
    
    TypeFunc _nsCppParser_TTypeReferenceTypeFunc;
    _nsCppParser_TTypeReferenceTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCppParser::TTypeReference>((nsCppParser::TTypeReference*) p, str);
    };
    _nsCppParser_TTypeReferenceTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCppParser::TTypeReference>((nsCppParser::TTypeReference*) p, str, err);
    };
    
    _nsCppParser_TTypeReferenceTypeFunc.rtti = globalTypeIdentifier->Type<nsCppParser::TTypeReference>();
    
    funcs.push_back(_nsCppParser_TTypeReferenceTypeFunc);
    
    int max = 0;
    for (auto& f : funcs) {
        max = std::max(f.rtti, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& f : funcs) {
        mTypeFuncVector[f.rtti] = f;
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::AccessLevel* p)
{
    switch (*p) {
        case nsCppParser::AccessLevel::COUNT:
            return "COUNT";
        case nsCppParser::AccessLevel::PRIVATE:
            return "PRIVATE";
        case nsCppParser::AccessLevel::PROTECTED:
            return "PROTECTED";
        case nsCppParser::AccessLevel::PUBLIC:
            return "PUBLIC";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::AccessLevel* p)
{
    std::map<std::string, nsCppParser::AccessLevel> m;
    m.insert({"COUNT", nsCppParser::AccessLevel::COUNT});
    m.insert({"PRIVATE", nsCppParser::AccessLevel::PRIVATE});
    m.insert({"PROTECTED", nsCppParser::AccessLevel::PROTECTED});
    m.insert({"PUBLIC", nsCppParser::AccessLevel::PUBLIC});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::AccessMethod* p)
{
    switch (*p) {
        case nsCppParser::AccessMethod::OBJECT:
            return "OBJECT";
        case nsCppParser::AccessMethod::POINTER:
            return "POINTER";
        case nsCppParser::AccessMethod::SMART_POINTER:
            return "SMART_POINTER";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::AccessMethod* p)
{
    std::map<std::string, nsCppParser::AccessMethod> m;
    m.insert({"OBJECT", nsCppParser::AccessMethod::OBJECT});
    m.insert({"POINTER", nsCppParser::AccessMethod::POINTER});
    m.insert({"SMART_POINTER", nsCppParser::AccessMethod::SMART_POINTER});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::DeclarationType* p)
{
    switch (*p) {
        case nsCppParser::DeclarationType::CLASS:
            return "CLASS";
        case nsCppParser::DeclarationType::ENUM:
            return "ENUM";
        case nsCppParser::DeclarationType::STRUCT:
            return "STRUCT";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::DeclarationType* p)
{
    std::map<std::string, nsCppParser::DeclarationType> m;
    m.insert({"CLASS", nsCppParser::DeclarationType::CLASS});
    m.insert({"ENUM", nsCppParser::DeclarationType::ENUM});
    m.insert({"STRUCT", nsCppParser::DeclarationType::STRUCT});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::MethodCategoryType* p)
{
    switch (*p) {
        case nsCppParser::MethodCategoryType::CTOR:
            return "CTOR";
        case nsCppParser::MethodCategoryType::DTOR:
            return "DTOR";
        case nsCppParser::MethodCategoryType::NONE:
            return "NONE";
        case nsCppParser::MethodCategoryType::OPERATOR:
            return "OPERATOR";
        case nsCppParser::MethodCategoryType::OVERRIDE:
            return "OVERRIDE";
        case nsCppParser::MethodCategoryType::OVERRIDE_FINAL:
            return "OVERRIDE_FINAL";
        case nsCppParser::MethodCategoryType::STATIC:
            return "STATIC";
        case nsCppParser::MethodCategoryType::TEMPLATE:
            return "TEMPLATE";
        case nsCppParser::MethodCategoryType::TEMPLATE_STATIC:
            return "TEMPLATE_STATIC";
        case nsCppParser::MethodCategoryType::VIRTUAL:
            return "VIRTUAL";
        case nsCppParser::MethodCategoryType::VIRTUAL_DTOR:
            return "VIRTUAL_DTOR";
        case nsCppParser::MethodCategoryType::VIRTUAL_PURE:
            return "VIRTUAL_PURE";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::MethodCategoryType* p)
{
    std::map<std::string, nsCppParser::MethodCategoryType> m;
    m.insert({"CTOR", nsCppParser::MethodCategoryType::CTOR});
    m.insert({"DTOR", nsCppParser::MethodCategoryType::DTOR});
    m.insert({"NONE", nsCppParser::MethodCategoryType::NONE});
    m.insert({"OPERATOR", nsCppParser::MethodCategoryType::OPERATOR});
    m.insert({"OVERRIDE", nsCppParser::MethodCategoryType::OVERRIDE});
    m.insert({"OVERRIDE_FINAL", nsCppParser::MethodCategoryType::OVERRIDE_FINAL});
    m.insert({"STATIC", nsCppParser::MethodCategoryType::STATIC});
    m.insert({"TEMPLATE", nsCppParser::MethodCategoryType::TEMPLATE});
    m.insert({"TEMPLATE_STATIC", nsCppParser::MethodCategoryType::TEMPLATE_STATIC});
    m.insert({"VIRTUAL", nsCppParser::MethodCategoryType::VIRTUAL});
    m.insert({"VIRTUAL_DTOR", nsCppParser::MethodCategoryType::VIRTUAL_DTOR});
    m.insert({"VIRTUAL_PURE", nsCppParser::MethodCategoryType::VIRTUAL_PURE});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsCppParser::TInheritanceInfo* p, Jobj& obj)
{
    _Serialize((nsCppParser::TTypeReference*)p, obj);// Inheritances
    auto mInheritanceAccessLevel_c0 = _SerializeEnum(&(p->mInheritanceAccessLevel));
    PUM::Push(obj, "mInheritanceAccessLevel", mInheritanceAccessLevel_c0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsCppParser::TInheritanceInfo* p, const Jobj& obj)
{
    _Deserialize((nsCppParser::TTypeReference*)p, obj);// Inheritances
    std::string mInheritanceAccessLevel_c0;
    POM::PopStr(obj, "mInheritanceAccessLevel", mInheritanceAccessLevel_c0);
    _DeserializeEnum(mInheritanceAccessLevel_c0, &(p->mInheritanceAccessLevel));
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsCppParser::TMemberExtendedTypeInfo* p, Jobj& obj)
{
    auto mCategory_c0 = _SerializeEnum(&(p->mCategory));
    PUM::Push(obj, "mCategory", mCategory_c0);
    auto mAccessMethod_c0 = _SerializeEnum(&(p->mAccessMethod));
    PUM::Push(obj, "mAccessMethod", mAccessMethod_c0);
    PUM::Value mTemplateChildArr_a0(rapidjson::kArrayType);
    for(size_t mTemplateChildArr_i0 = 0 ; mTemplateChildArr_i0 < p->mTemplateChildArr.size() ; mTemplateChildArr_i0++) {
        auto& mTemplateChildArr_e0 = p->mTemplateChildArr[mTemplateChildArr_i0];
        PUM::Value mTemplateChildArr_a1(rapidjson::kObjectType);
        auto mTemplateChildArr_c1 = mTemplateChildArr_a1.GetObject();
        _Serialize(&mTemplateChildArr_e0, mTemplateChildArr_c1);
        PUM::PushBack(mTemplateChildArr_a0, mTemplateChildArr_a1);
    }
    PUM::Push(obj, "mTemplateChildArr", mTemplateChildArr_a0);
    PUM::Push(obj, "mShortType", p->mShortType);
    PUM::Push(obj, "mLongType", p->mLongType);
    PUM::Push(obj, "mNameSpace", p->mNameSpace);
    PUM::Push(obj, "mSmartPtrType", p->mSmartPtrType);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsCppParser::TMemberExtendedTypeInfo* p, const Jobj& obj)
{
    std::string mCategory_c0;
    POM::PopStr(obj, "mCategory", mCategory_c0);
    _DeserializeEnum(mCategory_c0, &(p->mCategory));
    std::string mAccessMethod_c0;
    POM::PopStr(obj, "mAccessMethod", mAccessMethod_c0);
    _DeserializeEnum(mAccessMethod_c0, &(p->mAccessMethod));
    auto mTemplateChildArr_a0 = POM::FindArray(obj, "mTemplateChildArr");
    for(auto& mTemplateChildArr_e0 : mTemplateChildArr_a0) {
        auto mTemplateChildArr_o1 = mTemplateChildArr_e0.GetObject();
        nsCppParser::TMemberExtendedTypeInfo mTemplateChildArr_c1;
        _Deserialize(&mTemplateChildArr_c1, mTemplateChildArr_o1);
        p->mTemplateChildArr.push_back(mTemplateChildArr_c1);
    }
    POM::PopStr(obj, "mShortType", p->mShortType);
    POM::PopStr(obj, "mLongType", p->mLongType);
    POM::PopStr(obj, "mNameSpace", p->mNameSpace);
    POM::PopStr(obj, "mSmartPtrType", p->mSmartPtrType);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsCppParser::TMemberInfo* p, Jobj& obj)
{
    PUM::Value mPragmaTextSet_a0(rapidjson::kArrayType);
    for(auto mPragmaTextSet_e0 : p->mPragmaTextSet) {
        PUM::PushBack(mPragmaTextSet_a0, mPragmaTextSet_e0);
    }
    PUM::Push(obj, "mPragmaTextSet", mPragmaTextSet_a0);
    auto mAccessLevel_c0 = _SerializeEnum(&(p->mAccessLevel));
    PUM::Push(obj, "mAccessLevel", mAccessLevel_c0);
    PUM::Push(obj, "mName", p->mName);
    PUM::Push(obj, "mTypeName", p->mTypeName);
    auto mCategory_c0 = _SerializeEnum(&(p->mCategory));
    PUM::Push(obj, "mCategory", mCategory_c0);
    auto mExtendedInfo_o = PUM::AddObject(obj, "mExtendedInfo");
    _Serialize(&(p->mExtendedInfo), mExtendedInfo_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsCppParser::TMemberInfo* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "mPragmaTextSet")) {
        auto mPragmaTextSet_a0 = POM::FindArray(obj, "mPragmaTextSet");
        for(auto& mPragmaTextSet_e0 : mPragmaTextSet_a0) {
            p->mPragmaTextSet.insert(mPragmaTextSet_e0.GetString());
        }
    } else {
        std::string mPragmaTextSet_t0;
        POM::PopStr(obj, "mPragmaTextSet", mPragmaTextSet_t0);
        p->mPragmaTextSet.insert(mPragmaTextSet_t0);
    }
    std::string mAccessLevel_c0;
    POM::PopStr(obj, "mAccessLevel", mAccessLevel_c0);
    _DeserializeEnum(mAccessLevel_c0, &(p->mAccessLevel));
    POM::PopStr(obj, "mName", p->mName);
    POM::PopStr(obj, "mTypeName", p->mTypeName);
    std::string mCategory_c0;
    POM::PopStr(obj, "mCategory", mCategory_c0);
    _DeserializeEnum(mCategory_c0, &(p->mCategory));
    auto mExtendedInfo_o0 = POM::FindObject(obj, "mExtendedInfo");
    _Deserialize(&(p->mExtendedInfo), mExtendedInfo_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsCppParser::TTypeInfo* p, Jobj& obj)
{
    PUM::Push(obj, "mFileName", p->mFileName);
    PUM::Push(obj, "mAbsFileName", p->mAbsFileName);
    PUM::Value mPragmaTextSet_a0(rapidjson::kArrayType);
    for(auto mPragmaTextSet_e0 : p->mPragmaTextSet) {
        PUM::PushBack(mPragmaTextSet_a0, mPragmaTextSet_e0);
    }
    PUM::Push(obj, "mPragmaTextSet", mPragmaTextSet_a0);
    auto mType_c0 = _SerializeEnum(&(p->mType));
    PUM::Push(obj, "mType", mType_c0);
    PUM::Value mEnumKeys_a0(rapidjson::kArrayType);
    for(auto mEnumKeys_e0 : p->mEnumKeys) {
        PUM::PushBack(mEnumKeys_a0, mEnumKeys_e0);
    }
    PUM::Push(obj, "mEnumKeys", mEnumKeys_a0);
    PUM::Value mInheritanceVec_a0(rapidjson::kArrayType);
    for(size_t mInheritanceVec_i0 = 0 ; mInheritanceVec_i0 < p->mInheritanceVec.size() ; mInheritanceVec_i0++) {
        auto& mInheritanceVec_e0 = p->mInheritanceVec[mInheritanceVec_i0];
        PUM::Value mInheritanceVec_a1(rapidjson::kObjectType);
        auto mInheritanceVec_c1 = mInheritanceVec_a1.GetObject();
        _Serialize(&mInheritanceVec_e0, mInheritanceVec_c1);
        PUM::PushBack(mInheritanceVec_a0, mInheritanceVec_a1);
    }
    PUM::Push(obj, "mInheritanceVec", mInheritanceVec_a0);
    PUM::Push(obj, "mName", p->mName);
    PUM::Value mNamespaceVec_a0(rapidjson::kArrayType);
    for(size_t mNamespaceVec_i0 = 0 ; mNamespaceVec_i0 < p->mNamespaceVec.size() ; mNamespaceVec_i0++) {
        auto& mNamespaceVec_e0 = p->mNamespaceVec[mNamespaceVec_i0];
        PUM::PushBack(mNamespaceVec_a0, mNamespaceVec_e0);
    }
    PUM::Push(obj, "mNamespaceVec", mNamespaceVec_a0);
    PUM::Value mTemplateArgs_a0(rapidjson::kArrayType);
    for(size_t mTemplateArgs_i0 = 0 ; mTemplateArgs_i0 < p->mTemplateArgs.size() ; mTemplateArgs_i0++) {
        auto& mTemplateArgs_e0 = p->mTemplateArgs[mTemplateArgs_i0];
        PUM::PushBack(mTemplateArgs_a0, mTemplateArgs_e0);
    }
    PUM::Push(obj, "mTemplateArgs", mTemplateArgs_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsCppParser::TTypeInfo* p, const Jobj& obj)
{
    POM::PopStr(obj, "mFileName", p->mFileName);
    POM::PopStr(obj, "mAbsFileName", p->mAbsFileName);
    if (POM::IsArray(obj, "mPragmaTextSet")) {
        auto mPragmaTextSet_a0 = POM::FindArray(obj, "mPragmaTextSet");
        for(auto& mPragmaTextSet_e0 : mPragmaTextSet_a0) {
            p->mPragmaTextSet.insert(mPragmaTextSet_e0.GetString());
        }
    } else {
        std::string mPragmaTextSet_t0;
        POM::PopStr(obj, "mPragmaTextSet", mPragmaTextSet_t0);
        p->mPragmaTextSet.insert(mPragmaTextSet_t0);
    }
    std::string mType_c0;
    POM::PopStr(obj, "mType", mType_c0);
    _DeserializeEnum(mType_c0, &(p->mType));
    if (POM::IsArray(obj, "mEnumKeys")) {
        auto mEnumKeys_a0 = POM::FindArray(obj, "mEnumKeys");
        for(auto& mEnumKeys_e0 : mEnumKeys_a0) {
            p->mEnumKeys.insert(mEnumKeys_e0.GetString());
        }
    } else {
        std::string mEnumKeys_t0;
        POM::PopStr(obj, "mEnumKeys", mEnumKeys_t0);
        p->mEnumKeys.insert(mEnumKeys_t0);
    }
    auto mInheritanceVec_a0 = POM::FindArray(obj, "mInheritanceVec");
    for(auto& mInheritanceVec_e0 : mInheritanceVec_a0) {
        auto mInheritanceVec_o1 = mInheritanceVec_e0.GetObject();
        nsCppParser::TInheritanceInfo mInheritanceVec_c1;
        _Deserialize(&mInheritanceVec_c1, mInheritanceVec_o1);
        p->mInheritanceVec.push_back(mInheritanceVec_c1);
    }
    POM::PopStr(obj, "mName", p->mName);
    if (POM::IsArray(obj, "mNamespaceVec")) {
        auto mNamespaceVec_a0 = POM::FindArray(obj, "mNamespaceVec");
        for(auto& mNamespaceVec_e0 : mNamespaceVec_a0) {
            p->mNamespaceVec.push_back(mNamespaceVec_e0.GetString());
        }
    } else {
        std::string mNamespaceVec_t0;
        POM::PopStr(obj, "mNamespaceVec", mNamespaceVec_t0);
        p->mNamespaceVec.push_back(mNamespaceVec_t0);
    }
    if (POM::IsArray(obj, "mTemplateArgs")) {
        auto mTemplateArgs_a0 = POM::FindArray(obj, "mTemplateArgs");
        for(auto& mTemplateArgs_e0 : mTemplateArgs_a0) {
            p->mTemplateArgs.push_back(mTemplateArgs_e0.GetString());
        }
    } else {
        std::string mTemplateArgs_t0;
        POM::PopStr(obj, "mTemplateArgs", mTemplateArgs_t0);
        p->mTemplateArgs.push_back(mTemplateArgs_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsCppParser::TTypeReference* p, Jobj& obj)
{
    PUM::Push(obj, "mOriginalName", p->mOriginalName);
    PUM::Push(obj, "mOriginalTypeName", p->mOriginalTypeName);
    PUM::Push(obj, "mOriginalNameSpace", p->mOriginalNameSpace);
    PUM::Push(obj, "mShortTypeName", p->mShortTypeName);
    PUM::Push(obj, "mNameSpace", p->mNameSpace);
    PUM::Push(obj, "mLongTypeName", p->mLongTypeName);
    PUM::Value originalTemplates_a0(rapidjson::kArrayType);
    for(auto& originalTemplates_e0 : p->originalTemplates) {
        PUM::PushBack(originalTemplates_a0, originalTemplates_e0);
    }
    PUM::Push(obj, "originalTemplates", originalTemplates_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsCppParser::TTypeReference* p, const Jobj& obj)
{
    POM::PopStr(obj, "mOriginalName", p->mOriginalName);
    POM::PopStr(obj, "mOriginalTypeName", p->mOriginalTypeName);
    POM::PopStr(obj, "mOriginalNameSpace", p->mOriginalNameSpace);
    POM::PopStr(obj, "mShortTypeName", p->mShortTypeName);
    POM::PopStr(obj, "mNameSpace", p->mNameSpace);
    POM::PopStr(obj, "mLongTypeName", p->mLongTypeName);
    if (POM::IsArray(obj, "originalTemplates")) {
        auto originalTemplates_a0 = POM::FindArray(obj, "originalTemplates");
        for(auto& originalTemplates_e0 : originalTemplates_a0) {
            p->originalTemplates.push_back(originalTemplates_e0.GetString());
        }
    } else {
        std::string originalTemplates_t0;
        POM::PopStr(obj, "originalTemplates", originalTemplates_t0);
        p->originalTemplates.push_back(originalTemplates_t0);
    }
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::TemplateArgument* p)
{
    switch (*p) {
        case nsCppParser::TemplateArgument::CLASS:
            return "CLASS";
        case nsCppParser::TemplateArgument::TYPE:
            return "TYPE";
        case nsCppParser::TemplateArgument::TYPENAME:
            return "TYPENAME";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::TemplateArgument* p)
{
    std::map<std::string, nsCppParser::TemplateArgument> m;
    m.insert({"CLASS", nsCppParser::TemplateArgument::CLASS});
    m.insert({"TYPE", nsCppParser::TemplateArgument::TYPE});
    m.insert({"TYPENAME", nsCppParser::TemplateArgument::TYPENAME});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::TypeCategory* p)
{
    switch (*p) {
        case nsCppParser::TypeCategory::ARRAY:
            return "ARRAY";
        case nsCppParser::TypeCategory::BOOL:
            return "BOOL";
        case nsCppParser::TypeCategory::CEIL_NUMBER:
            return "CEIL_NUMBER";
        case nsCppParser::TypeCategory::LIST:
            return "LIST";
        case nsCppParser::TypeCategory::MAP:
            return "MAP";
        case nsCppParser::TypeCategory::NUMBER:
            return "NUMBER";
        case nsCppParser::TypeCategory::REFLECTION:
            return "REFLECTION";
        case nsCppParser::TypeCategory::SET:
            return "SET";
        case nsCppParser::TypeCategory::SMART_POINTER:
            return "SMART_POINTER";
        case nsCppParser::TypeCategory::STRING:
            return "STRING";
        case nsCppParser::TypeCategory::VECTOR:
            return "VECTOR";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::TypeCategory* p)
{
    std::map<std::string, nsCppParser::TypeCategory> m;
    m.insert({"ARRAY", nsCppParser::TypeCategory::ARRAY});
    m.insert({"BOOL", nsCppParser::TypeCategory::BOOL});
    m.insert({"CEIL_NUMBER", nsCppParser::TypeCategory::CEIL_NUMBER});
    m.insert({"LIST", nsCppParser::TypeCategory::LIST});
    m.insert({"MAP", nsCppParser::TypeCategory::MAP});
    m.insert({"NUMBER", nsCppParser::TypeCategory::NUMBER});
    m.insert({"REFLECTION", nsCppParser::TypeCategory::REFLECTION});
    m.insert({"SET", nsCppParser::TypeCategory::SET});
    m.insert({"SMART_POINTER", nsCppParser::TypeCategory::SMART_POINTER});
    m.insert({"STRING", nsCppParser::TypeCategory::STRING});
    m.insert({"VECTOR", nsCppParser::TypeCategory::VECTOR});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsCppParser::VariableCategory* p)
{
    switch (*p) {
        case nsCppParser::VariableCategory::CONST:
            return "CONST";
        case nsCppParser::VariableCategory::MUTABLE:
            return "MUTABLE";
        case nsCppParser::VariableCategory::NONE:
            return "NONE";
        case nsCppParser::VariableCategory::STATIC:
            return "STATIC";
        case nsCppParser::VariableCategory::STATIC_CONST:
            return "STATIC_CONST";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::VariableCategory* p)
{
    std::map<std::string, nsCppParser::VariableCategory> m;
    m.insert({"CONST", nsCppParser::VariableCategory::CONST});
    m.insert({"MUTABLE", nsCppParser::VariableCategory::MUTABLE});
    m.insert({"NONE", nsCppParser::VariableCategory::NONE});
    m.insert({"STATIC", nsCppParser::VariableCategory::STATIC});
    m.insert({"STATIC_CONST", nsCppParser::VariableCategory::STATIC_CONST});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
