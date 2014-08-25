/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SrcEvent_ExH
#define SrcEvent_ExH

#include "DstEvent.h"
#include "SrcEvent.h"

//-------------------------------------------------------------------------------
template<typename T>
void TSrcEvent::AddEventWithoutCopy(T* pObject)
{
  BL_ASSERT(pDstEvent);
  pDstEvent->AddEventInQueueWithoutCopy<T>(mTypeObject, this, pObject, -1);
}
//-------------------------------------------------------------------------------
template<typename T>
void TSrcEvent::AddEventWithoutCopy(T* pObject, unsigned int time_create_ms)
{
  BL_ASSERT(pDstEvent);
  pDstEvent->AddEventInQueueWithoutCopy<T>(mTypeObject, this, pObject, time_create_ms);
}
//-------------------------------------------------------------------------------


#endif
