/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PopMasterH
#define PopMasterH

#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>

#include "BreakPacket.h"
#include "TypeDef.h"

class ISerializable;

class DllExport TPopMaster
{
  char* mPtrData;
  int mSizeData;
  int mOffset;
public:
  void SetBuffer(TContainerRise* pC, int offset );
  int GetOffset();
public:
  //bool, unsigned char, char, unsigned short, short, unsigned int, int, float, double
  template<typename T>
  void Pop( T& t);
  //std::string
  void PopStr( std::string& str );
  //ISerializable
  template<typename T>
  void PopSer( T& serializable );
  //ISerializable*
  template<typename T>
  void PopPtrSer( T*& pSer );

  //std::vector/list/set
  // unsigned char, char, unsigned short, short, unsigned int, int, float, double
  template<typename T, typename Array>
  void PopArray( Array& array );
  //std::vector/list/set<std::string>
  template<typename Array>
  void PopArrayStr( Array& array );
  //std::vector/list/set<ISerializable>
  template<typename T>
  void PopVectorSer( std::vector<T>& array );
  template<typename T>
  void PopListSer( std::list<T>& array );
  template<typename T>
  void PopSetSer( std::set<T>& array );
  //std::vector/list/set<ISerializable*>
  template<typename T, typename Array>
  void PopArrayPtrSer( Array& array );

  // std::map
  template<typename Key, typename Value, typename Map>
  void PopMap__( Map& m );
  template<typename Key, typename Map>
  void PopMap_Str( Map& m );
  template<typename Key, typename Value, typename Map>
  void PopMap_Ser( Map& m );
  template<typename Key, typename Value, typename Map>
  void PopMap_PtrSer( Map& m );

  template<typename Value, typename Map>
  void PopMapStr_( Map& m );
  template<typename Map>
  void PopMapStrStr( Map& m );
  template<typename Value, typename Map>
  void PopMapStrSer( Map& m );
  template<typename Value, typename Map>
  void PopMapStrPtrSer( Map& m );

  template<typename Key, typename Value, typename Map>
  void PopMapSer_( Map& m );
  template<typename Key, typename Map>
  void PopMapSerStr( Map& m );
  template<typename Key, typename Value, typename Map>
  void PopMapSerSer( Map& m );
  template<typename Key, typename Value, typename Map>
  void PopMapSerPtrSer( Map& m );
private:
  void PopSize( int& size );

  template<typename T, typename Array>
  void PopByInsert( Array* pArray );
  template<typename T, typename Array>
  void PopByPush( Array* pArray );

  void PopStrByInsert( std::set<std::string>* pSetStr );
  template<typename Array>
  void PopStrByPush( Array* pArray );
};
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::Pop( T& t)
{ 
  memcpy( &t, mPtrData + mOffset, sizeof(T) ); 
  mOffset += sizeof(T);
}
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::PopSer( T& serializable )
{
  serializable.Deserialize( this );
}
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::PopPtrSer( T*& pSer )
{
  unsigned char isNotNull;
  Pop( isNotNull );
  if( isNotNull )
  {
    if( pSer == NULL)
      pSer = new T();
    pSer->Deserialize( this );
  }
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPopMaster::PopArray( Array& array )
{
  array.clear();

  typedef std::set<T> SET_T;
  typedef std::list<T> LIST_T;
  typedef std::vector<T> VECTOR_T;
  // такое кол-во веток в if возникает из-за того, что у set INSERT, а у list и vector push_back
  if( typeid(array)==typeid(SET_T) )
  {
    SET_T* pSet = (SET_T*)&array;
    PopByInsert<T>( pSet );
  }
  else if( typeid(array)==typeid(LIST_T) )
  {
    LIST_T* pList = (LIST_T*)&array;
    PopByPush<T>( pList );
  }
  else
  {
    VECTOR_T* pVector = (VECTOR_T*)&array;
    PopByPush<T>( pVector );
  }
}
//------------------------------------------------------------------------
template<typename Array>
void TPopMaster::PopArrayStr( Array& array )
{
  array.clear();

  typedef std::set<std::string> SET_STR;
  typedef std::list<std::string> LIST_STR;
  typedef std::vector<std::string> VECTOR_STR;
  // такое кол-во веток в if возникает из-за того, что у set INSERT, а у list и vector push_back
  if( typeid(array)==typeid(SET_STR) )
  {
    SET_STR* pSet = (SET_STR*)&array;
    PopStrByInsert( pSet );
  }
  else if( typeid(array)==typeid(LIST_STR) )
  {
    LIST_STR* pList = (LIST_STR*)&array;
    PopStrByPush( pList );
  }
  else
  {
    VECTOR_STR* pVector = (VECTOR_STR*)&array;
    PopStrByPush( pVector );
  }
}
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::PopVectorSer( std::vector<T>& array )
{
  array.clear();

  int size;
  PopSize( size );
  array.reserve( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T t;
    PopSer( t );
    array.push_back( t );
  }
}
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::PopListSer( std::list<T>& array )
{
  array.clear();

  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T t;
    PopSer( t );
    array.push_back( t );
  }
}
//------------------------------------------------------------------------
template<typename T>
void TPopMaster::PopSetSer( std::set<T>& array )
{
  array.clear();

  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T t;
    PopSer( t );
    array.insert( t );
  }
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPopMaster::PopArrayPtrSer( Array& array )
{// а здесь set быть не может!
  array.clear();

  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T* t = NULL;
    PopPtrSer<T>( t );
    array.push_back( t );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMap__( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    Pop( key );
    Value value;
    Pop( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPopMaster::PopMap_Str( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    Pop( key );
    std::string value;
    PopStr( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMap_Ser( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    Pop( key );
    Value value;
    PopSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMap_PtrSer( Map& m )
{
  for( auto& vt : m )
    delete vt.second;
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    Pop( key );
    Value* value = NULL;
    PopPtrSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Value, typename Map>
void TPopMaster::PopMapStr_( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string key;
    PopStr( key );
    Value value;
    Pop( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Map>
void TPopMaster::PopMapStrStr( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string key;
    PopStr( key );
    std::string value;
    PopStr( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Value, typename Map>
void TPopMaster::PopMapStrSer( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string key;
    PopStr( key );
    Value value;
    PopSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Value, typename Map>
void TPopMaster::PopMapStrPtrSer( Map& m )
{
  for( auto& vt : m )
    delete vt.second;
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string key;
    PopStr( key );
    Value* value = NULL;
    PopPtrSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMapSer_( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    PopSer( key );
    Value value;
    Pop( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPopMaster::PopMapSerStr( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    PopSer( key );
    std::string value;
    PopStr( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMapSerSer( Map& m )
{
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    PopSer( key );
    Value value;
    PopSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPopMaster::PopMapSerPtrSer( Map& m )
{
  for( auto& vt : m )
    delete vt.second;
  m.clear();

  typedef Map::value_type MapVT;
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    Key key;
    PopSer( key );
    Value* value = NULL;
    PopPtrSer( value );
    m.insert( MapVT(key,value) );
  }
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPopMaster::PopByInsert( Array* pArray )
{
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T t;
    Pop( t );
    pArray->insert( t );
  }
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPopMaster::PopByPush( Array* pArray )
{
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    T t;
    Pop( t );
    pArray->push_back( t );
  }
}
//------------------------------------------------------------------------
template<typename Array>
void TPopMaster::PopStrByPush( Array* pArray )
{
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string str;
    PopStr( str );
    pArray->push_back( str );
  }
}
//------------------------------------------------------------------------
#endif
