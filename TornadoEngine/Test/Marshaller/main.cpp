/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HiTimer.h"
#include "TestClass.h"
#include <conio.h>
#include "Marshaller.h"
#include "MemoryPool.h"
#include "MemoryPoolAllocator.h"
#include "BinarySerializer.h"
#include "lz4.h"
#include "BinaryMarshaller.h"

#ifdef _DEBUG
const int cnt = 1000;
#else
const int cnt = 100000000;
#endif

void FillTestSrc( nsBS::TTestStruct& t )
{
  t.password = "012345678";
  t.port = 123;
  t.flag = true;

  // array
  t.strSet = {"0","1","2"};
  t.intSet = {0, 1, 2};
  t.boolList = {false, true, false};
  t.numList = {0, 1, 2, 3};
  t.numVector = {0, 1, 2};

  // ser array
  t.baseVec = {nsBS::TBaseStruct( "0123456789" ), nsBS::TBaseStruct( "0123456789" ), nsBS::TBaseStruct( "0123456789" )};
  t.basePtrVec = {nullptr, new nsBS::TBaseStruct( "0123456789" ), nullptr};
  t.baseSPVec = {std::shared_ptr<nsBS::TBaseStruct>( new nsBS::TBaseStruct( "0123456789" ) ), std::shared_ptr<nsBS::TBaseStruct>()};

  // map
  t.intIntMap = {{0,0},{1,1}};
  t.intBoolMap = {{0,false},{1,true}};
  t.intStrMap = {{ 0, "0" }, { 1, "1" }};

  t.strStrMap = {{ "0", "0" }, { "1", "1" }};
  t.strIntMap = {{ "0", 0 }, { "1", 1 }};
  t.strBoolMap = {{ "0", false }, { "1", true }};

  // map
  t.strBaseMap = {{"0", nsBS::TBaseStruct( "0123456789" )}, {"1",nsBS::TBaseStruct( "0123456789" )}};
  t.strBasePtrMap = {{"0", new nsBS::TBaseStruct( "0123456789" )}, {"1", nullptr }};
  t.strBaseSPMap = {{"0", std::shared_ptr<nsBS::TBaseStruct>()}, {"1",std::shared_ptr<nsBS::TBaseStruct>( new nsBS::TBaseStruct( "0123456789" ) )}};

  t.intBaseMap = {{0, nsBS::TBaseStruct( "0123456789" )}, {1,nsBS::TBaseStruct( "0123456789" )}};
  t.intBasePtrMap = {{0, nullptr}, {1,new nsBS::TBaseStruct( "0123456789" )}};
  t.intBaseSPMap = {{0, std::shared_ptr<nsBS::TBaseStruct>( new nsBS::TBaseStruct( "0123456789" ) )}, {1,std::shared_ptr<nsBS::TBaseStruct>()}};
}

// Тесты
void Benchmark()
{
  const int MARSHALL_COUNT =
#ifdef _DEBUG
    1000000;
#else
    50000000;
#endif
  nsBS::TTestStruct testSrc;
  nsBS::TTestStruct testDst;
  FillTestSrc( testSrc );

  TContainerRise c;
  nsBinary::TBinaryMarshaller marshaller;
  marshaller.SetLimitForCompression( 1000 );
  //marshaller.Pack( &testSrc, c );
  //auto id = marshaller.GetID( c.GetPtr(), c.GetSize() );
  //switch ( id )
  //{
  //  case nsBinary::TBinaryMarshaller::eTTestStruct:
  //  {
  //    auto p = marshaller.HandleUnpack<TTestStruct>( c.GetPtr(), c.GetSize() );
  //    marshaller.FillUnpack<TTestStruct>( &testDst, c.GetPtr(), c.GetSize() );
  //  }
  //  break;
  //}

  // настройка
  TTestClass src;
  TParamClass param;
  src.vParam.push_back( param );
  src.vParam.push_back( param );
  src.vParam.push_back( param );
  src.vParam[0].id = 1;
  src.vParam[1].id = 2;
  src.vParam[2].id = 3;

  TTestClass dst;
  auto pDst = &dst;
  //marshaller.Serialize( &src, c );
  marshaller.Pack( &src, c );
  auto startM = ht_GetMSCount();
  // полный цикл маршаллинга
  for ( size_t i = 0; i < MARSHALL_COUNT; i++ )
  {
    //marshaller.Serialize( &src, c );
    //marshaller.Fill( pDst, c.GetPtr(), c.GetSize() );

    marshaller.Pack( &src, c );
    marshaller.Unpack( c.GetPtr(), c.GetSize() );

    //auto p = marshaller.HandleUnpack<TTestClass>( c.GetPtr(), c.GetSize() );
    //nsBinary::TBinaryMarshaller::Deallocate<TTestClass>( p );

    //marshaller.FillUnpack<TTestClass>( pDst, c.GetPtr(), c.GetSize() );
  }
  auto stopM = ht_GetMSCount();
  float speedM = ( stopM - startM ) * 1000.0f / MARSHALL_COUNT;

  printf( "size of serialized object = %d\n", c.GetSize() );
  printf( "speed = %f us/1 \n", speedM );
  return;
  //------------------------------------------------

  //TContainerRise networkPacket;// transport simulation 

  ////TParamClass param;
  //auto srcObj = new TTestClass();
  //srcObj->vParam.push_back( param );
  //srcObj->vParam.push_back( param );
  //srcObj->vParam.push_back( param );
  //srcObj->vParam[0].id = 1;
  //srcObj->vParam[0].pos.x = 2;
  //srcObj->vParam[0].pos.y = 3;
  //srcObj->vParam[0].pos.z = 4;
  //srcObj->vParam[0].rot.w = 5;
  //srcObj->vParam[0].rot.x = 6;
  //srcObj->vParam[0].rot.y = 7;
  //srcObj->vParam[0].rot.z = 8;
  //srcObj->vParam[0].vel.x = 9;
  //srcObj->vParam[0].vel.y = 10;
  //srcObj->vParam[0].vel.z = 11;
  //TBinarySerializer serializer;
  //printf( "cnt=%d\n", cnt );
  //unsigned int start = ht_GetMSCount();
  //for ( int i = 0; i < cnt; i++ )
  //  serializer.Serialize( srcObj, networkPacket );
  //unsigned int end = ht_GetMSCount();
  //float speed = (float) ( end - start ) / cnt;
  //printf( "ser speed = %f us/1\n", speed*1000.0f );
  //printf( "size=%d\n", networkPacket.GetSize() );

  //serializer.Serialize( srcObj, networkPacket );

  //TTestClass* dstObj = new TTestClass();
  //start = ht_GetMSCount();
  //for ( int i = 0; i < cnt; i++ )
  //  serializer.Deserialize( dstObj, networkPacket );
  //end = ht_GetMSCount();
  //speed = (float) ( end - start ) / cnt;
  //printf( "deser speed = %f us/1\n", speed*1000.0f );
}
//-----------------------------------------------------------------------------------------
int main( int argc, char** argv )
{
  try
  {
    Benchmark();
  }
  catch ( std::exception e )
  {
    printf( "Exception %s\n", e.what() );
  }
  _getch();
  return 0;
}
