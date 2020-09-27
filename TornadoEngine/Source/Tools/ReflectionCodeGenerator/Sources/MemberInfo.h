/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <set>
#include "MemberTypeExtendedInfo.h"

struct TMemberInfo
{
  std::set<std::string> mPragmaTextSet;// #pragma TEXT

  enum AccessLevel
  {
    ePublic, eProtected, ePrivate
  };
  AccessLevel mAccessLevel;

  std::string mName;

  std::string mTypeName;

  TMemberTypeExtendedInfo mExtendedInfo;

  void CreateExtArray(std::vector<TMemberTypeExtendedInfo>& arr);
};
