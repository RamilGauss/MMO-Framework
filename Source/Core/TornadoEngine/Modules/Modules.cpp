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

TModuleGraphicEngine* TModules::G() const
{
    return pGraphicEngine;
}
//----------------------------------------------------------
TModulePhysicEngine* TModules::P() const
{
    return pPhysicEngine;
}
//----------------------------------------------------------
TModuleLogic* TModules::L() const
{
    return pLogic;
}
//----------------------------------------------------------
TModuleMMOEngine* TModules::MMO() const
{
    return pMMOEngine;
}
//----------------------------------------------------------
TModuleNetTransport* TModules::Net() const
{
    return pNetTransport;
}
//----------------------------------------------------------
TModuleSoundEngine* TModules::S() const
{
    return pSoundEngine;
}
//----------------------------------------------------------
TModuleDataBase* TModules::DB() const
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
