/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_31 21:19:28.338
	
#include "FeatureTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<TFeatureTypeFactory::Data> TFeatureTypeFactory::mDataVector;
void TFeatureTypeFactory::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsGraphicWrapper_TBeginGraphicFeature_Data;
    nsGraphicWrapper_TBeginGraphicFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TBeginGraphicFeature(); };
    nsGraphicWrapper_TBeginGraphicFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TBeginGraphicFeature*)p; };
    auto rtti_nsGraphicWrapper_TBeginGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TBeginGraphicFeature_Data, nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsGraphicWrapper_TButtonBuilderSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TButtonBuilderSystem(); };
    nsGraphicWrapper_TButtonBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TButtonBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TButtonBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonBuilderSystem_Data, nsGraphicWrapper_TButtonBuilderSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TButtonClickHandlerMakerSystem(); };
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TButtonClickHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data, nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TButtonClickHandlerTerminatorSystem(); };
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TButtonClickHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TButtonMakerSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TButtonMakerSystem(); };
    nsGraphicWrapper_TButtonMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TButtonMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TButtonMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonMakerSystem_Data, nsGraphicWrapper_TButtonMakerSystem_Data });
    
    Data nsGraphicWrapper_TButtonTerminatorSystem_Data;
    nsGraphicWrapper_TButtonTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TButtonTerminatorSystem(); };
    nsGraphicWrapper_TButtonTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TButtonTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TButtonTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonTerminatorSystem_Data, nsGraphicWrapper_TButtonTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsGraphicWrapper_TCameraBuilderFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraBuilderFeature(); };
    nsGraphicWrapper_TCameraBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraBuilderFeature*)p; };
    auto rtti_nsGraphicWrapper_TCameraBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraBuilderFeature_Data, nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsGraphicWrapper_TCameraMakerSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraMakerSystem(); };
    nsGraphicWrapper_TCameraMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TCameraMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraMakerSystem_Data, nsGraphicWrapper_TCameraMakerSystem_Data });
    
    Data nsGraphicWrapper_TCameraTerminatorSystem_Data;
    nsGraphicWrapper_TCameraTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraTerminatorSystem(); };
    nsGraphicWrapper_TCameraTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TCameraTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraTerminatorSystem_Data, nsGraphicWrapper_TCameraTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraUpdaterToModuleSystem(); };
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraUpdaterToModuleSystem*)p; };
    auto rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data, nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TCleanUpUniverseContextSystem(); };
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCleanUpUniverseContextSystem*)p; };
    auto rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data, nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TDialogBuilderSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TDialogBuilderSystem(); };
    nsGraphicWrapper_TDialogBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TDialogBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TDialogBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogBuilderSystem_Data, nsGraphicWrapper_TDialogBuilderSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem(); };
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem(); };
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TDialogMakerSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TDialogMakerSystem(); };
    nsGraphicWrapper_TDialogMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TDialogMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TDialogMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogMakerSystem_Data, nsGraphicWrapper_TDialogMakerSystem_Data });
    
    Data nsGraphicWrapper_TDialogTerminatorSystem_Data;
    nsGraphicWrapper_TDialogTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TDialogTerminatorSystem(); };
    nsGraphicWrapper_TDialogTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TDialogTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TDialogTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogTerminatorSystem_Data, nsGraphicWrapper_TDialogTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_Data;
    nsGraphicWrapper_TEndGraphicFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TEndGraphicFeature(); };
    nsGraphicWrapper_TEndGraphicFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TEndGraphicFeature*)p; };
    auto rtti_nsGraphicWrapper_TEndGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TEndGraphicFeature_Data, nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameKeyHandlerMakerSystem(); };
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameKeyHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem(); };
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem(); };
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem(); };
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem(); };
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem(); };
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem(); };
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem(); };
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsGraphicWrapper_TGuiBuilderFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiBuilderFeature(); };
    nsGraphicWrapper_TGuiBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiBuilderFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiBuilderFeature_Data, nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiCameraBuilderSystem(); };
    nsGraphicWrapper_TGuiCameraBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiCameraBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TGuiCameraBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiCameraBuilderSystem_Data, nsGraphicWrapper_TGuiCameraBuilderSystem_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_Data;
    nsGraphicWrapper_TGuiMakerFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiMakerFeature(); };
    nsGraphicWrapper_TGuiMakerFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiMakerFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiMakerFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiMakerFeature_Data, nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiTerminatorFeature(); };
    nsGraphicWrapper_TGuiTerminatorFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiTerminatorFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data, nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiUpdaterFromModuleFeature(); };
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiUpdaterFromModuleFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiUpdaterToModuleFeature(); };
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiUpdaterToModuleFeature*)p; };
    auto rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TInputTextBuilderSystem(); };
    nsGraphicWrapper_TInputTextBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TInputTextBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TInputTextBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextBuilderSystem_Data, nsGraphicWrapper_TInputTextBuilderSystem_Data });
    
    Data nsGraphicWrapper_TInputTextMakerSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TInputTextMakerSystem(); };
    nsGraphicWrapper_TInputTextMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TInputTextMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TInputTextMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextMakerSystem_Data, nsGraphicWrapper_TInputTextMakerSystem_Data });
    
    Data nsGraphicWrapper_TInputTextTerminatorSystem_Data;
    nsGraphicWrapper_TInputTextTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TInputTextTerminatorSystem(); };
    nsGraphicWrapper_TInputTextTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TInputTextTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TInputTextTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextTerminatorSystem_Data, nsGraphicWrapper_TInputTextTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TInputTextValueUpdaterSystem(); };
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TInputTextValueUpdaterSystem*)p; };
    auto rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data, nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TLabelBuilderSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TLabelBuilderSystem(); };
    nsGraphicWrapper_TLabelBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TLabelBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TLabelBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelBuilderSystem_Data, nsGraphicWrapper_TLabelBuilderSystem_Data });
    
    Data nsGraphicWrapper_TLabelMakerSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TLabelMakerSystem(); };
    nsGraphicWrapper_TLabelMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TLabelMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TLabelMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelMakerSystem_Data, nsGraphicWrapper_TLabelMakerSystem_Data });
    
    Data nsGraphicWrapper_TLabelTerminatorSystem_Data;
    nsGraphicWrapper_TLabelTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TLabelTerminatorSystem(); };
    nsGraphicWrapper_TLabelTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TLabelTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TLabelTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelTerminatorSystem_Data, nsGraphicWrapper_TLabelTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMainWindowBuilderSystem(); };
    nsGraphicWrapper_TMainWindowBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMainWindowBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TMainWindowBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowBuilderSystem_Data, nsGraphicWrapper_TMainWindowBuilderSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMainWindowMakerSystem(); };
    nsGraphicWrapper_TMainWindowMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMainWindowMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TMainWindowMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowMakerSystem_Data, nsGraphicWrapper_TMainWindowMakerSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowTerminatorSystem_Data;
    nsGraphicWrapper_TMainWindowTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMainWindowTerminatorSystem(); };
    nsGraphicWrapper_TMainWindowTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMainWindowTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TMainWindowTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowTerminatorSystem_Data, nsGraphicWrapper_TMainWindowTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMenuNodeBuilderSystem(); };
    nsGraphicWrapper_TMenuNodeBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMenuNodeBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TMenuNodeBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeBuilderSystem_Data, nsGraphicWrapper_TMenuNodeBuilderSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem(); };
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem(); };
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMenuNodeMakerSystem(); };
    nsGraphicWrapper_TMenuNodeMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMenuNodeMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TMenuNodeMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeMakerSystem_Data, nsGraphicWrapper_TMenuNodeMakerSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeTerminatorSystem_Data;
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TMenuNodeTerminatorSystem(); };
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TMenuNodeTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TMenuNodeTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeTerminatorSystem_Data, nsGraphicWrapper_TMenuNodeTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TOnAddUniverseContextSystem(); };
    nsGraphicWrapper_TOnAddUniverseContextSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TOnAddUniverseContextSystem*)p; };
    auto rtti_nsGraphicWrapper_TOnAddUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TOnAddUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TOnAddUniverseContextSystem_Data, nsGraphicWrapper_TOnAddUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data;
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TOnRemoveUniverseContextSystem(); };
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TOnRemoveUniverseContextSystem*)p; };
    auto rtti_nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TOnRemoveUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data, nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TTextureMakerSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTextureMakerSystem(); };
    nsGraphicWrapper_TTextureMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTextureMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TTextureMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureMakerSystem_Data, nsGraphicWrapper_TTextureMakerSystem_Data });
    
    Data nsGraphicWrapper_TTextureTerminatorSystem_Data;
    nsGraphicWrapper_TTextureTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTextureTerminatorSystem(); };
    nsGraphicWrapper_TTextureTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTextureTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TTextureTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureTerminatorSystem_Data, nsGraphicWrapper_TTextureTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTitleUpdaterSystem(); };
    nsGraphicWrapper_TTitleUpdaterSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTitleUpdaterSystem*)p; };
    auto rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data, nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeNodeBuilderSystem(); };
    nsGraphicWrapper_TTreeNodeBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeNodeBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeNodeBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeBuilderSystem_Data, nsGraphicWrapper_TTreeNodeBuilderSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeNodeMakerSystem(); };
    nsGraphicWrapper_TTreeNodeMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeNodeMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeNodeMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeMakerSystem_Data, nsGraphicWrapper_TTreeNodeMakerSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeTerminatorSystem_Data;
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeNodeTerminatorSystem(); };
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeNodeTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeNodeTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeTerminatorSystem_Data, nsGraphicWrapper_TTreeNodeTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeViewBuilderSystem(); };
    nsGraphicWrapper_TTreeViewBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeViewBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeViewBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewBuilderSystem_Data, nsGraphicWrapper_TTreeViewBuilderSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeViewMakerSystem(); };
    nsGraphicWrapper_TTreeViewMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeViewMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeViewMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewMakerSystem_Data, nsGraphicWrapper_TTreeViewMakerSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewTerminatorSystem_Data;
    nsGraphicWrapper_TTreeViewTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TTreeViewTerminatorSystem(); };
    nsGraphicWrapper_TTreeViewTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTreeViewTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TTreeViewTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewTerminatorSystem_Data, nsGraphicWrapper_TTreeViewTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TWindowBuilderSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TWindowBuilderSystem(); };
    nsGraphicWrapper_TWindowBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TWindowBuilderSystem*)p; };
    auto rtti_nsGraphicWrapper_TWindowBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowBuilderSystem_Data, nsGraphicWrapper_TWindowBuilderSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem(); };
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem(); };
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TWindowMakerSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TWindowMakerSystem(); };
    nsGraphicWrapper_TWindowMakerSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TWindowMakerSystem*)p; };
    auto rtti_nsGraphicWrapper_TWindowMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowMakerSystem_Data, nsGraphicWrapper_TWindowMakerSystem_Data });
    
    Data nsGraphicWrapper_TWindowTerminatorSystem_Data;
    nsGraphicWrapper_TWindowTerminatorSystem_Data.newFunc = [](){ return new nsGraphicWrapper::TWindowTerminatorSystem(); };
    nsGraphicWrapper_TWindowTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TWindowTerminatorSystem*)p; };
    auto rtti_nsGraphicWrapper_TWindowTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowTerminatorSystem_Data, nsGraphicWrapper_TWindowTerminatorSystem_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_Data;
    nsLogicWrapper_TBeginLogicFeature_Data.newFunc = [](){ return new nsLogicWrapper::TBeginLogicFeature(); };
    nsLogicWrapper_TBeginLogicFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TBeginLogicFeature*)p; };
    auto rtti_nsLogicWrapper_TBeginLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TBeginLogicFeature_Data, nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_Data;
    nsLogicWrapper_TEndLogicFeature_Data.newFunc = [](){ return new nsLogicWrapper::TEndLogicFeature(); };
    nsLogicWrapper_TEndLogicFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TEndLogicFeature*)p; };
    auto rtti_nsLogicWrapper_TEndLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TEndLogicFeature_Data, nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.newFunc = [](){ return new nsLogicWrapper::THandlerCallCollectorNotifySystem(); };
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::THandlerCallCollectorNotifySystem*)p; };
    auto rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    m.insert({ rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data, nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_Data;
    nsLogicWrapper_TLogicBuilderFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicBuilderFeature(); };
    nsLogicWrapper_TLogicBuilderFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicBuilderFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicBuilderFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicBuilderFeature_Data, nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_Data;
    nsLogicWrapper_TLogicMakerFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicMakerFeature(); };
    nsLogicWrapper_TLogicMakerFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicMakerFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicMakerFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicMakerFeature_Data, nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsLogicWrapper_TLogicTerminatorFeature_Data.newFunc = [](){ return new nsLogicWrapper::TLogicTerminatorFeature(); };
    nsLogicWrapper_TLogicTerminatorFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLogicTerminatorFeature*)p; };
    auto rtti_nsLogicWrapper_TLogicTerminatorFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicTerminatorFeature_Data, nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_Data.newFunc = [](){ return new nsLogicWrapper::TNeedDestroyObjectSystem(); };
    nsLogicWrapper_TNeedDestroyObjectSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TNeedDestroyObjectSystem*)p; };
    auto rtti_nsLogicWrapper_TNeedDestroyObjectSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TNeedDestroyObjectSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TNeedDestroyObjectSystem_Data, nsLogicWrapper_TNeedDestroyObjectSystem_Data });
    
    Data nsLogicWrapper_TObjectFeature_Data;
    nsLogicWrapper_TObjectFeature_Data.newFunc = [](){ return new nsLogicWrapper::TObjectFeature(); };
    nsLogicWrapper_TObjectFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TObjectFeature*)p; };
    auto rtti_nsLogicWrapper_TObjectFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectFeature_Data, nsLogicWrapper_TObjectFeature_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data.newFunc = [](){ return new nsLogicWrapper::TObjectInstanceEndHandlerBuilderSystem(); };
    nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TObjectInstanceEndHandlerBuilderSystem*)p; };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerBuilderSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data.newFunc = [](){ return new nsLogicWrapper::TObjectInstanceEndHandlerMakerSystem(); };
    nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TObjectInstanceEndHandlerMakerSystem*)p; };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerMakerSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data.newFunc = [](){ return new nsLogicWrapper::TObjectInstanceEndHandlerTerminatorSystem(); };
    nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TObjectInstanceEndHandlerTerminatorSystem*)p; };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data });
    
    Data nsLogicWrapper_TSceneFeature_Data;
    nsLogicWrapper_TSceneFeature_Data.newFunc = [](){ return new nsLogicWrapper::TSceneFeature(); };
    nsLogicWrapper_TSceneFeature_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSceneFeature*)p; };
    auto rtti_nsLogicWrapper_TSceneFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneFeature_Data, nsLogicWrapper_TSceneFeature_Data });
    
    Data nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_Data.newFunc = [](){ return new nsLogicWrapper::TStartedScenesInitSystem(); };
    nsLogicWrapper_TStartedScenesInitSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TStartedScenesInitSystem*)p; };
    auto rtti_nsLogicWrapper_TStartedScenesInitSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TStartedScenesInitSystem_Data, nsLogicWrapper_TStartedScenesInitSystem_Data });
    
    Data nsLogicWrapper_TSystemBuilderSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_Data.newFunc = [](){ return new nsLogicWrapper::TSystemBuilderSystem(); };
    nsLogicWrapper_TSystemBuilderSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSystemBuilderSystem*)p; };
    auto rtti_nsLogicWrapper_TSystemBuilderSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemBuilderSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemBuilderSystem_Data, nsLogicWrapper_TSystemBuilderSystem_Data });
    
    Data nsLogicWrapper_TSystemMakerSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_Data.newFunc = [](){ return new nsLogicWrapper::TSystemMakerSystem(); };
    nsLogicWrapper_TSystemMakerSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSystemMakerSystem*)p; };
    auto rtti_nsLogicWrapper_TSystemMakerSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemMakerSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemMakerSystem_Data, nsLogicWrapper_TSystemMakerSystem_Data });
    
    Data nsLogicWrapper_TSystemTerminatorSystem_Data;
    nsLogicWrapper_TSystemTerminatorSystem_Data.newFunc = [](){ return new nsLogicWrapper::TSystemTerminatorSystem(); };
    nsLogicWrapper_TSystemTerminatorSystem_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSystemTerminatorSystem*)p; };
    auto rtti_nsLogicWrapper_TSystemTerminatorSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemTerminatorSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemTerminatorSystem_Data, nsLogicWrapper_TSystemTerminatorSystem_Data });
    
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
void* TFeatureTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TFeatureTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TFeatureTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
