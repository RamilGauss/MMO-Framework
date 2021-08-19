/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModuleManager.h"
#include "IModule.h"
#include "Modules.h"
#include "ModulesAccessor.h"

#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"
#include "ModuleMMOEngine.h"
#include "ModuleNetTransport.h"
#include "ModuleDatabase.h"

using namespace nsTornadoEngine;

TModuleManager::TModuleManager(TStopAccessor* stopAccessor)
{
    mStopAccessor = stopAccessor;
}
//----------------------------------------------------------------------------
IModule* TModuleManager::GetModuleByName(ModuleType moduleType)
{
    IModule* module = nullptr;
    switch (moduleType) {
        case ModuleType::Logic:
            module = new TModuleLogic();
            break;
        case ModuleType::GraphicEngine:
            module = new TModuleGraphicEngine();
            break;
        case ModuleType::PhysicEngine:
            module = new TModulePhysicEngine();
            break;
        case ModuleType::NetTransport:
            module = new TModuleNetTransport();
            break;
        case ModuleType::MMOEngine:
            module = new TModuleMMOEngine();
            break;
        case ModuleType::SoundEngine:
            module = new TModuleSoundEngine();
            break;
        case ModuleType::DataBase:
            module = new TModuleDataBase();
            break;
    }
    module->mType = moduleType;
    mModules.push_back(module);
    return module;
}
//----------------------------------------------------------------------------
void TModuleManager::ApplyToModulesSingleton()
{
    for (auto& module : mModules) {
        switch (module->mType) {
            case ModuleType::Logic:
                TModulesAccessor::SetLogic((TModuleLogic*) module);
                break;
            case ModuleType::GraphicEngine:
                TModulesAccessor::SetGraphicEngine((TModuleGraphicEngine*) module);
                break;
            case ModuleType::PhysicEngine:
                TModulesAccessor::SetPhysicEngine((TModulePhysicEngine*) module);
                break;
            case ModuleType::NetTransport:
                TModulesAccessor::SetNetTransport((TModuleNetTransport*) module);
                break;
            case ModuleType::MMOEngine:
                TModulesAccessor::SetMMOEngine((TModuleMMOEngine*) module);
                break;
            case ModuleType::SoundEngine:
                TModulesAccessor::SetSoundEngine((TModuleSoundEngine*) module);
                break;
            case ModuleType::DataBase:
                TModulesAccessor::SetDataBase((TModuleDataBase*) module);
                break;
        }
    }
    TModulesAccessor::SetEntMng(&mEntMng);
    TModulesAccessor::SetSceneMng(&mSceneMng);
    TModulesAccessor::SetPrefabMng(&mPrefabMng);
    TModulesAccessor::SetStopAccessor(mStopAccessor);
    TModulesAccessor::SetKeyMouse(&mKeyMouseEventContainer);
}
//----------------------------------------------------------------------------