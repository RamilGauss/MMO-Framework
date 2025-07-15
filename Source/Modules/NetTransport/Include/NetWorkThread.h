/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <boost/asio/io_service.hpp>
#include "Base/Common/FramedThread.h"

class TNetWorkThread
{
    nsBase::nsCommon::TFramedThread mThread;

    boost::asio::io_context mIO_Context;

public:
    TNetWorkThread();
    virtual ~TNetWorkThread();

    boost::asio::io_context* GetIO_Context()
    {
        return &mIO_Context;
    }

    void Start();
    void Stop();
    bool IsActive() const;
protected:
    void Work();
};
