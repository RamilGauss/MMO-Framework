/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MeshMakerDX.h"
#include "BL_Debug.h"
#include <atlconv.h>

using namespace nsMeshStruct;

// vertex declaration
D3DVERTEXELEMENT9 VERTEX_DECL_BJ[] =
{
  { 0,  0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_POSITION, 0},
  { 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_NORMAL,   0},
  { 0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 0},
  D3DDECL_END()
};


TMeshMakerDX::TMeshMakerDX()
{

}
//-------------------------------------------------------------
TMeshMakerDX::~TMeshMakerDX()
{

}
//-------------------------------------------------------------
ID3DXMesh* TMeshMakerDX::Load(IDirect3DDevice9* pd3dDevice, const char* strFilename)
{
	const char* sFind = strstr(strFilename,".");
	if(sFind==NULL) return NULL;
	sFind++;
	// определить расширение файла
  // obj или bj
	while(1)
	{
		if(strcmp(sFind,"obj")==0)
			return LoadFrom(pd3dDevice, strFilename,&mMeshFromObj);
		else if(strcmp(sFind,"bj")==0)
			return LoadFrom(pd3dDevice, strFilename,&mMeshFromBj);

		sFind = strstr(sFind,".");
		if(sFind==NULL) return NULL;
		sFind++;
	}

  return NULL;
}
//-------------------------------------------------------------
ID3DXMesh* TMeshMakerDX::LoadFrom(IDirect3DDevice9* pd3dDevice, const char* strFilename, IMeshFile* pMeshFile)
{
  VERTEX* pVertex;
  unsigned int cntV;
  unsigned int* pIndex;
  unsigned int cntI;
  pMeshFile->Load(strFilename,pVertex,cntV,pIndex,cntI);
  // массив атрибутов
  unsigned int attributesCnt = cntI/3;
  unsigned int* pArrAttributes = new unsigned int[attributesCnt];
  memset(pArrAttributes, 0, attributesCnt*sizeof(unsigned int));
  //------------------------------------------------------
  HRESULT hr;
  // Create the encapsulated mesh
  ID3DXMesh* pMesh = NULL;
  V( D3DXCreateMesh( cntI / 3, cntV,
    D3DXMESH_MANAGED | D3DXMESH_32BIT, VERTEX_DECL_BJ,
    pd3dDevice, &pMesh ) );

  // Copy the vertex data
  VERTEX* pVertexMesh;
  V( pMesh->LockVertexBuffer( 0, ( void** )&pVertexMesh ) );
  memcpy( pVertexMesh, pVertex, cntV*sizeof( VERTEX ) );
  pMesh->UnlockVertexBuffer();

  // Copy the index data
  DWORD* pIndexMesh;
  V( pMesh->LockIndexBuffer( 0, ( void** )&pIndexMesh ) );
  memcpy( pIndexMesh, pIndex, cntI * sizeof( unsigned int ) );
  pMesh->UnlockIndexBuffer();

  // Copy the attribute data
  DWORD* pSubset;
  V( pMesh->LockAttributeBuffer( 0, &pSubset ) );
  memcpy( pSubset, pArrAttributes, attributesCnt * sizeof( unsigned int ) );
  pMesh->UnlockAttributeBuffer();

  DWORD* aAdjacency = new DWORD[pMesh->GetNumFaces() * 3];
  if( aAdjacency != NULL )
  {
    V( pMesh->GenerateAdjacency( 1e-6f, aAdjacency ) );
    V( pMesh->OptimizeInplace( D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE, aAdjacency, NULL, NULL, NULL ) );

    SAFE_DELETE_ARRAY( aAdjacency );
  }
  else
    SAFE_RELEASE(pMesh);


  SAFE_DELETE_ARRAY(pVertex);
  SAFE_DELETE_ARRAY(pIndex);
  SAFE_DELETE_ARRAY(pArrAttributes);
  
  return pMesh;
}
//-------------------------------------------------------------
bool TMeshMakerDX::SaveAsBj(const char* strFilename,ID3DXMesh* pMesh)
{
  VERTEX* pVertex      = NULL;
  unsigned int cntV    = pMesh->GetNumVertices();
  unsigned int* pIndex = NULL;
  unsigned int cntI    = pMesh->GetNumFaces()*3;

  HRESULT hr;

  V( pMesh->LockVertexBuffer( 0, ( void** )&pVertex ) );
  V( pMesh->LockIndexBuffer( 0, ( void** )&pIndex ) );

  bool res = mMeshFromBj.Save(strFilename, pVertex, cntV, pIndex, cntI);
  
  pMesh->UnlockVertexBuffer();
  pMesh->UnlockIndexBuffer();
  
  return res;
}
//-------------------------------------------------------------