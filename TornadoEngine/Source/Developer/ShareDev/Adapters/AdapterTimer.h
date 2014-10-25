/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterTimerH
#define AdapterTimerH

#include "PrototypeDev.h"
#include <map>
#include "HiTimer.h"

class DllExport AdapterTimer : public PrototypeDev
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
  struct TEvent
  {
    unsigned int id;
  };

  AdapterTimer();
  virtual ~AdapterTimer();

  virtual bool Work();

  unsigned int New(int delta_time_ms, bool enable = true);
  void Delete(unsigned int id);
  void SetEnable(unsigned int id, bool val);
  void SetInterval(unsigned int id, int val);

protected:
  TDescTimer* Get(unsigned int id);
  void Done();
};

#endif
