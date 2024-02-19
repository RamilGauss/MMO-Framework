/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules/Common/Modules.h"

namespace nsTornadoEngine
{
    class DllExport TModulesAccessor
    {
    public:
        static void SetGraphicEngine(IGraphicEngineModule* value);
        static void SetPhysicEngine(IPhysicEngineModule* value);
        static void SetLogic(ILogicModule* value);
        static void SetMMOEngine(IMMOEngineModule* value);
        static void SetNetTransport(INetTransportModule* value);
        static void SetSoundEngine(ISoundEngineModule* value);
        static void SetDataBase(IDataBaseModule* value);

        static void SetEntMng(nsECSFramework::TEntityManager* value);
        static void SetResourceMng(TResourceManager* value);
        static void SetSceneMng(TSceneManager* value);
        static void SetPrefabMng(TPrefabManager* value);
        static void SetStopAccessor(TStopAccessor* value);
        static void SetKeyMouse(nsGraphicEngine::TKeyMouseEventContainer* value);
        static void SetHandlerCall(THandlerCallCollector* value);
        static void SetGizmo(TGizmo* value);
        static void SetPropertyMng(TPropertyManager* value);
    };
}