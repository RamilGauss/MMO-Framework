/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Server.h"
#include "ListModule.h"


TDevTool_Server::TDevTool_Server()
{

}
//--------------------------------------------------------------------
TDevTool_Server::~TDevTool_Server()
{

}
//--------------------------------------------------------------------
int TDevTool_Server::GetCountModule()
{
  return eCountModule;
}
//--------------------------------------------------------------------
int TDevTool_Server::GetModuleID(int index)
{
  switch(index)
  {
    case eModuleDev:
      return MODULE_DEV_TOOL;
    case eModuleMMO:
      return GetIDPrototypeMMOEngineServer();
    case eModuleQt:
      return MODULE_ALONE_GUI;
    case eModuleTimer:
      return MODULE_TIMER;
    case eModuleServer:
      return MODULE_SERVER;
  }
  return -1;
}
//--------------------------------------------------------------------
bool TDevTool_Server::IsAddModuleInConveyer(int index)
{
  switch(index)
  {
    case eModuleMMO:
    case eModuleTimer:
    case eModuleServer:
      return true;
  }
  return false;
}
//--------------------------------------------------------------------
void TDevTool_Server::SetLoadConveyer(int procent)
{
  mComponent.mMMO->SetLoad(procent);
}
//--------------------------------------------------------------------
int TDevTool_Server::GetTimeRefresh_ms()
{
  return 100;
}
//--------------------------------------------------------------------
