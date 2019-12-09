/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IFileGenerator.h"

namespace nsReflectionCodeGenerator
{
  class TJsonSerializerFileGenerator : public IFileGenerator
  {
  protected:
    TJsonSerializerGeneratorConfig* mJsonSerializer;

    const std::string s_Jobj = "Jobj";
    const std::string s_Jarr = "Jarr";
    const std::string sSerializeMethod = "_Serialize";
    const std::string sDeserializeMethod = "_Deserialize";

    // S - Type* p, Jobj& obj
    std::list<std::string> GetParamListForSerialize( const std::string& namespaceWithType ); 
    std::list<std::string> GetParamListForDeserialize( const std::string& namespaceWithType ); 

    TJsonSerializerFileGenerator();

  };
}

