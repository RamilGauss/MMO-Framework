/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Slave.h"
#include "SlaveLogic.h"

TDevTool_Slave::TDevTool_Slave()
{

}
//---------------------------------------------------------------------------
TDevTool_Slave::~TDevTool_Slave()
{

}
//---------------------------------------------------------------------------
std::string TDevTool_Slave::GetVariantConveyer()
{
  return "Slave";
}
//---------------------------------------------------------------------------
TModuleDev* TDevTool_Slave::GetModuleLogic()
{
  return new TSlaveLogic;
}
//---------------------------------------------------------------------------
