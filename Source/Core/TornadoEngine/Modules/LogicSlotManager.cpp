/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LogicSlotManager.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

TLogicSlotManager::~TLogicSlotManager()
{
    Clear();
}
//--------------------------------------------------------------------
void TLogicSlotManager::Work()
{
    for (auto& slot : mSlots) {
        slot->Work();
    }
}
//--------------------------------------------------------------------
void TLogicSlotManager::AddFeature(TFeature* p)
{
    GetCurrentSlot()->AddFeature(p);
}
//--------------------------------------------------------------------
void TLogicSlotManager::RemoveFeature(TFeature* p)
{
    GetCurrentSlot()->RemoveFeature(p);
}
//--------------------------------------------------------------------
void TLogicSlotManager::SetCurrentSlotIndex(int index)
{
    if (index < 0 && index >= GetSlotCount()) {
        BL_FIX_BUG();
    }

    mCurrentIndex = index;
}
//--------------------------------------------------------------------
int TLogicSlotManager::GetCurrentSlotIndex() const
{
    return mCurrentIndex;
}
//--------------------------------------------------------------------
nsECSFramework::TEntityManager* TLogicSlotManager::GetCurrentEntMng() const
{
    return GetCurrentSlot()->GetEntMng();
}
//--------------------------------------------------------------------
void TLogicSlotManager::CreateSlot(nsECSFramework::TEntityManager* pEntMng)
{
    auto newSlot = new TLogicSlot();
    newSlot->SetEntMng(pEntMng);
    mSlots.push_back(newSlot);
}
//--------------------------------------------------------------------
void TLogicSlotManager::DestroyLastSlot()
{
    auto count = GetSlotCount();
    if (count == 0) {
        return;
    }

    delete mSlots[count - 1];
    mSlots.pop_back();
}
//--------------------------------------------------------------------
int TLogicSlotManager::GetSlotCount() const
{
    return mSlots.size();
}
//--------------------------------------------------------------------
TLogicSlot* TLogicSlotManager::GetCurrentSlot() const
{
    return mSlots[mCurrentIndex];
}
//--------------------------------------------------------------------
void TLogicSlotManager::Clear()
{
    while (GetSlotCount() > 0) {
        DestroyLastSlot();
    }
}
//--------------------------------------------------------------------
