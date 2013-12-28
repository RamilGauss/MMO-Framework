/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DXUT_Class.h"
#include "GraphicEngine.h"

using namespace std;
using namespace nsStruct3D;

TDXUT* pDXUT_Realize = NULL;

//--------------------------------------------------------------------------------------
void CALLBACK OnKeyEvent( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnKeyEvent( nChar, bKeyDown, bAltDown, pUserContext );
}
//--------------------------------------------------------------------------------------
void TDXUT::OnKeyEvent( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext )
{
  if(pGE)
    pGE->OnKeyEvent( nChar, bKeyDown, bAltDown, pUserContext );
}
//--------------------------------------------------------------------------------------
void CALLBACK OnMouseEvent( UINT state, bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown, bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta, int xPos, int yPos, void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnMouseEvent(state, bLeftButtonDown, bRightButtonDown, bMiddleButtonDown, bSideButton1Down, bSideButton2Down, nMouseWheelDelta, xPos, yPos, pUserContext );
}
//--------------------------------------------------------------------------------------
void TDXUT::OnMouseEvent( UINT state, bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown, bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta, int xPos, int yPos, void* pUserContext )
{
  if(pGE)
    pGE->OnMouseEvent( state, nMouseWheelDelta, xPos, yPos, pUserContext );
}
//--------------------------------------------------------------------------------------
// Called during device initialization, this code checks the device for some 
// minimum set of capabilities, and rejects those that don't pass by returning false.
//--------------------------------------------------------------------------------------
bool CALLBACK IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat,
                                 D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext )
{
  if(pDXUT_Realize)
    return pDXUT_Realize->IsDeviceAcceptable( pCaps, AdapterFormat,BackBufferFormat, bWindowed, pUserContext );
  return false;
}
//--------------------------------------------------------------------------------------
bool TDXUT::IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat,
                                  D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext )
{
  if(pGE)
    return pGE->IsDeviceAcceptable( pCaps, AdapterFormat,BackBufferFormat, bWindowed, pUserContext );

  return false;
}
//--------------------------------------------------------------------------------------
// This callback function is called immediately before a device is created to allow the 
// application to modify the device settings. The supplied pDeviceSettings parameter 
// contains the settings that the framework has selected for the new device, and the 
// application can make any desired changes directly to this structure.  Note however that 
// DXUT will not correct invalid device settings so care must be taken 
// to return valid device settings, otherwise IDirect3D9::CreateDevice() will fail.  
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
  if(pDXUT_Realize)
    return pDXUT_Realize->ModifyDeviceSettings( pDeviceSettings, pUserContext );
  return false;
}
//--------------------------------------------------------------------------------------
bool TDXUT::ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
  if(pGE)
    return pGE->ModifyDeviceSettings( pDeviceSettings, pUserContext );
  return false;
}
//--------------------------------------------------------------------------------------
// This callback function will be called immediately after the Direct3D device has been 
// created, which will happen during application initialization and windowed/full screen 
// toggles. This is the best location to create D3DPOOL_MANAGED resources since these 
// resources need to be reloaded whenever the device is destroyed. Resources created  
// here should be released in the OnDestroyDevice callback. 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                 void* pUserContext )
{
  if(pDXUT_Realize)
    return pDXUT_Realize->OnCreateDevice( pd3dDevice, pBackBufferSurfaceDesc, pUserContext );
  return S_FALSE;
}
//--------------------------------------------------------------------------------------
HRESULT TDXUT::OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                 void* pUserContext )
{
  if(pGE)
    return pGE->OnCreateDevice( pd3dDevice, pBackBufferSurfaceDesc, pUserContext );
  return S_FALSE;
}
//--------------------------------------------------------------------------------------
// This callback function will be called immediately after the Direct3D device has been 
// reset, which will happen after a lost device scenario. This is the best location to 
// create D3DPOOL_DEFAULT resources since these resources need to be reloaded whenever 
// the device is lost. Resources created here should be released in the OnLostDevice 
// callback. 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnResetDevice( IDirect3DDevice9* pd3dDevice,
                               const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
  if(pDXUT_Realize)
    return pDXUT_Realize->OnResetDevice( pd3dDevice, pBackBufferSurfaceDesc, pUserContext );
  return S_FALSE;
}
//--------------------------------------------------------------------------------------
HRESULT TDXUT::OnResetDevice( IDirect3DDevice9* pd3dDevice,
                                const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
  HRESULT hr;
  if(pGE)
  {
    V_RETURN(pGE->OnResetDevice( pd3dDevice, pBackBufferSurfaceDesc, pUserContext ));
    m_pManagerState.Reset(pd3dDevice);
    return S_OK;
  }

  return S_FALSE;
}
//--------------------------------------------------------------------------------------
// This callback function will be called once at the beginning of every frame. This is the
// best location for your application to handle updates to the scene, but is not 
// intended to contain actual rendering calls, which should instead be placed in the 
// OnFrameRender callback.  
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnFrameMove(fTime, fElapsedTime, pUserContext);
}
//--------------------------------------------------------------------------------------
void TDXUT::OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
  if(pGE)
    pGE->OnFrameMove(fTime, fElapsedTime, pUserContext);
}
//--------------------------------------------------------------------------------------
// This callback function will be called at the end of every frame to perform all the 
// rendering calls for the scene, and it will also be called if the window needs to be 
// repainted. After this function has returned, DXUT will call 
// IDirect3DDevice9::Present to display the contents of the next buffer in the swap chain
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnFrameRender( pd3dDevice, fTime, fElapsedTime, pUserContext );
}
//--------------------------------------------------------------------------------------
void TDXUT::OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
  if(pGE)
    pGE->OnFrameRender( pd3dDevice, fTime, fElapsedTime, pUserContext );
}
//--------------------------------------------------------------------------------------
// Before handling window messages, DXUT passes incoming windows 
// messages to the application through this callback function. If the application sets 
// *pbNoFurtherProcessing to TRUE, then DXUT will not process this message.
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing,
                          void* pUserContext )
{
  if(pDXUT_Realize)
    return pDXUT_Realize->MsgProc(hWnd, uMsg, wParam, lParam, pbNoFurtherProcessing,pUserContext);
  return 0;
}
//--------------------------------------------------------------------------------------
LRESULT TDXUT::MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing,
                          void* pUserContext )
{
  if(pGE)
    return pGE->MsgProc(hWnd, uMsg, wParam, lParam, pbNoFurtherProcessing,pUserContext);
  return 0;
}
//--------------------------------------------------------------------------------------
// This callback function will be called immediately after the Direct3D device has 
// entered a lost state and before IDirect3DDevice9::Reset is called. Resources created
// in the OnResetDevice callback should be released here, which generally includes all 
// D3DPOOL_DEFAULT resources. See the "Lost Devices" section of the documentation for 
// information about lost devices.
//--------------------------------------------------------------------------------------
void CALLBACK OnLostDevice( void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnLostDevice(pUserContext);
}
//--------------------------------------------------------------------------------------
void TDXUT::OnLostDevice( void* pUserContext )
{
  if(pGE)
    pGE->OnLostDevice(pUserContext);

  flgWasLostEvent = true;

  m_pManagerState.Lost();
}
//--------------------------------------------------------------------------------------
// This callback function will be called immediately after the Direct3D device has 
// been destroyed, which generally happens as a result of application termination or 
// windowed/full screen toggles. Resources created in the OnCreateDevice callback 
// should be released here, which generally includes all D3DPOOL_MANAGED resources. 
//--------------------------------------------------------------------------------------
void CALLBACK OnDestroyDevice( void* pUserContext )
{
  if(pDXUT_Realize)
    pDXUT_Realize->OnDestroyDevice(pUserContext);
}
//--------------------------------------------------------------------------------------
void TDXUT::OnDestroyDevice( void* pUserContext )
{
  if(pGE)
    pGE->OnDestroyDevice(pUserContext);

  flgWasDestroyEvent = true;
}
//--------------------------------------------------------------------------------------
TDXUT::TDXUT( TGraphicEngine * _pMDX )
: IDirectX_Realize(_pMDX)
{
  pDXUT_Realize = this;
}
//--------------------------------------------------------------------------------------
TDXUT::~TDXUT()
{
  pDXUT_Realize = NULL;
}
//--------------------------------------------------------------------------------------
HRESULT TDXUT::Init()
{
  HRESULT hr;
  flgWasLostEvent    = false;
  flgWasDestroyEvent = false;

  DXUTSetCallbackKeyboard(::OnKeyEvent);
  DXUTSetCallbackMouse(::OnMouseEvent,true);
  DXUTSetCallbackMsgProc( ::MsgProc );
  //----------------------------------------------------
  DXUTSetCallbackD3D9DeviceAcceptable( ::IsDeviceAcceptable );
  DXUTSetCallbackDeviceChanging( ::ModifyDeviceSettings );
  DXUTSetCallbackD3D9DeviceCreated( ::OnCreateDevice );
  DXUTSetCallbackD3D9DeviceReset( ::OnResetDevice );

  //----------------------------------------------------
  DXUTSetCallbackFrameMove( ::OnFrameMove );
  DXUTSetCallbackD3D9FrameRender( ::OnFrameRender );
  //----------------------------------------------------
  DXUTSetCallbackD3D9DeviceLost( ::OnLostDevice );
  DXUTSetCallbackD3D9DeviceDestroyed( ::OnDestroyDevice );
  //----------------------------------------------------
  DXUTSetCursorSettings( true, true );

  if(FAILED(DXUTInit( true, true ))) return false; // Parse the command line and show msgboxes
  DXUTSetHotkeyHandling( true, false, false );  // handle the defaul hotkeys
  
  V_RETURN(DXUTCreateWindow( L"TDXUT" ))
  DXUTCreateDevice( true, 1024, 768 );
  return S_OK;
}
//--------------------------------------------------------------------------------------
void TDXUT::Work()
{
  // вызов по таймеру
  DXUTRender3DEnvironment();
}
//--------------------------------------------------------------------------------------
int TDXUT::Done()
{
  int res = DXUTGetExitCode();
  DXUTShutdown();
  while(!flgWasLostEvent&&!flgWasDestroyEvent)
  {
    Sleep(eWaitDestroy);
  }
  pGE = NULL;
  return res;
}
//--------------------------------------------------------------------------------------
std::string TDXUT::GetError()
{
  return string();
}
//--------------------------------------------------------------------------------------
float TDXUT::GetFPS()
{
  return DXUTGetFPS();
}
//--------------------------------------------------------------------------------------
void* TDXUT::GetWndProc()
{
  return DXUTGetStaticWndProc();
}
//--------------------------------------------------------------------------------------
bool TDXUT::IsFullScreen()
{
  return !DXUTIsWindowed();
}
//--------------------------------------------------------------------------------------
void TDXUT::ToggleFullScreen()
{
  DXUTToggleFullScreen();
}
//--------------------------------------------------------------------------------------
HWND TDXUT::GetHWND()
{
  return DXUTGetHWND();
}
//--------------------------------------------------------------------------------------
void TDXUT::SetTitleWindow(const char* sTitle)
{
  HWND hWnd = GetHWND();
  SetWindowTextA(hWnd,sTitle); 
}
//--------------------------------------------------------------------------------------
void TDXUT::GetSizeWindow(int &w, int &h)
{
  w = DXUTGetWindowWidth();
  h = DXUTGetWindowHeight();
}
//--------------------------------------------------------------------------------------
D3DPRESENT_PARAMETERS* TDXUT::GetDevicePresentParameters9()
{
  return &(DXUTGetDeviceSettings().d3d9.pp);
}
//--------------------------------------------------------------------------------------
IDirect3D9* TDXUT::GetD3D9Object()
{
  return DXUTGetD3D9Object(); // Does not addref unlike typical Get* APIs
}
//--------------------------------------------------------------------------------------
IDirect3DDevice9* TDXUT::GetD3D9Device()
{
  return DXUTGetD3D9Device(); // Does not addref unlike typical Get* APIs
}
//--------------------------------------------------------------------------------------
HRESULT TDXUT::CaptureState9()
{
  return m_pManagerState.Push();
}
//--------------------------------------------------------------------------------------
HRESULT TDXUT::ApplyState9()
{
  return m_pManagerState.Pop();
}
//--------------------------------------------------------------------------------------
void TDXUT::GetCubeMapViewMatrix( DWORD dwFace, TMatrix16& m)
{
	D3DXMATRIX mdx = DXUTGetCubeMapViewMatrix(dwFace);
	MATRIX16_EQUAL_M_M(m,mdx);
}
//--------------------------------------------------------------------------------------
DXUTDeviceSettings TDXUT::GetDeviceSettings()
{
	return DXUTGetDeviceSettings();
}
//--------------------------------------------------------------------------------------
const D3DSURFACE_DESC* TDXUT::GetD3D9BackBufferSurfaceDesc()
{
  return DXUTGetD3D9BackBufferSurfaceDesc();
}
//--------------------------------------------------------------------------------------
