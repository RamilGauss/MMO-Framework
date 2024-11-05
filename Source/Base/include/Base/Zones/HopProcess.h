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

#include "Base/Zones/HopProcessState.h"

namespace nsBase::nsZones
{
    class DllExport THopProcess
    {
    public:
        THopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
            nsBase::nsCommon::TStrandHolder::Ptr strandHolder, 
            SharedPtrZone zone);
        virtual ~THopProcess();

        virtual boost::asio::awaitable<void> Start(IHopProcessContext* pCtx) = 0;
        virtual boost::asio::awaitable<void> Stop(IHopProcessContext* pCtx) = 0;

        THopProcessState GetState(IHopProcessContext* pCtx) const;

        virtual std::string GetName() const = 0;

        virtual uint32_t GetSubProcessTotalPartCount() const = 0;
        virtual uint32_t GetSubProcessCompletedPartCount() const = 0;
        virtual std::string GetSubProcessName() const = 0;
    protected:

        // Main thread
        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

        // Second thread
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        SharedPtrZone mZone;

        std::unordered_map<IHopProcessContext*, SharedPtrContextState> mCtxStateMap;
    };
}
