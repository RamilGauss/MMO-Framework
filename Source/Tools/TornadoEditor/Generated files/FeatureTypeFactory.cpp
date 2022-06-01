/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_31 21:21:24.119
	
#include "FeatureTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<TFeatureTypeFactory::Data> TFeatureTypeFactory::mDataVector;
void TFeatureTypeFactory::Init()
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
    nsTornadoEditor_TBootstrapperFeature_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperFeature(); };
    nsTornadoEditor_TBootstrapperFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperFeature*)p; };
    auto rtti_nsTornadoEditor_TBootstrapperFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TBootstrapperFeature_Data, nsTornadoEditor_TBootstrapperFeature_Data });
    
    Data nsTornadoEditor_TBootstrapperSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperSystem(); };
    nsTornadoEditor_TBootstrapperSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperSystem*)p; };
    auto rtti_nsTornadoEditor_TBootstrapperSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TBootstrapperSystem_Data, nsTornadoEditor_TBootstrapperSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowRefreshSystem*)p; };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.newFunc = [](){ return new nsTornadoEditor::TMainFeature(); };
    nsTornadoEditor_TMainFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainFeature*)p; };
    auto rtti_nsTornadoEditor_TMainFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TMainFeature_Data, nsTornadoEditor_TMainFeature_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*)p; };
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
void* TFeatureTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TFeatureTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TFeatureTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
