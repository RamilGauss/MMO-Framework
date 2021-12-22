/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_22 08:22:04.738
	
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
    
    Data nsTornadoEditor_TCurrentPathToInputTextHandler_Data;
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.newFunc = [](){ return new nsTornadoEditor::TCurrentPathToInputTextHandler(); };
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TCurrentPathToInputTextHandler*)p; };
    auto rtti_nsTornadoEditor_TCurrentPathToInputTextHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TCurrentPathToInputTextHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TCurrentPathToInputTextHandler_Data, nsTornadoEditor_TCurrentPathToInputTextHandler_Data });
    
    Data nsTornadoEditor_TDeleteOnButtonClickHandler_Data;
    nsTornadoEditor_TDeleteOnButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDeleteOnButtonClickHandler(); };
    nsTornadoEditor_TDeleteOnButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDeleteOnButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TDeleteOnButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TDeleteOnButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TDeleteOnButtonClickHandler_Data, nsTornadoEditor_TDeleteOnButtonClickHandler_Data });
    
    Data nsTornadoEditor_TDialogButtonClickHandler_Data;
    nsTornadoEditor_TDialogButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDialogButtonClickHandler(); };
    nsTornadoEditor_TDialogButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDialogButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TDialogButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TDialogButtonClickHandler_Data, nsTornadoEditor_TDialogButtonClickHandler_Data });
    
    Data nsTornadoEditor_TExitButtonClickHandler_Data;
    nsTornadoEditor_TExitButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TExitButtonClickHandler(); };
    nsTornadoEditor_TExitButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TExitButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TExitButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TExitButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TExitButtonClickHandler_Data, nsTornadoEditor_TExitButtonClickHandler_Data });
    
    Data nsTornadoEditor_TOnCloseDialogHandler_Data;
    nsTornadoEditor_TOnCloseDialogHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseDialogHandler(); };
    nsTornadoEditor_TOnCloseDialogHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseDialogHandler*)p; };
    auto rtti_nsTornadoEditor_TOnCloseDialogHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseDialogHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnCloseDialogHandler_Data, nsTornadoEditor_TOnCloseDialogHandler_Data });
    
    Data nsTornadoEditor_TOnCloseWindowHandler_Data;
    nsTornadoEditor_TOnCloseWindowHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseWindowHandler(); };
    nsTornadoEditor_TOnCloseWindowHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseWindowHandler*)p; };
    auto rtti_nsTornadoEditor_TOnCloseWindowHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseWindowHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnCloseWindowHandler_Data, nsTornadoEditor_TOnCloseWindowHandler_Data });
    
    Data nsTornadoEditor_TOnExitClickHandler_Data;
    nsTornadoEditor_TOnExitClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnExitClickHandler(); };
    nsTornadoEditor_TOnExitClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnExitClickHandler*)p; };
    auto rtti_nsTornadoEditor_TOnExitClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnExitClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnExitClickHandler_Data, nsTornadoEditor_TOnExitClickHandler_Data });
    
    Data nsTornadoEditor_TOnOpenProjectClickHandler_Data;
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenProjectClickHandler(); };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenProjectClickHandler*)p; };
    auto rtti_nsTornadoEditor_TOnOpenProjectClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnOpenProjectClickHandler_Data, nsTornadoEditor_TOnOpenProjectClickHandler_Data });
    
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
