/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ClientH
#define DevTool_ClientH

#include "DevTool_Share.h"

class TDevTool_Client : public TDevTool_Share
{
  enum
  {
    MODULE_GE = 0,
    MODULE_MMO_CLIENT,
    MODULE_MOG,
    MODULE_TIMER,
    MODULE_DEV,
    CNT_MODULE,
  };

public:
  TDevTool_Client();
  virtual ~TDevTool_Client();

  virtual int  GetCountModule();
  virtual int  GetModuleID(int index);
  virtual bool IsAddModuleInConveyer(int index);
};

#endif
