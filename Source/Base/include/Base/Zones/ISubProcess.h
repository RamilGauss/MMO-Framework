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

#include "Base/Zones/Types.h"
#include "Base/Zones/ContextStateInProcess.h"

namespace nsBase::nsZones
{
    class DllExport ISubProcess
    {
    public:
        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread);

        virtual ~ISubProcess();

        virtual boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) = 0;
        virtual boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) = 0;
        
        TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const;
    protected:
        virtual void Launch(SharedPtrHopProcessContext pCtx) {};
        virtual uint32_t GetTotalPartCount(SharedPtrHopProcessContext pCtx) = 0;
        virtual void Work(SharedPtrHopProcessContext pCtx) = 0;
        virtual void Finalize(SharedPtrHopProcessContext pCtx) {};

        // Main thread
        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

        // Second thread
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        std::unordered_map<SharedPtrHopProcessContext, SharedPtrContextState> mCtxStateMap;
    };
}
