/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextStateInProcess.h"

namespace nsBase::nsZones
{
    TContextStateInProcess::State TContextStateInProcess::GetState() const
    {
        return mState;
    }
    void TContextStateInProcess::SetState(State state)
    {
        mState = state;
    }
    bool TContextStateInProcess::IsFinishedOrStopped() const
    {
        return mState == State::CANCELED || mState == State::DONE;
    }
    bool TContextStateInProcess::IsWork() const
    {
        return mState == State::WORKING;
    }
    void TContextStateInProcess::SetSubProcessTotalPartCount(uint32_t value)
    {
        mSubProcessTotalPartCount = value;
    }
    void TContextStateInProcess::SetSubProcessCompletedPartCount(uint32_t value)
    {
        mSubProcessCompletedPartCount = value;
    }
    void TContextStateInProcess::SetSubProcessName(const std::string& value)
    {
        mSubProcessName = value;
    }
    uint32_t TContextStateInProcess::GetSubProcessTotalPartCount() const
    {
        return mSubProcessTotalPartCount;
    }
    uint32_t TContextStateInProcess::GetSubProcessCompletedPartCount() const
    {
        return mSubProcessCompletedPartCount;
    }
    std::string TContextStateInProcess::GetSubProcessName() const
    {
        return mSubProcessName;
    }

    void TContextStateInProcess::Increment()
    {
        mSubProcessCompletedPartCount++;
    }
    bool TContextStateInProcess::IsCompleted() const
    {
        return mSubProcessTotalPartCount == mSubProcessCompletedPartCount;
    }
}
