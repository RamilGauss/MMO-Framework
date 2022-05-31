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

#include "LogicModule.h"
#include "GraphicEngineModule.h"
#include "PhysicEngineModule.h"
#include "SoundEngineModule.h"
#include "MMOEngineModule.h"
#include "NetTransportModule.h"
#include "DatabaseModule.h"

using namespace nsTornadoEngine;

TModuleManager::TModuleManager(TStopAccessor* stopAccessor) : 
    mEntMng("ModuleManager")
{
    mStopAccessor = stopAccessor;
}
//----------------------------------------------------------------------------
IModule* TModuleManager::GetModuleByName(ModuleType moduleType)
{
    IModule* module = nullptr;
    switch (moduleType) {
        case ModuleType::Logic:
            module = new TLogicModule();
            break;
        case ModuleType::GraphicEngine:
            module = new TGraphicEngineModule();
            break;
        case ModuleType::PhysicEngine:
            module = new TPhysicEngineModule();
            break;
        case ModuleType::NetTransport:
            module = new TNetTransportModule();
            break;
        case ModuleType::MMOEngine:
            module = new TMMOEngineModule();
            break;
        case ModuleType::SoundEngine:
            module = new TSoundEngineModule();
            break;
        case ModuleType::DataBase:
            module = new TDataBaseModule();
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
                TModulesAccessor::SetLogic((ILogicModule*) module);
                break;
            case ModuleType::GraphicEngine:
                TModulesAccessor::SetGraphicEngine((IGraphicEngineModule*) module);
                break;
            case ModuleType::PhysicEngine:
                TModulesAccessor::SetPhysicEngine((IPhysicEngineModule*) module);
                break;
            case ModuleType::NetTransport:
                TModulesAccessor::SetNetTransport((INetTransportModule*) module);
                break;
            case ModuleType::MMOEngine:
                TModulesAccessor::SetMMOEngine((IMMOEngineModule*) module);
                break;
            case ModuleType::SoundEngine:
                TModulesAccessor::SetSoundEngine((ISoundEngineModule*) module);
                break;
            case ModuleType::DataBase:
                TModulesAccessor::SetDataBase((IDataBaseModule*) module);
                break;
        }
    }
    TModulesAccessor::SetEntMng(&mEntMng);
    TModulesAccessor::SetSceneMng(&mSceneMng);
    TModulesAccessor::SetPrefabMng(&mPrefabMng);
    TModulesAccessor::SetStopAccessor(mStopAccessor);
    TModulesAccessor::SetKeyMouse(&mKeyMouseEventContainer);
    TModulesAccessor::SetHandlerCall(&mHandlerCallCollector);
    TModulesAccessor::SetPrefabObjConstructor(&mPrefabObjConstructor);
    TModulesAccessor::SetHierarchyHelper(&mHierarchyHelper);
    TModulesAccessor::SetGizmo(&mGizmo);
}
//----------------------------------------------------------------------------