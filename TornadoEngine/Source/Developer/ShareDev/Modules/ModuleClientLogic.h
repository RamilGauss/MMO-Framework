/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleClientLogicH
#define ModuleClientLogicH

#include "ModuleLogic.h"
#include "InputCmdDevTool.h"

class DllExport TModuleClientLogic : public TModuleLogic
{
protected:
  TInputCmdDevTool mInputCmd;
public:
  virtual bool Work();
  virtual void ParseCmd(std::vector<std::string>& arg);
protected:
  virtual bool WorkClient() = 0;
};

#endif
