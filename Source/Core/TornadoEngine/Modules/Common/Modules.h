/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsECSFramework
{
    class TEntityManager;
}

namespace nsGraphicEngine
{
    struct TKeyMouseEventContainer;
}

class TSingletonManager;

namespace nsTornadoEngine
{
    class IGraphicEngineModule;
    class IPhysicEngineModule;
    class ILogicModule;
    class IMMOEngineModule;
    class INetTransportModule;
    class ISoundEngineModule;
    class IDataBaseModule;

    class TResourceManager;
    class TSceneManager;
    class TPrefabManager;

    class TStopAccessor;

    class TModulesAccessor;
    class THandlerCallCollector;
    class TPrefabObjectConstructor;
    class THierarchyHelper;
    class TGizmo;
    class TPropertyManager;
    class TEngineLogger;

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
        TResourceManager* ResourceMng() const;
        TSceneManager* SceneMng() const;
        TPrefabManager* PrefabMng() const;

        TStopAccessor* StopAccessor() const;

        nsGraphicEngine::TKeyMouseEventContainer* KeyMouse() const;

        THandlerCallCollector* HandlerCalls() const;
        TGizmo* Gizmo() const;

        TPropertyManager* PropertyMng() const;

        // Core logger
        TEventHub* Log(const std::source_location loc = std::source_location::current()) const;
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
        TResourceManager* resourceMng = nullptr;
        TSceneManager* sceneMng = nullptr;
        TPrefabManager* prefabMng = nullptr;
        TEngineLogger* engineLogger = nullptr;

        TStopAccessor* stopAccessor = nullptr;

        nsGraphicEngine::TKeyMouseEventContainer* keyMouse = nullptr;

        THandlerCallCollector* handlerCallCollector = nullptr;
        TPrefabObjectConstructor* prefabObjectConstructor = nullptr;

        TGizmo* gizmo = nullptr;
        TPropertyManager* propertyMng = nullptr;

        friend class TSingletonManager;
        TModules();
    };

    extern DllExport TModules* Modules();
}
