/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GraphicEngine_Ogre_MyGUI.h"
#include "GE_Impl.h"
#include "BL_Debug.h"
#include "SrcEvent_ex.h"
#include "Events.h"
#include "Logger.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

TGraphicEngine_Ogre_MyGUI::TGraphicEngine_Ogre_MyGUI()
{
  mTimeoutDblClick = eTimeoutDblClick;

  mCBKeyBoard.Register( &TGraphicEngine_Ogre_MyGUI::KeyBoardEvent, this);
  mCBMouse.Register( &TGraphicEngine_Ogre_MyGUI::MouseEvent, this);

	mGE.reset(new TGE_Impl);
  
  mGE->SetCallBackKeyBoard(&mCBKeyBoard);
  mGE->SetCallBackMouse(&mCBMouse);
}
//---------------------------------------------------------------------
TGraphicEngine_Ogre_MyGUI::~TGraphicEngine_Ogre_MyGUI()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_MyGUI::InitOGRE(const std::string& pathPluginCfg)
{
#ifdef WIN32
  ShowCursor(false);
#else

#endif

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
void TGraphicEngine_Ogre_MyGUI::AddResource(const std::string& name, const std::string& type)
{
  mGE->AddResource(name, type);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_MyGUI::InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin)
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
bool TGraphicEngine_Ogre_MyGUI::Work()
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
Ogre::Root* TGraphicEngine_Ogre_MyGUI::GetRoot()
{
  return mGE->GetRoot();
}
//---------------------------------------------------------------------
Ogre::SceneManager* TGraphicEngine_Ogre_MyGUI::GetSceneManager()
{
  return mGE->GetSceneManager();
}
//---------------------------------------------------------------------
Ogre::Camera* TGraphicEngine_Ogre_MyGUI::GetCamera()
{
  return mGE->GetCamera();
}
//---------------------------------------------------------------------
Ogre::RenderWindow* TGraphicEngine_Ogre_MyGUI::GetWindow()
{
	return mGE->GetWindow();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::MsgException(MyGUI::Exception& _e)
{
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
  MessageBoxA( NULL, _e.getFullDescription().c_str(), "An exception has occured", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
  std::cerr << "An exception has occured" << " : " << _e.getFullDescription().c_str();
#endif
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::SetWindowCaptionW(const std::wstring& _text)
{
  mGE->SetWindowCaption(_text);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::SetWindowCaptionUtf8(const char* sMsgUtf8)
{
#ifdef WIN32
  size_t lenMsgUtf8 = strlen(sMsgUtf8);
  TContainer cUnicode;
  cUnicode.SetData(NULL, 3*lenMsgUtf8+2);
  std::auto_ptr<boost::locale::util::base_converter> mConvFrom = 
    boost::locale::util::create_utf8_converter();

  wchar_t* pUnicode = (wchar_t*)cUnicode.GetPtr();
  const char* pCurFrom = sMsgUtf8;
  char* pEndFrom = (char*)sMsgUtf8 + lenMsgUtf8;
  int cntUnicode = 0;
  while(true)
  {
    boost::uint32_t u = mConvFrom->to_unicode(pCurFrom, pEndFrom);
    pUnicode[cntUnicode] = u;
    cntUnicode++;
    int len = pEndFrom - pCurFrom;
    if( len <= 0 )
      break;
  }
#else
  wchar_t* pUnicode = (wchar_t*)sMsgUtf8;
#endif
  pUnicode[cntUnicode] = L'\0';
  std::wstring caption = pUnicode;

  mGE->SetWindowCaption(caption);
}
//---------------------------------------------------------------------
size_t TGraphicEngine_Ogre_MyGUI::GetWindowHandle()
{
  return mGE->GetWindowHandle();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::KeyBoardEvent(const OIS::KeyEvent & k, bool pressed)
{
  nsGraphicEngine::TKeyEvent* pKE = new nsGraphicEngine::TKeyEvent;

  pKE->key      = k.key;
  pKE->pressed  = pressed;
  pKE->modifier = mGE->GetModifierKeyBoard();
  
  AddEventWithoutCopy<nsGraphicEngine::TKeyEvent>(pKE);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::MouseEvent(const OIS::MouseEvent& m, OIS::MouseButtonID id,
                                           nsGraphicEngine::tTypeMouseEvent typeEvent)
{
  nsGraphicEngine::TMouseEvent* pME = new nsGraphicEngine::TMouseEvent;

  pME->x              = m.state.X.abs;
  pME->y              = m.state.Y.abs;
  pME->dx             = m.state.X.rel;
  pME->dy             = m.state.Y.rel;
  pME->button         = id;
  pME->pressedButtons = m.state.buttons;
  pME->typeEvent      = typeEvent;

  if(m.state.Z.rel!=0)
  {
    pME->typeEvent = nsGraphicEngine::eWheel;
    pME->delta_wheel = m.state.Z.rel;
  }
  
  AddEventWithoutCopy<nsGraphicEngine::TMouseEvent>(pME);

  if( CheckDblClick(m, id, typeEvent) )
  {
    pME = new nsGraphicEngine::TMouseEvent;

    pME->x              = m.state.X.abs;
    pME->y              = m.state.Y.abs;
    pME->dx             = m.state.X.rel;
    pME->dy             = m.state.Y.rel;
    pME->button         = id;
    pME->pressedButtons = m.state.buttons;
    pME->typeEvent      = nsGraphicEngine::eButtonDblClick;

    AddEventWithoutCopy<nsGraphicEngine::TMouseEvent>(pME);
  }
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_MyGUI::CheckDblClick(const OIS::MouseEvent& m, OIS::MouseButtonID id,
    nsGraphicEngine::tTypeMouseEvent typeEvent)
{
  // проверка на двойной клик
  if(typeEvent!=nsGraphicEngine::eButtonDown && 
     typeEvent!=nsGraphicEngine::eButtonUp    )
    return false;
  
  if(id!=OIS::MB_Left && id!=OIS::MB_Right)
    return false;

  TInfoClick* pClick = (id==OIS::MB_Left) ? &mLClick : &mRClick;

  unsigned int now_ms = ht_GetMSCount();

  if(typeEvent==nsGraphicEngine::eButtonDown)
  {
    pClick->SetTime(now_ms);
  }
  else
  {
    if(pClick->IsSecondRelease())
    {
      if(now_ms < pClick->mTimePrevLastPress + mTimeoutDblClick)
      {
        pClick->Init();
        return true;
      }
    }
  }
  return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::SetTimeoutDblClick(int t_ms)
{
  mTimeoutDblClick = t_ms;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_MyGUI::SetCenterClippingCursor(bool v)
{
  mGE->SetCenterClippingCursor(v);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_MyGUI::GetCenterClippingCursor()
{
  return mGE->GetCenterClippingCursor();
}
//---------------------------------------------------------------------
