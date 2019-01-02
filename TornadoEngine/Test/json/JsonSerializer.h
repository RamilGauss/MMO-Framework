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
#include "JsonPushMaster.h"
#include "JsonPopMaster.h"

#include "json11.h"

class TJsonSerializer
{
public:
  template <typename Type>
  void Serialize( Type* p, std::string& str );
  template <typename Type>
  void Deserialize( Type*& p, std::string& str );
  template <typename Type>
  void Fill( Type* p, std::string& str );
private:
  json11::Json _Serialize( TTestStruct* p );
  void _Deserialize( TTestStruct* p, const json11::Json& json );

  json11::Json _Serialize( TTestClass* p );
  void _Deserialize( TTestClass* p, const json11::Json& json );
};
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Serialize( Type* p, std::string& str )
{
  str = _Serialize( p ).dump();
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

  _Deserialize( p, json );
}
//------------------------------------------------------------------------------------
template <typename Type>
void TJsonSerializer::Fill( Type* p, std::string& str )
{
  std::string err;
  auto json = json11::Json::parse( str, err );
  if ( err.size() > 0 )
    return;

  _Deserialize( p, json );
}
//------------------------------------------------------------------------------------
