/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderModelDX.h"


TLoaderModelDX::TLoaderModelDX( void* _m_pd3dDevice)
{
  m_pd3dDevice = (IDirect3DDevice9*)_m_pd3dDevice;
}
//--------------------------------------------------------------------------------
TLoaderModelDX::~TLoaderModelDX()
{
}
//--------------------------------------------------------------------------------
void* TLoaderModelDX::LoadMesh(const char* strPathPrimitives)
{
  return mMeshFile.Load(m_pd3dDevice,strPathPrimitives);
}
//--------------------------------------------------------------------------------
