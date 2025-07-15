#include <Base/Common/CoroInThread.h>

namespace nsBase::nsCommon
{
    TCoroInThread::Ptr TCoroInThread::New()
    {
        Ptr ptr;
        ptr.reset(new TCoroInThread());
        return ptr;
    }
    //----------------------------------------------------------------------------------
    TCoroInThread::TCoroInThread()
    {
        mStrandHolder = TStrandHolder::New(mIoContext);
    }
    //----------------------------------------------------------------------------------
    TCoroInThread::~TCoroInThread()
    {

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
            if (mIoContext.stopped())
                mIoContext.restart();

            auto callHandlerCount = mIoContext.run_one();

            if (callHandlerCount == 0) {
                using namespace std::literals;
                std::this_thread::sleep_for(10ms);
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
