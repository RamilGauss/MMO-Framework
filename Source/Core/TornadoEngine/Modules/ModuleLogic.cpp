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
    for (auto& slot : mSlots) {
        slot->Work();
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
    GetCurrentSlot()->AddFeature(p);
}
//--------------------------------------------------------------------
void TModuleLogic::RemoveFeature(TFeature* p)
{
    GetCurrentSlot()->RemoveFeature(p);
}
//--------------------------------------------------------------------
void TModuleLogic::SetCurrentSlotIndex(int index)
{
    if (index < 0 && index >= GetSlotCount()) {
        BL_FIX_BUG();
    }

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
    auto newSlot = new TLogicSlot();
    newSlot->SetEntMng(pEntMng);
    mSlots.push_back(newSlot);
}
//--------------------------------------------------------------------
void TModuleLogic::DestroyLastSlot()
{
    auto count = GetSlotCount();
    if (count == 0) {
        return;
    }

    delete mSlots[count - 1];
    mSlots.pop_back();
}
//--------------------------------------------------------------------
int TModuleLogic::GetSlotCount() const
{
    return mSlots.size();
}
//--------------------------------------------------------------------
TLogicSlot* TModuleLogic::GetCurrentSlot() const
{
    return mSlots[mCurrentIndex];
}
//--------------------------------------------------------------------
