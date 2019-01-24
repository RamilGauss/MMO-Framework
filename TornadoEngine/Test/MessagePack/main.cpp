/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "lz4.h"
#include <msgpack.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include "HiTimer.h"
#include "ContainerRise.h"
#include "MessagePackSerializer.h"
#include "Marshaller.h"
#include "MemoryPoolAllocator.h"

#ifdef _DEBUG
#define TEST_COUNT 3000
#else
#define TEST_COUNT 10000000
#endif

struct TFloat3
{
  unsigned char x = 0;
  unsigned char y = 0;
  unsigned char z = 0;
  MSGPACK_DEFINE( x, y, z );
};

struct TFloat4
{
  float x = 1.2345678f;
  float y = 2.2345678f;
  float z = 3.2345678f;
  float w = 4.2345678f;
  MSGPACK_DEFINE( x, y, z, w );
};

struct TLocationInfo
{
  TLocationInfo() {}
  TLocationInfo( int id ) { robotID = id; }
  int robotID;
  TFloat3 pos;
  TFloat4 orient;
  TFloat3 velocity;
  MSGPACK_DEFINE( robotID, pos, orient, velocity );
};

struct TSynchronizationData
{
  //std::vector<TLocationInfo> infoVec;
  //MSGPACK_DEFINE( infoVec );
  std::string s;// = "0123456789";
  MSGPACK_DEFINE( s );
};

int main( void )
{
  short id = 0;
  TMarshaller<TMessagePackSerializer<msgpack::object_handle>> marsh;
  marsh.SetLimitForCompression( 10000 );
  marsh.Add<TSynchronizationData>( id++, TMemoryPoolAllocator::AllocateFunc<TSynchronizationData> );

  TContainerRise c;
  TSynchronizationData src;
  //src.infoVec.push_back( TLocationInfo( 1 ) );
  //src.infoVec.push_back( TLocationInfo( 2 ) );
  //src.infoVec.push_back( TLocationInfo( 3 ) );

  TMarshaller<TMessagePackSerializer<msgpack::object_handle>>::TypeID type;
  auto startM = ht_GetMSCount();
  // полный цикл маршаллинга
  for( size_t i = 0; i < TEST_COUNT; i++ )
  {
    marsh.Serialize( &src, c );
    void* p = marsh.Deserialize( c, type );
    TMemoryPoolAllocator::DeallocateFunc( p );
  }
  auto stopM = ht_GetMSCount();
  float speedM = (stopM - startM) * 1000.0f / TEST_COUNT;

  marsh.Serialize( &src, c );
  printf( "size of serialized object = %d\n", c.GetSize());
  printf( "speed = %f us/1 \n", speedM );
  return 0;
  //------------------------------------------------
  //TSynchronizationData src;
  //src.infoVec.push_back( TLocationInfo( 1 ) );
  //src.infoVec.push_back( TLocationInfo( 2 ) );
  //src.infoVec.push_back( TLocationInfo( 3 ) );

  TContainerRise buffer;
  TMessagePackSerializer<msgpack::object_handle> msgPackSerializer;
  auto start = ht_GetMSCount();

  for( int i = 0; i < TEST_COUNT; i++ )
  {
    msgPackSerializer.Serialize( &src, buffer, 0 );
  }

  auto end = ht_GetMSCount();
  auto delta = end - start;
  auto speed = delta * 1000.0f / TEST_COUNT;
  printf( "Pack speed %f us/1\n", speed );

  start = ht_GetMSCount();
  TSynchronizationData dst;

  for( int i = 0; i < TEST_COUNT; i++ )
  {
    msgPackSerializer.Deserialize( &src, buffer );
  }
  end = ht_GetMSCount();
  delta = end - start;
  speed = delta * 1000.0f / TEST_COUNT;
  printf( "Unpack speed %f us/1\n", speed );
  return 0;
}

