/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LoaderModelDXTestH
#define LoaderModelDXTestH

#include "ILoaderModelGE.h"
#include "MeshMakerDX.h"

class TLoaderModelDX : public ILoaderModelGE
{
protected:
  IDirect3DDevice9* m_pd3dDevice;
  TMeshMakerDX mMeshFile;

public:
  TLoaderModelDX(void* _m_pd3dDevice);
  virtual ~TLoaderModelDX();

protected:
  virtual void* LoadMesh(const char* strPathPrimitives);
};


#endif