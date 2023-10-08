/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_08 13:54:04.622
	
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
    
    Data nsTornadoEditor_TCurrentPathToInputTextHandler_Data;
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.newFunc = [](){ return new nsTornadoEditor::TCurrentPathToInputTextHandler(); };
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TCurrentPathToInputTextHandler*)p; };
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TCurrentPathToInputTextHandler>();
    
    datas.push_back(nsTornadoEditor_TCurrentPathToInputTextHandler_Data);
    
    Data nsTornadoEditor_TDialogButtonClickHandler_Data;
    nsTornadoEditor_TDialogButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDialogButtonClickHandler(); };
    nsTornadoEditor_TDialogButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDialogButtonClickHandler*)p; };
    nsTornadoEditor_TDialogButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TDialogButtonClickHandler_Data);
    
    Data nsTornadoEditor_TOnCloseDialogHandler_Data;
    nsTornadoEditor_TOnCloseDialogHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseDialogHandler(); };
    nsTornadoEditor_TOnCloseDialogHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseDialogHandler*)p; };
    nsTornadoEditor_TOnCloseDialogHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseDialogHandler>();
    
    datas.push_back(nsTornadoEditor_TOnCloseDialogHandler_Data);
    
    Data nsTornadoEditor_TOnCloseWindowHandler_Data;
    nsTornadoEditor_TOnCloseWindowHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseWindowHandler(); };
    nsTornadoEditor_TOnCloseWindowHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseWindowHandler*)p; };
    nsTornadoEditor_TOnCloseWindowHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseWindowHandler>();
    
    datas.push_back(nsTornadoEditor_TOnCloseWindowHandler_Data);
    
    Data nsTornadoEditor_TOnExitClickHandler_Data;
    nsTornadoEditor_TOnExitClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnExitClickHandler(); };
    nsTornadoEditor_TOnExitClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnExitClickHandler*)p; };
    nsTornadoEditor_TOnExitClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnExitClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnExitClickHandler_Data);
    
    Data nsTornadoEditor_TOnFileHierarchyClickHandler_Data;
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnFileHierarchyClickHandler(); };
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnFileHierarchyClickHandler*)p; };
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnFileHierarchyClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnFileHierarchyClickHandler_Data);
    
    Data nsTornadoEditor_TOnMouseClickFileNodeHandler_Data;
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnMouseClickFileNodeHandler(); };
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnMouseClickFileNodeHandler*)p; };
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnMouseClickFileNodeHandler>();
    
    datas.push_back(nsTornadoEditor_TOnMouseClickFileNodeHandler_Data);
    
    Data nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data;
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenComponentViewerClickHandler(); };
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenComponentViewerClickHandler*)p; };
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenComponentViewerClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data);
    
    Data nsTornadoEditor_TOnOpenProjectClickHandler_Data;
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenProjectClickHandler(); };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenProjectClickHandler*)p; };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_Data);
    
    Data nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data;
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenSystemViewerClickHandler(); };
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenSystemViewerClickHandler*)p; };
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenSystemViewerClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data);
    
    Data nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectCancelButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectCancelButtonClickHandler*)p; };
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectCancelButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data);
    
    Data nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectOkButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectOkButtonClickHandler*)p; };
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectOkButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data);
    
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
