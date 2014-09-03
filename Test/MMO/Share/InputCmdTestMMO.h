/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef InputCmdTestMMOH
#define InputCmdTestMMOH

#include <string>
#include <vector>

#include "CmdParam.h"
#include "CommonParam.h"
 
class TInputCmdTestMMO
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

	struct TInput
	{
		unsigned short begin_port;
    int            count;
		TInput()
		{
      begin_port = CLIENT_PORT;
			count      = 1;
		}
	};

  TInputCmdTestMMO();
  ~TInputCmdTestMMO();

	bool SetArg(int argc, char** argv);
	bool SetArg(std::vector<std::string>& vecArgv);
	void Get(TInput& v_out);

protected:
	TInput mInput;
};

#endif
