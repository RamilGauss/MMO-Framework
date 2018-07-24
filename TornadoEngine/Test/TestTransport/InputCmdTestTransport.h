/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <vector>

#include "CmdParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "ResolverSelf_IP_v4.h"

class TInputCmdTestTransport
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

  struct TInput
  {
    unsigned char sub_net = 0;
    unsigned short self_port = 10000;
    unsigned short server_port = 20000;
    std::string ping_data;
    int ping_time = 100;
    unsigned int server_ip;
  };

  TInputCmdTestTransport();
  ~TInputCmdTestTransport();

  bool SetArg(int argc, char** argv);
  bool SetArg(std::vector<std::string>& vecArgv);
  void Get(TInput& v_out);

protected:
  TInput mInput;
};
