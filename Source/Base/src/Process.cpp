/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Process.h"

#include "ZoneManager.h"
#include "Zone.h"
#include "IContext.h"

namespace nsZones
{
    TProcess::TProcess()
    {
        mZoneMng.reset(new TZoneManager());
    }
    //------------------------------------------------------------------------------
    void TProcess::AddZone(TZone* pZone)
    {

    }
    //------------------------------------------------------------------------------
    void TProcess::Begin(IContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void TProcess::Work()
    {

    }
    //------------------------------------------------------------------------------
}
