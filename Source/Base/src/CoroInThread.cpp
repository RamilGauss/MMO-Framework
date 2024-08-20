#include <Base/Common/CoroInThread.h>

namespace nsBase::nsCommon
{
    TCoroInThread::TCoroInThread()
    {
        mStrandHolder = TStrandHolder::New(mIoContext);
    }
    //----------------------------------------------------------------------------------
    TStrandHolder::Ptr TCoroInThread::GetStrandHolder() const
    {
        return mStrandHolder;
    }
    //----------------------------------------------------------------------------------
    void TCoroInThread::Start()
    {
        mThread.Start([this]() {
            static int counter = 0;

            auto quantUsedCount = mIoContext.run_one();
            if (quantUsedCount == 0 && counter > 2) {

                counter = 0;

                using namespace std::literals;
                std::this_thread::sleep_for(10ms);
            } else {
                counter++;
            }

            });
    }
    //----------------------------------------------------------------------------------
    void TCoroInThread::Stop()
    {
        mThread.Stop();
    }
    //----------------------------------------------------------------------------------
}
