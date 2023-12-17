/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Zone.h"

#include "ZoneManager.h"
#include "ZoneProcess.h"
#include "IContext.h"

namespace nsZones
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
