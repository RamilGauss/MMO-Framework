/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#if 1
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

struct Foo {};
typedef boost::singleton_pool<Foo, sizeof(TypeStream)> g_SAllocator;
TCallBackRegistrator1<TypeStream*> g_CB_Delete;

#define CNT_PRINT_SPEED 500000
//#define USE_BOOST_POOL
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
#ifdef USE_BOOST_POOL
      (TypeStream*)g_SAllocator::malloc();
#else
      new TypeStream(0);
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
#ifdef USE_BOOST_POOL
      //g_List2Thread.UnlinkData(pp);
      //g_SAllocator::free(pData);
#else
#endif
			g_List2Thread.RemoveFirst();
      mSizeRecv++;
      if( mSizeRecv%CNT_PRINT_SPEED==0 )
      {
        unsigned int now = ht_GetMSCount();
        printf("speed = %f mcs/byte, %f mcs/pack, %f MB/sec, %f pack/mcs\n", 
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
    g_SAllocator::free(p);
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
  //int cnt = 100000000;
  //unsigned int start = ht_GetMSCount();
  //for( int i = 0 ; i < cnt ; i++)
  //{
  //  TypeStream* p = (TypeStream*)g_SAllocator::malloc();
  //  g_List2Thread.Add(p);
  //  TypeStream** pp = g_List2Thread.GetFirst();
  //  g_List2Thread.UnlinkData(pp);
  //  g_List2Thread.RemoveFirst();
  //  g_SAllocator::free(p);
  //}
  //unsigned int end = ht_GetMSCount();
  //printf("%f kilo\n", cnt/((end - start)/1.0f));

  TTestProducer producer;
  TTestConsumer consumer;

  producer.Start();
  consumer.Start();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------
#else
// test stream file
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
#include "LoadFromFile.h"
#include "SaveToFile.h"

typedef unsigned short TypeStream;
TDataExchange2Thread<TypeStream> g_List2Thread;
std::string                      g_PathFile;
char sErr[300];
unsigned int g_Start;

struct Foo {};
typedef boost::singleton_pool<Foo, sizeof(TypeStream)> g_SAllocator;
TCallBackRegistrator1<TypeStream*> g_CB_Delete;

#define CMD_STOP 0xff00
#define CNT_PRINT_SPEED 500000
#define ALLOC_FILE_CACHE 10000000

#define USE_BOOST_POOL
//---------------------------------------------------------------------------------------
class TTestProducer : public TThreadBoost
{
  TLoadFromFile mLoader;
  int mSizeSend;
  TContainer mBuffer;
  int mSizeSendFromBuffer;
public:
  TTestProducer()
  {
    if( mLoader.ReOpen((char*)g_PathFile.data())==false )
    {
      sprintf(sErr,"File open FAIL \"%s\".\n", g_PathFile.data());
      BL_MessageBug(sErr);
      _exit(2);
    }
    mSizeSend = 0;
    mSizeSendFromBuffer = -1;
    mBuffer.SetData(NULL, ALLOC_FILE_CACHE);
  }
protected:
  virtual void Work()
  {
    if( mSizeSend==0 )
      g_Start = ht_GetMSCount();

    if( mSizeSend==mLoader.Size() )
    {
      TypeStream* pCmd = 
#ifdef USE_BOOST_POOL
        (TypeStream*)g_SAllocator::malloc();
#else
        new TypeStream(0);
#endif
      *pCmd = CMD_STOP;
      g_List2Thread.Add(pCmd);
      Stop();
      return;
    }
    TypeStream* pData = 
#ifdef USE_BOOST_POOL
      (TypeStream*)g_SAllocator::malloc();
#else
      new TypeStream(0);
#endif
    *pData = 0;
    ReadFromFile(pData);
    g_List2Thread.Add(pData);
    mSizeSend++;
  }
  void ReadFromFile(TypeStream* pData)
  {
    if( mSizeSendFromBuffer==-1 ||
      mSizeSendFromBuffer==mBuffer.GetSize() )
    {
      unsigned int restSize = mLoader.Size() - mSizeSend;
      if( mBuffer.GetSize() > restSize )
        mBuffer.SetData(NULL, restSize);

      unsigned int resRead = mLoader.Read(mBuffer.GetPtr(), mBuffer.GetSize(), mSizeSend);
      if( resRead!=mBuffer.GetSize() )
      {
        sprintf(sErr,"File read FAIL \"%s\", offset=%d.\n", g_PathFile.data(), mSizeSend);
        BL_MessageBug(sErr);
        _exit(4);
      }
      mSizeSendFromBuffer = 0;
    }
    memcpy( pData, mBuffer.GetPtr() + mSizeSendFromBuffer, sizeof(char));
    mSizeSendFromBuffer++;
  }
};
//---------------------------------------------------------------------------------------
class TTestConsumer : public TThreadBoost
{
  TSaveToFile mSaver;
  int mSizeRecv;
public:
  TTestConsumer()
  {
    std::string sDst = g_PathFile + "_";
    if( mSaver.ReOpen((char*)sDst.data())==false )
    {
      sprintf(sErr,"File open FAIL \"%s\".\n", sDst.data());
      BL_MessageBug(sErr);
      _exit(3);
    }
    mSizeRecv = 0;
  }
protected:
  virtual void Work()
  {
    TypeStream** pp = g_List2Thread.GetFirst();
    if( pp )
    {
      char* pData = (char*)(*pp);
      char* pCmd  = pData + 1;
      if( *pCmd==CMD_STOP )
      {
        mSaver.Close();
        _exit(0);
      }
      mSaver.Write(pData, sizeof(char));
#ifdef USE_BOOST_POOL
      //g_List2Thread.UnlinkData(pp);
      //g_SAllocator::free(pData);
#else
#endif
      g_List2Thread.RemoveFirst();
      mSizeRecv++;
      if( mSizeRecv%CNT_PRINT_SPEED==0 )
      {
        unsigned int now = ht_GetMSCount();
        printf("speed = %f mcs/byte, %f MB/sec\n", ((now - g_Start)*1000.0f)/mSizeRecv, mSizeRecv/((now - g_Start)*1000.0f));
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
    g_SAllocator::free(p);
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
  if( argc==1 )
  {
    sprintf(sErr,"Set path file via argument.\n");
    BL_MessageBug(sErr);
    return 1;
  }
  g_PathFile = argv[1];

  TTestProducer producer;
  TTestConsumer consumer;

  producer.Start();
  consumer.Start();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------
#endif