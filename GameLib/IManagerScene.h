/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IManagerSceneH
#define IManagerSceneH

#include <vector>
#include "SrcEvent.h"

#define STR_NAME_MANAGER_SCENE "MScene"

class IScene;

class IManagerScene //: public TSrcEvent
{
protected:
  std::vector<IScene* > mVectorScene;

public:

  IManagerScene();
  virtual ~IManagerScene();

  virtual void Work() = 0;

  void AddObject(IScene* pScene);
  IScene* Get(int index);// отдать объект на изменение свойств (в основном для отладки)
  int GetCountObject();

  void Erase(int index);

};

#endif
