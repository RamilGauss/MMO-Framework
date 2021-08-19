/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules.h"
#include <ECS/include/EntityManager.h>

namespace nsTornadoEngine
{
    class DllExport TModulesAccessor
    {
    public:
        static void SetGraphicEngine(TModuleGraphicEngine* value);
        static void SetPhysicEngine(TModulePhysicEngine* value);
        static void SetLogic(TModuleLogic* value);
        static void SetMMOEngine(TModuleMMOEngine* value);
        static void SetNetTransport(TModuleNetTransport* value);
        static void SetSoundEngine(TModuleSoundEngine* value);
        static void SetDataBase(TModuleDataBase* value);

        static void SetEntMng(nsECSFramework::TEntityManager* value);
        static void SetSceneMng(TSceneManager* value);
        static void SetPrefabMng(TPrefabManager* value);
        static void SetStopAccessor(TStopAccessor* value);
        static void SetKeyMouse(nsGraphicEngine::TKeyMouseEventContainer* value);
    };
}