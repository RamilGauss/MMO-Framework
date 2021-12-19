/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_19 11:45:53.227
	
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
    
    Data nsTornadoEditor_TExampleFeature_Data;
    nsTornadoEditor_TExampleFeature_Data.newFunc = [](){ return new nsTornadoEditor::TExampleFeature(); };
    nsTornadoEditor_TExampleFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TExampleFeature*)p; };
    auto rtti_nsTornadoEditor_TExampleFeature_Data = globalTypeIdentifier->Type<nsTornadoEditor::TExampleFeature>();
    
    m.insert({ rtti_nsTornadoEditor_TExampleFeature_Data, nsTornadoEditor_TExampleFeature_Data });
    
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
