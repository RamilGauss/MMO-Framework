/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Client.h"
#include "ListModule.h"

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
  return eCountModule;
}
//--------------------------------------------------------------------
int TDevTool_Client::GetModuleID(int index)
{
  switch(index)
  {
    case eModuleDev:
      return MODULE_DEV_TOOL;
    case eModuleGE:
      return MODULE_GRAPHIC_ENGINE;
    case eModulePE:
      return MODULE_PHYSIC_ENGINE;
    case eModuleSE:
      return MODULE_SOUND_ENGINE;
    case eModuleMMO:
      return MODULE_MMO_ENGINE_CLIENT;
    case eModuleTimer:
      return MODULE_TIMER;
  }
  return -1;
}
//--------------------------------------------------------------------
bool TDevTool_Client::IsAddModuleInConveyer(int index)
{
  switch(index)
  {
    case eModuleGE:
    case eModulePE:
    case eModuleSE:
    case eModuleMMO:
    case eModuleTimer:
    //case eModuleDev:
      return true;
  }
  return false;
}
//--------------------------------------------------------------------
