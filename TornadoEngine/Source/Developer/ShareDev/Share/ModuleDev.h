/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleDevH
#define ModuleDevH

#include "TypeDef.h"
#include "IModule.h"

class DllExport TModuleDev : public IModule
{
  int mID;
  std::string mName;
public:
  TModuleDev();

  virtual int GetID();
  virtual std::string GetName();

  void SetID(int id);
  void SetName(const char* name);
protected:
  void InputFromSynchroPoint();
protected:
  virtual void Input(int id_sender, void* p, int size) = 0;
};

#endif
