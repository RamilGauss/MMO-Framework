/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BL_Debug.h"
#include "StateManagerD3D9.h"
#include "DXUT.h"


TStateManagerD3D9::TStateManagerD3D9()
{
  m_pStateBlock = NULL;
}
//--------------------------------------------------------------------------
TStateManagerD3D9::~TStateManagerD3D9()
{

}
//--------------------------------------------------------------------------
HRESULT TStateManagerD3D9::Reset(IDirect3DDevice9* pd3d9Device)
{
  HRESULT hr;
  V_RETURN( pd3d9Device->CreateStateBlock( D3DSBT_ALL, &m_pStateBlock ) );
  return S_OK;
}
//--------------------------------------------------------------------------
void TStateManagerD3D9::Lost()
{
  SAFE_RELEASE( m_pStateBlock );
}
//--------------------------------------------------------------------------
HRESULT TStateManagerD3D9::Push()
{
  HRESULT hr;
  V_RETURN( m_pStateBlock->Capture() );
  return S_OK;
}
//--------------------------------------------------------------------------
HRESULT TStateManagerD3D9::Pop()
{
  HRESULT hr;
  V_RETURN( m_pStateBlock->Apply() );
  return S_OK;
}
//--------------------------------------------------------------------------
