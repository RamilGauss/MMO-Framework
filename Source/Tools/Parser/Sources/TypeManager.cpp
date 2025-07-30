/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <memory>
#include "Parser/Sources/TypeManager.h"

using namespace nsCppParser;

//--------------------------------------------------------------------------------------
void TTypeManager::Add(std::string& nameSpaceName, TTypeInfo& typeInfo)
{
    auto fit = mNameSpaceTypesMap.find(nameSpaceName);
    if ( fit == mNameSpaceTypesMap.end() ) {
        mNameSpaceTypesMap.insert({ nameSpaceName, std::shared_ptr<TStrPtrMap>(new TStrPtrMap()) });
    }
    fit = mNameSpaceTypesMap.find(nameSpaceName);

    auto fitType = fit->second->find(typeInfo.mName);
    TTypeInfo* pTypeInfo = nullptr;

    if ( fitType == fit->second->end() ) {
        pTypeInfo = new TTypeInfo(typeInfo);
        fit->second->insert(TStrPtrMap::value_type(typeInfo.mName, std::shared_ptr<TTypeInfo>(pTypeInfo)));
    } else {
        pTypeInfo = fitType->second.get();
        pTypeInfo[0] = typeInfo;
    }

    auto nameSpaceTypeName = pTypeInfo->GetTypeNameWithNameSpace();

    mNameTypeInfoPtrMap.insert({ nameSpaceTypeName, pTypeInfo });
}
//--------------------------------------------------------------------------------------
TTypeInfo* TTypeManager::FindTypeInfo(const std::string& nameSpaceTypeName)
{
    auto fit = mNameTypeInfoPtrMap.find(nameSpaceTypeName);
    if ( fit == mNameTypeInfoPtrMap.end() ) {
        return nullptr;
    }
    return fit->second;
}
//--------------------------------------------------------------------------------------
TTypeInfo* TTypeManager::FindTypeInfoBy(const std::string& nameSpaceTypeName, const std::string& withinClassTypename)
{
    std::string nsWithin;
    std::string tnWithin;
    Split(withinClassTypename, nsWithin, tnWithin);

    if ( nsWithin.length() == 0 ) {
        return FindTypeInfo(nameSpaceTypeName);
    }

    std::string nsTarget;
    std::string tnTarget;
    Split(nameSpaceTypeName, nsTarget, tnTarget);

    std::string nsTypeName = nsWithin + "::" + nameSpaceTypeName;

    auto tt = FindTypeInfo(nsTypeName);
    if ( tt != nullptr ) {
        return tt;
    }

    return FindTypeInfo(nameSpaceTypeName);
}
//--------------------------------------------------------------------------------------
void TTypeManager::Split(const std::string& nameSpaceTypeName, std::string& nameSpace, std::string& typeName)
{
    const std::string cc = "::";

    auto ccIndex = nameSpaceTypeName.find(cc);
    if ( ccIndex == std::string::npos ) {
        typeName = nameSpaceTypeName;
        nameSpace = "";
        return;
    }

    nameSpace = nameSpaceTypeName.substr(0, ccIndex);
    typeName = nameSpaceTypeName.substr(ccIndex + cc.length(), nameSpaceTypeName.length() - ccIndex - cc.length());
}
//--------------------------------------------------------------------------------------
