/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/FramedThread.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/SingletonManager.h"

namespace nsBase::nsCommon
{
    TFramedThread::~TFramedThread()
    {
        Stop();
    }
    //----------------------------------------------------------------------------------
    void TFramedThread::Engine()
    {
        auto stopToken = mThread.get_stop_token();

        while (not stopToken.stop_requested()) {
            mFrameFunc();
        }
    }
    //----------------------------------------------------------------------------------
    void TFramedThread::Start(std::function<void()>&& frameFunc)
    {
        if (frameFunc == nullptr || IsActive()) {
            return;
        }

        mFrameFunc = std::move(frameFunc);

        mThread = std::jthread(&TFramedThread::Engine, this);

        while (not IsActive()) {
            ht_msleep(WAIT_FEED_BACK_MS);
        }
    }
    //----------------------------------------------------------------------------------
    void TFramedThread::Stop()
    {
        if (IsActive()) {
            mThread.request_stop();
            mThread.join();
        }
    }
    //----------------------------------------------------------------------------------
    bool TFramedThread::IsActive() const
    {
        return mThread.joinable();
    }
    //---------------------------------------------------------------------------------
}
