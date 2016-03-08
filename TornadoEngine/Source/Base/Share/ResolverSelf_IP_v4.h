/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ResolverSelf_IP_v4H
#define ResolverSelf_IP_v4H

#include "TypeDef.h"

// получение ip-адреса
class DllExport TResolverSelf_IP_v4
{
public:
  int GetCount();
  bool Get(std::string& sIP,    int numNetWork = 0);
  bool Get(unsigned int& numIP, int numNetWork = 0);
};
//------------------------------------------------------------------------------------------------------

#endif
