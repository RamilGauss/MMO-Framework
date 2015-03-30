/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/thread/thread.hpp>

#include "QtEngine.h"
#include <QtCore/QTextCodec>
#include <QThread>

#include "Application.h"
#include "HiTimer.h"
#include "BL_Debug.h"
#include "Logger.h"

#define STR_NAME_QT "QtEngine"

TQtEngine::TQtEngine()
{
  mApplication = NULL;
}
//-------------------------------------------------------------------
TQtEngine::~TQtEngine()
{
  Stop();
}
//-------------------------------------------------------------------
void TQtEngine::Start(int argc, char** argv)
{
  mArgc = argc;
  mArgv = argv;

  boost::thread work_thread(boost::bind(&TQtEngine::Work, this));

  while(IsActive()==false)
    ht_msleep(eFeedBack);
}
//-------------------------------------------------------------------
void TQtEngine::Work()
{
  GetLogger()->Register(STR_NAME_QT);
  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread start.\n");

  QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
  mApplication = new TApplication(mArgc, mArgv);
  mApplication->exec();

  lock();
  delete mApplication;
  mApplication = NULL;
  unlock();

  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread stop.\n");
}
//--------------------------------------------------------------------
void TQtEngine::Stop()
{
  if(IsActive()==false)
    return;

  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread: request stop.\n");
  
  QApplication::quit();

  while(IsActive())
    ht_msleep(eFeedBack);
}
//--------------------------------------------------------------------
bool TQtEngine::IsActive()
{
  lock();
  if(mApplication==NULL)
  {
    unlock();
    return false;
  }
  bool isActive = mApplication->thread()->isRunning();
  unlock();

  return isActive;
}
//--------------------------------------------------------------------
QApplication* TQtEngine::GetApp()
{
  return mApplication;
}
//--------------------------------------------------------------------
