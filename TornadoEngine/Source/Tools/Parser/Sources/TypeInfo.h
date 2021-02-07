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
#include <array>

#include "MemberInfo.h"
#include "InheritanceInfo.h"
#include "MethodInfo.h"

namespace nsCppParser
{
    struct DllExport TTypeInfo
    {
        std::string mFileName;

        std::set<std::string> mPragmaTextSet;// #pragma TEXT

        DeclarationType mType;

        std::vector<TInheritanceInfo> mInheritanceVec;

        std::string mName;
        std::vector<std::string> mNamespaceVec;

        typedef std::shared_ptr<TMethodInfo> TMethodInfoPtr;
        typedef std::vector<TMethodInfoPtr> TMethodInfoPtrVec;
        typedef std::array<TMethodInfoPtrVec, (size_t)AccessLevel::COUNT> TAccessLevelMethodInfoPtrVecArray;

        TAccessLevelMethodInfoPtrVecArray mMethods;

        typedef std::shared_ptr<TMemberInfo> TMemberInfoPtr;
        typedef std::vector<TMemberInfoPtr> TMemberInfoPtrVec;
        typedef std::array<TMemberInfoPtrVec, (size_t)AccessLevel::COUNT> TAccessLevelMemberInfoPtrVecArray;

        TAccessLevelMemberInfoPtrVecArray mMembers;

        std::string GetNameSpace();// all namespaces: A::B::...::Z
        std::string GetTypeNameWithNameSpace();// namespace::typename
        std::string GetTypeNameWithNameSpaceAsVar();// namespace_typename

        void AddMember(TMemberInfo& memberInfo);

        void ClearMember();
    };
}