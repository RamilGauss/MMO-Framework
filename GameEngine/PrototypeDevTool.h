/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeDevToolH
#define PrototypeDevToolH

#include "PrototypeBaseModule.h"

class DllExport PrototypeDevTool : public PrototypeBaseModule
{
public:
  virtual bool Work(){return true;}

  virtual PrototypeBaseModule* NewExample(){return new PrototypeDevTool;}
  virtual void DeleteExample(PrototypeBaseModule* ptr){delete ptr;}

  virtual int GetVersionPrototype(){return 1;}
  virtual int GetVersionAdapter(){return 1;}
protected:
  virtual int GetType(){return PROTOTYPE_TYPE_DEV_TOOL;}
};

#endif
