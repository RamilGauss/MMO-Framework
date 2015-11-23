/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_SlaveH
#define DevTool_SlaveH

#include "DevTool_Share.h"

class TDevTool_Slave : public TDevTool_Share
{
public:
  TDevTool_Slave();
  virtual ~TDevTool_Slave();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
