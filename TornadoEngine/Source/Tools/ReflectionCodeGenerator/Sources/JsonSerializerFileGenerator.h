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
  class TJsonSerializerFileGenerator : public IFileGenerator
  {
  protected:
    const std::string sSerialzeMethod = "_Serialize";
    const std::string sDeserialzeMethod = "_Deserialize";

    const std::string sTypeObject = "p";

    // S - Type* p, Jobj& obj
    std::list<std::string> GetParamListForSerialize( const std::string& namespaceWithType ); 
    std::list<std::string> GetParamListForDeserialize( const std::string& namespaceWithType ); 

  };
}

