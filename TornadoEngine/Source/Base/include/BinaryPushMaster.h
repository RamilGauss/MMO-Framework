/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <functional>

#include "BreakPacket.h"
#include "ContainerRise.h"
#include "BinaryMaster.h"

class DllExport TBinaryPushMaster : public TBinaryMaster
{
  TBreakPacket mCollectorMember;
public:// prototypes
  template<typename Type>
  using PushFunc = std::function<void( Type )>;

  template<typename Type, typename ElementType>
  using AddressFunc = std::function<Type( ElementType )>;
public:
  void CopyInBuffer( TContainerRise& receiveBuffer, int offset = 0 );
  void Clear();
public:
  // built-in
  template<typename T>
  void PushNum( const T& t )
  {
    mCollectorMember.PushBack( (char*) &t, sizeof( T ) );
  }
  void PushBool( const bool& t );
  // string
  void PushStr( const std::string& str );

  // vector,list,set<built-in>
  template<typename Type, typename Array>
  void PushNumArray( Array& value )
  {
    GeneralPushArray<Type, Array>( value, [this]( const Type& t ) { PushNum( t ); } );
  }
  // vector,list<bool>
  template<typename Array>
  void PushBoolArray( Array& value )
  {
    GeneralPushArray<bool, Array>( value, [this]( const bool& t ) { PushBool( t ); } );
  }
  // vector,list,set<string>
  template<typename Array>
  void PushStrArray( Array& value )
  {
    GeneralPushArray<std::string, Array>( value, [this]( const std::string& t ) { PushStr( t ); } );
  }

  // list, vector<serialized type>
  template <typename Type, typename Array>
  void PushSerObjArray( Array& value, PushFunc<Type*> pushFunc )
  {
    GeneralPushSerArray<Type*, Type&, Array>( value,
      pushFunc, []( Type& t ) { return &t; } );
  }
  template <typename Type, typename Array>
  void PushSerPtrArray( Array& value, PushFunc<Type*> pushFunc )
  {
    GeneralPushSerArray<Type*, Type*, Array>( value,
      pushFunc, [this]( Type* t ) { return t; } );
  }
  template <typename Type, typename ElementType, typename Array>
  void PushSerSmartPtrArray( Array& value, PushFunc<Type*> pushFunc )
  {
    GeneralPushSerArray<Type*, ElementType, Array>( value,
      pushFunc, [this]( ElementType t ) { return t.get(); } );
  }

  // map<num,>
  template<typename Key, typename Value>
  void PushNumNumMap( std::map<Key, Value>& m )
  {
    GeneralPushMap<Key, Value>
    ( m, [this]( const Key& t ) { PushNum( t ); },
         [this]( Value& t )     { PushNum( t ); } );
  }
  template<typename Key>
  void PushNumStrMap( std::map<Key, std::string>& m )
  {
    GeneralPushMap<Key, std::string>
      ( m, [this]( const Key& t )   { PushNum( t ); },
           [this]( std::string& t ) { PushStr( t ); });
  }
  template<typename Key>
  void PushNumBoolMap( std::map<Key, bool>& m )
  {
    GeneralPushMap<Key, bool>
      ( m, [this]( const Key& t ) { PushNum( t ); },
           [this]( bool& t )      { PushBool( t ); } );
  }
  template<typename Key, typename Value>
  void PushNumSerObjMap( std::map<Key, Value>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const Key*, const Key&,
                      Value*,     Value&>
      ( m, [this]( const Key* t ) { PushNum( *t ); }, []( const Key& t ) { return &t; },
           pushFunc,                                  []( Value& t ) { return &t; } );
  }
  template<typename Key, typename Value>
  void PushNumSerPtrMap( std::map<Key, Value*>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const Key*, const Key&,
                      Value*,     Value*>
      ( m, [this]( const Key* t ) { PushNum( *t ); }, []( const Key& t ) { return &t; },
           pushFunc,                                  []( Value* t ) { return t; } );
  }
  template<typename Key, typename Value, typename ElementType>
  void PushNumSerSmartPtrMap( std::map<Key, ElementType>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const Key*, const Key&,
                      Value*,     ElementType>
      ( m, [this]( const Key* t ) { PushNum( *t ); }, []( const Key& t ) { return &t; },
           pushFunc,                                  []( ElementType t ) { return t.get(); } );
  }

