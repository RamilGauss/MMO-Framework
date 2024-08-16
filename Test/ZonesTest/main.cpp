/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <Base/Common/CoroInThread.h>

boost::asio::awaitable<void> UpdateState()
{

    co_return;
}

boost::asio::awaitable<void> Stop(nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
{
    nsBase::nsCommon::TCoroInThread coroInThread;
    coroInThread.Start();

    strandHolder->Post([&coroInThread]() {
        coroInThread.GetStrandHolder()->StartCoroutine([]() {return CoroInThread(); });
        });

    co_await awaitable->Wait();
}

boost::asio::awaitable<void> Start(nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
{
    nsBase::nsCommon::TCoroInThread coroInThread;
    coroInThread.Start();

    strandHolder->Post([&coroInThread]() {
             coroInThread.GetStrandHolder()->StartCoroutine([]() {return CoroInThread(); });
        });

    co_await awaitable->Wait();
}


int main(int argc, char** argv)
{
    boost::asio::io_context ioContext;
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder;

    ioContext.run();

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
