/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_31 21:21:24.120
	
#include "EcsSystemExtension.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

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
    
    Data nsTornadoEditor_TBootstrapperFeature_Data;
    nsTornadoEditor_TBootstrapperFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TBootstrapperFeature*>(p)); };
    auto rtti_nsTornadoEditor_TBootstrapperFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TBootstrapperFeature_Data, nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsTornadoEditor_TBootstrapperSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TBootstrapperSystem*>(p)); };
    auto rtti_nsTornadoEditor_TBootstrapperSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TBootstrapperSystem_Data, nsTornadoEditor_TBootstrapperSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowRefreshSystem*>(p)); };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto rtti_nsTornadoEditor_TMainFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TMainFeature_Data, nsTornadoEditor_TMainFeature_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*>(p)); };
    auto rtti_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data });
    
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
