/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_01_09 09:44:01.028
	
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
