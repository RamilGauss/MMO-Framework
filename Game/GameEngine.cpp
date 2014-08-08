/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameEngine.h"
#include "IModule.h"
#include "PrototypeList.h"
#include "AdapterGraphicEngine.h"
#include "AdapterMMOSuperServer.h"
#include "AdapterMMOMaster.h"
#include "AdapterMMOSlave.h"
#include "AdapterMMOClient.h"
#include "AdapterAloneGUI_Starter.h"
#include "AdapterServer.h"
#include "AdapterPhysicEngine.h"
#include "AdapterTimer.h"
#include "AdapterMOG.h"
#include "PrototypeDevTool.h"


TGameEngine::TGameEngine()
{

}
//-------------------------------------------------------------------
TGameEngine::~TGameEngine()
{

}
//-------------------------------------------------------------------
void TGameEngine::SetupDevModule()
{
  int count = mDevTool->GetCountModule();
  for( int i = 0 ; i < count ; i++ )
  {
    int id_module = mDevTool->GetModuleID(i);
    IModule* pModule = NewModule(id_module, mDevTool->IsAddModuleInConveyer(i));
    mDevTool->SetModulePtr(pModule);
    PushModule(pModule);
  }
}
//-------------------------------------------------------------------
void TGameEngine::FreeDevModule()
{
  int count = mDevTool->GetCountModule();
  for( int i = 0 ; i < count ; i++ )
  {
    IModule* pModule = GetModulePtr(i);
    mDevTool->FreeModulePtr(pModule);
    DeleteModule(pModule);
  }
}
//-------------------------------------------------------------------
IModule* TGameEngine::NewModule(int id_module, bool flgUseInConveyer)
{
  IModule* pModule = NULL;
  switch(id_module)
  {
    case PROTOTYPE_TYPE_DEV_TOOL:
      pModule = new PrototypeDevTool;
      break;
    case PROTOTYPE_TYPE_GRAPHIC_ENGINE:
      pModule = new AdapterGraphicEngine;
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_CLIENT:
      pModule = new AdapterMMOClient;
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_SLAVE:
      pModule = new AdapterMMOSlave;
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_MASTER:
      pModule = new AdapterMMOMaster;
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_SUPER_SERVER:
      pModule = new AdapterMMOSuperServer;
      break;
    case PROTOTYPE_TYPE_ALONE_GUI:
      pModule = new AdapterAloneGUI_Starter;
      break;
    case PROTOTYPE_TYPE_SERVER:
      pModule = new AdapterServer;
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:
      pModule = new AdapterPhysicEngine;
      break;
    case PROTOTYPE_TYPE_TIMER:
      pModule = new AdapterTimer;
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
      pModule = new AdapterMOG;
      break;
  }
  pModule->SetID(id_module);
  pModule->SetUseInConveyer(flgUseInConveyer);
  return pModule;
}
//-------------------------------------------------------------------
void TGameEngine::DeleteModule(IModule* pModule)
{
  delete pModule;
}
//-------------------------------------------------------------------
int TGameEngine::GetVersionRelease()
{
	return 1;
}
//-------------------------------------------------------------------
