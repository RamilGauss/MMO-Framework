/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Share.h"
#include "ModuleDev.h"
#include "ListModule.h"

static TDevTool_Share* g_DevTool = NULL;

TDevTool_Share::TDevTool_Share()
{
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
void TDevTool_Share::SetModulePtr(ModuleDev* pModule)
{
  switch(pModule->GetID())
  {
    case MODULE_DEV_TOOL:
      mComponent.mDev.reset(new AdapterDevTool);
      pModule->SetPrototypeDev(mComponent.mDev.get());
      break;
    case MODULE_GRAPHIC_ENGINE:
      mComponent.mGraphicEngine.reset(new AdapterGraphicEngine);
      pModule->SetPrototypeDev(mComponent.mGraphicEngine.get());
      break;
    case MODULE_PHYSIC_ENGINE: 
      mComponent.mPhysicEngine.reset(new AdapterPhysicEngine);
      pModule->SetPrototypeDev(mComponent.mPhysicEngine.get());
      break;
    case MODULE_SERVER:
      mComponent.mServer.reset(new AdapterServer);
      pModule->SetPrototypeDev(mComponent.mServer.get());
      break;
    case MODULE_MMO_ENGINE_CLIENT:
      mComponent.mClient.reset(new AdapterMMO<nsMMOEngine::TClient>);
      pModule->SetPrototypeDev(mComponent.mClient.get());
      mComponent.mMMO = mComponent.mClient->Get();
      break;
    case MODULE_MMO_ENGINE_SLAVE:
      mComponent.mSlave.reset(new AdapterMMO<nsMMOEngine::TSlave>);
      pModule->SetPrototypeDev(mComponent.mSlave.get());
      mComponent.mMMO = mComponent.mSlave->Get();
      break;
    case MODULE_MMO_ENGINE_MASTER:
      mComponent.mMaster.reset(new AdapterMMO<nsMMOEngine::TMaster>);
      pModule->SetPrototypeDev(mComponent.mMaster.get());
      mComponent.mMMO = mComponent.mMaster->Get();
      break;
    case MODULE_MMO_ENGINE_SUPER_SERVER:
      mComponent.mSuperServer.reset(new AdapterMMO<nsMMOEngine::TSuperServer>);
      pModule->SetPrototypeDev(mComponent.mSuperServer.get());
      mComponent.mMMO = mComponent.mSuperServer->Get();
      break;
    case MODULE_ALONE_GUI:
      mComponent.mQtSrcEvent.reset(new AdapterAloneGUI);
      pModule->SetPrototypeDev(mComponent.mQtSrcEvent.get());
      mComponent.mQtSrcEvent->Start();
      mComponent.mQtGUI = mComponent.mQtSrcEvent->Get();
      break;
    case MODULE_TIMER:
      mComponent.mTimer.reset(new AdapterTimer);
      pModule->SetPrototypeDev(mComponent.mTimer.get());
      break;
  }
}
//-----------------------------------------------------------------------
void TDevTool_Share::FreeModulePtr(ModuleDev* pModule)
{

}
//-----------------------------------------------------------------------
std::string TDevTool_Share::GetPathXMLFile()
{
  return "resources.xml";
}
//---------------------------------------------------------------------------------------------
