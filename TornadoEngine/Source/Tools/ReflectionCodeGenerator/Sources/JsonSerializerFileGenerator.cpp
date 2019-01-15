/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializerFileGenerator.h"

using namespace nsReflectionCodeGenerator;

// S - Type* p, Jobj& obj
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForSerialize( const std::string& namespaceWithType )
{
  return std::list<std::string>
  {
    namespaceWithType + "* p",
    "Jobj& obj"
  };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForDeserialize( const std::string& namespaceWithType )
{
  return std::list<std::string> 
  {
    namespaceWithType + "* p",
    "const json11::Json& json"
  };
}
//----------------------------------------------------------------------------------------------------