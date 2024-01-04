/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IContext.h"
#include "Base/Zones/ContextZone.h"

namespace nsBase::nsZones
{
    void IContext::SetActiveProcess(TProcess* pProcess)
    {
        mActiveProcess = pProcess;
    }
    //-----------------------------------------------------------------------------
    void IContext::SetOwnerZone(TZone* pZone)
    {
        mOwnerZone = pZone;
    }
    //-----------------------------------------------------------------------------
    TProcess* IContext::GetActiveProcess() const
    {
        return mActiveProcess;
    }
    //-----------------------------------------------------------------------------
    TZone* IContext::GetOwnerZone() const
    {
        return mOwnerZone;
    }
    //-----------------------------------------------------------------------------
    TContextZone IContext::GetContextZone()
    {
        return TContextZone(this, mOwnerZone);
    }
    //-----------------------------------------------------------------------------
}
