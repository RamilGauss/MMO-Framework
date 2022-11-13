/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_11_08 14:16:12.111
	
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
    
    Data nsGraphicWrapper_TAddPropertiesFeature_Data;
    nsGraphicWrapper_TAddPropertiesFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TAddPropertiesFeature(); };
    nsGraphicWrapper_TAddPropertiesFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TAddPropertiesFeature*)p; };
    auto rtti_nsGraphicWrapper_TAddPropertiesFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TAddPropertiesFeature_Data, nsGraphicWrapper_TAddPropertiesFeature_Data });
    
    Data nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsGraphicWrapper_TBeginGraphicFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TBeginGraphicFeature(); };
    nsGraphicWrapper_TBeginGraphicFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TBeginGraphicFeature*)p; };
    auto rtti_nsGraphicWrapper_TBeginGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TBeginGraphicFeature_Data, nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsGraphicWrapper_TCameraBuilderFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraBuilderFeature(); };
    nsGraphicWrapper_TCameraBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraBuilderFeature*)p; };
    auto rtti_nsGraphicWrapper_TCameraBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraBuilderFeature_Data, nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraUpdaterToModuleSystem(); };
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraUpdaterToModuleSystem*)p; };
    auto rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data, nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCleanUpUniverseContextSystem(); };
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCleanUpUniverseContextSystem*)p; };
    auto rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data, nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
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
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiUpdaterFromModuleFeature(); };
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiUpdaterFromModuleFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiUpdaterToModuleFeature(); };
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiUpdaterToModuleFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TInputTextValueUpdaterSystem(); };
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TInputTextValueUpdaterSystem*)p; };
    auto rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data, nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TPositionUpdaterSystem_Data;
    nsGraphicWrapper_TPositionUpdaterSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TPositionUpdaterSystem(); };
    nsGraphicWrapper_TPositionUpdaterSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TPositionUpdaterSystem*)p; };
    auto rtti_nsGraphicWrapper_TPositionUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TPositionUpdaterSystem_Data, nsGraphicWrapper_TPositionUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTitleUpdaterSystem(); };
    nsGraphicWrapper_TTitleUpdaterSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTitleUpdaterSystem*)p; };
    auto rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data, nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TUpdatePropertiesFeature_Data;
    nsGraphicWrapper_TUpdatePropertiesFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TUpdatePropertiesFeature(); };
    nsGraphicWrapper_TUpdatePropertiesFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TUpdatePropertiesFeature*)p; };
    auto rtti_nsGraphicWrapper_TUpdatePropertiesFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TUpdatePropertiesFeature_Data, nsGraphicWrapper_TUpdatePropertiesFeature_Data });
    
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
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.newFunc = [](){ return new nsLogicWrapper::THandlerCallCollectorNotifySystem(); };
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::THandlerCallCollectorNotifySystem*)p; };
    auto rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    m.insert({ rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data, nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
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
    
    Data nsLogicWrapper_TObjectFeature_Data;
    nsLogicWrapper_TObjectFeature_Data.newFunc = [](){ return new nsLogicWrapper::TObjectFeature(); };
    nsLogicWrapper_TObjectFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TObjectFeature*)p; };
    auto rtti_nsLogicWrapper_TObjectFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectFeature_Data, nsLogicWrapper_TObjectFeature_Data });
    
    Data nsLogicWrapper_TSceneFeature_Data;
    nsLogicWrapper_TSceneFeature_Data.newFunc = [](){ return new nsLogicWrapper::TSceneFeature(); };
    nsLogicWrapper_TSceneFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSceneFeature*)p; };
    auto rtti_nsLogicWrapper_TSceneFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneFeature_Data, nsLogicWrapper_TSceneFeature_Data });
    
    Data nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_Data.newFunc = [](){ return new nsLogicWrapper::TStartedScenesInitSystem(); };
    nsLogicWrapper_TStartedScenesInitSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TStartedScenesInitSystem*)p; };
    auto rtti_nsLogicWrapper_TStartedScenesInitSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TStartedScenesInitSystem_Data, nsLogicWrapper_TStartedScenesInitSystem_Data });
    
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
