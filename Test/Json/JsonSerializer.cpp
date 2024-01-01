/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_05_28 18:22:44.392
	
#include "Base/Common/JsonSerializer.h"
#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsJson;

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
    
    TypeFunc _nsComplex_YTypeFunc;
    _nsComplex_YTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsComplex::Y>((nsComplex::Y*) p, str);
    };
    _nsComplex_YTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsComplex::Y>((nsComplex::Y*) p, str, err);
    };
    
    auto rtti__nsComplex_YTypeFunc = globalTypeIdentifier->Type<nsComplex::Y>();
    
    m.insert({ rtti__nsComplex_YTypeFunc, _nsComplex_YTypeFunc });
    
    TypeFunc _nsFarType_XTypeFunc;
    _nsFarType_XTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsFarType::X>((nsFarType::X*) p, str);
    };
    _nsFarType_XTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsFarType::X>((nsFarType::X*) p, str, err);
    };
    
    auto rtti__nsFarType_XTypeFunc = globalTypeIdentifier->Type<nsFarType::X>();
    
    m.insert({ rtti__nsFarType_XTypeFunc, _nsFarType_XTypeFunc });
    
    TypeFunc _nsInOut_ATypeFunc;
    _nsInOut_ATypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsInOut::A>((nsInOut::A*) p, str);
    };
    _nsInOut_ATypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsInOut::A>((nsInOut::A*) p, str, err);
    };
    
    auto rtti__nsInOut_ATypeFunc = globalTypeIdentifier->Type<nsInOut::A>();
    
    m.insert({ rtti__nsInOut_ATypeFunc, _nsInOut_ATypeFunc });
    
    TypeFunc _nsInOut_BTypeFunc;
    _nsInOut_BTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsInOut::B>((nsInOut::B*) p, str);
    };
    _nsInOut_BTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsInOut::B>((nsInOut::B*) p, str, err);
    };
    
    auto rtti__nsInOut_BTypeFunc = globalTypeIdentifier->Type<nsInOut::B>();
    
    m.insert({ rtti__nsInOut_BTypeFunc, _nsInOut_BTypeFunc });
    
    TypeFunc _nsSimple_XTypeFunc;
    _nsSimple_XTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimple::X>((nsSimple::X*) p, str);
    };
    _nsSimple_XTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimple::X>((nsSimple::X*) p, str, err);
    };
    
    auto rtti__nsSimple_XTypeFunc = globalTypeIdentifier->Type<nsSimple::X>();
    
    m.insert({ rtti__nsSimple_XTypeFunc, _nsSimple_XTypeFunc });
    
    TypeFunc _nsSimpleEnum_XTypeFunc;
    _nsSimpleEnum_XTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimpleEnum::X>((nsSimpleEnum::X*) p, str);
    };
    _nsSimpleEnum_XTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimpleEnum::X>((nsSimpleEnum::X*) p, str, err);
    };
    
    auto rtti__nsSimpleEnum_XTypeFunc = globalTypeIdentifier->Type<nsSimpleEnum::X>();
    
    m.insert({ rtti__nsSimpleEnum_XTypeFunc, _nsSimpleEnum_XTypeFunc });
    
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
void TJsonSerializer::_Serialize(nsComplex::Y* p, Jobj& obj)
{
    auto x_o = PUM::AddObject(obj, "x");
    _Serialize(&(p->x), x_o);
    if (p->px == nullptr) {
        PUM::PushNull(obj, "px");
    } else {
        auto px_o = PUM::AddObject(obj, "px");
        _Serialize(p->px, px_o);
    }
    if (p->shx.get() == nullptr) {
        PUM::PushNull(obj, "shx");
    } else {
        auto shx_o = PUM::AddObject(obj, "shx");
        _Serialize(p->shx.get(), shx_o);
    }
    PUM::Value x_l_a0(rapidjson::kArrayType);
    for(auto& x_l_e0 : p->x_l) {
        PUM::Value x_l_a1(rapidjson::kObjectType);
        auto x_l_c1 = x_l_a1.GetObject();
        _Serialize(&x_l_e0, x_l_c1);
        PUM::PushBack(x_l_a0, x_l_a1);
    }
    PUM::Push(obj, "x_l", x_l_a0);
    PUM::Value px_l_a0(rapidjson::kArrayType);
    for(auto& px_l_e0 : p->px_l) {
        if (px_l_e0 == nullptr) {
            PUM::PushBackNull(px_l_a0);
        } else {
            PUM::Value px_l_a1(rapidjson::kObjectType);
            auto px_l_c1 = px_l_a1.GetObject();
            _Serialize(px_l_e0, px_l_c1);
            PUM::PushBack(px_l_a0, px_l_a1);
        }
    }
    PUM::Push(obj, "px_l", px_l_a0);
    PUM::Value shx_l_a0(rapidjson::kArrayType);
    for(auto& shx_l_e0 : p->shx_l) {
        if (shx_l_e0.get() == nullptr) {
            PUM::PushBackNull(shx_l_a0);
        } else {
            PUM::Value shx_l_a1(rapidjson::kObjectType);
            auto shx_l_c1 = shx_l_a1.GetObject();
            _Serialize(shx_l_e0.get(), shx_l_c1);
            PUM::PushBack(shx_l_a0, shx_l_a1);
        }
    }
    PUM::Push(obj, "shx_l", shx_l_a0);
    PUM::Value x_ll_a0(rapidjson::kArrayType);
    for(auto& x_ll_e0 : p->x_ll) {
        PUM::Value x_ll_a1(rapidjson::kArrayType);
        for(auto& x_ll_e1 : x_ll_e0) {
            PUM::Value x_ll_a2(rapidjson::kObjectType);
            auto x_ll_c2 = x_ll_a2.GetObject();
            _Serialize(&x_ll_e1, x_ll_c2);
            PUM::PushBack(x_ll_a1, x_ll_a2);
        }
        PUM::PushBack(x_ll_a0, x_ll_a1);
    }
    PUM::Push(obj, "x_ll", x_ll_a0);
    PUM::Value px_ll_a0(rapidjson::kArrayType);
    for(auto& px_ll_e0 : p->px_ll) {
        PUM::Value px_ll_a1(rapidjson::kArrayType);
        for(auto& px_ll_e1 : px_ll_e0) {
            if (px_ll_e1 == nullptr) {
                PUM::PushBackNull(px_ll_a1);
            } else {
                PUM::Value px_ll_a2(rapidjson::kObjectType);
                auto px_ll_c2 = px_ll_a2.GetObject();
                _Serialize(px_ll_e1, px_ll_c2);
                PUM::PushBack(px_ll_a1, px_ll_a2);
            }
        }
        PUM::PushBack(px_ll_a0, px_ll_a1);
    }
    PUM::Push(obj, "px_ll", px_ll_a0);
    PUM::Value shx_ll_a0(rapidjson::kArrayType);
    for(auto& shx_ll_e0 : p->shx_ll) {
        PUM::Value shx_ll_a1(rapidjson::kArrayType);
        for(auto& shx_ll_e1 : shx_ll_e0) {
            if (shx_ll_e1.get() == nullptr) {
                PUM::PushBackNull(shx_ll_a1);
            } else {
                PUM::Value shx_ll_a2(rapidjson::kObjectType);
                auto shx_ll_c2 = shx_ll_a2.GetObject();
                _Serialize(shx_ll_e1.get(), shx_ll_c2);
                PUM::PushBack(shx_ll_a1, shx_ll_a2);
            }
        }
        PUM::PushBack(shx_ll_a0, shx_ll_a1);
    }
    PUM::Push(obj, "shx_ll", shx_ll_a0);
    PUM::Value x_v_a0(rapidjson::kArrayType);
    for(size_t x_v_i0 = 0 ; x_v_i0 < p->x_v.size() ; x_v_i0++) {
        auto& x_v_e0 = p->x_v[x_v_i0];
        PUM::Value x_v_a1(rapidjson::kObjectType);
        auto x_v_c1 = x_v_a1.GetObject();
        _Serialize(&x_v_e0, x_v_c1);
        PUM::PushBack(x_v_a0, x_v_a1);
    }
    PUM::Push(obj, "x_v", x_v_a0);
    PUM::Value px_v_a0(rapidjson::kArrayType);
    for(size_t px_v_i0 = 0 ; px_v_i0 < p->px_v.size() ; px_v_i0++) {
        auto& px_v_e0 = p->px_v[px_v_i0];
        if (px_v_e0 == nullptr) {
            PUM::PushBackNull(px_v_a0);
        } else {
            PUM::Value px_v_a1(rapidjson::kObjectType);
            auto px_v_c1 = px_v_a1.GetObject();
            _Serialize(px_v_e0, px_v_c1);
            PUM::PushBack(px_v_a0, px_v_a1);
        }
    }
    PUM::Push(obj, "px_v", px_v_a0);
    PUM::Value shx_v_a0(rapidjson::kArrayType);
    for(size_t shx_v_i0 = 0 ; shx_v_i0 < p->shx_v.size() ; shx_v_i0++) {
        auto& shx_v_e0 = p->shx_v[shx_v_i0];
        if (shx_v_e0.get() == nullptr) {
            PUM::PushBackNull(shx_v_a0);
        } else {
            PUM::Value shx_v_a1(rapidjson::kObjectType);
            auto shx_v_c1 = shx_v_a1.GetObject();
            _Serialize(shx_v_e0.get(), shx_v_c1);
            PUM::PushBack(shx_v_a0, shx_v_a1);
        }
    }
    PUM::Push(obj, "shx_v", shx_v_a0);
    auto ix_m_c0 = PUM::AddObject(obj, "ix_m");
    for(auto& ix_m_e0 : p->ix_m) {
        auto ix_m_a0 = PUM::AddObject(ix_m_c0, PUM::ConvertToString(ix_m_e0.first).data());
        _Serialize(&(ix_m_e0.second), ix_m_a0);
    }
    auto ipx_m_c0 = PUM::AddObject(obj, "ipx_m");
    for(auto& ipx_m_e0 : p->ipx_m) {
        if ( ipx_m_e0.second == nullptr ) {
            PUM::PushNull(obj, PUM::ConvertToString(ipx_m_e0.first).data());
        } else {
            auto ipx_m_a0 = PUM::AddObject(ipx_m_c0, PUM::ConvertToString(ipx_m_e0.first).data());
            _Serialize(ipx_m_e0.second, ipx_m_a0);
        }
    }
    auto ishx_m_c0 = PUM::AddObject(obj, "ishx_m");
    for(auto& ishx_m_e0 : p->ishx_m) {
        if ( ishx_m_e0.second.get() == nullptr ) {
            PUM::PushNull(obj, PUM::ConvertToString(ishx_m_e0.first).data());
        } else {
            auto ishx_m_a0 = PUM::AddObject(ishx_m_c0, PUM::ConvertToString(ishx_m_e0.first).data());
            _Serialize(ishx_m_e0.second.get(), ishx_m_a0);
        }
    }
    auto strx_m_c0 = PUM::AddObject(obj, "strx_m");
    for(auto& strx_m_e0 : p->strx_m) {
        auto strx_m_a0 = PUM::AddObject(strx_m_c0, PUM::ConvertToString(strx_m_e0.first).data());
        _Serialize(&(strx_m_e0.second), strx_m_a0);
    }
    auto strpx_m_c0 = PUM::AddObject(obj, "strpx_m");
    for(auto& strpx_m_e0 : p->strpx_m) {
        if ( strpx_m_e0.second == nullptr ) {
            PUM::PushNull(obj, PUM::ConvertToString(strpx_m_e0.first).data());
        } else {
            auto strpx_m_a0 = PUM::AddObject(strpx_m_c0, PUM::ConvertToString(strpx_m_e0.first).data());
            _Serialize(strpx_m_e0.second, strpx_m_a0);
        }
    }
    auto strshx_m_c0 = PUM::AddObject(obj, "strshx_m");
    for(auto& strshx_m_e0 : p->strshx_m) {
        if ( strshx_m_e0.second.get() == nullptr ) {
            PUM::PushNull(obj, PUM::ConvertToString(strshx_m_e0.first).data());
        } else {
            auto strshx_m_a0 = PUM::AddObject(strshx_m_c0, PUM::ConvertToString(strshx_m_e0.first).data());
            _Serialize(strshx_m_e0.second.get(), strshx_m_a0);
        }
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsComplex::Y* p, const Jobj& obj)
{
    auto x_o0 = POM::FindObject(obj, "x");
    _Deserialize(&(p->x), x_o0);
    if (POM::IsExist(obj, "px") && !POM::IsNull(obj, "px" ) ) {
        if (p->px == nullptr) {
            p->px = new nsSimple::X();
        }
        auto px_o0 = POM::FindObject(obj, "px");
        _Deserialize(p->px, px_o0);
    }
    if (POM::IsExist(obj, "shx") && !POM::IsNull(obj, "shx" ) ) {
        if (p->shx.get() == nullptr) {
            p->shx.reset(new nsSimple::X());
        }
        auto shx_o0 = POM::FindObject(obj, "shx");
        _Deserialize(p->shx.get(), shx_o0);
    }
    auto x_l_a0 = POM::FindArray(obj, "x_l");
    for(auto& x_l_e0 : x_l_a0) {
        auto x_l_o1 = x_l_e0.GetObject();
        nsSimple::X x_l_c1;
        _Deserialize(&x_l_c1, x_l_o1);
        p->x_l.push_back(x_l_c1);
    }
    auto px_l_a0 = POM::FindArray(obj, "px_l");
    for(auto& px_l_e0 : px_l_a0) {
        if (!px_l_e0.IsNull()) {
            auto px_l_o1 = px_l_e0.GetObject();
            auto px_l_c1 = new nsSimple::X();
            _Deserialize(px_l_c1, px_l_o1);
            p->px_l.push_back(px_l_c1);
        }
    }
    auto shx_l_a0 = POM::FindArray(obj, "shx_l");
    for(auto& shx_l_e0 : shx_l_a0) {
        if (!shx_l_e0.IsNull()) {
            auto shx_l_o1 = shx_l_e0.GetObject();
            auto shx_l_c1 = std::shared_ptr<nsSimple::X>(new nsSimple::X());
            _Deserialize(shx_l_c1.get(), shx_l_o1);
            p->shx_l.push_back(shx_l_c1);
        }
    }
    auto x_ll_a0 = POM::FindArray(obj, "x_ll");
    for(auto& x_ll_e0 : x_ll_a0) {
        std::list<nsSimple::X> x_ll_c1;
        auto x_ll_a1 = x_ll_e0.GetArray();
        for(auto& x_ll_e1 : x_ll_a1) {
            auto x_ll_o2 = x_ll_e1.GetObject();
            nsSimple::X x_ll_c2;
            _Deserialize(&x_ll_c2, x_ll_o2);
            x_ll_c1.push_back(x_ll_c2);
        }
        p->x_ll.push_back(x_ll_c1);
    }
    auto px_ll_a0 = POM::FindArray(obj, "px_ll");
    for(auto& px_ll_e0 : px_ll_a0) {
        std::list<nsSimple::X*> px_ll_c1;
        auto px_ll_a1 = px_ll_e0.GetArray();
        for(auto& px_ll_e1 : px_ll_a1) {
            if (!px_ll_e1.IsNull()) {
                auto px_ll_o2 = px_ll_e1.GetObject();
                auto px_ll_c2 = new nsSimple::X();
                _Deserialize(px_ll_c2, px_ll_o2);
                px_ll_c1.push_back(px_ll_c2);
            }
        }
        p->px_ll.push_back(px_ll_c1);
    }
    auto shx_ll_a0 = POM::FindArray(obj, "shx_ll");
    for(auto& shx_ll_e0 : shx_ll_a0) {
        std::list<std::shared_ptr<nsSimple::X>> shx_ll_c1;
        auto shx_ll_a1 = shx_ll_e0.GetArray();
        for(auto& shx_ll_e1 : shx_ll_a1) {
            if (!shx_ll_e1.IsNull()) {
                auto shx_ll_o2 = shx_ll_e1.GetObject();
                auto shx_ll_c2 = std::shared_ptr<nsSimple::X>(new nsSimple::X());
                _Deserialize(shx_ll_c2.get(), shx_ll_o2);
                shx_ll_c1.push_back(shx_ll_c2);
            }
        }
        p->shx_ll.push_back(shx_ll_c1);
    }
    auto x_v_a0 = POM::FindArray(obj, "x_v");
    for(auto& x_v_e0 : x_v_a0) {
        auto x_v_o1 = x_v_e0.GetObject();
        nsSimple::X x_v_c1;
        _Deserialize(&x_v_c1, x_v_o1);
        p->x_v.push_back(x_v_c1);
    }
    auto px_v_a0 = POM::FindArray(obj, "px_v");
    for(auto& px_v_e0 : px_v_a0) {
        if (!px_v_e0.IsNull()) {
            auto px_v_o1 = px_v_e0.GetObject();
            auto px_v_c1 = new nsSimple::X();
            _Deserialize(px_v_c1, px_v_o1);
            p->px_v.push_back(px_v_c1);
        }
    }
    auto shx_v_a0 = POM::FindArray(obj, "shx_v");
    for(auto& shx_v_e0 : shx_v_a0) {
        if (!shx_v_e0.IsNull()) {
            auto shx_v_o1 = shx_v_e0.GetObject();
            auto shx_v_c1 = std::shared_ptr<nsSimple::X>(new nsSimple::X());
            _Deserialize(shx_v_c1.get(), shx_v_o1);
            p->shx_v.push_back(shx_v_c1);
        }
    }
    auto ix_m_a0 = POM::FindObject(obj, "ix_m");
    for(auto& ix_m_e0 : ix_m_a0) {
        auto ix_m_o1 = ix_m_e0.value.GetObject();
        nsSimple::X ix_m_c1;
        _Deserialize(&ix_m_c1, ix_m_o1);
        p->ix_m.insert({ std::stod(ix_m_e0.name.GetString()), ix_m_c1 });
    }
    auto ipx_m_a0 = POM::FindObject(obj, "ipx_m");
    for(auto& ipx_m_e0 : ipx_m_a0) {
        if (!ipx_m_e0.value.IsNull() ) {
            auto ipx_m_o1 = ipx_m_e0.value.GetObject();
            auto ipx_m_c1 = new nsSimple::X();
            _Deserialize(ipx_m_c1, ipx_m_o1);
            p->ipx_m.insert({ std::stod(ipx_m_e0.name.GetString()), ipx_m_c1 });
        }
    }
    auto ishx_m_a0 = POM::FindObject(obj, "ishx_m");
    for(auto& ishx_m_e0 : ishx_m_a0) {
        if (!ishx_m_e0.value.IsNull() ) {
            auto ishx_m_o1 = ishx_m_e0.value.GetObject();
            auto ishx_m_c1 = std::shared_ptr<nsSimple::X>(new nsSimple::X());
            _Deserialize(ishx_m_c1.get(), ishx_m_o1);
            p->ishx_m.insert({ std::stod(ishx_m_e0.name.GetString()), ishx_m_c1 });
        }
    }
    auto strx_m_a0 = POM::FindObject(obj, "strx_m");
    for(auto& strx_m_e0 : strx_m_a0) {
        auto strx_m_o1 = strx_m_e0.value.GetObject();
        nsSimple::X strx_m_c1;
        _Deserialize(&strx_m_c1, strx_m_o1);
        p->strx_m.insert({ strx_m_e0.name.GetString(), strx_m_c1 });
    }
    auto strpx_m_a0 = POM::FindObject(obj, "strpx_m");
    for(auto& strpx_m_e0 : strpx_m_a0) {
        if (!strpx_m_e0.value.IsNull() ) {
            auto strpx_m_o1 = strpx_m_e0.value.GetObject();
            auto strpx_m_c1 = new nsSimple::X();
            _Deserialize(strpx_m_c1, strpx_m_o1);
            p->strpx_m.insert({ strpx_m_e0.name.GetString(), strpx_m_c1 });
        }
    }
    auto strshx_m_a0 = POM::FindObject(obj, "strshx_m");
    for(auto& strshx_m_e0 : strshx_m_a0) {
        if (!strshx_m_e0.value.IsNull() ) {
            auto strshx_m_o1 = strshx_m_e0.value.GetObject();
            auto strshx_m_c1 = std::shared_ptr<nsSimple::X>(new nsSimple::X());
            _Deserialize(strshx_m_c1.get(), strshx_m_o1);
            p->strshx_m.insert({ strshx_m_e0.name.GetString(), strshx_m_c1 });
        }
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsFarType::X* p, Jobj& obj)
{
    PUM::Value stf_l_a0(rapidjson::kArrayType);
    for(auto& stf_l_e0 : p->stf_l) {
    }
    PUM::Push(obj, "stf_l", stf_l_a0);
    auto stf_m_c0 = PUM::AddObject(obj, "stf_m");
    for(auto& stf_m_e0 : p->stf_m) {
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsFarType::X* p, const Jobj& obj)
{
    auto stf_l_a0 = POM::FindArray(obj, "stf_l");
    for(auto& stf_l_e0 : stf_l_a0) {
    }
    auto stf_m_a0 = POM::FindObject(obj, "stf_m");
    for(auto& stf_m_e0 : stf_m_a0) {
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsInOut::A* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsInOut::A* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsInOut::B* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    auto a_o = PUM::AddObject(obj, "a");
    _Serialize(&(p->a), a_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsInOut::B* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    auto a_o0 = POM::FindObject(obj, "a");
    _Deserialize(&(p->a), a_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimple::X* p, Jobj& obj)
{
    PUM::Push(obj, "b", p->b);
    PUM::Push(obj, "c", p->c);
    PUM::Push(obj, "uc", p->uc);
    PUM::Push(obj, "s", p->s);
    PUM::Push(obj, "us", p->us);
    PUM::Push(obj, "i", p->i);
    PUM::Push(obj, "ui", p->ui);
    PUM::Push(obj, "l", p->l);
    PUM::Push(obj, "ul", p->ul);
    PUM::Push(obj, "ll", p->ll);
    PUM::Push(obj, "ull", p->ull);
    PUM::Push(obj, "f", p->f);
    PUM::Push(obj, "d", p->d);
    PUM::Push(obj, "i8", p->i8);
    PUM::Push(obj, "ui8", p->ui8);
    PUM::Push(obj, "i16", p->i16);
    PUM::Push(obj, "ui16", p->ui16);
    PUM::Push(obj, "i32", p->i32);
    PUM::Push(obj, "ui32", p->ui32);
    PUM::Push(obj, "i64", p->i64);
    PUM::Push(obj, "ui64", p->ui64);
    PUM::Push(obj, "str", p->str);
    PUM::Value b_l_a0(rapidjson::kArrayType);
    for(auto& b_l_e0 : p->b_l) {
        PUM::PushBack(b_l_a0, b_l_e0);
    }
    PUM::Push(obj, "b_l", b_l_a0);
    PUM::Value i_l_a0(rapidjson::kArrayType);
    for(auto& i_l_e0 : p->i_l) {
        PUM::PushBack(i_l_a0, i_l_e0);
    }
    PUM::Push(obj, "i_l", i_l_a0);
    PUM::Value d_l_a0(rapidjson::kArrayType);
    for(auto& d_l_e0 : p->d_l) {
        PUM::PushBack(d_l_a0, d_l_e0);
    }
    PUM::Push(obj, "d_l", d_l_a0);
    PUM::Value str_l_a0(rapidjson::kArrayType);
    for(auto& str_l_e0 : p->str_l) {
        PUM::PushBack(str_l_a0, str_l_e0);
    }
    PUM::Push(obj, "str_l", str_l_a0);
    PUM::Value b_vl_a0(rapidjson::kArrayType);
    for(auto& b_vl_e0 : p->b_vl) {
        PUM::Value b_vl_a1(rapidjson::kArrayType);
        for(size_t b_vl_i1 = 0 ; b_vl_i1 < b_vl_e0.size() ; b_vl_i1++) {
            bool b_vl_e1 = b_vl_e0[b_vl_i1];
            PUM::PushBack(b_vl_a1, b_vl_e1);
        }
        PUM::PushBack(b_vl_a0, b_vl_a1);
    }
    PUM::Push(obj, "b_vl", b_vl_a0);
    PUM::Value i_vl_a0(rapidjson::kArrayType);
    for(auto& i_vl_e0 : p->i_vl) {
        PUM::Value i_vl_a1(rapidjson::kArrayType);
        for(size_t i_vl_i1 = 0 ; i_vl_i1 < i_vl_e0.size() ; i_vl_i1++) {
            auto& i_vl_e1 = i_vl_e0[i_vl_i1];
            PUM::PushBack(i_vl_a1, i_vl_e1);
        }
        PUM::PushBack(i_vl_a0, i_vl_a1);
    }
    PUM::Push(obj, "i_vl", i_vl_a0);
    PUM::Value d_vl_a0(rapidjson::kArrayType);
    for(auto& d_vl_e0 : p->d_vl) {
        PUM::Value d_vl_a1(rapidjson::kArrayType);
        for(size_t d_vl_i1 = 0 ; d_vl_i1 < d_vl_e0.size() ; d_vl_i1++) {
            auto& d_vl_e1 = d_vl_e0[d_vl_i1];
            PUM::PushBack(d_vl_a1, d_vl_e1);
        }
        PUM::PushBack(d_vl_a0, d_vl_a1);
    }
    PUM::Push(obj, "d_vl", d_vl_a0);
    PUM::Value str_vl_a0(rapidjson::kArrayType);
    for(auto& str_vl_e0 : p->str_vl) {
        PUM::Value str_vl_a1(rapidjson::kArrayType);
        for(size_t str_vl_i1 = 0 ; str_vl_i1 < str_vl_e0.size() ; str_vl_i1++) {
            auto& str_vl_e1 = str_vl_e0[str_vl_i1];
            PUM::PushBack(str_vl_a1, str_vl_e1);
        }
        PUM::PushBack(str_vl_a0, str_vl_a1);
    }
    PUM::Push(obj, "str_vl", str_vl_a0);
    PUM::Value b_ll_a0(rapidjson::kArrayType);
    for(auto& b_ll_e0 : p->b_ll) {
        PUM::Value b_ll_a1(rapidjson::kArrayType);
        for(auto& b_ll_e1 : b_ll_e0) {
            PUM::PushBack(b_ll_a1, b_ll_e1);
        }
        PUM::PushBack(b_ll_a0, b_ll_a1);
    }
    PUM::Push(obj, "b_ll", b_ll_a0);
    PUM::Value i_ll_a0(rapidjson::kArrayType);
    for(auto& i_ll_e0 : p->i_ll) {
        PUM::Value i_ll_a1(rapidjson::kArrayType);
        for(auto& i_ll_e1 : i_ll_e0) {
            PUM::PushBack(i_ll_a1, i_ll_e1);
        }
        PUM::PushBack(i_ll_a0, i_ll_a1);
    }
    PUM::Push(obj, "i_ll", i_ll_a0);
    PUM::Value d_ll_a0(rapidjson::kArrayType);
    for(auto& d_ll_e0 : p->d_ll) {
        PUM::Value d_ll_a1(rapidjson::kArrayType);
        for(auto& d_ll_e1 : d_ll_e0) {
            PUM::PushBack(d_ll_a1, d_ll_e1);
        }
        PUM::PushBack(d_ll_a0, d_ll_a1);
    }
    PUM::Push(obj, "d_ll", d_ll_a0);
    PUM::Value str_ll_a0(rapidjson::kArrayType);
    for(auto& str_ll_e0 : p->str_ll) {
        PUM::Value str_ll_a1(rapidjson::kArrayType);
        for(auto& str_ll_e1 : str_ll_e0) {
            PUM::PushBack(str_ll_a1, str_ll_e1);
        }
        PUM::PushBack(str_ll_a0, str_ll_a1);
    }
    PUM::Push(obj, "str_ll", str_ll_a0);
    PUM::Value b_v_a0(rapidjson::kArrayType);
    for(size_t b_v_i0 = 0 ; b_v_i0 < p->b_v.size() ; b_v_i0++) {
        bool b_v_e0 = p->b_v[b_v_i0];
        PUM::PushBack(b_v_a0, b_v_e0);
    }
    PUM::Push(obj, "b_v", b_v_a0);
    PUM::Value i_v_a0(rapidjson::kArrayType);
    for(size_t i_v_i0 = 0 ; i_v_i0 < p->i_v.size() ; i_v_i0++) {
        auto& i_v_e0 = p->i_v[i_v_i0];
        PUM::PushBack(i_v_a0, i_v_e0);
    }
    PUM::Push(obj, "i_v", i_v_a0);
    PUM::Value d_v_a0(rapidjson::kArrayType);
    for(size_t d_v_i0 = 0 ; d_v_i0 < p->d_v.size() ; d_v_i0++) {
        auto& d_v_e0 = p->d_v[d_v_i0];
        PUM::PushBack(d_v_a0, d_v_e0);
    }
    PUM::Push(obj, "d_v", d_v_a0);
    PUM::Value str_v_a0(rapidjson::kArrayType);
    for(size_t str_v_i0 = 0 ; str_v_i0 < p->str_v.size() ; str_v_i0++) {
        auto& str_v_e0 = p->str_v[str_v_i0];
        PUM::PushBack(str_v_a0, str_v_e0);
    }
    PUM::Push(obj, "str_v", str_v_a0);
    PUM::Value b_vv_a0(rapidjson::kArrayType);
    for(size_t b_vv_i0 = 0 ; b_vv_i0 < p->b_vv.size() ; b_vv_i0++) {
        auto& b_vv_e0 = p->b_vv[b_vv_i0];
        PUM::Value b_vv_a1(rapidjson::kArrayType);
        for(size_t b_vv_i1 = 0 ; b_vv_i1 < b_vv_e0.size() ; b_vv_i1++) {
            bool b_vv_e1 = b_vv_e0[b_vv_i1];
            PUM::PushBack(b_vv_a1, b_vv_e1);
        }
        PUM::PushBack(b_vv_a0, b_vv_a1);
    }
    PUM::Push(obj, "b_vv", b_vv_a0);
    PUM::Value i_vv_a0(rapidjson::kArrayType);
    for(size_t i_vv_i0 = 0 ; i_vv_i0 < p->i_vv.size() ; i_vv_i0++) {
        auto& i_vv_e0 = p->i_vv[i_vv_i0];
        PUM::Value i_vv_a1(rapidjson::kArrayType);
        for(size_t i_vv_i1 = 0 ; i_vv_i1 < i_vv_e0.size() ; i_vv_i1++) {
            auto& i_vv_e1 = i_vv_e0[i_vv_i1];
            PUM::PushBack(i_vv_a1, i_vv_e1);
        }
        PUM::PushBack(i_vv_a0, i_vv_a1);
    }
    PUM::Push(obj, "i_vv", i_vv_a0);
    PUM::Value d_vv_a0(rapidjson::kArrayType);
    for(size_t d_vv_i0 = 0 ; d_vv_i0 < p->d_vv.size() ; d_vv_i0++) {
        auto& d_vv_e0 = p->d_vv[d_vv_i0];
        PUM::Value d_vv_a1(rapidjson::kArrayType);
        for(size_t d_vv_i1 = 0 ; d_vv_i1 < d_vv_e0.size() ; d_vv_i1++) {
            auto& d_vv_e1 = d_vv_e0[d_vv_i1];
            PUM::PushBack(d_vv_a1, d_vv_e1);
        }
        PUM::PushBack(d_vv_a0, d_vv_a1);
    }
    PUM::Push(obj, "d_vv", d_vv_a0);
    PUM::Value str_vv_a0(rapidjson::kArrayType);
    for(size_t str_vv_i0 = 0 ; str_vv_i0 < p->str_vv.size() ; str_vv_i0++) {
        auto& str_vv_e0 = p->str_vv[str_vv_i0];
        PUM::Value str_vv_a1(rapidjson::kArrayType);
        for(size_t str_vv_i1 = 0 ; str_vv_i1 < str_vv_e0.size() ; str_vv_i1++) {
            auto& str_vv_e1 = str_vv_e0[str_vv_i1];
            PUM::PushBack(str_vv_a1, str_vv_e1);
        }
        PUM::PushBack(str_vv_a0, str_vv_a1);
    }
    PUM::Push(obj, "str_vv", str_vv_a0);
    PUM::Value b_lv_a0(rapidjson::kArrayType);
    for(size_t b_lv_i0 = 0 ; b_lv_i0 < p->b_lv.size() ; b_lv_i0++) {
        auto& b_lv_e0 = p->b_lv[b_lv_i0];
        PUM::Value b_lv_a1(rapidjson::kArrayType);
        for(auto& b_lv_e1 : b_lv_e0) {
            PUM::PushBack(b_lv_a1, b_lv_e1);
        }
        PUM::PushBack(b_lv_a0, b_lv_a1);
    }
    PUM::Push(obj, "b_lv", b_lv_a0);
    PUM::Value i_lv_a0(rapidjson::kArrayType);
    for(size_t i_lv_i0 = 0 ; i_lv_i0 < p->i_lv.size() ; i_lv_i0++) {
        auto& i_lv_e0 = p->i_lv[i_lv_i0];
        PUM::Value i_lv_a1(rapidjson::kArrayType);
        for(auto& i_lv_e1 : i_lv_e0) {
            PUM::PushBack(i_lv_a1, i_lv_e1);
        }
        PUM::PushBack(i_lv_a0, i_lv_a1);
    }
    PUM::Push(obj, "i_lv", i_lv_a0);
    PUM::Value d_lv_a0(rapidjson::kArrayType);
    for(size_t d_lv_i0 = 0 ; d_lv_i0 < p->d_lv.size() ; d_lv_i0++) {
        auto& d_lv_e0 = p->d_lv[d_lv_i0];
        PUM::Value d_lv_a1(rapidjson::kArrayType);
        for(auto& d_lv_e1 : d_lv_e0) {
            PUM::PushBack(d_lv_a1, d_lv_e1);
        }
        PUM::PushBack(d_lv_a0, d_lv_a1);
    }
    PUM::Push(obj, "d_lv", d_lv_a0);
    PUM::Value str_lv_a0(rapidjson::kArrayType);
    for(size_t str_lv_i0 = 0 ; str_lv_i0 < p->str_lv.size() ; str_lv_i0++) {
        auto& str_lv_e0 = p->str_lv[str_lv_i0];
        PUM::Value str_lv_a1(rapidjson::kArrayType);
        for(auto& str_lv_e1 : str_lv_e0) {
            PUM::PushBack(str_lv_a1, str_lv_e1);
        }
        PUM::PushBack(str_lv_a0, str_lv_a1);
    }
    PUM::Push(obj, "str_lv", str_lv_a0);
    PUM::Value i_s_a0(rapidjson::kArrayType);
    for(auto& i_s_e0 : p->i_s) {
        PUM::PushBack(i_s_a0, i_s_e0);
    }
    PUM::Push(obj, "i_s", i_s_a0);
    PUM::Value str_s_a0(rapidjson::kArrayType);
    for(auto& str_s_e0 : p->str_s) {
        PUM::PushBack(str_s_a0, str_s_e0);
    }
    PUM::Push(obj, "str_s", str_s_a0);
    auto ib_m_c0 = PUM::AddObject(obj, "ib_m");
    for(auto& ib_m_e0 : p->ib_m) {
        PUM::Push(ib_m_c0, PUM::ConvertToString(ib_m_e0.first).data(), ib_m_e0.second);
    }
    auto ii_m_c0 = PUM::AddObject(obj, "ii_m");
    for(auto& ii_m_e0 : p->ii_m) {
        PUM::Push(ii_m_c0, PUM::ConvertToString(ii_m_e0.first).data(), ii_m_e0.second);
    }
    auto id_m_c0 = PUM::AddObject(obj, "id_m");
    for(auto& id_m_e0 : p->id_m) {
        PUM::Push(id_m_c0, PUM::ConvertToString(id_m_e0.first).data(), id_m_e0.second);
    }
    auto istr_m_c0 = PUM::AddObject(obj, "istr_m");
    for(auto& istr_m_e0 : p->istr_m) {
        PUM::Push(istr_m_c0, PUM::ConvertToString(istr_m_e0.first).data(), istr_m_e0.second);
    }
    auto i_bl_m_c0 = PUM::AddObject(obj, "i_bl_m");
    for(auto& i_bl_m_e0 : p->i_bl_m) {
        PUM::Value i_bl_m_a1(rapidjson::kArrayType);
        for(auto& i_bl_m_e1 : i_bl_m_e0.second) {
            PUM::PushBack(i_bl_m_a1, i_bl_m_e1);
        }
        PUM::Push(i_bl_m_c0, PUM::ConvertToString(i_bl_m_e0.first).data(), i_bl_m_a1);
    }
    auto i_il_m_c0 = PUM::AddObject(obj, "i_il_m");
    for(auto& i_il_m_e0 : p->i_il_m) {
        PUM::Value i_il_m_a1(rapidjson::kArrayType);
        for(auto& i_il_m_e1 : i_il_m_e0.second) {
            PUM::PushBack(i_il_m_a1, i_il_m_e1);
        }
        PUM::Push(i_il_m_c0, PUM::ConvertToString(i_il_m_e0.first).data(), i_il_m_a1);
    }
    auto i_dl_m_c0 = PUM::AddObject(obj, "i_dl_m");
    for(auto& i_dl_m_e0 : p->i_dl_m) {
        PUM::Value i_dl_m_a1(rapidjson::kArrayType);
        for(auto& i_dl_m_e1 : i_dl_m_e0.second) {
            PUM::PushBack(i_dl_m_a1, i_dl_m_e1);
        }
        PUM::Push(i_dl_m_c0, PUM::ConvertToString(i_dl_m_e0.first).data(), i_dl_m_a1);
    }
    auto i_strl_m_c0 = PUM::AddObject(obj, "i_strl_m");
    for(auto& i_strl_m_e0 : p->i_strl_m) {
        PUM::Value i_strl_m_a1(rapidjson::kArrayType);
        for(auto& i_strl_m_e1 : i_strl_m_e0.second) {
            PUM::PushBack(i_strl_m_a1, i_strl_m_e1);
        }
        PUM::Push(i_strl_m_c0, PUM::ConvertToString(i_strl_m_e0.first).data(), i_strl_m_a1);
    }
    auto i_bv_m_c0 = PUM::AddObject(obj, "i_bv_m");
    for(auto& i_bv_m_e0 : p->i_bv_m) {
        PUM::Value i_bv_m_a1(rapidjson::kArrayType);
        for(size_t i_bv_m_i1 = 0 ; i_bv_m_i1 < i_bv_m_e0.second.size() ; i_bv_m_i1++) {
            bool i_bv_m_e1 = i_bv_m_e0.second[i_bv_m_i1];
            PUM::PushBack(i_bv_m_a1, i_bv_m_e1);
        }
        PUM::Push(i_bv_m_c0, PUM::ConvertToString(i_bv_m_e0.first).data(), i_bv_m_a1);
    }
    auto i_iv_m_c0 = PUM::AddObject(obj, "i_iv_m");
    for(auto& i_iv_m_e0 : p->i_iv_m) {
        PUM::Value i_iv_m_a1(rapidjson::kArrayType);
        for(size_t i_iv_m_i1 = 0 ; i_iv_m_i1 < i_iv_m_e0.second.size() ; i_iv_m_i1++) {
            auto& i_iv_m_e1 = i_iv_m_e0.second[i_iv_m_i1];
            PUM::PushBack(i_iv_m_a1, i_iv_m_e1);
        }
        PUM::Push(i_iv_m_c0, PUM::ConvertToString(i_iv_m_e0.first).data(), i_iv_m_a1);
    }
    auto i_dv_m_c0 = PUM::AddObject(obj, "i_dv_m");
    for(auto& i_dv_m_e0 : p->i_dv_m) {
        PUM::Value i_dv_m_a1(rapidjson::kArrayType);
        for(size_t i_dv_m_i1 = 0 ; i_dv_m_i1 < i_dv_m_e0.second.size() ; i_dv_m_i1++) {
            auto& i_dv_m_e1 = i_dv_m_e0.second[i_dv_m_i1];
            PUM::PushBack(i_dv_m_a1, i_dv_m_e1);
        }
        PUM::Push(i_dv_m_c0, PUM::ConvertToString(i_dv_m_e0.first).data(), i_dv_m_a1);
    }
    auto i_strv_m_c0 = PUM::AddObject(obj, "i_strv_m");
    for(auto& i_strv_m_e0 : p->i_strv_m) {
        PUM::Value i_strv_m_a1(rapidjson::kArrayType);
        for(size_t i_strv_m_i1 = 0 ; i_strv_m_i1 < i_strv_m_e0.second.size() ; i_strv_m_i1++) {
            auto& i_strv_m_e1 = i_strv_m_e0.second[i_strv_m_i1];
            PUM::PushBack(i_strv_m_a1, i_strv_m_e1);
        }
        PUM::Push(i_strv_m_c0, PUM::ConvertToString(i_strv_m_e0.first).data(), i_strv_m_a1);
    }
    auto i_is_m_c0 = PUM::AddObject(obj, "i_is_m");
    for(auto& i_is_m_e0 : p->i_is_m) {
        PUM::Value i_is_m_a1(rapidjson::kArrayType);
        for(auto& i_is_m_e1 : i_is_m_e0.second) {
            PUM::PushBack(i_is_m_a1, i_is_m_e1);
        }
        PUM::Push(i_is_m_c0, PUM::ConvertToString(i_is_m_e0.first).data(), i_is_m_a1);
    }
    auto i_strs_m_c0 = PUM::AddObject(obj, "i_strs_m");
    for(auto& i_strs_m_e0 : p->i_strs_m) {
        PUM::Value i_strs_m_a1(rapidjson::kArrayType);
        for(auto& i_strs_m_e1 : i_strs_m_e0.second) {
            PUM::PushBack(i_strs_m_a1, i_strs_m_e1);
        }
        PUM::Push(i_strs_m_c0, PUM::ConvertToString(i_strs_m_e0.first).data(), i_strs_m_a1);
    }
    auto i_ibm_m_c0 = PUM::AddObject(obj, "i_ibm_m");
    for(auto& i_ibm_m_e0 : p->i_ibm_m) {
        auto i_ibm_m_c1 = PUM::AddObject(i_ibm_m_c0, PUM::ConvertToString(i_ibm_m_e0.first).data());
        for(auto& i_ibm_m_e1 : i_ibm_m_e0.second) {
            PUM::Push(i_ibm_m_c1, PUM::ConvertToString(i_ibm_m_e1.first).data(), i_ibm_m_e1.second);
        }
    }
    auto i_iim_m_c0 = PUM::AddObject(obj, "i_iim_m");
    for(auto& i_iim_m_e0 : p->i_iim_m) {
        auto i_iim_m_c1 = PUM::AddObject(i_iim_m_c0, PUM::ConvertToString(i_iim_m_e0.first).data());
        for(auto& i_iim_m_e1 : i_iim_m_e0.second) {
            PUM::Push(i_iim_m_c1, PUM::ConvertToString(i_iim_m_e1.first).data(), i_iim_m_e1.second);
        }
    }
    auto i_idm_m_c0 = PUM::AddObject(obj, "i_idm_m");
    for(auto& i_idm_m_e0 : p->i_idm_m) {
        auto i_idm_m_c1 = PUM::AddObject(i_idm_m_c0, PUM::ConvertToString(i_idm_m_e0.first).data());
        for(auto& i_idm_m_e1 : i_idm_m_e0.second) {
            PUM::Push(i_idm_m_c1, PUM::ConvertToString(i_idm_m_e1.first).data(), i_idm_m_e1.second);
        }
    }
    auto i_istrm_m_c0 = PUM::AddObject(obj, "i_istrm_m");
    for(auto& i_istrm_m_e0 : p->i_istrm_m) {
        auto i_istrm_m_c1 = PUM::AddObject(i_istrm_m_c0, PUM::ConvertToString(i_istrm_m_e0.first).data());
        for(auto& i_istrm_m_e1 : i_istrm_m_e0.second) {
            PUM::Push(i_istrm_m_c1, PUM::ConvertToString(i_istrm_m_e1.first).data(), i_istrm_m_e1.second);
        }
    }
    auto i_strbm_m_c0 = PUM::AddObject(obj, "i_strbm_m");
    for(auto& i_strbm_m_e0 : p->i_strbm_m) {
        auto i_strbm_m_c1 = PUM::AddObject(i_strbm_m_c0, PUM::ConvertToString(i_strbm_m_e0.first).data());
        for(auto& i_strbm_m_e1 : i_strbm_m_e0.second) {
            PUM::Push(i_strbm_m_c1, PUM::ConvertToString(i_strbm_m_e1.first).data(), i_strbm_m_e1.second);
        }
    }
    auto i_strim_m_c0 = PUM::AddObject(obj, "i_strim_m");
    for(auto& i_strim_m_e0 : p->i_strim_m) {
        auto i_strim_m_c1 = PUM::AddObject(i_strim_m_c0, PUM::ConvertToString(i_strim_m_e0.first).data());
        for(auto& i_strim_m_e1 : i_strim_m_e0.second) {
            PUM::Push(i_strim_m_c1, PUM::ConvertToString(i_strim_m_e1.first).data(), i_strim_m_e1.second);
        }
    }
    auto i_strdm_m_c0 = PUM::AddObject(obj, "i_strdm_m");
    for(auto& i_strdm_m_e0 : p->i_strdm_m) {
        auto i_strdm_m_c1 = PUM::AddObject(i_strdm_m_c0, PUM::ConvertToString(i_strdm_m_e0.first).data());
        for(auto& i_strdm_m_e1 : i_strdm_m_e0.second) {
            PUM::Push(i_strdm_m_c1, PUM::ConvertToString(i_strdm_m_e1.first).data(), i_strdm_m_e1.second);
        }
    }
    auto i_strstrm_m_c0 = PUM::AddObject(obj, "i_strstrm_m");
    for(auto& i_strstrm_m_e0 : p->i_strstrm_m) {
        auto i_strstrm_m_c1 = PUM::AddObject(i_strstrm_m_c0, PUM::ConvertToString(i_strstrm_m_e0.first).data());
        for(auto& i_strstrm_m_e1 : i_strstrm_m_e0.second) {
            PUM::Push(i_strstrm_m_c1, PUM::ConvertToString(i_strstrm_m_e1.first).data(), i_strstrm_m_e1.second);
        }
    }
    auto strb_m_c0 = PUM::AddObject(obj, "strb_m");
    for(auto& strb_m_e0 : p->strb_m) {
        PUM::Push(strb_m_c0, PUM::ConvertToString(strb_m_e0.first).data(), strb_m_e0.second);
    }
    auto stri_m_c0 = PUM::AddObject(obj, "stri_m");
    for(auto& stri_m_e0 : p->stri_m) {
        PUM::Push(stri_m_c0, PUM::ConvertToString(stri_m_e0.first).data(), stri_m_e0.second);
    }
    auto strd_m_c0 = PUM::AddObject(obj, "strd_m");
    for(auto& strd_m_e0 : p->strd_m) {
        PUM::Push(strd_m_c0, PUM::ConvertToString(strd_m_e0.first).data(), strd_m_e0.second);
    }
    auto strstr_m_c0 = PUM::AddObject(obj, "strstr_m");
    for(auto& strstr_m_e0 : p->strstr_m) {
        PUM::Push(strstr_m_c0, PUM::ConvertToString(strstr_m_e0.first).data(), strstr_m_e0.second);
    }
    auto str_bv_m_c0 = PUM::AddObject(obj, "str_bv_m");
    for(auto& str_bv_m_e0 : p->str_bv_m) {
        PUM::Value str_bv_m_a1(rapidjson::kArrayType);
        for(size_t str_bv_m_i1 = 0 ; str_bv_m_i1 < str_bv_m_e0.second.size() ; str_bv_m_i1++) {
            bool str_bv_m_e1 = str_bv_m_e0.second[str_bv_m_i1];
            PUM::PushBack(str_bv_m_a1, str_bv_m_e1);
        }
        PUM::Push(str_bv_m_c0, PUM::ConvertToString(str_bv_m_e0.first).data(), str_bv_m_a1);
    }
    auto str_iv_m_c0 = PUM::AddObject(obj, "str_iv_m");
    for(auto& str_iv_m_e0 : p->str_iv_m) {
        PUM::Value str_iv_m_a1(rapidjson::kArrayType);
        for(size_t str_iv_m_i1 = 0 ; str_iv_m_i1 < str_iv_m_e0.second.size() ; str_iv_m_i1++) {
            auto& str_iv_m_e1 = str_iv_m_e0.second[str_iv_m_i1];
            PUM::PushBack(str_iv_m_a1, str_iv_m_e1);
        }
        PUM::Push(str_iv_m_c0, PUM::ConvertToString(str_iv_m_e0.first).data(), str_iv_m_a1);
    }
    auto str_dv_m_c0 = PUM::AddObject(obj, "str_dv_m");
    for(auto& str_dv_m_e0 : p->str_dv_m) {
        PUM::Value str_dv_m_a1(rapidjson::kArrayType);
        for(size_t str_dv_m_i1 = 0 ; str_dv_m_i1 < str_dv_m_e0.second.size() ; str_dv_m_i1++) {
            auto& str_dv_m_e1 = str_dv_m_e0.second[str_dv_m_i1];
            PUM::PushBack(str_dv_m_a1, str_dv_m_e1);
        }
        PUM::Push(str_dv_m_c0, PUM::ConvertToString(str_dv_m_e0.first).data(), str_dv_m_a1);
    }
    auto str_strv_m_c0 = PUM::AddObject(obj, "str_strv_m");
    for(auto& str_strv_m_e0 : p->str_strv_m) {
        PUM::Value str_strv_m_a1(rapidjson::kArrayType);
        for(size_t str_strv_m_i1 = 0 ; str_strv_m_i1 < str_strv_m_e0.second.size() ; str_strv_m_i1++) {
            auto& str_strv_m_e1 = str_strv_m_e0.second[str_strv_m_i1];
            PUM::PushBack(str_strv_m_a1, str_strv_m_e1);
        }
        PUM::Push(str_strv_m_c0, PUM::ConvertToString(str_strv_m_e0.first).data(), str_strv_m_a1);
    }
    auto str_bl_m_c0 = PUM::AddObject(obj, "str_bl_m");
    for(auto& str_bl_m_e0 : p->str_bl_m) {
        PUM::Value str_bl_m_a1(rapidjson::kArrayType);
        for(auto& str_bl_m_e1 : str_bl_m_e0.second) {
            PUM::PushBack(str_bl_m_a1, str_bl_m_e1);
        }
        PUM::Push(str_bl_m_c0, PUM::ConvertToString(str_bl_m_e0.first).data(), str_bl_m_a1);
    }
    auto str_il_m_c0 = PUM::AddObject(obj, "str_il_m");
    for(auto& str_il_m_e0 : p->str_il_m) {
        PUM::Value str_il_m_a1(rapidjson::kArrayType);
        for(auto& str_il_m_e1 : str_il_m_e0.second) {
            PUM::PushBack(str_il_m_a1, str_il_m_e1);
        }
        PUM::Push(str_il_m_c0, PUM::ConvertToString(str_il_m_e0.first).data(), str_il_m_a1);
    }
    auto str_dl_m_c0 = PUM::AddObject(obj, "str_dl_m");
    for(auto& str_dl_m_e0 : p->str_dl_m) {
        PUM::Value str_dl_m_a1(rapidjson::kArrayType);
        for(auto& str_dl_m_e1 : str_dl_m_e0.second) {
            PUM::PushBack(str_dl_m_a1, str_dl_m_e1);
        }
        PUM::Push(str_dl_m_c0, PUM::ConvertToString(str_dl_m_e0.first).data(), str_dl_m_a1);
    }
    auto str_strl_m_c0 = PUM::AddObject(obj, "str_strl_m");
    for(auto& str_strl_m_e0 : p->str_strl_m) {
        PUM::Value str_strl_m_a1(rapidjson::kArrayType);
        for(auto& str_strl_m_e1 : str_strl_m_e0.second) {
            PUM::PushBack(str_strl_m_a1, str_strl_m_e1);
        }
        PUM::Push(str_strl_m_c0, PUM::ConvertToString(str_strl_m_e0.first).data(), str_strl_m_a1);
    }
    auto str_is_m_c0 = PUM::AddObject(obj, "str_is_m");
    for(auto& str_is_m_e0 : p->str_is_m) {
        PUM::Value str_is_m_a1(rapidjson::kArrayType);
        for(auto& str_is_m_e1 : str_is_m_e0.second) {
            PUM::PushBack(str_is_m_a1, str_is_m_e1);
        }
        PUM::Push(str_is_m_c0, PUM::ConvertToString(str_is_m_e0.first).data(), str_is_m_a1);
    }
    auto str_strs_m_c0 = PUM::AddObject(obj, "str_strs_m");
    for(auto& str_strs_m_e0 : p->str_strs_m) {
        PUM::Value str_strs_m_a1(rapidjson::kArrayType);
        for(auto& str_strs_m_e1 : str_strs_m_e0.second) {
            PUM::PushBack(str_strs_m_a1, str_strs_m_e1);
        }
        PUM::Push(str_strs_m_c0, PUM::ConvertToString(str_strs_m_e0.first).data(), str_strs_m_a1);
    }
    auto str_ibm_m_c0 = PUM::AddObject(obj, "str_ibm_m");
    for(auto& str_ibm_m_e0 : p->str_ibm_m) {
        auto str_ibm_m_c1 = PUM::AddObject(str_ibm_m_c0, PUM::ConvertToString(str_ibm_m_e0.first).data());
        for(auto& str_ibm_m_e1 : str_ibm_m_e0.second) {
            PUM::Push(str_ibm_m_c1, PUM::ConvertToString(str_ibm_m_e1.first).data(), str_ibm_m_e1.second);
        }
    }
    auto str_iim_m_c0 = PUM::AddObject(obj, "str_iim_m");
    for(auto& str_iim_m_e0 : p->str_iim_m) {
        auto str_iim_m_c1 = PUM::AddObject(str_iim_m_c0, PUM::ConvertToString(str_iim_m_e0.first).data());
        for(auto& str_iim_m_e1 : str_iim_m_e0.second) {
            PUM::Push(str_iim_m_c1, PUM::ConvertToString(str_iim_m_e1.first).data(), str_iim_m_e1.second);
        }
    }
    auto str_idm_m_c0 = PUM::AddObject(obj, "str_idm_m");
    for(auto& str_idm_m_e0 : p->str_idm_m) {
        auto str_idm_m_c1 = PUM::AddObject(str_idm_m_c0, PUM::ConvertToString(str_idm_m_e0.first).data());
        for(auto& str_idm_m_e1 : str_idm_m_e0.second) {
            PUM::Push(str_idm_m_c1, PUM::ConvertToString(str_idm_m_e1.first).data(), str_idm_m_e1.second);
        }
    }
    auto str_istrm_m_c0 = PUM::AddObject(obj, "str_istrm_m");
    for(auto& str_istrm_m_e0 : p->str_istrm_m) {
        auto str_istrm_m_c1 = PUM::AddObject(str_istrm_m_c0, PUM::ConvertToString(str_istrm_m_e0.first).data());
        for(auto& str_istrm_m_e1 : str_istrm_m_e0.second) {
            PUM::Push(str_istrm_m_c1, PUM::ConvertToString(str_istrm_m_e1.first).data(), str_istrm_m_e1.second);
        }
    }
    auto str_strbm_m_c0 = PUM::AddObject(obj, "str_strbm_m");
    for(auto& str_strbm_m_e0 : p->str_strbm_m) {
        auto str_strbm_m_c1 = PUM::AddObject(str_strbm_m_c0, PUM::ConvertToString(str_strbm_m_e0.first).data());
        for(auto& str_strbm_m_e1 : str_strbm_m_e0.second) {
            PUM::Push(str_strbm_m_c1, PUM::ConvertToString(str_strbm_m_e1.first).data(), str_strbm_m_e1.second);
        }
    }
    auto str_strim_m_c0 = PUM::AddObject(obj, "str_strim_m");
    for(auto& str_strim_m_e0 : p->str_strim_m) {
        auto str_strim_m_c1 = PUM::AddObject(str_strim_m_c0, PUM::ConvertToString(str_strim_m_e0.first).data());
        for(auto& str_strim_m_e1 : str_strim_m_e0.second) {
            PUM::Push(str_strim_m_c1, PUM::ConvertToString(str_strim_m_e1.first).data(), str_strim_m_e1.second);
        }
    }
    auto str_strdm_m_c0 = PUM::AddObject(obj, "str_strdm_m");
    for(auto& str_strdm_m_e0 : p->str_strdm_m) {
        auto str_strdm_m_c1 = PUM::AddObject(str_strdm_m_c0, PUM::ConvertToString(str_strdm_m_e0.first).data());
        for(auto& str_strdm_m_e1 : str_strdm_m_e0.second) {
            PUM::Push(str_strdm_m_c1, PUM::ConvertToString(str_strdm_m_e1.first).data(), str_strdm_m_e1.second);
        }
    }
    auto str_strstrm_m_c0 = PUM::AddObject(obj, "str_strstrm_m");
    for(auto& str_strstrm_m_e0 : p->str_strstrm_m) {
        auto str_strstrm_m_c1 = PUM::AddObject(str_strstrm_m_c0, PUM::ConvertToString(str_strstrm_m_e0.first).data());
        for(auto& str_strstrm_m_e1 : str_strstrm_m_e0.second) {
            PUM::Push(str_strstrm_m_c1, PUM::ConvertToString(str_strstrm_m_e1.first).data(), str_strstrm_m_e1.second);
        }
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimple::X* p, const Jobj& obj)
{
    POM::PopBool(obj, "b", p->b);
    POM::PopNum(obj, "c", p->c);
    POM::PopNum(obj, "uc", p->uc);
    POM::PopNum(obj, "s", p->s);
    POM::PopNum(obj, "us", p->us);
    POM::PopNum(obj, "i", p->i);
    POM::PopNum(obj, "ui", p->ui);
    POM::PopNum(obj, "l", p->l);
    POM::PopNum(obj, "ul", p->ul);
    POM::PopNum(obj, "ll", p->ll);
    POM::PopNum(obj, "ull", p->ull);
    POM::PopNum(obj, "f", p->f);
    POM::PopNum(obj, "d", p->d);
    POM::PopNum(obj, "i8", p->i8);
    POM::PopNum(obj, "ui8", p->ui8);
    POM::PopNum(obj, "i16", p->i16);
    POM::PopNum(obj, "ui16", p->ui16);
    POM::PopNum(obj, "i32", p->i32);
    POM::PopNum(obj, "ui32", p->ui32);
    POM::PopNum(obj, "i64", p->i64);
    POM::PopNum(obj, "ui64", p->ui64);
    POM::PopStr(obj, "str", p->str);
    if (POM::IsArray(obj, "b_l")) {
        auto b_l_a0 = POM::FindArray(obj, "b_l");
        for(auto& b_l_e0 : b_l_a0) {
            p->b_l.push_back(b_l_e0.GetBool());
        }
    } else {
        bool b_l_t0;
        POM::PopBool(obj, "b_l", b_l_t0);
        p->b_l.push_back(b_l_t0);
    }
    if (POM::IsArray(obj, "i_l")) {
        auto i_l_a0 = POM::FindArray(obj, "i_l");
        for(auto& i_l_e0 : i_l_a0) {
            p->i_l.push_back(i_l_e0.GetInt64());
        }
    } else {
        int i_l_t0;
        POM::PopNum(obj, "i_l", i_l_t0);
        p->i_l.push_back(i_l_t0);
    }
    if (POM::IsArray(obj, "d_l")) {
        auto d_l_a0 = POM::FindArray(obj, "d_l");
        for(auto& d_l_e0 : d_l_a0) {
            p->d_l.push_back(d_l_e0.GetDouble());
        }
    } else {
        double d_l_t0;
        POM::PopNum(obj, "d_l", d_l_t0);
        p->d_l.push_back(d_l_t0);
    }
    if (POM::IsArray(obj, "str_l")) {
        auto str_l_a0 = POM::FindArray(obj, "str_l");
        for(auto& str_l_e0 : str_l_a0) {
            p->str_l.push_back(str_l_e0.GetString());
        }
    } else {
        std::string str_l_t0;
        POM::PopStr(obj, "str_l", str_l_t0);
        p->str_l.push_back(str_l_t0);
    }
    auto b_vl_a0 = POM::FindArray(obj, "b_vl");
    for(auto& b_vl_e0 : b_vl_a0) {
        if (b_vl_e0.IsArray()) {
            std::vector<bool> b_vl_c1;
            auto b_vl_a1 = b_vl_e0.GetArray();
            for(auto& b_vl_e1 : b_vl_a1) {
                b_vl_c1.push_back(b_vl_e1.GetBool());
            }
            p->b_vl.push_back(b_vl_c1);
        } else {
            auto b_vl_t1 = b_vl_e0.GetBool();
            std::vector<bool> b_vl_c1;
            b_vl_c1.push_back(b_vl_t1);
            p->b_vl.push_back(b_vl_c1);
        }
    }
    auto i_vl_a0 = POM::FindArray(obj, "i_vl");
    for(auto& i_vl_e0 : i_vl_a0) {
        if (i_vl_e0.IsArray()) {
            std::vector<int> i_vl_c1;
            auto i_vl_a1 = i_vl_e0.GetArray();
            for(auto& i_vl_e1 : i_vl_a1) {
                i_vl_c1.push_back(i_vl_e1.GetInt64());
            }
            p->i_vl.push_back(i_vl_c1);
        } else {
            auto i_vl_t1 = i_vl_e0.GetInt64();
            std::vector<int> i_vl_c1;
            i_vl_c1.push_back(i_vl_t1);
            p->i_vl.push_back(i_vl_c1);
        }
    }
    auto d_vl_a0 = POM::FindArray(obj, "d_vl");
    for(auto& d_vl_e0 : d_vl_a0) {
        if (d_vl_e0.IsArray()) {
            std::vector<double> d_vl_c1;
            auto d_vl_a1 = d_vl_e0.GetArray();
            for(auto& d_vl_e1 : d_vl_a1) {
                d_vl_c1.push_back(d_vl_e1.GetDouble());
            }
            p->d_vl.push_back(d_vl_c1);
        } else {
            auto d_vl_t1 = d_vl_e0.GetDouble();
            std::vector<double> d_vl_c1;
            d_vl_c1.push_back(d_vl_t1);
            p->d_vl.push_back(d_vl_c1);
        }
    }
    auto str_vl_a0 = POM::FindArray(obj, "str_vl");
    for(auto& str_vl_e0 : str_vl_a0) {
        if (str_vl_e0.IsArray()) {
            std::vector<std::string> str_vl_c1;
            auto str_vl_a1 = str_vl_e0.GetArray();
            for(auto& str_vl_e1 : str_vl_a1) {
                str_vl_c1.push_back(str_vl_e1.GetString());
            }
            p->str_vl.push_back(str_vl_c1);
        } else {
            auto str_vl_t1 = str_vl_e0.GetString();
            std::vector<std::string> str_vl_c1;
            str_vl_c1.push_back(str_vl_t1);
            p->str_vl.push_back(str_vl_c1);
        }
    }
    auto b_ll_a0 = POM::FindArray(obj, "b_ll");
    for(auto& b_ll_e0 : b_ll_a0) {
        if (b_ll_e0.IsArray()) {
            std::list<bool> b_ll_c1;
            auto b_ll_a1 = b_ll_e0.GetArray();
            for(auto& b_ll_e1 : b_ll_a1) {
                b_ll_c1.push_back(b_ll_e1.GetBool());
            }
            p->b_ll.push_back(b_ll_c1);
        } else {
            auto b_ll_t1 = b_ll_e0.GetBool();
            std::list<bool> b_ll_c1;
            b_ll_c1.push_back(b_ll_t1);
            p->b_ll.push_back(b_ll_c1);
        }
    }
    auto i_ll_a0 = POM::FindArray(obj, "i_ll");
    for(auto& i_ll_e0 : i_ll_a0) {
        if (i_ll_e0.IsArray()) {
            std::list<int> i_ll_c1;
            auto i_ll_a1 = i_ll_e0.GetArray();
            for(auto& i_ll_e1 : i_ll_a1) {
                i_ll_c1.push_back(i_ll_e1.GetInt64());
            }
            p->i_ll.push_back(i_ll_c1);
        } else {
            auto i_ll_t1 = i_ll_e0.GetInt64();
            std::list<int> i_ll_c1;
            i_ll_c1.push_back(i_ll_t1);
            p->i_ll.push_back(i_ll_c1);
        }
    }
    auto d_ll_a0 = POM::FindArray(obj, "d_ll");
    for(auto& d_ll_e0 : d_ll_a0) {
        if (d_ll_e0.IsArray()) {
            std::list<double> d_ll_c1;
            auto d_ll_a1 = d_ll_e0.GetArray();
            for(auto& d_ll_e1 : d_ll_a1) {
                d_ll_c1.push_back(d_ll_e1.GetDouble());
            }
            p->d_ll.push_back(d_ll_c1);
        } else {
            auto d_ll_t1 = d_ll_e0.GetDouble();
            std::list<double> d_ll_c1;
            d_ll_c1.push_back(d_ll_t1);
            p->d_ll.push_back(d_ll_c1);
        }
    }
    auto str_ll_a0 = POM::FindArray(obj, "str_ll");
    for(auto& str_ll_e0 : str_ll_a0) {
        if (str_ll_e0.IsArray()) {
            std::list<std::string> str_ll_c1;
            auto str_ll_a1 = str_ll_e0.GetArray();
            for(auto& str_ll_e1 : str_ll_a1) {
                str_ll_c1.push_back(str_ll_e1.GetString());
            }
            p->str_ll.push_back(str_ll_c1);
        } else {
            auto str_ll_t1 = str_ll_e0.GetString();
            std::list<std::string> str_ll_c1;
            str_ll_c1.push_back(str_ll_t1);
            p->str_ll.push_back(str_ll_c1);
        }
    }
    if (POM::IsArray(obj, "b_v")) {
        auto b_v_a0 = POM::FindArray(obj, "b_v");
        for(auto& b_v_e0 : b_v_a0) {
            p->b_v.push_back(b_v_e0.GetBool());
        }
    } else {
        bool b_v_t0;
        POM::PopBool(obj, "b_v", b_v_t0);
        p->b_v.push_back(b_v_t0);
    }
    if (POM::IsArray(obj, "i_v")) {
        auto i_v_a0 = POM::FindArray(obj, "i_v");
        for(auto& i_v_e0 : i_v_a0) {
            p->i_v.push_back(i_v_e0.GetInt64());
        }
    } else {
        int i_v_t0;
        POM::PopNum(obj, "i_v", i_v_t0);
        p->i_v.push_back(i_v_t0);
    }
    if (POM::IsArray(obj, "d_v")) {
        auto d_v_a0 = POM::FindArray(obj, "d_v");
        for(auto& d_v_e0 : d_v_a0) {
            p->d_v.push_back(d_v_e0.GetDouble());
        }
    } else {
        double d_v_t0;
        POM::PopNum(obj, "d_v", d_v_t0);
        p->d_v.push_back(d_v_t0);
    }
    if (POM::IsArray(obj, "str_v")) {
        auto str_v_a0 = POM::FindArray(obj, "str_v");
        for(auto& str_v_e0 : str_v_a0) {
            p->str_v.push_back(str_v_e0.GetString());
        }
    } else {
        std::string str_v_t0;
        POM::PopStr(obj, "str_v", str_v_t0);
        p->str_v.push_back(str_v_t0);
    }
    auto b_vv_a0 = POM::FindArray(obj, "b_vv");
    for(auto& b_vv_e0 : b_vv_a0) {
        if (b_vv_e0.IsArray()) {
            std::vector<bool> b_vv_c1;
            auto b_vv_a1 = b_vv_e0.GetArray();
            for(auto& b_vv_e1 : b_vv_a1) {
                b_vv_c1.push_back(b_vv_e1.GetBool());
            }
            p->b_vv.push_back(b_vv_c1);
        } else {
            auto b_vv_t1 = b_vv_e0.GetBool();
            std::vector<bool> b_vv_c1;
            b_vv_c1.push_back(b_vv_t1);
            p->b_vv.push_back(b_vv_c1);
        }
    }
    auto i_vv_a0 = POM::FindArray(obj, "i_vv");
    for(auto& i_vv_e0 : i_vv_a0) {
        if (i_vv_e0.IsArray()) {
            std::vector<int> i_vv_c1;
            auto i_vv_a1 = i_vv_e0.GetArray();
            for(auto& i_vv_e1 : i_vv_a1) {
                i_vv_c1.push_back(i_vv_e1.GetInt64());
            }
            p->i_vv.push_back(i_vv_c1);
        } else {
            auto i_vv_t1 = i_vv_e0.GetInt64();
            std::vector<int> i_vv_c1;
            i_vv_c1.push_back(i_vv_t1);
            p->i_vv.push_back(i_vv_c1);
        }
    }
    auto d_vv_a0 = POM::FindArray(obj, "d_vv");
    for(auto& d_vv_e0 : d_vv_a0) {
        if (d_vv_e0.IsArray()) {
            std::vector<double> d_vv_c1;
            auto d_vv_a1 = d_vv_e0.GetArray();
            for(auto& d_vv_e1 : d_vv_a1) {
                d_vv_c1.push_back(d_vv_e1.GetDouble());
            }
            p->d_vv.push_back(d_vv_c1);
        } else {
            auto d_vv_t1 = d_vv_e0.GetDouble();
            std::vector<double> d_vv_c1;
            d_vv_c1.push_back(d_vv_t1);
            p->d_vv.push_back(d_vv_c1);
        }
    }
    auto str_vv_a0 = POM::FindArray(obj, "str_vv");
    for(auto& str_vv_e0 : str_vv_a0) {
        if (str_vv_e0.IsArray()) {
            std::vector<std::string> str_vv_c1;
            auto str_vv_a1 = str_vv_e0.GetArray();
            for(auto& str_vv_e1 : str_vv_a1) {
                str_vv_c1.push_back(str_vv_e1.GetString());
            }
            p->str_vv.push_back(str_vv_c1);
        } else {
            auto str_vv_t1 = str_vv_e0.GetString();
            std::vector<std::string> str_vv_c1;
            str_vv_c1.push_back(str_vv_t1);
            p->str_vv.push_back(str_vv_c1);
        }
    }
    auto b_lv_a0 = POM::FindArray(obj, "b_lv");
    for(auto& b_lv_e0 : b_lv_a0) {
        if (b_lv_e0.IsArray()) {
            std::list<bool> b_lv_c1;
            auto b_lv_a1 = b_lv_e0.GetArray();
            for(auto& b_lv_e1 : b_lv_a1) {
                b_lv_c1.push_back(b_lv_e1.GetBool());
            }
            p->b_lv.push_back(b_lv_c1);
        } else {
            auto b_lv_t1 = b_lv_e0.GetBool();
            std::list<bool> b_lv_c1;
            b_lv_c1.push_back(b_lv_t1);
            p->b_lv.push_back(b_lv_c1);
        }
    }
    auto i_lv_a0 = POM::FindArray(obj, "i_lv");
    for(auto& i_lv_e0 : i_lv_a0) {
        if (i_lv_e0.IsArray()) {
            std::list<int> i_lv_c1;
            auto i_lv_a1 = i_lv_e0.GetArray();
            for(auto& i_lv_e1 : i_lv_a1) {
                i_lv_c1.push_back(i_lv_e1.GetInt64());
            }
            p->i_lv.push_back(i_lv_c1);
        } else {
            auto i_lv_t1 = i_lv_e0.GetInt64();
            std::list<int> i_lv_c1;
            i_lv_c1.push_back(i_lv_t1);
            p->i_lv.push_back(i_lv_c1);
        }
    }
    auto d_lv_a0 = POM::FindArray(obj, "d_lv");
    for(auto& d_lv_e0 : d_lv_a0) {
        if (d_lv_e0.IsArray()) {
            std::list<double> d_lv_c1;
            auto d_lv_a1 = d_lv_e0.GetArray();
            for(auto& d_lv_e1 : d_lv_a1) {
                d_lv_c1.push_back(d_lv_e1.GetDouble());
            }
            p->d_lv.push_back(d_lv_c1);
        } else {
            auto d_lv_t1 = d_lv_e0.GetDouble();
            std::list<double> d_lv_c1;
            d_lv_c1.push_back(d_lv_t1);
            p->d_lv.push_back(d_lv_c1);
        }
    }
    auto str_lv_a0 = POM::FindArray(obj, "str_lv");
    for(auto& str_lv_e0 : str_lv_a0) {
        if (str_lv_e0.IsArray()) {
            std::list<std::string> str_lv_c1;
            auto str_lv_a1 = str_lv_e0.GetArray();
            for(auto& str_lv_e1 : str_lv_a1) {
                str_lv_c1.push_back(str_lv_e1.GetString());
            }
            p->str_lv.push_back(str_lv_c1);
        } else {
            auto str_lv_t1 = str_lv_e0.GetString();
            std::list<std::string> str_lv_c1;
            str_lv_c1.push_back(str_lv_t1);
            p->str_lv.push_back(str_lv_c1);
        }
    }
    if (POM::IsArray(obj, "i_s")) {
        auto i_s_a0 = POM::FindArray(obj, "i_s");
        for(auto& i_s_e0 : i_s_a0) {
            p->i_s.insert(i_s_e0.GetInt64());
        }
    } else {
        int i_s_t0;
        POM::PopNum(obj, "i_s", i_s_t0);
        p->i_s.insert(i_s_t0);
    }
    if (POM::IsArray(obj, "str_s")) {
        auto str_s_a0 = POM::FindArray(obj, "str_s");
        for(auto& str_s_e0 : str_s_a0) {
            p->str_s.insert(str_s_e0.GetString());
        }
    } else {
        std::string str_s_t0;
        POM::PopStr(obj, "str_s", str_s_t0);
        p->str_s.insert(str_s_t0);
    }
    auto ib_m_a0 = POM::FindObject(obj, "ib_m");
    for(auto& ib_m_e0 : ib_m_a0) {
        p->ib_m.insert({ std::stod(ib_m_e0.name.GetString()), ib_m_e0.value.GetBool() });
    }
    auto ii_m_a0 = POM::FindObject(obj, "ii_m");
    for(auto& ii_m_e0 : ii_m_a0) {
        p->ii_m.insert({ std::stod(ii_m_e0.name.GetString()), ii_m_e0.value.GetInt64() });
    }
    auto id_m_a0 = POM::FindObject(obj, "id_m");
    for(auto& id_m_e0 : id_m_a0) {
        p->id_m.insert({ std::stod(id_m_e0.name.GetString()), id_m_e0.value.GetDouble() });
    }
    auto istr_m_a0 = POM::FindObject(obj, "istr_m");
    for(auto& istr_m_e0 : istr_m_a0) {
        p->istr_m.insert({ std::stod(istr_m_e0.name.GetString()), istr_m_e0.value.GetString() });
    }
    auto i_bl_m_a0 = POM::FindObject(obj, "i_bl_m");
    for(auto& i_bl_m_e0 : i_bl_m_a0) {
        if (i_bl_m_e0.value.IsArray()) {
            std::list<bool> i_bl_m_c1;
            auto i_bl_m_a1 = i_bl_m_e0.value.GetArray();
            for(auto& i_bl_m_e1 : i_bl_m_a1) {
                i_bl_m_c1.push_back(i_bl_m_e1.GetBool());
            }
            p->i_bl_m.insert({ std::stod(i_bl_m_e0.name.GetString()), i_bl_m_c1 });
        } else {
            auto i_bl_m_t1 = i_bl_m_e0.value.GetBool();
            std::list<bool> i_bl_m_c1;
            i_bl_m_c1.push_back(i_bl_m_t1);
            p->i_bl_m.insert({ std::stod(i_bl_m_e0.name.GetString()), i_bl_m_c1 });
        }
    }
    auto i_il_m_a0 = POM::FindObject(obj, "i_il_m");
    for(auto& i_il_m_e0 : i_il_m_a0) {
        if (i_il_m_e0.value.IsArray()) {
            std::list<int> i_il_m_c1;
            auto i_il_m_a1 = i_il_m_e0.value.GetArray();
            for(auto& i_il_m_e1 : i_il_m_a1) {
                i_il_m_c1.push_back(i_il_m_e1.GetInt64());
            }
            p->i_il_m.insert({ std::stod(i_il_m_e0.name.GetString()), i_il_m_c1 });
        } else {
            auto i_il_m_t1 = i_il_m_e0.value.GetInt64();
            std::list<int> i_il_m_c1;
            i_il_m_c1.push_back(i_il_m_t1);
            p->i_il_m.insert({ std::stod(i_il_m_e0.name.GetString()), i_il_m_c1 });
        }
    }
    auto i_dl_m_a0 = POM::FindObject(obj, "i_dl_m");
    for(auto& i_dl_m_e0 : i_dl_m_a0) {
        if (i_dl_m_e0.value.IsArray()) {
            std::list<double> i_dl_m_c1;
            auto i_dl_m_a1 = i_dl_m_e0.value.GetArray();
            for(auto& i_dl_m_e1 : i_dl_m_a1) {
                i_dl_m_c1.push_back(i_dl_m_e1.GetDouble());
            }
            p->i_dl_m.insert({ std::stod(i_dl_m_e0.name.GetString()), i_dl_m_c1 });
        } else {
            auto i_dl_m_t1 = i_dl_m_e0.value.GetDouble();
            std::list<double> i_dl_m_c1;
            i_dl_m_c1.push_back(i_dl_m_t1);
            p->i_dl_m.insert({ std::stod(i_dl_m_e0.name.GetString()), i_dl_m_c1 });
        }
    }
    auto i_strl_m_a0 = POM::FindObject(obj, "i_strl_m");
    for(auto& i_strl_m_e0 : i_strl_m_a0) {
        if (i_strl_m_e0.value.IsArray()) {
            std::list<std::string> i_strl_m_c1;
            auto i_strl_m_a1 = i_strl_m_e0.value.GetArray();
            for(auto& i_strl_m_e1 : i_strl_m_a1) {
                i_strl_m_c1.push_back(i_strl_m_e1.GetString());
            }
            p->i_strl_m.insert({ std::stod(i_strl_m_e0.name.GetString()), i_strl_m_c1 });
        } else {
            auto i_strl_m_t1 = i_strl_m_e0.value.GetString();
            std::list<std::string> i_strl_m_c1;
            i_strl_m_c1.push_back(i_strl_m_t1);
            p->i_strl_m.insert({ std::stod(i_strl_m_e0.name.GetString()), i_strl_m_c1 });
        }
    }
    auto i_bv_m_a0 = POM::FindObject(obj, "i_bv_m");
    for(auto& i_bv_m_e0 : i_bv_m_a0) {
        if (i_bv_m_e0.value.IsArray()) {
            std::vector<bool> i_bv_m_c1;
            auto i_bv_m_a1 = i_bv_m_e0.value.GetArray();
            for(auto& i_bv_m_e1 : i_bv_m_a1) {
                i_bv_m_c1.push_back(i_bv_m_e1.GetBool());
            }
            p->i_bv_m.insert({ std::stod(i_bv_m_e0.name.GetString()), i_bv_m_c1 });
        } else {
            auto i_bv_m_t1 = i_bv_m_e0.value.GetBool();
            std::vector<bool> i_bv_m_c1;
            i_bv_m_c1.push_back(i_bv_m_t1);
            p->i_bv_m.insert({ std::stod(i_bv_m_e0.name.GetString()), i_bv_m_c1 });
        }
    }
    auto i_iv_m_a0 = POM::FindObject(obj, "i_iv_m");
    for(auto& i_iv_m_e0 : i_iv_m_a0) {
        if (i_iv_m_e0.value.IsArray()) {
            std::vector<int> i_iv_m_c1;
            auto i_iv_m_a1 = i_iv_m_e0.value.GetArray();
            for(auto& i_iv_m_e1 : i_iv_m_a1) {
                i_iv_m_c1.push_back(i_iv_m_e1.GetInt64());
            }
            p->i_iv_m.insert({ std::stod(i_iv_m_e0.name.GetString()), i_iv_m_c1 });
        } else {
            auto i_iv_m_t1 = i_iv_m_e0.value.GetInt64();
            std::vector<int> i_iv_m_c1;
            i_iv_m_c1.push_back(i_iv_m_t1);
            p->i_iv_m.insert({ std::stod(i_iv_m_e0.name.GetString()), i_iv_m_c1 });
        }
    }
    auto i_dv_m_a0 = POM::FindObject(obj, "i_dv_m");
    for(auto& i_dv_m_e0 : i_dv_m_a0) {
        if (i_dv_m_e0.value.IsArray()) {
            std::vector<double> i_dv_m_c1;
            auto i_dv_m_a1 = i_dv_m_e0.value.GetArray();
            for(auto& i_dv_m_e1 : i_dv_m_a1) {
                i_dv_m_c1.push_back(i_dv_m_e1.GetDouble());
            }
            p->i_dv_m.insert({ std::stod(i_dv_m_e0.name.GetString()), i_dv_m_c1 });
        } else {
            auto i_dv_m_t1 = i_dv_m_e0.value.GetDouble();
            std::vector<double> i_dv_m_c1;
            i_dv_m_c1.push_back(i_dv_m_t1);
            p->i_dv_m.insert({ std::stod(i_dv_m_e0.name.GetString()), i_dv_m_c1 });
        }
    }
    auto i_strv_m_a0 = POM::FindObject(obj, "i_strv_m");
    for(auto& i_strv_m_e0 : i_strv_m_a0) {
        if (i_strv_m_e0.value.IsArray()) {
            std::vector<std::string> i_strv_m_c1;
            auto i_strv_m_a1 = i_strv_m_e0.value.GetArray();
            for(auto& i_strv_m_e1 : i_strv_m_a1) {
                i_strv_m_c1.push_back(i_strv_m_e1.GetString());
            }
            p->i_strv_m.insert({ std::stod(i_strv_m_e0.name.GetString()), i_strv_m_c1 });
        } else {
            auto i_strv_m_t1 = i_strv_m_e0.value.GetString();
            std::vector<std::string> i_strv_m_c1;
            i_strv_m_c1.push_back(i_strv_m_t1);
            p->i_strv_m.insert({ std::stod(i_strv_m_e0.name.GetString()), i_strv_m_c1 });
        }
    }
    auto i_is_m_a0 = POM::FindObject(obj, "i_is_m");
    for(auto& i_is_m_e0 : i_is_m_a0) {
        if (i_is_m_e0.value.IsArray()) {
            std::set<int> i_is_m_c1;
            auto i_is_m_a1 = i_is_m_e0.value.GetArray();
            for(auto& i_is_m_e1 : i_is_m_a1) {
                i_is_m_c1.insert(i_is_m_e1.GetInt64());
            }
            p->i_is_m.insert({ std::stod(i_is_m_e0.name.GetString()), i_is_m_c1 });
        } else {
            auto i_is_m_t1 = i_is_m_e0.value.GetInt64();
            std::set<int> i_is_m_c1;
            i_is_m_c1.insert(i_is_m_t1);
            p->i_is_m.insert({ std::stod(i_is_m_e0.name.GetString()), i_is_m_c1 });
        }
    }
    auto i_strs_m_a0 = POM::FindObject(obj, "i_strs_m");
    for(auto& i_strs_m_e0 : i_strs_m_a0) {
        if (i_strs_m_e0.value.IsArray()) {
            std::set<std::string> i_strs_m_c1;
            auto i_strs_m_a1 = i_strs_m_e0.value.GetArray();
            for(auto& i_strs_m_e1 : i_strs_m_a1) {
                i_strs_m_c1.insert(i_strs_m_e1.GetString());
            }
            p->i_strs_m.insert({ std::stod(i_strs_m_e0.name.GetString()), i_strs_m_c1 });
        } else {
            auto i_strs_m_t1 = i_strs_m_e0.value.GetString();
            std::set<std::string> i_strs_m_c1;
            i_strs_m_c1.insert(i_strs_m_t1);
            p->i_strs_m.insert({ std::stod(i_strs_m_e0.name.GetString()), i_strs_m_c1 });
        }
    }
    auto i_ibm_m_a0 = POM::FindObject(obj, "i_ibm_m");
    for(auto& i_ibm_m_e0 : i_ibm_m_a0) {
        std::map<int,bool> i_ibm_m_c1;
        auto i_ibm_m_a1 = i_ibm_m_e0.value.GetObject();
        for(auto& i_ibm_m_e1 : i_ibm_m_a1) {
            i_ibm_m_c1.insert({ std::stod(i_ibm_m_e1.name.GetString()), i_ibm_m_e1.value.GetBool() });
        }
        p->i_ibm_m.insert({ std::stod(i_ibm_m_e0.name.GetString()), i_ibm_m_c1 });
    }
    auto i_iim_m_a0 = POM::FindObject(obj, "i_iim_m");
    for(auto& i_iim_m_e0 : i_iim_m_a0) {
        std::map<int,int> i_iim_m_c1;
        auto i_iim_m_a1 = i_iim_m_e0.value.GetObject();
        for(auto& i_iim_m_e1 : i_iim_m_a1) {
            i_iim_m_c1.insert({ std::stod(i_iim_m_e1.name.GetString()), i_iim_m_e1.value.GetInt64() });
        }
        p->i_iim_m.insert({ std::stod(i_iim_m_e0.name.GetString()), i_iim_m_c1 });
    }
    auto i_idm_m_a0 = POM::FindObject(obj, "i_idm_m");
    for(auto& i_idm_m_e0 : i_idm_m_a0) {
        std::map<int,double> i_idm_m_c1;
        auto i_idm_m_a1 = i_idm_m_e0.value.GetObject();
        for(auto& i_idm_m_e1 : i_idm_m_a1) {
            i_idm_m_c1.insert({ std::stod(i_idm_m_e1.name.GetString()), i_idm_m_e1.value.GetDouble() });
        }
        p->i_idm_m.insert({ std::stod(i_idm_m_e0.name.GetString()), i_idm_m_c1 });
    }
    auto i_istrm_m_a0 = POM::FindObject(obj, "i_istrm_m");
    for(auto& i_istrm_m_e0 : i_istrm_m_a0) {
        std::map<int,std::string> i_istrm_m_c1;
        auto i_istrm_m_a1 = i_istrm_m_e0.value.GetObject();
        for(auto& i_istrm_m_e1 : i_istrm_m_a1) {
            i_istrm_m_c1.insert({ std::stod(i_istrm_m_e1.name.GetString()), i_istrm_m_e1.value.GetString() });
        }
        p->i_istrm_m.insert({ std::stod(i_istrm_m_e0.name.GetString()), i_istrm_m_c1 });
    }
    auto i_strbm_m_a0 = POM::FindObject(obj, "i_strbm_m");
    for(auto& i_strbm_m_e0 : i_strbm_m_a0) {
        std::map<std::string,bool> i_strbm_m_c1;
        auto i_strbm_m_a1 = i_strbm_m_e0.value.GetObject();
        for(auto& i_strbm_m_e1 : i_strbm_m_a1) {
            i_strbm_m_c1.insert({ i_strbm_m_e1.name.GetString(), i_strbm_m_e1.value.GetBool() });
        }
        p->i_strbm_m.insert({ std::stod(i_strbm_m_e0.name.GetString()), i_strbm_m_c1 });
    }
    auto i_strim_m_a0 = POM::FindObject(obj, "i_strim_m");
    for(auto& i_strim_m_e0 : i_strim_m_a0) {
        std::map<std::string,int> i_strim_m_c1;
        auto i_strim_m_a1 = i_strim_m_e0.value.GetObject();
        for(auto& i_strim_m_e1 : i_strim_m_a1) {
            i_strim_m_c1.insert({ i_strim_m_e1.name.GetString(), i_strim_m_e1.value.GetInt64() });
        }
        p->i_strim_m.insert({ std::stod(i_strim_m_e0.name.GetString()), i_strim_m_c1 });
    }
    auto i_strdm_m_a0 = POM::FindObject(obj, "i_strdm_m");
    for(auto& i_strdm_m_e0 : i_strdm_m_a0) {
        std::map<std::string,double> i_strdm_m_c1;
        auto i_strdm_m_a1 = i_strdm_m_e0.value.GetObject();
        for(auto& i_strdm_m_e1 : i_strdm_m_a1) {
            i_strdm_m_c1.insert({ i_strdm_m_e1.name.GetString(), i_strdm_m_e1.value.GetDouble() });
        }
        p->i_strdm_m.insert({ std::stod(i_strdm_m_e0.name.GetString()), i_strdm_m_c1 });
    }
    auto i_strstrm_m_a0 = POM::FindObject(obj, "i_strstrm_m");
    for(auto& i_strstrm_m_e0 : i_strstrm_m_a0) {
        std::map<std::string,std::string> i_strstrm_m_c1;
        auto i_strstrm_m_a1 = i_strstrm_m_e0.value.GetObject();
        for(auto& i_strstrm_m_e1 : i_strstrm_m_a1) {
            i_strstrm_m_c1.insert({ i_strstrm_m_e1.name.GetString(), i_strstrm_m_e1.value.GetString() });
        }
        p->i_strstrm_m.insert({ std::stod(i_strstrm_m_e0.name.GetString()), i_strstrm_m_c1 });
    }
    auto strb_m_a0 = POM::FindObject(obj, "strb_m");
    for(auto& strb_m_e0 : strb_m_a0) {
        p->strb_m.insert({ strb_m_e0.name.GetString(), strb_m_e0.value.GetBool() });
    }
    auto stri_m_a0 = POM::FindObject(obj, "stri_m");
    for(auto& stri_m_e0 : stri_m_a0) {
        p->stri_m.insert({ stri_m_e0.name.GetString(), stri_m_e0.value.GetInt64() });
    }
    auto strd_m_a0 = POM::FindObject(obj, "strd_m");
    for(auto& strd_m_e0 : strd_m_a0) {
        p->strd_m.insert({ strd_m_e0.name.GetString(), strd_m_e0.value.GetDouble() });
    }
    auto strstr_m_a0 = POM::FindObject(obj, "strstr_m");
    for(auto& strstr_m_e0 : strstr_m_a0) {
        p->strstr_m.insert({ strstr_m_e0.name.GetString(), strstr_m_e0.value.GetString() });
    }
    auto str_bv_m_a0 = POM::FindObject(obj, "str_bv_m");
    for(auto& str_bv_m_e0 : str_bv_m_a0) {
        if (str_bv_m_e0.value.IsArray()) {
            std::vector<bool> str_bv_m_c1;
            auto str_bv_m_a1 = str_bv_m_e0.value.GetArray();
            for(auto& str_bv_m_e1 : str_bv_m_a1) {
                str_bv_m_c1.push_back(str_bv_m_e1.GetBool());
            }
            p->str_bv_m.insert({ str_bv_m_e0.name.GetString(), str_bv_m_c1 });
        } else {
            auto str_bv_m_t1 = str_bv_m_e0.value.GetBool();
            std::vector<bool> str_bv_m_c1;
            str_bv_m_c1.push_back(str_bv_m_t1);
            p->str_bv_m.insert({ str_bv_m_e0.name.GetString(), str_bv_m_c1 });
        }
    }
    auto str_iv_m_a0 = POM::FindObject(obj, "str_iv_m");
    for(auto& str_iv_m_e0 : str_iv_m_a0) {
        if (str_iv_m_e0.value.IsArray()) {
            std::vector<int> str_iv_m_c1;
            auto str_iv_m_a1 = str_iv_m_e0.value.GetArray();
            for(auto& str_iv_m_e1 : str_iv_m_a1) {
                str_iv_m_c1.push_back(str_iv_m_e1.GetInt64());
            }
            p->str_iv_m.insert({ str_iv_m_e0.name.GetString(), str_iv_m_c1 });
        } else {
            auto str_iv_m_t1 = str_iv_m_e0.value.GetInt64();
            std::vector<int> str_iv_m_c1;
            str_iv_m_c1.push_back(str_iv_m_t1);
            p->str_iv_m.insert({ str_iv_m_e0.name.GetString(), str_iv_m_c1 });
        }
    }
    auto str_dv_m_a0 = POM::FindObject(obj, "str_dv_m");
    for(auto& str_dv_m_e0 : str_dv_m_a0) {
        if (str_dv_m_e0.value.IsArray()) {
            std::vector<double> str_dv_m_c1;
            auto str_dv_m_a1 = str_dv_m_e0.value.GetArray();
            for(auto& str_dv_m_e1 : str_dv_m_a1) {
                str_dv_m_c1.push_back(str_dv_m_e1.GetDouble());
            }
            p->str_dv_m.insert({ str_dv_m_e0.name.GetString(), str_dv_m_c1 });
        } else {
            auto str_dv_m_t1 = str_dv_m_e0.value.GetDouble();
            std::vector<double> str_dv_m_c1;
            str_dv_m_c1.push_back(str_dv_m_t1);
            p->str_dv_m.insert({ str_dv_m_e0.name.GetString(), str_dv_m_c1 });
        }
    }
    auto str_strv_m_a0 = POM::FindObject(obj, "str_strv_m");
    for(auto& str_strv_m_e0 : str_strv_m_a0) {
        if (str_strv_m_e0.value.IsArray()) {
            std::vector<std::string> str_strv_m_c1;
            auto str_strv_m_a1 = str_strv_m_e0.value.GetArray();
            for(auto& str_strv_m_e1 : str_strv_m_a1) {
                str_strv_m_c1.push_back(str_strv_m_e1.GetString());
            }
            p->str_strv_m.insert({ str_strv_m_e0.name.GetString(), str_strv_m_c1 });
        } else {
            auto str_strv_m_t1 = str_strv_m_e0.value.GetString();
            std::vector<std::string> str_strv_m_c1;
            str_strv_m_c1.push_back(str_strv_m_t1);
            p->str_strv_m.insert({ str_strv_m_e0.name.GetString(), str_strv_m_c1 });
        }
    }
    auto str_bl_m_a0 = POM::FindObject(obj, "str_bl_m");
    for(auto& str_bl_m_e0 : str_bl_m_a0) {
        if (str_bl_m_e0.value.IsArray()) {
            std::list<bool> str_bl_m_c1;
            auto str_bl_m_a1 = str_bl_m_e0.value.GetArray();
            for(auto& str_bl_m_e1 : str_bl_m_a1) {
                str_bl_m_c1.push_back(str_bl_m_e1.GetBool());
            }
            p->str_bl_m.insert({ str_bl_m_e0.name.GetString(), str_bl_m_c1 });
        } else {
            auto str_bl_m_t1 = str_bl_m_e0.value.GetBool();
            std::list<bool> str_bl_m_c1;
            str_bl_m_c1.push_back(str_bl_m_t1);
            p->str_bl_m.insert({ str_bl_m_e0.name.GetString(), str_bl_m_c1 });
        }
    }
    auto str_il_m_a0 = POM::FindObject(obj, "str_il_m");
    for(auto& str_il_m_e0 : str_il_m_a0) {
        if (str_il_m_e0.value.IsArray()) {
            std::list<int> str_il_m_c1;
            auto str_il_m_a1 = str_il_m_e0.value.GetArray();
            for(auto& str_il_m_e1 : str_il_m_a1) {
                str_il_m_c1.push_back(str_il_m_e1.GetInt64());
            }
            p->str_il_m.insert({ str_il_m_e0.name.GetString(), str_il_m_c1 });
        } else {
            auto str_il_m_t1 = str_il_m_e0.value.GetInt64();
            std::list<int> str_il_m_c1;
            str_il_m_c1.push_back(str_il_m_t1);
            p->str_il_m.insert({ str_il_m_e0.name.GetString(), str_il_m_c1 });
        }
    }
    auto str_dl_m_a0 = POM::FindObject(obj, "str_dl_m");
    for(auto& str_dl_m_e0 : str_dl_m_a0) {
        if (str_dl_m_e0.value.IsArray()) {
            std::list<double> str_dl_m_c1;
            auto str_dl_m_a1 = str_dl_m_e0.value.GetArray();
            for(auto& str_dl_m_e1 : str_dl_m_a1) {
                str_dl_m_c1.push_back(str_dl_m_e1.GetDouble());
            }
            p->str_dl_m.insert({ str_dl_m_e0.name.GetString(), str_dl_m_c1 });
        } else {
            auto str_dl_m_t1 = str_dl_m_e0.value.GetDouble();
            std::list<double> str_dl_m_c1;
            str_dl_m_c1.push_back(str_dl_m_t1);
            p->str_dl_m.insert({ str_dl_m_e0.name.GetString(), str_dl_m_c1 });
        }
    }
    auto str_strl_m_a0 = POM::FindObject(obj, "str_strl_m");
    for(auto& str_strl_m_e0 : str_strl_m_a0) {
        if (str_strl_m_e0.value.IsArray()) {
            std::list<std::string> str_strl_m_c1;
            auto str_strl_m_a1 = str_strl_m_e0.value.GetArray();
            for(auto& str_strl_m_e1 : str_strl_m_a1) {
                str_strl_m_c1.push_back(str_strl_m_e1.GetString());
            }
            p->str_strl_m.insert({ str_strl_m_e0.name.GetString(), str_strl_m_c1 });
        } else {
            auto str_strl_m_t1 = str_strl_m_e0.value.GetString();
            std::list<std::string> str_strl_m_c1;
            str_strl_m_c1.push_back(str_strl_m_t1);
            p->str_strl_m.insert({ str_strl_m_e0.name.GetString(), str_strl_m_c1 });
        }
    }
    auto str_is_m_a0 = POM::FindObject(obj, "str_is_m");
    for(auto& str_is_m_e0 : str_is_m_a0) {
        if (str_is_m_e0.value.IsArray()) {
            std::set<int> str_is_m_c1;
            auto str_is_m_a1 = str_is_m_e0.value.GetArray();
            for(auto& str_is_m_e1 : str_is_m_a1) {
                str_is_m_c1.insert(str_is_m_e1.GetInt64());
            }
            p->str_is_m.insert({ str_is_m_e0.name.GetString(), str_is_m_c1 });
        } else {
            auto str_is_m_t1 = str_is_m_e0.value.GetInt64();
            std::set<int> str_is_m_c1;
            str_is_m_c1.insert(str_is_m_t1);
            p->str_is_m.insert({ str_is_m_e0.name.GetString(), str_is_m_c1 });
        }
    }
    auto str_strs_m_a0 = POM::FindObject(obj, "str_strs_m");
    for(auto& str_strs_m_e0 : str_strs_m_a0) {
        if (str_strs_m_e0.value.IsArray()) {
            std::set<std::string> str_strs_m_c1;
            auto str_strs_m_a1 = str_strs_m_e0.value.GetArray();
            for(auto& str_strs_m_e1 : str_strs_m_a1) {
                str_strs_m_c1.insert(str_strs_m_e1.GetString());
            }
            p->str_strs_m.insert({ str_strs_m_e0.name.GetString(), str_strs_m_c1 });
        } else {
            auto str_strs_m_t1 = str_strs_m_e0.value.GetString();
            std::set<std::string> str_strs_m_c1;
            str_strs_m_c1.insert(str_strs_m_t1);
            p->str_strs_m.insert({ str_strs_m_e0.name.GetString(), str_strs_m_c1 });
        }
    }
    auto str_ibm_m_a0 = POM::FindObject(obj, "str_ibm_m");
    for(auto& str_ibm_m_e0 : str_ibm_m_a0) {
        std::map<int,bool> str_ibm_m_c1;
        auto str_ibm_m_a1 = str_ibm_m_e0.value.GetObject();
        for(auto& str_ibm_m_e1 : str_ibm_m_a1) {
            str_ibm_m_c1.insert({ std::stod(str_ibm_m_e1.name.GetString()), str_ibm_m_e1.value.GetBool() });
        }
        p->str_ibm_m.insert({ str_ibm_m_e0.name.GetString(), str_ibm_m_c1 });
    }
    auto str_iim_m_a0 = POM::FindObject(obj, "str_iim_m");
    for(auto& str_iim_m_e0 : str_iim_m_a0) {
        std::map<int,int> str_iim_m_c1;
        auto str_iim_m_a1 = str_iim_m_e0.value.GetObject();
        for(auto& str_iim_m_e1 : str_iim_m_a1) {
            str_iim_m_c1.insert({ std::stod(str_iim_m_e1.name.GetString()), str_iim_m_e1.value.GetInt64() });
        }
        p->str_iim_m.insert({ str_iim_m_e0.name.GetString(), str_iim_m_c1 });
    }
    auto str_idm_m_a0 = POM::FindObject(obj, "str_idm_m");
    for(auto& str_idm_m_e0 : str_idm_m_a0) {
        std::map<int,double> str_idm_m_c1;
        auto str_idm_m_a1 = str_idm_m_e0.value.GetObject();
        for(auto& str_idm_m_e1 : str_idm_m_a1) {
            str_idm_m_c1.insert({ std::stod(str_idm_m_e1.name.GetString()), str_idm_m_e1.value.GetDouble() });
        }
        p->str_idm_m.insert({ str_idm_m_e0.name.GetString(), str_idm_m_c1 });
    }
    auto str_istrm_m_a0 = POM::FindObject(obj, "str_istrm_m");
    for(auto& str_istrm_m_e0 : str_istrm_m_a0) {
        std::map<int,std::string> str_istrm_m_c1;
        auto str_istrm_m_a1 = str_istrm_m_e0.value.GetObject();
        for(auto& str_istrm_m_e1 : str_istrm_m_a1) {
            str_istrm_m_c1.insert({ std::stod(str_istrm_m_e1.name.GetString()), str_istrm_m_e1.value.GetString() });
        }
        p->str_istrm_m.insert({ str_istrm_m_e0.name.GetString(), str_istrm_m_c1 });
    }
    auto str_strbm_m_a0 = POM::FindObject(obj, "str_strbm_m");
    for(auto& str_strbm_m_e0 : str_strbm_m_a0) {
        std::map<std::string,bool> str_strbm_m_c1;
        auto str_strbm_m_a1 = str_strbm_m_e0.value.GetObject();
        for(auto& str_strbm_m_e1 : str_strbm_m_a1) {
            str_strbm_m_c1.insert({ str_strbm_m_e1.name.GetString(), str_strbm_m_e1.value.GetBool() });
        }
        p->str_strbm_m.insert({ str_strbm_m_e0.name.GetString(), str_strbm_m_c1 });
    }
    auto str_strim_m_a0 = POM::FindObject(obj, "str_strim_m");
    for(auto& str_strim_m_e0 : str_strim_m_a0) {
        std::map<std::string,int> str_strim_m_c1;
        auto str_strim_m_a1 = str_strim_m_e0.value.GetObject();
        for(auto& str_strim_m_e1 : str_strim_m_a1) {
            str_strim_m_c1.insert({ str_strim_m_e1.name.GetString(), str_strim_m_e1.value.GetInt64() });
        }
        p->str_strim_m.insert({ str_strim_m_e0.name.GetString(), str_strim_m_c1 });
    }
    auto str_strdm_m_a0 = POM::FindObject(obj, "str_strdm_m");
    for(auto& str_strdm_m_e0 : str_strdm_m_a0) {
        std::map<std::string,double> str_strdm_m_c1;
        auto str_strdm_m_a1 = str_strdm_m_e0.value.GetObject();
        for(auto& str_strdm_m_e1 : str_strdm_m_a1) {
            str_strdm_m_c1.insert({ str_strdm_m_e1.name.GetString(), str_strdm_m_e1.value.GetDouble() });
        }
        p->str_strdm_m.insert({ str_strdm_m_e0.name.GetString(), str_strdm_m_c1 });
    }
    auto str_strstrm_m_a0 = POM::FindObject(obj, "str_strstrm_m");
    for(auto& str_strstrm_m_e0 : str_strstrm_m_a0) {
        std::map<std::string,std::string> str_strstrm_m_c1;
        auto str_strstrm_m_a1 = str_strstrm_m_e0.value.GetObject();
        for(auto& str_strstrm_m_e1 : str_strstrm_m_a1) {
            str_strstrm_m_c1.insert({ str_strstrm_m_e1.name.GetString(), str_strstrm_m_e1.value.GetString() });
        }
        p->str_strstrm_m.insert({ str_strstrm_m_e0.name.GetString(), str_strstrm_m_c1 });
    }
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsSimpleEnum::A0* p)
{
    switch (*p) {
        case nsSimpleEnum::A0::_0:
            return "_0";
        case nsSimpleEnum::A0::_1:
            return "_1";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsSimpleEnum::A0* p)
{
    std::map<std::string, nsSimpleEnum::A0> m;
    m.insert({"_0", nsSimpleEnum::A0::_0});
    m.insert({"_1", nsSimpleEnum::A0::_1});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsSimpleEnum::A1* p)
{
    switch (*p) {
        case nsSimpleEnum::A1::_0:
            return "_0";
        case nsSimpleEnum::A1::_1:
            return "_1";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsSimpleEnum::A1* p)
{
    std::map<std::string, nsSimpleEnum::A1> m;
    m.insert({"_0", nsSimpleEnum::A1::_0});
    m.insert({"_1", nsSimpleEnum::A1::_1});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimpleEnum::X* p, Jobj& obj)
{
    auto a0_c0 = _SerializeEnum(&(p->a0));
    PUM::Push(obj, "a0", a0_c0);
    auto a1_c0 = _SerializeEnum(&(p->a1));
    PUM::Push(obj, "a1", a1_c0);
    auto e0_c0 = _SerializeEnum(&(p->e0));
    PUM::Push(obj, "e0", e0_c0);
    auto e1_c0 = _SerializeEnum(&(p->e1));
    PUM::Push(obj, "e1", e1_c0);
    PUM::Value a0_l_a0(rapidjson::kArrayType);
    for(auto& a0_l_e0 : p->a0_l) {
        auto a0_l_c1 = _SerializeEnum(&a0_l_e0);
        PUM::PushBack(a0_l_a0, a0_l_c1);
    }
    PUM::Push(obj, "a0_l", a0_l_a0);
    PUM::Value a1_l_a0(rapidjson::kArrayType);
    for(auto& a1_l_e0 : p->a1_l) {
        auto a1_l_c1 = _SerializeEnum(&a1_l_e0);
        PUM::PushBack(a1_l_a0, a1_l_c1);
    }
    PUM::Push(obj, "a1_l", a1_l_a0);
    PUM::Value e0_l_a0(rapidjson::kArrayType);
    for(auto& e0_l_e0 : p->e0_l) {
        auto e0_l_c1 = _SerializeEnum(&e0_l_e0);
        PUM::PushBack(e0_l_a0, e0_l_c1);
    }
    PUM::Push(obj, "e0_l", e0_l_a0);
    PUM::Value e1_l_a0(rapidjson::kArrayType);
    for(auto& e1_l_e0 : p->e1_l) {
        auto e1_l_c1 = _SerializeEnum(&e1_l_e0);
        PUM::PushBack(e1_l_a0, e1_l_c1);
    }
    PUM::Push(obj, "e1_l", e1_l_a0);
    auto a0_m_c0 = PUM::AddObject(obj, "a0_m");
    for(auto& a0_m_e0 : p->a0_m) {
        auto a0_m_c1 = _SerializeEnum(&a0_m_e0.second);
        PUM::Push(a0_m_c0, PUM::ConvertToString(a0_m_e0.first).data(), a0_m_c1);
    }
    auto a1_m_c0 = PUM::AddObject(obj, "a1_m");
    for(auto& a1_m_e0 : p->a1_m) {
        auto a1_m_c1 = _SerializeEnum(&a1_m_e0.second);
        PUM::Push(a1_m_c0, PUM::ConvertToString(a1_m_e0.first).data(), a1_m_c1);
    }
    auto e0_m_c0 = PUM::AddObject(obj, "e0_m");
    for(auto& e0_m_e0 : p->e0_m) {
        auto e0_m_c1 = _SerializeEnum(&e0_m_e0.second);
        PUM::Push(e0_m_c0, PUM::ConvertToString(e0_m_e0.first).data(), e0_m_c1);
    }
    auto e1_m_c0 = PUM::AddObject(obj, "e1_m");
    for(auto& e1_m_e0 : p->e1_m) {
        auto e1_m_c1 = _SerializeEnum(&e1_m_e0.second);
        PUM::Push(e1_m_c0, PUM::ConvertToString(e1_m_e0.first).data(), e1_m_c1);
    }
    PUM::Value a0_lll_a0(rapidjson::kArrayType);
    for(auto& a0_lll_e0 : p->a0_lll) {
        PUM::Value a0_lll_a1(rapidjson::kArrayType);
        for(auto& a0_lll_e1 : a0_lll_e0) {
            PUM::Value a0_lll_a2(rapidjson::kArrayType);
            for(auto& a0_lll_e2 : a0_lll_e1) {
                auto a0_lll_c3 = _SerializeEnum(&a0_lll_e2);
                PUM::PushBack(a0_lll_a2, a0_lll_c3);
            }
            PUM::PushBack(a0_lll_a1, a0_lll_a2);
        }
        PUM::PushBack(a0_lll_a0, a0_lll_a1);
    }
    PUM::Push(obj, "a0_lll", a0_lll_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimpleEnum::X* p, const Jobj& obj)
{
    std::string a0_c0;
    POM::PopStr(obj, "a0", a0_c0);
    _DeserializeEnum(a0_c0, &(p->a0));
    std::string a1_c0;
    POM::PopStr(obj, "a1", a1_c0);
    _DeserializeEnum(a1_c0, &(p->a1));
    std::string e0_c0;
    POM::PopStr(obj, "e0", e0_c0);
    _DeserializeEnum(e0_c0, &(p->e0));
    std::string e1_c0;
    POM::PopStr(obj, "e1", e1_c0);
    _DeserializeEnum(e1_c0, &(p->e1));
    auto a0_l_a0 = POM::FindArray(obj, "a0_l");
    for(auto& a0_l_e0 : a0_l_a0) {
        std::string a0_l_o1 = a0_l_e0.GetString();
        nsSimpleEnum::A0 a0_l_c1;
        _DeserializeEnum(a0_l_o1, &a0_l_c1);
        p->a0_l.push_back(a0_l_c1);
    }
    auto a1_l_a0 = POM::FindArray(obj, "a1_l");
    for(auto& a1_l_e0 : a1_l_a0) {
        std::string a1_l_o1 = a1_l_e0.GetString();
        nsSimpleEnum::A1 a1_l_c1;
        _DeserializeEnum(a1_l_o1, &a1_l_c1);
        p->a1_l.push_back(a1_l_c1);
    }
    auto e0_l_a0 = POM::FindArray(obj, "e0_l");
    for(auto& e0_l_e0 : e0_l_a0) {
        std::string e0_l_o1 = e0_l_e0.GetString();
        nsSimpleEnum::X::E0 e0_l_c1;
        _DeserializeEnum(e0_l_o1, &e0_l_c1);
        p->e0_l.push_back(e0_l_c1);
    }
    auto e1_l_a0 = POM::FindArray(obj, "e1_l");
    for(auto& e1_l_e0 : e1_l_a0) {
        std::string e1_l_o1 = e1_l_e0.GetString();
        nsSimpleEnum::X::E1 e1_l_c1;
        _DeserializeEnum(e1_l_o1, &e1_l_c1);
        p->e1_l.push_back(e1_l_c1);
    }
    auto a0_m_a0 = POM::FindObject(obj, "a0_m");
    for(auto& a0_m_e0 : a0_m_a0) {
        std::string a0_m_o1 = a0_m_e0.value.GetString();
        nsSimpleEnum::A0 a0_m_c1;
        _DeserializeEnum(a0_m_o1, &a0_m_c1);
        p->a0_m.insert({ std::stod(a0_m_e0.name.GetString()), a0_m_c1 });
    }
    auto a1_m_a0 = POM::FindObject(obj, "a1_m");
    for(auto& a1_m_e0 : a1_m_a0) {
        std::string a1_m_o1 = a1_m_e0.value.GetString();
        nsSimpleEnum::A1 a1_m_c1;
        _DeserializeEnum(a1_m_o1, &a1_m_c1);
        p->a1_m.insert({ std::stod(a1_m_e0.name.GetString()), a1_m_c1 });
    }
    auto e0_m_a0 = POM::FindObject(obj, "e0_m");
    for(auto& e0_m_e0 : e0_m_a0) {
        std::string e0_m_o1 = e0_m_e0.value.GetString();
        nsSimpleEnum::X::E0 e0_m_c1;
        _DeserializeEnum(e0_m_o1, &e0_m_c1);
        p->e0_m.insert({ std::stod(e0_m_e0.name.GetString()), e0_m_c1 });
    }
    auto e1_m_a0 = POM::FindObject(obj, "e1_m");
    for(auto& e1_m_e0 : e1_m_a0) {
        std::string e1_m_o1 = e1_m_e0.value.GetString();
        nsSimpleEnum::X::E1 e1_m_c1;
        _DeserializeEnum(e1_m_o1, &e1_m_c1);
        p->e1_m.insert({ std::stod(e1_m_e0.name.GetString()), e1_m_c1 });
    }
    auto a0_lll_a0 = POM::FindArray(obj, "a0_lll");
    for(auto& a0_lll_e0 : a0_lll_a0) {
        std::list<std::list<nsSimpleEnum::A0>> a0_lll_c1;
        auto a0_lll_a1 = a0_lll_e0.GetArray();
        for(auto& a0_lll_e1 : a0_lll_a1) {
            std::list<nsSimpleEnum::A0> a0_lll_c2;
            auto a0_lll_a2 = a0_lll_e1.GetArray();
            for(auto& a0_lll_e2 : a0_lll_a2) {
                std::string a0_lll_o3 = a0_lll_e2.GetString();
                nsSimpleEnum::A0 a0_lll_c3;
                _DeserializeEnum(a0_lll_o3, &a0_lll_c3);
                a0_lll_c2.push_back(a0_lll_c3);
            }
            a0_lll_c1.push_back(a0_lll_c2);
        }
        p->a0_lll.push_back(a0_lll_c1);
    }
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsSimpleEnum::X::E0* p)
{
    switch (*p) {
        case nsSimpleEnum::X::E0::_0:
            return "_0";
        case nsSimpleEnum::X::E0::_1:
            return "_1";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsSimpleEnum::X::E0* p)
{
    std::map<std::string, nsSimpleEnum::X::E0> m;
    m.insert({"_0", nsSimpleEnum::X::E0::_0});
    m.insert({"_1", nsSimpleEnum::X::E0::_1});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TJsonSerializer::_SerializeEnum(nsSimpleEnum::X::E1* p)
{
    switch (*p) {
        case nsSimpleEnum::X::E1::_0:
            return "_0";
        case nsSimpleEnum::X::E1::_1:
            return "_1";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsSimpleEnum::X::E1* p)
{
    std::map<std::string, nsSimpleEnum::X::E1> m;
    m.insert({"_0", nsSimpleEnum::X::E1::_0});
    m.insert({"_1", nsSimpleEnum::X::E1::_1});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
