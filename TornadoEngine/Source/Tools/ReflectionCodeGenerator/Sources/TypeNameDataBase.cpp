/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeNameDataBase.h"

using namespace nsReflectionCodeGenerator;
//-----------------------------------------------------------------------------------------------
void TTypeNameDataBase::AddForGenerate(TTypeInfo& typeInfo)
{
    mForGenerateList.insert(typeInfo);
}
//-----------------------------------------------------------------------------------------------
const std::set<TTypeNameDataBase::TTypeInfo>* TTypeNameDataBase::GetForGenerate() const
{
    return &mForGenerateList;
}
//-----------------------------------------------------------------------------------------------
void TTypeNameDataBase::AddReference(TReferenceInfo& refInfo)
{
    mFullTypeNameReferenceMap.insert({refInfo.typeInfo.GetFullType(), refInfo});
}
//-----------------------------------------------------------------------------------------------
const TTypeNameDataBase::TReferenceInfo* TTypeNameDataBase::GetReferenceFullTypeName(TRequestParams& requestParams)
{
    std::list<std::string> variants;
    GetReferenceVariants(requestParams, variants);

    for (auto& variant : variants) {
        auto findResult = Find(variant);
        if (findResult != nullptr) {
            return findResult;
        }
    }
    return nullptr;
}
//-----------------------------------------------------------------------------------------------
const TTypeNameDataBase::TReferenceInfo* TTypeNameDataBase::Find(const std::string& fullTypeName)
{
    auto fit = mFullTypeNameReferenceMap.find(fullTypeName);
    if (fit != mFullTypeNameReferenceMap.end()) {
        return &fit->second;
    }
    return nullptr;
}
//-----------------------------------------------------------------------------------------------
void TTypeNameDataBase::GetReferenceVariants(TRequestParams& requestParams, std::list<std::string>& variants)
{
    variants.clear();
    if (requestParams.typeInfo.nameSpace.empty()) {
        if (requestParams.preferredNameSpace.empty()) {
            variants.push_back(requestParams.typeInfo.typeName);
        } else {
            std::string fullTypeName = requestParams.preferredNameSpace + "::" + requestParams.typeInfo.typeName;
            variants.push_back(fullTypeName);
            variants.push_back(requestParams.typeInfo.typeName);
        }
    } else {
        variants.push_back(requestParams.typeInfo.GetFullType());
    }
}
//-----------------------------------------------------------------------------------------------
std::string TTypeNameDataBase::TTypeInfo::GetFullType() const
{
    if (nameSpace.empty()) {
        return typeName;
    }
    return nameSpace + "::" + typeName;
}
//-----------------------------------------------------------------------------------------------
bool TTypeNameDataBase::TTypeInfo::operator == (TTypeInfo const& p) const
{
    return nameSpace == p.nameSpace && typeName == p.typeName;
}
//-----------------------------------------------------------------------------------------------
bool TTypeNameDataBase::TTypeInfo::operator<(TTypeInfo const& p) const
{
    if (nameSpace < p.nameSpace) {
        return true;
    }
    if (nameSpace > p.nameSpace) {
        return false;
    }
    return typeName < p.typeName;
}
//-----------------------------------------------------------------------------------------------