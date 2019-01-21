/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <functional>
#include <set>
#include "JsonMaster.h"

class DllExport TJsonPopMaster : public TJsonMaster
{
public:
  template <typename Type>
  using GetValueFunc = std::function<Type( const json11::Json& )>;

  template <typename Type, typename ArrayType>
  using AddToArrayFunc = std::function<void( ArrayType& arr, Type& e )>;

  template <typename RetType>
  using FromStrFunc = std::function<RetType( const std::string& )>;

  template<typename Type>
  using DeserFunc = std::function<void( Type*, const Jobj& )>;

  template<typename RetType>
  using NewFunc = std::function<RetType()>;

  template<typename RetType, typename ArgType>
  using GetPtr = std::function<RetType( ArgType& )>;

  template<typename RetType>
  using GetNullValue = std::function<RetType()>;
public:
  // BOOL
  static void PopBool( const json11::Json& json, const char* sKey, bool& value )
  {
    value = BoolValue( json[sKey] );
  }
  // NUMBER
  template <typename Type>
  static void PopNum( const json11::Json& json, const char* sKey, Type& value )
  {
    value = (Type) NumValue<Type>( json[sKey] );
  }
  // STRING
  static void PopStr( const json11::Json& json, const char* sKey, std::string& value )
  {
    value = StrValue( json[sKey] );
  }
  // list, vector <bool>
  template <typename ArrayType>
  static void PopBoolArray( const json11::Json& json, const char* sKey, ArrayType& value )
  {
    PopArray<bool, ArrayType>( json, sKey, value, &BoolValue, &PushBack<bool, ArrayType> );
  }
  // list, vector <number>
  template <typename Type, typename ArrayType>
  static void PopNumArray( const json11::Json& json, const char* sKey, ArrayType& value )
  {
    PopArray<Type, ArrayType>( json, sKey, value, &NumValue<Type>, &PushBack<Type, ArrayType> );
  }
  // list, vector <string>
  template <typename ArrayType>
  static void PopStrArray( const json11::Json& json, const char* sKey, ArrayType& value )
  {
    PopArray<std::string, ArrayType>( json, sKey, value, &StrValue, &PushBack<std::string, ArrayType> );
  }

  // set<bool>
  static void PopBoolSet( const json11::Json& json, const char* sKey, std::set<bool>& value )
  {
    using boolSet = std::set<bool>;
    PopArray<bool, boolSet>( json, sKey, value, &BoolValue, &Insert<bool, boolSet> );
  }
  // set<number>
  template <typename Type>
  static void PopNumSet( const json11::Json& json, const char* sKey, std::set<Type>& value )
  {
    using typeSet = std::set<Type>;
    PopArray<Type, typeSet>( json, sKey, value, &NumValue<Type>, &Insert<Type, typeSet> );
  }
  // set<string>
  static void PopStrSet( const json11::Json& json, const char* sKey, std::set<std::string>& value )
  {
    using strSet = std::set<std::string>;
    PopArray<std::string, strSet>( json, sKey, value, &StrValue, &Insert<std::string, strSet > );
  }

  // map<num,{built-in,string}>
  template<typename Type>
  static void PopNumStrMap( const json11::Json& json, const char* sKey, std::map<Type, std::string>& m )
  {
    PopMap<Type, std::string>( json, sKey, m, &Str2Num<Type>, &StrValue );
  }
  // map<num,{string,string}>
  static void PopStrStrMap( const json11::Json& json, const char* sKey, std::map<std::string, std::string>& m )
  {
    PopMap<std::string, std::string>( json, sKey, m, &Str2Str, &StrValue );
  }
  // map<string,built-in> 
  template<typename Type>
  static void PopStrNumMap( const json11::Json& json, const char* sKey, std::map<std::string, Type>& m )
  {
    PopMap<std::string, Type>( json, sKey, m, &Str2Str, &NumValue<Type> );
  }
  // map<string,bool>
  static void PopStrBoolMap( const json11::Json& json, const char* sKey, std::map<std::string, bool>& m )
  {
    PopMap<std::string, bool>( json, sKey, m, &Str2Str, &BoolValue );
  }
  // map<built-in,built-in> 
  template<typename KeyType, typename ValueType>
  static void PopNumNumMap( const json11::Json& json, const char* sKey, std::map<KeyType, ValueType>& m )
  {
    PopMap<KeyType, ValueType>( json, sKey, m, &Str2Num<KeyType>, &NumValue<ValueType> );
  }
  // map<built-in,bool>
  template<typename Type>
  static void PopNumBoolMap( const json11::Json& json, const char* sKey, std::map<Type, bool>& m )
  {
    PopMap<Type, bool>( json, sKey, m, &Str2Num<Type>, &BoolValue );
  }

