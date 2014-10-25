/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ClientH
#define DevTool_ClientH

#include "DevTool_Share.h"

class DllExport TDevTool_Client : public TDevTool_Share
{
  enum
  {
    eModuleGE = 0,// графика
    eModulePE,    // физика
    eModuleSE,    // звук
    eModuleMMO,   // сеть
    eModuleTimer,    // таймер ядра
    eModuleDev,      // для создания события от самого же разработчика самому себе же
    eCountModule,
  };

public:
  TDevTool_Client();
  virtual ~TDevTool_Client();

  virtual int  GetCountModule();
  virtual int  GetModuleID(int index);
  virtual bool IsAddModuleInConveyer(int index);
  
  virtual std::string GetPathServerLog(){return "";}
};

#endif
