/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ResolverSelf_IP_v4.h"
#include "InputByCmd.h"
#include "CommonParam.h"

class TInputCmdTestMMO_ClusterMonitor : public TInputByCmd
{
public:
  struct TInput
  {
    std::string login = CLIENT_MONITOR_LOGIN;
    std::string password = CLIENT_MONITOR_PASSWORD;
    unsigned short server_port = SERVER_MONITOR_PORT;
    unsigned short self_port   = CLIENT_MONITOR_PORT;
    unsigned char  subnet = 0;
    std::string server_ip;
    TInput()
    {
      TResolverSelf_IP_v4 resolver;
      resolver.Get( server_ip, 0 );
    }
  };
  TInput mInput;
public:
  void Init() override;
};

