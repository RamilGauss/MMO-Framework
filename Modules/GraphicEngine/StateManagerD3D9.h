/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StateManagerD3D9H
#define StateManagerD3D9H

#include <winerror.h>

struct IDirect3DDevice9;
struct IDirect3DStateBlock9;

class TStateManagerD3D9
{

  IDirect3DStateBlock9* m_pStateBlock;

public:
  TStateManagerD3D9();
  virtual ~TStateManagerD3D9();


  HRESULT Reset(IDirect3DDevice9* pd3d9Device);
  void Lost();
  HRESULT Push();
  HRESULT Pop();

};

#endif