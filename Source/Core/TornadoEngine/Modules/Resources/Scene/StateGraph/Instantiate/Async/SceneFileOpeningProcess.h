/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/Types.h"
#include "Base/Zones/AsyncSubProcess.h"

namespace nsTornadoEngine
{
    class DllExport TSceneFileOpeningProcess : public nsBase::nsZones::TAsyncSubProcess
    {
    public:
        void Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        uint32_t GetSubProcessTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
    };
}
