/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef InputCmdTornadoH
#define InputCmdTornadoH

#include <string>
#include <vector>

#include "CmdParam.h"
 
class TInputCmdTornado
{
  
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

	struct TInput
	{
		std::string              libName;
    std::vector<std::string> param;
    int                      variant_use;
    bool                     useConsole;
		TInput()
		{
			variant_use = 0;
      useConsole  = false;
		}
	};

  TInputCmdTornado();
  ~TInputCmdTornado();

	bool SetArg(std::vector<std::string>& vecArgv);
	void Get(TInput& v_out);

protected:
	TInput mInput;
};

#endif
