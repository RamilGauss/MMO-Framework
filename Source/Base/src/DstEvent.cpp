/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/DstEvent.h"

using namespace nsEvent;

TDstEvent::TDstEvent() : 
    mListEvent(100'000)
{
}
//------------------------------------------------------------
TDstEvent::~TDstEvent()
{
}
//------------------------------------------------------------
void TDstEvent::AddEventInQueueCopy(int srcType, void* ptr_src, void* data, int size, unsigned int time_create_ms)
{
    auto pEvent = std::make_shared<nsEvent::TEvent>();
    pEvent->Init(time_create_ms);

    pEvent->pSrc = ptr_src;
    pEvent->srcType = srcType;
    pEvent->pContainer->SetDataByCount((char*)data, size);// sizeof(char)==1, поэтому size

    mListEvent.push(pEvent);
}
//------------------------------------------------------------
PEvent TDstEvent::GetEvent()
{
    nsEvent::PEvent pEvent;
    if (mListEvent.try_pop(pEvent)) {
        return pEvent;
    }
    return {};
}
//------------------------------------------------------------
void TDstEvent::Translate(nsEvent::PEvent pEvent)
{
    mListEvent.push(pEvent);
}
//------------------------------------------------------------
