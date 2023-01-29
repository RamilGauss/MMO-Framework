/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <boost/asio/io_service.hpp>
#include "ThreadBoost.h"

class TNetWorkThread : public TThreadBoost
{
    boost::asio::io_context mIO_Context;

public:
    TNetWorkThread();
    virtual ~TNetWorkThread();

    boost::asio::io_context* GetIO_Context()
    {
        return &mIO_Context;
    }

    void Stop() override;
protected:
    void Work() override;
};
