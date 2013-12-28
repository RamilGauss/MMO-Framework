/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IDirectX_RealizeH
#define IDirectX_RealizeH

#include <windows.h>
#include "Struct3D.h"
#include "DXUT.h"

class TGraphicEngine;

class IDirectX_Realize
{
protected:

  TGraphicEngine * pGE;

public:
  IDirectX_Realize(TGraphicEngine * _pGE){pGE=_pGE;}
  virtual ~IDirectX_Realize(){};

  virtual void* GetWndProc() = 0;
  virtual bool  IsFullScreen() = 0;
  virtual void  ToggleFullScreen() = 0;
  virtual void  SetTitleWindow(const char* sTitle) = 0;
  virtual void  GetSizeWindow(int &w, int &h) = 0;

  virtual HRESULT Init() = 0;
  virtual void    Work() = 0;
  virtual int     Done()  = 0;

  virtual float   GetFPS() = 0;

  virtual HWND    GetHWND() = 0;
  
  virtual D3DPRESENT_PARAMETERS* GetDevicePresentParameters9() = 0;
  virtual IDirect3D9*       GetD3D9Object() = 0;
  virtual IDirect3DDevice9* GetD3D9Device() = 0;

  virtual HRESULT CaptureState9() = 0;
  virtual HRESULT ApplyState9() = 0;

	virtual void GetCubeMapViewMatrix( DWORD dwFace, nsStruct3D::TMatrix16& m ) = 0;

	virtual DXUTDeviceSettings GetDeviceSettings() = 0;
  
  virtual const D3DSURFACE_DESC* GetD3D9BackBufferSurfaceDesc() = 0;

protected:
};


#endif
