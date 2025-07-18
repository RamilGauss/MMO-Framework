/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stdint.h>
#include <string>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsZones
{
    struct DllExport TContextStateInProcess
    {
        enum class State
        {
            IDLE,
            WORKING,
            CANCELED,
            DONE,
        };

        State GetState() const;
        void SetState(State state);
        bool IsFinishedOrStopped() const;
        bool IsWork() const;

        void SetSubProcessTotalPartCount(uint32_t value);
        void SetSubProcessCompletedPartCount(uint32_t value);
        void SetSubProcessName(const std::string& value);

        uint32_t GetSubProcessTotalPartCount() const;
        uint32_t GetSubProcessCompletedPartCount() const;
        std::string GetSubProcessName() const;

        void Increment();
        bool IsCompleted() const;
    private:
        State mState = State::IDLE;

        uint32_t mSubProcessTotalPartCount = 0;
        uint32_t mSubProcessCompletedPartCount = 0;
        std::string mSubProcessName;
    };

}
