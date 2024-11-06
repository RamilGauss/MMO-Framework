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
    void TZoneManager::StartProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process, SharedPtrZone toZone)
    {
        mStrandHolder->StartCoroutine(
            [ctx, process, toZone, this]() {
                return this->AsyncStartProcess(ctx, process, toZone);
            }
        );
    }
    //------------------------------------------------------------------------------
    boost::asio::awaitable<void> TZoneManager::AsyncStartProcess(SharedPtrHopProcessContext ctx, SharedPtrHopProcess process, SharedPtrZone toZone)
    {
        co_await process->Start(ctx);
        auto state = process->GetState(ctx);
        if (state.GetState() == TContextStateInProcess::State::FINISH) {
            auto currentZone = ctx->GetOwnerZone();
            currentZone->RemoveContext(ctx);
            toZone->AddContext(ctx);
        }
    }
    //------------------------------------------------------------------------------
}
