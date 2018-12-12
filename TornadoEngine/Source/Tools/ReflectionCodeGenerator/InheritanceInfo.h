/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "MemberInfo.h"

struct TInheritanceInfo
{
  std::string mParentTypeName;
  TMemberInfo::AccessLevel mInheritanceAccessLevel = TMemberInfo::ePrivate;
};

