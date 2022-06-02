/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_06_02 06:53:49.197
	
#include "EcsSystemExtension.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<TEcsSystemExtension::Data> TEcsSystemExtension::mDataVector;
void TEcsSystemExtension::Init()
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
    nsGraphicWrapper_TBeginGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TBeginGraphicFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TBeginGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TBeginGraphicFeature_Data, nsGraphicWrapper_TBeginGraphicFeature_Data });
    
    Data nsGraphicWrapper_TButtonBuilderSystem_Data;
    nsGraphicWrapper_TButtonBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TButtonBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonBuilderSystem_Data, nsGraphicWrapper_TButtonBuilderSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data, nsGraphicWrapper_TButtonClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TButtonMakerSystem_Data;
    nsGraphicWrapper_TButtonMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TButtonMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonMakerSystem_Data, nsGraphicWrapper_TButtonMakerSystem_Data });
    
    Data nsGraphicWrapper_TButtonTerminatorSystem_Data;
    nsGraphicWrapper_TButtonTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TButtonTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TButtonTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TButtonTerminatorSystem_Data, nsGraphicWrapper_TButtonTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TCameraBuilderFeature_Data;
    nsGraphicWrapper_TCameraBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraBuilderFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraBuilderFeature_Data, nsGraphicWrapper_TCameraBuilderFeature_Data });
    
    Data nsGraphicWrapper_TCameraMakerSystem_Data;
    nsGraphicWrapper_TCameraMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraMakerSystem_Data, nsGraphicWrapper_TCameraMakerSystem_Data });
    
    Data nsGraphicWrapper_TCameraTerminatorSystem_Data;
    nsGraphicWrapper_TCameraTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraTerminatorSystem_Data, nsGraphicWrapper_TCameraTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data;
    nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCameraUpdaterToModuleSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data, nsGraphicWrapper_TCameraUpdaterToModuleSystem_Data });
    
    Data nsGraphicWrapper_TCleanUpUniverseContextSystem_Data;
    nsGraphicWrapper_TCleanUpUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TCleanUpUniverseContextSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TCleanUpUniverseContextSystem_Data, nsGraphicWrapper_TCleanUpUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TDialogBuilderSystem_Data;
    nsGraphicWrapper_TDialogBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TDialogBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogBuilderSystem_Data, nsGraphicWrapper_TDialogBuilderSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TDialogMakerSystem_Data;
    nsGraphicWrapper_TDialogMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TDialogMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogMakerSystem_Data, nsGraphicWrapper_TDialogMakerSystem_Data });
    
    Data nsGraphicWrapper_TDialogTerminatorSystem_Data;
    nsGraphicWrapper_TDialogTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TDialogTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TDialogTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TDialogTerminatorSystem_Data, nsGraphicWrapper_TDialogTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TEndGraphicFeature_Data;
    nsGraphicWrapper_TEndGraphicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TEndGraphicFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TEndGraphicFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TEndGraphicFeature_Data, nsGraphicWrapper_TEndGraphicFeature_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TGuiBuilderFeature_Data;
    nsGraphicWrapper_TGuiBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiBuilderFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiBuilderFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiBuilderFeature_Data, nsGraphicWrapper_TGuiBuilderFeature_Data });
    
    Data nsGraphicWrapper_TGuiCameraBuilderSystem_Data;
    nsGraphicWrapper_TGuiCameraBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiCameraBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiCameraBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiCameraBuilderSystem_Data, nsGraphicWrapper_TGuiCameraBuilderSystem_Data });
    
    Data nsGraphicWrapper_TGuiMakerFeature_Data;
    nsGraphicWrapper_TGuiMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiMakerFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiMakerFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiMakerFeature_Data, nsGraphicWrapper_TGuiMakerFeature_Data });
    
    Data nsGraphicWrapper_TGuiTerminatorFeature_Data;
    nsGraphicWrapper_TGuiTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiTerminatorFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiTerminatorFeature_Data, nsGraphicWrapper_TGuiTerminatorFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterFromModuleFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_Data });
    
    Data nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data;
    nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TGuiUpdaterToModuleFeature*>(p)); };
    auto rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data, nsGraphicWrapper_TGuiUpdaterToModuleFeature_Data });
    
    Data nsGraphicWrapper_TInputTextBuilderSystem_Data;
    nsGraphicWrapper_TInputTextBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TInputTextBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextBuilderSystem_Data, nsGraphicWrapper_TInputTextBuilderSystem_Data });
    
    Data nsGraphicWrapper_TInputTextMakerSystem_Data;
    nsGraphicWrapper_TInputTextMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TInputTextMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextMakerSystem_Data, nsGraphicWrapper_TInputTextMakerSystem_Data });
    
    Data nsGraphicWrapper_TInputTextTerminatorSystem_Data;
    nsGraphicWrapper_TInputTextTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TInputTextTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextTerminatorSystem_Data, nsGraphicWrapper_TInputTextTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TInputTextValueUpdaterSystem_Data;
    nsGraphicWrapper_TInputTextValueUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TInputTextValueUpdaterSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TInputTextValueUpdaterSystem_Data, nsGraphicWrapper_TInputTextValueUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TLabelBuilderSystem_Data;
    nsGraphicWrapper_TLabelBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TLabelBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelBuilderSystem_Data, nsGraphicWrapper_TLabelBuilderSystem_Data });
    
    Data nsGraphicWrapper_TLabelMakerSystem_Data;
    nsGraphicWrapper_TLabelMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TLabelMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelMakerSystem_Data, nsGraphicWrapper_TLabelMakerSystem_Data });
    
    Data nsGraphicWrapper_TLabelTerminatorSystem_Data;
    nsGraphicWrapper_TLabelTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TLabelTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TLabelTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TLabelTerminatorSystem_Data, nsGraphicWrapper_TLabelTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowBuilderSystem_Data;
    nsGraphicWrapper_TMainWindowBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMainWindowBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowBuilderSystem_Data, nsGraphicWrapper_TMainWindowBuilderSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowMakerSystem_Data;
    nsGraphicWrapper_TMainWindowMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMainWindowMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowMakerSystem_Data, nsGraphicWrapper_TMainWindowMakerSystem_Data });
    
    Data nsGraphicWrapper_TMainWindowTerminatorSystem_Data;
    nsGraphicWrapper_TMainWindowTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMainWindowTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMainWindowTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMainWindowTerminatorSystem_Data, nsGraphicWrapper_TMainWindowTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeBuilderSystem_Data;
    nsGraphicWrapper_TMenuNodeBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMenuNodeBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeBuilderSystem_Data, nsGraphicWrapper_TMenuNodeBuilderSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeMakerSystem_Data;
    nsGraphicWrapper_TMenuNodeMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMenuNodeMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeMakerSystem_Data, nsGraphicWrapper_TMenuNodeMakerSystem_Data });
    
    Data nsGraphicWrapper_TMenuNodeTerminatorSystem_Data;
    nsGraphicWrapper_TMenuNodeTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TMenuNodeTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TMenuNodeTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TMenuNodeTerminatorSystem_Data, nsGraphicWrapper_TMenuNodeTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TOnAddUniverseContextSystem_Data;
    nsGraphicWrapper_TOnAddUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TOnAddUniverseContextSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TOnAddUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TOnAddUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TOnAddUniverseContextSystem_Data, nsGraphicWrapper_TOnAddUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data;
    nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TOnRemoveUniverseContextSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TOnRemoveUniverseContextSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data, nsGraphicWrapper_TOnRemoveUniverseContextSystem_Data });
    
    Data nsGraphicWrapper_TTextureMakerSystem_Data;
    nsGraphicWrapper_TTextureMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTextureMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTextureMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureMakerSystem_Data, nsGraphicWrapper_TTextureMakerSystem_Data });
    
    Data nsGraphicWrapper_TTextureTerminatorSystem_Data;
    nsGraphicWrapper_TTextureTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTextureTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTextureTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureTerminatorSystem_Data, nsGraphicWrapper_TTextureTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TTitleUpdaterSystem_Data;
    nsGraphicWrapper_TTitleUpdaterSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTitleUpdaterSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTitleUpdaterSystem_Data, nsGraphicWrapper_TTitleUpdaterSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeBuilderSystem_Data;
    nsGraphicWrapper_TTreeNodeBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeNodeBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeBuilderSystem_Data, nsGraphicWrapper_TTreeNodeBuilderSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeMakerSystem_Data;
    nsGraphicWrapper_TTreeNodeMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeNodeMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeMakerSystem_Data, nsGraphicWrapper_TTreeNodeMakerSystem_Data });
    
    Data nsGraphicWrapper_TTreeNodeTerminatorSystem_Data;
    nsGraphicWrapper_TTreeNodeTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeNodeTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeNodeTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeNodeTerminatorSystem_Data, nsGraphicWrapper_TTreeNodeTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewBuilderSystem_Data;
    nsGraphicWrapper_TTreeViewBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeViewBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewBuilderSystem_Data, nsGraphicWrapper_TTreeViewBuilderSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewMakerSystem_Data;
    nsGraphicWrapper_TTreeViewMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeViewMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewMakerSystem_Data, nsGraphicWrapper_TTreeViewMakerSystem_Data });
    
    Data nsGraphicWrapper_TTreeViewTerminatorSystem_Data;
    nsGraphicWrapper_TTreeViewTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TTreeViewTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TTreeViewTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TTreeViewTerminatorSystem_Data, nsGraphicWrapper_TTreeViewTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TWindowBuilderSystem_Data;
    nsGraphicWrapper_TWindowBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowBuilderSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TWindowBuilderSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowBuilderSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowBuilderSystem_Data, nsGraphicWrapper_TWindowBuilderSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_Data });
    
    Data nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data;
    nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_Data });
    
    Data nsGraphicWrapper_TWindowMakerSystem_Data;
    nsGraphicWrapper_TWindowMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowMakerSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TWindowMakerSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowMakerSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowMakerSystem_Data, nsGraphicWrapper_TWindowMakerSystem_Data });
    
    Data nsGraphicWrapper_TWindowTerminatorSystem_Data;
    nsGraphicWrapper_TWindowTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsGraphicWrapper::TWindowTerminatorSystem*>(p)); };
    auto rtti_nsGraphicWrapper_TWindowTerminatorSystem_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowTerminatorSystem>();
    
    m.insert({ rtti_nsGraphicWrapper_TWindowTerminatorSystem_Data, nsGraphicWrapper_TWindowTerminatorSystem_Data });
    
    Data nsLogicWrapper_TBeginLogicFeature_Data;
    nsLogicWrapper_TBeginLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TBeginLogicFeature*>(p)); };
    auto rtti_nsLogicWrapper_TBeginLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TBeginLogicFeature_Data, nsLogicWrapper_TBeginLogicFeature_Data });
    
    Data nsLogicWrapper_TEndLogicFeature_Data;
    nsLogicWrapper_TEndLogicFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TEndLogicFeature*>(p)); };
    auto rtti_nsLogicWrapper_TEndLogicFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TEndLogicFeature_Data, nsLogicWrapper_TEndLogicFeature_Data });
    
    Data nsLogicWrapper_THandlerCallCollectorNotifySystem_Data;
    nsLogicWrapper_THandlerCallCollectorNotifySystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::THandlerCallCollectorNotifySystem*>(p)); };
    auto rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    
    m.insert({ rtti_nsLogicWrapper_THandlerCallCollectorNotifySystem_Data, nsLogicWrapper_THandlerCallCollectorNotifySystem_Data });
    
    Data nsLogicWrapper_TLogicBuilderFeature_Data;
    nsLogicWrapper_TLogicBuilderFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicBuilderFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicBuilderFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicBuilderFeature_Data, nsLogicWrapper_TLogicBuilderFeature_Data });
    
    Data nsLogicWrapper_TLogicMakerFeature_Data;
    nsLogicWrapper_TLogicMakerFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicMakerFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicMakerFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicMakerFeature_Data, nsLogicWrapper_TLogicMakerFeature_Data });
    
    Data nsLogicWrapper_TLogicTerminatorFeature_Data;
    nsLogicWrapper_TLogicTerminatorFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TLogicTerminatorFeature*>(p)); };
    auto rtti_nsLogicWrapper_TLogicTerminatorFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TLogicTerminatorFeature_Data, nsLogicWrapper_TLogicTerminatorFeature_Data });
    
    Data nsLogicWrapper_TNeedDestroyObjectSystem_Data;
    nsLogicWrapper_TNeedDestroyObjectSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TNeedDestroyObjectSystem*>(p)); };
    auto rtti_nsLogicWrapper_TNeedDestroyObjectSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TNeedDestroyObjectSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TNeedDestroyObjectSystem_Data, nsLogicWrapper_TNeedDestroyObjectSystem_Data });
    
    Data nsLogicWrapper_TObjectFeature_Data;
    nsLogicWrapper_TObjectFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectFeature*>(p)); };
    auto rtti_nsLogicWrapper_TObjectFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectFeature_Data, nsLogicWrapper_TObjectFeature_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstanceEndHandlerBuilderSystem*>(p)); };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerBuilderSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerBuilderSystem_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstanceEndHandlerMakerSystem*>(p)); };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerMakerSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerMakerSystem_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data;
    nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TObjectInstanceEndHandlerTerminatorSystem*>(p)); };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerTerminatorSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data, nsLogicWrapper_TObjectInstanceEndHandlerTerminatorSystem_Data });
    
    Data nsLogicWrapper_TSceneFeature_Data;
    nsLogicWrapper_TSceneFeature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSceneFeature*>(p)); };
    auto rtti_nsLogicWrapper_TSceneFeature_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneFeature_Data, nsLogicWrapper_TSceneFeature_Data });
    
    Data nsLogicWrapper_TStartedScenesInitSystem_Data;
    nsLogicWrapper_TStartedScenesInitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TStartedScenesInitSystem*>(p)); };
    auto rtti_nsLogicWrapper_TStartedScenesInitSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TStartedScenesInitSystem_Data, nsLogicWrapper_TStartedScenesInitSystem_Data });
    
    Data nsLogicWrapper_TSystemBuilderSystem_Data;
    nsLogicWrapper_TSystemBuilderSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemBuilderSystem*>(p)); };
    auto rtti_nsLogicWrapper_TSystemBuilderSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemBuilderSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemBuilderSystem_Data, nsLogicWrapper_TSystemBuilderSystem_Data });
    
    Data nsLogicWrapper_TSystemMakerSystem_Data;
    nsLogicWrapper_TSystemMakerSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemMakerSystem*>(p)); };
    auto rtti_nsLogicWrapper_TSystemMakerSystem_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemMakerSystem>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemMakerSystem_Data, nsLogicWrapper_TSystemMakerSystem_Data });
    
    Data nsLogicWrapper_TSystemTerminatorSystem_Data;
    nsLogicWrapper_TSystemTerminatorSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<nsLogicWrapper::TSystemTerminatorSystem*>(p)); };
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
nsECSFramework::TSystem* TEcsSystemExtension::DynamicCast(void* p, int rtti)
{
    Init();
    return mDataVector[rtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
