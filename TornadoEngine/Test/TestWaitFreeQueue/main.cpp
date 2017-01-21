/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <boost/atomic/fences.hpp>

#include <boost/pool/poolfwd.hpp>
#include <boost/pool/simple_segregated_storage.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/object_pool.hpp>

#include "DataExchange2Thread.h"
#include "ThreadBoost.h"
#include "BL_Debug.h"
#include "HiTimer.h"

typedef unsigned char TypeStream;

TDataExchange2Thread<TypeStream> g_List2Thread;
char sErr[300];
unsigned int g_Start;

boost::pool<> g_Allocator(sizeof(TypeStream));
TCallBackRegistrator1<TypeStream*> g_CB_Delete;

#define CNT_PRINT_SPEED 1000000
#define USE_BOOST_POOL
//#define TESTING_ONE_THREAD
//#define WITHOUT_ALLOCATE_TEST
#ifdef WITHOUT_ALLOCATE_TEST
TypeStream g_ValueExchange;
#endif
//---------------------------------------------------------------------------------------
class TTestProducer : public TThreadBoost
{
	int mSizeSend;
public:
  TTestProducer()
  {
		mSizeSend = 0;

  }
protected:
  virtual void Work()
  {
    if( mSizeSend==0 )
      g_Start = ht_GetMSCount();

		TypeStream* pData = 
#ifdef WITHOUT_ALLOCATE_TEST
    &g_ValueExchange;
#else
  #ifdef USE_BOOST_POOL
        (TypeStream*)g_Allocator.malloc();
  #else
        new TypeStream(0);
  #endif
#endif
    g_List2Thread.Add(pData);
		mSizeSend++;
  }
};
//---------------------------------------------------------------------------------------
class TTestConsumer : public TThreadBoost
{
  int mSizeRecv;
public:
  TTestConsumer()
  {
    mSizeRecv = 0;
  }
protected:
  virtual void Work()
  {
    TypeStream** pp = g_List2Thread.GetFirst();
		if( pp )
		{
      TypeStream* pData = *pp;
#ifdef WITHOUT_ALLOCATE_TEST
      g_List2Thread.UnlinkData(pp);
#else
  #ifdef USE_BOOST_POOL
      //g_List2Thread.UnlinkData(pp);
      //g_SAllocator::free(pData);
  #else
  #endif
#endif
      g_List2Thread.RemoveFirst();
      mSizeRecv++;
      if( mSizeRecv%CNT_PRINT_SPEED==0 )
      {
        unsigned int now = ht_GetMSCount();
        printf("C speed = %f mcs/byte, %f mcs/pack, %f MB/sec, %f pack/mcs\n", 
          ((now - g_Start)*1000.0f)/(mSizeRecv*sizeof(TypeStream)), 
          ((now - g_Start)*1000.0f)/mSizeRecv, 
          (mSizeRecv*sizeof(TypeStream))/((now - g_Start)*1000.0f),
          mSizeRecv/((now - g_Start)*1000.0f));
      }
		}
  }
};
//---------------------------------------------------------------------------------------
class TDeleter
{
public:
  void Delete(TypeStream* p)
  {
    g_Allocator.free(p);
  }
};
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
#ifdef USE_BOOST_POOL
  TDeleter deleter;
  g_CB_Delete.Register(&TDeleter::Delete, &deleter);
  g_List2Thread.SetCB_DeleteData(&g_CB_Delete);
#endif
#ifdef TESTING_ONE_THREAD
  // test one thread exchanging
  unsigned int cnt = 4000000000;
  unsigned int start = ht_GetMSCount();
  for( unsigned int i = 0 ; i < cnt ; i++)
  {
    TypeStream* p = 
#ifdef USE_BOOST_POOL
			(TypeStream*)g_Allocator.malloc();
#else
			new TypeStream;
#endif
    g_List2Thread.Add(p);
    TypeStream** pp = g_List2Thread.GetFirst();
    g_List2Thread.UnlinkData(pp);
    g_List2Thread.RemoveFirst();
#ifdef USE_BOOST_POOL
		g_Allocator.free(p);
#else
		delete p;
#endif
	}
  unsigned int end = ht_GetMSCount();
  printf("%f kilo\n", cnt/((end - start)/1.0f));
  _getch();
#endif

  TTestProducer producer;
  TTestConsumer consumer;

  producer.Start();
  consumer.Start();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------

/*
  Результаты теста 
  Core2Duo E4600
  Core i3
  Core i5 4430


  TESTING_ONE_THREAD
  

*/