/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeBaseModuleH
#define PrototypeBaseModuleH

#include "PrototypeList.h"
#include "Logger.h"
#include "IModule.h"

class DllExport PrototypeBaseModule : public IModule
{
public:
  PrototypeBaseModule(){};
  virtual ~PrototypeBaseModule(){};

  virtual PrototypeBaseModule* NewExample() = 0;
  virtual void DeleteExample(PrototypeBaseModule* ptr) = 0;

	virtual int GetVersionPrototype() = 0;
  virtual int GetVersionAdapter() = 0;
};

#endif
