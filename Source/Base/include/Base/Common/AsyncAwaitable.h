#pragma once

#include <boost/asio.hpp>

#include <list>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TAsyncAwaitable : public std::enable_shared_from_this<TAsyncAwaitable>
    {
    public:
        using Ptr = std::shared_ptr<TAsyncAwaitable>;

        static Ptr New();

        boost::asio::awaitable<void> Wait();
        void Resume();

    private:
        TAsyncAwaitable() = default;

        TAsyncAwaitable& operator = (const TAsyncAwaitable& other) = default;

        using ElementType = boost::asio::detail::awaitable_handler<boost::asio::any_io_executor, boost::system::error_code>;
        using ElementTypePtr = std::shared_ptr<ElementType>;

        std::list<ElementTypePtr> mCallbacks;
    };
}
