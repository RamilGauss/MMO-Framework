/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "LogicSlot.h"

namespace nsTornadoEngine
{
    class DllExport TLogicSlotManager
    {
        int mCurrentIndex = 0;

        std::vector<TLogicSlot*> mSlots;
    public:
        virtual ~TLogicSlotManager();

        void Work();

        // For current slot
        void AddFeature(nsECSFramework::TFeature* p);
        void RemoveFeature(nsECSFramework::TFeature* p);

        nsECSFramework::TEntityManager* GetCurrentEntMng() const;

        int GetSlotCount() const;

        void SetCurrentSlotIndex(int index);
        int GetCurrentSlotIndex() const;

        int CreateSlot(nsECSFramework::TEntityManager* pEntMng);
        void DestroyLastSlot();

        void Clear();

    private:
        TLogicSlot* GetCurrentSlot() const;
    };
}