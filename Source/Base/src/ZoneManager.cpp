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
    TZoneManager::TZoneManager()
    {
        mStrandHolder = nsBase::nsCommon::TStrandHolder::New(mIoContext);
    }
    //------------------------------------------------------------------------------
    void TZoneManager::AddZone(SharedPtrZone pZone)
    {
        mZones.push_back(pZone);
        pZone->SetStrand(mStrandHolder);
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
        auto handlerCount = mIoContext.run_one();
        return (handlerCount > 0);
    }
    //------------------------------------------------------------------------------
    void TZoneManager::MoveContext(IHopProcessContext* pCtx, TZone* from, TZone* to)
    {
        from->RemoveContext(pCtx);

        to->AddContext(pCtx);
    }
    //------------------------------------------------------------------------------
}
