/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_01_05 21:27:10.964
	
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
    
    Data nsTornadoEditor_TDialogButtonClickHandler_Data;
    nsTornadoEditor_TDialogButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDialogButtonClickHandler(); };
    nsTornadoEditor_TDialogButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDialogButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TDialogButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TDialogButtonClickHandler_Data, nsTornadoEditor_TDialogButtonClickHandler_Data });
    
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
    
    Data nsTornadoEditor_TOnMouseClickFileNodeHandler_Data;
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnMouseClickFileNodeHandler(); };
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnMouseClickFileNodeHandler*)p; };
    auto rtti_nsTornadoEditor_TOnMouseClickFileNodeHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnMouseClickFileNodeHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnMouseClickFileNodeHandler_Data, nsTornadoEditor_TOnMouseClickFileNodeHandler_Data });
    
    Data nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data;
    nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenFileHierarchyWindowHandler(); };
    nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenFileHierarchyWindowHandler*)p; };
    auto rtti_nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenFileHierarchyWindowHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data, nsTornadoEditor_TOnOpenFileHierarchyWindowHandler_Data });
    
    Data nsTornadoEditor_TOnOpenProjectClickHandler_Data;
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenProjectClickHandler(); };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenProjectClickHandler*)p; };
    auto rtti_nsTornadoEditor_TOnOpenProjectClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOnOpenProjectClickHandler_Data, nsTornadoEditor_TOnOpenProjectClickHandler_Data });
    
    Data nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectCancelButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectCancelButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectCancelButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data, nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data });
    
    Data nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectOkButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectOkButtonClickHandler*)p; };
    auto rtti_nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectOkButtonClickHandler>();
    
    m.insert({ rtti_nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data, nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data });
    
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
