/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModuleLogic.h"
#include "Modules.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

bool TModuleLogic::StartEvent()
{
    CreateSlot(Modules()->EntMng());
    return true;
}
//--------------------------------------------------------------------
void TModuleLogic::Work()
{
    for (auto& slot : mFeatureSlots) {
        slot->Execute();
    }
}
//--------------------------------------------------------------------
void TModuleLogic::StopEvent()
{
    while (GetSlotCount() > 0) {
        DestroyLastSlot();
    }
}
//--------------------------------------------------------------------
void TModuleLogic::AddFeature(TFeature* p)
{
    GetCurrentSlot()->Add(p);
}
//--------------------------------------------------------------------
void TModuleLogic::RemoveFeature(TFeature* p)
{
    GetCurrentSlot()->Remove(p);
}
//--------------------------------------------------------------------
void TModuleLogic::SetCurrentSlotIndex(int index)
{
    mCurrentIndex = index;
}
//--------------------------------------------------------------------
int TModuleLogic::GetCurrentSlotIndex() const
{
    return mCurrentIndex;
}
//--------------------------------------------------------------------
nsECSFramework::TEntityManager* TModuleLogic::GetCurrentEntMng() const
{
    return GetCurrentSlot()->GetEntMng();
}
//--------------------------------------------------------------------
void TModuleLogic::CreateSlot(nsECSFramework::TEntityManager* pEntMng)
{
    auto newSlot = new TFeature();
    newSlot->SetEntMng(pEntMng);
    mFeatureSlots.push_back(newSlot);
}
//--------------------------------------------------------------------
void TModuleLogic::DestroyLastSlot()
{
    auto count = GetSlotCount();
    if (count == 0) {
        return;
    }

    delete mFeatureSlots[count - 1];
    mFeatureSlots.pop_back();
}
//--------------------------------------------------------------------
int TModuleLogic::GetSlotCount() const
{
    return mFeatureSlots.size();
}
//--------------------------------------------------------------------
nsECSFramework::TFeature* TModuleLogic::GetCurrentSlot() const
{
    return mFeatureSlots[mCurrentIndex];
}
//--------------------------------------------------------------------
