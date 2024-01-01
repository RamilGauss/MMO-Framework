/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/DstEvent.h"
#include "Base/Common/SrcEvent.h"
#include "Base/Common/BL_Debug.h"

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
