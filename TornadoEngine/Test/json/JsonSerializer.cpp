/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializer.h"
#include "fmt/core.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"

using namespace json11;
using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

void TJsonSerializer::_Serialize( TBaseStruct* p, Jobj& obj )
{
  PUM::Push( obj, "s", p->s );
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TBaseStruct* p, const Json& json )
{
  POM::PopStr( json, "s", p->s );
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TTestStruct* p, Jobj& obj )
{
  _Serialize( (TBaseStruct*) p, obj );
  PUM::Push( obj, "password", p->password );
  PUM::Push( obj, "port", p->port );
  PUM::Push( obj, "flag", p->flag );
  PUM::Push( obj, "numList", p->numList );
  PUM::Push( obj, "strSet", p->strSet );
  PUM::Push( obj, "numVector", p->numVector );
  PUM::Push( obj, "intSet", p->intSet );
  PUM::PushMap( obj, "intStrMap", p->intStrMap );
  PUM::PushMap( obj, "strStrMap", p->strStrMap );
  PUM::PushMap( obj, "strIntMap", p->strIntMap );
  PUM::PushMap( obj, "strBoolMap", p->strBoolMap );

  PUM::PushSerObjArray<TBaseStruct, TBaseStruct>( obj, "baseVec", p->baseVec, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerPtrArray<TBaseStruct, TBaseStruct*>( obj, "basePtrVec", p->basePtrVec, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerSmartPtrArray<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "baseSPVec", p->baseSPVec, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );

  PUM::PushSerObjMap<TBaseStruct, TBaseStruct>( obj, "strBaseMap", p->strBaseMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerPtrMap<TBaseStruct, TBaseStruct*>( obj, "strBasePtrMap", p->strBasePtrMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "strBaseSPMap", p->strBaseSPMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );

  PUM::PushSerObjMap<TBaseStruct, TBaseStruct>( obj, "intBaseMap", p->intBaseMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerPtrMap<TBaseStruct, TBaseStruct*>( obj, "intBasePtrMap", p->intBasePtrMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
  PUM::PushSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "intBaseSPMap", p->intBaseSPMap, [] ( TBaseStruct* p, Jobj& jobj ) { _Serialize( p, jobj ); } );
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestStruct* p, const Json& json )
{
  _Deserialize( (TBaseStruct*) p, json );

  POM::PopStr( json, "password", p->password );
  POM::PopNum( json, "port", p->port );
  POM::PopBool( json, "flag", p->flag );

  POM::PopNumArray<int>( json, "numList", p->numList );
  POM::PopStrSet( json, "strSet", p->strSet );
  POM::PopNumArray<int>( json, "numVector", p->numVector );
  POM::PopNumSet<int>( json, "intSet", p->intSet );

  POM::PopNumStrMap( json, "intStrMap", p->intStrMap );
  POM::PopStrStrMap( json, "strStrMap", p->strStrMap );
  POM::PopStrNumMap( json, "strIntMap", p->strIntMap );
  POM::PopStrBoolMap( json, "strBoolMap", p->strBoolMap );

  // ser array
  POM::PopSerObjArray<TBaseStruct>( json, "baseVec", p->baseVec, [] ( TBaseStruct* p, const Json& json ) { _Deserialize(p, json); } );
  POM::PopSerPtrArray<TBaseStruct>( json, "basePtrVec", p->basePtrVec, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); } );
  POM::PopSerSmartPtrArray<TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "baseSPVec", p->baseSPVec, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); }, [] () { return std::shared_ptr<TBaseStruct>( new TBaseStruct() ); } );

  // map
  POM::PopStrSerObjMap<TBaseStruct>( json, "strBaseMap", p->strBaseMap, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerPtrMap<TBaseStruct>( json, "strBasePtrMap", p->strBasePtrMap, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "strBaseSPMap", p->strBaseSPMap, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); }, [] () { return std::shared_ptr<TBaseStruct>( new TBaseStruct() ); } );

  POM::PopNumSerObjMap<int,TBaseStruct>( json, "intBaseMap", p->intBaseMap, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerPtrMap<int, TBaseStruct>( json, "intBasePtrMap", p->intBasePtrMap, [] ( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerSmartPtrMap<int, TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "intBaseSPMap", p->intBaseSPMap, []( TBaseStruct* p, const Json& json ) { _Deserialize( p, json ); }, [] () { return std::shared_ptr<TBaseStruct>( new TBaseStruct() ); } );
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TTestClass* p, Jobj& obj )
{
  Jobj objTs;
  _Serialize( &( p->ts ), objTs );
  PUM::Push( obj, "ts", objTs );
  PUM::Push( obj, "str", p->str );
}
//------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestClass* p, const Json& json )
{
  auto& jsonTs = json ["ts"];
  _Deserialize( &( p->ts ), jsonTs );

  p->str = json ["str"].string_value();
}
//------------------------------------------------------------------------------------
