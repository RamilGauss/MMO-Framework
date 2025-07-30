/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <stddef.h>
#include <stdarg.h>
#include "fmt/core.h"

#include "Base/Common/BL_Debug.h"
#include "Base/Common/ShareMisc.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/Logger.h"
#include "Base/Common/FileOperation.h"
#include "Base/Common/ThreadIndexator.h"
#include "Base/Common/SingletonManager.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Common/ModuleManager.h"

#include "TornadoEngine/TimeSliceEngine/TimeSliceEngine.h"
#include "TornadoEngine/TimeSliceEngine/IModule.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigLoader.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigUnloader.h"

using namespace nsTornadoEngine;

bool TTimeSliceEngine::Init(const std::list<ModuleType>& moduleTypes)
{
    mModuleMng.reset(new TModuleManager(this));
    mModuleTypes = moduleTypes;

    if (CreateModules() == false) {
        return false;
    }
    return true;
}
//------------------------------------------------------------------------
void TTimeSliceEngine::StartModules()
{
    for (auto& pModule : mModulePtrList) {
        if (!pModule->StartEvent()) {
            return;
        }
    }
}
//------------------------------------------------------------------------
void TTimeSliceEngine::Work(std::list<TLogDumper*>&& logDumpers)
{
    while (true) {
        for (auto& pModule : mModulePtrList) {
            pModule->Work();
        }
        for (auto& logDumper : logDumpers) {
            logDumper->TryFlushToFile();
        }
        if (IsNeedStop()) {
            break;
        }
    }
}
//------------------------------------------------------------------------
void TTimeSliceEngine::StopModules()
{
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
