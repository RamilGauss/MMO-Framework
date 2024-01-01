/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ZoneProcess.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/IContext.h"

namespace nsBase::nsZones
{
    TZoneProcess::TZoneProcess()
    {
        mZoneMng.reset(new TZoneManager());
    }
    //------------------------------------------------------------------------------
    TZoneProcess::~TZoneProcess()
    {

    }
    //------------------------------------------------------------------------------
    void TZoneProcess::AddZone(TZone* pZone)
    {

    }
    //------------------------------------------------------------------------------
    void TZoneProcess::Begin(IContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void TZoneProcess::SetMaxActiveCount(int value)
    {
        mMaxActiveCount = value;
    }
    //------------------------------------------------------------------------------
    int TZoneProcess::GetMaxActiveCount() const
    {
        return mMaxActiveCount;
    }
    //------------------------------------------------------------------------------
}
