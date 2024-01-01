/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/DstEvent.h"

using namespace nsEvent;

TDstEvent::TDstEvent()
{
    mListEvent = new TDataExchange2Thread<TEvent>();
}
//------------------------------------------------------------
TDstEvent::~TDstEvent()
{
    delete mListEvent;
}
//------------------------------------------------------------
void TDstEvent::AddEventInQueueCopy(int srcType, void* ptr_src, void* data, int size, unsigned int time_create_ms)
{
    TEvent* pEvent = new TEvent;
    pEvent->Init(time_create_ms);

    pEvent->pSrc = ptr_src;
    pEvent->srcType = srcType;
    pEvent->pContainer->SetDataByCount((char*)data, size);// sizeof(char)==1, поэтому size

    mListEvent->Add(pEvent);
}
//------------------------------------------------------------
TEvent* TDstEvent::GetEvent()
{
    TEvent** ppEvent = mListEvent->GetFirst();
    if (ppEvent == nullptr)
        return nullptr;

    TEvent* pEvent = *(ppEvent);
    mListEvent->UnlinkData(ppEvent);
    mListEvent->RemoveFirst();
    return pEvent;
}
//------------------------------------------------------------
void TDstEvent::Translate(nsEvent::TEvent* pEvent)
{
    mListEvent->Add(pEvent);
}
//------------------------------------------------------------