  // list, vector<Serialized object>
  template<typename Type, typename ArrayType>
  static void PopSerObjArray( const json11::Json& json, const char* sKey, ArrayType& arr, DeserFunc<Type> deserFunc )
  {
    PopSerArray<Type, ArrayType, Type>( json, sKey, arr, deserFunc, &NewObject<Type, Type>, &GetObjPtr<Type*, Type>, &GetNullForObject<Type> );
  }
  // list, vector<Serialized pointer>  
  template<typename Type, typename ArrayType>
  static void PopSerPtrArray( const json11::Json& json, const char* sKey, ArrayType& arr, DeserFunc<Type> deserFunc )
  {
    PopSerArray<Type, ArrayType, Type*>( json, sKey, arr, deserFunc, &NewPointer<Type*, Type>, &GetPtrPtr<Type*, Type*>, &GetNullForPtr<Type*> );
  }
  // list, vector<Serialized smart pointer>
  template<typename Type, typename SmartPointer, typename ArrayType>
  static void PopSerSmartPtrArray( const json11::Json& json, const char* sKey, ArrayType& arr, DeserFunc<Type> deserFunc, NewFunc<SmartPointer> newFunc )
  {
    PopSerArray<Type, ArrayType, SmartPointer>( json, sKey, arr, deserFunc, newFunc, &GetSmartPtrPtr<Type*, SmartPointer>, &GetNullForSmartPtr<SmartPointer> );
  }

  // map<string,object>
  template<typename Type>
  static void PopStrSerObjMap( const json11::Json& json, const char* sKey, std::map<std::string, Type>& m, DeserFunc<Type> deserFunc )
  {
    PopSerMap<Type, std::string, Type, Type>( json, sKey, m, deserFunc, &Str2Str, &NewObject<Type, Type>, &GetObjPtr<Type*, Type>, &GetNullForObject<Type> );
  }
  // map<string,pointer>
  template<typename Type>
  static void PopStrSerPtrMap( const json11::Json& json, const char* sKey, std::map<std::string, Type*>& m, DeserFunc<Type> deserFunc )
  {
    PopSerMap<Type, std::string, Type*, Type*>( json, sKey, m, deserFunc, &Str2Str, &NewPointer<Type*, Type>, &GetPtrPtr<Type*, Type*>, &GetNullForPtr<Type*> );
  }
  // map<string,smart pointer>
  template<typename Type, typename SmartPointer>
  static void PopStrSerSmartPtrMap( const json11::Json& json, const char* sKey, std::map<std::string, SmartPointer>& m, DeserFunc<Type> deserFunc, NewFunc<SmartPointer> newFunc )
  {
    PopSerMap<Type, std::string, SmartPointer, SmartPointer>( json, sKey, m, deserFunc, &Str2Str, newFunc, &GetSmartPtrPtr<Type*, SmartPointer>, &GetNullForSmartPtr<SmartPointer> );
  }

  template<typename KeyType, typename ValueType>
  static void PopNumSerObjMap( const json11::Json& json, const char* sKey, std::map<KeyType, ValueType>& m, DeserFunc<ValueType> deserFunc )
  {
    PopSerMap<ValueType, KeyType, ValueType, ValueType>( json, sKey, m, deserFunc, &Str2Num<KeyType>, &NewObject<ValueType, ValueType>, &GetObjPtr<ValueType*, ValueType>, &GetNullForObject<ValueType> );
  }
  template<typename KeyType, typename ValueType>
  static void PopNumSerPtrMap( const json11::Json& json, const char* sKey, std::map<KeyType, ValueType*>& m, DeserFunc<ValueType> deserFunc )
  {
    PopSerMap<ValueType, KeyType, ValueType*, ValueType*>( json, sKey, m, deserFunc, &Str2Num<KeyType>, &NewPointer<ValueType*, ValueType>, &GetPtrPtr<ValueType*, ValueType*>, &GetNullForPtr<ValueType*> );
  }
  template<typename KeyType, typename ValueType, typename SmartPointer>
  static void PopNumSerSmartPtrMap( const json11::Json& json, const char* sKey, std::map<KeyType, SmartPointer>& m, DeserFunc<ValueType> deserFunc, NewFunc<SmartPointer> newFunc )
  {
    PopSerMap<ValueType, KeyType, SmartPointer, SmartPointer>( json, sKey, m, deserFunc, &Str2Num<KeyType>, newFunc, &GetSmartPtrPtr<ValueType*, SmartPointer>, &GetNullForSmartPtr<SmartPointer> );
  }

private:
  // lambdas
  static bool BoolValue( const json11::Json& json )
  {
    return json.bool_value();
  }

