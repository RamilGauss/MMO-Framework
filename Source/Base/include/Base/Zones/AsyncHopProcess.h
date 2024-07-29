/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/HopProcess.h"

namespace nsBase::nsZones
{
    class DllExport TAsyncHopProcess : public THopProcess
    {
    protected:
        boost::asio::awaitable<void> AsyncWork(IHopProcessContext* ctx) override;
    };
}
