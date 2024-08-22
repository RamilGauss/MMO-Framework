#pragma once

/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

struct THopProcessState
{
    int commonCount = 0;
    int progressCount = 0;

    std::string state;

    void Increment()
    {
        progressCount++;
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
        return state == "stop" || state == "finish";
    }
    bool IsWork() const
    {
        return state == "work";
    }
};
