/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef QT_MEDIATOR_H
#define QT_MEDIATOR_H

#include <QObject>
#include <QEvent>

class TCallBackRegistrator0;

// ответственен за взаимодействие потоков с потоком Qt

class TQtMediator : public QObject
{
  Q_OBJECT

  enum{
    eEventExit       = QEvent::User+1,
    eEventHandleTime = QEvent::User+2,
  };

public:
  TQtMediator();
  ~TQtMediator();

  void StopQtThread();

	void CallFromQtThread(TCallBackRegistrator0* pCallBack);
  
  bool IsActive();

protected:
  virtual void customEvent( QEvent * e );
};


#endif