/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TManagerSceneH
#define TManagerSceneH

#include "IManagerScene.h"

class TManagerScene : public IManagerScene
{
public:

  TManagerScene();
  virtual ~TManagerScene();

  virtual void Work();

};

#endif
