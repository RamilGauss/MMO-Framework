/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

//###
class TGraphicEngine;
class TPhysicEngine;
class TEntityManager;
class TSceneManager;
class TPrefabManager;
//###


namespace nsTornadoEngine
{
    class TModulesAccessor;

    class DllExport TModules
    {
    protected:
        friend class TModulesAccessor;

        TModuleGraphicEngine* pGraphicEngine = nullptr;
        TModulePhysicEngine* pPhysicEngine = nullptr;
        TModuleLogic* pLogic = nullptr;

        TModuleMMOEngine* pMMOEngine = nullptr;
        TModuleNetTransport* pNetTransport = nullptr;

        TModuleSoundEngine* pSoundEngine = nullptr;
        TModuleDataBase* pDataBase = nullptr;

        TEntityManager* entMng = nullptr;
        TSceneManager* sceneMng = nullptr;
        TPrefabManager* prefabMng = nullptr;
    public:
        TModuleGraphicEngine* G() const;
        TModulePhysicEngine* P() const;
        TModuleLogic* L() const;
        TModuleMMOEngine* MMO() const;
        TModuleNetTransport* Net() const;
        TModuleSoundEngine* S() const;
        TModuleDataBase* DB() const;

        TEntityManager* EntMng() const;
        TSceneManager* SceneMng() const;
        TPrefabManager* PrefabMng() const;
    };

    extern DllExport TModules* Modules();
}
