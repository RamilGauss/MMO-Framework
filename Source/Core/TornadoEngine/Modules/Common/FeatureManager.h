/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include <ECS/include/Feature.h>

namespace nsTornadoEngine
{
    class DllExport TFeatureManager
    {
        int mCurrentIndex = 0;

        std::vector<nsECSFramework::TFeature*> mSlots;
    public:
        virtual ~TFeatureManager();

        void Work();

        // For current slot
        void AddSystem(nsECSFramework::TSystem* p);
        void RemoveSystem(nsECSFramework::TSystem* p);
        bool HasSystem(nsECSFramework::TSystem* p);

        nsECSFramework::TEntityManager* GetCurrentEntMng() const;

        int GetSlotCount() const;
        nsECSFramework::TFeature* GetSlotByIndex(int index);

        void SetCurrentSlotIndex(int index);
        int GetCurrentSlotIndex() const;

        int CreateSlot(nsECSFramework::TEntityManager* pEntMng);
        void DestroyLastSlot();

        void Clear();

    private:
        nsECSFramework::TFeature* GetCurrentSlot() const;
    };
}