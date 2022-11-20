/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_16 11:21:05.204
	
#include "DynamicCaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<std::vector<TDynamicCaster::Data>> TDynamicCaster::mDataVector;
void TDynamicCaster::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsECSFramework_TBaseCollectReactiveSystem_Map;
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsECSFramework::TBaseCollectReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TBaseCollectReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsECSFramework::TBaseCollectReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    m.insert({ nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_Map });
    
    std::map<int, Data> nsECSFramework_TBaseReactiveSystem_Map;
    
    Data nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TBaseReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TBaseReactiveSystem_Map.insert({ nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsECSFramework::TBaseReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TBaseReactiveSystem_Map.insert({ nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    m.insert({ nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TBaseReactiveSystem_Map });
    
    std::map<int, Data> nsECSFramework_TExecuteSystem_Map;
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TAddPropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TAddPropertiesFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TBeginGraphicFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraBuilderFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TEndGraphicFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TEndGraphicFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TEndGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TEndGraphicFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiBuilderFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiMakerFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiMakerFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiMakerFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiMakerFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsECSFramework_TExecuteSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti, nsECSFramework_TExecuteSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TBeginLogicFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TBeginLogicFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TBeginLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TBeginLogicFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TEndLogicFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TEndLogicFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TEndLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TEndLogicFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicBuilderFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicBuilderFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicBuilderFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicBuilderFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicMakerFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicMakerFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicMakerFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicMakerFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicTerminatorFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TObjectFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TObjectFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TObjectFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TObjectFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TObjectFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsLogicWrapper_TSceneFeature_Data;
    nsECSFramework_TExecuteSystem_nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TSceneFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsLogicWrapper_TSceneFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsLogicWrapper_TSceneFeature_rtti, nsECSFramework_TExecuteSystem_nsLogicWrapper_TSceneFeature_Data });
    
    auto nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    m.insert({ nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TExecuteSystem_Map });
    
    std::map<int, Data> nsECSFramework_TFeature_Map;
    
    Data nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TFeature_nsECSFramework_TSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TAddPropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TAddPropertiesFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TAddPropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TAddPropertiesFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TBeginGraphicFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TBeginGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TBeginGraphicFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraBuilderFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TCameraBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TCameraBuilderFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TEndGraphicFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TEndGraphicFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TEndGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TEndGraphicFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiBuilderFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TGuiBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TGuiBuilderFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TGuiMakerFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiMakerFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TGuiMakerFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TGuiMakerFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TGuiTerminatorFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TGuiTerminatorFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsECSFramework_TFeature_nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsECSFramework_TFeature_nsGraphicWrapper_TUpdatePropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsGraphicWrapper_TUpdatePropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsGraphicWrapper_TUpdatePropertiesFeature_rtti, nsECSFramework_TFeature_nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TBeginLogicFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TBeginLogicFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TBeginLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TBeginLogicFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TEndLogicFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TEndLogicFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TEndLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TEndLogicFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TLogicBuilderFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicBuilderFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TLogicBuilderFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TLogicBuilderFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TLogicMakerFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicMakerFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TLogicMakerFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TLogicMakerFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicTerminatorFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TLogicTerminatorFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TLogicTerminatorFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TObjectFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TObjectFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TObjectFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TObjectFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TObjectFeature_Data });
    
    Data nsECSFramework_TFeature_nsLogicWrapper_TSceneFeature_Data;
    nsECSFramework_TFeature_nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TSceneFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsLogicWrapper_TSceneFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsLogicWrapper_TSceneFeature_rtti, nsECSFramework_TFeature_nsLogicWrapper_TSceneFeature_Data });
    
    auto nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    m.insert({ nsECSFramework_TFeature_rtti, nsECSFramework_TFeature_Map });
    
    std::map<int, Data> nsECSFramework_TInitSystem_Map;
    
    Data nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsECSFramework_TInitSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti, nsECSFramework_TInitSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data;
    nsECSFramework_TInitSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsGraphicWrapper_TPositionUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsGraphicWrapper_TPositionUpdaterSystem_rtti, nsECSFramework_TInitSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsECSFramework_TInitSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsGraphicWrapper_TTitleUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsGraphicWrapper_TTitleUpdaterSystem_rtti, nsECSFramework_TInitSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsECSFramework_TInitSystem_nsLogicWrapper_TStartedScenesInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TStartedScenesInitSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsLogicWrapper_TStartedScenesInitSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsLogicWrapper_TStartedScenesInitSystem_rtti, nsECSFramework_TInitSystem_nsLogicWrapper_TStartedScenesInitSystem_Data });
    
    auto nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    m.insert({ nsECSFramework_TInitSystem_rtti, nsECSFramework_TInitSystem_Map });
    
    std::map<int, Data> nsECSFramework_TSystem_Map;
    
    Data nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TInitSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TInitSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TAddPropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TAddPropertiesFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TBeginGraphicFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraBuilderFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TEndGraphicFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TEndGraphicFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TEndGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TEndGraphicFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiBuilderFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TGuiMakerFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiMakerFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TGuiMakerFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TGuiMakerFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TPositionUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TPositionUpdaterSystem_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TPositionUpdaterSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TTitleUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TTitleUpdaterSystem_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsECSFramework_TSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsECSFramework_TSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti, nsECSFramework_TSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TBeginLogicFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TBeginLogicFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TBeginLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TBeginLogicFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TEndLogicFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TEndLogicFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TEndLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TEndLogicFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsECSFramework_TSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti, nsECSFramework_TSystem_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TLogicBuilderFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicBuilderFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TLogicBuilderFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TLogicBuilderFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TLogicMakerFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicMakerFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TLogicMakerFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TLogicMakerFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicTerminatorFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TObjectFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TObjectFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TObjectFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TObjectFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TObjectFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TSceneFeature_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TSceneFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TSceneFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TSceneFeature_rtti, nsECSFramework_TSystem_nsLogicWrapper_TSceneFeature_Data });
    
    Data nsECSFramework_TSystem_nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsECSFramework_TSystem_nsLogicWrapper_TStartedScenesInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TStartedScenesInitSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsLogicWrapper_TStartedScenesInitSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsLogicWrapper_TStartedScenesInitSystem_rtti, nsECSFramework_TSystem_nsLogicWrapper_TStartedScenesInitSystem_Data });
    
    auto nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    m.insert({ nsECSFramework_TSystem_rtti, nsECSFramework_TSystem_Map });
    
    std::map<int, Data> nsECSFramework_TTearDownSystem_Map;
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TAddPropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TAddPropertiesFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TAddPropertiesFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TBeginGraphicFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TBeginGraphicFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TCameraBuilderFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TCameraBuilderFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TEndGraphicFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TEndGraphicFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TEndGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TEndGraphicFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiBuilderFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiBuilderFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiMakerFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiMakerFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiMakerFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiMakerFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiTerminatorFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsECSFramework_TTearDownSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsGraphicWrapper_TUpdatePropertiesFeature_rtti, nsECSFramework_TTearDownSystem_nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TBeginLogicFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TBeginLogicFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TBeginLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TBeginLogicFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TEndLogicFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TEndLogicFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TEndLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TEndLogicFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicBuilderFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicBuilderFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicBuilderFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicBuilderFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicMakerFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicMakerFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicMakerFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicMakerFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TLogicTerminatorFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicTerminatorFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TObjectFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TObjectFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TObjectFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TObjectFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TObjectFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsLogicWrapper_TSceneFeature_Data;
    nsECSFramework_TTearDownSystem_nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsLogicWrapper::TSceneFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsLogicWrapper_TSceneFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsLogicWrapper_TSceneFeature_rtti, nsECSFramework_TTearDownSystem_nsLogicWrapper_TSceneFeature_Data });
    
    auto nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    m.insert({ nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TTearDownSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TAddPropertiesFeature_Map;
    
    Data nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TAddPropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TAddPropertiesFeature_Map.insert({ nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TAddPropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TAddPropertiesFeature_Map.insert({ nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TAddPropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TAddPropertiesFeature_Map.insert({ nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TAddPropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TAddPropertiesFeature_Map.insert({ nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TAddPropertiesFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TAddPropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    m.insert({ nsGraphicWrapper_TAddPropertiesFeature_rtti, nsGraphicWrapper_TAddPropertiesFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TAnchorsAddSystem_Map;
    
    Data nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TAnchorsAddSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TAnchorsAddSystem_Map.insert({ nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TAnchorsAddSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TAnchorsAddSystem_Map.insert({ nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TAnchorsAddSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TAnchorsAddSystem_Map.insert({ nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TAnchorsAddSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TAnchorsAddSystem_Map.insert({ nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TAnchorsAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TAnchorsAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAnchorsAddSystem>();
    
    m.insert({ nsGraphicWrapper_TAnchorsAddSystem_rtti, nsGraphicWrapper_TAnchorsAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TAnchorsUpdateSystem_Map;
    
    Data nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TAnchorsUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TAnchorsUpdateSystem_Map.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TAnchorsUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TAnchorsUpdateSystem_Map.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TAnchorsUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TAnchorsUpdateSystem_Map.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TAnchorsUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TAnchorsUpdateSystem_Map.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TAnchorsUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TAnchorsUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TAnchorsUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_rtti, nsGraphicWrapper_TAnchorsUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TBeginGraphicFeature_Map;
    
    Data nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TBeginGraphicFeature_Map.insert({ nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TBeginGraphicFeature_Map.insert({ nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TBeginGraphicFeature_Map.insert({ nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TBeginGraphicFeature_Map.insert({ nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TBeginGraphicFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TBeginGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ nsGraphicWrapper_TBeginGraphicFeature_rtti, nsGraphicWrapper_TBeginGraphicFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TButtonBuilderSystem_Map;
    
    Data nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TButtonBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TButtonBuilderSystem_Map.insert({ nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TButtonBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TButtonBuilderSystem_Map.insert({ nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TButtonBuilderSystem_Map.insert({ nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TButtonBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TButtonBuilderSystem_Map.insert({ nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TButtonBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TButtonBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TButtonBuilderSystem_rtti, nsGraphicWrapper_TButtonBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TButtonClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TButtonClickHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_rtti, nsGraphicWrapper_TButtonClickHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_rtti, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TButtonMakerSystem_Map;
    
    Data nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TButtonMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TButtonMakerSystem_Map.insert({ nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TButtonMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TButtonMakerSystem_Map.insert({ nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TButtonMakerSystem_Map.insert({ nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TButtonMakerSystem*>(p)); };
    auto nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TButtonMakerSystem_Map.insert({ nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TButtonMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TButtonMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TButtonMakerSystem_rtti, nsGraphicWrapper_TButtonMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TButtonTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TButtonTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TButtonTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TButtonTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TButtonTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TButtonTerminatorSystem_Map.insert({ nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TButtonTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TButtonTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TButtonTerminatorSystem_rtti, nsGraphicWrapper_TButtonTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TCameraBuilderFeature_Map;
    
    Data nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TCameraBuilderFeature_Map.insert({ nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TCameraBuilderFeature_Map.insert({ nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TCameraBuilderFeature_Map.insert({ nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TCameraBuilderFeature_Map.insert({ nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TCameraBuilderFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TCameraBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    m.insert({ nsGraphicWrapper_TCameraBuilderFeature_rtti, nsGraphicWrapper_TCameraBuilderFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TCameraMakerSystem_Map;
    
    Data nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TCameraMakerSystem*>(p)); };
    auto nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TCameraMakerSystem_Map.insert({ nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TCameraMakerSystem*>(p)); };
    auto nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TCameraMakerSystem_Map.insert({ nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraMakerSystem*>(p)); };
    auto nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TCameraMakerSystem_Map.insert({ nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TCameraMakerSystem*>(p)); };
    auto nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TCameraMakerSystem_Map.insert({ nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TCameraMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TCameraMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TCameraMakerSystem_rtti, nsGraphicWrapper_TCameraMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TCameraTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TCameraTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TCameraTerminatorSystem_Map.insert({ nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TCameraTerminatorSystem_Map.insert({ nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TCameraTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TCameraTerminatorSystem_Map.insert({ nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TCameraTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TCameraTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TCameraTerminatorSystem_rtti, nsGraphicWrapper_TCameraTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TCameraUpdaterToModuleSystem_Map;
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(p)); };
    auto nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Map.insert({ nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(p)); };
    auto nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Map.insert({ nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TCameraUpdaterToModuleSystem_nsECSFramework_TSystem_Data });
    
    auto nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    m.insert({ nsGraphicWrapper_TCameraUpdaterToModuleSystem_rtti, nsGraphicWrapper_TCameraUpdaterToModuleSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TCleanUpUniverseContextSystem_Map;
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Map.insert({ nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Map.insert({ nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TCleanUpUniverseContextSystem_nsECSFramework_TSystem_Data });
    
    auto nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    m.insert({ nsGraphicWrapper_TCleanUpUniverseContextSystem_rtti, nsGraphicWrapper_TCleanUpUniverseContextSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TDialogBuilderSystem_Map;
    
    Data nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TDialogBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TDialogBuilderSystem_Map.insert({ nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TDialogBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TDialogBuilderSystem_Map.insert({ nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TDialogBuilderSystem_Map.insert({ nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TDialogBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TDialogBuilderSystem_Map.insert({ nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TDialogBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TDialogBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TDialogBuilderSystem_rtti, nsGraphicWrapper_TDialogBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_rtti, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TDialogMakerSystem_Map;
    
    Data nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TDialogMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TDialogMakerSystem_Map.insert({ nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TDialogMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TDialogMakerSystem_Map.insert({ nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TDialogMakerSystem_Map.insert({ nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TDialogMakerSystem*>(p)); };
    auto nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TDialogMakerSystem_Map.insert({ nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TDialogMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TDialogMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TDialogMakerSystem_rtti, nsGraphicWrapper_TDialogMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TDialogTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TDialogTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TDialogTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TDialogTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TDialogTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TDialogTerminatorSystem_Map.insert({ nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TDialogTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TDialogTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TDialogTerminatorSystem_rtti, nsGraphicWrapper_TDialogTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TEndGraphicFeature_Map;
    
    Data nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TEndGraphicFeature_Map.insert({ nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TEndGraphicFeature_Map.insert({ nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TEndGraphicFeature_Map.insert({ nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TEndGraphicFeature_Map.insert({ nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TEndGraphicFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TEndGraphicFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    m.insert({ nsGraphicWrapper_TEndGraphicFeature_rtti, nsGraphicWrapper_TEndGraphicFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFocusAddSystem_Map;
    
    Data nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFocusAddSystem*>(p)); };
    auto nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFocusAddSystem_Map.insert({ nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFocusAddSystem*>(p)); };
    auto nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFocusAddSystem_Map.insert({ nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFocusAddSystem*>(p)); };
    auto nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFocusAddSystem_Map.insert({ nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFocusAddSystem*>(p)); };
    auto nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFocusAddSystem_Map.insert({ nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFocusAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFocusAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFocusAddSystem>();
    
    m.insert({ nsGraphicWrapper_TFocusAddSystem_rtti, nsGraphicWrapper_TFocusAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFocusUpdateSystem_Map;
    
    Data nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFocusUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFocusUpdateSystem_Map.insert({ nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFocusUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFocusUpdateSystem_Map.insert({ nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFocusUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFocusUpdateSystem_Map.insert({ nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFocusUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFocusUpdateSystem_Map.insert({ nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFocusUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFocusUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFocusUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TFocusUpdateSystem_rtti, nsGraphicWrapper_TFocusUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameKeyHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_rtti, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_rtti, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_rtti, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_rtti, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiBuilderFeature_Map;
    
    Data nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiBuilderFeature_Map.insert({ nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TGuiBuilderFeature_Map.insert({ nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiBuilderFeature_Map.insert({ nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiBuilderFeature_Map.insert({ nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiBuilderFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiBuilderFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    m.insert({ nsGraphicWrapper_TGuiBuilderFeature_rtti, nsGraphicWrapper_TGuiBuilderFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiCameraBuilderSystem_Map;
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TGuiCameraBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TGuiCameraBuilderSystem_Map.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiCameraBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiCameraBuilderSystem_Map.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiCameraBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiCameraBuilderSystem_Map.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiCameraBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiCameraBuilderSystem_Map.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiCameraBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiCameraBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_rtti, nsGraphicWrapper_TGuiCameraBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiMakerFeature_Map;
    
    Data nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiMakerFeature_Map.insert({ nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TGuiMakerFeature_Map.insert({ nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiMakerFeature_Map.insert({ nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiMakerFeature_Map.insert({ nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiMakerFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiMakerFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    m.insert({ nsGraphicWrapper_TGuiMakerFeature_rtti, nsGraphicWrapper_TGuiMakerFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiTerminatorFeature_Map;
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiTerminatorFeature_Map.insert({ nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TGuiTerminatorFeature_Map.insert({ nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiTerminatorFeature_Map.insert({ nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiTerminatorFeature_Map.insert({ nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiTerminatorFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiTerminatorFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    m.insert({ nsGraphicWrapper_TGuiTerminatorFeature_rtti, nsGraphicWrapper_TGuiTerminatorFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map;
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    m.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_rtti, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map;
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TGuiUpdaterToModuleFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    m.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_rtti, nsGraphicWrapper_TGuiUpdaterToModuleFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_THorizontalAlignAddSystem_Map;
    
    Data nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_THorizontalAlignAddSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_THorizontalAlignAddSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_THorizontalAlignAddSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_THorizontalAlignAddSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_THorizontalAlignAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_THorizontalAlignAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::THorizontalAlignAddSystem>();
    
    m.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_rtti, nsGraphicWrapper_THorizontalAlignAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_THorizontalAlignUpdateSystem_Map;
    
    Data nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_THorizontalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_THorizontalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_THorizontalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::THorizontalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_THorizontalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_THorizontalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_THorizontalAlignUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::THorizontalAlignUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_rtti, nsGraphicWrapper_THorizontalAlignUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TInputTextBuilderSystem_Map;
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TInputTextBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TInputTextBuilderSystem_Map.insert({ nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TInputTextBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TInputTextBuilderSystem_Map.insert({ nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TInputTextBuilderSystem_Map.insert({ nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TInputTextBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TInputTextBuilderSystem_Map.insert({ nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TInputTextBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TInputTextBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TInputTextBuilderSystem_rtti, nsGraphicWrapper_TInputTextBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TInputTextMakerSystem_Map;
    
    Data nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TInputTextMakerSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TInputTextMakerSystem_Map.insert({ nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TInputTextMakerSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TInputTextMakerSystem_Map.insert({ nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextMakerSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TInputTextMakerSystem_Map.insert({ nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TInputTextMakerSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TInputTextMakerSystem_Map.insert({ nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TInputTextMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TInputTextMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TInputTextMakerSystem_rtti, nsGraphicWrapper_TInputTextMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TInputTextTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TInputTextTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TInputTextTerminatorSystem_Map.insert({ nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TInputTextTerminatorSystem_Map.insert({ nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TInputTextTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TInputTextTerminatorSystem_Map.insert({ nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TInputTextTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TInputTextTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TInputTextTerminatorSystem_rtti, nsGraphicWrapper_TInputTextTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TInputTextValueUpdaterSystem_Map;
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Map.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TInitSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Map.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TInitSystem_rtti, nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Map.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Map.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TInputTextValueUpdaterSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    m.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_rtti, nsGraphicWrapper_TInputTextValueUpdaterSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TLabelBuilderSystem_Map;
    
    Data nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TLabelBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TLabelBuilderSystem_Map.insert({ nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TLabelBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TLabelBuilderSystem_Map.insert({ nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TLabelBuilderSystem_Map.insert({ nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TLabelBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TLabelBuilderSystem_Map.insert({ nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TLabelBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TLabelBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TLabelBuilderSystem_rtti, nsGraphicWrapper_TLabelBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TLabelMakerSystem_Map;
    
    Data nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TLabelMakerSystem*>(p)); };
    auto nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TLabelMakerSystem_Map.insert({ nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TLabelMakerSystem*>(p)); };
    auto nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TLabelMakerSystem_Map.insert({ nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelMakerSystem*>(p)); };
    auto nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TLabelMakerSystem_Map.insert({ nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TLabelMakerSystem*>(p)); };
    auto nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TLabelMakerSystem_Map.insert({ nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TLabelMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TLabelMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TLabelMakerSystem_rtti, nsGraphicWrapper_TLabelMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TLabelTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TLabelTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TLabelTerminatorSystem_Map.insert({ nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TLabelTerminatorSystem_Map.insert({ nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TLabelTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TLabelTerminatorSystem_Map.insert({ nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TLabelTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TLabelTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TLabelTerminatorSystem_rtti, nsGraphicWrapper_TLabelTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMainWindowBuilderSystem_Map;
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMainWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMainWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMainWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMainWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMainWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMainWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMainWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMainWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMainWindowBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_rtti, nsGraphicWrapper_TMainWindowBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMainWindowMakerSystem_Map;
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMainWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMainWindowMakerSystem_Map.insert({ nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMainWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMainWindowMakerSystem_Map.insert({ nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMainWindowMakerSystem_Map.insert({ nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMainWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMainWindowMakerSystem_Map.insert({ nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMainWindowMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMainWindowMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TMainWindowMakerSystem_rtti, nsGraphicWrapper_TMainWindowMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMainWindowTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TMainWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TMainWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMainWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMainWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMainWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMainWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMainWindowTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TMainWindowTerminatorSystem_rtti, nsGraphicWrapper_TMainWindowTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMaxSizeAddSystem_Map;
    
    Data nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMaxSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMaxSizeAddSystem_Map.insert({ nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMaxSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMaxSizeAddSystem_Map.insert({ nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMaxSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMaxSizeAddSystem_Map.insert({ nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMaxSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMaxSizeAddSystem_Map.insert({ nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMaxSizeAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMaxSizeAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMaxSizeAddSystem>();
    
    m.insert({ nsGraphicWrapper_TMaxSizeAddSystem_rtti, nsGraphicWrapper_TMaxSizeAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMaxSizeUpdateSystem_Map;
    
    Data nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMaxSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMaxSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMaxSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMaxSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMaxSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMaxSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMaxSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMaxSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMaxSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMaxSizeUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMaxSizeUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_rtti, nsGraphicWrapper_TMaxSizeUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMenuNodeBuilderSystem_Map;
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMenuNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMenuNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMenuNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMenuNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMenuNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMenuNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMenuNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMenuNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMenuNodeBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_rtti, nsGraphicWrapper_TMenuNodeBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_rtti, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMenuNodeMakerSystem_Map;
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMenuNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMenuNodeMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMenuNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMenuNodeMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMenuNodeMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMenuNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMenuNodeMakerSystem_Map.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMenuNodeMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMenuNodeMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_rtti, nsGraphicWrapper_TMenuNodeMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMenuNodeTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TMenuNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMenuNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMenuNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMenuNodeTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TMenuNodeTerminatorSystem_rtti, nsGraphicWrapper_TMenuNodeTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMinDistanceToParentAddSystem_Map;
    
    Data nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentAddSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentAddSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentAddSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentAddSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMinDistanceToParentAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMinDistanceToParentAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMinDistanceToParentAddSystem>();
    
    m.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_rtti, nsGraphicWrapper_TMinDistanceToParentAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map;
    
    Data nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMinDistanceToParentUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMinDistanceToParentUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMinDistanceToParentUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_rtti, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMinSizeAddSystem_Map;
    
    Data nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMinSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMinSizeAddSystem_Map.insert({ nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMinSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMinSizeAddSystem_Map.insert({ nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMinSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMinSizeAddSystem_Map.insert({ nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMinSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMinSizeAddSystem_Map.insert({ nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMinSizeAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMinSizeAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMinSizeAddSystem>();
    
    m.insert({ nsGraphicWrapper_TMinSizeAddSystem_rtti, nsGraphicWrapper_TMinSizeAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TMinSizeUpdateSystem_Map;
    
    Data nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TMinSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TMinSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TMinSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TMinSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMinSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TMinSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TMinSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TMinSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TMinSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TMinSizeUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TMinSizeUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_rtti, nsGraphicWrapper_TMinSizeUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TOnAddUniverseContextSystem_Map;
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TOnAddUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TOnAddUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TOnAddUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TOnAddUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TOnAddUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TOnAddUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TOnAddUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TOnAddUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TOnAddUniverseContextSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TOnAddUniverseContextSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TOnAddUniverseContextSystem>();
    
    m.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_rtti, nsGraphicWrapper_TOnAddUniverseContextSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TOnRemoveUniverseContextSystem_Map;
    
    Data nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TOnRemoveUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TOnRemoveUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TOnRemoveUniverseContextSystem*>(p)); };
    auto nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Map.insert({ nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TOnRemoveUniverseContextSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TOnRemoveUniverseContextSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TOnRemoveUniverseContextSystem>();
    
    m.insert({ nsGraphicWrapper_TOnRemoveUniverseContextSystem_rtti, nsGraphicWrapper_TOnRemoveUniverseContextSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TPositionAddSystem_Map;
    
    Data nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TPositionAddSystem*>(p)); };
    auto nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TPositionAddSystem_Map.insert({ nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TPositionAddSystem*>(p)); };
    auto nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TPositionAddSystem_Map.insert({ nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TPositionAddSystem*>(p)); };
    auto nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TPositionAddSystem_Map.insert({ nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TPositionAddSystem*>(p)); };
    auto nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TPositionAddSystem_Map.insert({ nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TPositionAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TPositionAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionAddSystem>();
    
    m.insert({ nsGraphicWrapper_TPositionAddSystem_rtti, nsGraphicWrapper_TPositionAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TPositionUpdateSystem_Map;
    
    Data nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TPositionUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TPositionUpdateSystem_Map.insert({ nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TPositionUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TPositionUpdateSystem_Map.insert({ nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TPositionUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TPositionUpdateSystem_Map.insert({ nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TPositionUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TPositionUpdateSystem_Map.insert({ nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TPositionUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TPositionUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TPositionUpdateSystem_rtti, nsGraphicWrapper_TPositionUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TPositionUpdaterSystem_Map;
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TPositionUpdaterSystem_Map.insert({ nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TInitSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsGraphicWrapper_TPositionUpdaterSystem_Map.insert({ nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TInitSystem_rtti, nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TPositionUpdaterSystem_Map.insert({ nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TPositionUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TPositionUpdaterSystem_Map.insert({ nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TPositionUpdaterSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TPositionUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    
    m.insert({ nsGraphicWrapper_TPositionUpdaterSystem_rtti, nsGraphicWrapper_TPositionUpdaterSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TSizeAddSystem_Map;
    
    Data nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TSizeAddSystem_Map.insert({ nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TSizeAddSystem_Map.insert({ nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TSizeAddSystem_Map.insert({ nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TSizeAddSystem*>(p)); };
    auto nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TSizeAddSystem_Map.insert({ nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TSizeAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TSizeAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TSizeAddSystem>();
    
    m.insert({ nsGraphicWrapper_TSizeAddSystem_rtti, nsGraphicWrapper_TSizeAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TSizeUpdateSystem_Map;
    
    Data nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TSizeUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TSizeUpdateSystem_Map.insert({ nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TSizeUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TSizeUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TSizeUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TSizeUpdateSystem_rtti, nsGraphicWrapper_TSizeUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTextureMakerSystem_Map;
    
    Data nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTextureMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTextureMakerSystem_Map.insert({ nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTextureMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTextureMakerSystem_Map.insert({ nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTextureMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTextureMakerSystem_Map.insert({ nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTextureMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTextureMakerSystem_Map.insert({ nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTextureMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTextureMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TTextureMakerSystem_rtti, nsGraphicWrapper_TTextureMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTextureTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TTextureTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TTextureTerminatorSystem_Map.insert({ nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTextureTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTextureTerminatorSystem_Map.insert({ nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTextureTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTextureTerminatorSystem_Map.insert({ nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTextureTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTextureTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TTextureTerminatorSystem_rtti, nsGraphicWrapper_TTextureTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTitleAddSystem_Map;
    
    Data nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTitleAddSystem*>(p)); };
    auto nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTitleAddSystem_Map.insert({ nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTitleAddSystem*>(p)); };
    auto nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTitleAddSystem_Map.insert({ nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTitleAddSystem*>(p)); };
    auto nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTitleAddSystem_Map.insert({ nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTitleAddSystem*>(p)); };
    auto nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTitleAddSystem_Map.insert({ nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTitleAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTitleAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleAddSystem>();
    
    m.insert({ nsGraphicWrapper_TTitleAddSystem_rtti, nsGraphicWrapper_TTitleAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTitleUpdateSystem_Map;
    
    Data nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTitleUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTitleUpdateSystem_Map.insert({ nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTitleUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTitleUpdateSystem_Map.insert({ nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTitleUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTitleUpdateSystem_Map.insert({ nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTitleUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTitleUpdateSystem_Map.insert({ nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTitleUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTitleUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TTitleUpdateSystem_rtti, nsGraphicWrapper_TTitleUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTitleUpdaterSystem_Map;
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TTitleUpdaterSystem_Map.insert({ nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TInitSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsGraphicWrapper_TTitleUpdaterSystem_Map.insert({ nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TInitSystem_rtti, nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTitleUpdaterSystem_Map.insert({ nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTitleUpdaterSystem_Map.insert({ nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTitleUpdaterSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTitleUpdaterSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    m.insert({ nsGraphicWrapper_TTitleUpdaterSystem_rtti, nsGraphicWrapper_TTitleUpdaterSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeNodeBuilderSystem_Map;
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTreeNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTreeNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTreeNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeNodeBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeNodeBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeNodeBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeNodeBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_rtti, nsGraphicWrapper_TTreeNodeBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeNodeMakerSystem_Map;
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTreeNodeMakerSystem_Map.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTreeNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTreeNodeMakerSystem_Map.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeNodeMakerSystem_Map.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeNodeMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeNodeMakerSystem_Map.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeNodeMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeNodeMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_rtti, nsGraphicWrapper_TTreeNodeMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeNodeTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeNodeTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeNodeTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeNodeTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeNodeTerminatorSystem_rtti, nsGraphicWrapper_TTreeNodeTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeViewBuilderSystem_Map;
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeViewBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTreeViewBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTreeViewBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTreeViewBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeViewBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeViewBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeViewBuilderSystem_Map.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeViewBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeViewBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_rtti, nsGraphicWrapper_TTreeViewBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeViewMakerSystem_Map;
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeViewMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TTreeViewMakerSystem_Map.insert({ nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TTreeViewMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TTreeViewMakerSystem_Map.insert({ nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeViewMakerSystem_Map.insert({ nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeViewMakerSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeViewMakerSystem_Map.insert({ nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeViewMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeViewMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeViewMakerSystem_rtti, nsGraphicWrapper_TTreeViewMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTreeViewTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TTreeViewTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TTreeViewTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TTreeViewTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TTreeViewTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TTreeViewTerminatorSystem_Map.insert({ nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TTreeViewTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TTreeViewTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TTreeViewTerminatorSystem_rtti, nsGraphicWrapper_TTreeViewTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TUpdatePropertiesFeature_Map;
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TUpdatePropertiesFeature_Map.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TFeature_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsGraphicWrapper_TUpdatePropertiesFeature_Map.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TFeature_rtti, nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TFeature_Data });
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TUpdatePropertiesFeature_Map.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TUpdatePropertiesFeature*>(p)); };
    auto nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TUpdatePropertiesFeature_Map.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TUpdatePropertiesFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TUpdatePropertiesFeature_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    m.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_rtti, nsGraphicWrapper_TUpdatePropertiesFeature_Map });
    
    std::map<int, Data> nsGraphicWrapper_TVerticalAlignAddSystem_Map;
    
    Data nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TVerticalAlignAddSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TVerticalAlignAddSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TVerticalAlignAddSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignAddSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TVerticalAlignAddSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TVerticalAlignAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TVerticalAlignAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TVerticalAlignAddSystem>();
    
    m.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_rtti, nsGraphicWrapper_TVerticalAlignAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TVerticalAlignUpdateSystem_Map;
    
    Data nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TVerticalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TVerticalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TVerticalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TVerticalAlignUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TVerticalAlignUpdateSystem_Map.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TVerticalAlignUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TVerticalAlignUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TVerticalAlignUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_rtti, nsGraphicWrapper_TVerticalAlignUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TVisibilityAddSystem_Map;
    
    Data nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TVisibilityAddSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TVisibilityAddSystem_Map.insert({ nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TVisibilityAddSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TVisibilityAddSystem_Map.insert({ nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TVisibilityAddSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TVisibilityAddSystem_Map.insert({ nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TVisibilityAddSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TVisibilityAddSystem_Map.insert({ nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TVisibilityAddSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TVisibilityAddSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TVisibilityAddSystem>();
    
    m.insert({ nsGraphicWrapper_TVisibilityAddSystem_rtti, nsGraphicWrapper_TVisibilityAddSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TVisibilityUpdateSystem_Map;
    
    Data nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TVisibilityUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TVisibilityUpdateSystem_Map.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TVisibilityUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TVisibilityUpdateSystem_Map.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TVisibilityUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TVisibilityUpdateSystem_Map.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TVisibilityUpdateSystem*>(p)); };
    auto nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TVisibilityUpdateSystem_Map.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TVisibilityUpdateSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TVisibilityUpdateSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TVisibilityUpdateSystem>();
    
    m.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_rtti, nsGraphicWrapper_TVisibilityUpdateSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TWindowBuilderSystem_Map;
    
    Data nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TWindowBuilderSystem*>(p)); };
    auto nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TWindowBuilderSystem_Map.insert({ nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TWindowBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TWindowBuilderSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowBuilderSystem>();
    
    m.insert({ nsGraphicWrapper_TWindowBuilderSystem_rtti, nsGraphicWrapper_TWindowBuilderSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map;
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_rtti, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TWindowMakerSystem_Map;
    
    Data nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsGraphicWrapper::TWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsGraphicWrapper_TWindowMakerSystem_Map.insert({ nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsGraphicWrapper::TWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsGraphicWrapper_TWindowMakerSystem_Map.insert({ nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TWindowMakerSystem_Map.insert({ nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TWindowMakerSystem*>(p)); };
    auto nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TWindowMakerSystem_Map.insert({ nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TWindowMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TWindowMakerSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowMakerSystem>();
    
    m.insert({ nsGraphicWrapper_TWindowMakerSystem_rtti, nsGraphicWrapper_TWindowMakerSystem_Map });
    
    std::map<int, Data> nsGraphicWrapper_TWindowTerminatorSystem_Map;
    
    Data nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsGraphicWrapper::TWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsGraphicWrapper_TWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TSystem_Data;
    nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsGraphicWrapper_TWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TSystem_rtti, nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsGraphicWrapper::TWindowTerminatorSystem*>(p)); };
    auto nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsGraphicWrapper_TWindowTerminatorSystem_Map.insert({ nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsGraphicWrapper_TWindowTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsGraphicWrapper_TWindowTerminatorSystem_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowTerminatorSystem>();
    
    m.insert({ nsGraphicWrapper_TWindowTerminatorSystem_rtti, nsGraphicWrapper_TWindowTerminatorSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TBeginLogicFeature_Map;
    
    Data nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TBeginLogicFeature_Map.insert({ nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TBeginLogicFeature_Map.insert({ nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TBeginLogicFeature_Map.insert({ nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TBeginLogicFeature_Map.insert({ nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TBeginLogicFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TBeginLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    m.insert({ nsLogicWrapper_TBeginLogicFeature_rtti, nsLogicWrapper_TBeginLogicFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TEndLogicFeature_Map;
    
    Data nsLogicWrapper_TEndLogicFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TEndLogicFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto nsLogicWrapper_TEndLogicFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TEndLogicFeature_Map.insert({ nsLogicWrapper_TEndLogicFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TEndLogicFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TEndLogicFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto nsLogicWrapper_TEndLogicFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TEndLogicFeature_Map.insert({ nsLogicWrapper_TEndLogicFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TEndLogicFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TEndLogicFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto nsLogicWrapper_TEndLogicFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TEndLogicFeature_Map.insert({ nsLogicWrapper_TEndLogicFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TEndLogicFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TEndLogicFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto nsLogicWrapper_TEndLogicFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TEndLogicFeature_Map.insert({ nsLogicWrapper_TEndLogicFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TEndLogicFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TEndLogicFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    m.insert({ nsLogicWrapper_TEndLogicFeature_rtti, nsLogicWrapper_TEndLogicFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_THandlerCallCollectorNotifySystem_Map;
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(p)); };
    auto nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Map.insert({ nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(p)); };
    auto nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Map.insert({ nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_THandlerCallCollectorNotifySystem_nsECSFramework_TSystem_Data });
    
    auto nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    m.insert({ nsLogicWrapper_THandlerCallCollectorNotifySystem_rtti, nsLogicWrapper_THandlerCallCollectorNotifySystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TLogicBuilderFeature_Map;
    
    Data nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TLogicBuilderFeature_Map.insert({ nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TLogicBuilderFeature_Map.insert({ nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TLogicBuilderFeature_Map.insert({ nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TLogicBuilderFeature_Map.insert({ nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TLogicBuilderFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TLogicBuilderFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    m.insert({ nsLogicWrapper_TLogicBuilderFeature_rtti, nsLogicWrapper_TLogicBuilderFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TLogicMakerFeature_Map;
    
    Data nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TLogicMakerFeature_Map.insert({ nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TLogicMakerFeature_Map.insert({ nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TLogicMakerFeature_Map.insert({ nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TLogicMakerFeature_Map.insert({ nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TLogicMakerFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TLogicMakerFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    m.insert({ nsLogicWrapper_TLogicMakerFeature_rtti, nsLogicWrapper_TLogicMakerFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TLogicTerminatorFeature_Map;
    
    Data nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TLogicTerminatorFeature_Map.insert({ nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TLogicTerminatorFeature_Map.insert({ nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TLogicTerminatorFeature_Map.insert({ nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TLogicTerminatorFeature_Map.insert({ nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TLogicTerminatorFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TLogicTerminatorFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    m.insert({ nsLogicWrapper_TLogicTerminatorFeature_rtti, nsLogicWrapper_TLogicTerminatorFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TNeedDestroyObjectSystem_Map;
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsLogicWrapper::TNeedDestroyObjectSystem*>(p)); };
    auto nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsLogicWrapper_TNeedDestroyObjectSystem_Map.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TNeedDestroyObjectSystem*>(p)); };
    auto nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TNeedDestroyObjectSystem_Map.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TNeedDestroyObjectSystem*>(p)); };
    auto nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TNeedDestroyObjectSystem_Map.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TNeedDestroyObjectSystem*>(p)); };
    auto nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TNeedDestroyObjectSystem_Map.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TNeedDestroyObjectSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TNeedDestroyObjectSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TNeedDestroyObjectSystem>();
    
    m.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_rtti, nsLogicWrapper_TNeedDestroyObjectSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TObjectFeature_Map;
    
    Data nsLogicWrapper_TObjectFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TObjectFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto nsLogicWrapper_TObjectFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TObjectFeature_Map.insert({ nsLogicWrapper_TObjectFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TObjectFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TObjectFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TObjectFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto nsLogicWrapper_TObjectFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TObjectFeature_Map.insert({ nsLogicWrapper_TObjectFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TObjectFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TObjectFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TObjectFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto nsLogicWrapper_TObjectFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TObjectFeature_Map.insert({ nsLogicWrapper_TObjectFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TObjectFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TObjectFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TObjectFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto nsLogicWrapper_TObjectFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TObjectFeature_Map.insert({ nsLogicWrapper_TObjectFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TObjectFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TObjectFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    m.insert({ nsLogicWrapper_TObjectFeature_rtti, nsLogicWrapper_TObjectFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map;
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem>();
    
    m.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map;
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem>();
    
    m.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_Map;
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_Map.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem>();
    
    m.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_rtti, nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TSceneFeature_Map;
    
    Data nsLogicWrapper_TSceneFeature_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TSceneFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto nsLogicWrapper_TSceneFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TSceneFeature_Map.insert({ nsLogicWrapper_TSceneFeature_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TSceneFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TSceneFeature_nsECSFramework_TFeature_Data;
    nsLogicWrapper_TSceneFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto nsLogicWrapper_TSceneFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsLogicWrapper_TSceneFeature_Map.insert({ nsLogicWrapper_TSceneFeature_nsECSFramework_TFeature_rtti, nsLogicWrapper_TSceneFeature_nsECSFramework_TFeature_Data });
    
    Data nsLogicWrapper_TSceneFeature_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TSceneFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto nsLogicWrapper_TSceneFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TSceneFeature_Map.insert({ nsLogicWrapper_TSceneFeature_nsECSFramework_TSystem_rtti, nsLogicWrapper_TSceneFeature_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TSceneFeature_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TSceneFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto nsLogicWrapper_TSceneFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TSceneFeature_Map.insert({ nsLogicWrapper_TSceneFeature_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TSceneFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TSceneFeature_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ nsLogicWrapper_TSceneFeature_rtti, nsLogicWrapper_TSceneFeature_Map });
    
    std::map<int, Data> nsLogicWrapper_TStartedScenesInitSystem_Map;
    
    Data nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TInitSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsLogicWrapper::TStartedScenesInitSystem*>(p)); };
    auto nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsLogicWrapper_TStartedScenesInitSystem_Map.insert({ nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TInitSystem_rtti, nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TStartedScenesInitSystem*>(p)); };
    auto nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TStartedScenesInitSystem_Map.insert({ nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TStartedScenesInitSystem_nsECSFramework_TSystem_Data });
    
    auto nsLogicWrapper_TStartedScenesInitSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    m.insert({ nsLogicWrapper_TStartedScenesInitSystem_rtti, nsLogicWrapper_TStartedScenesInitSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TSystemBuilderSystem_Map;
    
    Data nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsLogicWrapper::TSystemBuilderSystem*>(p)); };
    auto nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsLogicWrapper_TSystemBuilderSystem_Map.insert({ nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TSystemBuilderSystem*>(p)); };
    auto nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TSystemBuilderSystem_Map.insert({ nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemBuilderSystem*>(p)); };
    auto nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TSystemBuilderSystem_Map.insert({ nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TSystemBuilderSystem*>(p)); };
    auto nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TSystemBuilderSystem_Map.insert({ nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TSystemBuilderSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TSystemBuilderSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSystemBuilderSystem>();
    
    m.insert({ nsLogicWrapper_TSystemBuilderSystem_rtti, nsLogicWrapper_TSystemBuilderSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TSystemMakerSystem_Map;
    
    Data nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsLogicWrapper::TSystemMakerSystem*>(p)); };
    auto nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsLogicWrapper_TSystemMakerSystem_Map.insert({ nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TExecuteSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsLogicWrapper::TSystemMakerSystem*>(p)); };
    auto nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsLogicWrapper_TSystemMakerSystem_Map.insert({ nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TExecuteSystem_rtti, nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemMakerSystem*>(p)); };
    auto nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TSystemMakerSystem_Map.insert({ nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TSystemMakerSystem*>(p)); };
    auto nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TSystemMakerSystem_Map.insert({ nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TSystemMakerSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TSystemMakerSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSystemMakerSystem>();
    
    m.insert({ nsLogicWrapper_TSystemMakerSystem_rtti, nsLogicWrapper_TSystemMakerSystem_Map });
    
    std::map<int, Data> nsLogicWrapper_TSystemTerminatorSystem_Map;
    
    Data nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseReactiveSystem*>(static_cast<nsLogicWrapper::TSystemTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsLogicWrapper_TSystemTerminatorSystem_Map.insert({ nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TSystem_Data;
    nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsLogicWrapper_TSystemTerminatorSystem_Map.insert({ nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TSystem_rtti, nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TSystem_Data });
    
    Data nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TTearDownSystem_Data;
    nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsLogicWrapper::TSystemTerminatorSystem*>(p)); };
    auto nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsLogicWrapper_TSystemTerminatorSystem_Map.insert({ nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TTearDownSystem_rtti, nsLogicWrapper_TSystemTerminatorSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsLogicWrapper_TSystemTerminatorSystem_rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSystemTerminatorSystem>();
    
    m.insert({ nsLogicWrapper_TSystemTerminatorSystem_rtti, nsLogicWrapper_TSystemTerminatorSystem_Map });
    
    int srcMax = 0;
    for (auto& vt : m) {
        srcMax = std::max(vt.first, srcMax);
    }
    
    mDataVector.resize(srcMax + 1);
    for (auto& vt : m) {
        std::vector<Data> vecData;
        int dstMax = 0;
        for (auto& vtDst : vt.second) {
            
            dstMax = std::max(vtDst.first, dstMax);
        }
        
        vecData.resize(dstMax + 1);
        for (auto& vtDst : vt.second) {
            vecData[vtDst.first] = vtDst.second;
        }
        
        mDataVector[vt.first] = vecData;
    }
}
//---------------------------------------------------------------------------------------
void* TDynamicCaster::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[srcRtti][dstRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
