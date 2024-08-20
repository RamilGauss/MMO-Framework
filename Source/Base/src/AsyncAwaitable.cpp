#include "Base/Common/AsyncAwaitable.h"

namespace nsBase::nsCommon
{
    TAsyncAwaitable::Ptr TAsyncAwaitable::New()
    {
        Ptr ptr;
        ptr.reset(new TAsyncAwaitable);
        return ptr;
    }
    //---------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncAwaitable::Wait()
    {
        return boost::asio::async_initiate<
            decltype(boost::asio::use_awaitable),
            void(boost::system::error_code)>(
                [self = Ptr(this->shared_from_this())](auto&& handler) mutable {
                    self->mCallbacks.push_back(std::make_shared<ElementType>(std::forward<decltype(handler)>(handler)));
                },
                boost::asio::use_awaitable
            );
    }
    //---------------------------------------------------------------------------------------
    void TAsyncAwaitable::Resume()
    {
        if (mCallbacks.size()) {
            auto func = std::move(mCallbacks.front());
            mCallbacks.pop_front();
            (std::move(func))->operator()(boost::system::error_code());
        }
    }
}
