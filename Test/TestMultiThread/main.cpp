/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <intrin.h>

#include <boost/lexical_cast.hpp>

#include "ThreadBoost.h"
#include "BL_Debug.h"
#include "HiTimer.h"
#include "ShareMisc.h"

typedef unsigned int Type;
Type g_ArrInitValue [8];

#define COUNT_CALCULATE 20000
#define COUNT_MEASURE_SPEED 10000
//---------------------------------------------------------------------------------------
class TThread : public TThreadBoost
{
  Type* pPtr;
  float mRes;
  int mCountWork;
  unsigned int mStart;
  bool mFlgPrintf;
  float mSpeed;
public:
  void Setup( Type* p, bool isPrintf = false )
  {
    pPtr = p;
    mRes = 1.0f;
    mCountWork = 0;
    mStart = 0;
    mFlgPrintf = isPrintf;
  }
protected:
  virtual void Work()
  {
    if ( mCountWork == 0 )
      mStart = ht_GetMSCount();

    for ( int i = 0; i < COUNT_CALCULATE; i++ )
      mRes = sinf( mRes*pPtr [0] )*cosf( mRes*pPtr [0] );
    mCountWork++;

    if ( mFlgPrintf )
      if ( mCountWork%COUNT_MEASURE_SPEED == 0 )
      {
        unsigned int now = ht_GetMSCount();
        mSpeed = COUNT_MEASURE_SPEED / ( 0.1f*( now - mStart ) );
        mStart = now;
        printf( "speed=%f\n", mSpeed );
      }
  }
};
//---------------------------------------------------------------------------------------
int main( int argc, char** argv )
{
  std::string CPUBrandString;
  GetBrandCPU( CPUBrandString );
  printf( "CPU Brand Name \"%s\"\n", CPUBrandString.data() );

  printf( "Input parameter: number of threads\n" );
  if ( argc != 2 )
  {
    _getch();
    return -1;
  }

  int cntThread = boost::lexical_cast<int>( argv [1] );
  printf( "Arguments number of threads = %d\n", cntThread );
  TThread arrThread [8];

  for ( int i = 0; i < cntThread; i++ )
  {
    if ( i == 0 )
      arrThread [i].Setup( &g_ArrInitValue [i], true );
    else
      arrThread [i].Setup( &g_ArrInitValue [i] );
    arrThread [i].Start();
  }
  printf( "All threads started.\n" );
  _getch();

  for ( int i = 0; i < cntThread; i++ )
    arrThread [i].Stop();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------
/*
  Intel(R) Core(TM) i5 4430 @ 3.00GHz
  Кол-во потоков, Производительность, Относительно 1 потока
  1                    26.7                 100%
  2                    26.2                 173%
  3                    25.7                 289%
  4                    25.4                 381%

  Intel(R) Core(TM)2 Duo CPU E4600  @ 2.40GHz
  1                    8.91                 100%
  2                    8.56                 192%
  3                    4.4                  148%
  4                    4.35                 195%

  Intel(R) Core(TM) i3 4030 @ 3.00GHz
  1                    6.6                  100%
  2                    3.1                  94 % Intel, что за наебалово?
  3                    2.8                  127%
  4                    2.7                  164%

  AMD FX(tm)-4100 Quad-Core Processor @ 3.8GHz (скорость нестабильна)
  1                    14.3                 100%
  2                    6.1                  85%
  3                    6.5                  136%
  4                    6.0                  168%
*/