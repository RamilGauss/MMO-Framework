/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include <boost/asio/io_context.hpp>

#include "Base/Common/CoroInThread.h"
#include "Base/Common/TypeDef.h"
#include "Base/Common/StrandHolder.h"

#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class DllExport TZoneManager
    {
    public:
        TZoneManager() = default;

        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder, nsBase::nsCommon::TCoroInThread::Ptr coroInThread);

        void AddZone(SharedPtrZone pZone);
        SharedPtrZone GetZone(const std::string& zoneName);

        void StartProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process, SharedPtrZone toZone);
    private:
        boost::asio::awaitable<void> AsyncStartProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process, SharedPtrZone toZone);

        std::list<SharedPtrZone> mZones;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;
    };
}
