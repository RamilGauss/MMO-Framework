/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GUI_DescWindowH
#define GUI_DescWindowH

#ifdef WIN32
  #include <windows.h>
  #include <d3d9types.h>
  #include <d3d9.h>
#else 

#endif

struct TGUIDescWindow
{
#ifdef WIN32
  HWND                   hwnd;
  IDirect3D9*            pD3D;         
  IDirect3DDevice9*      pD3DDevice;   
  D3DPRESENT_PARAMETERS* pD3DPP;
#else // MacOS

#endif
  bool windowed;
};

struct TGUIDescToggleWindow
{
#ifdef WIN32
  HWND hWnd;
#else
#endif
  int width;
  int height;
  bool fullScreen;
};


#endif