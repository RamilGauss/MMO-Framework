/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Common/ModuleManager.h"
#include "TimeSliceEngine/IModule.h"
#include "Modules/Common/Modules.h"
#include "ModulesAccessor.h"

#include "Modules/Implementations/LogicModule.h"
#include "Modules/Implementations/GraphicEngineModule.h"
#include "Modules/Implementations/PhysicEngineModule.h"
#include "Modules/Implementations/SoundEngineModule.h"
#include "Modules/Implementations/MMOEngineModule.h"
#include "Modules/Implementations/NetTransportModule.h"
#include "Modules/Implementations/DataBaseModule.h"

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
    TModulesAccessor::SetResourceMng(&mResourceMng);
    TModulesAccessor::SetSceneMng(&mSceneMng);
    TModulesAccessor::SetPrefabMng(&mPrefabMng);
    TModulesAccessor::SetStopAccessor(mStopAccessor);
    TModulesAccessor::SetKeyMouse(&mKeyMouseEventContainer);
    TModulesAccessor::SetHandlerCall(&mHandlerCallCollector);
    TModulesAccessor::SetGizmo(&mGizmo);
    TModulesAccessor::SetPropertyMng(&mPropertyMng);
}
//----------------------------------------------------------------------------