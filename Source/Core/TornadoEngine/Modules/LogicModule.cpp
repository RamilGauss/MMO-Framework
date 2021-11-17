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

bool TLogicModule::StartEvent()
{
    mWorkSlots.CreateSlot(Modules()->EntMng());
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
TLogicSlotManager* TLogicModule::GetWorkSlots()
{
    return &mWorkSlots;
}
//--------------------------------------------------------------------
void TLogicModule::SetWorkSlots(TLogicSlotManager* pLSM)
{

}
//--------------------------------------------------------------------