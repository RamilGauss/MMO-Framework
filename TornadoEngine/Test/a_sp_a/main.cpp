/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SynchroAbonent.h"
#include "SynchroPoint.h"
#include "ContainerTypes.h"
#include "HiTimer.h"
#include "ShareMisc.h"
#include "BL_Debug.h"
#include "CallBackRegistrator.h"
#include "ContainerArrObj.h"
#include "SaveToFile.h"
#include <boost/thread/thread.hpp>
#include "ThreadBoost.h"
#include "StatisticValue.h"

#define NUM_GE    3
#define NUM_LOGIC 1
//---------------------------------------------------------------------------------------
//Цель теста: тестирование связки Точка синхронизация-Абоненты
class TA
{
public:
  ~TA()
  {
    abc = 0;
  }
  int abc;
};
//---------------------------------------------------------------------------------------
class TTestAbonent : public TThreadBoost
{
  TSynchroAbonent mSAbonent;
  
  TSynchroPoint*  mSPoint;
  int             mDstID;

  unsigned int mStartAdd;

  TStatType_double mStatTimeAdd;
  unsigned int mTimePrint;
  enum{eIntervalPrint=700,};
public:
  TTestAbonent();
  void Setup(TSynchroPoint* pSP, int id_reciver, int id_sender);
protected:
  virtual void Work();

  void PrintStatistic();
};
//---------------------------------------------------------------------------------------
TTestAbonent::TTestAbonent() : mStatTimeAdd(100)
{
  mSPoint = NULL;
  mDstID  = 0;
  mStartAdd = ht_GetMSCount();
  mTimePrint = 0;
}
//---------------------------------------------------------------------------------------
void TTestAbonent::Setup(TSynchroPoint* pSP, int selfID, int dstID)
{
  mDstID  = dstID;
  mSPoint = pSP;

  mSAbonent.SetSynchroPoint(pSP);
  mSAbonent.SetSelfID(selfID);
}
//---------------------------------------------------------------------------------------
void TTestAbonent::Work()
{
  int i = 0;
  while(1)
  {
    if( (rand() % 100) == 0) // имитация случайности пакетов
    {
      TA* pA0 = new TA;
      pA0->abc = i;
      IContainer* pC = new TContainerArrObj<TA>;
      pC->EntrustByCount( (char*)pA0, 1);
      mSAbonent.AddEventWithoutCopy( mDstID, pC);

      unsigned int now_ms = ht_GetMSCount();
      unsigned int dTime = now_ms - mStartAdd;
      mStatTimeAdd.add(dTime);
      mStartAdd = now_ms; 
    }

    int id_sender;
    IContainer* pEvent = mSAbonent.GetEvent(id_sender);
    if(pEvent)
    {
      TA* pA1 = (TA*)pEvent->GetPtr();
    }
    i++;

    PrintStatistic();
  }
}
//---------------------------------------------------------------------------------------
void TTestAbonent::PrintStatistic()
{
  unsigned int now_ms = ht_GetMSCount();
  if(mTimePrint + eIntervalPrint < now_ms)
  {
    printf("Stat time adding %f\n", mStatTimeAdd.aver());
    mTimePrint = now_ms;
  }
}
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  bool resSetPath = SetCurrentPathByFile(argv[0]);
  BL_ASSERT(resSetPath);

  TSynchroPoint* pSP = new TSynchroPoint;

  TTestAbonent testGE, testLogic;
  testGE.Setup(pSP, NUM_LOGIC, NUM_GE);
  testLogic.Setup(pSP, NUM_GE, NUM_LOGIC );

  pSP->SetupAfterRegister();

  testGE.Start();
  testLogic.Start();
  ht_msleep(1000000);
  
  delete pSP;
  return 0;
}
/*

#include <iostream>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include "HiTimer.h"
#include "ThreadBoost.h"

boost::mutex io_mutex;
boost::condition_variable condition;

class TThread : public TThreadBoost
{
  bool flgNotify;
public:
  TThread(){flgNotify=true;}
  virtual void Work()
  {
    if(flgNotify)
      condition.notify_all();
    flgNotify = false;

    ht_msleep(50);
  }
};

TThread arrThread[4];

void WorkThread0()
{
  boost::mutex::scoped_lock lock(io_mutex);
  while(lock.owns_lock()==false) 
    ht_msleep(50);

  for( int i = 0 ; i < 4 ; i++)
    arrThread[i].Start();

  lock.unlock();
}

int main()
{
  boost::mutex::scoped_lock lock(io_mutex);
  boost::thread workThread(&WorkThread0);
  condition.wait(lock);
  for( int i = 0 ; i < 4 ; i++)
    arrThread[i].Stop();
  return 0;
}*/