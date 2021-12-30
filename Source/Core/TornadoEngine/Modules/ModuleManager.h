/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <ECS/include/EntityManager.h>
#include "KeyMouseEventContainer.h"

#include "SceneManager.h"
#include "PrefabManager.h"
#include "IModule.h"
#include "HandlerCallCollector.h"
#include "PrefabObjectConstructor.h"
#include "HierarchyHelper.h"

namespace nsTornadoEngine
{
    class TStopAccessor;
    class TModuleManager
    {
        nsECSFramework::TEntityManager mEntMng;
        TSceneManager mSceneMng;
        TPrefabManager mPrefabMng;
        TStopAccessor* mStopAccessor = nullptr;
        nsGraphicEngine::TKeyMouseEventContainer mKeyMouseEventContainer;
        THandlerCallCollector mHandlerCallCollector;
        TPrefabObjectConstructor mPrefabObjConstructor;
        THierarchyHelper mHierarchyHelper;

        std::list<IModule*> mModules;

    public:
        TModuleManager(TStopAccessor* stopAccessor);

        IModule* GetModuleByName(ModuleType moduleType);

        void ApplyToModulesSingleton();
    };
}
