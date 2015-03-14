#include "ThreadBoost.h"
#include <boost/thread/thread_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/condition_variable.hpp>

#include "SynchroAbonent.h"
#include "SynchroPoint.h"
#include "ContainerTypes.h"
#include "HiTimer.h"
#include "ShareMisc.h"
#include "BL_Debug.h"

//#include "ParserXMLConveyer.h"

#define NUM_GE  0
#define NUM_PE  1
#define NUM_SE  2

//Цель теста: тестирование связки Точка синхронизация-Абоненты

int main(int argc, char** argv)
{
  bool resSetPath = SetCurrentPathByFile(argv[0]);
  BL_ASSERT(resSetPath);

  //TParserXMLConveyer parser;

  //std::string fileConveyer = "conveyer.xml";
  //std::string variant = "Client";

  //parser.Work(fileConveyer, variant);

  //typedef std::vector<std::string> TVecStr;
  //typedef std::vector< TVecStr > TVecVecStr;
  //typedef std::map<std::string,TVecStr> TMapStrVecStr;

  //TMapStrVecStr mMapDst_SrcModule;
  //TVecVecStr mVecVecStrModule;
  //parser.GetResult(mVecVecStrModule, mMapDst_SrcModule);


  TSynchroAbonent GE, PE, SE;
  TSynchroPoint* pSP = new TSynchroPoint;

  GE.SetSynchroPoint(pSP);
  GE.SetSelfID(NUM_GE);
  GE.Register(NUM_PE);

  SE.SetSynchroPoint(pSP);
  SE.SetSelfID(NUM_SE);
  SE.Register(NUM_PE);

  PE.SetSynchroPoint(pSP);
  PE.SetSelfID(NUM_PE);
  PE.Register(NUM_GE);
  
  //char eventGE[] = {0x1,};
  //GE.AddEventCopy( &eventGE[0], sizeof(eventGE));
  //TContainer* pEvent1 = PE.GetEvent(NUM_GE);

  char eventPE[] = {0x2,};
  PE.AddEventWithoutCopy( &eventPE[0], sizeof(eventPE));

  TContainer* pEventGE = GE.GetEvent(NUM_PE);
  char* pGE  = pEventGE->GetPtr();
  int sizeGE = pEventGE->GetSize();

  TContainer* pEventSE = SE.GetEvent(NUM_PE);
  char* pSE  = pEventSE->GetPtr();
  int sizeSE = pEventSE->GetSize();

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