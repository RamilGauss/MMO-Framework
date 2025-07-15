/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <algorithm>

#include "Base/Common/HiTimer.h"
#include "Base/Common/BL_Debug.h"
#include "Base/Common/GlobalEventHub.h"

#include "MMOEngine/include/EnumMMO.h"

#include "NetTransport/Include/NetWorkThread.h"
#include "NetTransport/Include/INetControl.h"

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
    mIO_Context.run_one(ec);
    if (ec) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("TNetWorkThread::Engine FAIL {}", ec.value());
    }
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Start()
{
    mThread.Start([this]() {Work(); });
}
//----------------------------------------------------------------------------------
void TNetWorkThread::Stop()
{
    mIO_Context.stop();
    mThread.Stop();
}
//----------------------------------------------------------------------------------
bool TNetWorkThread::IsActive() const
{
    return mThread.IsActive();
}
//----------------------------------------------------------------------------------