/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#pragma once

#include "IBinaryMarshaller.h"

#define REFLECTION_ATTRIBUTE

class TBinaryMarshaller : public IBinaryMarshaller<TBinaryMarshaller>
{
public:
  void ProtectedSerialize( int* p )
  {
    p [0] = 0;
  }
  void ProtectedSerialize( float* p )
  {
    p [0] = 0;
  }
};