/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DXUT_ClassH
#define DXUT_ClassH

#include "DXUT.h"
#include "DXUTcamera.h"
#include "DXUTsettingsdlg.h"
#include "SDKmisc.h"
#include "IDirectX_Realize.h"
#include <string>
#include "DXUTgui.h"
#include "StateManagerD3D9.h"

class TDXUT : public IDirectX_Realize
{
  enum{eWaitDestroy=40};

  bool flgWasLostEvent;
  bool flgWasDestroyEvent;

  TStateManagerD3D9 m_pManagerState;

public:
  TDXUT(TGraphicEngine * pMDX );
  virtual ~TDXUT();

  virtual HRESULT CaptureState9();
  virtual HRESULT ApplyState9();

  virtual void* GetWndProc();
  virtual bool IsFullScreen();
  virtual void ToggleFullScreen();
  virtual void SetTitleWindow(const char* sTitle);
  virtual void GetSizeWindow(int &w, int &h);

  virtual HRESULT Init();
  virtual void Work();
  virtual int Done();

  virtual std::string GetError();
  virtual float GetFPS();

  virtual HWND GetHWND();
  
  virtual D3DPRESENT_PARAMETERS* GetDevicePresentParameters9();

  virtual IDirect3D9*       GetD3D9Object();
  virtual IDirect3DDevice9* GetD3D9Device();

	virtual void GetCubeMapViewMatrix( DWORD dwFace, nsStruct3D::TMatrix16& m);

	virtual DXUTDeviceSettings GetDeviceSettings();

  virtual const D3DSURFACE_DESC* GetD3D9BackBufferSurfaceDesc();

protected:

  friend bool CALLBACK IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext );
  friend bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext );
  friend void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext );
  friend LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing, void* pUserContext );
  //friend void CALLBACK OnGUIEvent( UINT nEvent, int nControlID, CDXUTControl* pControl, void* pUserContext );
  friend void CALLBACK OnKeyEvent( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext );
  friend void CALLBACK OnMouseEvent( UINT state, bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown, bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta, int xPos, int yPos, void* pUserContext );

  // must
  friend void CALLBACK OnLostDevice( void* pUserContext );   
  friend void CALLBACK OnDestroyDevice( void* pUserContext );
  friend void CALLBACK OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );
  friend HRESULT CALLBACK OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext );
  friend HRESULT CALLBACK OnResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext );
  //------------------------------------------------------------------------------------------------------
  bool IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext );
  bool ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext );
  HRESULT OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext );
  HRESULT OnResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext );
  void OnFrameMove( double fTime, float fElapsedTime, void* pUserContext );
  void OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );
  LRESULT MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing, void* pUserContext );
  void OnLostDevice( void* pUserContext );
  void OnDestroyDevice( void* pUserContext );
  void OnKeyEvent( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext );
  void OnMouseEvent( UINT state, bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown, bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta, int xPos, int yPos, void* pUserContext );

};




#endif