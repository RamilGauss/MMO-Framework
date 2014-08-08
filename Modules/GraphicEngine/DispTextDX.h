/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef DispTextDXH
#define DispTextDXH

#include "DXUT.h"
#include <xstring>

class TDispTextDX
{
  IDirect3DDevice9* mpd3dDevice;
  ID3DXFont*        pFont;
  ID3DXSprite*      pTextSprite;

  bool bShow;

  int mX, mY;

  std::wstring mText;

public:
  
  TDispTextDX();
  ~TDispTextDX();

  // движок
  HRESULT CreateDevice(IDirect3DDevice9* pd3dDevice);
  HRESULT Reset();
  HRESULT Lost();
  HRESULT Destroy();
  void Render();

  // непосредственное использование
  void Show();
  void Hide();

  void SetPos(int x, int y);
  void SetText(std::wstring& str);
protected:
  HRESULT SetupFont();
};

#endif