/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModulesAccessor.h"

using namespace nsTornadoEngine;

void TModulesAccessor::SetGraphicEngine(TModuleGraphicEngine* value)
{
    Modules()->pGraphicEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetPhysicEngine(TModulePhysicEngine* value)
{
    Modules()->pPhysicEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetLogic(TModuleLogic* value)
{
    Modules()->pLogic = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetMMOEngine(TModuleMMOEngine* value)
{
    Modules()->pMMOEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetNetTransport(TModuleNetTransport* value)
{
    Modules()->pNetTransport = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetSoundEngine(TModuleSoundEngine* value)
{
    Modules()->pSoundEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetDataBase(TModuleDataBase* value)
{
    Modules()->pDataBase = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetEntMng(nsECSFramework::TEntityManager* value)
{
    Modules()->entMng = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetSceneMng(TSceneManager* value)
{
    Modules()->sceneMng = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetPrefabMng(TPrefabManager* value)
{
    Modules()->prefabMng = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetStopAccessor(TStopAccessor* value)
{
    Modules()->stopAccessor = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetKeyMouse(nsGraphicEngine::TKeyMouseEventContainer* value)
{
    Modules()->keyMouse = value;
}
//--------------------------------------------------------------------------
