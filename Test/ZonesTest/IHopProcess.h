/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

class IHopProcess
{
public:
    IHopProcess(nsBase::nsCommon::TStrandHolder::Ptr strandHolder) {}
    virtual ~IHopProcess() {}

    virtual boost::asio::awaitable<void> Stop() = 0;
    virtual boost::asio::awaitable<void> Start() = 0;
    virtual THopProcessState GetState() const = 0;
protected:
    virtual void Work() {};
};
