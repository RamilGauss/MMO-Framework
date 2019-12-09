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
    // can be Handle for an every type
    //static void Handle( TTestStruct* p )
    //{
    //  TBinaryMarshaller::Deallocate( p );
    //}

    //static void Handle( TBaseStruct* p )
    //{
    //  TBinaryMarshaller::Deallocate( p );
    //}

    template <typename Type>
    static void Handle( Type* p )
    {
      // default: free all
      //AddToECS( p );

      TBinaryMarshaller::Deallocate( p );
    }
  };
}
