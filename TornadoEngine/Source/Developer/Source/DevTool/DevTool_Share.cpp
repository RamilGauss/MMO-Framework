/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Share.h"
#include "ListModules.h"

#include "ModuleGraphicEngine_Dev.h"
#include "ModuleAloneGUI_Dev.h"
#include "ModuleModuleMMOClient_Dev.h"
#include "ModuleModuleMMOSlave_Dev.h"
#include "ModuleModuleMMOMaster_Dev.h"
#include "ModuleModuleMMOSuperServer_Dev.h"

#include "ModuleServerLogicSlave_Dev.h"
#include "ModuleServerLogicMaster_Dev.h"
#include "ModuleServerLogicSuperServer_Dev.h"

#include "ModulePhysicEngine_Dev.h"
#include "ModuleModuleTimer.h"

#include "Client.h"
#include "Master.h"
#include "Slave.h"
#include "SuperServer.h"

using namespace std;
using namespace nsListModules;

TDevTool_Share::TDevTool_Share()
{
  InitMapModules();
}
//-----------------------------------------------------------------------
TDevTool_Share::~TDevTool_Share()
{

}
//-----------------------------------------------------------------------
void TDevTool_Share::Init(vector<string>& arg)
{
  // загрузка и разбор XML файла (ресурсы)
}
//-----------------------------------------------------------------------
IModule* TDevTool_Share::GetModuleByName(const char* sName)
{
  IModule* pModule = NULL;
  int id = FindIDByNameModule(sName);
  switch(id)
  {
    case MODULE_GRAPHIC_ENGINE:
      pModule = mGraphicEngine.reset(new TModuleGraphicEngine);
      break;
    case MODULE_ALONE_GUI:
      pModule = mAloneGUI.reset(new TModuleAloneGUI);
      break;
    case MODULE_MMO_ENGINE_CLIENT:
      pModule = mClient.reset(new TModuleMMOEngine<nsMMOEngine::TClient>);
      break;
    case MODULE_MMO_ENGINE_SLAVE:
      pModule = mClient.reset(new TModuleMMOEngine<nsMMOEngine::TSlave>);
      break;
    case MODULE_MMO_ENGINE_MASTER:
      pModule = mClient.reset(new TModuleMMOEngine<nsMMOEngine::TMaster>);
      break;
    case MODULE_MMO_ENGINE_SUPER_SERVER:
      pModule = mClient.reset(new TModuleMMOEngine<nsMMOEngine::TSuperServer>);
      break;
    case MODULE_PHYSIC_ENGINE: 
      pModule = mPhysicEngine.reset(new TModulePhysicEngine);
      break;
    case MODULE_SERVER:
      pModule = mServer.reset(new TModuleServer);
      break;
    default:return NULL;
  }
  AddModule(pModule);
  return pModule;
}
//-----------------------------------------------------------------------
void TDevTool_Share::InitMapModules()
{
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(GraphicEngine),        GraphicEngine))
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(AloneGUI),             AloneGUI);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(MMOEngineClient),      MMOEngineClient);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(MMOEngineSlave),       MMOEngineSlave);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(MMOEngineMaster),      MMOEngineMaster);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(MMOEngineSuperServer), MMOEngineSuperServer);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(PhysicEngine),         PhysicEngine);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(ServerEngine),         ServerEngine);
  mMapNameID_Modules.insert(TMapStrIntVT(NAME_MODULE(SoundEngine),          SoundEngine);
}
//-----------------------------------------------------------------------
int TDevTool_Share::FindIDByNameModule(std::string name)
{
  TMapStrIntIt fit = mMapNameID_Modules.find(name);
  if(fit==mMapNameID_Modules.end())
    return Undef;
  return fit->second;
}
//-----------------------------------------------------------------------
