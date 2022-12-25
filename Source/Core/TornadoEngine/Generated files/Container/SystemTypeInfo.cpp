/*
Core System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_24 21:59:44.787
	
#include "SystemTypeInfo.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::list<std::string> TSystemTypeInfo::mTypeNameList;
std::list<int> TSystemTypeInfo::mRttiList;

std::vector<std::string> TSystemTypeInfo::mNameVector;
std::map<std::string, int> TSystemTypeInfo::mNameRttiMap;

void TSystemTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsGraphicWrapper_TAddPropertiesFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TAddPropertiesFeature>();
    std::string nsGraphicWrapper_TAddPropertiesFeature_n = "nsGraphicWrapper::TAddPropertiesFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TAddPropertiesFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TAddPropertiesFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TAddPropertiesFeature_n, nsGraphicWrapper_TAddPropertiesFeature_i });
    
    int nsGraphicWrapper_TAnchorsAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TAnchorsAddSystem>();
    std::string nsGraphicWrapper_TAnchorsAddSystem_n = "nsGraphicWrapper::TAnchorsAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TAnchorsAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TAnchorsAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TAnchorsAddSystem_n, nsGraphicWrapper_TAnchorsAddSystem_i });
    
    int nsGraphicWrapper_TAnchorsUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TAnchorsUpdateSystem>();
    std::string nsGraphicWrapper_TAnchorsUpdateSystem_n = "nsGraphicWrapper::TAnchorsUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TAnchorsUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TAnchorsUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TAnchorsUpdateSystem_n, nsGraphicWrapper_TAnchorsUpdateSystem_i });
    
    int nsGraphicWrapper_TBeginGraphicFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    std::string nsGraphicWrapper_TBeginGraphicFeature_n = "nsGraphicWrapper::TBeginGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TBeginGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TBeginGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TBeginGraphicFeature_n, nsGraphicWrapper_TBeginGraphicFeature_i });
    
    int nsGraphicWrapper_TButtonBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonBuilderSystem>();
    std::string nsGraphicWrapper_TButtonBuilderSystem_n = "nsGraphicWrapper::TButtonBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TButtonBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TButtonBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TButtonBuilderSystem_n, nsGraphicWrapper_TButtonBuilderSystem_i });
    
    int nsGraphicWrapper_TButtonClickHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerMakerSystem>();
    std::string nsGraphicWrapper_TButtonClickHandlerMakerSystem_n = "nsGraphicWrapper::TButtonClickHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TButtonClickHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TButtonClickHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TButtonClickHandlerMakerSystem_n, nsGraphicWrapper_TButtonClickHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonClickHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_n = "nsGraphicWrapper::TButtonClickHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_n, nsGraphicWrapper_TButtonClickHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TButtonMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonMakerSystem>();
    std::string nsGraphicWrapper_TButtonMakerSystem_n = "nsGraphicWrapper::TButtonMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TButtonMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TButtonMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TButtonMakerSystem_n, nsGraphicWrapper_TButtonMakerSystem_i });
    
    int nsGraphicWrapper_TButtonTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TButtonTerminatorSystem>();
    std::string nsGraphicWrapper_TButtonTerminatorSystem_n = "nsGraphicWrapper::TButtonTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TButtonTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TButtonTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TButtonTerminatorSystem_n, nsGraphicWrapper_TButtonTerminatorSystem_i });
    
    int nsGraphicWrapper_TCameraBuilderFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    std::string nsGraphicWrapper_TCameraBuilderFeature_n = "nsGraphicWrapper::TCameraBuilderFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraBuilderFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraBuilderFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraBuilderFeature_n, nsGraphicWrapper_TCameraBuilderFeature_i });
    
    int nsGraphicWrapper_TCameraMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraMakerSystem>();
    std::string nsGraphicWrapper_TCameraMakerSystem_n = "nsGraphicWrapper::TCameraMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraMakerSystem_n, nsGraphicWrapper_TCameraMakerSystem_i });
    
    int nsGraphicWrapper_TCameraTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTerminatorSystem>();
    std::string nsGraphicWrapper_TCameraTerminatorSystem_n = "nsGraphicWrapper::TCameraTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraTerminatorSystem_n, nsGraphicWrapper_TCameraTerminatorSystem_i });
    
    int nsGraphicWrapper_TCameraUpdaterToModuleSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    std::string nsGraphicWrapper_TCameraUpdaterToModuleSystem_n = "nsGraphicWrapper::TCameraUpdaterToModuleSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraUpdaterToModuleSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraUpdaterToModuleSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraUpdaterToModuleSystem_n, nsGraphicWrapper_TCameraUpdaterToModuleSystem_i });
    
    int nsGraphicWrapper_TCleanUpUniverseContextSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    std::string nsGraphicWrapper_TCleanUpUniverseContextSystem_n = "nsGraphicWrapper::TCleanUpUniverseContextSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCleanUpUniverseContextSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCleanUpUniverseContextSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCleanUpUniverseContextSystem_n, nsGraphicWrapper_TCleanUpUniverseContextSystem_i });
    
    int nsGraphicWrapper_TDialogBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogBuilderSystem>();
    std::string nsGraphicWrapper_TDialogBuilderSystem_n = "nsGraphicWrapper::TDialogBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TDialogBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TDialogBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TDialogBuilderSystem_n, nsGraphicWrapper_TDialogBuilderSystem_i });
    
    int nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem>();
    std::string nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_n = "nsGraphicWrapper::TDialogCloseEventHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_n, nsGraphicWrapper_TDialogCloseEventHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_n = "nsGraphicWrapper::TDialogCloseEventHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_n, nsGraphicWrapper_TDialogCloseEventHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TDialogMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogMakerSystem>();
    std::string nsGraphicWrapper_TDialogMakerSystem_n = "nsGraphicWrapper::TDialogMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TDialogMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TDialogMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TDialogMakerSystem_n, nsGraphicWrapper_TDialogMakerSystem_i });
    
    int nsGraphicWrapper_TDialogTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TDialogTerminatorSystem>();
    std::string nsGraphicWrapper_TDialogTerminatorSystem_n = "nsGraphicWrapper::TDialogTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TDialogTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TDialogTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TDialogTerminatorSystem_n, nsGraphicWrapper_TDialogTerminatorSystem_i });
    
    int nsGraphicWrapper_TEndGraphicFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    std::string nsGraphicWrapper_TEndGraphicFeature_n = "nsGraphicWrapper::TEndGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TEndGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TEndGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TEndGraphicFeature_n, nsGraphicWrapper_TEndGraphicFeature_i });
    
    int nsGraphicWrapper_TFocusAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFocusAddSystem>();
    std::string nsGraphicWrapper_TFocusAddSystem_n = "nsGraphicWrapper::TFocusAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFocusAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFocusAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFocusAddSystem_n, nsGraphicWrapper_TFocusAddSystem_i });
    
    int nsGraphicWrapper_TFocusUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFocusUpdateSystem>();
    std::string nsGraphicWrapper_TFocusUpdateSystem_n = "nsGraphicWrapper::TFocusUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFocusUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFocusUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFocusUpdateSystem_n, nsGraphicWrapper_TFocusUpdateSystem_i });
    
    int nsGraphicWrapper_TFrameKeyHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerMakerSystem>();
    std::string nsGraphicWrapper_TFrameKeyHandlerMakerSystem_n = "nsGraphicWrapper::TFrameKeyHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameKeyHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameKeyHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameKeyHandlerMakerSystem_n, nsGraphicWrapper_TFrameKeyHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_n = "nsGraphicWrapper::TFrameKeyHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_n, nsGraphicWrapper_TFrameKeyHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem>();
    std::string nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_n = "nsGraphicWrapper::TFrameMouseClickHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_n, nsGraphicWrapper_TFrameMouseClickHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_n = "nsGraphicWrapper::TFrameMouseClickHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_n, nsGraphicWrapper_TFrameMouseClickHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem>();
    std::string nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_n = "nsGraphicWrapper::TFrameMouseMoveHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_n, nsGraphicWrapper_TFrameMouseMoveHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_n = "nsGraphicWrapper::TFrameMouseMoveHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_n, nsGraphicWrapper_TFrameMouseMoveHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem>();
    std::string nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_n = "nsGraphicWrapper::TFrameMouseWheelHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_n, nsGraphicWrapper_TFrameMouseWheelHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_n = "nsGraphicWrapper::TFrameMouseWheelHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_n, nsGraphicWrapper_TFrameMouseWheelHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TGuiBuilderFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    std::string nsGraphicWrapper_TGuiBuilderFeature_n = "nsGraphicWrapper::TGuiBuilderFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiBuilderFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiBuilderFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiBuilderFeature_n, nsGraphicWrapper_TGuiBuilderFeature_i });
    
    int nsGraphicWrapper_TGuiCameraBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraBuilderSystem>();
    std::string nsGraphicWrapper_TGuiCameraBuilderSystem_n = "nsGraphicWrapper::TGuiCameraBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiCameraBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiCameraBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiCameraBuilderSystem_n, nsGraphicWrapper_TGuiCameraBuilderSystem_i });
    
    int nsGraphicWrapper_TGuiMakerFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    std::string nsGraphicWrapper_TGuiMakerFeature_n = "nsGraphicWrapper::TGuiMakerFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiMakerFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiMakerFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiMakerFeature_n, nsGraphicWrapper_TGuiMakerFeature_i });
    
    int nsGraphicWrapper_TGuiTerminatorFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    std::string nsGraphicWrapper_TGuiTerminatorFeature_n = "nsGraphicWrapper::TGuiTerminatorFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiTerminatorFeature_n, nsGraphicWrapper_TGuiTerminatorFeature_i });
    
    int nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    std::string nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n = "nsGraphicWrapper::TGuiUpdaterFromModuleFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i });
    
    int nsGraphicWrapper_TGuiUpdaterToModuleFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    std::string nsGraphicWrapper_TGuiUpdaterToModuleFeature_n = "nsGraphicWrapper::TGuiUpdaterToModuleFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiUpdaterToModuleFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiUpdaterToModuleFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_n, nsGraphicWrapper_TGuiUpdaterToModuleFeature_i });
    
    int nsGraphicWrapper_THorizontalAlignAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::THorizontalAlignAddSystem>();
    std::string nsGraphicWrapper_THorizontalAlignAddSystem_n = "nsGraphicWrapper::THorizontalAlignAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_THorizontalAlignAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_THorizontalAlignAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_THorizontalAlignAddSystem_n, nsGraphicWrapper_THorizontalAlignAddSystem_i });
    
    int nsGraphicWrapper_THorizontalAlignUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::THorizontalAlignUpdateSystem>();
    std::string nsGraphicWrapper_THorizontalAlignUpdateSystem_n = "nsGraphicWrapper::THorizontalAlignUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_THorizontalAlignUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_THorizontalAlignUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_THorizontalAlignUpdateSystem_n, nsGraphicWrapper_THorizontalAlignUpdateSystem_i });
    
    int nsGraphicWrapper_TInputTextBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextBuilderSystem>();
    std::string nsGraphicWrapper_TInputTextBuilderSystem_n = "nsGraphicWrapper::TInputTextBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TInputTextBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TInputTextBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TInputTextBuilderSystem_n, nsGraphicWrapper_TInputTextBuilderSystem_i });
    
    int nsGraphicWrapper_TInputTextMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextMakerSystem>();
    std::string nsGraphicWrapper_TInputTextMakerSystem_n = "nsGraphicWrapper::TInputTextMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TInputTextMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TInputTextMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TInputTextMakerSystem_n, nsGraphicWrapper_TInputTextMakerSystem_i });
    
    int nsGraphicWrapper_TInputTextTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextTerminatorSystem>();
    std::string nsGraphicWrapper_TInputTextTerminatorSystem_n = "nsGraphicWrapper::TInputTextTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TInputTextTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TInputTextTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TInputTextTerminatorSystem_n, nsGraphicWrapper_TInputTextTerminatorSystem_i });
    
    int nsGraphicWrapper_TInputTextValueUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    std::string nsGraphicWrapper_TInputTextValueUpdaterSystem_n = "nsGraphicWrapper::TInputTextValueUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TInputTextValueUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TInputTextValueUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_n, nsGraphicWrapper_TInputTextValueUpdaterSystem_i });
    
    int nsGraphicWrapper_TLabelBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelBuilderSystem>();
    std::string nsGraphicWrapper_TLabelBuilderSystem_n = "nsGraphicWrapper::TLabelBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TLabelBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TLabelBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TLabelBuilderSystem_n, nsGraphicWrapper_TLabelBuilderSystem_i });
    
    int nsGraphicWrapper_TLabelMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelMakerSystem>();
    std::string nsGraphicWrapper_TLabelMakerSystem_n = "nsGraphicWrapper::TLabelMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TLabelMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TLabelMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TLabelMakerSystem_n, nsGraphicWrapper_TLabelMakerSystem_i });
    
    int nsGraphicWrapper_TLabelTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TLabelTerminatorSystem>();
    std::string nsGraphicWrapper_TLabelTerminatorSystem_n = "nsGraphicWrapper::TLabelTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TLabelTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TLabelTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TLabelTerminatorSystem_n, nsGraphicWrapper_TLabelTerminatorSystem_i });
    
    int nsGraphicWrapper_TMainWindowBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowBuilderSystem>();
    std::string nsGraphicWrapper_TMainWindowBuilderSystem_n = "nsGraphicWrapper::TMainWindowBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMainWindowBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMainWindowBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMainWindowBuilderSystem_n, nsGraphicWrapper_TMainWindowBuilderSystem_i });
    
    int nsGraphicWrapper_TMainWindowMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowMakerSystem>();
    std::string nsGraphicWrapper_TMainWindowMakerSystem_n = "nsGraphicWrapper::TMainWindowMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMainWindowMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMainWindowMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMainWindowMakerSystem_n, nsGraphicWrapper_TMainWindowMakerSystem_i });
    
    int nsGraphicWrapper_TMainWindowTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMainWindowTerminatorSystem>();
    std::string nsGraphicWrapper_TMainWindowTerminatorSystem_n = "nsGraphicWrapper::TMainWindowTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMainWindowTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMainWindowTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMainWindowTerminatorSystem_n, nsGraphicWrapper_TMainWindowTerminatorSystem_i });
    
    int nsGraphicWrapper_TMaxSizeAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMaxSizeAddSystem>();
    std::string nsGraphicWrapper_TMaxSizeAddSystem_n = "nsGraphicWrapper::TMaxSizeAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMaxSizeAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMaxSizeAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMaxSizeAddSystem_n, nsGraphicWrapper_TMaxSizeAddSystem_i });
    
    int nsGraphicWrapper_TMaxSizeUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMaxSizeUpdateSystem>();
    std::string nsGraphicWrapper_TMaxSizeUpdateSystem_n = "nsGraphicWrapper::TMaxSizeUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMaxSizeUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMaxSizeUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMaxSizeUpdateSystem_n, nsGraphicWrapper_TMaxSizeUpdateSystem_i });
    
    int nsGraphicWrapper_TMenuNodeBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeBuilderSystem>();
    std::string nsGraphicWrapper_TMenuNodeBuilderSystem_n = "nsGraphicWrapper::TMenuNodeBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMenuNodeBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMenuNodeBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMenuNodeBuilderSystem_n, nsGraphicWrapper_TMenuNodeBuilderSystem_i });
    
    int nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem>();
    std::string nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_n = "nsGraphicWrapper::TMenuNodeClickHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_n, nsGraphicWrapper_TMenuNodeClickHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_n = "nsGraphicWrapper::TMenuNodeClickHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_n, nsGraphicWrapper_TMenuNodeClickHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TMenuNodeMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeMakerSystem>();
    std::string nsGraphicWrapper_TMenuNodeMakerSystem_n = "nsGraphicWrapper::TMenuNodeMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMenuNodeMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMenuNodeMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMenuNodeMakerSystem_n, nsGraphicWrapper_TMenuNodeMakerSystem_i });
    
    int nsGraphicWrapper_TMenuNodeTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMenuNodeTerminatorSystem>();
    std::string nsGraphicWrapper_TMenuNodeTerminatorSystem_n = "nsGraphicWrapper::TMenuNodeTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMenuNodeTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMenuNodeTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMenuNodeTerminatorSystem_n, nsGraphicWrapper_TMenuNodeTerminatorSystem_i });
    
    int nsGraphicWrapper_TMinDistanceToParentAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMinDistanceToParentAddSystem>();
    std::string nsGraphicWrapper_TMinDistanceToParentAddSystem_n = "nsGraphicWrapper::TMinDistanceToParentAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMinDistanceToParentAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMinDistanceToParentAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMinDistanceToParentAddSystem_n, nsGraphicWrapper_TMinDistanceToParentAddSystem_i });
    
    int nsGraphicWrapper_TMinDistanceToParentUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMinDistanceToParentUpdateSystem>();
    std::string nsGraphicWrapper_TMinDistanceToParentUpdateSystem_n = "nsGraphicWrapper::TMinDistanceToParentUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMinDistanceToParentUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMinDistanceToParentUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMinDistanceToParentUpdateSystem_n, nsGraphicWrapper_TMinDistanceToParentUpdateSystem_i });
    
    int nsGraphicWrapper_TMinSizeAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMinSizeAddSystem>();
    std::string nsGraphicWrapper_TMinSizeAddSystem_n = "nsGraphicWrapper::TMinSizeAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMinSizeAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMinSizeAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMinSizeAddSystem_n, nsGraphicWrapper_TMinSizeAddSystem_i });
    
    int nsGraphicWrapper_TMinSizeUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TMinSizeUpdateSystem>();
    std::string nsGraphicWrapper_TMinSizeUpdateSystem_n = "nsGraphicWrapper::TMinSizeUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TMinSizeUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TMinSizeUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TMinSizeUpdateSystem_n, nsGraphicWrapper_TMinSizeUpdateSystem_i });
    
    int nsGraphicWrapper_TOnAddUniverseContextSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TOnAddUniverseContextSystem>();
    std::string nsGraphicWrapper_TOnAddUniverseContextSystem_n = "nsGraphicWrapper::TOnAddUniverseContextSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TOnAddUniverseContextSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TOnAddUniverseContextSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TOnAddUniverseContextSystem_n, nsGraphicWrapper_TOnAddUniverseContextSystem_i });
    
    int nsGraphicWrapper_TOnRemoveUniverseContextSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TOnRemoveUniverseContextSystem>();
    std::string nsGraphicWrapper_TOnRemoveUniverseContextSystem_n = "nsGraphicWrapper::TOnRemoveUniverseContextSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TOnRemoveUniverseContextSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TOnRemoveUniverseContextSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TOnRemoveUniverseContextSystem_n, nsGraphicWrapper_TOnRemoveUniverseContextSystem_i });
    
    int nsGraphicWrapper_TPositionAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionAddSystem>();
    std::string nsGraphicWrapper_TPositionAddSystem_n = "nsGraphicWrapper::TPositionAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TPositionAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TPositionAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TPositionAddSystem_n, nsGraphicWrapper_TPositionAddSystem_i });
    
    int nsGraphicWrapper_TPositionUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdateSystem>();
    std::string nsGraphicWrapper_TPositionUpdateSystem_n = "nsGraphicWrapper::TPositionUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TPositionUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TPositionUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TPositionUpdateSystem_n, nsGraphicWrapper_TPositionUpdateSystem_i });
    
    int nsGraphicWrapper_TPositionUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    std::string nsGraphicWrapper_TPositionUpdaterSystem_n = "nsGraphicWrapper::TPositionUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TPositionUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TPositionUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TPositionUpdaterSystem_n, nsGraphicWrapper_TPositionUpdaterSystem_i });
    
    int nsGraphicWrapper_TSizeAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TSizeAddSystem>();
    std::string nsGraphicWrapper_TSizeAddSystem_n = "nsGraphicWrapper::TSizeAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TSizeAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TSizeAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TSizeAddSystem_n, nsGraphicWrapper_TSizeAddSystem_i });
    
    int nsGraphicWrapper_TSizeUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TSizeUpdateSystem>();
    std::string nsGraphicWrapper_TSizeUpdateSystem_n = "nsGraphicWrapper::TSizeUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TSizeUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TSizeUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TSizeUpdateSystem_n, nsGraphicWrapper_TSizeUpdateSystem_i });
    
    int nsGraphicWrapper_TTextureMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureMakerSystem>();
    std::string nsGraphicWrapper_TTextureMakerSystem_n = "nsGraphicWrapper::TTextureMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTextureMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTextureMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTextureMakerSystem_n, nsGraphicWrapper_TTextureMakerSystem_i });
    
    int nsGraphicWrapper_TTextureTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureTerminatorSystem>();
    std::string nsGraphicWrapper_TTextureTerminatorSystem_n = "nsGraphicWrapper::TTextureTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTextureTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTextureTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTextureTerminatorSystem_n, nsGraphicWrapper_TTextureTerminatorSystem_i });
    
    int nsGraphicWrapper_TTitleAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleAddSystem>();
    std::string nsGraphicWrapper_TTitleAddSystem_n = "nsGraphicWrapper::TTitleAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTitleAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTitleAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTitleAddSystem_n, nsGraphicWrapper_TTitleAddSystem_i });
    
    int nsGraphicWrapper_TTitleUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdateSystem>();
    std::string nsGraphicWrapper_TTitleUpdateSystem_n = "nsGraphicWrapper::TTitleUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTitleUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTitleUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTitleUpdateSystem_n, nsGraphicWrapper_TTitleUpdateSystem_i });
    
    int nsGraphicWrapper_TTitleUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    std::string nsGraphicWrapper_TTitleUpdaterSystem_n = "nsGraphicWrapper::TTitleUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTitleUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTitleUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTitleUpdaterSystem_n, nsGraphicWrapper_TTitleUpdaterSystem_i });
    
    int nsGraphicWrapper_TTreeNodeBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeBuilderSystem>();
    std::string nsGraphicWrapper_TTreeNodeBuilderSystem_n = "nsGraphicWrapper::TTreeNodeBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeNodeBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeNodeBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeNodeBuilderSystem_n, nsGraphicWrapper_TTreeNodeBuilderSystem_i });
    
    int nsGraphicWrapper_TTreeNodeMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeMakerSystem>();
    std::string nsGraphicWrapper_TTreeNodeMakerSystem_n = "nsGraphicWrapper::TTreeNodeMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeNodeMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeNodeMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeNodeMakerSystem_n, nsGraphicWrapper_TTreeNodeMakerSystem_i });
    
    int nsGraphicWrapper_TTreeNodeTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeNodeTerminatorSystem>();
    std::string nsGraphicWrapper_TTreeNodeTerminatorSystem_n = "nsGraphicWrapper::TTreeNodeTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeNodeTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeNodeTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeNodeTerminatorSystem_n, nsGraphicWrapper_TTreeNodeTerminatorSystem_i });
    
    int nsGraphicWrapper_TTreeViewBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewBuilderSystem>();
    std::string nsGraphicWrapper_TTreeViewBuilderSystem_n = "nsGraphicWrapper::TTreeViewBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeViewBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeViewBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeViewBuilderSystem_n, nsGraphicWrapper_TTreeViewBuilderSystem_i });
    
    int nsGraphicWrapper_TTreeViewMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewMakerSystem>();
    std::string nsGraphicWrapper_TTreeViewMakerSystem_n = "nsGraphicWrapper::TTreeViewMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeViewMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeViewMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeViewMakerSystem_n, nsGraphicWrapper_TTreeViewMakerSystem_i });
    
    int nsGraphicWrapper_TTreeViewTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTreeViewTerminatorSystem>();
    std::string nsGraphicWrapper_TTreeViewTerminatorSystem_n = "nsGraphicWrapper::TTreeViewTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTreeViewTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTreeViewTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTreeViewTerminatorSystem_n, nsGraphicWrapper_TTreeViewTerminatorSystem_i });
    
    int nsGraphicWrapper_TUpdatePropertiesFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TUpdatePropertiesFeature>();
    std::string nsGraphicWrapper_TUpdatePropertiesFeature_n = "nsGraphicWrapper::TUpdatePropertiesFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TUpdatePropertiesFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TUpdatePropertiesFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TUpdatePropertiesFeature_n, nsGraphicWrapper_TUpdatePropertiesFeature_i });
    
    int nsGraphicWrapper_TVerticalAlignAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TVerticalAlignAddSystem>();
    std::string nsGraphicWrapper_TVerticalAlignAddSystem_n = "nsGraphicWrapper::TVerticalAlignAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TVerticalAlignAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TVerticalAlignAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TVerticalAlignAddSystem_n, nsGraphicWrapper_TVerticalAlignAddSystem_i });
    
    int nsGraphicWrapper_TVerticalAlignUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TVerticalAlignUpdateSystem>();
    std::string nsGraphicWrapper_TVerticalAlignUpdateSystem_n = "nsGraphicWrapper::TVerticalAlignUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TVerticalAlignUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TVerticalAlignUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TVerticalAlignUpdateSystem_n, nsGraphicWrapper_TVerticalAlignUpdateSystem_i });
    
    int nsGraphicWrapper_TVisibilityAddSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TVisibilityAddSystem>();
    std::string nsGraphicWrapper_TVisibilityAddSystem_n = "nsGraphicWrapper::TVisibilityAddSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TVisibilityAddSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TVisibilityAddSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TVisibilityAddSystem_n, nsGraphicWrapper_TVisibilityAddSystem_i });
    
    int nsGraphicWrapper_TVisibilityUpdateSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TVisibilityUpdateSystem>();
    std::string nsGraphicWrapper_TVisibilityUpdateSystem_n = "nsGraphicWrapper::TVisibilityUpdateSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TVisibilityUpdateSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TVisibilityUpdateSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TVisibilityUpdateSystem_n, nsGraphicWrapper_TVisibilityUpdateSystem_i });
    
    int nsGraphicWrapper_TWindowBuilderSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowBuilderSystem>();
    std::string nsGraphicWrapper_TWindowBuilderSystem_n = "nsGraphicWrapper::TWindowBuilderSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TWindowBuilderSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TWindowBuilderSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TWindowBuilderSystem_n, nsGraphicWrapper_TWindowBuilderSystem_i });
    
    int nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem>();
    std::string nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_n = "nsGraphicWrapper::TWindowCloseEventHandlerMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_n, nsGraphicWrapper_TWindowCloseEventHandlerMakerSystem_i });
    
    int nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem>();
    std::string nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_n = "nsGraphicWrapper::TWindowCloseEventHandlerTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_n, nsGraphicWrapper_TWindowCloseEventHandlerTerminatorSystem_i });
    
    int nsGraphicWrapper_TWindowMakerSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowMakerSystem>();
    std::string nsGraphicWrapper_TWindowMakerSystem_n = "nsGraphicWrapper::TWindowMakerSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TWindowMakerSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TWindowMakerSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TWindowMakerSystem_n, nsGraphicWrapper_TWindowMakerSystem_i });
    
    int nsGraphicWrapper_TWindowTerminatorSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TWindowTerminatorSystem>();
    std::string nsGraphicWrapper_TWindowTerminatorSystem_n = "nsGraphicWrapper::TWindowTerminatorSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TWindowTerminatorSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TWindowTerminatorSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TWindowTerminatorSystem_n, nsGraphicWrapper_TWindowTerminatorSystem_i });
    
    int nsLogicWrapper_TBeginLogicFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    std::string nsLogicWrapper_TBeginLogicFeature_n = "nsLogicWrapper::TBeginLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TBeginLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TBeginLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TBeginLogicFeature_n, nsLogicWrapper_TBeginLogicFeature_i });
    
    int nsLogicWrapper_TEndLogicFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    std::string nsLogicWrapper_TEndLogicFeature_n = "nsLogicWrapper::TEndLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TEndLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TEndLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TEndLogicFeature_n, nsLogicWrapper_TEndLogicFeature_i });
    
    int nsLogicWrapper_THandlerCallCollectorNotifySystem_i = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    std::string nsLogicWrapper_THandlerCallCollectorNotifySystem_n = "nsLogicWrapper::THandlerCallCollectorNotifySystem";
    mTypeNameList.push_back(nsLogicWrapper_THandlerCallCollectorNotifySystem_n);
    mRttiList.push_back(nsLogicWrapper_THandlerCallCollectorNotifySystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_THandlerCallCollectorNotifySystem_n, nsLogicWrapper_THandlerCallCollectorNotifySystem_i });
    
    int nsLogicWrapper_TLogicBuilderFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    std::string nsLogicWrapper_TLogicBuilderFeature_n = "nsLogicWrapper::TLogicBuilderFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicBuilderFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicBuilderFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicBuilderFeature_n, nsLogicWrapper_TLogicBuilderFeature_i });
    
    int nsLogicWrapper_TLogicMakerFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    std::string nsLogicWrapper_TLogicMakerFeature_n = "nsLogicWrapper::TLogicMakerFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicMakerFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicMakerFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicMakerFeature_n, nsLogicWrapper_TLogicMakerFeature_i });
    
    int nsLogicWrapper_TLogicTerminatorFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    std::string nsLogicWrapper_TLogicTerminatorFeature_n = "nsLogicWrapper::TLogicTerminatorFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicTerminatorFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicTerminatorFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicTerminatorFeature_n, nsLogicWrapper_TLogicTerminatorFeature_i });
    
    int nsLogicWrapper_TNeedDestroyObjectSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TNeedDestroyObjectSystem>();
    std::string nsLogicWrapper_TNeedDestroyObjectSystem_n = "nsLogicWrapper::TNeedDestroyObjectSystem";
    mTypeNameList.push_back(nsLogicWrapper_TNeedDestroyObjectSystem_n);
    mRttiList.push_back(nsLogicWrapper_TNeedDestroyObjectSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TNeedDestroyObjectSystem_n, nsLogicWrapper_TNeedDestroyObjectSystem_i });
    
    int nsLogicWrapper_TObjectFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    std::string nsLogicWrapper_TObjectFeature_n = "nsLogicWrapper::TObjectFeature";
    mTypeNameList.push_back(nsLogicWrapper_TObjectFeature_n);
    mRttiList.push_back(nsLogicWrapper_TObjectFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TObjectFeature_n, nsLogicWrapper_TObjectFeature_i });
    
    int nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem>();
    std::string nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_n = "nsLogicWrapper::TObjectInstantiationCompletionHandlerBuilderSystem";
    mTypeNameList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_n);
    mRttiList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_n, nsLogicWrapper_TObjectInstantiationCompletionHandlerBuilderSystem_i });
    
    int nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem>();
    std::string nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_n = "nsLogicWrapper::TObjectInstantiationCompletionHandlerMakerSystem";
    mTypeNameList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_n);
    mRttiList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_n, nsLogicWrapper_TObjectInstantiationCompletionHandlerMakerSystem_i });
    
    int nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem>();
    std::string nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_n = "nsLogicWrapper::TObjectInstantiationCompletionHandlerTerminatorSystem";
    mTypeNameList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_n);
    mRttiList.push_back(nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_n, nsLogicWrapper_TObjectInstantiationCompletionHandlerTerminatorSystem_i });
    
    int nsLogicWrapper_TSceneFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    std::string nsLogicWrapper_TSceneFeature_n = "nsLogicWrapper::TSceneFeature";
    mTypeNameList.push_back(nsLogicWrapper_TSceneFeature_n);
    mRttiList.push_back(nsLogicWrapper_TSceneFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSceneFeature_n, nsLogicWrapper_TSceneFeature_i });
    
    int nsLogicWrapper_TStartedScenesInitSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    std::string nsLogicWrapper_TStartedScenesInitSystem_n = "nsLogicWrapper::TStartedScenesInitSystem";
    mTypeNameList.push_back(nsLogicWrapper_TStartedScenesInitSystem_n);
    mRttiList.push_back(nsLogicWrapper_TStartedScenesInitSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TStartedScenesInitSystem_n, nsLogicWrapper_TStartedScenesInitSystem_i });
    
    int nsLogicWrapper_TSystemBuilderSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TSystemBuilderSystem>();
    std::string nsLogicWrapper_TSystemBuilderSystem_n = "nsLogicWrapper::TSystemBuilderSystem";
    mTypeNameList.push_back(nsLogicWrapper_TSystemBuilderSystem_n);
    mRttiList.push_back(nsLogicWrapper_TSystemBuilderSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSystemBuilderSystem_n, nsLogicWrapper_TSystemBuilderSystem_i });
    
    int nsLogicWrapper_TSystemMakerSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TSystemMakerSystem>();
    std::string nsLogicWrapper_TSystemMakerSystem_n = "nsLogicWrapper::TSystemMakerSystem";
    mTypeNameList.push_back(nsLogicWrapper_TSystemMakerSystem_n);
    mRttiList.push_back(nsLogicWrapper_TSystemMakerSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSystemMakerSystem_n, nsLogicWrapper_TSystemMakerSystem_i });
    
    int nsLogicWrapper_TSystemTerminatorSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TSystemTerminatorSystem>();
    std::string nsLogicWrapper_TSystemTerminatorSystem_n = "nsLogicWrapper::TSystemTerminatorSystem";
    mTypeNameList.push_back(nsLogicWrapper_TSystemTerminatorSystem_n);
    mRttiList.push_back(nsLogicWrapper_TSystemTerminatorSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSystemTerminatorSystem_n, nsLogicWrapper_TSystemTerminatorSystem_i });
    
    int max = 0;
    for (auto& nameRtti : mNameRttiMap) {
        max = std::max(max, nameRtti.second);
    }
    mNameVector.resize(max + 1);
    for (auto& nameRtti : mNameRttiMap) {
        mNameVector[nameRtti.second] = nameRtti.first;
    }
}
//---------------------------------------------------------------------------------------
const std::list<std::string>* TSystemTypeInfo::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TSystemTypeInfo::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TSystemTypeInfo::ConvertRttiToName(int rtti)
{
    Init();
    
    if (rtti < 0 || rtti >= mNameVector.size()) {
        return nullptr;
    }
    auto pStr = &(mNameVector[rtti]);
    if (pStr->size() == 0) {
        return nullptr;
    }
    return pStr;
}
//---------------------------------------------------------------------------------------
bool TSystemTypeInfo::ConvertNameToRtti(const std::string& typeName, int& rtti)
{
    Init();
    auto fit = mNameRttiMap.find(typeName);
    if (fit == mNameRttiMap.end()) {
        return false;
    }
    rtti = fit->second;
    return true;
}
//---------------------------------------------------------------------------------------
