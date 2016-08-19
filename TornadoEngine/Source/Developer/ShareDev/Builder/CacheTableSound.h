/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CacheTableSoundH
#define CacheTableSoundH

#include "TypeDef.h"

struct TTableSoundItem;

class DllExport TCacheTableSound
{
public:
  TCacheTableSound();
  virtual ~TCacheTableSound();

  void Set(TTableSoundItem* pTableSoundItem);
  void WorkFromThread_OpenAL();
};

#endif
