/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleAloneGUI.h"
#include "QtEngine.h"

#include "LogicEventCallBack.h"
#include <QApplication>
#include "QtEventNotify.h"

TModuleAloneGUI::TModuleAloneGUI()
{
  mArgc = 0;
  mArgv = NULL;
}
//--------------------------------------------------------------
void TModuleAloneGUI::StartEvent()
{
  mQt.reset(new TQtEngine);
  mQt->Start(mArgc, mArgv);
}
//--------------------------------------------------------------
void TModuleAloneGUI::StopEvent()
{
  mQt->Stop();
}
//--------------------------------------------------------------
bool TModuleAloneGUI::WorkInherit()
{
  InputFromSynchroPoint();
  OutputToSynchroPoint();

  // что бы разгрузить поток
  ht_msleep(eSleep);
  return true;
}
//--------------------------------------------------------------
void TModuleAloneGUI::SetArg(int argc, char** argv)
{
  mArgc = argc;
  mArgv = argv;
}
//--------------------------------------------------------------
void TModuleAloneGUI::Input(int id_sender, void* p, int size)
{
  if(id_sender!=mLogicID)
    return;

  TBaseLogicPacket* pBLP = (TBaseLogicPacket*)p;
  switch(pBLP->type)
  {
    case nsBaseLogicPacket::eCallBack0:
    {
      // создать customEvent для Qt
      TQtEventNotify* pE = new TQtEventNotify;
      pE->mCB = ((TLogicEventCallBack*)pBLP)->mCB;
      QCoreApplication::postEvent( mQt->GetApp(), pE);
    }
      break;
    default:;
  }
}
//--------------------------------------------------------------
