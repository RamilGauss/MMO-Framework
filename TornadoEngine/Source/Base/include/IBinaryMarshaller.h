/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "TypeDef.h"

template<typename Inherited>
class DllExport IBinaryMarshaller
{
public:
  template <typename T>
  void Serialize(T* t)
  {
    ((Inherited*)this)->ProtectedSerialize( t );
  }
};