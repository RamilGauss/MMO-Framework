/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/Types.h"
#include "Base/Zones/SyncSubProcess.h"

namespace nsTornadoEngine
{
    class DllExport TPrefabInstantiatingProcess : public nsBase::nsZones::TSyncSubProcess
    {
    public:
        void Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        void Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        uint32_t GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
    private:
        const int PART_SIZE = 3;
    };
}
