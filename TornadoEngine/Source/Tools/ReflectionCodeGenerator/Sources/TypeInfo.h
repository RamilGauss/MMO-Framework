/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <vector>
#include <list>
#include <map>
#include <memory>
#include "MemberInfo.h"
#include "InheritanceInfo.h"

struct TTypeInfo
{
    std::string mFileName;

    std::set<std::string> mPragmaTextSet;// #pragma TEXT

    enum eType
    {
        Class, Struct
    };
    eType mType;

    std::vector<TInheritanceInfo> mInheritanceVec;

    std::string mName;
    std::vector<std::string> mNamespaceVec;

    typedef std::shared_ptr<TMemberInfo> TMemberInfoPtr;
    typedef std::vector<TMemberInfoPtr> TMemberInfoPtrVec;
    typedef std::map<TMemberInfo::AccessLevel, TMemberInfoPtrVec> TAccessLevelMemberInfoPtrVecMap;

    TAccessLevelMemberInfoPtrVecMap mMemberMap;

    std::string GetNameSpace();// all namespaces: A::B::...::Z
    std::string GetTypeNameWithNameSpace();// namespace::typename

    void AddMember(TMemberInfo& memberInfo);

    void ClearMember();
};
