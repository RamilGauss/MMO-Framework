/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsZones
{
    class IHopProcess;
    class TZone;
    class TZoneManager;
    struct THopProcessContext;
    struct TContextState;

    using SharedPtrZone = std::shared_ptr<TZone>;
    using SharedPtrZoneManager = std::shared_ptr<TZoneManager>;
    using SharedPtrHopProcess = std::shared_ptr<IHopProcess>;
    using SharedPtrHopProcessContext = std::shared_ptr<THopProcessContext>;
    using SharedPtrContextState = std::shared_ptr<TContextState>;
}
