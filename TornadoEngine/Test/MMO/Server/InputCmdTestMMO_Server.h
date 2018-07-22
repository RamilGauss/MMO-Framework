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
#include "CommonParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "ResolverSelf_IP_v4.h"

class TInputCmdTestMMO_Server
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

  struct TInput
  {
    unsigned char  subnet = 0;
  };

  TInputCmdTestMMO_Server();
  ~TInputCmdTestMMO_Server();

  bool SetArg( int argc, char** argv );
  bool SetArg( std::vector<std::string>& vecArgv );
  void Get( TInput& v_out );

protected:
  TInput mInput;
};
