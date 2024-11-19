/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <boost/asio/awaitable.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/strand.hpp>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TStrandHolder : public std::enable_shared_from_this<TStrandHolder>
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
