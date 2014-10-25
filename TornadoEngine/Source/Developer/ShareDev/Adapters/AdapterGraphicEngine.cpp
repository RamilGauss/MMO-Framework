/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterGraphicEngine.h"
#include "BL_Debug.h"
#include "MyGUI_Gui.h"
#include "OGRE_Application.h"

using namespace demo;

AdapterGraphicEngine::AdapterGraphicEngine()
{
  try
  {
    mDemoKeeper = new DemoKeeper();
    mDemoKeeper->prepare();
    bool resCreate = mDemoKeeper->create();
    BL_ASSERT(resCreate);
  }
  catch (MyGUI::Exception& _e)
  {
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
    MessageBoxA( NULL, _e.getFullDescription().c_str(), "An exception has occured", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
    std::cerr << "An exception has occured" << " : " << _e.getFullDescription().c_str();
#endif
    throw;
  }
}
//---------------------------------------------------------------------------------
AdapterGraphicEngine::~AdapterGraphicEngine()
{
  mDemoKeeper->destroy();
  delete mDemoKeeper;
  mDemoKeeper = 0;
}
//---------------------------------------------------------------------------------
bool AdapterGraphicEngine::Work()
{
  try
  {
    return mDemoKeeper->work();
  }
  catch (MyGUI::Exception& _e)
  {
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
    MessageBoxA( NULL, _e.getFullDescription().c_str(), "An exception has occured", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
    std::cerr << "An exception has occured" << " : " << _e.getFullDescription().c_str();
#endif
    throw;
  }
}
//---------------------------------------------------------------------------------
