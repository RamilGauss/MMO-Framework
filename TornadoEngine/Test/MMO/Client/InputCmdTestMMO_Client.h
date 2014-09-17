/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef InputCmdTestMMO_ClientH
#define InputCmdTestMMO_ClientH

#include <string>
#include <vector>

#include "CmdParam.h"
#include "CommonParam.h"
 
class TInputCmdTestMMO_Client
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

	struct TInput
	{
		unsigned short begin_port;
    int            count;
    int            begin_id;
		TInput()
		{
      begin_port = CLIENT_PORT;
			count      = 1;
      begin_id   = 0;
		}
	};

  TInputCmdTestMMO_Client();
  ~TInputCmdTestMMO_Client();

	bool SetArg(int argc, char** argv);
	bool SetArg(std::vector<std::string>& vecArgv);
	void Get(TInput& v_out);

protected:
	TInput mInput;
};

#endif
