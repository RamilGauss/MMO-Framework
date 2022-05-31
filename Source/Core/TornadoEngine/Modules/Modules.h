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
    class IGraphicEngineModule;
    class IPhysicEngineModule;
    class ILogicModule;
    class IMMOEngineModule;
    class INetTransportModule;
    class ISoundEngineModule;
    class IDataBaseModule;

    class TSceneManager;
    class TPrefabManager;

    class TStopAccessor;

    class TModulesAccessor;
    class THandlerCallCollector;
    class TPrefabObjectConstructor;
    class THierarchyHelper;
    class TGizmo;

    class DllExport TModules
    {
    public:
        // Mostly for inner usage
        IGraphicEngineModule* G() const;
        IPhysicEngineModule* P() const;
        ILogicModule* L() const;
        IMMOEngineModule* MMO() const;
        INetTransportModule* Net() const;
        ISoundEngineModule* S() const;
        IDataBaseModule* DB() const;

        // Usage in projects
        nsECSFramework::TEntityManager* EntMng() const;
        TSceneManager* SceneMng() const;
        TPrefabManager* PrefabMng() const;

        TStopAccessor* StopAccessor() const;

        nsGraphicEngine::TKeyMouseEventContainer* KeyMouse() const;

        THandlerCallCollector* HandlerCalls() const;
        TPrefabObjectConstructor* PrefabObjConstructor() const;

        THierarchyHelper* HierarchyHelper() const;

        TGizmo* Gizmo() const;
    protected:
        friend class TModulesAccessor;

        IGraphicEngineModule* pGraphicEngine = nullptr;
        IPhysicEngineModule* pPhysicEngine = nullptr;
        ILogicModule* pLogic = nullptr;

        IMMOEngineModule* pMMOEngine = nullptr;
        INetTransportModule* pNetTransport = nullptr;

        ISoundEngineModule* pSoundEngine = nullptr;
        IDataBaseModule* pDataBase = nullptr;

        nsECSFramework::TEntityManager* entMng = nullptr;
        TSceneManager* sceneMng = nullptr;
        TPrefabManager* prefabMng = nullptr;

        TStopAccessor* stopAccessor = nullptr;

        nsGraphicEngine::TKeyMouseEventContainer* keyMouse = nullptr;

        THandlerCallCollector* handlerCallCollector = nullptr;
        TPrefabObjectConstructor* prefabObjectConstructor = nullptr;

        THierarchyHelper* hierarchyHelper = nullptr;

        TGizmo* gizmo = nullptr;
    };

    extern DllExport TModules* Modules();
}
