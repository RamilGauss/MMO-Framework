/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_Share.h"
#include "ListModules.h"

#include "ModuleGraphicEngine_Dev.h"
#include "ModuleAloneGUISlave_Dev.h"
#include "ModuleAloneGUIMaster_Dev.h"
#include "ModuleAloneGUISuperServer_Dev.h"

#include "ModuleMMOEngineClient.h"
#include "ModuleMMOEngineSlave.h"
#include "ModuleMMOEngineMaster.h"
#include "ModuleMMOEngineSuperServer.h"

#include "ModuleClientLogic_Dev.h"
#include "ModuleServerLogicSlave_Dev.h"
#include "ModuleServerLogicMaster_Dev.h"
#include "ModuleServerLogicSuperServer_Dev.h"

#include "ModulePhysicEngineClient_Dev.h"
#include "ModulePhysicEngineSlave_Dev.h"

#include "ModuleSoundEngine.h"
#include "ModuleTimer.h"
#include "ModuleDatabase.h"

#include "ParserXMLResource.h"

#include <boost/foreach.hpp>

#include "GraphicEngine_OGRE_MyGUI.h"

namespace nsDevTool_Share
{
  const char* sFileResources = "resources.xml";

  const char* sCore     = "Core";
  const char* sSkin     = "Skin";
  const char* sConveyer = "Conveyer";
}

//using namespace std;
using namespace nsListModules;

