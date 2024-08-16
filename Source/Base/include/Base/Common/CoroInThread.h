#pragma once

#include <boost/asio/io_context.hpp>

#include <Base/Common/FramedThread.h>
#include <Base/Common/StrandHolder.h>
#include <Base/Common/TypeDef.h>

namespace nsBase::nsCommon
{
    class DllExport TCoroInThread final
    {
    public:
        TCoroInThread();

        TStrandHolder::Ptr GetStrandHolder() const;
        void Start();
        void Stop();

    private:
        TFramedThread mThread;

        boost::asio::io_context mIoContext;
        TStrandHolder::Ptr mStrandHolder;
    };
}
