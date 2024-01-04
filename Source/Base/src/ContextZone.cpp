/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextZone.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/ZoneProcess.h"

namespace nsBase::nsZones
{
    TContextZone::TContextZone(IContext* pCtx, TZone* pZone)
    {
        mCtx = pCtx;
        mZone = pZone;
    }
    //--------------------------------------------------------------------------------
    bool TContextZone::StartProcess(const std::string& processName)
    {
        auto pProcess = mZone->GetProcess(processName);
        if (pProcess)
            pProcess->Start(mCtx);// TODO: check
        return (pProcess != nullptr);
    }
    //--------------------------------------------------------------------------------
}
