/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializer.h"
#include "json11.h"

using namespace json11;

Json TJsonSerializer::_Serialize( TTestStruct* p )
{
  return Json::object
  {
    { "password", p->password },
  { "port", p->port },
  { "flag", p->flag },
  { "numList", { p->numList } },
  { "strSet", { p->strSet } },
  };
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestStruct* p, const Json& json )
{
  p->password = json ["password"].string_value();
  p->port = (unsigned short) json ["port"].number_value();
  p->flag = json ["flag"].bool_value();

  auto& v = json ["numList"].array_items();
  for ( auto& e : v )
    p->numList.push_back( (int) e.number_value() );

  auto& s = json ["strSet"].array_items();
  for ( auto& e : s )
    p->strSet.insert( e.string_value() );
}
//------------------------------------------------------------------------------------
Json TJsonSerializer::_Serialize( TTestClass* p )
{
  return Json::object
  {
    { "ts", _Serialize( &( p->ts ) ) },
  { "str", p->str },
  };
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestClass* p, const Json& json )
{
  auto& obj = json ["ts"];
  auto pTs = &( p->ts );
  _Deserialize( pTs, obj );

  p->str = json ["str"].string_value();
}
//------------------------------------------------------------------------------------
