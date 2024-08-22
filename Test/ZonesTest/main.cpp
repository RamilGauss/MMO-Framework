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

#define asString() asStringPure(__FILE__, __LINE__)


void asStringPure(const char* fileName, int line)
{
    printf("%s %d\n", fileName, line);
}


int main(int argc, char** argv)
{
    asString();
    asString();


    boost::asio::io_context ioContext;
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    nsBase::nsCommon::TCoroInThread coroInThread;

    TAsyncHopProcess hopProcess(&coroInThread, strandHolder);
    coroInThread.Start();

    strandHolder->StartCoroutine([&hopProcess]() {return hopProcess.Start(); });

    bool isStopping = false;

    while (true) {
        auto quantUsedCount = ioContext.run_one();

        using namespace std::literals;
        std::this_thread::sleep_for(10ms);

        if (hopProcess.GetState().IsWork() && 
            hopProcess.GetState().GetProgress() > 70) {

            if (!isStopping) {
                isStopping = true;
                strandHolder->StartCoroutine([&hopProcess, &isStopping]() {
                    return hopProcess.Stop([&isStopping]() {
                        isStopping = false;
                }); });
            }
        }
    }

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
