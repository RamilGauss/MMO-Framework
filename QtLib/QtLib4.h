/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef QT_LIB_4_H
#define QT_LIB_4_H

#include "IQtLib.h"

class TQtMediator;
class QApplication;

// ответственен за старт, стоп и запрос кванта времени

class TQtLib4 : public IQtLib
{
  QApplication* mApplication;
  TQtMediator* mQtComm;

  enum{
    eFeedBack = 30,// мс
  };

public:
  TQtLib4();
  virtual ~TQtLib4();
  
  virtual void Init(int argc, char** argv);
protected:
  // запрос на квант времени потока Qt
	virtual void CallFromQtThread(TCallBackRegistrator0* pCallBack);

	void Thread(int argc, char** argv);
  void StopQtThread();
};


#endif