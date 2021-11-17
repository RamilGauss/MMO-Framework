/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DstModule.h"

using namespace nsTornadoEngine;

void TDstModule::Work()
{
    mBeginLogicSlotManager.Work();
    
    ModuleWork();
    
    mEndLogicSlotManager.Work();
}
//-------------------------------------------------------------------
TLogicSlotManager* TDstModule::GetBeginLogicSlotManager()
{
    return &mBeginLogicSlotManager;
}
//-------------------------------------------------------------------
TLogicSlotManager* TDstModule::GetEndLogicSlotManager()
{
    return &mEndLogicSlotManager;
}
//-------------------------------------------------------------------
