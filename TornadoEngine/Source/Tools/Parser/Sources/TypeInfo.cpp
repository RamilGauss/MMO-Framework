/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeInfo.h"

using namespace nsCppParser;

std::string TTypeInfo::GetNameSpace()// all namespaces: A::B::...::Z
{
    std::string summa;
    auto size = mNamespaceVec.size();
    for ( auto i = 0; i < size; i++ )
    {
        summa += mNamespaceVec[i];
        if ( i != size - 1 )
            summa += "::";
    }
    return summa;
}
//-----------------------------------------------------------------------------------------
std::string TTypeInfo::GetTypeNameWithNameSpace()
{
    auto sNamespace = GetNameSpace();
    if ( sNamespace.length() > 0 )
        return sNamespace + "::" + mName;
    return mName;
}
//-----------------------------------------------------------------------------------------
std::string TTypeInfo::GetTypeNameWithNameSpaceAsVar()
{
    auto sNamespace = GetNameSpace();
    if ( sNamespace.length() > 0 )
        return sNamespace + "_" + mName;
    return mName;
}
//-----------------------------------------------------------------------------------------
void TTypeInfo::AddMember(TMemberInfo& memberInfo)
{
    // copy
    auto memberInfoPtr = TMemberInfoPtr(new TMemberInfo());
    memberInfoPtr.get()[0] = memberInfo;

    mMembers[(size_t)memberInfo.mAccessLevel].push_back(memberInfoPtr);
}
//-----------------------------------------------------------------------------------------
void TTypeInfo::ClearMember()
{
    for ( auto& v : mMembers ) {
        v.clear();
    }
}
//-----------------------------------------------------------------------------------------
