/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <atomic>

#include "Base/Common/TypeDef.h"

class DllExport TThreadBoost
{
    std::atomic_bool flgActive;
    std::atomic_bool flgNeedStop;

    std::atomic_uint32_t mTimeStart;
    enum
    {
        eWaitFeedBack = 1, // ждать пока активизируется двигатель, мс
    };

public:
    TThreadBoost();
    virtual ~TThreadBoost();

    virtual bool IsActive();
    virtual void Start();
    virtual void Stop();

    virtual unsigned int GetTimeLastStart();
    virtual unsigned int GetTimeWork();
protected:
    void Engine();
protected:
    virtual void Work() = 0;
    virtual void StartEvent()
    {}
    virtual void StopEvent()
    {}
};
