/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_19 11:41:21.716
	
#include "FeatureTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

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
    
    Data nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsGraphicWrapper_TBeginGraphicFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TBeginGraphicFeature(); };
    nsGraphicWrapper_TBeginGraphicFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TBeginGraphicFeature*)p; };
    auto rtti_nsGraphicWrapper_TBeginGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TBeginGraphicFeature_Data, nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_Data;
    nsGraphicWrapper_TEndGraphicFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TEndGraphicFeature(); };
    nsGraphicWrapper_TEndGraphicFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TEndGraphicFeature*)p; };
    auto rtti_nsGraphicWrapper_TEndGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TEndGraphicFeature_Data, nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsGraphicWrapper_TGuiBuilderFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiBuilderFeature(); };
    nsGraphicWrapper_TGuiBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiBuilderFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiBuilderFeature_Data, nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_Data;
    nsGraphicWrapper_TGuiMakerFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiMakerFeature(); };
    nsGraphicWrapper_TGuiMakerFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiMakerFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiMakerFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiMakerFeature_Data, nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiTerminatorFeature(); };
    nsGraphicWrapper_TGuiTerminatorFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiTerminatorFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data, nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiUpdaterFeature(); };
    nsGraphicWrapper_TGuiUpdaterFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiUpdaterFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiUpdaterFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterFeature_Data, nsGraphicWrapper_TGuiUpdaterFeature_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_Data;
    nsLogicWrapper_TBeginLogicFeature_Data.newFunc = [](){ return new nsLogicWrapper::TBeginLogicFeature(); };
    nsLogicWrapper_TBeginLogicFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TBeginLogicFeature*)p; };
    auto rtti_nsLogicWrapper_TBeginLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TBeginLogicFeature_Data, nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_Data;
    nsLogicWrapper_TEndLogicFeature_Data.newFunc = [](){ return new nsLogicWrapper::TEndLogicFeature(); };
    nsLogicWrapper_TEndLogicFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TEndLogicFeature*)p; };
    auto rtti_nsLogicWrapper_TEndLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TEndLogicFeature_Data, nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_Data;
    nsLogicWrapper_TLogicBuilderFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicBuilderFeature(); };
    nsLogicWrapper_TLogicBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicBuilderFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicBuilderFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicBuilderFeature_Data, nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_Data;
    nsLogicWrapper_TLogicMakerFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicMakerFeature(); };
    nsLogicWrapper_TLogicMakerFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicMakerFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicMakerFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicMakerFeature_Data, nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsLogicWrapper_TLogicTerminatorFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicTerminatorFeature(); };
    nsLogicWrapper_TLogicTerminatorFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicTerminatorFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicTerminatorFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicTerminatorFeature_Data, nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsLogicWrapper_TPrefabFeature_Data;
    nsLogicWrapper_TPrefabFeature_Data.newFunc = [](){ return new nsLogicWrapper::TPrefabFeature(); };
    nsLogicWrapper_TPrefabFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TPrefabFeature*)p; };
    auto rtti_nsLogicWrapper_TPrefabFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TPrefabFeature_Data, nsLogicWrapper_TPrefabFeature_Data });
    
    Data nsLogicWrapper_TSceneFeature_Data;
    nsLogicWrapper_TSceneFeature_Data.newFunc = [](){ return new nsLogicWrapper::TSceneFeature(); };
    nsLogicWrapper_TSceneFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSceneFeature*)p; };
    auto rtti_nsLogicWrapper_TSceneFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneFeature_Data, nsLogicWrapper_TSceneFeature_Data });
    
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
