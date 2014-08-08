/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterAloneGUI_Dev.h"
#include "MakerQtLib.h"
#include "IQtLib.h"
#include "Logger.h"

AdapterAloneGUI_Dev::AdapterAloneGUI_Dev()
{
  GetLogger()->Register(STR_NAME_QT);

  TMakerQtLib maker;
  mQtLib = maker.New();
}
//--------------------------------------------------------------
AdapterAloneGUI_Dev::~AdapterAloneGUI_Dev()
{
  Stop();
}
//--------------------------------------------------------------
void AdapterAloneGUI_Dev::Start()
{
  mQtLib->Init(0,NULL);
}
//--------------------------------------------------------------
void AdapterAloneGUI_Dev::Stop()
{
  TMakerQtLib maker;
  maker.Delete(mQtLib);
  mQtLib = NULL;
}
//--------------------------------------------------------------
IQtLib* AdapterAloneGUI_Dev::Get()
{
  return mQtLib;
}
//--------------------------------------------------------------

