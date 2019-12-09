/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef DevTool_SuperServerH
#define DevTool_SuperServerH

#include "DevTool_Share.h"

class TDevTool_SuperServer : public TDevTool_Share
{
public:
  TDevTool_SuperServer();
  virtual ~TDevTool_SuperServer();
  
  virtual std::string GetVariantConveyer();
protected:
  virtual TModuleDev* GetModuleLogic();
};

#endif
