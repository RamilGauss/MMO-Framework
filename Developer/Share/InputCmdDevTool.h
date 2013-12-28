/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef INPUT_CMD_DEV_TOOL_H
#define INPUT_CMD_DEV_TOOL_H

#include <string>
#include <vector>

#include "CmdParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
 
class TInputCmdDevTool
{
 TCmdParam mCmdParam;

 typedef std::vector<std::string> TVectorStr;
 TVectorStr mVecDefKey;

public:
	struct TInput
	{
    unsigned int   ip;
    unsigned short port;
	};

  TInputCmdDevTool();
  ~TInputCmdDevTool();

  void SetDefParam(TInput& defInput);

	bool SetArg(std::vector<std::string>& vecArgv);
	void Get(TInput& v_out);

protected:
	TInput mInput;
};

#endif