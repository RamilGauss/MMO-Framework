/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules.h"
#include "SingletonManager.h"

nsTornadoEngine::TModules* nsTornadoEngine::Modules()
{
    return SingletonManager()->Get<nsTornadoEngine::TModules>();
}
//----------------------------------------------------------

using namespace nsTornadoEngine;
using namespace nsECSFramework;
using namespace nsGraphicEngine;

IGraphicEngineModule* TModules::G() const
{
    return pGraphicEngine;
}
//----------------------------------------------------------
IPhysicEngineModule* TModules::P() const
{
    return pPhysicEngine;
}
//----------------------------------------------------------
ILogicModule* TModules::L() const
{
    return pLogic;
}
//----------------------------------------------------------
IMMOEngineModule* TModules::MMO() const
{
    return pMMOEngine;
}
//----------------------------------------------------------
INetTransportModule* TModules::Net() const
{
    return pNetTransport;
}
//----------------------------------------------------------
ISoundEngineModule* TModules::S() const
{
    return pSoundEngine;
}
//----------------------------------------------------------
IDataBaseModule* TModules::DB() const
{
    return pDataBase;
}
//----------------------------------------------------------
TEntityManager* TModules::EntMng() const
{
    return entMng;
}
//----------------------------------------------------------
TSceneManager* TModules::SceneMng() const
{
    return sceneMng;
}
//----------------------------------------------------------
TPrefabManager* TModules::PrefabMng() const
{
    return prefabMng;
}
//----------------------------------------------------------
TStopAccessor* TModules::StopAccessor() const
{
    return stopAccessor;
}
//----------------------------------------------------------
TKeyMouseEventContainer* TModules::KeyMouse() const
{
    return keyMouse;
}
//----------------------------------------------------------
THandlerCallCollector* TModules::HandlerCalls() const
{
    return handlerCallCollector;
}
//----------------------------------------------------------
TPrefabObjectConstructor* TModules::PrefabObjConstructor() const
{
    return prefabObjectConstructor;
}
//----------------------------------------------------------
TGizmo* TModules::Gizmo() const
{
    return gizmo;
}
//----------------------------------------------------------
TPropertyManager* TModules::PropertyMng() const
{
    return propertyMng;
}
//----------------------------------------------------------
TModules::TModules()
{

}
//----------------------------------------------------------