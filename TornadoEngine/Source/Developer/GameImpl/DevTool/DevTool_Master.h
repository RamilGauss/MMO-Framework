/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_MasterH
#define DevTool_MasterH

#include "DevTool_Share.h"

class TDevTool_Master : public TDevTool_Share
{
public:
  TDevTool_Master();
  virtual ~TDevTool_Master();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
