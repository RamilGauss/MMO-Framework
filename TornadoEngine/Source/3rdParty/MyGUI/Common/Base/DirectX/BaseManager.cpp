/*!
	@file
	@author		Albert Semenov
	@date		05/2009
*/


#include "Precompiled.h"
#include <d3dx9.h>
#include "BaseManager.h"
#include <MyGUI_DirectXPlatform.h>

#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
#	include <windows.h>
#	include <winuser.h>
# include <d3d9types.h>
#endif

// имя класса окна
const char* WND_CLASS_NAME = "MyGUI_Demo_window";

LRESULT CALLBACK DXWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	  case WM_CREATE:
	  {
		  SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)((LPCREATESTRUCT)lParam)->lpCreateParams);
		  break;
	  }

	  case WM_SIZE:
	  {
		  if (wParam != SIZE_MINIMIZED)
		  {
			  base::BaseManager* baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
			  if (baseManager)
				  baseManager->_windowResized();
		  }
		  break;
	  }

	  case WM_CLOSE:
	  {
		  base::BaseManager* baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		  if (baseManager)
			  baseManager->quit();
	  }

	  case WM_DESTROY:
	  {
		  PostQuitMessage(0);
		  break;
	  }

	  default:
	  {
		  return DefWindowProc(hWnd, uMsg, wParam, lParam);
	  }
	}
	return 0;
}

namespace base
{

	D3DPRESENT_PARAMETERS mD3dpp;

	BaseManager::BaseManager() :
		mGUI(nullptr),
		mPlatform(nullptr),
		hWnd(0),
		mD3d(nullptr),
		mDevice(nullptr),
		hInstance(nullptr),
		mExit(false),
		mResourceFileName("MyGUI_Core.xml"),
		mIsDeviceLost(false)
	{
	}

	BaseManager::~BaseManager()
	{
	}

