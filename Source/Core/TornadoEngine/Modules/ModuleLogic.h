/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <vector>
#include <list>

#include "DstModule.h"
#include "LogicSlot.h"

namespace nsTornadoEngine
{
    class DllExport TModuleLogic : public TDstModule
    {
        int mCurrentIndex = 0;

        std::vector<TLogicSlot*> mSlots;

    public:
        bool StartEvent() override;
        void Work() override;
        void StopEvent() override;

        void AddFeature(nsECSFramework::TFeature* p);
        void RemoveFeature(nsECSFramework::TFeature* p);

        // Slot managment
        nsECSFramework::TEntityManager* GetCurrentEntMng() const;

        int GetSlotCount() const;

        void SetCurrentSlotIndex(int index);
        int GetCurrentSlotIndex() const;
        
        void CreateSlot(nsECSFramework::TEntityManager* pEntMng);
        void DestroyLastSlot();

    private:
        TLogicSlot* GetCurrentSlot() const;
    };
}