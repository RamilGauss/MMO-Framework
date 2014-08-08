/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeTimerH
#define PrototypeTimerH

#include "PrototypeBaseModule.h"

class DllExport PrototypeTimer : public PrototypeBaseModule
{
public:
  struct TEvent
  {
    unsigned int id;
  };

  PrototypeTimer();
  virtual ~PrototypeTimer();

  virtual unsigned int New(int delta_time_ms, bool enable = true) = 0;
  virtual void Delete(unsigned int id) = 0;
  virtual void SetEnable(unsigned int id, bool val) = 0;
  virtual void SetInterval(unsigned int id, int val) = 0;

	virtual int GetVersionPrototype();
};

#endif
