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
