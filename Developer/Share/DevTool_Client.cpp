/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Client.h"

TDevTool_Client::TDevTool_Client()
{

}
//--------------------------------------------------------------------
TDevTool_Client::~TDevTool_Client()
{

}
//--------------------------------------------------------------------
int TDevTool_Client::GetCountModule()
{
  return CNT_MODULE;
}
//--------------------------------------------------------------------
int TDevTool_Client::GetModuleID(int index)
{
  switch(index)
  {
    case MODULE_DEV:
      return PROTOTYPE_TYPE_DEV_TOOL;
    case MODULE_GE:
      return PROTOTYPE_TYPE_GRAPHIC_ENGINE;
    case MODULE_MMO_CLIENT:
      return PROTOTYPE_TYPE_MMO_ENGINE_CLIENT;
    case MODULE_MOG:
      return PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL;
    case MODULE_TIMER:
      return PROTOTYPE_TYPE_TIMER;
  }
  return -1;
}
//--------------------------------------------------------------------
bool TDevTool_Client::IsAddModuleInConveyer(int index)
{
  switch(index)
  {
    case MODULE_GE:
    case MODULE_MMO_CLIENT:
    case MODULE_MOG:
    case MODULE_TIMER:
      return true;
  }
  return false;
}
//--------------------------------------------------------------------
