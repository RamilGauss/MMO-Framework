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
    TModulesAccessor moduleAccessor;

    for (auto& module : mModules) {
        switch (module->mType) {
            case ModuleType::Logic:
                moduleAccessor.SetLogic((TModuleLogic*) module);
                break;
            case ModuleType::GraphicEngine:
                moduleAccessor.SetGraphicEngine((TModuleGraphicEngine*) module);
                break;
            case ModuleType::PhysicEngine:
                moduleAccessor.SetPhysicEngine((TModulePhysicEngine*) module);
                break;
            case ModuleType::NetTransport:
                moduleAccessor.SetNetTransport((TModuleNetTransport*) module);
                break;
            case ModuleType::MMOEngine:
                moduleAccessor.SetMMOEngine((TModuleMMOEngine*) module);
                break;
            case ModuleType::SoundEngine:
                moduleAccessor.SetSoundEngine((TModuleSoundEngine*) module);
                break;
            case ModuleType::DataBase:
                moduleAccessor.SetDataBase((TModuleDataBase*) module);
                break;
        }
    }
    moduleAccessor.SetEntMng(&mEntMng);
    moduleAccessor.SetSceneMng(&mSceneMng);
    moduleAccessor.SetPrefabMng(&mPrefabMng);
    moduleAccessor.SetStopAccessor(mStopAccessor);
}
//----------------------------------------------------------------------------