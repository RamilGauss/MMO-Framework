#pragma once

#include <boost/asio.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

#include <concepts>

namespace nsBase::nsCommon
{
    class TStrandHolder : public std::enable_shared_from_this<TStrandHolder>
    {
    public:
        using Ptr = std::shared_ptr<TStrandHolder>;

        static Ptr New(boost::asio::io_context& ioContext);

        boost::asio::strand<boost::asio::io_context::executor_type>& GetStrand();

        void StartCoroutine(std::function<boost::asio::awaitable<void>()> coro) const;

        template <std::invocable Task>
        void Post(Task&& task) const
        {
            boost::asio::post(
                mBoostStrand,
                std::forward<Task>(task)
            );
        }

        boost::asio::awaitable<void> Wait() const;

        static void CoroutineCompletionToken(std::exception_ptr e);

    private:
        explicit TStrandHolder(boost::asio::io_context& ioContext);

        boost::asio::strand<boost::asio::io_context::executor_type> mBoostStrand;
    };

}
