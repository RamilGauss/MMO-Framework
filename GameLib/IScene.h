/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ISceneH
#define ISceneH

#include <list>

#include "IManagerObjectCommon.h"
#include "IPhysicEngine.h"

class IScene
{
public:
  IScene();
  virtual ~IScene();

  virtual void Work() = 0;

protected:

  IManagerObjectCommon* mMOC;
  IPhysicEngine*        mPhysicEngine;


  virtual float GetTimeWork() = 0;

};

#endif