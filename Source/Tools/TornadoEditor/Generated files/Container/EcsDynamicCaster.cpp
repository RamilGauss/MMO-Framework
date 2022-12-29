/*
Project Ecs System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_28 18:35:00.269
	
#include "EcsDynamicCaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<std::vector<TEcsDynamicCaster::Data>> TEcsDynamicCaster::mDataVector;
std::map<int, std::set<int>> TEcsDynamicCaster::mRttiCombinations;

void TEcsDynamicCaster::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
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
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TBaseCollectReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TBaseCollectReactiveSystem*>(p)); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data });
    
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
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsTornadoEditor_TBootstrapperFeature_Data;
    nsECSFramework_TExecuteSystem_nsTornadoEditor_TBootstrapperFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsTornadoEditor_TBootstrapperFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsTornadoEditor_TBootstrapperFeature_rtti, nsECSFramework_TExecuteSystem_nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TExecuteSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti, nsECSFramework_TExecuteSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsTornadoEditor_TInitWindowsFeature_Data;
    nsECSFramework_TExecuteSystem_nsTornadoEditor_TInitWindowsFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TInitWindowsFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsTornadoEditor_TInitWindowsFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsTornadoEditor_TInitWindowsFeature_rtti, nsECSFramework_TExecuteSystem_nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsTornadoEditor_TMainFeature_Data;
    nsECSFramework_TExecuteSystem_nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TMainFeature*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsTornadoEditor_TMainFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsTornadoEditor_TMainFeature_rtti, nsECSFramework_TExecuteSystem_nsTornadoEditor_TMainFeature_Data });
    
    Data nsECSFramework_TExecuteSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TExecuteSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TExecuteSystem*>(p)); };
    auto nsECSFramework_TExecuteSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti, nsECSFramework_TExecuteSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data });
    
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
    
    Data nsECSFramework_TFeature_nsTornadoEditor_TBootstrapperFeature_Data;
    nsECSFramework_TFeature_nsTornadoEditor_TBootstrapperFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsTornadoEditor_TBootstrapperFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsTornadoEditor_TBootstrapperFeature_rtti, nsECSFramework_TFeature_nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsECSFramework_TFeature_nsTornadoEditor_TInitWindowsFeature_Data;
    nsECSFramework_TFeature_nsTornadoEditor_TInitWindowsFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TInitWindowsFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsTornadoEditor_TInitWindowsFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsTornadoEditor_TInitWindowsFeature_rtti, nsECSFramework_TFeature_nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsECSFramework_TFeature_nsTornadoEditor_TMainFeature_Data;
    nsECSFramework_TFeature_nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TMainFeature*>(static_cast<nsECSFramework::TFeature*>(p)); };
    auto nsECSFramework_TFeature_nsTornadoEditor_TMainFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsTornadoEditor_TMainFeature_rtti, nsECSFramework_TFeature_nsTornadoEditor_TMainFeature_Data });
    
    auto nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    m.insert({ nsECSFramework_TFeature_rtti, nsECSFramework_TFeature_Map });
    
    std::map<int, Data> nsECSFramework_TInitSystem_Map;
    
    Data nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TInitSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsTornadoEditor_TBootstrapperSystem_Data;
    nsECSFramework_TInitSystem_nsTornadoEditor_TBootstrapperSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsTornadoEditor_TBootstrapperSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsTornadoEditor_TBootstrapperSystem_rtti, nsECSFramework_TInitSystem_nsTornadoEditor_TBootstrapperSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsECSFramework_TInitSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowInitSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti, nsECSFramework_TInitSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data });
    
    Data nsECSFramework_TInitSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsECSFramework_TInitSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowInitSystem*>(static_cast<nsECSFramework::TInitSystem*>(p)); };
    auto nsECSFramework_TInitSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    nsECSFramework_TInitSystem_Map.insert({ nsECSFramework_TInitSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti, nsECSFramework_TInitSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data });
    
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
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperFeature_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperFeature_rtti, nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperSystem_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperSystem_rtti, nsECSFramework_TSystem_nsTornadoEditor_TBootstrapperSystem_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowInitSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti, nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti, nsECSFramework_TSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TInitWindowsFeature_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TInitWindowsFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TInitWindowsFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TInitWindowsFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TInitWindowsFeature_rtti, nsECSFramework_TSystem_nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TMainFeature_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TMainFeature*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TMainFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TMainFeature_rtti, nsECSFramework_TSystem_nsTornadoEditor_TMainFeature_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowInitSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti, nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data });
    
    Data nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TSystem*>(p)); };
    auto nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti, nsECSFramework_TSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data });
    
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
    
    Data nsECSFramework_TTearDownSystem_nsTornadoEditor_TBootstrapperFeature_Data;
    nsECSFramework_TTearDownSystem_nsTornadoEditor_TBootstrapperFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TBootstrapperFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsTornadoEditor_TBootstrapperFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsTornadoEditor_TBootstrapperFeature_rtti, nsECSFramework_TTearDownSystem_nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TTearDownSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti, nsECSFramework_TTearDownSystem_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsTornadoEditor_TInitWindowsFeature_Data;
    nsECSFramework_TTearDownSystem_nsTornadoEditor_TInitWindowsFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TInitWindowsFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsTornadoEditor_TInitWindowsFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsTornadoEditor_TInitWindowsFeature_rtti, nsECSFramework_TTearDownSystem_nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsTornadoEditor_TMainFeature_Data;
    nsECSFramework_TTearDownSystem_nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TMainFeature*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsTornadoEditor_TMainFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsTornadoEditor_TMainFeature_rtti, nsECSFramework_TTearDownSystem_nsTornadoEditor_TMainFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsECSFramework_TTearDownSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(static_cast<nsECSFramework::TTearDownSystem*>(p)); };
    auto nsECSFramework_TTearDownSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti, nsECSFramework_TTearDownSystem_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data });
    
    auto nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    m.insert({ nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TTearDownSystem_Map });
    
    std::map<int, Data> nsTornadoEditor_TBootstrapperFeature_Map;
    
    Data nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TExecuteSystem_Data;
    nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsTornadoEditor::TBootstrapperFeature*>(p)); };
    auto nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsTornadoEditor_TBootstrapperFeature_Map.insert({ nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TExecuteSystem_rtti, nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TFeature_Data;
    nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsTornadoEditor::TBootstrapperFeature*>(p)); };
    auto nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsTornadoEditor_TBootstrapperFeature_Map.insert({ nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TFeature_rtti, nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TFeature_Data });
    
    Data nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TBootstrapperFeature*>(p)); };
    auto nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TBootstrapperFeature_Map.insert({ nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TSystem_rtti, nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TSystem_Data });
    
    Data nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TTearDownSystem_Data;
    nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsTornadoEditor::TBootstrapperFeature*>(p)); };
    auto nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsTornadoEditor_TBootstrapperFeature_Map.insert({ nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TTearDownSystem_rtti, nsTornadoEditor_TBootstrapperFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsTornadoEditor_TBootstrapperFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    m.insert({ nsTornadoEditor_TBootstrapperFeature_rtti, nsTornadoEditor_TBootstrapperFeature_Map });
    
    std::map<int, Data> nsTornadoEditor_TBootstrapperSystem_Map;
    
    Data nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TInitSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsTornadoEditor::TBootstrapperSystem*>(p)); };
    auto nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsTornadoEditor_TBootstrapperSystem_Map.insert({ nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TInitSystem_rtti, nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TBootstrapperSystem*>(p)); };
    auto nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TBootstrapperSystem_Map.insert({ nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TSystem_rtti, nsTornadoEditor_TBootstrapperSystem_nsECSFramework_TSystem_Data });
    
    auto nsTornadoEditor_TBootstrapperSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    m.insert({ nsTornadoEditor_TBootstrapperSystem_rtti, nsTornadoEditor_TBootstrapperSystem_Map });
    
    std::map<int, Data> nsTornadoEditor_TFileHierarchyWindowInitSystem_Map;
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowInitSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TInitSystem_rtti, nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowInitSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TSystem_rtti, nsTornadoEditor_TFileHierarchyWindowInitSystem_nsECSFramework_TSystem_Data });
    
    auto nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    m.insert({ nsTornadoEditor_TFileHierarchyWindowInitSystem_rtti, nsTornadoEditor_TFileHierarchyWindowInitSystem_Map });
    
    std::map<int, Data> nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map;
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_rtti, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TSystem_rtti, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_rtti, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    m.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_rtti, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Map });
    
    std::map<int, Data> nsTornadoEditor_TInitWindowsFeature_Map;
    
    Data nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TExecuteSystem_Data;
    nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsTornadoEditor::TInitWindowsFeature*>(p)); };
    auto nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsTornadoEditor_TInitWindowsFeature_Map.insert({ nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TExecuteSystem_rtti, nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TFeature_Data;
    nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsTornadoEditor::TInitWindowsFeature*>(p)); };
    auto nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsTornadoEditor_TInitWindowsFeature_Map.insert({ nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TFeature_rtti, nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TFeature_Data });
    
    Data nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TInitWindowsFeature*>(p)); };
    auto nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TInitWindowsFeature_Map.insert({ nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TSystem_rtti, nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TSystem_Data });
    
    Data nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TTearDownSystem_Data;
    nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsTornadoEditor::TInitWindowsFeature*>(p)); };
    auto nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsTornadoEditor_TInitWindowsFeature_Map.insert({ nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TTearDownSystem_rtti, nsTornadoEditor_TInitWindowsFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsTornadoEditor_TInitWindowsFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    m.insert({ nsTornadoEditor_TInitWindowsFeature_rtti, nsTornadoEditor_TInitWindowsFeature_Map });
    
    std::map<int, Data> nsTornadoEditor_TMainFeature_Map;
    
    Data nsTornadoEditor_TMainFeature_nsECSFramework_TExecuteSystem_Data;
    nsTornadoEditor_TMainFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto nsTornadoEditor_TMainFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsTornadoEditor_TMainFeature_Map.insert({ nsTornadoEditor_TMainFeature_nsECSFramework_TExecuteSystem_rtti, nsTornadoEditor_TMainFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsTornadoEditor_TMainFeature_nsECSFramework_TFeature_Data;
    nsTornadoEditor_TMainFeature_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TFeature*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto nsTornadoEditor_TMainFeature_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsTornadoEditor_TMainFeature_Map.insert({ nsTornadoEditor_TMainFeature_nsECSFramework_TFeature_rtti, nsTornadoEditor_TMainFeature_nsECSFramework_TFeature_Data });
    
    Data nsTornadoEditor_TMainFeature_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TMainFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto nsTornadoEditor_TMainFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TMainFeature_Map.insert({ nsTornadoEditor_TMainFeature_nsECSFramework_TSystem_rtti, nsTornadoEditor_TMainFeature_nsECSFramework_TSystem_Data });
    
    Data nsTornadoEditor_TMainFeature_nsECSFramework_TTearDownSystem_Data;
    nsTornadoEditor_TMainFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto nsTornadoEditor_TMainFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsTornadoEditor_TMainFeature_Map.insert({ nsTornadoEditor_TMainFeature_nsECSFramework_TTearDownSystem_rtti, nsTornadoEditor_TMainFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsTornadoEditor_TMainFeature_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    m.insert({ nsTornadoEditor_TMainFeature_rtti, nsTornadoEditor_TMainFeature_Map });
    
    std::map<int, Data> nsTornadoEditor_TObjectHierarchyWindowInitSystem_Map;
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TInitSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowInitSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TInitSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TInitSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TInitSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TInitSystem_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowInitSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowInitSystem_nsECSFramework_TSystem_Data });
    
    auto nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    m.insert({ nsTornadoEditor_TObjectHierarchyWindowInitSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowInitSystem_Map });
    
    std::map<int, Data> nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map;
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TBaseCollectReactiveSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TExecuteSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TSystem_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TTearDownSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(p)); };
    auto nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    m.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_rtti, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Map });
    
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
        std::set<int> rttis;
        for (auto& vtDst : vt.second) {
            vecData[vtDst.first] = vtDst.second;
            rttis.insert(vtDst.first);
        }
        
        mRttiCombinations.insert({ vt.first, rttis });
        
        mDataVector[vt.first] = vecData;
    }
}
//---------------------------------------------------------------------------------------
void* TEcsDynamicCaster::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[srcRtti][dstRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TEcsDynamicCaster::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
