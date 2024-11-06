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
    TZone::TZone(const std::string& name)
    {
        mName = name;
    }
    //------------------------------------------------------------------------------
    void TZone::Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
        mStrandHolder = std::move(strandHolder);
        mCoroInThread = std::move(coroInThread);
    }
    //------------------------------------------------------------------------------
    std::string TZone::GetName() const
    {
        return mName;
    }
    //------------------------------------------------------------------------------
    void TZone::AddProcess(SharedPtrHopProcess pProcess)
    {
        mProcesses.push_back(pProcess);
        pProcess->Init(mStrandHolder, mCoroInThread);
    }
    //------------------------------------------------------------------------------
    SharedPtrHopProcess TZone::GetProcess(const std::string& processName)
    {
        auto fit = std::find_if(mProcesses.begin(), mProcesses.end(), 
            [&processName](SharedPtrHopProcess p) {return p->GetName() == processName; });

        if (fit == std::end(mProcesses))
            return nullptr;

        return *fit;
    }
    //------------------------------------------------------------------------------
    void TZone::AddContext(SharedPtrHopProcessContext pCtx)
    {
        mContexts.push_back(pCtx);
        pCtx->SetOwnerZone(this);
        pCtx->SetStrand(mStrandHolder);
    }
    //------------------------------------------------------------------------------
    void TZone::RemoveContext(SharedPtrHopProcessContext pCtx)
    {
        mContexts.remove(pCtx);
        pCtx->SetOwnerZone(nullptr);
    }
    //------------------------------------------------------------------------------
}
