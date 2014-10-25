/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef OGRE_ApplicationH
#define OGRE_ApplicationH

#include "Ogre/ExampleApplication.h"
#include "MyGUI_Gui.h"
#include "MyGUI_OgrePlatform.h"

class TOGRE_Application : public ExampleApplication 
{
  MyGUI::OgrePlatform* mPlatform;
  MyGUI::Gui* mGUI;
public: 
  TOGRE_Application();
  ~TOGRE_Application();
  
  void Init();
  void Work();
protected:
  virtual void createScene();
  virtual bool setup(void);
};

#endif