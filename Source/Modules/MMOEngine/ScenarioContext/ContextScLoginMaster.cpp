/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContextScLoginMaster.h"

using namespace nsMMOEngine;

TContextScLoginMaster::TContextScLoginMaster()
{
    mTimeWait = 0;
}
//------------------------------------------------------------------
TContextScLoginMaster::~TContextScLoginMaster()
{

}
//------------------------------------------------------------------
void TContextScLoginMaster::SetTimeWait(unsigned int v)
{
    mTimeWait = v;
}
//------------------------------------------------------------------
unsigned int TContextScLoginMaster::GetTimeWait()
{
    return mTimeWait;
}
//------------------------------------------------------------------
