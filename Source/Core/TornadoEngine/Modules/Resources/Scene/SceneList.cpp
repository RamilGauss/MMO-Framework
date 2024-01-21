/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Scene/SceneList.h"

namespace nsTornadoEngine
{
    void TSceneList::Setup(int maxActiveCount, std::function<bool(TSceneInstanceStatePtr)> deactivateCondition)
    {
        mMaxActiveCount = maxActiveCount;
        mDeactivateCondition = deactivateCondition;
    }
    //-------------------------------------------------------------------------------------------------------------
    void TSceneList::AddToWait(TSceneInstanceStatePtr pSceneInstanceState)
    {
        mWaitScenes.push_back(pSceneInstanceState);
    }
    //-------------------------------------------------------------------------------------------------------------
    void TSceneList::TryActivate(std::list<TSceneInstanceStatePtr>& sceneInstanceStates)
    {
        int delta = mMaxActiveCount - mActiveScenes.size();
        if (delta <= 0) {
            return;
        }

        delta = std::min(delta, (int)mWaitScenes.size());

        for (int i = 0; i < delta; i++) {

            auto activatedScene = mWaitScenes.front();

            mActiveScenes.push_back(activatedScene);
            sceneInstanceStates.push_back(activatedScene);

            mWaitScenes.pop_front();
        }
    }
    //-------------------------------------------------------------------------------------------------------------
    void TSceneList::TryDeactivate(std::list<TSceneInstanceStatePtr>& sceneInstanceStates)
    {
        for (auto& scene : mActiveScenes) {
            if (mDeactivateCondition(scene)) {
                sceneInstanceStates.push_back(scene);
            }
        }

        for (auto& scene : sceneInstanceStates) {
            mActiveScenes.remove(scene);
        }
    }
    //-------------------------------------------------------------------------------------------------------------
    void TSceneList::Deactivate(TSceneInstanceStatePtr pSceneInstanceState)
    {
        mWaitScenes.remove(pSceneInstanceState);
        mActiveScenes.remove(pSceneInstanceState);
    }
    //-------------------------------------------------------------------------------------------------------------
    std::list<TSceneInstanceStatePtr> TSceneList::GetActive() const
    {
        return mActiveScenes;
    }
    //-------------------------------------------------------------------------------------------------------------
}
