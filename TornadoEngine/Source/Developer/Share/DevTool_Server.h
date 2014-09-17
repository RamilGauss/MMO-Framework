/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ServerH
#define DevTool_ServerH

#include "DevTool_Share.h"

class TDevTool_Server : public TDevTool_Share
{
  enum
  {
    eModuleDev = 0,
    eModuleMMO,
    eModuleQt,
    eModuleTimer,
    eModuleServer,
    eCountModule,
  };

public:
  TDevTool_Server();
  virtual ~TDevTool_Server();

  virtual int  GetCountModule();
  virtual int  GetModuleID(int index);
  virtual bool IsAddModuleInConveyer(int index);

  virtual void SetLoadConveyer(int procent);
  virtual int  GetTimeRefresh_ms();
protected:
  virtual int GetIDPrototypeMMOEngineServer() = 0;// выбрать какой тип из серверов
};

#endif
