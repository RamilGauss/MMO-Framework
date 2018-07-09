/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MyClass.h"
#include "HiTimer.h"
#include "TestClass.h"
#include <conio.h>
#include "Marshaller.h"
#include "MemoryPool.h"
#include "MemoryPoolAllocator.h"
#include "BinarySerializer.h"
#include "lz4.h"

#ifdef _DEBUG
const int cnt = 1000;
#else
const int cnt = 100000000;
#endif

// Тесты
void Benchmark()
{
  const int MARSHALL_COUNT =
#ifdef _DEBUG
    1000000;
#else
    50000000;
#endif
  // настройка
  TMarshaller<TBinarySerializer>::TypeID id = 0;
  TMarshaller<TBinarySerializer> marsh;
  marsh.SetLimitForCompression( 10000 );
  marsh.Add<TTestClass>( id++, TMemoryPoolAllocator::AllocateFunc<TTestClass> );
  TTestClass src;
  TParamClass param;
  src.vParam.push_back( param );
  src.vParam.push_back( param );
  src.vParam.push_back( param );
  src.vParam[0].id = 1;
  src.vParam[1].id = 2;
  src.vParam[2].id = 3;

  TContainerRise c;

  TMarshaller<TBinarySerializer>::TypeID type;
  auto startM = ht_GetMSCount();
  // полный цикл маршаллинга
  for( size_t i = 0; i < MARSHALL_COUNT; i++ )
  {
    marsh.Serialize( &src, c );
    void* p = marsh.Deserialize( c, type );
    TMemoryPoolAllocator::DeallocateFunc( p );
  }
  auto stopM = ht_GetMSCount();
  float speedM = (stopM - startM) * 1000.0f / MARSHALL_COUNT;

  marsh.Serialize( &src, c );
  printf( "size of serialized object = %d\n", c.GetSize() );
  printf( "speed = %f us/1 \n", speedM );
  return;
  //------------------------------------------------

  TContainerRise networkPacket;// transport simulation 

  //TParamClass param;
  auto srcObj = new TTestClass();
  srcObj->vParam.push_back( param );
  srcObj->vParam.push_back( param );
  srcObj->vParam.push_back( param );
  srcObj->vParam[0].id = 1;
  srcObj->vParam[0].pos.x = 2;
  srcObj->vParam[0].pos.y = 3;
  srcObj->vParam[0].pos.z = 4;
  srcObj->vParam[0].rot.w = 5;
  srcObj->vParam[0].rot.x = 6;
  srcObj->vParam[0].rot.y = 7;
  srcObj->vParam[0].rot.z = 8;
  srcObj->vParam[0].vel.x = 9;
  srcObj->vParam[0].vel.y = 10;
  srcObj->vParam[0].vel.z = 11;
  TBinarySerializer serializer;
  printf( "cnt=%d\n", cnt );
  unsigned int start = ht_GetMSCount();
  for( int i = 0; i < cnt; i++ )
    serializer.Serialize( srcObj, networkPacket );
  unsigned int end = ht_GetMSCount();
  float speed = (float) (end - start) / cnt;
  printf( "ser speed = %f us/1\n", speed*1000.0f );
  printf( "size=%d\n", networkPacket.GetSize() );

  serializer.Serialize( srcObj, networkPacket );

  TTestClass* dstObj = new TTestClass();
  start = ht_GetMSCount();
  for( int i = 0; i < cnt; i++ )
    serializer.Deserialize( dstObj, networkPacket );
  end = ht_GetMSCount();
  speed = (float) (end - start) / cnt;
  printf( "deser speed = %f us/1\n", speed*1000.0f );
}
//-----------------------------------------------------------------------------------------
int main( int argc, char** argv )
{
  try
  {
    Benchmark();
  }
  catch( std::exception e )
  {
    printf( "Exception %s\n", e.what() );
  }
  _getch();
  return 0;
}

/*
Эксперименты с JSON boost
#include <sstream>
#include <map>
#include <set>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

void example()
{
  // Write json.
  ptree pt;
  ptree children;
  ptree child;

  child.put("1", 1);
  child.put("2", 2);
  child.put("3", 3);

  children.push_back(std::make_pair("1", child));
  children.push_back(std::make_pair("2", child));
  children.push_back(std::make_pair("3", child));

  pt.add_child("MyArray", children);

  std::ostringstream buf;
  write_json(buf, pt, false);
  std::string json = buf.str(); // {"foo":"bar"}

  // Read json.
  ptree pt2;
  std::istringstream is(json);
  read_json(is, pt2);
  std::string foo = pt2.get<std::string>("foo");
}

std::string map2json(const std::map<std::string, std::string>& map)
{
  ptree pt;
  for (auto& entry : map)
    pt.put(entry.first, entry.second);
  std::ostringstream buf;
  write_json(buf, pt, false);
  return buf.str();
}

int main(int argc, char** argv)
{
  typedef std::map<std::string, std::string> TMapStrStr;
  typedef TMapStrStr::value_type TMapStrStrVT;
  typedef TMapStrStr::iterator TMapStrStrIt;
  TMapStrStr map;
  map.insert(TMapStrStrVT("1", "1"));
  map2json(map);

  example();

  return 0;
}
*/
