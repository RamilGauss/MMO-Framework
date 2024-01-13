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
    class TProcess;
    class TZone;

    using SharedPtrZone = std::shared_ptr<TZone>;
    using SharedPtrProcess = std::shared_ptr<TProcess>;
}
