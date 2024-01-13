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
    void TZoneManager::AddZone(SharedPtrZone pZone)
    {
        mZones.push_back(pZone);
        pZone->SetRank(GetRank());
    }
    //------------------------------------------------------------------------------
    TZone* TZoneManager::GetZone(const std::string& zoneName)
    {
        auto fit = std::find_if(mZones.begin(), mZones.end(),
            [&zoneName](SharedPtrZone p) {return p->GetName() == zoneName; });

        if (fit == std::end(mZones))
            return nullptr;

        return fit->get();

    }
    //------------------------------------------------------------------------------
    bool TZoneManager::Work()
    {
        bool wasSpent = false;
        for (auto& pZone : mZones) {
            wasSpent |= pZone->Work();
        }

        return wasSpent;
    }
    //------------------------------------------------------------------------------
    void TZoneManager::MoveContext(IContext* pCtx, TZone* from, TZone* to)
    {
        from->RemoveContext(pCtx);

        to->AddContext(pCtx);
    }
    //------------------------------------------------------------------------------
}
