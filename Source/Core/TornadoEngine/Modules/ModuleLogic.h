/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <vector>

#include "DstModule.h"
#include <ECS/include/Feature.h>

namespace nsTornadoEngine
{
    class DllExport TModuleLogic : public TDstModule
    {
        int mCurrentIndex = 0;

        std::vector<nsECSFramework::TFeature*> mFeatureSlots;

        //###
        //TLoadStartedScenesSystem mLoadStartedScenesSystem;
        //TObjectMakerFeature mObjectMakerFeature;
        //TTreeBuilderFeature mTreeBuilderFeature;
        //###

    public:
        bool StartEvent() override;
        void Work() override;
        void StopEvent() override;

        void AddFeature(nsECSFramework::TFeature* p);
        void RemoveFeature(nsECSFramework::TFeature* p);


        void SetCurrentSlotIndex(int index);
        int GetCurrentSlotIndex() const;
        nsECSFramework::TEntityManager* GetCurrentEntMng() const;
        
        void CreateSlot(nsECSFramework::TEntityManager* pEntMng);
        void DestroyLastSlot();

        int GetSlotCount() const;

    private:
        nsECSFramework::TFeature* GetCurrentSlot() const;
    };
}