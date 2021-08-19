/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsECSFramework
{
    class TEntityManager;
}

namespace nsGraphicEngine
{
    struct TKeyMouseEventContainer;
}

namespace nsTornadoEngine
{
    class TModuleGraphicEngine;
    class TModulePhysicEngine;
    class TModuleLogic;
    class TModuleMMOEngine;
    class TModuleNetTransport;
    class TModuleSoundEngine;
    class TModuleDataBase;

    class TSceneManager;
    class TPrefabManager;

    class TStopAccessor;

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

        nsECSFramework::TEntityManager* entMng = nullptr;
        TSceneManager* sceneMng = nullptr;
        TPrefabManager* prefabMng = nullptr;

        TStopAccessor* stopAccessor = nullptr;

        nsGraphicEngine::TKeyMouseEventContainer* keyMouse = nullptr;
    public:
        TModuleGraphicEngine* G() const;
        TModulePhysicEngine* P() const;
        TModuleLogic* L() const;
        TModuleMMOEngine* MMO() const;
        TModuleNetTransport* Net() const;
        TModuleSoundEngine* S() const;
        TModuleDataBase* DB() const;

        nsECSFramework::TEntityManager* EntMng() const;
        TSceneManager* SceneMng() const;
        TPrefabManager* PrefabMng() const;

        TStopAccessor* StopAccessor() const;

        nsGraphicEngine::TKeyMouseEventContainer* KeyMouse() const;
    };

    extern DllExport TModules* Modules();
}
