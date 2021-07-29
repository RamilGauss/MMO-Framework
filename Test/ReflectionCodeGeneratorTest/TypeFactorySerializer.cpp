/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_29 08:27:54.091
	
#include "TypeFactorySerializer.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTypeFactory;

std::vector<TTypeFactorySerializer::Data> TTypeFactorySerializer::mDataVector;
void TTypeFactorySerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsAllTypes_A_Data;
    nsAllTypes_A_Data.newFunc = [](){ return new nsAllTypes::A(); };
    nsAllTypes_A_Data.deleteFunc = [](void* p){ delete (nsAllTypes::A*)p; };
    auto rtti_nsAllTypes_A_Data = globalTypeIdentifier->type<nsAllTypes::A>();
    
    m.insert({ rtti_nsAllTypes_A_Data, nsAllTypes_A_Data });
    
    Data nsAllTypes_B_Data;
    nsAllTypes_B_Data.newFunc = [](){ return new nsAllTypes::B(); };
    nsAllTypes_B_Data.deleteFunc = [](void* p){ delete (nsAllTypes::B*)p; };
    auto rtti_nsAllTypes_B_Data = globalTypeIdentifier->type<nsAllTypes::B>();
    
    m.insert({ rtti_nsAllTypes_B_Data, nsAllTypes_B_Data });
    
    Data nsAllTypes_C_Data;
    nsAllTypes_C_Data.newFunc = [](){ return new nsAllTypes::C(); };
    nsAllTypes_C_Data.deleteFunc = [](void* p){ delete (nsAllTypes::C*)p; };
    auto rtti_nsAllTypes_C_Data = globalTypeIdentifier->type<nsAllTypes::C>();
    
    m.insert({ rtti_nsAllTypes_C_Data, nsAllTypes_C_Data });
    
    Data nsSimpleComponents_TNameComponent_Data;
    nsSimpleComponents_TNameComponent_Data.newFunc = [](){ return new nsSimpleComponents::TNameComponent(); };
    nsSimpleComponents_TNameComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TNameComponent*)p; };
    auto rtti_nsSimpleComponents_TNameComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TNameComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TNameComponent_Data, nsSimpleComponents_TNameComponent_Data });
    
    Data nsSimpleComponents_TSimpleComponent_Data;
    nsSimpleComponents_TSimpleComponent_Data.newFunc = [](){ return new nsSimpleComponents::TSimpleComponent(); };
    nsSimpleComponents_TSimpleComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TSimpleComponent*)p; };
    auto rtti_nsSimpleComponents_TSimpleComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TSimpleComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TSimpleComponent_Data, nsSimpleComponents_TSimpleComponent_Data });
    
    Data nsSimpleComponents_TValueComponent_Data;
    nsSimpleComponents_TValueComponent_Data.newFunc = [](){ return new nsSimpleComponents::TValueComponent(); };
    nsSimpleComponents_TValueComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TValueComponent*)p; };
    auto rtti_nsSimpleComponents_TValueComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TValueComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TValueComponent_Data, nsSimpleComponents_TValueComponent_Data });
    
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
void* TTypeFactorySerializer::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TTypeFactorySerializer::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
