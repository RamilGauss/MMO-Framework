/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/SyncHopProcess.h"

namespace nsBase::nsZones
{
    boost::asio::awaitable<void> TSyncHopProcess::AsyncWork(IHopProcessContext* ctx)
    {
        while (IsActive(ctx)) {

            Work(ctx);
            co_await mStrandHolder->Wait();
        }

        co_return;
    }
}
