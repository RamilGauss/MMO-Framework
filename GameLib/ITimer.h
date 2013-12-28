/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ITimerH
#define ITimerH

#include "../Share/SrcEvent.h"

class ITimer : public TSrcEvent
{
public:
  struct TEvent
  {
    unsigned int id;
  };

  virtual ~ITimer(){};

  virtual void Work() = 0;

  virtual unsigned int New(int delta_time_ms, bool enable = true) = 0;
  virtual void Delete(unsigned int id) = 0;
  virtual void SetEnable(unsigned int id, bool val) = 0;
  virtual void SetInterval(unsigned int id, int val) = 0;
};

#endif
