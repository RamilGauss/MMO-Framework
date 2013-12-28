/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MeshFileObj.h"
#include "LoadFromHDD.h"
#include "BL_Debug.h"
#include <fstream>
#include <list>
#include <map>
#include <boost/foreach.hpp>

using namespace nsMeshStruct;
using namespace nsStruct3D;
using namespace std;

TMeshFileObj::TMeshFileObj()
{
}
//-----------------------------------------------------------------------------------
TMeshFileObj::~TMeshFileObj()
{

}
//-----------------------------------------------------------------------------------
bool TMeshFileObj::Load(const char* strFilename, 
            VERTEX*&      pVertex, unsigned int& cntV,
            unsigned int*& pIndex, unsigned int& cntI)
{
  typedef map<unsigned int, TVector2> TMapUintVector2;
  typedef map<unsigned int, TVector3> TMapUintVector3;
  typedef map<VERTEX, unsigned int>   TMapVertexUint;
  typedef list<VERTEX>                TListVertex;
  
  typedef TMapUintVector2::iterator TMapUV2_It;
  typedef TMapUintVector3::iterator TMapUV3_It;
  typedef TMapVertexUint::iterator  TMapVU_It;
  typedef TListVertex::iterator     TListV_It;
  
  typedef TMapUintVector2::value_type TMapUV2_v;
  typedef TMapUintVector3::value_type TMapUV3_v;
  typedef TMapVertexUint::value_type  TMapVU_v;

  TMapUintVector3 mapPositions;
  TMapUintVector2 mapTexCoords;
  TMapUintVector3 mapNormals;

  TMapVertexUint mapVertex;
  TListVertex    listVertex;

  // File input
  wchar_t strCommand[256] = {0};
  wifstream InFile( strFilename );
  if( !InFile )
    return false;

  for(;;)
  {
    InFile >> strCommand;
    if( !InFile )
      break;

    if( 0 == wcscmp( strCommand, L"#" ) )
    {
      // Comment
    }
    else if( 0 == wcscmp( strCommand, L"v" ) )
    {
      // Vertex Position
      float x, y, z;
      InFile >> x >> y >> z;
      mapPositions.insert( TMapUV3_v( mapPositions.size(),TVector3( x, y, z ) ) );
    }
    else if( 0 == wcscmp( strCommand, L"vt" ) )
    {
      // Vertex TexCoord
      float u, v;
      InFile >> u >> v;
      mapTexCoords.insert( TMapUV2_v( mapTexCoords.size(),TVector2( u, v ) ) );
    }
    else if( 0 == wcscmp( strCommand, L"vn" ) )
    {
      // Vertex Normal
      float x, y, z;
      InFile >> x >> y >> z;
      mapNormals.insert( TMapUV3_v( mapNormals.size() ,TVector3( x, y, z ) ) );
    }
    else if( 0 == wcscmp( strCommand, L"f" ) )
    {
      const unsigned char cntVertex = 4;
      // Face
      unsigned int iPosition, iTexCoord, iNormal;
      VERTEX vertex[cntVertex];// копить точки
      // 05.03.2013 - Gauss добавил конвертацию из 4 точек в 3 точки
      unsigned char iFace = 0;
      while(InFile.peek()!='\n')
      {
        BL_ASSERT(iFace<cntVertex);
        InFile >> iPosition;
        vertex[iFace].position = mapPositions[ iPosition - 1 ];
        if( '/' == InFile.peek() )
        {
          InFile.ignore();
          if( '/' != InFile.peek() )
          {
            // Optional texture coordinate
            InFile >> iTexCoord;
            vertex[iFace].texcoord = mapTexCoords[ iTexCoord - 1 ];
          }
          if( '/' == InFile.peek() )
          {
            InFile.ignore();
            // Optional vertex normal
            InFile >> iNormal;
            vertex[iFace].normal = mapNormals[ iNormal - 1 ];
          }
        }
        // проверить на дублирование вершин в массиве
        TMapVU_It fit = mapVertex.find(vertex[iFace]);
        if(fit==mapVertex.end())
          mapVertex.insert(TMapVU_v(vertex[iFace],mapVertex.size()));

        iFace++;
      }
      // (0,1,2,3)->(0,1,3)+(1,2,3)
      if(iFace>3)
      {
        listVertex.push_back(vertex[0]);
        listVertex.push_back(vertex[1]);
        listVertex.push_back(vertex[3]);
        listVertex.push_back(vertex[1]);
        listVertex.push_back(vertex[2]);
        listVertex.push_back(vertex[3]);
      }
      else
      {
        listVertex.push_back(vertex[0]);
        listVertex.push_back(vertex[1]);
        listVertex.push_back(vertex[2]);
      }
    }
    else if( 0 == wcscmp( strCommand, L"mtllib" ) )
    {
      // Material library
    }
    else if( 0 == wcscmp( strCommand, L"usemtl" ) )
    {
      // Material
    }
    else
    {
      // Unimplemented or unrecognized command
    }
    InFile.ignore( 1000, '\n' );
  }

  // Cleanup
  InFile.close();

  // создать 
  cntV    = mapVertex.size();
  pVertex = new VERTEX[cntV];
  cntI    = listVertex.size(); 
  pIndex  = new unsigned int[cntI];
  // найти по вершине индекс
  unsigned int iIndex = 0;
  BOOST_FOREACH(VERTEX& vertex,listVertex)
  {
    TMapVU_It fit = mapVertex.find(vertex);
    if(fit!=mapVertex.end())
    {
      pIndex[iIndex] = fit->second;
      iIndex++;
    }
    else BL_FIX_BUG();
  }
  // копировать вершины
  BOOST_FOREACH(TMapVertexUint::value_type& bit,mapVertex)
    pVertex[bit.second] = bit.first;

  return true;
}
//-----------------------------------------------------------------------------------
bool TMeshFileObj::Save(const char* strFilename, 
                  VERTEX*       pVertex, unsigned int cntV,
                  unsigned int* pIndex,  unsigned int cntI) 
{
  BL_FIX_BUG();// пока не умею сохран€ть
  return false;
}
//-----------------------------------------------------------------------------------
void TMeshFileObj::Done()
{
}
//-----------------------------------------------------------------------------------
