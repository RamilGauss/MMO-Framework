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

#include "BinaryMaster.h"
#include "ContainerRise.h"

class DllExport TBinaryPopMaster : public TBinaryMaster
{
  char* mPtrData;
  int mSizeData;
  int mOffset;
public:
  void SetBuffer( TContainerRise* pC, int offset );
  void SetBuffer( char* pData, int size, int offset );
  int GetOffset();
public:
  template<typename Type>
  using PopFunc = std::function<void( Type )>;

  template<typename ValueType, typename TypeForSer>
  using AddToArray = std::function<void( ValueType, TypeForSer )>;

  template<typename RetType, typename InputType>
  using GetAddressFunc = std::function<RetType(InputType)>;

  template<typename RetType>
  using GetNewFunc = std::function<RetType()>;

  template<typename RetType>
  using GetNullPtrFunc = std::function<RetType()>;
public:
  // built-in
  template<typename T>
  void PopNum( T& t )
  {
    memcpy( &t, mPtrData + mOffset, sizeof( T ) );
    mOffset += sizeof( T );
  }
  // bool 
  void PopBool( bool& t );
  // string
  void PopStr( std::string& str );

  // vector/list<built-in>
  template<typename Type, typename Array>
  void PopNumArray( Array& array )
  {
    GeneralPopArray<Type, Array>( array, 
      [this]( Type& t ) {PopNum( t ); }, []( Array& array, Type& t ) { array.push_back( t ); } );
  }
  // vector/list<bool>
  template<typename Array>
  void PopBoolArray( Array& array )
  {
    GeneralPopArray<bool, Array>( array,
      [this]( bool& t ) {PopBool( t ); }, []( Array& array, bool& t ) { array.push_back( t ); } );
  }
  // vector/list<string>
  template<typename Array>
  void PopStrArray( Array& array )
  {
    GeneralPopArray<std::string, Array>( array,
      [this]( std::string& t ) {PopStr( t ); }, []( Array& array, std::string& t ) { array.push_back( t ); } );
  }
  // set<built-in>
  template<typename Type>
  void PopNumSet( std::set<Type>& array )
  {
    GeneralPopArray<Type, std::set<Type>>( array,
      [this]( Type& t ) {PopNum( t ); }, []( std::set<Type>& array, Type& t ) { array.insert( t ); } );
  }
  // set<bool>
  void PopBoolSet( std::set<bool>& array )
  {
    GeneralPopArray<bool, std::set<bool>>( array,
      [this]( bool& t ) {PopBool( t ); }, []( std::set<bool>& array, bool& t ) { array.insert( t ); } );
  }
  // set<string>
  void PopStrSet( std::set<std::string>& array )
  {
    GeneralPopArray<std::string, std::set<std::string>>( array,
      [this]( std::string& t ) {PopStr( t ); }, []( std::set<std::string>& array, std::string& t ) { array.insert( t ); } );
  }
  // vector/list<serializable>
  template<typename Type, typename Array>
  void PopSerObjArray( Array& array, PopFunc<Type*> popFunc )
  {
    GeneralPopSerArray<Type, Type, Array>( array, 
      []() {return Type(); }, []( Type& t ) {return &t; }, popFunc, 
      []() {return Type(); } );
  }
  template<typename Type, typename Array>
  void PopSerPtrArray( Array& array, PopFunc<Type*> popFunc )
  {
    GeneralPopSerArray<Type, Type*, Array>( array,
      []() {return new Type(); }, []( Type* t ) {return t; }, popFunc,
      []() {return nullptr; } );
  }
  template<typename Type, typename ElementType, typename Array>
  void PopSerSmartPtrArray( Array& array, PopFunc<Type*> popFunc )
  {
    GeneralPopSerArray<Type, ElementType, Array>( array,
      []() {return ElementType( new Type() ); }, []( ElementType& t ) {return t.get(); }, popFunc,
      []() {return ElementType(); } );
  }

  // map<num,>
  template<typename Key>
  void PopNumBoolMap( std::map<Key, bool>& m )
  {
    GeneralPopMap<Key, bool>( m, [this]( Key& t ) { PopNum( t ); }, [this]( bool& t ) { PopBool( t ); } );
  }
  template<typename Key, typename Value>
  void PopNumNumMap( std::map<Key, Value>& m )
  {
    GeneralPopMap<Key, Value>( m, [this]( Key& t ) { PopNum( t ); }, [this]( Value& t ) { PopNum( t ); } );
  }
  template<typename Key>
  void PopNumStrMap( std::map<Key, std::string>& m )
  {
    GeneralPopMap<Key, std::string>( m, [this]( Key& t ) { PopNum( t ); }, [this]( std::string& t ) { PopStr( t ); } );
  }
  // map<str,>
  void PopStrBoolMap( std::map<std::string, bool>& m )
  {
    GeneralPopMap<std::string, bool>( m, [this]( std::string& t ) { PopStr( t ); }, [this]( bool& t ) { PopBool( t ); } );
  }
  template<typename Value>
  void PopStrNumMap( std::map<std::string, Value>& m )
  {
    GeneralPopMap<std::string, Value>( m, [this]( std::string& t ) { PopStr( t ); }, [this]( Value& t ) { PopNum( t ); } );
  }
  void PopStrStrMap( std::map<std::string, std::string>& m )
  {
    GeneralPopMap<std::string, std::string>( m, [this]( std::string& t ) { PopStr( t ); }, [this]( std::string& t ) { PopStr( t ); } );
  }

