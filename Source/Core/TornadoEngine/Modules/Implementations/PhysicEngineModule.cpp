/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PhysicEngineModule.h"

using namespace nsTornadoEngine;

TPhysicEngineModule::TPhysicEngineModule()
{
    mPE.reset(new TPhysicEngine_Bullet);
}
//---------------------------------------------------------------------------------
void TPhysicEngineModule::ModuleWork()
{
    mPE->Work();
}
//---------------------------------------------------------------------------------
bool TPhysicEngineModule::ModuleStartEvent()
{
    return true;
}
//---------------------------------------------------------------------------------
void TPhysicEngineModule::StopEvent()
{

}
//---------------------------------------------------------------------------------
TPhysicEngine_Bullet* TPhysicEngineModule::GetPE()
{
    return mPE.get();
}
//---------------------------------------------------------------------------------
void TPhysicEngineModule::SetPE(TPhysicEngine_Bullet* pPE)
{

}
//---------------------------------------------------------------------------------
