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

        int mGuidComponentRtti = 0;
        int mParentGuidComponentRtti = 0;
        int mSceneRootComponentRtti = 0;

        std::string mGuidComponentTypeName;
        std::string mParentGuidComponentTypeName;
        std::string mSceneRootComponentTypeName;
    public:
        TSceneInstantiatingThread(TSceneInstanceState* pSceneInstanceState);
    protected:
        void Work() override;
    private:
        void Init();
        void FileLoading();
        void SceneDeserializing();
        void PrepareTreeEntity();
        void SortingEntitiesByRank();

        void SingleSortingEntitiesByRank();
        
        void CalculateAccurateProgressValues();
        void CalculateRoughProgressValues();

        const float ROUGH_ENTITY_SIZE_IN_FILE = 1312.0f;
    };
}
