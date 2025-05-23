/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "Base/Common/DescEvent.h"
#include "Base/Common/MPMCQueue.h"

/*
  поглотитель событий. работает в связке с TSrcEvent
  пронаследоваться,
  зарегистрировать источники с помощью функции AddSrcEvent
  и получать события через GetEvent
*/

class DllExport TDstEvent
{
    rigtorp::MPMCQueue<nsEvent::PEvent> mListEvent;
public:
    TDstEvent();
    virtual ~TDstEvent();

    void AddEventInQueueCopy(int srcType, void* ptr_src, void* data, int size, unsigned int time_create_ms);

    template<typename T>
    void AddEventInQueueWithoutCopy(int srcType, void* ptr_src, T* data, unsigned int time_create_ms);

    void Translate(nsEvent::PEvent pEvent);
public:
    // забрал объект - уничтожь с помощью delete
    nsEvent::PEvent GetEvent();
};
//-------------------------------------------------------------------------------------
template<typename T>
void TDstEvent::AddEventInQueueWithoutCopy(int srcType, void* ptr_src, T* data, unsigned int time_create_ms)
{
    auto pEvent = std::make_shared<nsEvent::TEvent>();
    pEvent->Init<T>(time_create_ms);

    pEvent->srcType = srcType;
    pEvent->pSrc = ptr_src;
    pEvent->pContainer->EntrustByCount((char*)data, 1);

    mListEvent.push(pEvent);
}
//-------------------------------------------------------------------------------------
