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

	mTimeStart = -1;
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

  StopEvent();

  flgActive = false;
}
//----------------------------------------------------------------------------------
void TThreadBoost::Start()
{
  boost::thread work_thread(boost::bind(&TThreadBoost::Engine, this));

  while(IsActive()==false)
    ht_msleep(eWaitFeedBack);

	mTimeStart = ht_GetMSCount();
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
unsigned int TThreadBoost::GetTimeLastStart()
{
	return mTimeStart;
}
//---------------------------------------------------------------------------------
unsigned int TThreadBoost::GetTimeWork()
{
	if(IsActive()==false)
		return 0;
	unsigned int now_ms = ht_GetMSCount();
	return now_ms - mTimeStart;
}
//---------------------------------------------------------------------------------
