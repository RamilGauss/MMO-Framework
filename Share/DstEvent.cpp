/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DstEvent.h"
#include "SrcEvent.h"
#include "ListMultiThread.h"

using namespace nsEvent;

TDstEvent::TDstEvent()
{
  pListEvent = new TListMultiThread<TEvent>;
}
//------------------------------------------------------------
TDstEvent::~TDstEvent()
{
  delete pListEvent;
}
//------------------------------------------------------------
void TDstEvent::AddEventInQueueCopy(int from, void* data, int size, unsigned int time_create_ms)
{
  TEvent* pEvent = new TEvent;
  pEvent->Init(time_create_ms);

  pEvent->from = from;
  pEvent->pContainer->SetDataByCount((char*)data, size);// sizeof(char)==1, поэтому size
  pListEvent->Add(pEvent);
}
//------------------------------------------------------------
TEvent* TDstEvent::GetEvent()
{
  TEvent** ppEvent = pListEvent->GetFirst();
  if(ppEvent==NULL) return NULL;
  TEvent* pEvent = *(ppEvent);
  pListEvent->ZeroPointerElement(ppEvent);
  pListEvent->Remove(ppEvent);
  return pEvent;
}
//------------------------------------------------------------
void TDstEvent::AddSrcEvent(TSrcEvent* pSrcEvent)
{
  pSrcEvent->SetDstObject(this);
}
//------------------------------------------------------------
