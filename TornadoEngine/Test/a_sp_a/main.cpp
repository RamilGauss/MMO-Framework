#include "SynchroAbonent.h"
#include "SynchroPoint.h"
#include "ContainerTypes.h"
#include "HiTimer.h"
#include "ShareMisc.h"
#include "BL_Debug.h"
#include "CallBackRegistrator.h"
#include "ContainerArrObj.h"
#include "SaveToFile.h"

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

int main(int argc, char** argv)
{
  bool resSetPath = SetCurrentPathByFile(argv[0]);
  BL_ASSERT(resSetPath);

  TSynchroAbonent GE, Logic;
  TSynchroPoint* pSP = new TSynchroPoint;

  GE.SetSynchroPoint(pSP);
  GE.SetSelfID(NUM_GE);

  Logic.SetSynchroPoint(pSP);
  Logic.SetSelfID(NUM_LOGIC);

  pSP->SetupAfterRegister();

  int i = 0;
  while(1)
  {
    i++;
    TA* pA0 = new TA;
    pA0->abc = i;
    IContainer* pC = new TContainerArrObj<TA>;
    pC->EntrustByCount( (char*)pA0, 1);
    GE.AddEventWithoutCopy( NUM_LOGIC, pC);

    int id_sender;
    IContainer* pEventLogic = Logic.GetEvent(id_sender);
    TA* pA1  = (TA*)pEventLogic->GetPtr();
    int a = 0;
  }

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