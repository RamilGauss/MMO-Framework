/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DemoKeeper.h"

namespace demo
{

	void DemoKeeper::setupResources()
	{
		base::BaseManager::setupResources();
    addResourceLocation(getRootMedia() + "/Demos/Demo_Themes");
    addResourceLocation(getRootMedia() + "/Common/Themes");
    addResourceLocation(getRootMedia() + "/../form");
	}
  //-------------------------------------------------------------------------------------
	void DemoKeeper::createScene()
	{
    // загрузка скина
    MyGUI::ResourceManager::getInstance().load("MyGUI_BlackBlueTheme.xml");
  }
  //-------------------------------------------------------------------------------------
  void DemoKeeper::destroyScene()
	{
	}
  //-------------------------------------------------------------------------------------
} // namespace demo
