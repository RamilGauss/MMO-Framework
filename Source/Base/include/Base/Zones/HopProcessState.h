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
    struct DllExport THopProcessState
    {
        enum class State
        {
            IDLE,
            WORK,
            STOP,
            FINISH,
        };
        State state;

        State GetState() const
        {
            return state;
        }

        bool IsFinishedOrStopped() const
        {
            return state == State::STOP || state == State::FINISH;
        }
        bool IsWork() const
        {
            return state == State::WORK;
        }
    };

}
