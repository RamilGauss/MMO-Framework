/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "MemberInfo.h"

std::vector<TMemberTypeExtendedInfo> TMemberInfo::CreateExtArray()
{
  auto pExt = &mExtendedInfo;
  std::vector<TMemberTypeExtendedInfo> arr;
  arr.push_back( *pExt );
  while( pExt->mTemplateChildArr.size() > 0 )
  {
    pExt = &(pExt->mTemplateChildArr.back());
    arr.push_back( *pExt );
  }
  return arr;
}
