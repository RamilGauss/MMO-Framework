/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_22 17:36:56.835
	
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
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TFileHierarchyWindowInitSystem*>(p)); };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data, nsTornadoEditor_TFileHierarchyWindowInitSystem_Data });
    
    Data nsTornadoEditor_TInitWindowsFeature_Data;
    nsTornadoEditor_TInitWindowsFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TInitWindowsFeature*>(p)); };
    auto rtti_nsTornadoEditor_TInitWindowsFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TInitWindowsFeature_Data, nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TMainFeature*>(p)); };
    auto rtti_nsTornadoEditor_TMainFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TMainFeature_Data, nsTornadoEditor_TMainFeature_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsTornadoEditor::TObjectHierarchyWindowInitSystem*>(p)); };
    auto rtti_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data, nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data });
    
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
