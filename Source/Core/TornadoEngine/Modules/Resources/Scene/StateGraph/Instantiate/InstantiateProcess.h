/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/ZoneProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TInstantiateProcess : public nsBase::nsZones::TProcess
    {
    public:

        void Work(std::list<nsBase::nsZones::IContext*>& aciveCtx) override;
    };
}
