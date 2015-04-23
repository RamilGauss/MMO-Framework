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

#define NUM_GE    3
#define NUM_LOGIC 1

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

TSynchroPoint* pSP = NULL;

void Thread0(TSynchroAbonent* pAbonent)
{
  int i = 0;
  while(1)
  {
    TA* pA0 = new TA;
    pA0->abc = i;
    IContainer* pC = new TContainerArrObj<TA>;
    pC->EntrustByCount( (char*)pA0, 1);
    pAbonent->AddEventWithoutCopy( NUM_LOGIC, pC);

    int id_sender;
    IContainer* pEventLogic = pAbonent->GetEvent(id_sender);
    if(pEventLogic)
    {
      TA* pA1  = (TA*)pEventLogic->GetPtr();
    }
    i++;
  }
}

void Thread1(TSynchroAbonent* pAbonent)
{
  int i = 0;
  while(1)
  {
    TA* pA0 = new TA;
    pA0->abc = i;
    IContainer* pC = new TContainerArrObj<TA>;
    pC->EntrustByCount( (char*)pA0, 1);
    pAbonent->AddEventWithoutCopy( NUM_GE, pC);

    int id_sender;
    IContainer* pEventLogic = pAbonent->GetEvent(id_sender);
    if(pEventLogic)
    {
      TA* pA1  = (TA*)pEventLogic->GetPtr();
    }
    i++;
  }
}

int main(int argc, char** argv)
{
  bool resSetPath = SetCurrentPathByFile(argv[0]);
  BL_ASSERT(resSetPath);

  TSynchroAbonent GE, Logic;
  pSP = new TSynchroPoint;

  GE.SetSynchroPoint(pSP);
  GE.SetSelfID(NUM_GE);

  Logic.SetSynchroPoint(pSP);
  Logic.SetSelfID(NUM_LOGIC);

  pSP->SetupAfterRegister();

  boost::thread threadGE(boost::bind(&Thread0,&GE));
  boost::thread threadLogic(boost::bind(&Thread0,&Logic));
  ht_msleep(1000000);
  //int i = 0;
  //while(1)
  //{
  //  i++;
  //  TA* pA0 = new TA;
  //  pA0->abc = i;
  //  IContainer* pC = new TContainerArrObj<TA>;
  //  pC->EntrustByCount( (char*)pA0, 1);
  //  GE.AddEventWithoutCopy( NUM_LOGIC, pC);

  //  int id_sender;
  //  IContainer* pEventLogic = Logic.GetEvent(id_sender);
  //  TA* pA1  = (TA*)pEventLogic->GetPtr();
  //  int a = 0;
  //}

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