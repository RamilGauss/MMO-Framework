/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MeshStructH
#define MeshStructH

#include "Struct3D.h"

// бинарный формат хранения Mesh
// только вершины (координаты, нормали, текстурные координаты) и индексы
namespace nsMeshStruct
{
  // Vertex format
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct VERTEX
  {
    nsStruct3D::TVector3 position;
    nsStruct3D::TVector3 normal;
    nsStruct3D::TVector2 texcoord;

    bool operator == ( const VERTEX& v) const
    {
      if((position!=v.position)||
         (normal  !=v.normal  )||
         (texcoord!=v.texcoord))
         return false;
      return true;
    }
    bool operator != ( const VERTEX& v) const
    {
      if((position!=v.position)||
         (normal  !=v.normal  )||
         (texcoord!=v.texcoord))
        return true;
      return false;
    }
    bool operator < ( const VERTEX& v) const
    {
      if(position < v.position) return true;// высший разряд
      else if(position > v.position) return false;
      //-------------------------------------------
      if(normal < v.normal) return true;
      else if(normal > v.normal) return false;
      //-------------------------------------------
      if(texcoord < v.texcoord) // низший разряд
        return true;

      return false;
    }
    bool operator > ( const VERTEX& v) const
    {
      if(position > v.position) return true;// высший разряд
      else if(position < v.position) return false;
      //-------------------------------------------
      if(normal > v.normal) return true;
      else if(normal < v.normal) return false;
      //-------------------------------------------
      if(texcoord > v.texcoord) // низший разряд
        return true;

      return false;
    }

  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
}


#endif
