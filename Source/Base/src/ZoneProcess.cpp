/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ZoneProcess.h"

#include "ZoneManager.h"
#include "Zone.h"
#include "IContext.h"

namespace nsZones
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
