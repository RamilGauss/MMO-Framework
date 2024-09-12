/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

#include "AsyncHopProcess.h"

int main(int argc, char** argv)
{
    boost::asio::io_context ioContext;
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    auto  coroInThread = nsBase::nsCommon::TCoroInThread::New();

    TAsyncHopProcess hopProcess(coroInThread, strandHolder);
    coroInThread->Start();

    strandHolder->StartCoroutine([&hopProcess]() {return hopProcess.Start(); });

    bool isStopping = false;

    while (true) {
        auto quantUsedCount = ioContext.run_one();

        using namespace std::literals;
        std::this_thread::sleep_for(10ms);

        auto state = hopProcess.GetState();

        if (state.IsWork() && 
            state.GetProgress() > 70) {

            if (isStopping == false) {
                isStopping = true;
                strandHolder->StartCoroutine([&hopProcess, &isStopping]() {
                    return hopProcess.Stop(); });
            }
        }
        if (state.IsFinishedOrStopped()) {
            isStopping = false;
        }
    }

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
