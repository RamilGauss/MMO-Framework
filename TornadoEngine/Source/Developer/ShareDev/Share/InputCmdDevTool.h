/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef InputCmdDevToolH
#define InputCmdDevToolH

#include <string>
#include <vector>

#include "CmdParam.h"
 
class DllExport TInputCmdDevTool
{
 TCmdParam mCmdParam;

 typedef std::vector<std::string> TVectorStr;
 TVectorStr mVecDefKey;

public:
	struct TInput
	{
    unsigned int   ip_dst;
    unsigned short port_dst;
    unsigned short port_self;
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