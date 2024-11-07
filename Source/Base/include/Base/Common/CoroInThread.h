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
        using Ptr = std::shared_ptr<TCoroInThread>;

        static Ptr New();

        TStrandHolder::Ptr GetStrandHolder() const;
        void Start();
        void Stop();

        ~TCoroInThread();
    private:
        TCoroInThread();
        TFramedThread mThread;

        boost::asio::io_context mIoContext;
        TStrandHolder::Ptr mStrandHolder;
    };
}
