/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "IFileGenerator.h"

namespace nsReflectionCodeGenerator
{
  class TIncludeListFileGenerator : public IFileGenerator
  {
  public:
    virtual void Work() override;

  private:
    void AddIncludes();
  };
}