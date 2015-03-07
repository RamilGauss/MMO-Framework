/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GraphicEngine_OGRE_MyGUI.h"
#include "GE_Impl.h"
#include "BL_Debug.h"


TGraphicEngine_OGRE_MyGUI::TGraphicEngine_OGRE_MyGUI()
{
	mGE.reset(new TGE_Impl);
}
//---------------------------------------------------------------------
TGraphicEngine_OGRE_MyGUI::~TGraphicEngine_OGRE_MyGUI()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_OGRE_MyGUI::InitOGRE(const std::string& pathPluginCfg)
{
	try
	{
		return mGE->InitOGRE(pathPluginCfg);
	}
	catch(MyGUI::Exception& _e)
	{
    MsgException(_e);
		throw;
	}
	return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_OGRE_MyGUI::AddResource(const std::string& name, const std::string& type)
{
  mGE->AddResource(name, type);
}
//---------------------------------------------------------------------
bool TGraphicEngine_OGRE_MyGUI::InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin)
{
  try
  {
    return mGE->InitMyGUI(nameFileCore, nameFileSkin);
  }
  catch(MyGUI::Exception& _e)
  {
    MsgException(_e);    
    throw;
  }
  return false;
}
//---------------------------------------------------------------------
bool TGraphicEngine_OGRE_MyGUI::Work()
{
  try
  {
    return mGE->Work();
  }
  catch(MyGUI::Exception& _e)
  {
    MsgException(_e);    
    throw;
  }
  return false;
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_OGRE_MyGUI::GetRoot()
{
  return mGE->GetRoot();
}
//---------------------------------------------------------------------
Ogre::SceneManager* TGraphicEngine_OGRE_MyGUI::GetSceneManager()
{
  return mGE->GetSceneManager();
}
//---------------------------------------------------------------------
Ogre::Camera* TGraphicEngine_OGRE_MyGUI::GetCamera()
{
  return mGE->GetCamera();
}
//---------------------------------------------------------------------
Ogre::RenderWindow* TGraphicEngine_OGRE_MyGUI::GetWindow()
{
	return mGE->GetWindow();
}
//---------------------------------------------------------------------
void TGraphicEngine_OGRE_MyGUI::MsgException(MyGUI::Exception& _e)
{
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
  MessageBoxA( NULL, _e.getFullDescription().c_str(), "An exception has occured", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
  std::cerr << "An exception has occured" << " : " << _e.getFullDescription().c_str();
#endif
}
//---------------------------------------------------------------------
void TGraphicEngine_OGRE_MyGUI::SetWindowCaption(const std::wstring& _text)
{
  mGE->SetWindowCaption(_text);
}
//---------------------------------------------------------------------
size_t TGraphicEngine_OGRE_MyGUI::GetWindowHandle()
{
  return mGE->GetWindowHandle();
}
//---------------------------------------------------------------------

