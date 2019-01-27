/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include <vector>
#include <string>

namespace nsReflectionCodeGenerator
{
  namespace nsManual
  {
    const std::map<std::string, std::vector<std::string>> g_Manual =
    {
      { "1. SHOULD BE",
        {
          "struct or class",
          "with many inheritances",
          "other types with reflection attribute",
          "in many name spaces",
          "pointer to reflective types (is not equal null!!!)",
          "public members only",
          "built in types",
          "std: map, set, vector, list",
        }
      },
      { "2. PROHIBITED",
        {
          "typedefs for types",
          "void*",
          "std::function or other Lambda",
        }
      },
      { "3. IGNORE",
        {
          "static variables",
          "any methods (virtual, template, static, operators)",
          "constructors and destructor",
          "friends",
          "no template members, such as T<int>",
        }
      },
      { "4. USING",
        {
          "Path to JSON file with configure",
          "example: CodeGenerator.exe config.json",
        }
      }
    };
  }
}
