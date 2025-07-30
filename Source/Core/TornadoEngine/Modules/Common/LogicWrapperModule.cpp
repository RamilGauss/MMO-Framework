/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/HiTimer.h"

#include "TornadoEngine/Modules/Common/LogicWrapperModule.h"

using namespace nsTornadoEngine;

void TLogicWrapperModule::Work()
{
    mBeginLogicSlotManager.Work();

    BlockBeginReactives();

    auto start = ht_GetUSCount();

    ModuleWork();

    mLastExecutionTime = (ht_GetUSCount() - start) / 1'000'000.0;

    mEndLogicSlotManager.Work();

    UnblockBeginReactives();
    ClearBeginReactives();
}
//-------------------------------------------------------------------
bool TLogicWrapperModule::StartEvent()
{
    auto startRes = ModuleStartEvent();

    int cnt = mBeginLogicSlotManager.GetSlotCount();
    for (int i = 0; i < cnt; i++) {
        mBeginLogicSlotManager.GetSlotByIndex(i)->GetInstantReactives(mInstantReactiveSystems);
        mBeginLogicSlotManager.GetSlotByIndex(i)->GetCollectReactives(mCollectReactiveSystems);
    }

    return startRes;
}
//-------------------------------------------------------------------
void TLogicWrapperModule::BlockBeginReactives()
{
    for (auto& s : mInstantReactiveSystems) {
        s->SetEnableReactive(false);
    }
}
//-------------------------------------------------------------------
void TLogicWrapperModule::UnblockBeginReactives()
{
    for (auto& s : mInstantReactiveSystems) {
        s->SetEnableReactive(true);
    }
}
//-------------------------------------------------------------------
void TLogicWrapperModule::ClearBeginReactives()
{
    for (auto& s : mCollectReactiveSystems) {
        s->ClearEvents();
    }
}
//-------------------------------------------------------------------
TFeatureManager* TLogicWrapperModule::GetBeginLogicSlotManager()
{
    return &mBeginLogicSlotManager;
}
//-------------------------------------------------------------------
TFeatureManager* TLogicWrapperModule::GetEndLogicSlotManager()
{
    return &mEndLogicSlotManager;
}
//-------------------------------------------------------------------
double TLogicWrapperModule::GetLastExecutionTime() const
{
    return mLastExecutionTime;
}
//-------------------------------------------------------------------
