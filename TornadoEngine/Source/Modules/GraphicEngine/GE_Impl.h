/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GRAPHIC_ENGINE_IMPLEMENTATION_H
#define GRAPHIC_ENGINE_IMPLEMENTATION_H

#include <Ogre.h>
#include <MyGUI.h>

#include "InputManagerOIS.h"
#include "MyGUI_LastHeader.h"
#include "MyGUI_OgrePlatform.h"

class TGE_Impl :
  public TInputManagerOIS,
	public Ogre::FrameListener,
	public Ogre::WindowEventListener
{
public:
	TGE_Impl();
	virtual ~TGE_Impl();

  bool InitOGRE(const std::string& pathPluginCfg);
  void AddResource(const std::string& name, const std::string& type);
  bool InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin);

  bool Work();

	void SetWindowCaption(const std::wstring& _text);
	size_t GetWindowHandle();

/*internal:*/
	Ogre::SceneManager* GetSceneManager();
	Ogre::Root*         GetRoot();
	Ogre::Camera*       GetCamera();
  Ogre::RenderWindow* GetWindow();
protected:
  void Done();

  virtual bool mouseMoved( const OIS::MouseEvent &arg );
  virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
  virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
  virtual bool keyPressed(const OIS::KeyEvent &arg);
  virtual bool keyReleased(const OIS::KeyEvent &arg);		

	void DestroyGui();
private:
	virtual bool frameStarted(const Ogre::FrameEvent& _evt);
	virtual bool frameEnded(const Ogre::FrameEvent& _evt);
	virtual void windowResized(Ogre::RenderWindow* _rw);
	virtual void windowClosed(Ogre::RenderWindow* _rw);

private:
	MyGUI::Gui* mGUI;
	MyGUI::OgrePlatform* mPlatform;

	Ogre::Root* mRoot;
	Ogre::Camera* mCamera;
	Ogre::SceneManager* mSceneManager;
	Ogre::RenderWindow* mWindow;

	bool mExit;
};

#endif 
