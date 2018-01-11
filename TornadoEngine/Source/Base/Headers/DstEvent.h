/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DstEventH
#define DstEventH

#include <string>
#include <vector>
#include "TypeDef.h"
#include "DescEvent.h"
#include "DataExchange2Thread.h"

/*
  поглотитель событий. работает в связке с TSrcEvent
  пронаследоваться,
  зарегистрировать источники с помощью функции AddSrcEvent
  и получать события через GetEvent
*/

class DllExport TDstEvent
{
  TDataExchange2Thread<nsEvent::TEvent>* mListEvent;
public:
  TDstEvent();
  virtual ~TDstEvent();

  void AddEventInQueueCopy(int type_object, void* ptr_src, void* data, int size, unsigned int time_create_ms);

  template<typename T>
  void AddEventInQueueWithoutCopy(int type_object, void* ptr_src, T* data, unsigned int time_create_ms);

  void Translate(nsEvent::TEvent* pEvent);
public:
  // забрал объект - уничтожь с помощью delete
  nsEvent::TEvent* GetEvent();
};
//-------------------------------------------------------------------------------------
template<typename T>
void TDstEvent::AddEventInQueueWithoutCopy(int type_object, void* ptr_src, T* data, unsigned int time_create_ms)
{
  nsEvent::TEvent* pEvent = new nsEvent::TEvent();
  pEvent->Init<T>(time_create_ms);
  
  pEvent->type_object = type_object;
  pEvent->ptr_object = ptr_src;
  pEvent->pContainer->EntrustByCount((char*)data,1);
  
  mListEvent->Add(pEvent);
}
//-------------------------------------------------------------------------------------

#endif
