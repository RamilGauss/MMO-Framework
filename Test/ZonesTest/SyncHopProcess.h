/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

class TSyncHopProcess
{
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
    THopProcessState mState;
public:

    TSyncHopProcess(nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

    boost::asio::awaitable<void> Stop();
    boost::asio::awaitable<void> Start();
    THopProcessState GetState() const;
protected:
    virtual void Work() {};
};
