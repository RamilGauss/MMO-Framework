/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
              "pointer to reflective types",
              "public members only",
              "built-in types",
              "std: map, set, vector, list",
              "std: shared_ptr, auto_ptr, weak_ptr, unique",
              "class UnpackHandler with static void Handle( Type* p )",
              "Custimize or out sources of other serializators: use full namespace:\n\t\t namespace::MemberType memberName;",
            }
          },
          { "2. PROHIBITED",
            {
              "void*",
              "std::function or other Lambda",
              "other variants of use std::vector<bool> (cause it is not standart container)",
              "bool as key in std::set and std::map",
              "object, pointer and smart_pointer as key in std::set and std::map",
            }
          },
          { "3. IGNORED",
            {
              "typedefs for types",
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
              "example: ReflectionCodeGenerator.exe config.json",
            }
          }
        };
    }
}
