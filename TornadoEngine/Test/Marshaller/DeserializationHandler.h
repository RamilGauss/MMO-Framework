/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "GeneratedClass.h"
#include "MyClass.h"
#include "BinaryMarshaller.h"

namespace nsBinary
{
  class TDeserializationHandler
  {
  public:
    // can be Handle for an every type
    static void Handle( TGeneratedClass* p )
    {
      TBinaryMarshaller::Deallocate( p );
    }

    static void Handle( TMyClass* p )
    {
      TBinaryMarshaller::Deallocate( p );
    }

    template < typename Type >
    static void Handle( Type* p )
    {
      // default: free all
      TBinaryMarshaller::Deallocate( p );
    }
  };
}
