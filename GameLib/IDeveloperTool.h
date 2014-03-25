/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IDeveloperToolH
#define IDeveloperToolH

#include "classTools.h"
#include <string>
#include "DescEvent.h"
#include "IMakerObjectGeneral.h"
#include "Logger.h"
#include "SrcEvent.h"

class ITimer;

class IDeveloperTool
{
  NO_COPY_OBJECT(IDeveloperTool)

  bool flgExit;
protected:
  struct TComponent
  {
    TSrcEvent mDev;
    ITimer* mTimerFirstEvent;
    ITimer* mTimerLastEvent;
    TComponent()
    {
      mTimerFirstEvent = NULL;
      mTimerLastEvent  = NULL;
    }
  };

	IMakerObjectGeneral* mMakerObjectGeneral;

public:
  IDeveloperTool(){flgExit=false;}
  virtual ~IDeveloperTool(){};
  virtual IMakerObjectGeneral* GetMakerObjectGeneral() = 0;
  virtual std::string GetPathXMLFile() = 0;

  virtual void Done() = 0;
  virtual void Event(nsEvent::TEvent* pEvent) = 0;

	void Exit(){flgExit = true;}// закончить работу с движком
	bool NeedExit(){return flgExit;}
};

#endif
