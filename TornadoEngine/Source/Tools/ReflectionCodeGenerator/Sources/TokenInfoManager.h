/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TokenInfo.h"

class TTokenInfoManager
{
public:
  typedef std::list<TTokenInfo> TTokenInfoList;
  typedef TTokenInfoList::iterator TTokenInfoListIt;

  typedef std::map<std::string, TTokenInfoList> TStrListMap;
  typedef TStrListMap::value_type TStrListMapVT;

  TStrListMap mTokenInfoMap;

protected:
  TTokenInfoManager() { };
  friend class TSingletonManager;// for singleton pattern

};