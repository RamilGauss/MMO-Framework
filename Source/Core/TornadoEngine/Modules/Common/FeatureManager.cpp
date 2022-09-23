/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureManager.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

TFeatureManager::~TFeatureManager()
{
    Clear();
}
//--------------------------------------------------------------------
void TFeatureManager::Work()
{
    for (auto& slot : mSlots) {
        slot->Execute();
    }
}
//--------------------------------------------------------------------
void TFeatureManager::AddSystem(TSystem* p)
{
    GetCurrentSlot()->Add(p);
}
//--------------------------------------------------------------------
void TFeatureManager::RemoveSystem(TSystem* p)
{
    GetCurrentSlot()->Remove(p);
}
//--------------------------------------------------------------------
bool TFeatureManager::HasSystem(nsECSFramework::TSystem* p)
{
    return GetCurrentSlot()->Has(p);
}
//--------------------------------------------------------------------
void TFeatureManager::SetCurrentSlotIndex(int index)
{
    if (index < 0 && index >= GetSlotCount()) {
        BL_FIX_BUG();
    }

    mCurrentIndex = index;
}
//--------------------------------------------------------------------
int TFeatureManager::GetCurrentSlotIndex() const
{
    return mCurrentIndex;
}
//--------------------------------------------------------------------
nsECSFramework::TEntityManager* TFeatureManager::GetCurrentEntMng() const
{
    return GetCurrentSlot()->GetEntMng();
}
//--------------------------------------------------------------------
int TFeatureManager::CreateSlot(nsECSFramework::TEntityManager* pEntMng)
{
    auto newSlot = new TFeature();
    newSlot->SetEntMng(pEntMng);
    mSlots.push_back(newSlot);
    
    return GetSlotCount() - 1;
}
//--------------------------------------------------------------------
void TFeatureManager::DestroyLastSlot()
{
    auto count = GetSlotCount();
    if (count == 0) {
        return;
    }

    delete mSlots[count - 1];
    mSlots.pop_back();
}
//--------------------------------------------------------------------
int TFeatureManager::GetSlotCount() const
{
    return mSlots.size();
}
//--------------------------------------------------------------------
TFeature* TFeatureManager::GetCurrentSlot() const
{
    return mSlots[mCurrentIndex];
}
//--------------------------------------------------------------------
void TFeatureManager::Clear()
{
    while (GetSlotCount() > 0) {
        DestroyLastSlot();
    }
}
//--------------------------------------------------------------------
