/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleGraphicEngine_DevH
#define ModuleGraphicEngine_DevH

#include "ModuleGraphicEngine.h"
#include "ClientMain.h"
#include <OgreEntity.h>
#include <OgreRenderWindow.h>


class TModuleGraphicEngine_Dev : public TModuleGraphicEngine
{
  boost::scoped_ptr<TClientMain> mClientMain;
public:
  virtual void StartEvent();
  virtual void StopEvent();
protected:
  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
private:
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

#endif
