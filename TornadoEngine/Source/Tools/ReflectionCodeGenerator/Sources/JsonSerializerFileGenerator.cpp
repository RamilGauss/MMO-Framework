/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializerFileGenerator.h"

using namespace nsReflectionCodeGenerator;

TJsonSerializerFileGenerator::TJsonSerializerFileGenerator()
{
  mJsonSerializer = mConfig->targetForCodeGeneration.implementation.jsonSerializer.get();
}
//----------------------------------------------------------------------------------------------------
// S - Type* p, Jobj& obj
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForSerialize( const std::string& namespaceWithType )
{
  return std::list<std::string>
  {
    namespaceWithType + "* " + s_TypeObject,
    "Jobj& obj"
  };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForDeserialize( const std::string& namespaceWithType )
{
  return std::list<std::string> 
  {
    namespaceWithType + "* " + s_TypeObject,
    "const json11::Json& json"
  };
}
//----------------------------------------------------------------------------------------------------