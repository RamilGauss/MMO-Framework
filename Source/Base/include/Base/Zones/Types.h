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
    class THopProcess;
    class TZone;
    class TZoneManager;

    using SharedPtrZone = std::shared_ptr<TZone>;
    using SharedPtrZoneManager = std::shared_ptr<TZoneManager>;
    using SharedPtrHopProcess = std::shared_ptr<THopProcess>;
}
