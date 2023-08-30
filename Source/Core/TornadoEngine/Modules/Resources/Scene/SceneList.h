/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <functional>

#include "SceneInstanceState.h"

namespace nsTornadoEngine
{
    class DllExport TSceneList
    {
        std::list<TSceneInstanceStatePtr> mWaitScenes;
        std::list<TSceneInstanceStatePtr> mActiveScenes;

        int mMaxActiveCount = 1;
        std::function<bool(TSceneInstanceStatePtr)> mDeactivateCondition;
    public:
        TSceneList(int maxActiveCount, 
            std::function<bool(TSceneInstanceStatePtr)> deactivateCondition);

        void AddToWait(TSceneInstanceStatePtr pSceneInstanceState);
        void TryActivate(std::list<TSceneInstanceStatePtr>& sceneInstanceStates);
        void TryDeactivate(std::list<TSceneInstanceStatePtr>& sceneInstanceStates);

        void Deactivate(TSceneInstanceStatePtr sceneInstanceState);

        std::list<TSceneInstanceStatePtr> GetActive() const;
    };
}
