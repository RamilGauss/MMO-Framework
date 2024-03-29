/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BinaryMarshaller.h"

namespace nsBinary
{
  class TUnpackHandler
  {
  public:
    template <typename Type>
    static void Handle( Type* p )
    {
      TBinaryMarshaller::Deallocate( p );
    }
  };
}
