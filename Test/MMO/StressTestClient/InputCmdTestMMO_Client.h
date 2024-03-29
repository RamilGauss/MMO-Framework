/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CommonParam.h"

#include <boost/asio/ip/impl/address_v4.ipp>
#include "Base/Common/ResolverSelf_IP_v4.h"
#include "Base/Common/InputByCmd.h"

class TInputCmdTestMMO_Client : public TInputByCmd
{
public:
    struct TInput
    {
        unsigned short begin_port;
        int            count;
        int            begin_id;
        std::string    ip_server;
        TInput()
        {
            begin_port = CLIENT_PORT;
            count = 1;
            begin_id = 0;

            TResolverSelf_IP_v4 resolver;
            resolver.Get(ip_server, 0);
        }
    };

    TInputCmdTestMMO_Client();
    ~TInputCmdTestMMO_Client();

    void Init() override;

    bool SetArg(int argc, char** argv);
    bool SetArg(std::vector<std::string>& vecArgv);
    void Get(TInput& v_out);

protected:
    TInput mInput;
};
