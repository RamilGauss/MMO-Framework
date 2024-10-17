/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

//#include "Base/Zones/HopProcess.h"
//
//namespace nsBase::nsZones
//{
//    class DllExport TAsyncHopProcess : public THopProcess
//    {
//    protected:
//        boost::asio::awaitable<void> AsyncWork(IHopProcessContext* ctx) override;
//    };
//}

#pragma once

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"
#include "IHopProcess.h"

namespace nsBase::nsZones
{
    class DllExport TAsyncHopProcess : public IHopProcess
    {
    public:
        TAsyncHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
            nsBase::nsCommon::TStrandHolder::Ptr strandHolder);
        boost::asio::awaitable<void> Stop(IHopProcessContext* pCtx) override;
        boost::asio::awaitable<void> Start(IHopProcessContext* pCtx) override;

    protected:

        boost::asio::awaitable<void> WorkInOtherThread();
        boost::asio::awaitable<void> FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable);
        boost::asio::awaitable<void> StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable);
        boost::asio::awaitable<void> UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
            THopProcessState& state);
    };
}
