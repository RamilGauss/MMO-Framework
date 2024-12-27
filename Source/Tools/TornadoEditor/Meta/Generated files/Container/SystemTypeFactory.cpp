/*
Project System
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_27 12:43:36.247
#include "SystemTypeFactory.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

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
    
    std::list<Data> datas;
    
    Data nsTornadoEditor_TBootstrapperFeature_Data;
    nsTornadoEditor_TBootstrapperFeature_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperFeature(); };
    nsTornadoEditor_TBootstrapperFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperFeature*)p; };
    nsTornadoEditor_TBootstrapperFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    datas.push_back(nsTornadoEditor_TBootstrapperFeature_Data);
    
    Data nsTornadoEditor_TBootstrapperSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperSystem(); };
    nsTornadoEditor_TBootstrapperSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperSystem*)p; };
    nsTornadoEditor_TBootstrapperSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    datas.push_back(nsTornadoEditor_TBootstrapperSystem_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowInitSystem(); };
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowInitSystem*)p; };
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowRefreshSystem*)p; };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data);
    
    Data nsTornadoEditor_TInitWindowsFeature_Data;
    nsTornadoEditor_TInitWindowsFeature_Data.newFunc = [](){ return new nsTornadoEditor::TInitWindowsFeature(); };
    nsTornadoEditor_TInitWindowsFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TInitWindowsFeature*)p; };
    nsTornadoEditor_TInitWindowsFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    datas.push_back(nsTornadoEditor_TInitWindowsFeature_Data);
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.newFunc = [](){ return new nsTornadoEditor::TMainFeature(); };
    nsTornadoEditor_TMainFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainFeature*)p; };
    nsTornadoEditor_TMainFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    datas.push_back(nsTornadoEditor_TMainFeature_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowInitSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowInitSystem*)p; };
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*)p; };
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mDataVector.resize(max + 1);
    for (auto& d : datas) {
        mDataVector[d.rtti] = d;
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
