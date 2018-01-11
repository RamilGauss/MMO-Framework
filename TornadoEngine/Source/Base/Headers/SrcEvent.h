/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SrcEventH
#define SrcEventH

#include "TypeDef.h"
#include "DescEvent.h"
#include "DstEvent.h"

/*
  источник событий. работает в связке с TDstEvent
  пронаследоваться,
  добавлять события AddEvent
*/

class DllExport TSrcEvent
{
  int mTypeObject;
  TDstEvent* pDstEvent;

public:

  TSrcEvent();
  virtual ~TSrcEvent();

  void SetSelfID(int type_object);

  void SetDstObject(TDstEvent* p);
  // можно добавлять события через источник 
  // добавить событие
  void AddEventCopy(void* data, int size);
  void AddEventCopy(void* data, int size, unsigned int time_create_ms);


  // Note: to use this methods include "SrcEvent_ex.h"
  template<typename T>
  void AddEventWithoutCopy(T* pObject);
  template<typename T>
  void AddEventWithoutCopy(T* pObject, unsigned int time_create_ms);

  void Translate(nsEvent::TEvent* pEvent, bool use_self_info = true);
};
//-------------------------------------------------------------------------------


#endif
