/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_10_29 17:33:25.647
	
#include "EcsSystemExtension.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<TEcsSystemExtension::Data> TEcsSystemExtension::mDataVector;
void TEcsSystemExtension::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsGraphicWrapper_TAddPropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TAddPropertiesFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TAddPropertiesFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TAddPropertiesFeature_Data, nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TBeginGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TBeginGraphicFeature_Data, nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraBuilderFeature_Data, nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data, nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data, nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_Data;
    nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TEndGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TEndGraphicFeature_Data, nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiBuilderFeature_Data, nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_Data;
    nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiMakerFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiMakerFeature_Data, nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data, nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data, nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TPositionUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TPositionUpdaterSystem_Data, nsGraphicWrapper_TPositionUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data, nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TUpdatePropertiesFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TUpdatePropertiesFeature_Data, nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_Data;
    nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto rtti_nsLogicWrapper_TBeginLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TBeginLogicFeature_Data, nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_Data;
    nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto rtti_nsLogicWrapper_TEndLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TEndLogicFeature_Data, nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(p)); };
    auto rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    m.insert({ rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data, nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_Data;
    nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicBuilderFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicBuilderFeature_Data, nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_Data;
    nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicMakerFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicMakerFeature_Data, nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicTerminatorFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicTerminatorFeature_Data, nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsLogicWrapper_TObjectFeature_Data;
    nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto rtti_nsLogicWrapper_TObjectFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectFeature_Data, nsLogicWrapper_TObjectFeature_Data });
    
    Data nsLogicWrapper_TSceneFeature_Data;
    nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto rtti_nsLogicWrapper_TSceneFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneFeature_Data, nsLogicWrapper_TSceneFeature_Data });
    
    Data nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TStartedScenesInitSystem*>(p)); };
    auto rtti_nsLogicWrapper_TStartedScenesInitSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TStartedScenesInitSystem_Data, nsLogicWrapper_TStartedScenesInitSystem_Data });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mDataVector.resize(max + 1);
    for (auto& vt : m) {
        mDataVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
nsECSFramework::TSystem* TEcsSystemExtension::DynamicCast(void* p, int rtti)
{
    Init();
    return mDataVector[rtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
