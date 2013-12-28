/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MeshMakerDXH
#define MeshMakerDXH

#include "TypeDef.h"

#include "DXUT.h"
#include "MeshFileBj.h"
#include "MeshFileObj.h"

// открыть класс для использования при конвертировании меша

class GRAPHIC_ENGINE_EI TMeshMakerDX
{
  TMeshFileBj mMeshFromBj;
  TMeshFileObj mMeshFromObj;

public:
  
  TMeshMakerDX();
  virtual ~TMeshMakerDX();

  virtual ID3DXMesh* Load(IDirect3DDevice9* pd3dDevice, const char* strFilename);

  virtual bool SaveAsBj(const char* strFilename,ID3DXMesh* pMesh);
protected:

  ID3DXMesh* LoadFrom(IDirect3DDevice9* pd3dDevice, const char* strFilename, IMeshFile* pMeshFile);
  //ID3DXMesh* LoadFromBj(IDirect3DDevice9* pd3dDevice, const char* strFilename);


};

#endif
