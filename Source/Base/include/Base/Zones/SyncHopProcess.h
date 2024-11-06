/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/IHopProcess.h"
#include "IHopProcess.h"

#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

namespace nsBase::nsZones
{
    class DllExport TSyncSubProcess : public ISubProcess
    {
    public:

        TSyncSubProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread, nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

        boost::asio::awaitable<void> Stop(IHopProcessContext* pCtx) override;
        boost::asio::awaitable<void> Start(IHopProcessContext* pCtx) override;
    };
}
