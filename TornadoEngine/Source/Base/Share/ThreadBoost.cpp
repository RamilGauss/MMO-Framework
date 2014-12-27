/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ThreadBoost.h"

#include <boost/thread/thread.hpp>
#include "HiTimer.h"

TThreadBoost::TThreadBoost()
{
  flgActive   = false;
  flgNeedStop = false;
}
//-----------------------------------------------------------------
TThreadBoost::~TThreadBoost()
{
  Stop();
}
//-----------------------------------------------------------------
void TThreadBoost::Engine()
{
  flgNeedStop = false;
  flgActive   = true;

  StartEvent();

  while(flgNeedStop==false)
    Work();

  flgActive = false;

  StopEvent();
}
//----------------------------------------------------------------------------------
void TThreadBoost::Start()
{
  boost::thread work_thread(boost::bind(&TThreadBoost::Engine, this));

  while(IsActive()==false)
    ht_msleep(eWaitFeedBack);
}
//----------------------------------------------------------------------------------
void TThreadBoost::Stop()
{
  flgNeedStop = true;

  while(IsActive())
    ht_msleep(eWaitFeedBack);
}
//----------------------------------------------------------------------------------
bool TThreadBoost::IsActive()
{
  return flgActive;
}
//---------------------------------------------------------------------------------
