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

#include "Base/Zones/ZoneManagerMaster.h"

namespace nsBase::nsZones
{
    class DllExport IHopSubProcess
    {
    public:
        IHopSubProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
            nsBase::nsCommon::TStrandHolder::Ptr strandHolder);
        virtual ~IHopSubProcess();

        virtual boost::asio::awaitable<void> Start(IHopProcessContext* pCtx) = 0;
        virtual boost::asio::awaitable<void> Stop(IHopProcessContext* pCtx) = 0;
        
        std::optional<SharedPtrContextState> GetState(IHopProcessContext* pCtx) const;
    protected:
        virtual void Work() {};

        // Main thread
        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

        // Second thread
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        std::unordered_map<IHopProcessContext*, SharedPtrContextState> mCtxStateMap;
    };
}
