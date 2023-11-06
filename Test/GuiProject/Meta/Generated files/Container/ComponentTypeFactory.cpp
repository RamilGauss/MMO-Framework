/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_06 17:11:46.632
	
#include "ComponentTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<TComponentTypeFactory::Data> TComponentTypeFactory::mDataVector;
void TComponentTypeFactory::Init()
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
void* TComponentTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TComponentTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TComponentTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
