/*
Project System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_01_15 11:03:00.798
	
#include "SystemTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<TSystemTypeFactory::Data> TSystemTypeFactory::mDataVector;
void TSystemTypeFactory::Init()
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
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowInitSystem(); };
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowInitSystem*)p; };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowInitSystem_Data, nsTornadoEditor_TFileHierarchyWindowInitSystem_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowRefreshSystem*)p; };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data });
    
    Data nsTornadoEditor_TInitWindowsFeature_Data;
    nsTornadoEditor_TInitWindowsFeature_Data.newFunc = [](){ return new nsTornadoEditor::TInitWindowsFeature(); };
    nsTornadoEditor_TInitWindowsFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TInitWindowsFeature*)p; };
    auto rtti_nsTornadoEditor_TInitWindowsFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TInitWindowsFeature_Data, nsTornadoEditor_TInitWindowsFeature_Data });
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.newFunc = [](){ return new nsTornadoEditor::TMainFeature(); };
    nsTornadoEditor_TMainFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainFeature*)p; };
    auto rtti_nsTornadoEditor_TMainFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TMainFeature_Data, nsTornadoEditor_TMainFeature_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowInitSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowInitSystem*)p; };
    auto rtti_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    m.insert({ rtti_nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data, nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data });
    
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
void* TSystemTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TSystemTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TSystemTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
