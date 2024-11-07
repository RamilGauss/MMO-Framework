/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/ISubProcess.h"

namespace nsBase::nsZones
{
    class DllExport TAsyncSubProcess : public ISubProcess
    {
    public:
        boost::asio::awaitable<void> Start(SharedPtrHopProcessContext pCtx) override;
        boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) override;

    protected:

        boost::asio::awaitable<void> WorkInOtherThread(SharedPtrHopProcessContext pCtx, SharedPtrContextState pState);
        boost::asio::awaitable<void> FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState);
        boost::asio::awaitable<void> StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState);
        boost::asio::awaitable<void> UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
            SharedPtrContextState pState);
    };
}
