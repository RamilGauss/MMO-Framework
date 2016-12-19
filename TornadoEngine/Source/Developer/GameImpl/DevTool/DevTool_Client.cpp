/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Client.h"
#include "ClientLogic.h"

TDevTool_Client::TDevTool_Client()
{

}
//---------------------------------------------------------------------------
TDevTool_Client::~TDevTool_Client()
{

}
//---------------------------------------------------------------------------
std::string TDevTool_Client::GetVariantConveyer()
{
  return "Client";
}
//---------------------------------------------------------------------------
TModuleDev* TDevTool_Client::GetModuleLogic()
{
  return new TClientLogic;
}
//---------------------------------------------------------------------------
