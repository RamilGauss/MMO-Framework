/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
// File has been generated by ReflectionCodeGenerator version 1.0 build 22, at 2019_01_28 19:58:08.202
	
#include "JsonSerializer.h"
#include "fmt/core.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"

using namespace nsJson;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

void TJsonSerializer::_Serialize( TFloat3* p, Jobj& obj )
{
  PUM::Push( obj, "x", p->x );
  PUM::Push( obj, "y", p->y );
  PUM::Push( obj, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TFloat3* p, const json11::Json& json )
{
  POM::PopNum( json, "x", p->x );
  POM::PopNum( json, "y", p->y );
  POM::PopNum( json, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TFloat4* p, Jobj& obj )
{
  PUM::Push( obj, "x", p->x );
  PUM::Push( obj, "y", p->y );
  PUM::Push( obj, "z", p->z );
  PUM::Push( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TFloat4* p, const json11::Json& json )
{
  POM::PopNum( json, "x", p->x );
  POM::PopNum( json, "y", p->y );
  POM::PopNum( json, "z", p->z );
  POM::PopNum( json, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TParamClass* p, Jobj& obj )
{
  PUM::Push( obj, "id", p->id );
  Jobj pos_obj;
  _Serialize( &(p->pos), pos_obj );
  PUM::Push( obj, "pos", pos_obj );
  Jobj rot_obj;
  _Serialize( &(p->rot), rot_obj );
  PUM::Push( obj, "rot", rot_obj );
  Jobj vel_obj;
  _Serialize( &(p->vel), vel_obj );
  PUM::Push( obj, "vel", vel_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TParamClass* p, const json11::Json& json )
{
  POM::PopNum( json, "id", p->id );
  auto& pos_json = json["pos"];
  _Deserialize( &(p->pos), pos_json );
  auto& rot_json = json["rot"];
  _Deserialize( &(p->rot), rot_json );
  auto& vel_json = json["vel"];
  _Deserialize( &(p->vel), vel_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TTestClass* p, Jobj& obj )
{
  PUM::PushSerObjArray<TParamClass>( obj, "vParam", p->vParam, []( TParamClass* p, Jobj& obj ) { _Serialize( p, obj ); } );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestClass* p, const json11::Json& json )
{
  POM::PopSerObjArray<TParamClass>( json, "vParam", p->vParam, []( TParamClass* p, const json11::Json& json ) { _Deserialize( p, json ); } );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsBS::TBaseStruct* p, Jobj& obj )
{
  PUM::Push( obj, "s", p->s );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsBS::TBaseStruct* p, const json11::Json& json )
{
  POM::PopStr( json, "s", p->s );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsBS::TTestStruct* p, Jobj& obj )
{
  _Serialize( (nsBS::TBaseStruct*)p, obj);
  Jobj baseStruct_obj;
  _Serialize( &(p->baseStruct), baseStruct_obj );
  PUM::Push( obj, "baseStruct", baseStruct_obj );
  Jobj pBaseStruct_obj;
  auto p_pBaseStruct = p->pBaseStruct;
  if ( p_pBaseStruct )
  {
    _Serialize( p_pBaseStruct, pBaseStruct_obj );
    PUM::Push( obj, "pBaseStruct", pBaseStruct_obj );
  }
  else
    PUM::PushNull( obj, "pBaseStruct" );
  Jobj spBaseStruct_obj;
  auto p_spBaseStruct = p->spBaseStruct.get();
  if ( p_spBaseStruct )
  {
    _Serialize( p_spBaseStruct, spBaseStruct_obj );
    PUM::Push( obj, "spBaseStruct", spBaseStruct_obj );
  }
  else
    PUM::PushNull( obj, "spBaseStruct" );
  PUM::Push( obj, "password", p->password );
  PUM::Push( obj, "port", p->port );
  PUM::Push( obj, "flag", p->flag );
  PUM::Push( obj, "strSet", p->strSet );
  PUM::Push( obj, "intSet", p->intSet );
  PUM::Push( obj, "boolList", p->boolList );
  PUM::Push( obj, "numList", p->numList );
  PUM::Push( obj, "numVector", p->numVector );
  PUM::Push( obj, "strVector", p->strVector );
  PUM::PushSerObjArray<nsBS::TBaseStruct>( obj, "baseVec", p->baseVec, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrArray<nsBS::TBaseStruct>( obj, "basePtrVec", p->basePtrVec, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrArray<nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( obj, "baseSPVec", p->baseSPVec, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushMap( obj, "intIntMap", p->intIntMap );
  PUM::PushMap( obj, "intBoolMap", p->intBoolMap );
  PUM::PushMap( obj, "intStrMap", p->intStrMap );
  PUM::PushMap( obj, "strStrMap", p->strStrMap );
  PUM::PushMap( obj, "strIntMap", p->strIntMap );
  PUM::PushMap( obj, "strBoolMap", p->strBoolMap );
  PUM::PushSerObjMap<nsBS::TBaseStruct>( obj, "strBaseMap", p->strBaseMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrMap<nsBS::TBaseStruct>( obj, "strBasePtrMap", p->strBasePtrMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrMap<nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( obj, "strBaseSPMap", p->strBaseSPMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerObjMap<nsBS::TBaseStruct>( obj, "intBaseMap", p->intBaseMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrMap<nsBS::TBaseStruct>( obj, "intBasePtrMap", p->intBasePtrMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrMap<nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( obj, "intBaseSPMap", p->intBaseSPMap, []( nsBS::TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsBS::TTestStruct* p, const json11::Json& json )
{
  _Deserialize( (nsBS::TBaseStruct*)p, json);
  auto& baseStruct_json = json["baseStruct"];
  _Deserialize( &(p->baseStruct), baseStruct_json );
  auto& pBaseStruct_json = json["pBaseStruct"];
  if ( pBaseStruct_json.is_null() == false )
  {
    if ( p->pBaseStruct == nullptr )
      p->pBaseStruct = new nsBS::TBaseStruct();
    _Deserialize( p->pBaseStruct, pBaseStruct_json );
  }
  auto& spBaseStruct_json = json["spBaseStruct"];
  if ( spBaseStruct_json.is_null() == false )
  {
    if ( p->spBaseStruct.get() == nullptr )
      p->spBaseStruct.reset( new nsBS::TBaseStruct() );
    _Deserialize( p->spBaseStruct.get(), spBaseStruct_json );
  }
  POM::PopStr( json, "password", p->password );
  POM::PopNum( json, "port", p->port );
  POM::PopBool( json, "flag", p->flag );
  POM::PopStrSet( json, "strSet", p->strSet );
  POM::PopNumSet<int>( json, "intSet", p->intSet );
  POM::PopBoolArray( json, "boolList", p->boolList );
  POM::PopNumArray<int>( json, "numList", p->numList );
  POM::PopNumArray<int>( json, "numVector", p->numVector );
  POM::PopStrArray( json, "strVector", p->strVector );
  POM::PopSerObjArray<nsBS::TBaseStruct>( json, "baseVec", p->baseVec, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopSerPtrArray<nsBS::TBaseStruct>( json, "basePtrVec", p->basePtrVec, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopSerSmartPtrArray<nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( json, "baseSPVec", p->baseSPVec, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumNumMap( json, "intIntMap", p->intIntMap );
  POM::PopNumBoolMap( json, "intBoolMap", p->intBoolMap );
  POM::PopNumStrMap( json, "intStrMap", p->intStrMap );
  POM::PopStrStrMap( json, "strStrMap", p->strStrMap );
  POM::PopStrNumMap( json, "strIntMap", p->strIntMap );
  POM::PopStrBoolMap( json, "strBoolMap", p->strBoolMap );
  POM::PopStrSerObjMap<nsBS::TBaseStruct>( json, "strBaseMap", p->strBaseMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerPtrMap<nsBS::TBaseStruct>( json, "strBasePtrMap", p->strBasePtrMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerSmartPtrMap<nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( json, "strBaseSPMap", p->strBaseSPMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerObjMap<int, nsBS::TBaseStruct>( json, "intBaseMap", p->intBaseMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerPtrMap<int, nsBS::TBaseStruct>( json, "intBasePtrMap", p->intBasePtrMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerSmartPtrMap<int, nsBS::TBaseStruct, std::shared_ptr<nsBS::TBaseStruct>>( json, "intBaseSPMap", p->intBaseSPMap, []( nsBS::TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, Jobj& obj )
{
  _Serialize( (nsReflectionCodeGenerator::TClassDesc*)p, obj);
  Jobj unpackHandler_obj;
  _Serialize( &(p->unpackHandler), unpackHandler_obj );
  PUM::Push( obj, "unpackHandler", unpackHandler_obj );
  PUM::Push( obj, "beginID", p->beginID );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, const json11::Json& json )
{
  _Deserialize( (nsReflectionCodeGenerator::TClassDesc*)p, json);
  auto& unpackHandler_json = json["unpackHandler"];
  _Deserialize( &(p->unpackHandler), unpackHandler_json );
  POM::PopNum( json, "beginID", p->beginID );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj )
{
  PUM::Push( obj, "exportDeclaration", p->exportDeclaration );
  PUM::Push( obj, "nameSpaceName", p->nameSpaceName );
  PUM::Push( obj, "className", p->className );
  PUM::Push( obj, "fileName", p->fileName );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TClassDesc* p, const json11::Json& json )
{
  POM::PopStr( json, "exportDeclaration", p->exportDeclaration );
  POM::PopStr( json, "nameSpaceName", p->nameSpaceName );
  POM::PopStr( json, "className", p->className );
  POM::PopStr( json, "fileName", p->fileName );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TConfig* p, Jobj& obj )
{
  Jobj targetForParsing_obj;
  _Serialize( &(p->targetForParsing), targetForParsing_obj );
  PUM::Push( obj, "targetForParsing", targetForParsing_obj );
  Jobj filter_obj;
  _Serialize( &(p->filter), filter_obj );
  PUM::Push( obj, "filter", filter_obj );
  Jobj targetForCodeGeneration_obj;
  _Serialize( &(p->targetForCodeGeneration), targetForCodeGeneration_obj );
  PUM::Push( obj, "targetForCodeGeneration", targetForCodeGeneration_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TConfig* p, const json11::Json& json )
{
  auto& targetForParsing_json = json["targetForParsing"];
  _Deserialize( &(p->targetForParsing), targetForParsing_json );
  auto& filter_json = json["filter"];
  _Deserialize( &(p->filter), filter_json );
  auto& targetForCodeGeneration_json = json["targetForCodeGeneration"];
  _Deserialize( &(p->targetForCodeGeneration), targetForCodeGeneration_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TFilter* p, Jobj& obj )
{
  PUM::Push( obj, "attribute", p->attribute );
  PUM::Push( obj, "extensions", p->extensions );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TFilter* p, const json11::Json& json )
{
  POM::PopStr( json, "attribute", p->attribute );
  POM::PopStrArray( json, "extensions", p->extensions );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TImplementation* p, Jobj& obj )
{
  Jobj jsonSerializer_obj;
  auto p_jsonSerializer = p->jsonSerializer.get();
  if ( p_jsonSerializer )
  {
    _Serialize( p_jsonSerializer, jsonSerializer_obj );
    PUM::Push( obj, "jsonSerializer", jsonSerializer_obj );
  }
  else
    PUM::PushNull( obj, "jsonSerializer" );
  Jobj binaryMarshaller_obj;
  auto p_binaryMarshaller = p->binaryMarshaller.get();
  if ( p_binaryMarshaller )
  {
    _Serialize( p_binaryMarshaller, binaryMarshaller_obj );
    PUM::Push( obj, "binaryMarshaller", binaryMarshaller_obj );
  }
  else
    PUM::PushNull( obj, "binaryMarshaller" );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TImplementation* p, const json11::Json& json )
{
  auto& jsonSerializer_json = json["jsonSerializer"];
  if ( jsonSerializer_json.is_null() == false )
  {
    if ( p->jsonSerializer.get() == nullptr )
      p->jsonSerializer.reset( new nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig() );
    _Deserialize( p->jsonSerializer.get(), jsonSerializer_json );
  }
  auto& binaryMarshaller_json = json["binaryMarshaller"];
  if ( binaryMarshaller_json.is_null() == false )
  {
    if ( p->binaryMarshaller.get() == nullptr )
      p->binaryMarshaller.reset( new nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig() );
    _Deserialize( p->binaryMarshaller.get(), binaryMarshaller_json );
  }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, Jobj& obj )
{
  _Serialize( (nsReflectionCodeGenerator::TClassDesc*)p, obj);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, const json11::Json& json )
{
  _Deserialize( (nsReflectionCodeGenerator::TClassDesc*)p, json);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj )
{
  PUM::Push( obj, "directory", p->directory );
  PUM::Push( obj, "includeListFileName", p->includeListFileName );
  Jobj implementation_obj;
  _Serialize( &(p->implementation), implementation_obj );
  PUM::Push( obj, "implementation", implementation_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const json11::Json& json )
{
  POM::PopStr( json, "directory", p->directory );
  POM::PopStr( json, "includeListFileName", p->includeListFileName );
  auto& implementation_json = json["implementation"];
  _Deserialize( &(p->implementation), implementation_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj )
{
  PUM::Push( obj, "directories", p->directories );
  PUM::Push( obj, "recursive", p->recursive );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TTargetForParsing* p, const json11::Json& json )
{
  POM::PopStrArray( json, "directories", p->directories );
  POM::PopBool( json, "recursive", p->recursive );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TUnpackHandler* p, Jobj& obj )
{
  _Serialize( (nsReflectionCodeGenerator::TClassDesc*)p, obj);
  PUM::Push( obj, "method", p->method );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TUnpackHandler* p, const json11::Json& json )
{
  _Deserialize( (nsReflectionCodeGenerator::TClassDesc*)p, json);
  POM::PopStr( json, "method", p->method );
}
//---------------------------------------------------------------------------------------