TDevTool_Share::TDevTool_Share()
{
  mCBSetupGraphicEngine.Register(&TDevTool_Share::SetupGraphicEngine,this);
  InitMapModules();
}
//-----------------------------------------------------------------------
TDevTool_Share::~TDevTool_Share()
{

}
//-----------------------------------------------------------------------
void TDevTool_Share::Init(std::vector<std::string>& arg)
{
  // загрузка и разбор XML файла (ресурсы)
  TParserXMLResource parser;
  std::string file = nsDevTool_Share::sFileResources;
  bool res = parser.Work(file);

  TResourcesGraphicEngine mGraphicEngine_Resources;
  TResources mGame_Resources;
  TResources mGUI_Resources;
  TResources mGameEngine_Resources;

  parser.GetResultGame(mGame_Resources);
  parser.GetResultGameEngine(mGameEngine_Resources);
  parser.GetResultGUI(mGUI_Resources);
  parser.GetResultGraphicEngine(mGraphicEngine_Resources);
  
  mPluginsCfg = mGraphicEngine_Resources.GetPluginsCfg();

  mGame_Resources.GetResource(mListRGame);
  mGameEngine_Resources.GetResource(mListRGameEngine);
  mGUI_Resources.GetResource(mListRGUI);
  mGraphicEngine_Resources.GetResource(mListRGraphicEngine);
}
//-----------------------------------------------------------------------
IModule* TDevTool_Share::GetModuleByName(const char* sName)
{
  int id = FindIDByNameModule(sName);
  TModuleDev* pModule = FindPtrModuleByID(id);
  if(pModule)
    return pModule;

  switch(id)
  {
    // active modules
    case GraphicEngine: pModule = new TModuleGraphicEngine_Dev;
      // единственный модуль, который требуется настраивать в том же потоке
      ((TModuleGraphicEngine*)pModule)->SetFuncForSetup(&mCBSetupGraphicEngine);
      break;
    case AloneGUISlave:          pModule = new TModuleAloneGUISlave_Dev;         break;
    case AloneGUIMaster:         pModule = new TModuleAloneGUIMaster_Dev;        break;
    case AloneGUISuperServer:    pModule = new TModuleAloneGUISuperServer_Dev;   break;
    case ClientLogic:            pModule = new TModuleClientLogic_Dev;           break;
    case ServerLogicSlave:       pModule = new TModuleServerLogicSlave_Dev;      break;
    case ServerLogicMaster:      pModule = new TModuleServerLogicMaster_Dev;     break;
    case ServerLogicSuperServer: pModule = new TModuleServerLogicSuperServer_Dev;break;
    case PhysicEngineClient:     pModule = new TModulePhysicEngineClient_Dev;    break;
    case PhysicEngineSlave:      pModule = new TModulePhysicEngineSlave_Dev;     break;
    // passive modules
    case MMOEngineClient:        pModule = new TModuleMMOEngineClient;           break;
    case MMOEngineSlave:         pModule = new TModuleMMOEngineSlave;            break;
    case MMOEngineMaster:        pModule = new TModuleMMOEngineMaster;           break;
    case MMOEngineSuperServer:   pModule = new TModuleMMOEngineSuperServer;      break;
    case SoundEngine:            pModule = new TModuleSoundEngine;               break;
    case DataBase:               pModule = new TModuleDataBase;                  break;
    case Timer:                  pModule = new TModuleTimer;                     break;
    default:BL_FIX_BUG();
  }
  pModule->SetID(id);
  pModule->SetName(sName);
  Add(id,pModule);
  return pModule;
}
//-----------------------------------------------------------------------
#define NAME_ID(X) NAME_MODULE(X),X
void TDevTool_Share::InitMapModules()
{
  Add(NAME_ID(GraphicEngine)       );
  Add(NAME_ID(AloneGUISlave)       );
  Add(NAME_ID(AloneGUIMaster)      );
  Add(NAME_ID(AloneGUISuperServer) );
  Add(NAME_ID(MMOEngineClient)     );
  Add(NAME_ID(MMOEngineSlave)      );
  Add(NAME_ID(MMOEngineMaster)     );
  Add(NAME_ID(MMOEngineSuperServer));
  Add(NAME_ID(ClientLogic)         );
  Add(NAME_ID(ServerLogicSlave)    );
  Add(NAME_ID(ServerLogicMaster)   );
  Add(NAME_ID(ServerLogicSlave)    );
  Add(NAME_ID(PhysicEngineClient)  );
  Add(NAME_ID(PhysicEngineSlave)   );
  Add(NAME_ID(SoundEngine)         );
  Add(NAME_ID(DataBase)            );
  Add(NAME_ID(Timer)               );
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
TModuleDev* TDevTool_Share::FindPtrModuleByID(int id)
{
  TMapIntPtrModuleIt fit = mMapID_PtrModules.find(id);
  if(fit==mMapID_PtrModules.end())
    return NULL;
  return fit->second;
}
//-----------------------------------------------------------------------
void TDevTool_Share::Add(int id, TModuleDev* pModule)
{
  if(pModule)
    mMapID_PtrModules.insert(TMapIntPtrModuleVT(id, pModule));
}
//-----------------------------------------------------------------------
void TDevTool_Share::Add(std::string name, int id)
{
  mMapNameID_Modules.insert(TMapStrIntVT(name, id));
}
//-----------------------------------------------------------------------
std::string TDevTool_Share::GetFileDescConveyer()
{
	BOOST_FOREACH(TResources::TPairStrStr& pairNameType, mListRGameEngine)
	{
		if(pairNameType.second==nsDevTool_Share::sConveyer)
			return pairNameType.first;
	}
	BL_FIX_BUG();
	return "";
}
//-----------------------------------------------------------------------
void TDevTool_Share::EventGameEngine(int id, const char* sDesc)
{

}
//-----------------------------------------------------------------------
void TDevTool_Share::SetupGraphicEngine(TModuleDev* pModule)
{
  TModuleGraphicEngine* pGE = (TModuleGraphicEngine*)pModule;
  // настройка перед запуском
  pGE->GetGE()->InitOGRE(mPluginsCfg);
  // пути для ресурсов графического движка
	BOOST_FOREACH(TResources::TPairStrStr& pairNameType, mListRGraphicEngine)
    pGE->GetGE()->AddResource(pairNameType.first, pairNameType.second);
  // оболочка и ядро для GUI
  std::string sSkin, sCore;
  BOOST_FOREACH(TResources::TPairStrStr& pairNameType, mListRGUI)
  {
    if(pairNameType.second==nsDevTool_Share::sCore)
      sCore = pairNameType.first;
    if(pairNameType.second==nsDevTool_Share::sSkin)
      sSkin = pairNameType.first;
  }
  BL_ASSERT(sCore.length() && sSkin.length());
  pGE->GetGE()->InitMyGUI(sCore,sSkin);
}
//-----------------------------------------------------------------------