	void BaseManager::_windowResized()
	{
		RECT rect = { 0, 0, 0, 0 };
		GetClientRect(hWnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		resizeRender(width, height);

		if (mPlatform)
			mPlatform->getRenderManagerPtr()->setViewSize(width, height);

		setInputViewSize(width, height);
	}

	bool BaseManager::create()
	{
    const unsigned int width = 1024;
		const unsigned int height = 768;
		bool windowed = true;

		// регистрируем класс окна
		WNDCLASS wc =
		{
			0, (WNDPROC)DXWndProc, 0, 0, GetModuleHandle(NULL), LoadIcon(NULL, MAKEINTRESOURCE(1001)),
			LoadCursor(NULL, IDC_ARROW), (HBRUSH)GetStockObject(BLACK_BRUSH), NULL, TEXT(WND_CLASS_NAME),
		};
		RegisterClass(&wc);

		// создаем главное окно
		hWnd = CreateWindow(wc.lpszClassName, TEXT("Direct3D9 Render Window"), WS_POPUP,
			0, 0, 0, 0, GetDesktopWindow(), NULL, wc.hInstance, this);
		if (!hWnd)
		{
			//OutException("fatal error!", "failed create window");
			return false;
		}

	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		// берем имя нашего экзешника
		char buf[MAX_PATH];
		::GetModuleFileNameA(0, (LPCH)&buf, MAX_PATH);
		// берем инстанс нашего модуля
		HINSTANCE instance = ::GetModuleHandleA(buf);
		// побыстрому грузим иконку
		HICON hIcon = ::LoadIcon(instance, MAKEINTRESOURCE(1001));
		if (hIcon)
		{
			::SendMessageA((HWND)hWnd, WM_SETICON, 1, (LPARAM)hIcon);
			::SendMessageA((HWND)hWnd, WM_SETICON, 0, (LPARAM)hIcon);
		}
	#endif

		hInstance = wc.hInstance;

		windowAdjustSettings(hWnd, width, height, !windowed);

		createRender(width, height, windowed);

		createGui();

		createInput((size_t)hWnd);

		createPointerManager((size_t)hWnd);

		createScene();

		_windowResized();

		return true;
	}
  //------------------------------------------------------------------------
	void BaseManager::run()
  {
		MSG msg;
		while (true)
		{
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (mExit)
				break;
			else if (msg.message == WM_QUIT)
				break;

			captureInput();
			drawOneFrame();

			if (GetActiveWindow() != hWnd)
				::Sleep(50);
		}
	}

	void BaseManager::destroy()
	{
		destroyScene();

		destroyPointerManager();

		destroyInput();

		destroyGui();

		destroyRender();

		if (hWnd)
		{
			DestroyWindow(hWnd);
			hWnd = 0;
		}

		UnregisterClass(WND_CLASS_NAME, hInstance);
	}

	void BaseManager::setupResources()
	{
		MyGUI::xml::Document doc;

		if (!doc.open(std::string("resources.xml")))
			doc.getLastError();

		MyGUI::xml::ElementPtr root = doc.getRoot();
		if (root == nullptr || root->getName() != "Paths")
			return;

		MyGUI::xml::ElementEnumerator node = root->getElementEnumerator();
		while (node.next())
		{
			if (node->getName() == "Path")
			{
				if (node->findAttribute("root") != "")
				{
					bool root = MyGUI::utility::parseBool(node->findAttribute("root"));
					if (root)
						mRootMedia = node->getContent();
				}
				addResourceLocation(node->getContent(), false);
			}
		}

		addResourceLocation(getRootMedia() + "/Common/Base");
	}

	void BaseManager::createGui()
	{
		mPlatform = new MyGUI::DirectXPlatform();
		mPlatform->initialise(mDevice);

		setupResources();

		mGUI = new MyGUI::Gui();
		mGUI->initialise(mResourceFileName);
	}

	void BaseManager::destroyGui()
	{
		if (mGUI)
		{
			mGUI->shutdown();
			delete mGUI;
			mGUI = nullptr;
		}

		if (mPlatform)
		{
			mPlatform->shutdown();
			delete mPlatform;
			mPlatform = nullptr;
		}
	}

	size_t BaseManager::getWindowHandle()
	{
		return (size_t)hWnd;
	}

	void BaseManager::setWindowCaption(const std::wstring& _text)
	{
		SetWindowTextW(hWnd, _text.c_str());
	}

	void BaseManager::prepare()
	{
	}

	void BaseManager::addResourceLocation(const std::string& _name, bool _recursive)
	{
		mPlatform->getDataManagerPtr()->addResourceLocation(_name, _recursive);
	}

	void BaseManager::windowAdjustSettings(HWND hWnd, int width, int height, bool fullScreen)
	{
		// стиль окна
		HWND hwndAfter = 0;
		unsigned long style = 0;
		unsigned long style_ex = 0;

		RECT rc = { 0, 0, width, height };

		if (fullScreen)
		{
			style = WS_POPUP | WS_VISIBLE;
			style_ex = GetWindowLongPtr(hWnd, GWL_EXSTYLE) | (WS_EX_TOPMOST);
			hwndAfter = HWND_TOPMOST;
		}
		else
		{
			style = WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_THICKFRAME;
			style_ex = GetWindowLongPtr(hWnd, GWL_EXSTYLE) & (~WS_EX_TOPMOST);
			hwndAfter = HWND_NOTOPMOST;
			AdjustWindowRect(&rc, style, false);
		}

		SetWindowLongPtr(hWnd, GWL_STYLE, style);
		SetWindowLongPtr(hWnd, GWL_EXSTYLE, style_ex);

		int desk_width  = GetSystemMetrics(SM_CXSCREEN);
		int desk_height = GetSystemMetrics(SM_CYSCREEN);

		int w = rc.right - rc.left;
		int h = rc.bottom - rc.top;
		int x = fullScreen ? 0 : (desk_width  - w) / 2;
		int y = fullScreen ? 0 : (desk_height - h) / 2;

		SetWindowPos(hWnd, hwndAfter, x, y, w, h, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
	}

	void BaseManager::injectMouseMove(int _absx, int _absy, int _absz)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMouseMove(_absx, _absy, _absz);
	}

	void BaseManager::injectMousePress(int _absx, int _absy, MyGUI::MouseButton _id)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMousePress(_absx, _absy, _id);
	}

