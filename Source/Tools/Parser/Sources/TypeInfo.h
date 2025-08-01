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

#include "Parser/Sources/MemberInfo.h"
#include "Parser/Sources/InheritanceInfo.h"
#include "Parser/Sources/MethodInfo.h"

namespace nsCppParser
{
#pragma REFLECTION_ATTRIBUTE
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

        using TMemberInfoPtr = std::shared_ptr<TMemberInfo>;
        using TMemberInfoPtrVec = std::vector<TMemberInfoPtr>;
        using TAccessLevelMemberInfoPtrVecArray = std::array<TMemberInfoPtrVec, (size_t)AccessLevel::COUNT>;

        TAccessLevelMemberInfoPtrVecArray mMembers;

        using TMethodInfoPtr = std::shared_ptr<TMethodInfo>;
        using TMethodInfoPtrVec = std::vector<TMethodInfoPtr>;
        using TAccessLevelMethodInfoPtrVecArray = std::array<TMethodInfoPtrVec, (size_t)AccessLevel::COUNT>;

        TAccessLevelMethodInfoPtrVecArray mMethods;

        std::string GetNameSpace() const;// all namespaces: A::B::...::Z
        std::string GetNameSpaceAsVar() const;// all namespaces: A_B_..._Z

        std::string GetTypeNameWithNameSpace() const;// namespace::typename
        std::string GetTypeNameWithNameSpaceAsVar() const;// namespace_typename

        void AddMember(TMemberInfo& memberInfo);
        void AddMethod(TMethodInfo& methodInfo);

        void ClearMembers();
        void ClearMethods();
    };
}
