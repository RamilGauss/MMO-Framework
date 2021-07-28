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

#include "SceneManager.h"
#include "PrefabManager.h"
#include "IModule.h"

namespace nsTornadoEngine
{
    class TModuleManager
    {
        nsECSFramework::TEntityManager mEntMng;
        TSceneManager mSceneMng;
        TPrefabManager mPrefabMng;

        std::list<IModule*> mModules;

    public:
        IModule* GetModuleByName(ModuleType moduleType);

        void ApplyToModulesSingleton();
    };
}
