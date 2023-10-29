/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:17:14.636
	
#include "HandlerTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<THandlerTypeFactory::Data> THandlerTypeFactory::mDataVector;
void THandlerTypeFactory::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<Data> datas;
    
    Data nsGuiProject_TScenePrefabTestComponent_Data;
    nsGuiProject_TScenePrefabTestComponent_Data.newFunc = [](){ return new nsGuiProject::TScenePrefabTestComponent(); };
    nsGuiProject_TScenePrefabTestComponent_Data.deleteFunc = [](void* p){ delete (nsGuiProject::TScenePrefabTestComponent*)p; };
    nsGuiProject_TScenePrefabTestComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiProject::TScenePrefabTestComponent>();
    
    datas.push_back(nsGuiProject_TScenePrefabTestComponent_Data);
    
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
void* THandlerTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void THandlerTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool THandlerTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