  // map<string,>
  template<typename Value>
  void PushStrNumMap( std::map<std::string, Value>& m )
  {
    GeneralPushMap<std::string, Value>
      ( m, [this]( const std::string& t ) { PushStr( t ); },
           [this]( Value& t )             { PushNum( t ); } );
  }
  void PushStrStrMap( std::map<std::string, std::string>& m )
  {
    GeneralPushMap<std::string, std::string>
      ( m, [this]( const std::string& t ) { PushStr( t ); },
           [this]( std::string& t )       { PushStr( t ); });
  }
  void PushStrBoolMap( std::map<std::string, bool>& m )
  {
    GeneralPushMap<std::string, bool>
      ( m, [this]( const std::string& t ) { PushStr( t ); },
           [this]( bool& t )              { PushBool( t ); } );
  }
  template<typename Value>
  void PushStrSerObjMap( std::map<std::string, Value>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const std::string*, const std::string&,
                      Value*,             Value&>
      ( m, [this]( const std::string* t ) { PushStr( *t ); }, []( const std::string& t ) { return &t; },
           pushFunc,                                          []( Value& t ) { return &t; } );
  }
  template<typename Value>
  void PushStrSerPtrMap( std::map<std::string, Value*>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const std::string*, const std::string&,
                      Value*,             Value*>
      ( m, [this]( const std::string* t ) { PushStr( *t ); }, []( const std::string& t ) { return &t; },
           pushFunc,                                          []( Value* t ) { return t; } );
  }
  template<typename Value, typename ElementType>
  void PushStrSerSmartPtrMap( std::map<std::string, ElementType>& m, PushFunc<Value*> pushFunc )
  {
    GeneralPushSerMap<const std::string*, const std::string&,
                      Value*,             ElementType>
      ( m, [this]( const std::string* t ) { PushStr( *t ); }, []( const std::string& t ) { return &t; },
           pushFunc,                                          []( ElementType t ) { return t.get(); } );
  }
private:
  // array
  template <typename Type, typename ValueType>
  void GeneralPushArray( ValueType& value, PushFunc<Type> pushFunc )
  {
    SizeType size = value.size();
    PushNum( size );
    for ( auto& e : value )
      pushFunc( e );
  }

  template <typename Type, typename InputAddrType, typename ValueType>
  void GeneralPushSerArray( ValueType& value, PushFunc<Type> pushFunc, AddressFunc<Type, InputAddrType> addressFunc )
  {
    SizeType size = value.size();
    PushNum( size );
    for ( auto& e : value )
    {
      Type pE = addressFunc( e );
      auto isNotNull = !( pE == nullptr );
      PushBool( isNotNull );
      if( isNotNull )
        pushFunc( pE );
    }
  }

  template <typename KeyType, typename ValueType>
  void GeneralPushMap( std::map<KeyType, ValueType>& m,
    PushFunc<const KeyType&> keyPushFunc, PushFunc<ValueType&> valuePushFunc)
  {
    SizeType size = m.size();
    PushNum( size );
    for ( auto& bit : m )
    {
      keyPushFunc( bit.first );
      valuePushFunc( bit.second );
    }
  }
  template <typename KeyType, typename KeyInputAddrType,
    typename ValueType, typename ValueInputAddrType,
    typename Map>
    void GeneralPushSerMap( Map& m,
      PushFunc<KeyType> keyPushFunc, AddressFunc<KeyType, KeyInputAddrType> keyAddressFunc,
      PushFunc<ValueType> valuePushFunc, AddressFunc<ValueType, ValueInputAddrType> valueAddressFunc )
  {
    SizeType size = m.size();
    PushNum( size );
    for ( auto& bit : m )
    {
      auto& key = bit.first;
      KeyType pKey = keyAddressFunc( key );
      keyPushFunc( pKey );

      auto& value = bit.second;
      ValueType pValue = valueAddressFunc( value );
      auto isNotNull = !( pValue == nullptr );
      PushBool( isNotNull );
      if ( isNotNull )
        valuePushFunc( pValue );
    }
  }
};
