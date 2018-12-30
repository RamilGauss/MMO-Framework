/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ICodeGenerator.h"

namespace nsReflectionCodeGenerator
{
  class TBinaryMarshallerGenerator : public ICodeGenerator
  {
  public:
    TBinaryMarshallerGenerator() : ICodeGenerator( "BinaryMarshallerGenerator" ) { }

    virtual void Work() override;
  };
}