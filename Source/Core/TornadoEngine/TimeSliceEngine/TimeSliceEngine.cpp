/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <stddef.h>
#include <stdarg.h>
#include "fmt/core.h"

#include "TimeSliceEngine/TimeSliceEngine.h"
#include "Base/Common/BL_Debug.h"
#include "Base/Common/ShareMisc.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/Logger.h"
#include "Base/Common/FileOperation.h"

#include "Modules/Common/Modules.h"
#include "TimeSliceEngine/IModule.h"
#include "Modules/Common/ModuleManager.h"

#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "ProjectConfigLoader.h"
#include "ProjectConfigUnloader.h"

using namespace nsTornadoEngine;

TTimeSliceEngine::TTimeSliceEngine()
{
    SetProject(&mProjectConfigContainer);

    mModuleMng.reset(new TModuleManager(this));
}
//----------------------------------------------------------------------
void TTimeSliceEngine::Done()
{
}
//----------------------------------------------------------------------
bool TTimeSliceEngine::Work(const std::list<ModuleType>& moduleTypes)
{
    mModuleTypes = moduleTypes;

    if (CreateModules() == false) {
        return false;
    }

    Work();

    Done();
    return true;
}
//------------------------------------------------------------------------
void TTimeSliceEngine::Work()
{
    for (auto& pModule : mModulePtrList) {
        if (!pModule->StartEvent()) {
            return;
        }
    }

    onModuleCreationEndsCb.Notify();

    while (true) {
        for (auto& pModule : mModulePtrList) {
            pModule->Work();
        }
        if (IsNeedStop()) {
            break;
        }
    }

    for (auto& pModule : mModulePtrList) {
        pModule->StopEvent();
    }
}
//------------------------------------------------------------------------
bool TTimeSliceEngine::CreateModules()
{
    for (auto& moduleName : mModuleTypes) {
        auto pModule = mModuleMng->GetModuleByName(moduleName);
        if (pModule != nullptr) {
            mModulePtrList.push_back(pModule);
        } else {
            return false;
        }
    }

    mModuleMng->ApplyToModulesSingleton();
    return true;
}
//------------------------------------------------------------------------
