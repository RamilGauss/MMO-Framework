/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LogicWrapperModule.h"

using namespace nsTornadoEngine;

void TLogicWrapperModule::Work()
{
    mBeginLogicSlotManager.Work();
    
    auto start = ht_GetUSCount();

    ModuleWork();

    mLastExecutionTime = (ht_GetUSCount() - start) / 1'000'000.0;
    
    mEndLogicSlotManager.Work();
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
