/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef ISceneSystemCollisionH
#define ISceneSystemCollisionH


class ISceneSystemCollision
{
public:

  ISceneSystemCollision();

  // дать квант для генерации коллизий из потока физики
  virtual void RefreshCollision() = 0;
};


#endif
