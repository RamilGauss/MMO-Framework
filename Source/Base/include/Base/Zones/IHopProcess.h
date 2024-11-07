/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <memory>
#include <string>
#include <type_traits>

#include <boost/asio/awaitable.hpp>

#include "Base/Common/AsyncAwaitable.h"
#include "Base/Common/CallbackPool.h"
#include "Base/Common/CoroInThread.h"
#include "Base/Common/TypeDef.h"

#include "Base/Zones/ContextStateInProcess.h"
#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class DllExport IHopProcess
    {
    public:
        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread);
        virtual ~IHopProcess() = default;

        virtual std::string GetName() const = 0;
        virtual boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) = 0;
        virtual boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) = 0;
        virtual TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const = 0;
    protected:
        virtual void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) = 0;

        // Main thread
        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

        // Second thread
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;
    };
}
