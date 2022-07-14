/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <algorithm>
#include "MMOEngine/include/EnumMMO.h"

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
    Stop();
}
//-----------------------------------------------------------------
void TNetWorkThread::Work()
{
    boost::system::error_code ec;
    mIO_Context.run_one(ec);
    if (ec) {
        GetLogger(STR_NAME_NET_TRANSPORT)->WriteF_time("TNetWorkThread::Engine FAIL %d\n", ec.value());
    }
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Stop()
{
    mIO_Context.stop();
    TThreadBoost::Stop();
}
//----------------------------------------------------------------------------------
