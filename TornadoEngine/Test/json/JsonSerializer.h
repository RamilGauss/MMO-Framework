/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include "TestStruct.h"
#include "TestClass.h"
#include "JsonMaster.h"

#include "json11.h"

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
private:
  static void _Serialize( TBaseStruct* p, Jobj& obj );
  static void _Deserialize( TBaseStruct* p, const json11::Json& json );

  static void _Serialize( TTestStruct* p, Jobj& obj );
  static void _Deserialize( TTestStruct* p, const json11::Json& json );

  static void _Serialize( TTestClass* p, Jobj& obj );
  static void _Deserialize( TTestClass* p, const json11::Json& json );
private:
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
  std::string err;
  auto json = json11::Json::parse( str, err );
  if ( err.size() > 0 )
    return;
  p = p ? p : new Type();

  _Deserialize( p, json.object_items() );
}
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Fill( Type* p, std::string& str )
{
  std::string err;
  auto json = json11::Json::parse( str, err );
  if ( err.size() > 0 )
    return;

  _Deserialize( p, json.object_items() );
}
//------------------------------------------------------------------------------------