  // map<>
  template<typename Key, typename Value>
  void PopNumSerObjMap( std::map<Key, Value>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<Key, Value, Value>( m, [this]( Key& t ) { PopNum( t ); },
      []() {return Value(); }, []( Value& t ) { return &t; }, popFunc, 
      []() {return Value(); } );
  }
  template<typename Key, typename Value>
  void PopNumSerPtrMap( std::map<Key, Value*>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<Key, Value, Value*>( m, [this]( Key& t ) { PopNum( t ); },
      []() {return new Value(); }, []( Value* t ) { return t; }, popFunc,
      []() {return nullptr; } );
  }
  template<typename Key, typename Value, typename ElementType>
  void PopNumSerSmartPtrMap( std::map<Key, ElementType>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<Key, Value, ElementType>( m, [this]( Key& t ) { PopNum( t ); },
      []() {return ElementType( new Value() ); }, []( ElementType t ) { return t.get(); }, popFunc,
      []() {return ElementType(); } );
  }

  template<typename Value>
  void PopStrSerObjMap( std::map<std::string, Value>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<std::string, Value, Value>( m, [this]( std::string& t ) { PopStr( t ); },
      []() {return Value(); }, []( Value& t ) { return &t; }, popFunc,
      []() {return Value(); } );
  }
  template<typename Value>
  void PopStrSerPtrMap( std::map<std::string, Value*>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<std::string, Value, Value*>( m, [this]( std::string& t ) { PopStr( t ); },
      []() {return new Value(); }, []( Value* t ) { return t; }, popFunc,
      []() {return nullptr; } );
  }
  template<typename Value, typename ElementType>
  void PopStrSerSmartPtrMap( std::map<std::string, ElementType>& m, PopFunc<Value*> popFunc )
  {
    GeneralPopSerMap<std::string, Value, ElementType>( m, [this]( std::string& t ) { PopStr( t ); },
      []() {return ElementType( new Value() ); }, []( ElementType t ) { return t.get(); }, popFunc,
      []() {return ElementType(); } );
  }
private:
  template<typename Type, typename Array>
  void GeneralPopArray( Array& array, PopFunc<Type&> popFunc, AddToArray<Array&, Type&> addToArray )
  {
    array.clear();
    SizeType size;
    PopNum( size );
    Type t;
    for ( SizeType i = 0; i < size; i++ )
    {
      popFunc( t );
      addToArray( array, t );
    }
  }

  template<typename Type, typename NewType, typename Array>
  void GeneralPopSerArray( Array& array, 
    GetNewFunc<NewType> getNewFunc, GetAddressFunc<Type*,NewType&> getAddressFunc, 
    PopFunc<Type*> popFunc, GetNullPtrFunc<NewType> getNullPtrFunc )
  {
    array.clear();
    SizeType size;
    PopNum( size );
    bool isNotNull;
    for ( SizeType i = 0; i < size; i++ )
    {
      PopBool( isNotNull );
      if ( isNotNull == false )
      {
        array.push_back( getNullPtrFunc() );
        continue;
      }

      NewType t = getNewFunc();
      auto pT = getAddressFunc( t );
      popFunc( pT );
      array.push_back( t );
    }
  }

  template<typename Key, typename Value>
  void GeneralPopMap( std::map<Key, Value>& m, PopFunc<Key&> keyPopFunc, PopFunc<Value&> valuePopFunc )
  {
    SizeType size;
    PopNum( size );
    for ( SizeType i = 0; i < size; i++ )
    {
      Key key;
      keyPopFunc( key );
      Value value;
      valuePopFunc( value );
      m.insert( {key, value} );
    }
  }

  template<typename Key, typename Value, typename NewType>
  void GeneralPopSerMap( std::map<Key, NewType>& m, PopFunc<Key&> keyPopFunc, 
    GetNewFunc<NewType> getNewFunc, GetAddressFunc<Value*, NewType&> getAddressFunc,
    PopFunc<Value*> valuePopFunc, GetNullPtrFunc<NewType> getNullPtrFunc )
  {
    SizeType size;
    PopNum( size );
    for ( SizeType i = 0; i < size; i++ )
    {
      Key key;
      keyPopFunc( key );

      bool isNotNull;
      PopBool( isNotNull );
      if ( isNotNull == false )
      {
        m.insert( {key, getNullPtrFunc()} );
        continue;
      }
      NewType value = getNewFunc();
      auto pValue = getAddressFunc( value );
      valuePopFunc( pValue );

      m.insert( {key, value} );
    }
  }
};
