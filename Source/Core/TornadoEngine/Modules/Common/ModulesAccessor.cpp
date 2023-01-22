/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModulesAccessor.h"

using namespace nsTornadoEngine;

void TModulesAccessor::SetGraphicEngine(IGraphicEngineModule* value)
{
    Modules()->pGraphicEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetPhysicEngine(IPhysicEngineModule* value)
{
    Modules()->pPhysicEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetLogic(ILogicModule* value)
{
    Modules()->pLogic = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetMMOEngine(IMMOEngineModule* value)
{
    Modules()->pMMOEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetNetTransport(INetTransportModule* value)
{
    Modules()->pNetTransport = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetSoundEngine(ISoundEngineModule* value)
{
    Modules()->pSoundEngine = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetDataBase(IDataBaseModule* value)
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
void TModulesAccessor::SetHandlerCall(THandlerCallCollector* value)
{
    Modules()->handlerCallCollector = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetPrefabObjConstructor(TPrefabObjectConstructor* value)
{
    Modules()->prefabObjectConstructor = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetGizmo(TGizmo* value)
{
    Modules()->gizmo = value;
}
//--------------------------------------------------------------------------
void TModulesAccessor::SetPropertyMng(TPropertyManager* value)
{
    Modules()->propertyMng = value;
}
//--------------------------------------------------------------------------
