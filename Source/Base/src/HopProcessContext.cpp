/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/HopProcessContext.h"

namespace nsBase::nsZones
{
    void THopProcessContext::SetActiveProcess(SharedPtrHopProcess process)
    {
        mActiveProcess = process;
    }
    //-----------------------------------------------------------------------------
    void THopProcessContext::SetOwnerZone(SharedPtrZone zone)
    {
        mOwnerZone = zone;
    }
    //-----------------------------------------------------------------------------
    SharedPtrHopProcess THopProcessContext::GetActiveProcess() const
    {
        return mActiveProcess;
    }
    //-----------------------------------------------------------------------------
    SharedPtrZone THopProcessContext::GetOwnerZone() const
    {
        return mOwnerZone;
    }
    //-----------------------------------------------------------------------------
}
