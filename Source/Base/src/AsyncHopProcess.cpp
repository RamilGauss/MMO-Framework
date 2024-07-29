/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/AsyncHopProcess.h"

namespace nsBase::nsZones
{
    boost::asio::awaitable<void> TAsyncHopProcess::AsyncWork(IHopProcessContext* pCtx)
    {
        boost::asio::post(
            mThreadPool,
            [&]() {

                while (IsActive(pCtx)) {
                    Work(pCtx);
                }

                mStrandHolder->Post([&]() {
                    mThreadAwaitable->Resume();
                    });
            }
        );

        co_await mThreadAwaitable->Wait();

        co_return;
    }
}
