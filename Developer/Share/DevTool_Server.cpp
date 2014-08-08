/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Server.h"
#include "PrototypeMMOBase.h"


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
  return CNT_MODULE;
}
//--------------------------------------------------------------------
int TDevTool_Server::GetModuleID(int index)
{
  switch(index)
  {
    case MODULE_DEV:
      return PROTOTYPE_TYPE_DEV_TOOL;
    case MODULE_MMO:
      return GetIDPrototypeMMOEngineServer();
    case MODULE_QT:
      return PROTOTYPE_TYPE_ALONE_GUI;
    case MODULE_TIMER:
      return PROTOTYPE_TYPE_TIMER;
  }
  return -1;
}
//--------------------------------------------------------------------
bool TDevTool_Server::IsAddModuleInConveyer(int index)
{
  switch(index)
  {
    case MODULE_MMO:
    case MODULE_TIMER:
      return true;
  }
  return false;
}
//--------------------------------------------------------------------
void TDevTool_Server::SetLoadConveyer(int procent)
{
  mComponent.mNet.Base->SetLoad(procent);
}
//--------------------------------------------------------------------
int TDevTool_Server::GetTimeRefresh_ms()
{
  return 100;
}
//--------------------------------------------------------------------
