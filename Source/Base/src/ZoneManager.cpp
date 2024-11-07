/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ZoneManager.h"

#include "Base/Zones/Zone.h"
#include "Base/Zones/IHopProcess.h"
#include "Base/Zones/HopProcessContext.h"

namespace nsBase::nsZones
{
    void TZoneManager::Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder, nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
        mStrandHolder = std::move(strandHolder);
        mCoroInThread = std::move(coroInThread);

        mCoroInThread->Start();
    }
    //------------------------------------------------------------------------------
    void TZoneManager::AddZone(SharedPtrZone pZone)
    {
        mZones.push_back(pZone);
        pZone->Init(mStrandHolder, mCoroInThread);
    }
    //------------------------------------------------------------------------------
    SharedPtrZone TZoneManager::GetZone(const std::string& zoneName)
    {
        auto fit = std::find_if(mZones.begin(), mZones.end(),
            [&zoneName](SharedPtrZone p) {return p->GetName() == zoneName; });

        if (fit == std::end(mZones))
            return nullptr;

        return *fit;

    }
    //------------------------------------------------------------------------------
    void TZoneManager::StartProcess(SharedPtrHopProcessContext ctx, const std::string& processName, SharedPtrZone toZone)
    {
        mStrandHolder->StartCoroutine(
            [ctx, processName, toZone, this]() {
                return this->AsyncStartProcess(ctx, processName, toZone);
            }
        );
    }
    //------------------------------------------------------------------------------
    void TZoneManager::StopProcess(SharedPtrHopProcessContext ctx)
    {
        mStrandHolder->StartCoroutine(
            [ctx, this]() {
                return this->AsyncStopCurrentProcess(ctx);
            }
        );
    }
    //------------------------------------------------------------------------------
    boost::asio::awaitable<void> TZoneManager::AsyncStopCurrentProcess(SharedPtrHopProcessContext ctx)
    {
        auto activeProcess = GetActiveProcess(ctx);
        if (activeProcess) {
            co_await activeProcess->Stop(ctx);
        }
    }
    //------------------------------------------------------------------------------
    boost::asio::awaitable<void> TZoneManager::AsyncStartProcess(SharedPtrHopProcessContext ctx, const std::string& processName, SharedPtrZone toZone)
    {
        auto process = GetZone(ctx)->GetProcess(processName);
        if (process == nullptr) {
            co_return;
        }

        co_await AsyncStopCurrentProcess(ctx);

        SetActiveProcess(ctx, process);
        auto result = co_await process->Start(ctx);
        if (result) {
            LinkContext(ctx, toZone);
        }
        SetActiveProcess(ctx, nullptr);
    }
    //------------------------------------------------------------------------------
    void TZoneManager::LinkContext(SharedPtrHopProcessContext ctx, SharedPtrZone pZone)
    {
        mCtxZones.insert_or_assign(ctx, pZone);
    }
    //------------------------------------------------------------------------------
    SharedPtrZone TZoneManager::GetZone(SharedPtrHopProcessContext ctx) const
    {
        auto fit = mCtxZones.find(ctx);
        if (fit == mCtxZones.end())
            return nullptr;
        return fit->second;
    }
    //------------------------------------------------------------------------------
    SharedPtrHopProcess TZoneManager::GetActiveProcess(SharedPtrHopProcessContext ctx) const
    {
        auto fit = mCtxProcesses.find(ctx);
        if (fit == mCtxProcesses.end())
            return nullptr;
        return fit->second;
    }
    //------------------------------------------------------------------------------
    void TZoneManager::SetActiveProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process)
    {
        mCtxProcesses.insert_or_assign(ctx, process);
    }
    //------------------------------------------------------------------------------
    std::optional<TContextStateInProcess> TZoneManager::GetState(SharedPtrHopProcessContext ctx) const
    {
        auto process = GetActiveProcess(ctx);
        if (process)
            return process->GetState(ctx);
        return std::nullopt;
    }
    //------------------------------------------------------------------------------
}
