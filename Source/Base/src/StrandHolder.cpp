#include "Base/Common/StrandHolder.h"

namespace nsBase::nsCommon
{
    TStrandHolder::Ptr TStrandHolder::New(boost::asio::io_context& ioContext)
    {
        Ptr ptr;
        ptr.reset(new TStrandHolder(ioContext));
        return ptr;
    }
    //-----------------------------------------------------------------------------------
    boost::asio::strand<boost::asio::io_context::executor_type>& TStrandHolder::GetStrand()
    {
        return mBoostStrand;
    }
    //-----------------------------------------------------------------------------------
    void TStrandHolder::StartCoroutine(std::function<boost::asio::awaitable<void>()> coro) const
    {
        boost::asio::co_spawn(
            mBoostStrand,
            std::move(coro),
            CoroutineCompletionToken
        );
    }
    //-----------------------------------------------------------------------------------
    boost::asio::awaitable<void> TStrandHolder::Wait() const
    {
        return boost::asio::post(mBoostStrand, boost::asio::use_awaitable);
    }
    //-----------------------------------------------------------------------------------
    void TStrandHolder::CoroutineCompletionToken(std::exception_ptr e)
    {
        if (e)
            std::rethrow_exception(e);
    }
    //-----------------------------------------------------------------------------------
    TStrandHolder::TStrandHolder(boost::asio::io_context& ioContext)
        : mBoostStrand(ioContext.get_executor())
    {
    }
}
