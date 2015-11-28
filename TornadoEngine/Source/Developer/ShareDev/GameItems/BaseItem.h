/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseItemH
#define BaseItemH

#include <string>
#include "TypeDef.h"

struct DllExport TBaseItem
{
  std::string mName;

  TBaseItem(std::string& name);
};

#endif
