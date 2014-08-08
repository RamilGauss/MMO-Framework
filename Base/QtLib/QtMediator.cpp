/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "QtMediator.h"

#include <QtGui/QApplication>

#include "HiTimer.h"
#include "IQtLib.h"
#include "CallBackRegistrator.h"

class TEventCallBack : public QEvent
{
public:
	TEventCallBack(QEvent::Type type):
			QEvent(type)
	{
		mCallBack=NULL;
	}
	~TEventCallBack()
	{
		delete mCallBack;
	}
	TCallBackRegistrator0* mCallBack;
};
//--------------------------------------------------------------------
//--------------------------------------------------------------------
TQtMediator::TQtMediator()
{

}
//--------------------------------------------------------------------
TQtMediator::~TQtMediator()
{
}
//--------------------------------------------------------------------
void TQtMediator::StopQtThread()
{
  // отослать событие потоку Qt
  QEvent* pEvent = new QEvent((QEvent::Type)eEventExit);
  QApplication::postEvent(this,pEvent);
}
//--------------------------------------------------------------------
void TQtMediator::customEvent( QEvent * e )
{
	TEventCallBack* pEvent = (TEventCallBack*)e;
  switch(e->type())
  {
    case eEventExit:
      QApplication::quit();
      break;
    case eEventHandleTime:
      pEvent->mCallBack->Notify();
      break;
    default:;
  }
}
//--------------------------------------------------------------------
void TQtMediator::CallFromQtThread(TCallBackRegistrator0* pCallBack)
{
	TEventCallBack* pEvent = new TEventCallBack((QEvent::Type)eEventHandleTime);
	pEvent->mCallBack = pCallBack;
	QApplication::postEvent(this,pEvent);
}
//--------------------------------------------------------------------
