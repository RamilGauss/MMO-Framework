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
        mThread.Start([this]() { mIoContext.run_one(); });
    }
    //----------------------------------------------------------------------------------
    void TCoroInThread::Stop()
    {
        mThread.Stop();
    }
}
