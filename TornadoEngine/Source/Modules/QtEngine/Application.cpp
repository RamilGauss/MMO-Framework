/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Application.h"

TApplication::TApplication(int arc, char** arv) : QApplication(arc, arv)
{
  mCB_Timer = NULL;
}
//--------------------------------------------------------------------
void TApplication::SetCallBackTimer(TCallBackRegistrator0* pCB)
{
  mCB_Timer = pCB;
}
//--------------------------------------------------------------------
void TApplication::timerEvent( QTimerEvent * e )
{
  if(mCB_Timer)
    mCB_Timer->Notify();
}
//--------------------------------------------------------------------
