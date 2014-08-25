/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterAloneGUI.h"
#include "MakerQtLib.h"
#include "IQtLib.h"
#include "Logger.h"

AdapterAloneGUI::AdapterAloneGUI()
{
  GetLogger()->Register(STR_NAME_QT);
  mQtLib = NULL;
}
//--------------------------------------------------------------
AdapterAloneGUI::~AdapterAloneGUI()
{
  Stop();
}
//--------------------------------------------------------------
void AdapterAloneGUI::Start()
{
  TMakerQtLib maker;
  mQtLib = maker.New();
  mQtLib->Init(0,NULL);
}
//--------------------------------------------------------------
void AdapterAloneGUI::Stop()
{
  TMakerQtLib maker;
  maker.Delete(mQtLib);
  mQtLib = NULL;
}
//--------------------------------------------------------------
IQtLib* AdapterAloneGUI::Get()
{
  return mQtLib;
}
//--------------------------------------------------------------

