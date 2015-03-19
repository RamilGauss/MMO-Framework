/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleAloneGUI.h"
#include "QtEngine.h"

TModuleAloneGUI::TModuleAloneGUI()
{
  mArgc = 0;
  mArgv = NULL;
}
//--------------------------------------------------------------
TModuleAloneGUI::~TModuleAloneGUI()
{

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
bool TModuleAloneGUI::Work()
{
  if(mQt->IsActive()==false)
    return false;

  InputFromModules();
  //OutputFromModule();// не имеет смысла вызывать, потому что все события обрабатываются в формах
  return true;
}
//--------------------------------------------------------------
void TModuleAloneGUI::SetArg(int argc, char** argv)
{
  mArgc = argc;
  mArgv = argv;
}
//--------------------------------------------------------------
