/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GE_Impl.h"
#include "Logger.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "Events.h"

#include <MyGUI_OgrePlatform.h>

using namespace std;

#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
#	include <windows.h>
#elif MYGUI_PLATFORM == MYGUI_PLATFORM_LINUX
#	include <X11/Xlib.h>
#	include <X11/Xutil.h>
#	include <X11/Xatom.h>
#endif

#if MYGUI_PLATFORM == MYGUI_PLATFORM_APPLE
#include <CoreFoundation/CoreFoundation.h>
// This function will locate the path to our application on OS X,
// unlike windows you can not rely on the current working directory
// for locating your configuration files and resources.
std::string macBundlePath()
{
	char path[1024];
	CFBundleRef mainBundle = CFBundleGetMainBundle();
	assert(mainBundle);
	CFURLRef mainBundleURL = CFBundleCopyBundleURL(mainBundle);
	assert(mainBundleURL);
	CFStringRef cfStringRef = CFURLCopyFileSystemPath( mainBundleURL, kCFURLPOSIXPathStyle);
	assert(cfStringRef);
	CFStringGetCString(cfStringRef, path, 1024, kCFStringEncodingASCII);
	CFRelease(mainBundleURL);
	CFRelease(cfStringRef);
	return std::string(path);
}
#endif

