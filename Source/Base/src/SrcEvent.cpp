/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SrcEvent.h"
#include <stddef.h>
#include "BL_Debug.h"

using namespace std;

void TSrcEvent::SetDstObject(TDstEvent* p)
{
    pDstEvent = p;
}
//------------------------------------------------------------
void TSrcEvent::AddEventCopy(void* data, int size)
{
    pDstEvent->AddEventInQueueCopy(mTypeObject, this, data, size, (unsigned int) (-1));
}
//------------------------------------------------------------
void TSrcEvent::AddEventCopy(void* data, int size, unsigned int time_create_ms)
{
    pDstEvent->AddEventInQueueCopy(mTypeObject, this, data, size, time_create_ms);
}
//------------------------------------------------------------
void TSrcEvent::SetSelfID(int srcType)
{
    mTypeObject = srcType;
}
//------------------------------------------------------------
void TSrcEvent::Translate(nsEvent::TEvent* pEvent, bool use_self_info)
{
    if (use_self_info) {
        pEvent->srcType = mTypeObject;
        pEvent->pSrc = this;
    }

    pDstEvent->Translate(pEvent);
}
//------------------------------------------------------------
