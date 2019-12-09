/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef DevTool_ClientH
#define DevTool_ClientH

#include "DevTool_Share.h"

class TDevTool_Client : public TDevTool_Share
{
public:
  TDevTool_Client();
  virtual ~TDevTool_Client();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