	void BaseManager::injectMouseRelease(int _absx, int _absy, MyGUI::MouseButton _id)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMouseRelease(_absx, _absy, _id);
	}

	void BaseManager::injectKeyPress(MyGUI::KeyCode _key, MyGUI::Char _text)
	{
		if (!mGUI)
			return;

		if (_key == MyGUI::KeyCode::Escape)
		{
			mExit = true;
			return;
		}

		MyGUI::InputManager::getInstance().injectKeyPress(_key, _text);
	}

	void BaseManager::injectKeyRelease(MyGUI::KeyCode _key)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectKeyRelease(_key);
	}

	void BaseManager::resizeRender(int _width, int _height)
	{
		if (mDevice != nullptr)
		{
			if (mPlatform != nullptr)
				mPlatform->getRenderManagerPtr()->deviceLost();

			mD3dpp.BackBufferWidth = _width;
			mD3dpp.BackBufferHeight = _height;
			HRESULT hr = mDevice->Reset(&mD3dpp);

			if (hr == D3DERR_INVALIDCALL)
			{
				MessageBox( NULL, "Call to Reset() failed with D3DERR_INVALIDCALL! ",
					"ERROR", MB_OK | MB_ICONEXCLAMATION );
			}

			if (mPlatform != nullptr)
				mPlatform->getRenderManagerPtr()->deviceRestore();
		}
	}

	bool BaseManager::createRender(int _width, int _height, bool _windowed)
	{
		// инициализация direct3d
		mD3d = Direct3DCreate9(D3D_SDK_VERSION);

		D3DDISPLAYMODE d3ddm;
		mD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

		memset(&mD3dpp, 0, sizeof(mD3dpp));
		mD3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		mD3dpp.EnableAutoDepthStencil = TRUE;
		mD3dpp.BackBufferCount  = 1;
		mD3dpp.BackBufferFormat = d3ddm.Format;
		mD3dpp.BackBufferWidth  = _width;
		mD3dpp.BackBufferHeight = _height;
		mD3dpp.hDeviceWindow = hWnd;
		mD3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;
		mD3dpp.Windowed = _windowed;

    // ### Gauss 11.12.2012
		if (FAILED(mD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &mD3dpp, &mDevice)))
		{
      if (FAILED(mD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &mD3dpp, &mDevice)))
      {
        //OutException("fatal error!", "failed create d3d9 mDevice");
        return false;
      }
		}
    // ### Gauss
		return true;
	}

	bool mIsDeviceLost = false;

	void BaseManager::drawOneFrame()
	{
		if (mIsDeviceLost == true)
		{
			Sleep( 100 );

			HRESULT hr;
			if (FAILED(hr = mDevice->TestCooperativeLevel()))
			{
				if (hr == D3DERR_DEVICELOST)
					return;

				if (hr == D3DERR_DEVICENOTRESET)
				{
					if (mPlatform != nullptr)
						mPlatform->getRenderManagerPtr()->deviceLost();

					hr = mDevice->Reset( &mD3dpp );

					if (FAILED(hr))
						return;

					if (mPlatform != nullptr)
						mPlatform->getRenderManagerPtr()->deviceRestore();
				}

				return;
			}

			mIsDeviceLost = false;
		}

		if (SUCCEEDED(mDevice->BeginScene()))
		{
			mDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
			mPlatform->getRenderManagerPtr()->drawOneFrame();
			mDevice->EndScene();
		}

		if (mDevice->Present(NULL, NULL, 0, NULL) == D3DERR_DEVICELOST)
			mIsDeviceLost = true;
	}

	void BaseManager::destroyRender()
	{
		if (mDevice)
		{
			mDevice->Release();
			mDevice = 0;
		}
		if (mD3d)
		{
			mD3d->Release();
			mD3d = 0;
		}
	}

	void BaseManager::quit()
	{
		mExit = true;
	}

	const std::string& BaseManager::getRootMedia()
	{
		return mRootMedia;
	}

	void BaseManager::setResourceFilename(const std::string& _flename)
	{
		mResourceFileName = _flename;
	}
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  //### Gauss 13.12.2012
  bool BaseManager::addWindow(HWND hwnd, IDirect3D9* pD3d, IDirect3DDevice9* pDevice, void* pD3dpp, bool windowed)
  {
    hWnd = hwnd;
    RECT rect;
    BOOL res = GetWindowRect( hWnd, &rect); // размер окна
    if(res==false) return false;
    unsigned int width  = rect.right  - rect.left;
    unsigned int height = rect.bottom - rect.top;
    //---------------------------------------
    char pClassName[500];
    int resName = GetClassName(hWnd,pClassName,sizeof(pClassName)-1);
    if(resName==0) return false;
    //---------------------------------------
    HINSTANCE whInstance = GetModuleHandle(NULL);
    if(whInstance==NULL) 
      return false;
    //---------------------------------------
#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
    // берем имя нашего экзешника
    char buf[MAX_PATH];
    ::GetModuleFileNameA(0, (LPCH)&buf, MAX_PATH);
    // берем инстанс нашего модуля
    HINSTANCE instance = ::GetModuleHandleA(buf);
    // побыстрому грузим иконку
    HICON hIcon = ::LoadIcon(instance, MAKEINTRESOURCE(1001));
    if (hIcon)
    {
      ::SendMessageA((HWND)hWnd, WM_SETICON, 1, (LPARAM)hIcon);
      ::SendMessageA((HWND)hWnd, WM_SETICON, 0, (LPARAM)hIcon);
    }
#endif

    hInstance = whInstance;

    windowAdjustSettings(hWnd, width, height, !windowed);
    addRender(pD3d, pDevice, pD3dpp);
    createGui();
    createInput((size_t)hWnd);
    createPointerManager((size_t)hWnd);
    createScene();
    _windowResizedPartly();
    return true;
  }
  //------------------------------------------------------------------------
  //### Gauss 13.12.2012
  void BaseManager::addRender(IDirect3D9* pD3d, IDirect3DDevice9* pDevice, void* pD3dpp)
  {
    mD3d    = pD3d;
    mDevice = pDevice;
    mD3dpp  = *((D3DPRESENT_PARAMETERS*)pD3dpp);
  }
  //------------------------------------------------------------------------
  //### Gauss 13.12.2012
  void BaseManager::render()
  { 
    mPlatform->getRenderManagerPtr()->drawOneFrame();
  }
  //------------------------------------------------------------------------
  //### Gauss 13.12.2012
  void BaseManager::lostDevice()
  {
    Sleep( 100 );

    //HRESULT hr;
    //if (FAILED(hr = mDevice->TestCooperativeLevel()))
    {
      //if (hr == D3DERR_DEVICELOST)
        //return;

      //if (hr == D3DERR_DEVICENOTRESET)
      //{
        if (mPlatform != nullptr)
          mPlatform->getRenderManagerPtr()->deviceLost();

        // hr = mDevice->Reset( &mD3dpp ); // 19.12.2012 Gauss конвейер сам сделает 

        //if (FAILED(hr))
          //return;

        if (mPlatform != nullptr)
          mPlatform->getRenderManagerPtr()->deviceRestore();
      //}
    }
  }
  //------------------------------------------------------------------------
  // ### Gauss 14.12.2012
  void BaseManager::destroyPartly()
  {
    destroyScene();
    destroyPointerManager();
    destroyInput();
    destroyGui();
    hWnd = 0;
  }
  //------------------------------------------------------------------------
  void BaseManager::resizeRenderPartly(int _width, int _height)
  {
    if (mDevice != nullptr)
    {
      if (mPlatform != nullptr)
        mPlatform->getRenderManagerPtr()->deviceLost();

      //mD3dpp.BackBufferWidth = _width;
      //mD3dpp.BackBufferHeight = _height;
      //HRESULT hr = mDevice->Reset(&mD3dpp);

      //if (hr == D3DERR_INVALIDCALL)
      //{
      //  MessageBox( NULL, "Call to Reset() failed with D3DERR_INVALIDCALL! ",
      //    "ERROR", MB_OK | MB_ICONEXCLAMATION );
      //}

      if (mPlatform != nullptr)
        mPlatform->getRenderManagerPtr()->deviceRestore();
    }
  }
  //------------------------------------------------------------------------
  void BaseManager::_windowResizedPartly()
  {
    RECT rect = { 0, 0, 0, 0 };
    GetClientRect(hWnd, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    resizeRenderPartly(width, height);

    if (mPlatform)
      mPlatform->getRenderManagerPtr()->setViewSize(width, height);

    setInputViewSize(width, height);
  }
  //------------------------------------------------------------------------
} // namespace base
