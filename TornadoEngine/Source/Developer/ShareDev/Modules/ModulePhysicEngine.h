/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModulePhysicEngineH
#define ModulePhysicEngineH

#include "ModuleComponent.h"
#include "PhysicEngine_Bullet.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

class DllExport TModulePhysicEngine : public TModuleComponent
{
  boost::scoped_ptr<TPhysicEngine_Bullet> mPE;
public:
  TModulePhysicEngine();

  TPhysicEngine_Bullet* GetPE();

  virtual void StartEvent();
  virtual bool WorkInherit();
  virtual void StopEvent();
};

#endif
