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
        std::string mAbsFileName;

        std::set<std::string> mPragmaTextSet;// #pragma TEXT

        DeclarationType mType;

        std::set<std::string> mEnumKeys;

        std::vector<TInheritanceInfo> mInheritanceVec;

        std::string mName;
        std::vector<std::string> mNamespaceVec;
        std::vector<std::string> mTemplateArgs;

        using TMethodInfoPtr = std::shared_ptr<TMethodInfo>;
        using TMethodInfoPtrVec = std::vector<TMethodInfoPtr>;
        using TAccessLevelMethodInfoPtrVecArray = std::array<TMethodInfoPtrVec, (size_t)AccessLevel::COUNT>;

        TAccessLevelMethodInfoPtrVecArray mMethods;

        using TMemberInfoPtr = std::shared_ptr<TMemberInfo>;
        using TMemberInfoPtrVec = std::vector<TMemberInfoPtr>;
        using TAccessLevelMemberInfoPtrVecArray = std::array<TMemberInfoPtrVec, (size_t)AccessLevel::COUNT>;

        TAccessLevelMemberInfoPtrVecArray mMembers;

        std::string GetNameSpace();// all namespaces: A::B::...::Z
        std::string GetNameSpaceAsVar();// all namespaces: A_B_..._Z

        std::string GetTypeNameWithNameSpace();// namespace::typename
        std::string GetTypeNameWithNameSpaceAsVar();// namespace_typename

        void AddMember(TMemberInfo& memberInfo);
        void AddMethod(TMethodInfo& methodInfo);

        void ClearMembers();
        void ClearMethods();
    };
}