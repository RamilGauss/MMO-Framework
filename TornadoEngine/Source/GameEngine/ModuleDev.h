/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleDevH
#define ModuleDevH

#include "IModule.h"

class PrototypeDev;

/*
  Является источником события через TSrcEvent-TDstEvent
  и требует (не всегда) квант времени.
*/

class DllExport TModuleDev : public IModule
{
  PrototypeDev* mPrototypeDev;
public:
  TModuleDev();
  virtual ~TModuleDev();

  virtual bool Work();
  void SetPrototypeDev(PrototypeDev* ptr);
};

#endif
