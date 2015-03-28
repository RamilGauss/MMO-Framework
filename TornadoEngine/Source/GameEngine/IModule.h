/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IModuleH
#define IModuleH

#include "SynchroAbonent.h"

class DllExport IModule : public TSynchroAbonent
{
public:
  IModule(){};
  virtual ~IModule(){};

  virtual bool Work()           = 0;
  virtual int GetID()           = 0;
  virtual std::string GetName() = 0;

	virtual void StartEvent(){}
	virtual void StopEvent() {}
};

#endif
