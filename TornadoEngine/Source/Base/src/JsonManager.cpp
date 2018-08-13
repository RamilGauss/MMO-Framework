/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonManager.h"
#include "json11.h"
#include "ContainerTypes.h"

std::string tn_value = "value";
std::string tn_type = "type";

std::string tn_uchar = "uchar";
std::string tn_ushort = "ushort";

std::string tn_int = "int";
std::string tn_uint = "uint";

std::string tn_float = "float";
std::string tn_double = "double";
//-----------------------------------------------------------------------------------------
namespace nsJsonManager
{
  template<class T>
  void Push( double num, char* pObj, int& offset )
  {
    auto t = (T) num;
    auto pT = (T*) &pObj[offset];
    *pT = t;
    offset += sizeof( T );
  }
}
//-----------------------------------------------------------------------------------------
TJsonManager::TJsonManager()
{
  if( g_TypeNameFuncMap )
    return;

  g_TypeNameFuncMap = SingletonManager()->Get<TStrFuncMap>();
  if( g_TypeNameFuncMap->size() )
    return;

  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_uchar, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<unsigned char>( num, pObj, offset );  } ) );
  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_ushort, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<unsigned short>( num, pObj, offset ); } ) );
  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_int, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<int>( num, pObj, offset );            } ) );
  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_uint, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<unsigned int>( num, pObj, offset );   } ) );
  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_float, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<float>( num, pObj, offset );          } ) );
  g_TypeNameFuncMap->insert( TStrFuncMap::value_type( tn_double, []( double num, char* pObj, int& offset )
  {  nsJsonManager::Push<double>( num, pObj, offset );         } ) );
}
//-----------------------------------------------------------------------------------------
void TJsonManager::Push( json11::Json& json, char* pObj, int& offset )
{
  auto objMap = json.object_items();
  for( auto jsonPair : objMap )
  {
    auto jsonNode = jsonPair.second.object_items().begin()->second;

    auto type = jsonNode.type();
    switch( type )
    {
      case json11::Json::NUL:
      case json11::Json::ARRAY:
      case json11::Json::NUMBER:
        break;
      case json11::Json::BOOL:
      {
        auto pBool = (bool*) &pObj[offset];
        *pBool = jsonNode.bool_value();
        offset += sizeof( bool );
      }
      break;
      case json11::Json::STRING:
      {
        auto pStr = (std::string*)&pObj[offset];
        *pStr = jsonNode.string_value();
        offset += sizeof( std::string );
      }
      break;
      case json11::Json::OBJECT:
      {
        auto jsonValue = jsonNode[tn_value];
        auto jsonType = jsonNode[tn_type];
        auto typeStr = jsonType.string_value();
        auto valueNum = jsonValue.number_value();
        auto fit = g_TypeNameFuncMap->find( typeStr );
        if( fit != g_TypeNameFuncMap->end() )
          fit->second( valueNum, pObj, offset );
      }
      break;
    }
  }
}
//-----------------------------------------------------------------------------------------