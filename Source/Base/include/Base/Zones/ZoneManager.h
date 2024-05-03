/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "Base/Common/TypeDef.h"

#include "Base/Zones/Rank.h"
#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class TZone;
    struct IHopProcessContext;
    class DllExport TZoneManager : public TRank
    {
        std::list<SharedPtrZone> mZones;

    public:
        void AddZone(SharedPtrZone pZone);

        TZone* GetZone(const std::string& zoneName);

        bool Work();

        void MoveContext(IHopProcessContext* pCtx, TZone* from, TZone* to);
    };
}
