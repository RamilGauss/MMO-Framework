/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.3, build 54 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_08 07:21:43.417
	
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
    
    std::map<int, Data> m;
    
    Data nsTornadoEditor_TDeleteOnButtonClickHandler_Data;
    nsTornadoEditor_TDeleteOnButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDeleteOnButtonClickHandler(); };
    nsTornadoEditor_TDeleteOnButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDeleteOnButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TDeleteOnButtonClickHandler_Data = globalTypeIdentifier->type<nsTornadoEditor::TDeleteOnButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TDeleteOnButtonClickHandler_Data, nsTornadoEditor_TDeleteOnButtonClickHandler_Data });
    
    Data nsTornadoEditor_TExitButtonClickHandler_Data;
    nsTornadoEditor_TExitButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TExitButtonClickHandler(); };
    nsTornadoEditor_TExitButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TExitButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TExitButtonClickHandler_Data = globalTypeIdentifier->type<nsTornadoEditor::TExitButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TExitButtonClickHandler_Data, nsTornadoEditor_TExitButtonClickHandler_Data });
    
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