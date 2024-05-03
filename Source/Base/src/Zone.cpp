/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/Zone.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/HopProcess.h"
#include "Base/Zones/IHopProcessContext.h"

namespace nsBase::nsZones
{
    TZone::TZone(const std::string& name) : mName(name)
    {

    }
    //------------------------------------------------------------------------------
    const std::string& TZone::GetName() const
    {
        return mName;
    }
    //------------------------------------------------------------------------------
    void TZone::AddProcess(SharedPtrHopProcess pProcess)
    {
        mProcesses.push_back(pProcess);

        pProcess->mStopEvent.Register(this, &TZone::OnStopProcess);
        pProcess->mFinishEvent.Register(this, &TZone::OnFinishProcess);

        pProcess->SetRank(GetRank());
    }
    //------------------------------------------------------------------------------
    THopProcess* TZone::GetProcess(const std::string& processName)
    {
        auto fit = std::find_if(mProcesses.begin(), mProcesses.end(), 
            [&processName](SharedPtrHopProcess p) {return p->GetName() == processName; });

        if (fit == std::end(mProcesses))
            return nullptr;

        return fit->get();
    }
    //------------------------------------------------------------------------------
    void TZone::AddContext(IHopProcessContext* pCtx)
    {
        mContexts.push_back(pCtx);
        pCtx->PushOwnerZone(this);
    }
    //------------------------------------------------------------------------------
    void TZone::RemoveContext(IHopProcessContext* pCtx)
    {
        mContexts.remove(pCtx);
        pCtx->PopOwnerZone();
    }
    //------------------------------------------------------------------------------
    bool TZone::Work()
    {
        bool wasSpent = false;
        for (auto process : mProcesses) {
            wasSpent |= process->Work();
        }

        return wasSpent;
    }
    //------------------------------------------------------------------------------
    void TZone::OnStopProcess(THopProcess* pProcess, IHopProcessContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void TZone::OnFinishProcess(THopProcess* pProcess, TZone* pZone, IHopProcessContext* pCtx)
    {
        mZoneMng->MoveContext(pCtx, this, pZone);
    }
    //------------------------------------------------------------------------------
}
