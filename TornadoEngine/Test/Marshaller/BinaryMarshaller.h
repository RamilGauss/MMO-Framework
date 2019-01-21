/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ContainerRise.h"

namespace nsBinary
{
  class TBinaryMarshaller
  {
    static bool flgNeedInit;
    static void Init();
  public:
    template <typename Type>
    static void Serialize( Type* p, TContainerRise& c );

    static void Deserialize( TContainerRise& c );

    template <typename Type>
    static void Deallocate( Type* p );
  private:

  };
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Serialize( Type* p, TContainerRise& c )
  {

  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Deallocate( Type* p )
  {

  }
  //-----------------------------------------------------------------------------
}

