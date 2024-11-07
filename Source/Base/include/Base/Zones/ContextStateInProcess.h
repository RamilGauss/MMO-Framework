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
            WORKING,
            CANCELED,
            DONE,
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
            return mState == State::CANCELED || mState == State::DONE;
        }
        bool IsWork() const
        {
            return mState == State::WORKING;
        }

        void SetSubProcessTotalPartCount(uint32_t value) { mSubProcessTotalPartCount = value; };
        void SetSubProcessCompletedPartCount(uint32_t value) { mSubProcessCompletedPartCount = value; };
        void SetSubProcessName(const std::string& value) { mSubProcessName = value; };

        uint32_t GetSubProcessTotalPartCount() const { return mSubProcessTotalPartCount; };
        uint32_t GetSubProcessCompletedPartCount() const { return mSubProcessCompletedPartCount; };
        std::string GetSubProcessName() const { return mSubProcessName; };

        void Increment() { mSubProcessCompletedPartCount++; }
        bool IsCompleted() const { return mSubProcessCompletedPartCount == mSubProcessCompletedPartCount; };
    private:
        State mState;

        uint32_t mSubProcessTotalPartCount;
        uint32_t mSubProcessCompletedPartCount;
        std::string mSubProcessName;
    };

}
