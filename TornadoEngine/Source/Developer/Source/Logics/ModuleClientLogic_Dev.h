/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleClientLogic_DevH
#define ModuleClientLogic_DevH

#include "ModuleClientLogic.h"

class TClientMain;

class TModuleClientLogic_Dev : public TModuleClientLogic
{
	TClientMain* mClientMain;

public:
	virtual void StartEvent();
protected:
  virtual bool WorkClient();

  virtual void Input(int id, void* p, int size);
private:
	void StartTimer();
	void InitForms();
};

#endif
