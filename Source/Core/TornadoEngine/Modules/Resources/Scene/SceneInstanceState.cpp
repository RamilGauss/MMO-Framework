/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneInstanceState.h"

namespace nsTornadoEngine
{
    std::string TSceneInstanceState::GetGuid() const
    {
        return mGuid;
    }
    //--------------------------------------------------------------------------------------------------
    TSceneInstanceState::Step TSceneInstanceState::GetStep() const
    {
        return mStep;
    }
    //--------------------------------------------------------------------------------------------------
    float TSceneInstanceState::GetLoadingProgress()
    {
        return 0.0f;
    }
    //--------------------------------------------------------------------------------------------------
    void TSceneInstanceState::Work()
    {

    }
    //--------------------------------------------------------------------------------------------------
}
