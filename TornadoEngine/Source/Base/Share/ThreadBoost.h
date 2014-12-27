/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TypeDef.h"

#ifndef ThreadBoostH
#define ThreadBoostH

class DllExport TThreadBoost
{
  volatile bool flgActive;
  volatile bool flgNeedStop;

  enum
  {
    eWaitFeedBack = 50, // ждать пока активизируется двигатель, мс
  };

public:
	TThreadBoost();
	virtual ~TThreadBoost();

  virtual bool IsActive();
  virtual void Start();
  virtual void Stop();
protected:
  void Engine();
protected:
  virtual void Work() = 0;
  virtual void StartEvent(){}
  virtual void StopEvent(){}
};


#endif