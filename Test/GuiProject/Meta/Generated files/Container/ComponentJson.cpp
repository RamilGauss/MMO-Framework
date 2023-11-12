/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_12 13:46:44.820
	
#include "ComponentJson.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentJson::TypeFunc> TComponentJson::mTypeFuncVector;

void TComponentJson::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<TypeFunc> funcs;
    
    TypeFunc _nsGuiProject_TScenePrefabTestComponentTypeFunc;
    _nsGuiProject_TScenePrefabTestComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiProject::TScenePrefabTestComponent>((nsGuiProject::TScenePrefabTestComponent*) p, str);
    };
    _nsGuiProject_TScenePrefabTestComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiProject::TScenePrefabTestComponent>((nsGuiProject::TScenePrefabTestComponent*) p, str, err);
    };
    
    _nsGuiProject_TScenePrefabTestComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsGuiProject::TScenePrefabTestComponent>();
    
    funcs.push_back(_nsGuiProject_TScenePrefabTestComponentTypeFunc);
    
    int max = 0;
    for (auto& f : funcs) {
        max = std::max(f.rtti, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& f : funcs) {
        mTypeFuncVector[f.rtti] = f;
    }
}
//---------------------------------------------------------------------------------------
void TComponentJson::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiProject::TScenePrefabTestComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiProject::TScenePrefabTestComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
