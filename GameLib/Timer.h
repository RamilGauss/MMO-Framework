/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TimerH
#define TimerH

#include "ITimer.h"
#include <map>
#include "../Share/HiTimer.h"

// NOT Thread Safe!!!

class TTimer : public ITimer
{
  unsigned int mLastID;

  struct TDescTimer
  {
    unsigned int start_time_ms;

    unsigned int id;
    unsigned int interval_ms;
    bool enable;
    TDescTimer()
    {
      start_time_ms = ht_GetMSCount();
    }
  };

  typedef std::map<unsigned int,TDescTimer*> TMapDescPtr;
  typedef TMapDescPtr::iterator TMapDescPtrIt;

  TMapDescPtr mMapIDTimer;

public:
  TTimer();
  virtual ~TTimer();

  virtual void Work();

  virtual unsigned int New(int interval_ms, bool enable = true);
  virtual void Delete(unsigned int id);
  virtual void SetEnable(unsigned int id, bool val);
  virtual void SetInterval(unsigned int id, int val);
protected:
  TDescTimer* Get(unsigned int id);
  void Done();
};

#endif
