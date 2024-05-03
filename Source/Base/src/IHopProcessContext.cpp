/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IHopProcessContext.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/HopProcess.h"

namespace nsBase::nsZones
{
    void IHopProcessContext::PushActiveProcess(THopProcess* pProcess)
    {
        mActiveProcesses.push_back(pProcess);
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::PopActiveProcess()
    {
        mActiveProcesses.pop_back();
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::PushOwnerZone(TZone* pZone)
    {
        mOwnerZones.push_back(pZone);
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::PopOwnerZone()
    {
        mOwnerZones.pop_back();
    }
    //-----------------------------------------------------------------------------
    uint32_t IHopProcessContext::GetRankCount() const
    {
        return mActiveProcesses.size();
    }
    //-----------------------------------------------------------------------------
    THopProcess* IHopProcessContext::GetActiveProcess(uint32_t rank) const
    {
        if (mActiveProcesses.size() <= rank) {
            return nullptr;
        }

        return mActiveProcesses[rank];
    }
    //-----------------------------------------------------------------------------
    TZone* IHopProcessContext::GetOwnerZone(uint32_t rank) const
    {
        if (mOwnerZones.size() <= rank) {
            return nullptr;
        }

        return mOwnerZones[rank];
    }
    //-----------------------------------------------------------------------------
    void IHopProcessContext::StartProcess(const std::string& processName, uint32_t rank)
    {
        auto pProcess = GetOwnerZone(rank)->GetProcess(processName);
        if (pProcess)
            pProcess->Start(this);
        //return (pProcess != nullptr);
    }
    //-----------------------------------------------------------------------------
}
