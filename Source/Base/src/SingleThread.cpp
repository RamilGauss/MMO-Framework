/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SingleThread.h"

namespace nsBase::nsCommon
{
    TSingleThread::TSingleThread()
    {

    }
    //-----------------------------------------------------------------
    TSingleThread::~TSingleThread()
    {
        Stop();
    }
    //-----------------------------------------------------------------
    void TSingleThread::Engine()
    {
        auto stopToken = mThread.get_stop_token();

        StartEvent();

        while (not stopToken.stop_requested()) {
            Work();
        }

        StopEvent();
    }
    //----------------------------------------------------------------------------------
    void TSingleThread::Start()
    {
        mThread = std::jthread(&TSingleThread::Engine, this);

        while (not mThread.joinable()) {
            int a = 0;
        }
    }
    //----------------------------------------------------------------------------------
    void TSingleThread::Stop()
    {
        mThread.request_stop();
        mThread.join();
    }
    //----------------------------------------------------------------------------------
    bool TSingleThread::IsActive()
    {
        return mThread.joinable();
    }
    //---------------------------------------------------------------------------------
}
