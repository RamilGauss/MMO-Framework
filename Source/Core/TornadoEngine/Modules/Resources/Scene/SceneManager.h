/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "UniverseManager.h"
#include "ObjectManager.h"
#include "InstantiateSceneParams.h"

namespace nsTornadoEngine
{
    class DllExport TSceneManager : public TObjectManager
    {
        TUniverseManager mUniverseManager;

        struct TReference
        {
            int counter = 0;
        };

        TColanderVector<TReference> mReferenceCounters;

    public:
        void InstantiateByGuid(TInstantiateSceneParams instantiateSceneParams);
        void InstantiateByAbsPath(const TInstantiateSceneParams& instantiateSceneParams);

        void Destroy(const std::string& sceneInstanceGuid);
        void Destroy(nsECSFramework::TEntityID anyEidInScene);

        void Save(const std::string& sceneGuid);
    private:

        void IncrementReferenceCounter(TUniverseManager::IndexType index);
        void DecrementReferenceCounter(TUniverseManager::IndexType index);

        int GetReferenceCounter(TUniverseManager::IndexType index);
    };
}