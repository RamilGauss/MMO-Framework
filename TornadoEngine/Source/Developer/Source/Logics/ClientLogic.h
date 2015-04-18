/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ClientLogicH
#define ClientLogicH

#include "ModuleClientLogic.h"
#include "BaseEvent.h"

class TClientMain;

class TClientLogic : public TModuleClientLogic
{
  TClientMain* mClientMain;

public:
  virtual void StartEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id, void* p, int size);
private:
  void StartTimer();
  void InitForms();

  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);

  void LoginOnServer();

  void ShowFPS();
};

#endif
