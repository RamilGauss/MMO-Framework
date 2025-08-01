/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "ECS/Include/EntityManager.h"
#include "GraphicEngine/KeyMouseEventContainer.h"

#include "TornadoEngine/TimeSliceEngine/IModule.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneManager.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"
#include "TornadoEngine/Modules/Gizmos/Gizmo.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

namespace nsTornadoEngine
{
    class TStopAccessor;
    class TModuleManager
    {
        nsECSFramework::TEntityManager mEntMng;
        TResourceManager mResourceMng;
        TSceneManager mSceneMng;
        TPrefabManager mPrefabMng;
        TStopAccessor* mStopAccessor = nullptr;
        nsGraphicEngine::TKeyMouseEventContainer mKeyMouseEventContainer;
        THandlerCallCollector mHandlerCallCollector;
        TGizmo mGizmo;
        TPropertyManager mPropertyMng;

        std::list<IModule*> mModules;

    public:
        TModuleManager(TStopAccessor* stopAccessor);

        IModule* GetModuleByName(ModuleType moduleType);

        void ApplyToModulesSingleton();
    };
}
