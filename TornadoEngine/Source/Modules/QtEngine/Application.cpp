/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Application.h"
#include "CallBackRegistrator.h"
#include "QtEventNotify.h"

TApplication::TApplication(int arc, char** arv) : QApplication(arc, arv)
{

}
//--------------------------------------------------------------------
void TApplication::customEvent(QEvent *pE)
{
  switch(pE->type())
  {
    case TQtEventNotify::TypeEvent:
      ((TQtEventNotify*)pE)->mCB.Notify();
      break;
    default:;
  }
}
//--------------------------------------------------------------------
