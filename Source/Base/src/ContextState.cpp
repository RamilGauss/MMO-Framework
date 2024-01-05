/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextState.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/ZoneProcess.h"
#include "Base/Zones/IContext.h"

namespace nsBase::nsZones
{
    TContextState::TContextState(IContext* pCtx, TZone* pZone, TProcess* pProcess)
    {
        mCtx = pCtx;
        mZone = pZone;
        mActiveProcess = pProcess;
    }
    //--------------------------------------------------------------------------------
    bool TContextState::StartProcess(const std::string& processName)
    {
        auto pProcess = mZone->GetProcess(processName);
        if (pProcess)
            pProcess->Start(mCtx);
        return (pProcess != nullptr);
    }
    //--------------------------------------------------------------------------------
    void TContextState::StopProcess()
    {
        if (mActiveProcess)
            mActiveProcess->Stop(mCtx);
    }
    //--------------------------------------------------------------------------------
}
