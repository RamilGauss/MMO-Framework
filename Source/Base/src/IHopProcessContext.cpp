/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IHopProcessContext.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/IHopProcess.h"

namespace nsBase::nsZones
{
    IHopProcess* IHopProcessContext::GetActiveProcess() const
    {
        return mActiveProcess;
    }
    //-----------------------------------------------------------------------------
    TZone* IHopProcessContext::GetOwnerZone() const
    {
        return mOwnerZone;
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::StartProcess(const std::string& processName)
    {
        auto pProcess = GetOwnerZone()->GetProcess(processName);
        if (pProcess)
            mStrandHolder->StartCoroutine(
                [pProcess, this]() {
                    return pProcess->Start(this);
                }
            );
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::SetStrand(nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
    {
        mStrandHolder = strandHolder;
    }
    //-----------------------------------------------------------------------------
}
