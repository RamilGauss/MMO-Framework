/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicSuperServer_DevH
#define ModuleServerLogicSuperServer_DevH

#include "ModuleServerLogic.h"

class TSuperServerForm;

class TModuleServerLogicSuperServer_Dev : public TModuleServerLogic
{

	TSuperServerForm* mSuperServerForm;
public:
	TModuleServerLogicSuperServer_Dev();

	virtual void StartEvent();
	virtual void StopEvent();
protected:
  virtual bool WorkServer();
  virtual void EndWork();

  virtual void Input(int id, void* p, int size);
private:
	void InitForms();
};

#endif
