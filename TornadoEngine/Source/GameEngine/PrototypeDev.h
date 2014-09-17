/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeDevH
#define PrototypeDevH

#include "TypeDef.h"

class TSrcEvent;

class DllExport PrototypeDev
{
  TSrcEvent* mSrcEvent;

public:
  PrototypeDev();
  virtual ~PrototypeDev();

  virtual bool Work() = 0;

  void SetSrcEvent(TSrcEvent* pSrcEvent);
  TSrcEvent* GetSrcEvent();
};

#endif
