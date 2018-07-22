/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <string>
#include <vector>

// получение ip-адреса
class DllExport TResolverSelf_IP_v4
{
  struct TDescHost
  {
    std::string s;
    unsigned int ip;
  };

  typedef std::vector<TDescHost> TVectorDesc;

  static inline TVectorDesc* mVecDesc = nullptr;
public:
  TResolverSelf_IP_v4();

  int GetCount();
  bool Get( std::string& sIP, int numNetWork = 0 );
  bool Get( unsigned int& numIP, int numNetWork = 0 );
private:
  static void InitVecDesc();
};
