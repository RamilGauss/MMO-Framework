/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IDevToolH
#define IDevToolH

#include "classTools.h"
#include <string>
#include "DescEvent.h"
#include "Logger.h"

class TModuleDev;

class DllExport IDevTool
{
  NO_COPY_OBJECT(IDevTool)

  bool flgExit;
public:
  IDevTool();
  virtual ~IDevTool();

  virtual void Init(std::vector<std::string>& arg) = 0;
  virtual std::string GetPathXMLFile() = 0;
  virtual std::string GetPathServerLog() = 0;

  virtual void Done() = 0;
  virtual void Event(nsEvent::TEvent* pEvent) = 0;

  virtual int  GetCountModule() = 0;
  virtual int  GetModuleID(int index) = 0;
  virtual bool IsAddModuleInConveyer(int index) = 0;
  virtual void SetModulePtr(TModuleDev* ptr) = 0;// результат создания модуля, разработчик внесет к себе в компоненты
  virtual void FreeModulePtr(TModuleDev* ptr) = 0;// вызывается перед освобождением модуля, разработчик произведет дополнительные действия

  virtual void SetLoadConveyer(int procent);
  virtual int  GetTimeRefresh_ms();

	bool NeedExit();
	void Exit();// закончить работу с движком
};

#endif
