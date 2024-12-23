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
    class ISubProcess;
    class DllExport IHopProcess
    {
    public:
        explicit IHopProcess(std::string name);
        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread);
        virtual ~IHopProcess() = default;

        std::string GetName() const;
        virtual boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) = 0;
        virtual boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) = 0;
        virtual TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const = 0;
    protected:
        virtual void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) = 0;

        void SetCurrentSubProcess(SharedPtrHopProcessContext pCtx, ISubProcess* pCurrentSubvProcess);
        ISubProcess* GetCurrentSubProcess(SharedPtrHopProcessContext pCtx) const;

        std::string mName;

        // Main thread
        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

        // Second thread
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        std::unordered_map<SharedPtrHopProcessContext, ISubProcess*> mCurrentSubProcess;
    };
}
