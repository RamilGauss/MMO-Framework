/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/IHopProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TCancelInstantiateProcess : public nsBase::nsZones::IHopProcess
    {
    public:

        //void Work(std::list<nsBase::nsZones::IContext*>& aciveCtx) override;
    };
}