TGE_Impl::TGE_Impl()
{
  mGUI          = NULL;
  mPlatform     = NULL;
  mRoot         = NULL;
  mCamera       = NULL;
  mSceneManager = NULL;
  mWindow       = NULL;
  mExit         = false;

  mCBKeyBoard  = NULL;
  mCBMouse     = NULL;
  mKeyModifier = 0;

  flgLControl_Press = false;
  flgRControl_Press = false;
  flgLAlt_Press = false;
  flgRAlt_Press = false;
  flgLShift_Press = false;
  flgRShift_Press = false;
}
//------------------------------------------------------------------------------------------
TGE_Impl::~TGE_Impl()
{
  Done();
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::InitOGRE(const std::string& pathPluginCfg)
{
	mRoot = new Ogre::Root(pathPluginCfg, "ogre.cfg", "Ogre.log");
  if( !mRoot->restoreConfig() )// попробуем завестись на дефолтных
  {
    if(!mRoot->showConfigDialog()) return false;// ничего не получилось, покажем диалог
  }
  mWindow = mRoot->initialise(true);
  // вытаскиваем дискриптор окна
  size_t handle = GetWindowHandle();
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
  // берем имя нашего исполняемого файла
  char buf[MAX_PATH];
  ::GetModuleFileNameA(0, (LPCH)&buf, MAX_PATH);
  // берем инстанс нашего модуля
  HINSTANCE instance = ::GetModuleHandleA(buf);
  // по-быстрому грузим иконку
  HICON hIcon = ::LoadIcon(instance, MAKEINTRESOURCE(1001));
  if( hIcon )
  {
    ::SendMessageA((HWND)handle, WM_SETICON, 1, (LPARAM)hIcon);
    ::SendMessageA((HWND)handle, WM_SETICON, 0, (LPARAM)hIcon);
  }
#endif
  mSceneManager = mRoot->createSceneManager(Ogre::ST_GENERIC, "BaseSceneManager");

  mCamera = mSceneManager->createCamera("BaseCamera");
  mCamera->setNearClipDistance(5);
  mCamera->setPosition(400, 400, 400);
  mCamera->lookAt(0, 150, 0);

  // Create one viewport, entire window
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
  // Alter the camera aspect ratio to match the viewport
  mCamera->setAspectRatio((float)vp->getActualWidth() / (float)vp->getActualHeight());

  // Set default mipmap level (NB some APIs ignore this)
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

  mRoot->addFrameListener(this);
  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
  return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin)
{
  // Load resources
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  mPlatform = new MyGUI::OgrePlatform();
  mPlatform->initialise(mWindow, mSceneManager);
  mGUI = new MyGUI::Gui();
  mGUI->initialise(nameFileCore);

  bool resLoad = MyGUI::ResourceManager::getInstance().load(nameFileSkin);

  CreateInput(GetWindowHandle());
	windowResized(mWindow);

  return resLoad;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::Done()
{
	DestroyInput();
	DestroyGui();

	// очищаем сцену
	if(mSceneManager)
	{
		mSceneManager->clearScene();
		mSceneManager->destroyAllCameras();
		mSceneManager = nullptr;
		mCamera = nullptr;
	}

	if(mWindow)
	{
		mWindow->destroy();
		mWindow = nullptr;
	}

	if(mRoot)
	{
		Ogre::RenderWindow* window = mRoot->getAutoCreatedWindow();
		if(window)
			window->removeAllViewports();
		delete mRoot;
		mRoot = nullptr;
	}

#ifdef WIN32
  RECT rc;
  rc.left = 0;
  rc.top  = 0;
  rc.right  = 10000;
  rc.bottom = 10000;
  ClipCursor(&rc);
#else
  // TODO: X11, how clip cursor?
#endif
}
//------------------------------------------------------------------------------------------
void TGE_Impl::DestroyGui()
{
	if(mGUI)
	{
		mGUI->shutdown();
		delete mGUI;
		mGUI = nullptr;
	}

	if(mPlatform)
	{
		mPlatform->shutdown();
		delete mPlatform;
		mPlatform = nullptr;
	}
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::frameStarted(const Ogre::FrameEvent& evt)
{
	if(mExit)
		return false;

	if (!mGUI)
		return true;

	CaptureInput();
	return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::frameEnded(const Ogre::FrameEvent& evt)
{
	return true;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::windowResized(Ogre::RenderWindow* _rw)
{
	int width  = (int)_rw->getWidth();
	int height = (int)_rw->getHeight();

	// при удалении окна может вызываться этот метод
	if(mCamera)
	{
		mCamera->setAspectRatio((float)width / (float)height);
		SetInputViewSize(width, height);
	}
}
//------------------------------------------------------------------------------------------
void TGE_Impl::windowClosed(Ogre::RenderWindow* _rw)
{
	mExit = true;
	DestroyInput();
}
//------------------------------------------------------------------------------------------
size_t TGE_Impl::GetWindowHandle()
{
	size_t handle = 0;
	mWindow->getCustomAttribute("WINDOW", &handle);
	return handle;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::SetWindowCaption(const std::wstring& _text)
{
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
	::SetWindowTextW((HWND)GetWindowHandle(), _text.c_str());
#elif MYGUI_PLATFORM == MYGUI_PLATFORM_LINUX
	Display* xDisplay = nullptr;
	unsigned long windowHandle = 0;
	mWindow->getCustomAttribute("XDISPLAY", &xDisplay);
	mWindow->getCustomAttribute("WINDOW", &windowHandle);
	Window win = (Window)windowHandle;

	XTextProperty windowName;
	windowName.value    = (unsigned char *)(MyGUI::UString(_text).asUTF8_c_str());
	windowName.encoding = XA_STRING;
	windowName.format   = 8;
	windowName.nitems   = strlen((char *)(windowName.value));
	XSetWMName(xDisplay, win, &windowName);
#endif
}
//------------------------------------------------------------------------------------------
void TGE_Impl::AddResource(const std::string& name, const std::string& type)
{
#if MYGUI_PLATFORM == MYGUI_PLATFORM_APPLE
  // OS X does not set the working directory relative to the app, In order to make things portable on OS X we need to provide the loading with it's own bundle path location
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(Ogre::String(macBundlePath() + "/" + name), type);
#else
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type);
#endif
}
//------------------------------------------------------------------------------------------
Ogre::SceneManager* TGE_Impl::GetSceneManager()
{
	return mSceneManager;
}
//------------------------------------------------------------------------------------------
Ogre::Camera* TGE_Impl::GetCamera()
{
	return mCamera;
}
//------------------------------------------------------------------------------------------
Ogre::RenderWindow* TGE_Impl::GetWindow()
{
  return mWindow;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::Work()
{
  Ogre::WindowEventUtilities::messagePump();
  return mRoot->renderOneFrame();
}
//------------------------------------------------------------------------------------------
Ogre::Root* TGE_Impl::GetRoot()
{
  return mRoot;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::mouseMoved( const OIS::MouseEvent &arg )
{
  // 04.10.2016, clipping the cursor
  // проверить - выходит ли курсор за границу окна 
#ifdef WIN32
  RECT rc;
  POINT point;
  point.x = 0;
  point.y = 0;
  ClientToScreen((HWND)GetWindowHandle(), &point);
  rc.left = point.x;
  rc.top  = point.y;

  point.x = (int)GetWindow()->getWidth();
  point.y = (int)GetWindow()->getHeight();
  ClientToScreen((HWND)GetWindowHandle(), &point);
  rc.right  = point.x;
  rc.bottom = point.y;

  ClipCursor(&rc);
#else
  // TODO: X11, how clip cursor?
#endif

  bool unused = true;
  if(mGUI)
    unused = !MyGUI::InputManager::getInstance().injectMouseMove(
      arg.state.X.abs, arg.state.Y.abs, arg.state.Z.abs);
  
  if(unused)
  {
    // транслировать разработчику как событие
    mCBMouse->Notify( arg, OIS::MB_Left/*nevermind*/, nsGraphicEngine::eMove);
  }
  return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  bool unused = true;
  if(mGUI)
    unused = !MyGUI::InputManager::getInstance().injectMousePress(
      arg.state.X.abs, arg.state.Y.abs, MyGUI::MouseButton::Enum(id));

  if(unused)
  {
    // транслировать разработчику как событие
    mCBMouse->Notify( arg, id, nsGraphicEngine::eButtonDown);
  }
  return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  bool unused = true;
  if(mGUI)
    unused = !MyGUI::InputManager::getInstance().injectMouseRelease(
      arg.state.X.abs, arg.state.Y.abs, MyGUI::MouseButton::Enum(id));

  if(unused)
  {
    // транслировать разработчику как событие
    mCBMouse->Notify( arg, id, nsGraphicEngine::eButtonUp );
  }
  return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::keyPressed(const OIS::KeyEvent &arg)
{
  SetKeyBoardModifier(arg, true);

  MyGUI::Char text;
  MyGUI::KeyCode key;
  ConvertOIS2MyGUI(arg, text, key);

  bool unused = true;
  if(mGUI)
    unused = !MyGUI::InputManager::getInstance().injectKeyPress(key, text);

  if(unused)
  {
    // транслировать разработчику как событие
    mCBKeyBoard->Notify( arg, true);
  }
  return true;
}
//------------------------------------------------------------------------------------------
bool TGE_Impl::keyReleased(const OIS::KeyEvent &arg)
{
  SetKeyBoardModifier(arg, false);

  MyGUI::Char text;
  MyGUI::KeyCode key;
  ConvertOIS2MyGUI(arg, text, key);

  bool unused = true;
  if(mGUI)
    unused = !MyGUI::InputManager::getInstance().injectKeyRelease(key);

  if(unused)
  {
    // транслировать разработчику как событие
    mCBKeyBoard->Notify( arg, false);
  }
  return true;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::SetCallBackKeyBoard(TCallBackRegistrator2<const OIS::KeyEvent &, bool>* pCB)
{
  mCBKeyBoard = pCB;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::SetCallBackMouse(TCallBackRegistrator3<const OIS::MouseEvent &,OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>* pCB)
{
  mCBMouse = pCB;
}
//------------------------------------------------------------------------------------------
int TGE_Impl::GetModifierKeyBoard()
{
  return mKeyModifier;
}
//------------------------------------------------------------------------------------------
void TGE_Impl::SetKeyBoardModifier(const OIS::KeyEvent &arg, bool pressed)
{
  switch(arg.key)
  {
    case OIS::KC_LCONTROL:
      flgLControl_Press = pressed;
      break;
    case OIS::KC_RCONTROL:
      flgRControl_Press = pressed;
      break;
    case OIS::KC_LSHIFT:
      flgLShift_Press = pressed;
      break;
    case OIS::KC_RSHIFT:
      flgRShift_Press = pressed;
      break;
    case OIS::KC_LMENU:// alt
      flgLAlt_Press = pressed;
      break;
    case OIS::KC_RMENU:// alt
      flgRAlt_Press = pressed;
      break;
    default:return;
  }
  mKeyModifier = 0;
  if(flgLControl_Press || flgRControl_Press)
    mKeyModifier |= OIS::Keyboard::Ctrl;
  if(flgLShift_Press || flgRShift_Press)
    mKeyModifier |= OIS::Keyboard::Shift;
  if(flgLAlt_Press || flgRAlt_Press)
    mKeyModifier |= OIS::Keyboard::Alt;
}
//------------------------------------------------------------------------------------------
