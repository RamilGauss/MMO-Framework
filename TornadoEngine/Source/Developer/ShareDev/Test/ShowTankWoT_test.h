/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef ShowTankWoT_testH
#define ShowTankWoT_testH

#include "TypeDef.h"
#include <Ogre.h>

class DllExport TShowTankWoT_test
{
  struct TOrient
  {
    const Ogre::Vector3 axisRotate;
    const Ogre::Radian  angleRotate;
    const Ogre::Vector3 scale;
    const Ogre::Vector3 pos;
    TOrient(Ogre::Vector3 _axisRotate, Ogre::Radian _angleRotate, 
      Ogre::Vector3 _scale, Ogre::Vector3 _pos):
    axisRotate(_axisRotate), angleRotate(_angleRotate),
      scale(_scale),pos(_pos){}
  };
public:
  TShowTankWoT_test();

  void ShowTanks(int cnt = 1);// Ogre thread only
protected:
  void AddEntity(Ogre::Entity* pEnt, TOrient& orient, Ogre::SceneManager* pSM);
  void ShowTank(int index, Ogre::Vector3& pos);
};

#endif
