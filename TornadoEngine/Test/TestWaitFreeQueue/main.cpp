/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DataExchange2Thread.h"
#include "ThreadBoost.h"
#include <conio.h>
#include "HiTimer.h"
#include <stdlib.h>
#include <stdio.h>
#include <boost/atomic/fences.hpp>

TDataExchange2Thread<int> g_List2Thread;
//---------------------------------------------------------------------------------------
class TTestProducer : public TThreadBoost
{
  int mNum;
public:
  TTestProducer()
  {
    mNum = 0;
  }
protected:
  virtual void Work()
  {
    unsigned int start = ht_GetMSCount();
    const int cnt = 30000000;
    for( int i = 0 ; i < cnt ; i++ )
    {
      g_List2Thread.Add(&mNum);
    }
    unsigned int d = ht_GetMSCount() - start;
    printf("Producer d = %f mcs\n", (d*1000.0f)/cnt);
  }
};
//---------------------------------------------------------------------------------------
class TTestConsumer : public TThreadBoost
{
  unsigned int mTimeCheckCount;
  enum{eIntervalCheck = 1000,};

public:
  TTestConsumer()
  {
    mTimeCheckCount = 0;
  }
protected:
  virtual void Work()
  {
    int** ppInt = g_List2Thread.GetFirst();
    while(ppInt)
    {
      g_List2Thread.UnlinkData(ppInt);
      g_List2Thread.RemoveFirst();
      ppInt = g_List2Thread.GetFirst();
    }
  }
};
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	//memory_order_relaxed = 0,
	//memory_order_consume = 1,
	//memory_order_acquire = 2,
	//memory_order_release = 4,
	//memory_order_acq_rel = 6, // acquire | release
	//memory_order_seq_cst = 14 // acq_rel | 8

  TTestProducer producer;
  TTestConsumer consumer;
  
  producer.Start();
  consumer.Start();

  _getch();
  return 0;
}
//---------------------------------------------------------------------------------------
