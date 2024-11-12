/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "Base/Common/CoroInThread.h"
#include "Base/Common/TypeDef.h"
#include "Base/Common/StrandHolder.h"

#include "Base/Zones/Types.h"
#include "Base/Zones/ContextStateInProcess.h"

namespace nsBase::nsZones
{
    class DllExport TZoneManager
    {
    public:
        TZoneManager() = default;

        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder, nsBase::nsCommon::TCoroInThread::Ptr coroInThread);

        void AddZone(SharedPtrZone pZone);
        SharedPtrZone GetZone(const std::string& zoneName);

        void LinkContext(SharedPtrHopProcessContext ctx, SharedPtrZone pZone);
        void RemoveContext(SharedPtrHopProcessContext ctx);
        SharedPtrZone GetZone(SharedPtrHopProcessContext ctx) const;

        SharedPtrHopProcess GetActiveProcess(SharedPtrHopProcessContext ctx) const;

        std::optional<TContextStateInProcess> GetState(SharedPtrHopProcessContext ctx) const;

        void StartProcess(SharedPtrHopProcessContext ctx, const std::string& processName, SharedPtrZone toZone);
        void StopProcess(SharedPtrHopProcessContext ctx);
    private:
        boost::asio::awaitable<void> AsyncStartProcess(SharedPtrHopProcessContext ctx, const std::string& processName, SharedPtrZone toZone);
        boost::asio::awaitable<void> AsyncStopCurrentProcess(SharedPtrHopProcessContext ctx);

        void SetActiveProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process);

        std::list<SharedPtrZone> mZones;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        std::unordered_map<SharedPtrHopProcessContext, SharedPtrZone> mCtxZones;
        std::unordered_map<SharedPtrHopProcessContext, SharedPtrHopProcess> mCtxProcesses;
    };
}
