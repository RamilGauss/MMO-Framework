/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/AsyncAwaitable.h"

namespace nsBase::nsZones
{
    struct DllExport TContextStateInProcess
    {
        enum class State
        {
            IDLE,
            WORK,
            STOP,
            FINISH,
        };

        State GetState() const
        {
            return mState;
        }

        void SetState(State state)
        {
            mState = state;
        }

        bool IsFinishedOrStopped() const
        {
            return mState == State::STOP || mState == State::FINISH;
        }
        bool IsWork() const
        {
            return mState == State::WORK;
        }
    private:
        State mState;
    };

}
