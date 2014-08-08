/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Share.h"
#include "MakerObjectGeneral.h"
#include "IModule.h"
#include "PrototypeGraphicEngine.h"
#include "PrototypeMMOSuperServer.h"
#include "PrototypeMMOMaster.h"
#include "PrototypeMMOClient.h"
#include "PrototypeMMOSlave.h"
#include "PrototypeAloneGUI_Starter.h"
#include "PrototypeMOG.h"
#include "AdapterGraphicEngineGUI_DX9.h"
#include "BL_Debug.h"

static TDevTool_Share* g_DevTool = NULL;

TDevTool_Share::TDevTool_Share()
{
  mMakerObjectGeneral.reset(new TMakerObjectGeneral);

  g_DevTool = this;
}
//-----------------------------------------------------------------------
TDevTool_Share::~TDevTool_Share()
{
  g_DevTool = NULL;
}
//-----------------------------------------------------------------------
TDevTool_Share* TDevTool_Share::Singleton()
{
  return g_DevTool;
}
//-----------------------------------------------------------------------
void TDevTool_Share::SetModulePtr(IModule* pModule)
{
  switch(pModule->GetID())
  {
    case PROTOTYPE_TYPE_DEV_TOOL:
    {
      mComponent.mDev = (PrototypeDevTool*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_GRAPHIC_ENGINE:
    {
      mMyGUI_DX9.reset(new AdapterGraphicEngineGUI_DX9); 
      mComponent.mGraphicEngine = (PrototypeGraphicEngine*)pModule;
      if(mComponent.mGraphicEngine->GetTypeRender()==PrototypeGraphicEngine::DX9)
        mComponent.mGraphicEngine->SetGUI(mMyGUI_DX9.get());
      else
        BL_FIX_BUG();// другая реализация GUI
      mComponent.mGraphicEngine->Init();// создали окно
      mComponent.mGraphicEngine->SetTitleWindow(GetTitleWindow().data());
    }
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:        
    {
      mComponent.mPhysicEngine = (PrototypePhysicEngine*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_SERVER:
    {
      mComponent.mServer = (PrototypeServer*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
    {
      mComponent.mMOG = (PrototypeMOG*)pModule;
      mComponent.mMOG->Init(mMakerObjectGeneral.get());
    }
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_CLIENT:
    {
      mComponent.mNetClient = (PrototypeMMOClient*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_SLAVE:
    {
      mComponent.mNet.Slave = (PrototypeMMOSlave*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_MASTER:
    {
      mComponent.mNet.Master = (PrototypeMMOMaster*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_MMO_ENGINE_SUPER_SERVER:
    {
      mComponent.mNet.SuperServer = (PrototypeMMOSuperServer*)pModule;
    }
      break;
    case PROTOTYPE_TYPE_ALONE_GUI:
    {
      mAloneGUI_Dev.reset(new AdapterAloneGUI_Dev);
      mComponent.mQtSrcEvent = (PrototypeAloneGUI_Starter*)pModule;
      mComponent.mQtGUI = mAloneGUI_Dev->Get();
      mComponent.mQtSrcEvent->SetDev(mAloneGUI_Dev.get());
    }
      break;
    case PROTOTYPE_TYPE_TIMER:
    {
      mComponent.mTimer = (PrototypeTimer*)pModule;
    }
      break;
  }
}
//-----------------------------------------------------------------------
void TDevTool_Share::FreeModulePtr(IModule* pModule)
{
  switch(pModule->GetID())
  {
    case PROTOTYPE_TYPE_GRAPHIC_ENGINE:
    {
      mMyGUI_DX9.reset(NULL); 
      mComponent.mGraphicEngine->ZeroGUI();
    }
    break;
  }
}
//-----------------------------------------------------------------------
std::string TDevTool_Share::GetPathXMLFile()
{
  return "resources.xml";
}
//---------------------------------------------------------------------------------------------
