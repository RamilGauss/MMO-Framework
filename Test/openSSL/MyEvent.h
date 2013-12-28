#ifndef MyEventH
#define MyEventH

#include "ContainerObject.h"

struct TMyEvent
{
  unsigned int time_ms;
  int from;
  TContainer* pContainer;
  TMyEvent(){pContainer=NULL;}
  ~TMyEvent(){delete pContainer;}
  void Init(unsigned int time_create_ms)
  {
    pContainer = new TContainer;
    InitPrivate(time_create_ms);
  }
  template <typename T>
  void Init(unsigned int time_create_ms)
  {
    pContainer = (TContainer*)new TContainerObject<T>;
    InitPrivate(time_create_ms);
  }
protected:
  void InitPrivate(unsigned int time_create_ms)
  {
    if(time_create_ms!=-1)
      time_ms = ht_GetMSCount();
    else
      time_ms = time_create_ms;
  }
};


#endif