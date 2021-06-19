/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "lz4.h"        /* LZ4_VERSION_STRING */
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <string.h>
#include "HiTimer.h"

#ifdef _DEBUG
#define TEST_COUNT 3000
#else
#define TEST_COUNT 10000000
#endif

int main( int /*argc*/, char** /*argv*/ )
{
  std::srand( std::time( nullptr ) );
  unsigned char src [] = { 145, 147 ,148 , 1, 147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,148 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,202 ,64 ,135 ,129 ,148 ,147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,148 ,2 ,147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,148 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,202 ,64 ,135 ,129 ,148 ,147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,148 ,3 ,147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,148 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 ,202 ,64 ,135 ,129 ,148 ,147 ,202 ,63 ,158 ,6 ,81 ,202 ,64 ,15 ,3 ,41 ,202 ,64 ,79 ,3 ,41 };
  const int srcSize = sizeof( src );

  int compressedCapacity = 1024;
  char* compressedData = new char[compressedCapacity];
  auto original = (const char*) &src[0];

  int compressRes = 0;

  auto start = ht_GetMSCount();

  for( int i = 0; i < TEST_COUNT; i++ )
  {
    compressRes = LZ4_compress_default( original, compressedData, srcSize, compressedCapacity );
  }
  auto end = ht_GetMSCount();
  auto delta = end - start;
  auto speed = delta * 1000.0f / TEST_COUNT;
  printf( "Compress speed %f us/1\n", speed );

  int decompressedCapacity = 1024;
  char* decompressedData = new char[decompressedCapacity];
  int decompressedRes = 0;

  start = ht_GetMSCount();
  for( int i = 0; i < TEST_COUNT; i++ )
  {
    decompressedRes = LZ4_decompress_safe( compressedData, decompressedData, compressRes, decompressedCapacity );
  }
  end = ht_GetMSCount();
  delta = end - start;
  speed = delta * 1000.0f / TEST_COUNT;
  printf( "Decompress speed %f us/1\n", speed );

  auto cmp = memcmp( original, decompressedData, decompressedRes );
  return 0;
}
