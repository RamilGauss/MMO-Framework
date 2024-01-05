/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/Zone.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/ZoneProcess.h"
#include "Base/Zones/IContext.h"

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
    void TZone::AddProcess(TProcess* pProcess)
    {
        mProcesses.push_back(pProcess);

        pProcess->mStopEvent.Register(this, &TZone::OnStopProcess);
        pProcess->mFinishEvent.Register(this, &TZone::OnFinishProcess);
    }
    //------------------------------------------------------------------------------
    TProcess* TZone::GetProcess(const std::string& processName)
    {
        auto fit = std::find_if(mProcesses.begin(), mProcesses.end(), 
            [&processName](TProcess* p) {return p->GetName() == processName; });

        if (fit == std::end(mProcesses))
            return nullptr;

        return *fit;
    }
    //------------------------------------------------------------------------------
    void TZone::AddContext(IContext* pCtx)
    {
        mContexts.push_back(pCtx);
        pCtx->SetOwnerZone(GetRank(), this);
    }
    //------------------------------------------------------------------------------
    void TZone::RemoveContext(IContext* pCtx)
    {
        mContexts.remove(pCtx);
    }
    //------------------------------------------------------------------------------
    void TZone::Work()
    {
        for (auto process : mProcesses) {
            process->Work();
        }
    }
    //------------------------------------------------------------------------------
    void TZone::OnStopProcess(TProcess* pProcess, IContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void TZone::OnFinishProcess(TProcess* pProcess, TZone* pZone, IContext* pCtx)
    {
        mZoneMng->MoveContext(pCtx, this, pZone);
    }
    //------------------------------------------------------------------------------
}