  template <typename Type>
  static Type NumValue( const json11::Json& json )
  {
    return (Type) json.number_value();
  }

  static std::string StrValue( const json11::Json& json )
  {
    return json.string_value();
  }
  //=================
  template <typename Type, typename ArrayType>
  static void PushBack( ArrayType& arr, Type& t )
  {
    arr.push_back( t );
  }

  template <typename Type, typename ArrayType>
  static void Insert( ArrayType& arr, Type& t )
  {
    arr.insert( t );
  }
  //=================
  template <typename RetType>
  static RetType Str2Num( const std::string& v )
  {
    return (RetType) std::stod( v );
  }

  static std::string Str2Str( const std::string& v )
  {
    return v;
  }
  //=================
  template<typename RetType, typename ArgType>
  static RetType NewObject()
  {
    return ArgType();
  }
  template<typename RetType, typename ArgType>
  static RetType NewPointer()
  {
    return new ArgType();
  }
  //=================
  template<typename RetType, typename ArgType>
  static RetType GetObjPtr( ArgType& obj )
  {
    return &obj;
  }
  template<typename RetType, typename ArgType>
  static RetType GetPtrPtr( ArgType& p )
  {
    return p;
  }
  template<typename RetType, typename ArgType>
  static RetType GetSmartPtrPtr( ArgType& p )
  {
    return p.get();
  }
  //=================
  template<typename RetType>
  static RetType GetNullForObject()
  {
    return RetType();
  }
  template<typename RetType>
  static RetType GetNullForPtr()
  {
    return nullptr;
  }
  template<typename RetType>
  static RetType GetNullForSmartPtr()
  {
    return RetType();
  }
private:
  // list, vector, set
  template <typename Type, typename ArrayType>
  static void PopArray( const json11::Json& json, const char* sKey, ArrayType& value, GetValueFunc<Type> getValue, AddToArrayFunc<Type, ArrayType> addFunc )
  {
    value.clear();

    auto& v = json[sKey].array_items();
    for ( auto& e : v )
    {
      auto t = getValue( e );
      addFunc( value, t );
    }
  }

  // map<num,{built-in,string}>
  template<typename Key, typename Value>
  static void PopMap( const json11::Json& json, const char* sKey, std::map<Key, Value>& m, FromStrFunc<Key> fromStr, GetValueFunc<Value> getValue )
  {
    m.clear();

    auto& obj = json[sKey].object_items();
    for ( auto& is : obj )
      m.insert( {fromStr( is.first ), getValue( is.second )} );
  }

  template<typename Type, typename ArrayType, typename New>
  static void PopSerArray( const json11::Json& json, const char* sKey, ArrayType& arr, DeserFunc<Type> deserFunc, NewFunc<New> newFunc,
    GetPtr<Type*, New> getPtr, GetNullValue<New> getNull )
  {
    arr.clear();

    auto& jvalue = json[sKey];
    auto jarr = jvalue.array_items();
    for ( auto& e : jarr )
    {
      if ( e.is_null() )
      {
        arr.push_back( getNull() );
        continue;
      }
      if ( e.is_object() == false )
        continue;

      arr.push_back( newFunc() );
      auto& back = arr.back();
      auto& jobj = e.object_items();
      deserFunc( getPtr( back ), jobj );
    }
  }

  template<typename Type, typename KeyType, typename ValueType, typename New>
  static void PopSerMap( const json11::Json& json, const char* sKey, std::map<KeyType, ValueType>& m, DeserFunc<Type> deserFunc, FromStrFunc<KeyType> fromStr,
    NewFunc<New> newFunc, GetPtr<Type*, New> getPtr, GetNullValue<New> getNull )
  {
    m.clear();

    auto& obj = json[sKey].object_items();
    for ( auto& is : obj )
    {
      auto key = fromStr( is.first );
      if ( is.second.is_null() )
      {
        m.insert( {key, getNull()} );
        continue;
      }
      if ( is.second.is_object() == false )
        continue;

      m.insert( {key, newFunc()} );
      auto& value = m[key];
      auto& jobj = is.second.object_items();
      auto p = getPtr( value );
      deserFunc( p, jobj );
    }
  }
};
