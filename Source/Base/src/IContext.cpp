/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IContext.h"
#include "Base/Zones/ContextState.h"

namespace nsBase::nsZones
{
    void IContext::PushActiveProcess(TProcess* pProcess)
    {
        mActiveProcesses.push_back(pProcess);
    }
    //-----------------------------------------------------------------------------
    void IContext::PopActiveProcess()
    {
        mActiveProcesses.pop_back();
    }
    //-----------------------------------------------------------------------------
    void IContext::PushOwnerZone(TZone* pZone)
    {
        mOwnerZones.push_back(pZone);
    }
    //-----------------------------------------------------------------------------
    void IContext::PopOwnerZone()
    {
        mOwnerZones.pop_back();
    }
    //-----------------------------------------------------------------------------
    uint32_t IContext::GetRankCount() const
    {
        return mActiveProcesses.size();
    }
    //-----------------------------------------------------------------------------
    TProcess* IContext::GetActiveProcess(uint32_t rank) const
    {
        if (mActiveProcesses.size() <= rank) {
            return nullptr;
        }

        return mActiveProcesses[rank];
    }
    //-----------------------------------------------------------------------------
    TZone* IContext::GetOwnerZone(uint32_t rank) const
    {
        if (mOwnerZones.size() <= rank) {
            return nullptr;
        }

        return mOwnerZones[rank];
    }
    //-----------------------------------------------------------------------------
    TContextState IContext::GetContextZone(uint32_t rank)
    {
        return TContextState(this, GetOwnerZone(rank), GetActiveProcess(rank));
    }
    //-----------------------------------------------------------------------------
}
