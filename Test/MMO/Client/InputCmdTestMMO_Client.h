/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <vector>

#include "CommonParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "Base/Common/ResolverSelf_IP_v4.h"
#include "InputByCmd.h"

class TInputCmdTestMMO_Client : public TInputByCmd
{
public:
  struct TInput
  {
    unsigned short begin_port = CLIENT_PORT;
    int            count = 1;
    int            begin_id = 0;
    std::string    server_ip;
    int            ping_time = 0x1FFFFFFF;
    unsigned char  subnet = 0;
    TInput()
    {
      TResolverSelf_IP_v4 resolver;
      resolver.Get( server_ip, 0 );
    }
  };

  TInput mInput;
  void Init() override;
};

