/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "StopWatch.h"
#include "HiTimer.h"

void TStopWatch::Start()
{
    mBegin = ht_GetMSCount();
    mStamp = mBegin;
}
//------------------------------------------------------------------------------------------
unsigned int TStopWatch::Stamp()
{
    mBegin = mStamp;
    mStamp = ht_GetMSCount();

    return mStamp - mBegin;
}
//------------------------------------------------------------------------------------------