/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LogicModule.h"
#include "Modules.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

bool TLogicModule::ModuleStartEvent()
{
    auto entMng = Modules()->EntMng();

    auto beginSlotIndex = GetBeginLogicSlotManager()->CreateSlot(entMng);
    GetBeginLogicSlotManager()->SetCurrentSlotIndex(beginSlotIndex);
    GetBeginLogicSlotManager()->AddSystem(&mBeginFeature);

    auto workSlotIndex = mWorkSlots.CreateSlot(entMng);
    mWorkSlots.SetCurrentSlotIndex(workSlotIndex);

    auto endSlotIndex = GetEndLogicSlotManager()->CreateSlot(entMng);
    GetEndLogicSlotManager()->SetCurrentSlotIndex(endSlotIndex);
    GetEndLogicSlotManager()->AddSystem(&mEndFeature);

    return true;
}
//--------------------------------------------------------------------
void TLogicModule::ModuleWork()
{
    mWorkSlots.Work();
}
//--------------------------------------------------------------------
void TLogicModule::StopEvent()
{
    mWorkSlots.Clear();
}
//--------------------------------------------------------------------
TFeatureManager* TLogicModule::GetWorkSlots()
{
    return &mWorkSlots;
}
//--------------------------------------------------------------------
void TLogicModule::SetWorkSlots(TFeatureManager* pLSM)
{

}
//--------------------------------------------------------------------