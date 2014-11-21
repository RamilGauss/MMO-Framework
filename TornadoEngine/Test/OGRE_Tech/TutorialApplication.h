/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

protected:
    virtual void createScene(void);

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
    void AddEntity(Ogre::Entity* pEnt, TOrient& orient);
};
//---------------------------------------------------------------------------
#endif // #ifndef __TutorialApplication_h_
