/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleComponentH
#define ModuleComponentH

#include "ModuleDev.h"
#include "DstEvent.h"

class DllExport TModuleComponent : public TModuleDev, public TDstEvent
{
protected:
	int mLogicID;
public:
  TModuleComponent();

  void SetLogicID(int id);

protected:
  virtual void Input(int id_sender, void* p, int size);
protected:
  void OutputToSynchroPoint();
};

#endif
