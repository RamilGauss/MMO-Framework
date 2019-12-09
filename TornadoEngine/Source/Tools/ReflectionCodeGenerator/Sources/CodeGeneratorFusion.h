/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ICodeGenerator.h"

namespace nsReflectionCodeGenerator
{
  class TCodeGeneratorFusion
  {
    ICodeGenerator::TPairList mForDump;

  public:
    void Work();
  private:
    void Collect();
    void Dump();
    void CollectFromIncludeList();
    void CollectFromJson();
    void CollectFromBinary();
  };
}