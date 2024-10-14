/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "gtest/gtest.h"

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

struct THopProcessState
{
    std::string 
    int commonCount = 0;
    int progressCount = 0;

    enum class State
    {
        IDLE,
        WORK,
        STOP,
        FINISH,
    };
    State state;

    void Increment()
    {
        progressCount++;
    }

    State GetState() const
    {
        return state;
    }

    float GetProgress() const
    {
        if (commonCount == 0)
            return -1.0f;
        return (progressCount * 100.0f) / commonCount;
    }

    bool IsCompleted() const
    {
        return commonCount == progressCount;
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
