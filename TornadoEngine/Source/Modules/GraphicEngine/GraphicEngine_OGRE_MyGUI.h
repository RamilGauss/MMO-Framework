/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GraphicEngine_Ogre_MyGUIH
#define GraphicEngine_Ogre_MyGUIH

#include "TypeDef.h"
#include "SrcEvent.h"
#include "CallBackRegistrator.h"
#include "Events.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <MyGUI_Exception.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class TGE_Impl;

#define STR_NAME_GRAPHIC_ENGINE "GE"

/*
  Задачи класса: организация использования кванта времени (через Work()),
  выдача событий клавиатуры и мыши (те что не были поглощены GUI), 
  отрисовка окна GUI, 
  давать возможность управления камерой, 
  добавление и изменение объектов.
*/

class DllExport TGraphicEngine_Ogre_MyGUI : 
  public TSrcEvent /*for generation keyboard and mouse events(unused by GUI)*/
{
  TCallBackRegistrator2<const OIS::KeyEvent &, bool> mCBKeyBoard;
  TCallBackRegistrator3<const OIS::MouseEvent&, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent> mCBMouse;
public:
  TGraphicEngine_Ogre_MyGUI();
  virtual ~TGraphicEngine_Ogre_MyGUI();
/* Order of calls:
   1. InitOGRE, 2. AddResource, 3. InitMyGUI */
	bool InitOGRE(const std::string& pathPluginCfg);
  void AddResource(const std::string& name, const std::string& type);
  bool InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin);
  // return false - need exit
	bool Work();

  void SetWindowCaptionW(const std::wstring& _text);
  void SetWindowCaptionUtf8(const char* _text);
  size_t GetWindowHandle();

  void SetTimeoutDblClick(int t_ms);

  // например, в шутерах когда мешает GUI для получения события движения мыши
  void SetCenterClippingCursor(bool v);
  bool GetCenterClippingCursor();

  Ogre::Root*         GetRoot();
  Ogre::SceneManager* GetSceneManager();
  Ogre::Camera*       GetCamera();
  Ogre::RenderWindow* GetWindow();
private:
	boost::scoped_ptr<TGE_Impl> mGE;
  void MsgException(MyGUI::Exception& _e);

  void KeyBoardEvent(const OIS::KeyEvent & k, bool pressed);
  void MouseEvent(const OIS::MouseEvent& m, OIS::MouseButtonID id,
    nsGraphicEngine::tTypeMouseEvent typeEvent);

  bool CheckDblClick(const OIS::MouseEvent& m, OIS::MouseButtonID id,
    nsGraphicEngine::tTypeMouseEvent typeEvent);

private:
  struct TInfoClick
  {
    unsigned int mTimePrevLastPress;
    unsigned int mTimeLastPress;
    TInfoClick(){Init();}
    void Init(){mTimePrevLastPress=-1;mTimeLastPress=-1;}
    void SetTime(unsigned int t){mTimePrevLastPress=mTimeLastPress;mTimeLastPress=t;}
    bool IsSecondRelease(){return mTimePrevLastPress!=-1;}
  };

  TInfoClick mLClick;
  TInfoClick mRClick;

  int mTimeoutDblClick;
  enum
  {
    eTimeoutDblClick = 350, // ms
  };
};

#endif
