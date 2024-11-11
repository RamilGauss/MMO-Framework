/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/IHopProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TInstantiateProcess : public nsBase::nsZones::IHopProcess
    {
        enum class Zone
        {
            INIT,
            ASYNCED,
            SYNCED,
        };

        enum class Process
        {
            ASYNC,
            DUMMY_ASYNC,
            SYNC
        };
    public:
        std::string GetName() const override;
        boost::asio::awaitable<bool> Start(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        boost::asio::awaitable<void> Stop(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        nsBase::nsZones::TContextStateInProcess GetState(nsBase::nsZones::SharedPtrHopProcessContext pCtx) const override;
    protected:
        void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) override;
    };
}
