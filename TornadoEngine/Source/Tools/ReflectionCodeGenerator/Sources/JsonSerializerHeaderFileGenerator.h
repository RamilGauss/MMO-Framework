/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include "fmt/core.h"

namespace nsReflectionCodeGenerator
{
  class TJsonSerializerHeaderFileGenerator : public TJsonSerializerFileGenerator
  {
    const std::list<std::string> s_JsonDecl =
    {
      fmt::format( "  typedef TJsonMaster::Jobj {};", s_Jobj ), 
      fmt::format( "  typedef TJsonMaster::Jarr {};", s_Jarr ), 
      "public:",
      "  template <typename Type>",
      "  static void Serialize( Type* p, std::string& str );",
      "  template <typename Type>",
      "  static void Deserialize( Type*& p, std::string& str );",
      "  template <typename Type>",
      "  static void Fill( Type* p, std::string& str );",
      "private:",
      "  template <typename Type>",
      "  static void _Deserialize( Type*& p, std::string& str, bool checkPtr );",
    };

    const std::list<std::string> s_JsonImpl = 
    {
      "//------------------------------------------------------------------------------------------------------------",
      "template <typename Type>",
      fmt::format( "static void {}::Serialize( Type* p, std::string& str )", mJsonSerializer->className ),
      "{",
      "  Jobj obj;",
      fmt::format( "  {}( p, obj );", sSerializeMethod ),
      "  json11::Json json( obj );",
      "  str = json.dump();",
      "}",
      "//------------------------------------------------------------------------------------------------------------",
      "template <typename Type>",
      fmt::format( "static void {}::Deserialize( Type*& p, std::string& str )", mJsonSerializer->className ),
      "{",
      "  _Deserialize( p, str, true );",
      "}",
      "//------------------------------------------------------------------------------------------------------------",
      "template <typename Type>",
      fmt::format( "static void {}::Fill( Type* p, std::string& str )", mJsonSerializer->className ),
      "{",
      "  _Deserialize( p, str, false );",
      "}",
      "//------------------------------------------------------------------------------------------------------------",
      "template <typename Type>",
      fmt::format( "static void {}::_Deserialize( Type*& p, std::string& str, bool checkPtr )", mJsonSerializer->className ),
      "{",
      "  std::string err;",
      "  auto json = json11::Json::parse( str, err, json11::JsonParse::COMMENTS );",
      "  if ( err.size() > 0 )",
      "    return;",
      "",
      "  if ( checkPtr )",
      "    p = p ? p : new Type();",
      "",
      fmt::format( "  {}( p, json.object_items() );", sDeserializeMethod ),
      "}",
    };

  public:
    virtual void Work() override;

  private:
    void AddDeclarations();

    void AddSerializeMethodDeclaration( std::string& namespaceWithType );
    void AddDeserializeMethodDeclaration( std::string& namespaceWithType );


  };
}

