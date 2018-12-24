/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>

#include "IncludeListGenerator.h"

class ICodeGenerator;

class TCodeGeneratorFactory
{
  TIncludeListGenerator mIncludeListGenerator;

public:
  ICodeGenerator* Get( std::string& name );
};