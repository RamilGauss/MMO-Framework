/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/ISubProcess.h"

namespace nsBase::nsZones
{
    class DllExport TSyncSubProcess : public ISubProcess
    {
    public:
        boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) override;
        boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) override;
    };
}
