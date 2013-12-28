/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <algorithm>
#include <boost/thread/thread.hpp>

#include "NetWorkThread.h"

#include "HiTimer.h"
#include "INetControl.h"
#include "BL_Debug.h"
#include "Logger.h"

using namespace std;

TNetWorkThread::TNetWorkThread()
{
  flgActive   = false;
  flgNeedStop = false;
}
//-----------------------------------------------------------------
TNetWorkThread::~TNetWorkThread()
{
  Done();
}
//-----------------------------------------------------------------
void TNetWorkThread::Engine()
{
  flgNeedStop = false;
  flgActive = true;
  while(!flgNeedStop)
  {
    boost::system::error_code ec;
    mIO_Service.run(ec);
    if(ec)
      GetLogger(STR_NAME_NET_TRANSPORT)->
        WriteF_time("TNetWorkThread::Engine FAIL %d\n",ec.value());
  }
  flgActive = false;
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Start()
{
  boost::thread work_thread(boost::bind(&TNetWorkThread::Engine, this));

  while(IsActive()==false)
    ht_msleep(eWaitFeedBack);
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Stop()
{
  flgNeedStop = true;

  mIO_Service.stop();
  while(IsActive())
    ht_msleep(eWaitFeedBack);
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Done()
{

}
//----------------------------------------------------------------------------------
