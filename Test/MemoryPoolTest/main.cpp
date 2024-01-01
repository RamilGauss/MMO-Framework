#include "Base/Common/HiTimer.h"
#include "Base/Common/MemoryObjectPoolAllocator.h"
#include "fmt/core.h"
#include "Base/Common/MemoryPool.h"

#include <functional>
#include <algorithm>

#include "DataExchange2ThreadElement.h"
#include <boost/pool/pool.hpp>

struct A
{
};
typedef A TestingClass;
//---------------------------------------------------------------------------------------------
#if _DEBUG
const long TEST_COUNT = 100;
const long ELEMENT_COUNT = 100;
#else
const long TEST_COUNT = 30000;
const long ELEMENT_COUNT = 10000;
#endif
TestingClass* g_Arr[ELEMENT_COUNT];
TMemoryPool<TestingClass>::TPointerDesc* g_DescArr[ELEMENT_COUNT];

struct TTestResult
{
  std::string name;
  int timePerCycle;
};
std::vector<TTestResult> g_TestResult;
//---------------------------------------------------------------------------------------------
void Test_NewDelete( int testCount, int elementCount )
{
  for ( long i = 0; i < testCount; i++ )
  {
    for ( long e = 0; e < elementCount; e++ )
    {
      auto pA = new TestingClass();
      delete pA;
    }
  }
}
//---------------------------------------------------------------------------------------------
void Test_MemoryObjectPoolAllocator( int testCount, int elementCount )
{
  for ( long i = 0; i < testCount; i++ )
  {
    for ( long e = 0; e < elementCount; e++ )
      g_Arr[e] = TMemoryObjectPoolAllocator::AllocateFunc<TestingClass>();

    for ( long e = 0; e < elementCount; e++ )
      TMemoryObjectPoolAllocator::DeallocateFunc( g_Arr[e] );
  }
}
//---------------------------------------------------------------------------------------------
void Test_MemoryPool( int testCount, int elementCount )
{
  auto pMP = SingletonManager()->Get<TMemoryPool<TestingClass>>();

  for ( long i = 0; i < testCount; i++ )
  {
    for ( long e = 0; e < elementCount; e++ )
      g_DescArr[e] = pMP->Pop( 1 );

    for ( long e = 0; e < elementCount; e++ )
      pMP->Push( g_DescArr[e] );
  }
}
//---------------------------------------------------------------------------------------------
void Test_BoostAllocator( int testCount, int elementCount )
{
  auto allocator = new boost::pool<>( sizeof( TestingClass ) );

  for ( long i = 0; i < testCount; i++ )
  {
    for ( long e = 0; e < elementCount; e++ )
      g_Arr[e] = ( TestingClass*) allocator->malloc();

    for ( long e = 0; e < elementCount; e++ )
      allocator->free( g_Arr[e] );
  }
}
//---------------------------------------------------------------------------------------------
void Test_MemoryObjectPool( int testCount, int elementCount )
{
  auto pMOP = SingletonManager()->Get<TMemoryObjectPool<TestingClass>>();

  for ( long i = 0; i < testCount; i++ )
  {
    for ( long e = 0; e < elementCount; e++ )
      g_Arr[e] = pMOP->Pop();

    for ( long e = 0; e < elementCount; e++ )
      pMOP->Push( g_Arr[e] );
  }
}
//---------------------------------------------------------------------------------------------
void Test( std::string testName, std::function<void( int, int )> func )
{
  auto start = ht_GetMSCount();

  func( TEST_COUNT, ELEMENT_COUNT );

  auto stop = ht_GetMSCount();
  auto delta = stop - start;

  TTestResult result;
  result.timePerCycle = ( int) ( ( 1000000.0 * delta ) / ( TEST_COUNT * ELEMENT_COUNT ) );
  result.name = testName;
  g_TestResult.push_back( result );

  fmt::print( "test ended {}\n", g_TestResult.size() );
}
//---------------------------------------------------------------------------------------------

//###
class X
{
public:
  int a;
};
class Y
{
public:
  int a;
};
class Z
{
public:
  int a;
};
class W
{
public:
  int a;
};
//###


int main( int argc, char* argv[] )
{
  //###
  auto pTypeId = SingletonManager()->Get<TRunTimeTypeIndex<>>();

  auto x = pTypeId->type<X>();
  auto y = pTypeId->type<Y>();
  auto z = pTypeId->type<Z>();
  auto w = pTypeId->type<W>();
  auto xz0 = pTypeId->type<X, Z>();
  auto xz1 = pTypeId->type<X, Z>();
  auto zx = pTypeId->type<Z, X>();

  auto xyz = pTypeId->type<X, Y, Z>();
  auto xzy = pTypeId->type<X, Z, Y>();
  auto zxy = pTypeId->type<Z, X, Y>();
  auto xyzw = pTypeId->type<X, Y, Z, W>();
  //###

  Test( "MemoryObjectPoolAllocator", Test_MemoryObjectPoolAllocator );
  Test( "MemoryPool", Test_MemoryPool );
  Test( "Boost", Test_BoostAllocator );
  Test( "MemoryObjectPool", Test_MemoryObjectPool );
  Test( "new/delete", Test_NewDelete );

  int maxTime = 0;
  for ( auto& test : g_TestResult )
  {
    maxTime = std::max( maxTime, test.timePerCycle );
  }

  for ( auto& test : g_TestResult )
  {
    auto percentage = ( ( 100.0f * test.timePerCycle ) / maxTime );
    fmt::print( "{:30}: time per cycle {:6} ns - {:6.2f} %\n", test.name, test.timePerCycle, percentage );
  }

  getchar();
  return 0;
}
//---------------------------------------------------------------------------------------------
