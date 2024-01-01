/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_05_28 18:22:45.838
	
#include "JsonSerializer_InOut_1.h"
#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "JsonSerializer_InOut_0.h"

using namespace nsJson_InOut_1;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TJsonSerializer::TypeFunc> TJsonSerializer::mTypeFuncVector;

void TJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsInOut_BTypeFunc;
    _nsInOut_BTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsInOut::B>((nsInOut::B*) p, str);
    };
    _nsInOut_BTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsInOut::B>((nsInOut::B*) p, str, err);
    };
    
    auto rtti__nsInOut_BTypeFunc = globalTypeIdentifier->Type<nsInOut::B>();
    
    m.insert({ rtti__nsInOut_BTypeFunc, _nsInOut_BTypeFunc });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& vt : m) {
        mTypeFuncVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsInOut::B* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    auto a_o = PUM::AddObject(obj, "a");
    nsJson_InOut_0::TJsonSerializer::_Serialize(&(p->a), a_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsInOut::B* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    auto a_o0 = POM::FindObject(obj, "a");
    nsJson_InOut_0::TJsonSerializer::_Deserialize(&(p->a), a_o0);
}
//---------------------------------------------------------------------------------------
