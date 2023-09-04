/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ThreadBoost.h"

namespace nsTornadoEngine
{
    struct TSceneInstanceState;

    class DllExport TSceneInstantiatingThread : public TThreadBoost
    {
        TSceneInstanceState* mScState = nullptr;
    public:
        TSceneInstantiatingThread(TSceneInstanceState* pSceneInstanceState);
    protected:
        void Work() override;
    private:
        void Init();
        void FileLoading();
        void SceneDeserializing();
        void ComponentsDeserializing();
        void SortingEntitiesByRank();
        
        void CalculateAccurateProgressValues();
        void CalculateRoughProgressValues();
    };
}
