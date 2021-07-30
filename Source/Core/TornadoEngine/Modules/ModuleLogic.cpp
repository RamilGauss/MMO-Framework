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
    mMainFeature.SetEntMng(Modules()->EntMng());

    //###
    AddFeature(&test);
    //###


    return true;
}
//--------------------------------------------------------------------
void TModuleLogic::Work()
{
    mMainFeature.Execute();
}
//--------------------------------------------------------------------
void TModuleLogic::StopEvent()
{

}
//--------------------------------------------------------------------
void TModuleLogic::AddFeature(TFeature* p)
{
    mMainFeature.Add(p);
}
//--------------------------------------------------------------------
void TModuleLogic::RemoveFeature(TFeature* p)
{
    mMainFeature.Remove(p);
}
//--------------------------------------------------------------------