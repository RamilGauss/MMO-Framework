/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "CallBackRegistrator.h"

// Класс нужен для обработки таймерного кванта от Qt

class TApplication : public QApplication
{
  Q_OBJECT

  TCallBackRegistrator0* mCB_Timer;
public:
  TApplication(int arc, char** arv);

  void SetCallBackTimer(TCallBackRegistrator0* pCB);
protected:
  virtual void timerEvent( QTimerEvent * e );
};


#endif