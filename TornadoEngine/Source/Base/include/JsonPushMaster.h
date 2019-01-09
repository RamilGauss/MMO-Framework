/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>

#include <functional>
#include "JsonMaster.h"

class DllExport TJsonPushMaster : public TJsonMaster
{
public:// types
  typedef json11::Json::object Jobj;

public:// prototypes
  template<typename Type>
  using SerFunc = std::function<void( Type*, Jobj& )>;

  template<typename Type, typename ElementType>
  using AddressFunc = std::function<Type*( ElementType& )>;

  template <typename Type, typename ElementType, typename ValueType>
  using PushBy = std::function<void( Jobj&, const char*, ValueType&, SerFunc<Type>, AddressFunc<Type, ElementType> )>;

public:// methods
  // built-in, string, {vector, list, set}<{built-in, string}>
  template <typename ValueType>
  static void Push( Jobj& obj, const char* sKey, ValueType& value )
  {
    obj.insert( { sKey, value } );
  }
  // map<{built-in,string},{built-in,string}>
  template <typename ValueType>
  static void PushMap( Jobj& obj, const char* sKey, ValueType& value )
  {
    Jobj jMap;
    for ( auto& intStr : value )
      jMap.insert( { fmt::format( "{}", intStr.first ), intStr.second } );
    obj.insert( { sKey, jMap } );
  }
  // list, vector, set(serialized type)
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerObjArray( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerArray<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &ObjAddress<Type,ElementType> );
  }
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerPtrArray( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerArray<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &PtrAddress<Type, ElementType> );
  }
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerSmartPtrArray( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerArray<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &SmartPtrAddress<Type, ElementType> );
  }

  // map<{built-in,string},{serialized type}>
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerObjMap( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerMap<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &ObjAddress<Type, ElementType> );
  }
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerPtrMap( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerMap<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &PtrAddress<Type, ElementType> );
  }
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerSmartPtrMap( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc )
  {
    PushSerMap<Type, ElementType, ValueType>( obj, sKey, value, serFunc, &SmartPtrAddress<Type, ElementType> );
  }

  // general methods
private:
  template<typename Type, typename ElementType>
  static Type* ObjAddress( ElementType& e ) { return &e; }

  template<typename Type, typename ElementType>
  static Type* PtrAddress( ElementType& p ) { return p; }

  template<typename Type, typename ElementType>
  static Type* SmartPtrAddress( ElementType& sp ) { return sp.get(); }

  // array
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerArray( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc, AddressFunc<Type, ElementType> addressFunc )
  {
    //std::list<Jobj> arrJobj;
    std::list<json11::Json> arrJ;
    for ( auto& e : value )
    {
      Jobj elObj;
      auto pE = addressFunc( e );
      if ( pE )
      {
        serFunc( pE, elObj );
        arrJ.push_back( elObj );
      }
      else
        arrJ.push_back( json11::Json( nullptr ) );
    }
    obj.insert( { sKey, arrJ } );
  }
  // map
  template <typename Type, typename ElementType, typename ValueType>
  static void PushSerMap( Jobj& obj, const char* sKey, ValueType& value, SerFunc<Type> serFunc, AddressFunc<Type, ElementType> addressFunc )
  {
    Jobj jMap;
    for ( auto& intStr : value )
    {
      Jobj elObj;
      auto pE = addressFunc( intStr.second );
      if ( pE )
      {
        serFunc( pE, elObj );
        jMap.insert( {fmt::format( "{}", intStr.first ), elObj} );
      }
      else
        jMap.insert( {fmt::format( "{}", intStr.first ), json11::Json( nullptr )} );
    }
    obj.insert( { sKey, jMap } );
  }
};
