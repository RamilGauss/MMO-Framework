/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DispTextDX.h"
#include "SDKmisc.h"

using namespace std;

TDispTextDX::TDispTextDX()
{
  mpd3dDevice = NULL;
  pFont = NULL;
  pTextSprite = NULL;
  bShow = true;

  mX = 5;
  mY = 5;
}
//-----------------------------------------------------
TDispTextDX::~TDispTextDX()
{

}
//-----------------------------------------------------
HRESULT TDispTextDX::CreateDevice(IDirect3DDevice9* pd3dDevice)
{
  HRESULT hr;
  mpd3dDevice = pd3dDevice;

  V_RETURN(SetupFont());

  return S_OK;
}
//-----------------------------------------------------
void TDispTextDX::Show()
{
  bShow = true;
}
//-----------------------------------------------------
void TDispTextDX::Hide()
{
  bShow = false;
}
//-----------------------------------------------------
void TDispTextDX::SetPos(int x, int y)
{
  mX = x;
  mY = y;
}
//-----------------------------------------------------
void TDispTextDX::SetText(wstring& str)
{
  mText = str;
}
//-----------------------------------------------------
void TDispTextDX::Render()
{
  if(bShow==false) return;

  CDXUTTextHelper txtHelper( pFont, pTextSprite, 15 );

  txtHelper.Begin();
  txtHelper.SetInsertionPos( mX, mY );
  txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 0.0f, 1.0f ) );
  txtHelper.DrawTextLine( mText.data() );

  txtHelper.End();
}
//-----------------------------------------------------
HRESULT TDispTextDX::SetupFont()
{
  HRESULT hr;
  V_RETURN( D3DXCreateFont( mpd3dDevice, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET,
    OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
    L"Arial", &pFont ) );

  return S_OK;
}
//-----------------------------------------------------
HRESULT TDispTextDX::Lost()
{
  HRESULT hr;
  if( pFont )
    V_RETURN( pFont->OnLostDevice());
  SAFE_RELEASE( pTextSprite );
  return S_OK;
}
//-----------------------------------------------------
HRESULT TDispTextDX::Destroy()
{
  SAFE_RELEASE( pFont );
  return S_OK;
}
//-----------------------------------------------------
HRESULT TDispTextDX::Reset()
{
  HRESULT hr;
  if( pFont )
    V_RETURN( pFont->OnResetDevice() );
  V_RETURN( D3DXCreateSprite( mpd3dDevice, &pTextSprite ) );
  return S_OK;
}
//-----------------------------------------------------
