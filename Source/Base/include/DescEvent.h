/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "HiTimer.h"

namespace nsEvent
{
#pragma pack(push, 1)

    struct DllExport TEvent
    {
        unsigned int time_ms;
        int srcType;
        void* pSrc = nullptr;
        IContainer* pContainer = nullptr;
        ~TEvent()
        {
            delete pContainer;
        }
        void Init(unsigned int time_create_ms)
        {
            pContainer = new TContainer();
            InitPrivate(time_create_ms);
        }
        template <typename T>
        void Init(unsigned int time_create_ms)
        {
            pContainer = new TContainerArrObj<T>;
            InitPrivate(time_create_ms);
        }
    protected:
        void InitPrivate(unsigned int time_create_ms)
        {
            if (time_create_ms != -1)
                time_ms = ht_GetMSCount();
            else
                time_ms = time_create_ms;
        }
    };
#pragma pack(pop)
}