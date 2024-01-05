/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ZoneManager.h"

#include "Base/Zones/Zone.h"

namespace nsBase::nsZones
{
    void TZoneManager::AddZone(TZone* pZone)
    {
        mZones.push_back(pZone);
        pZone->SetRank(GetRank());
    }
    //------------------------------------------------------------------------------
    void TZoneManager::Work()
    {
        for (auto& pZone : mZones) {
            pZone->Work();
        }
    }
    //------------------------------------------------------------------------------
    void TZoneManager::MoveContext(IContext* pCtx, TZone* from, TZone* to)
    {
        from->RemoveContext(pCtx);

        to->AddContext(pCtx);
    }
    //------------------------------------------------------------------------------
}
