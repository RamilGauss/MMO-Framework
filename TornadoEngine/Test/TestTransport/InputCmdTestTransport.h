/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef InputCmdTestTransportH
#define InputCmdTestTransportH

#include <string>
#include <vector>

#include "CmdParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "NetSystem.h"

class TInputCmdTestTransport
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

	struct TInput
	{
		unsigned short port_src;
    unsigned short port_dst;
    int            timer_send; // ms
    TInput()
    {
      timer_send = 1000000000;
    }
	};

  TInputCmdTestTransport();
  ~TInputCmdTestTransport();

	bool SetArg(int argc, char** argv);
	bool SetArg(std::vector<std::string>& vecArgv);
	void Get(TInput& v_out);

protected:
	TInput mInput;
};

#endif
