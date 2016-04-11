/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef QtEngineH
#define QtEngineH

#include "TypeDef.h"
#include "Mutex.h"

class TApplication;
class QApplication;

// ответственен за старт, стоп и запрос кванта времени

class DllExport TQtEngine
{
  TApplication* mApplication;
  
  int mArgc;
  char** mArgv;

  enum
  {
    eFeedBack = 50,
  };

  TMutex mMutexApplication;
public:
  TQtEngine();
  ~TQtEngine();
  
  void Start(int argc, char** argv);
  void Stop();

  bool IsActive();

  QApplication* GetApp();
protected:
  void Work();
private:
  void lock()  {mMutexApplication.lock();}
  void unlock(){mMutexApplication.unlock();}
};


#endif