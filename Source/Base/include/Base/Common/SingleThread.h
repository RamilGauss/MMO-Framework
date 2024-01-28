/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <thread>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TSingleThread
    {
        const uint32_t WAIT_FEED_BACK_MS = 1;

        std::jthread mThread;

    public:
        TSingleThread();
        virtual ~TSingleThread();

        virtual bool IsActive();
        virtual void Start();
        virtual void Stop();

    protected:
        void Engine();
    protected:
        virtual void Work() = 0;
        virtual void StartEvent()
        {
        }
        virtual void StopEvent()
        {
        }
    };
}