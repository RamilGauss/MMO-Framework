/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeGUI_DescWindow_DX9H
#define PrototypeGUI_DescWindow_DX9H

#include <windows.h>

struct IDirect3D9;
struct IDirect3DDevice9;
struct D3DPRESENT_PARAMETERS;

struct TGUIDescWindow
{
  HWND                   hwnd;
  IDirect3D9*            pD3D;         
  IDirect3DDevice9*      pD3DDevice;   
  D3DPRESENT_PARAMETERS* pD3DPP;

  bool windowed;
};

#endif