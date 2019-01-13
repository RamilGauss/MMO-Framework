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
  class TJsonSerializerHeaderFileGenerator : public TJsonSerializerFileGenerator
  {
    const std::list<std::string> s_JsonDecl =
    {
    "  typedef TJsonMaster::Jobj Jobj;",
    "public:",
    "  template <typename Type>",
    "  static void Serialize( Type* p, std::string& str );",
    "",
    "  template <typename Type>",
    "  static void Deserialize( Type*& p, std::string& str );",
    "",
    "  template <typename Type>",
    "  static void Fill( Type* p, std::string& str );",
    "private:",
    "  template <typename Type>",
    "  static void _Deserialize( Type*& p, std::string& str, bool checkPtr );",
    };
  public:
    virtual void Work() override;

  private:
    void AddDeclarations();

    void AddSerializeMethodDeclaration( std::string& namespaceWithType );
    void AddDeserializeMethodDeclaration( std::string& namespaceWithType );


  };
}

