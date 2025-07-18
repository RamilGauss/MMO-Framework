/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <thread>
#include <functional>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TFramedThread final
    {
        const uint32_t WAIT_FEED_BACK_MS = 1;

        std::jthread mThread;

        std::function<void()> mFrameFunc;

    public:
        ~TFramedThread();

        bool IsActive() const;
        void Start(std::function<void()>&& frameFunc);
        void Stop();

    private:
        void Engine();
    };
}
