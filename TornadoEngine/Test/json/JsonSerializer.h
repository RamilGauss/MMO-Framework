/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include "JsonMaster.h"
#include "json11.h"
#include "IncludeList.h"

class TJsonSerializer
{
  typedef TJsonMaster::Jobj Jobj;
public:
  template <typename Type>
  static void Serialize( Type* p, std::string& str );

  template <typename Type>
  static void Deserialize( Type*& p, std::string& str );

  template <typename Type>
  static void Fill( Type* p, std::string& str );
private:// enumerate all structs and classes
  static void _Serialize( TBaseStruct* p, Jobj& obj );
  static void _Deserialize( TBaseStruct* p, const json11::Json& json );

  static void _Serialize( TTestStruct* p, Jobj& obj );
  static void _Deserialize( TTestStruct* p, const json11::Json& json );

  static void _Serialize( TTestClass* p, Jobj& obj );
  static void _Deserialize( TTestClass* p, const json11::Json& json );
private:
  template <typename Type>
  static void _Deserialize( Type*& p, std::string& str, bool checkPtr );
};
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Serialize( Type* p, std::string& str )
{
  Jobj obj;
  _Serialize( p, obj );
  json11::Json json( obj );
  str = json.dump();
}
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Deserialize( Type*& p, std::string& str )
{
  _Deserialize( p, str, true );
}
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Fill( Type* p, std::string& str )
{
  _Deserialize( p, str, false );
}
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::_Deserialize( Type*& p, std::string& str, bool checkPtr )
{
  std::string err;
  auto json = json11::Json::parse( str, err, json11::JsonParse::COMMENTS );
  if ( err.size() > 0 )
    return;
  if ( checkPtr )
    p = p ? p : new Type();

  _Deserialize( p, json.object_items() );
}
//------------------------------------------------------------------------------------
