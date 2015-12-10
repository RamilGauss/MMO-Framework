/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModelItemH
#define ModelItemH

#include "BaseItem.h"

struct DllExport TModelItem : public TBaseItem
{
  std::string mNamePattern;
  

  TModelItem(std::string& name);
};

#endif
