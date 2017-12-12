/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PushMasterH
#define PushMasterH

#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>

#include "BreakPacket.h"
#include "TypeDef.h"

class ISerializable;

class DllExport TPushMaster
{
  TBreakPacket mCollectorMember;
public:
  void Clear();
  TContainer GetBuffer();
public:
  //bool, unsigned char, char, unsigned short, short, unsigned int, int, float, double
  template<typename T>
  void Push( T& t, bool copy = false );
  //std::string
  void PushStr( std::string& str );
  //ISerializable
  template<typename T>
  void PushSer( T& serializable );
  //ISerializable*
  void PushPtrSer( ISerializable* ser );

  //std::vector/list/set
  // unsigned char, char, unsigned short, short, unsigned int, int, float, double
  template<typename T, typename Array>
  void PushArray( Array& array );
  //std::vector/list/set<std::string>
  template<typename Array>
  void PushArrayStr( Array& array );
  //std::vector/list/set<ISerializable>
  template<typename T, typename Array>
  void PushArraySer( Array& array );
  //std::vector/list/set<ISerializable*>
  template<typename Array>
  void PushArrayPtrSer( Array& array );

  // std::map
  template<typename Key, typename Value, typename Map>
  void PushMap__( Map& m );
  template<typename Key, typename Map>
  void PushMap_Str( Map& m );
  template<typename Key, typename Value, typename Map>
  void PushMap_Ser( Map& m );
  template<typename Key, typename Map>
  void PushMap_PtrSer( Map& m );

  template<typename Value, typename Map>
  void PushMapStr_( Map& m );
  template<typename Map>
  void PushMapStrStr( Map& m );
  template<typename Value, typename Map>
  void PushMapStrSer( Map& m );
  template<typename Map>
  void PushMapStrPtrSer( Map& m );

  template<typename Key, typename Value, typename Map>
  void PushMapSer_( Map& m );
  template<typename Key, typename Map>
  void PushMapSerStr( Map& m );
  template<typename Key, typename Value, typename Map>
  void PushMapSerSer( Map& m );
  template<typename Key, typename Map>
  void PushMapSerPtrSer( Map& m );
private:
  void PushSize( int& size );
};
//------------------------------------------------------------------------
template<typename T>
void TPushMaster::Push( T& t, bool copy )
{ 
  mCollectorMember.PushBack((char*)&t, sizeof(T), copy);
}
//------------------------------------------------------------------------
template<typename T>
void TPushMaster::PushSer( T& serializable )
{
  serializable.Serialize( this );
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPushMaster::PushArray( Array& array )
{
  int size = array.size();
  PushSize( size );
  Array::iterator bit = array.begin();
  Array::iterator eit = array.end();
  while( bit != eit )
  {
    T& t = *bit;
    Push<T>( t );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Array>
void TPushMaster::PushArrayStr( Array& array )
{
  int size = array.size();
  PushSize( size );
  Array::iterator bit = array.begin();
  Array::iterator eit = array.end();
  while( bit != eit )
  {
    std::string& t = *bit;
    PushStr( t );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename T, typename Array>
void TPushMaster::PushArraySer( Array& array )
{
  int size = array.size();
  PushSize( size );
  Array::iterator bit = array.begin();
  Array::iterator eit = array.end();
  while( bit != eit )
  {
    T& t = *bit;
    PushSer<T>( t );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Array>
void TPushMaster::PushArrayPtrSer( Array& array )
{
  int size = array.size();
  PushSize( size );
  Array::iterator bit = array.begin();
  Array::iterator eit = array.end();
  while( bit != eit )
  {
    ISerializable* t = *bit;
    PushPtrSer( t );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPushMaster::PushMap__( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    Push<Key>( key );
    Value& value = bit->second;
    Push<Value>( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPushMaster::PushMap_Str( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    Push<Key>( key );
    std::string& value = bit->second;
    PushStr( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPushMaster::PushMap_Ser( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    Push<Key>( key );
    Value& value = bit->second;
    PushSer<Value>( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPushMaster::PushMap_PtrSer( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    Push<Key>( key );
    ISerializable* value = bit->second;
    PushPtrSer( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Value, typename Map>
void TPushMaster::PushMapStr_( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    std::string& key = *((std::string*)&(bit->first));
    PushStr( key );
    Value& value = bit->second;
    Push<Value>( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Map>
void TPushMaster::PushMapStrStr( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    std::string& key = *((std::string*)&(bit->first));
    PushStr( key );
    std::string& value = bit->second;
    PushStr( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Value, typename Map>
void TPushMaster::PushMapStrSer( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    std::string& key = *((std::string*)&(bit->first));
    PushStr( key );
    Value& value = bit->second;
    PushSer( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Map>
void TPushMaster::PushMapStrPtrSer( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    std::string& key = *((std::string*)&(bit->first));
    PushStr( key );
    ISerializable* value = bit->second;
    PushPtrSer( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPushMaster::PushMapSer_( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    PushSer( key );
    Value& value = bit->second;
    Push( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPushMaster::PushMapSerStr( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    PushSer( key );
    std::string& value = bit->second;
    PushStr( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Value, typename Map>
void TPushMaster::PushMapSerSer( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    PushSer( key );
    Value& value = bit->second;
    PushSer( value );
    bit++;
  }
}
//------------------------------------------------------------------------
template<typename Key, typename Map>
void TPushMaster::PushMapSerPtrSer( Map& m )
{
  int size = m.size();
  PushSize( size );
  typedef Map::iterator MapIt;
  MapIt bit = m.begin();
  MapIt eit = m.end();
  while( bit != eit )
  {
    Key& key = *((Key*)&(bit->first));
    PushSer( key );
    ISerializable* value = bit->second;
    PushPtrSer( value );
  }
}
//------------------------------------------------------------------------
#endif
