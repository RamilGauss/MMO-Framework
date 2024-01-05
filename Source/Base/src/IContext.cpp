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
    void IContext::SetActiveProcess(uint32_t rank, TProcess* pProcess)
    {
        if (mActiveProcesses.size() <= rank) {
            mActiveProcesses.resize(rank + 1);
        }

        mActiveProcesses[rank] = pProcess;
    }
    //-----------------------------------------------------------------------------
    void IContext::SetOwnerZone(uint32_t rank, TZone* pZone)
    {
        if (mOwnerZones.size() <= rank) {
            mOwnerZones.resize(rank + 1);
        }

        mOwnerZones[rank] = pZone;
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
