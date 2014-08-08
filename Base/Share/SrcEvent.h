/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SrcEventH
#define SrcEventH

#include "TypeDef.h"
//#include <string>
//#include "BL_Debug.h"

class TDstEvent;

/*
  источник событий. работает в св€зке с TDstEvent
  пронаследоватьс€,
  добавл€ть событи€ AddEvent
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
  // можно добавл€ть событи€ через источник 
  // добавить событие
  void AddEventCopy(void* data, int size);
  void AddEventCopy(void* data, int size, unsigned int time_create_ms);


  // Note: to use this methods include "SrcEvent_ex.h"
  template<typename T>
  void AddEventWithoutCopy(T* pObject);
  template<typename T>
  void AddEventWithoutCopy(T* pObject, unsigned int time_create_ms);
};
//-------------------------------------------------------------------------------


#endif
