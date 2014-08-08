/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterTimerH
#define AdapterTimerH

#include "PrototypeTimer.h"
#include <map>
#include "HiTimer.h"

// NOT Thread Safe!!!

class DllExport AdapterTimer : public PrototypeTimer
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

  virtual unsigned int New(int delta_time_ms, bool enable = true);
  virtual void Delete(unsigned int id);
  virtual void SetEnable(unsigned int id, bool val);
  virtual void SetInterval(unsigned int id, int val);

  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();

  virtual bool Work();

protected:
  TDescTimer* Get(unsigned int id);
  void Done();
};

#endif
