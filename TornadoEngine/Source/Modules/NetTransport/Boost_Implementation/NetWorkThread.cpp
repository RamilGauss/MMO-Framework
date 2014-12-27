/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <algorithm>
//#include <boost/thread/thread.hpp>

#include "NetWorkThread.h"

#include "HiTimer.h"
#include "INetControl.h"
#include "BL_Debug.h"
#include "Logger.h"

TNetWorkThread::TNetWorkThread()
{

}
//-----------------------------------------------------------------
TNetWorkThread::~TNetWorkThread()
{

}
//-----------------------------------------------------------------
void TNetWorkThread::Work()
{
  boost::system::error_code ec;
  mIO_Service.run(ec);
  if(ec)
    GetLogger(STR_NAME_NET_TRANSPORT)->
    WriteF_time("TNetWorkThread::Engine FAIL %d\n",ec.value());
}
//----------------------------------------------------------------------------------
void TNetWorkThread::StartEvent()
{

}
//----------------------------------------------------------------------------------
void TNetWorkThread::StopEvent()
{
  mIO_Service.stop();
}
//----------------------------------------------------------------------------------
