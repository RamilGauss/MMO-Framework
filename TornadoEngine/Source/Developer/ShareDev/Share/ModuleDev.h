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

  TCallBackRegistrator0 mCBEndWork;
public:
  TModuleDev();

  virtual bool Work();
  virtual bool WorkInherit() = 0;
  TCallBackRegistrator0* GetCBEndWork();

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
