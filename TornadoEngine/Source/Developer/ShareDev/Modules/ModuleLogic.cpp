/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleLogic.h"

#include "ModuleGraphicEngine.h"
#include "ModuleMMOEngineClient.h"
#include "ModuleMMOEngineSlave.h"
#include "ModuleMMOEngineMaster.h"
#include "ModuleMMOEngineSuperServer.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"
#include "ModuleTimer.h"
#include "ModuleDatabase.h"

static TModuleLogic* g_ptrModuleLogic = NULL;

#define DEF_USE_ID_MODULE(MODULE) \
if( MODULE ) mSetUseID_Module.insert(MODULE->GetID());


TModuleLogic::TModuleLogic()
{
  g_ptrModuleLogic = this;
  flgNeedExit = false;
}
//--------------------------------------------------------------------
void TModuleLogic::SetComponents(TComponents components)
{
  mComp = components;

	mSetUseID_Module.clear();

	mSetUseID_Module.insert(GetID());// логика есть всегда

	DEF_USE_ID_MODULE( mComp.pGraphicEngine )
	DEF_USE_ID_MODULE( mComp.pMMOEngineClient )
	DEF_USE_ID_MODULE( mComp.pMMOEngineSlave )
	DEF_USE_ID_MODULE( mComp.pMMOEngineMaster )
	DEF_USE_ID_MODULE( mComp.pMMOEngineSuperServer )
	DEF_USE_ID_MODULE( mComp.pPhysicEngine )
	DEF_USE_ID_MODULE( mComp.pSoundEngine )
	DEF_USE_ID_MODULE( mComp.pDataBase )
	DEF_USE_ID_MODULE( mComp.pTimer )
}
//--------------------------------------------------------------------
TFactoryGameItem* TModuleLogic::GetFGI()
{
  return &mFGI;
}
//--------------------------------------------------------------------
TFactoryBehaviourPatternModel* TModuleLogic::GetFBPM()
{
  return &mFBPM;
}
//--------------------------------------------------------------------
TModuleLogic* TModuleLogic::Get()
{
  return g_ptrModuleLogic;
}
//--------------------------------------------------------------------
void TModuleLogic::Exit( int reason )
{
  flgNeedExit = true;
}
//--------------------------------------------------------------------
bool TModuleLogic::NeedExit()
{
  return flgNeedExit;
}
//--------------------------------------------------------------------
TComponents* TModuleLogic::GetC()
{
  return &mComp;
}
//--------------------------------------------------------------------
void TModuleLogic::InitLog()
{

}
//--------------------------------------------------------------------
std::string TModuleLogic::GetTerrainPath()
{
	return mTerrainPath;
}
//--------------------------------------------------------------------
void TModuleLogic::SetTerrainPath(std::string& path)
{
	mTerrainPath = path;
}
//--------------------------------------------------------------------
std::set<int> TModuleLogic::GetUseID_Module()
{
	return mSetUseID_Module;
}
//--------------------------------------------------------------------
