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
#include "DstEvent.h"

class DllExport TModuleDev : public IModule, public TDstEvent
{
  int mID;
  std::string mName;
public:
  TModuleDev();
  virtual ~TModuleDev();

  virtual int GetID();
  virtual std::string GetName();

  void SetID(int id);
  void GetName(const char* name);

protected:
  virtual void InputFromModules();
  virtual void OutputFromModules();

  virtual void Input(void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
