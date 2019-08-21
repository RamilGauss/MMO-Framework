/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include "TypeDef.h"

#include "IComponent.h"
#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"

namespace nsECSFramework
{
  class DllExport TComplexType
  {
  public:
    TColanderVector<IComponent*> parts;
    std::list<unsigned char> mComponentTypeIdentifierList;

    bool operator < ( const TComplexType& other ) const
    {
      //я знаю, что данная операция не меняет объекты, но нужен не константный объект, потому что массив не поддерживает константный объект
      //hack
      auto pThis = (TComplexType*)this;
      auto pOther = (TComplexType*)& other;

      for ( auto& index : mComponentTypeIdentifierList )
      {
        if ( pThis->parts.operator[]( index )->IsEqual( pOther->parts.operator[]( index ) ) )
          continue;
        return pThis->parts.operator[]( index )->IsLess( pOther->parts.operator[]( index ) );
      }
      //BL_FIX_BUG();
      return false;
    }

    void Done()
    {
      for ( auto& index : mComponentTypeIdentifierList )
        parts.operator[]( index ) = nullptr;
      mComponentTypeIdentifierList.clear();
    }
  };
}