/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScLoginSlave.h"

using namespace nsMMOEngine;

TContextScLoginSlave::TContextScLoginSlave()
{
  flgConnectToMaster = false;
  mTimeWaitAnswerFromMaster = 0;
}
//------------------------------------------------------------------
TContextScLoginSlave::~TContextScLoginSlave()
{

}
//------------------------------------------------------------------
bool TContextScLoginSlave::IsConnect()
{
  return flgConnectToMaster;
}
//------------------------------------------------------------------
void TContextScLoginSlave::SetConnect(bool v)
{
  flgConnectToMaster = v;
}
//------------------------------------------------------------------
unsigned int TContextScLoginSlave::GetTimeWait()
{
  return mTimeWaitAnswerFromMaster;
}
//------------------------------------------------------------------
void TContextScLoginSlave::SetTimeWait(unsigned int v)
{
  mTimeWaitAnswerFromMaster = v;
}
//------------------------------------------------------------------
