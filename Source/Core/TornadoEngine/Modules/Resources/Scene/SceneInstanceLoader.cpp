/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneInstanceLoader.h"
#include "HiTimer.h"

namespace nsTornadoEngine
{
    void TSceneInstanceLoader::AsyncWork(TSceneInstanceState* pSc)
    {
        pSc->mAsyncThread = std::make_shared<TSceneInstantiatingThread>(pSc);

        pSc->mAsyncThread->Start();
    }
    //---------------------------------------------------------------------------------------
    void TSceneInstanceLoader::SyncWork(TSceneInstanceState* pSc, int maxDuration = -1)
    {
        auto start = ht_GetMSCount();

        //while() {

        switch (pSc->mStep) {
            case TSceneInstanceState::Step::ENTITY_INSTANTIATING:
                break;
            case TSceneInstanceState::Step::PREFAB_INSTANTIATING:
                break;
            default:;
        }

    }
    //---------------------------------------------------------------------------------------
}
