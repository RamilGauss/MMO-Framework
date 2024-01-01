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
    void TZone::AddProcess(TZoneProcess* pProcess)
    {
        mProcesses.push_back(pProcess);
    }
    //------------------------------------------------------------------------------
    void TZone::AddContext(IContext* pCtx)
    {
        mContexts.push_back(pCtx);
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
}
