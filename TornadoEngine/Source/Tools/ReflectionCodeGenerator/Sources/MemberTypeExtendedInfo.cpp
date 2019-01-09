/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MemberTypeExtendedInfo.h"

bool TMemberTypeExtendedInfo::IsContainer()
{
  return mCategory == Vector ||
    mCategory == List || 
    mCategory == Set || 
    mCategory == Map;
}
