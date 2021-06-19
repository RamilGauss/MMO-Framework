/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef IHandlerSceneH
#define IHandlerSceneH

#include "Scene.h"

class IHandlerScene
{
  TScene mScene;
public:
  IHandlerScene();

  TScene* GetScenePtr();
};


#endif
