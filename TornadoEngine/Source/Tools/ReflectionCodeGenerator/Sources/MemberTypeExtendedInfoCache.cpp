/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MemberTypeExtendedInfoCache.h"


TMemberTypeExtendedInfo* TMemberTypeExtendedInfoCache::TryGetFromCache(const std::string& memberName)
{
    auto fit = mTokenCache.find(memberName);
    if ( fit == mTokenCache.end() ) {
        return nullptr;
    }
    return fit->second.get();
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoCache::AddToCache(const std::string& memberName, TMemberTypeExtendedInfo& memberInfo)
{
    TMemberInfoPtr memberInfoPtr;
    memberInfoPtr.reset(new TMemberTypeExtendedInfo(memberInfo));
    mTokenCache.insert(TStrInfoPtrMap::value_type(memberName, memberInfoPtr));
}
//------------------------------------------------------------------------------
