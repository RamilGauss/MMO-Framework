/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"

namespace nsReflectionCodeGenerator
{
  class TJsonSerializerSourceFileGenerator : public TJsonSerializerFileGenerator
  {

  public:
    virtual void Work() override;

  private:
    void AddImplementations();

    void AddSerializeMethodImplementation( TTypeInfo* p );
    void AddDeserializeMethodImplementation( TTypeInfo* p );
 
  };
}
