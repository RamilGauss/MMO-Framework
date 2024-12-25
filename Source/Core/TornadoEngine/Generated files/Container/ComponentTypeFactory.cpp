/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_25 11:43:17.755
#include "ComponentTypeFactory.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<TComponentTypeFactory::Data> TComponentTypeFactory::mDataVector;
void TComponentTypeFactory::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<Data> datas;
    
    Data nsCommonWrapper_TGlobalMatrixComponent_Data;
    nsCommonWrapper_TGlobalMatrixComponent_Data.newFunc = [](){ return new nsCommonWrapper::TGlobalMatrixComponent(); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TGlobalMatrixComponent*)p; };
    nsCommonWrapper_TGlobalMatrixComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    datas.push_back(nsCommonWrapper_TGlobalMatrixComponent_Data);
    
    Data nsCommonWrapper_TGuidComponent_Data;
    nsCommonWrapper_TGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TGuidComponent(); };
    nsCommonWrapper_TGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TGuidComponent*)p; };
    nsCommonWrapper_TGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TGuidComponent_Data);
    
    Data nsCommonWrapper_TNameComponent_Data;
    nsCommonWrapper_TNameComponent_Data.newFunc = [](){ return new nsCommonWrapper::TNameComponent(); };
    nsCommonWrapper_TNameComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TNameComponent*)p; };
    nsCommonWrapper_TNameComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    datas.push_back(nsCommonWrapper_TNameComponent_Data);
    
    Data nsCommonWrapper_TNeedDestroyObjectTagComponent_Data;
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.newFunc = [](){ return new nsCommonWrapper::TNeedDestroyObjectTagComponent(); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TNeedDestroyObjectTagComponent*)p; };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    datas.push_back(nsCommonWrapper_TNeedDestroyObjectTagComponent_Data);
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
    nsCommonWrapper_TParentGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TParentGuidComponent(); };
    nsCommonWrapper_TParentGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TParentGuidComponent*)p; };
    nsCommonWrapper_TParentGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TParentGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabGuidComponent_Data;
    nsCommonWrapper_TPrefabGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TPrefabGuidComponent(); };
    nsCommonWrapper_TPrefabGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TPrefabGuidComponent*)p; };
    nsCommonWrapper_TPrefabGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabInstanceGuidComponent_Data;
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TPrefabInstanceGuidComponent(); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TPrefabInstanceGuidComponent*)p; };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabInstanceGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabOriginalGuidComponent_Data;
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TPrefabOriginalGuidComponent(); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TPrefabOriginalGuidComponent*)p; };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabOriginalGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabRootComponent_Data;
    nsCommonWrapper_TPrefabRootComponent_Data.newFunc = [](){ return new nsCommonWrapper::TPrefabRootComponent(); };
    nsCommonWrapper_TPrefabRootComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TPrefabRootComponent*)p; };
    nsCommonWrapper_TPrefabRootComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabRootComponent_Data);
    
    Data nsCommonWrapper_TProjectionToUniverseComponent_Data;
    nsCommonWrapper_TProjectionToUniverseComponent_Data.newFunc = [](){ return new nsCommonWrapper::TProjectionToUniverseComponent(); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TProjectionToUniverseComponent*)p; };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    
    datas.push_back(nsCommonWrapper_TProjectionToUniverseComponent_Data);
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
    nsCommonWrapper_TSceneGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TSceneGuidComponent(); };
    nsCommonWrapper_TSceneGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TSceneGuidComponent*)p; };
    nsCommonWrapper_TSceneGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneInstanceGuidComponent_Data;
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TSceneInstanceGuidComponent(); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TSceneInstanceGuidComponent*)p; };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneInstanceGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneOriginalGuidComponent_Data;
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TSceneOriginalGuidComponent(); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TSceneOriginalGuidComponent*)p; };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneOriginalGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
    nsCommonWrapper_TSceneRootComponent_Data.newFunc = [](){ return new nsCommonWrapper::TSceneRootComponent(); };
    nsCommonWrapper_TSceneRootComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TSceneRootComponent*)p; };
    nsCommonWrapper_TSceneRootComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneRootComponent_Data);
    
    Data nsCommonWrapper_TUniverseGuidComponent_Data;
    nsCommonWrapper_TUniverseGuidComponent_Data.newFunc = [](){ return new nsCommonWrapper::TUniverseGuidComponent(); };
    nsCommonWrapper_TUniverseGuidComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TUniverseGuidComponent*)p; };
    nsCommonWrapper_TUniverseGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TUniverseGuidComponent_Data);
    
    Data nsCommonWrapper_TUniverseIndexComponent_Data;
    nsCommonWrapper_TUniverseIndexComponent_Data.newFunc = [](){ return new nsCommonWrapper::TUniverseIndexComponent(); };
    nsCommonWrapper_TUniverseIndexComponent_Data.deleteFunc = [](void* p){ delete (nsCommonWrapper::TUniverseIndexComponent*)p; };
    nsCommonWrapper_TUniverseIndexComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    datas.push_back(nsCommonWrapper_TUniverseIndexComponent_Data);
    
    Data nsGraphicWrapper_TCameraComponent_Data;
    nsGraphicWrapper_TCameraComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraComponent(); };
    nsGraphicWrapper_TCameraComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraComponent*)p; };
    nsGraphicWrapper_TCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraComponent_Data);
    
    Data nsGraphicWrapper_TCameraTextureTagComponent_Data;
    nsGraphicWrapper_TCameraTextureTagComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraTextureTagComponent(); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraTextureTagComponent*)p; };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraTextureTagComponent_Data);
    
    Data nsGraphicWrapper_TCameraWindowPositionComponent_Data;
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraWindowPositionComponent(); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraWindowPositionComponent*)p; };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraWindowPositionComponent_Data);
    
    Data nsGraphicWrapper_TCameraWindowSizeComponent_Data;
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TCameraWindowSizeComponent(); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TCameraWindowSizeComponent*)p; };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraWindowSizeComponent_Data);
    
    Data nsGraphicWrapper_TGuiCameraTagComponent_Data;
    nsGraphicWrapper_TGuiCameraTagComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TGuiCameraTagComponent(); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TGuiCameraTagComponent*)p; };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    datas.push_back(nsGraphicWrapper_TGuiCameraTagComponent_Data);
    
    Data nsGraphicWrapper_TLightComponent_Data;
    nsGraphicWrapper_TLightComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TLightComponent(); };
    nsGraphicWrapper_TLightComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TLightComponent*)p; };
    nsGraphicWrapper_TLightComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    datas.push_back(nsGraphicWrapper_TLightComponent_Data);
    
    Data nsGraphicWrapper_TRenderToTextureCameraComponent_Data;
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TRenderToTextureCameraComponent(); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TRenderToTextureCameraComponent*)p; };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TRenderToTextureCameraComponent_Data);
    
    Data nsGraphicWrapper_TTextureFromCameraComponent_Data;
    nsGraphicWrapper_TTextureFromCameraComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TTextureFromCameraComponent(); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTextureFromCameraComponent*)p; };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TTextureFromCameraComponent_Data);
    
    Data nsGraphicWrapper_TTextureFromFileComponent_Data;
    nsGraphicWrapper_TTextureFromFileComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TTextureFromFileComponent(); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TTextureFromFileComponent*)p; };
    nsGraphicWrapper_TTextureFromFileComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    datas.push_back(nsGraphicWrapper_TTextureFromFileComponent_Data);
    
    Data nsGraphicWrapper_TUniverseCameraComponent_Data;
    nsGraphicWrapper_TUniverseCameraComponent_Data.newFunc = [](){ return new nsGraphicWrapper::TUniverseCameraComponent(); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.deleteFunc = [](void* p){ delete (nsGraphicWrapper::TUniverseCameraComponent*)p; };
    nsGraphicWrapper_TUniverseCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TUniverseCameraComponent_Data);
    
    Data nsGuiWrapper_TAnchorsComponent_Data;
    nsGuiWrapper_TAnchorsComponent_Data.newFunc = [](){ return new nsGuiWrapper::TAnchorsComponent(); };
    nsGuiWrapper_TAnchorsComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TAnchorsComponent*)p; };
    nsGuiWrapper_TAnchorsComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    datas.push_back(nsGuiWrapper_TAnchorsComponent_Data);
    
    Data nsGuiWrapper_TButtonComponent_Data;
    nsGuiWrapper_TButtonComponent_Data.newFunc = [](){ return new nsGuiWrapper::TButtonComponent(); };
    nsGuiWrapper_TButtonComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TButtonComponent*)p; };
    nsGuiWrapper_TButtonComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    datas.push_back(nsGuiWrapper_TButtonComponent_Data);
    
    Data nsGuiWrapper_TColorComponent_Data;
    nsGuiWrapper_TColorComponent_Data.newFunc = [](){ return new nsGuiWrapper::TColorComponent(); };
    nsGuiWrapper_TColorComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TColorComponent*)p; };
    nsGuiWrapper_TColorComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    datas.push_back(nsGuiWrapper_TColorComponent_Data);
    
    Data nsGuiWrapper_TDialogComponent_Data;
    nsGuiWrapper_TDialogComponent_Data.newFunc = [](){ return new nsGuiWrapper::TDialogComponent(); };
    nsGuiWrapper_TDialogComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TDialogComponent*)p; };
    nsGuiWrapper_TDialogComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    datas.push_back(nsGuiWrapper_TDialogComponent_Data);
    
    Data nsGuiWrapper_TFocusComponent_Data;
    nsGuiWrapper_TFocusComponent_Data.newFunc = [](){ return new nsGuiWrapper::TFocusComponent(); };
    nsGuiWrapper_TFocusComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TFocusComponent*)p; };
    nsGuiWrapper_TFocusComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    datas.push_back(nsGuiWrapper_TFocusComponent_Data);
    
    Data nsGuiWrapper_TFrameComponent_Data;
    nsGuiWrapper_TFrameComponent_Data.newFunc = [](){ return new nsGuiWrapper::TFrameComponent(); };
    nsGuiWrapper_TFrameComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TFrameComponent*)p; };
    nsGuiWrapper_TFrameComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    datas.push_back(nsGuiWrapper_TFrameComponent_Data);
    
    Data nsGuiWrapper_TGridComponent_Data;
    nsGuiWrapper_TGridComponent_Data.newFunc = [](){ return new nsGuiWrapper::TGridComponent(); };
    nsGuiWrapper_TGridComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TGridComponent*)p; };
    nsGuiWrapper_TGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    datas.push_back(nsGuiWrapper_TGridComponent_Data);
    
    Data nsGuiWrapper_THorizontalAlignComponent_Data;
    nsGuiWrapper_THorizontalAlignComponent_Data.newFunc = [](){ return new nsGuiWrapper::THorizontalAlignComponent(); };
    nsGuiWrapper_THorizontalAlignComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::THorizontalAlignComponent*)p; };
    nsGuiWrapper_THorizontalAlignComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    datas.push_back(nsGuiWrapper_THorizontalAlignComponent_Data);
    
    Data nsGuiWrapper_TInputTextComponent_Data;
    nsGuiWrapper_TInputTextComponent_Data.newFunc = [](){ return new nsGuiWrapper::TInputTextComponent(); };
    nsGuiWrapper_TInputTextComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TInputTextComponent*)p; };
    nsGuiWrapper_TInputTextComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    datas.push_back(nsGuiWrapper_TInputTextComponent_Data);
    
    Data nsGuiWrapper_TInputTextValueComponent_Data;
    nsGuiWrapper_TInputTextValueComponent_Data.newFunc = [](){ return new nsGuiWrapper::TInputTextValueComponent(); };
    nsGuiWrapper_TInputTextValueComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TInputTextValueComponent*)p; };
    nsGuiWrapper_TInputTextValueComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    datas.push_back(nsGuiWrapper_TInputTextValueComponent_Data);
    
    Data nsGuiWrapper_TLabelComponent_Data;
    nsGuiWrapper_TLabelComponent_Data.newFunc = [](){ return new nsGuiWrapper::TLabelComponent(); };
    nsGuiWrapper_TLabelComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TLabelComponent*)p; };
    nsGuiWrapper_TLabelComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    datas.push_back(nsGuiWrapper_TLabelComponent_Data);
    
    Data nsGuiWrapper_TLabelValueComponent_Data;
    nsGuiWrapper_TLabelValueComponent_Data.newFunc = [](){ return new nsGuiWrapper::TLabelValueComponent(); };
    nsGuiWrapper_TLabelValueComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TLabelValueComponent*)p; };
    nsGuiWrapper_TLabelValueComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    datas.push_back(nsGuiWrapper_TLabelValueComponent_Data);
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
    nsGuiWrapper_TMainWindowComponent_Data.newFunc = [](){ return new nsGuiWrapper::TMainWindowComponent(); };
    nsGuiWrapper_TMainWindowComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TMainWindowComponent*)p; };
    nsGuiWrapper_TMainWindowComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    datas.push_back(nsGuiWrapper_TMainWindowComponent_Data);
    
    Data nsGuiWrapper_TMaxSizeComponent_Data;
    nsGuiWrapper_TMaxSizeComponent_Data.newFunc = [](){ return new nsGuiWrapper::TMaxSizeComponent(); };
    nsGuiWrapper_TMaxSizeComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TMaxSizeComponent*)p; };
    nsGuiWrapper_TMaxSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TMaxSizeComponent_Data);
    
    Data nsGuiWrapper_TMenuNodeComponent_Data;
    nsGuiWrapper_TMenuNodeComponent_Data.newFunc = [](){ return new nsGuiWrapper::TMenuNodeComponent(); };
    nsGuiWrapper_TMenuNodeComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TMenuNodeComponent*)p; };
    nsGuiWrapper_TMenuNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    datas.push_back(nsGuiWrapper_TMenuNodeComponent_Data);
    
    Data nsGuiWrapper_TMinDistanceToParentComponent_Data;
    nsGuiWrapper_TMinDistanceToParentComponent_Data.newFunc = [](){ return new nsGuiWrapper::TMinDistanceToParentComponent(); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TMinDistanceToParentComponent*)p; };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    datas.push_back(nsGuiWrapper_TMinDistanceToParentComponent_Data);
    
    Data nsGuiWrapper_TMinSizeComponent_Data;
    nsGuiWrapper_TMinSizeComponent_Data.newFunc = [](){ return new nsGuiWrapper::TMinSizeComponent(); };
    nsGuiWrapper_TMinSizeComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TMinSizeComponent*)p; };
    nsGuiWrapper_TMinSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TMinSizeComponent_Data);
    
    Data nsGuiWrapper_TNodeIconComponent_Data;
    nsGuiWrapper_TNodeIconComponent_Data.newFunc = [](){ return new nsGuiWrapper::TNodeIconComponent(); };
    nsGuiWrapper_TNodeIconComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TNodeIconComponent*)p; };
    nsGuiWrapper_TNodeIconComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    datas.push_back(nsGuiWrapper_TNodeIconComponent_Data);
    
    Data nsGuiWrapper_TPaddingComponent_Data;
    nsGuiWrapper_TPaddingComponent_Data.newFunc = [](){ return new nsGuiWrapper::TPaddingComponent(); };
    nsGuiWrapper_TPaddingComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TPaddingComponent*)p; };
    nsGuiWrapper_TPaddingComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    datas.push_back(nsGuiWrapper_TPaddingComponent_Data);
    
    Data nsGuiWrapper_TPositionComponent_Data;
    nsGuiWrapper_TPositionComponent_Data.newFunc = [](){ return new nsGuiWrapper::TPositionComponent(); };
    nsGuiWrapper_TPositionComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TPositionComponent*)p; };
    nsGuiWrapper_TPositionComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    datas.push_back(nsGuiWrapper_TPositionComponent_Data);
    
    Data nsGuiWrapper_TPositionInGridComponent_Data;
    nsGuiWrapper_TPositionInGridComponent_Data.newFunc = [](){ return new nsGuiWrapper::TPositionInGridComponent(); };
    nsGuiWrapper_TPositionInGridComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TPositionInGridComponent*)p; };
    nsGuiWrapper_TPositionInGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    datas.push_back(nsGuiWrapper_TPositionInGridComponent_Data);
    
    Data nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data;
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.newFunc = [](){ return new nsGuiWrapper::TSelectedTreeNodeGuidComponent(); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TSelectedTreeNodeGuidComponent*)p; };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    datas.push_back(nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data);
    
    Data nsGuiWrapper_TSizeComponent_Data;
    nsGuiWrapper_TSizeComponent_Data.newFunc = [](){ return new nsGuiWrapper::TSizeComponent(); };
    nsGuiWrapper_TSizeComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TSizeComponent*)p; };
    nsGuiWrapper_TSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TSizeComponent_Data);
    
    Data nsGuiWrapper_TSizeInGridComponent_Data;
    nsGuiWrapper_TSizeInGridComponent_Data.newFunc = [](){ return new nsGuiWrapper::TSizeInGridComponent(); };
    nsGuiWrapper_TSizeInGridComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TSizeInGridComponent*)p; };
    nsGuiWrapper_TSizeInGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    datas.push_back(nsGuiWrapper_TSizeInGridComponent_Data);
    
    Data nsGuiWrapper_TSpacingComponent_Data;
    nsGuiWrapper_TSpacingComponent_Data.newFunc = [](){ return new nsGuiWrapper::TSpacingComponent(); };
    nsGuiWrapper_TSpacingComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TSpacingComponent*)p; };
    nsGuiWrapper_TSpacingComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    datas.push_back(nsGuiWrapper_TSpacingComponent_Data);
    
    Data nsGuiWrapper_TTitleComponent_Data;
    nsGuiWrapper_TTitleComponent_Data.newFunc = [](){ return new nsGuiWrapper::TTitleComponent(); };
    nsGuiWrapper_TTitleComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TTitleComponent*)p; };
    nsGuiWrapper_TTitleComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    datas.push_back(nsGuiWrapper_TTitleComponent_Data);
    
    Data nsGuiWrapper_TTreeNodeComponent_Data;
    nsGuiWrapper_TTreeNodeComponent_Data.newFunc = [](){ return new nsGuiWrapper::TTreeNodeComponent(); };
    nsGuiWrapper_TTreeNodeComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TTreeNodeComponent*)p; };
    nsGuiWrapper_TTreeNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    datas.push_back(nsGuiWrapper_TTreeNodeComponent_Data);
    
    Data nsGuiWrapper_TTreeViewComponent_Data;
    nsGuiWrapper_TTreeViewComponent_Data.newFunc = [](){ return new nsGuiWrapper::TTreeViewComponent(); };
    nsGuiWrapper_TTreeViewComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TTreeViewComponent*)p; };
    nsGuiWrapper_TTreeViewComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    datas.push_back(nsGuiWrapper_TTreeViewComponent_Data);
    
    Data nsGuiWrapper_TVerticalAlignComponent_Data;
    nsGuiWrapper_TVerticalAlignComponent_Data.newFunc = [](){ return new nsGuiWrapper::TVerticalAlignComponent(); };
    nsGuiWrapper_TVerticalAlignComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TVerticalAlignComponent*)p; };
    nsGuiWrapper_TVerticalAlignComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    datas.push_back(nsGuiWrapper_TVerticalAlignComponent_Data);
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
    nsGuiWrapper_TVisibilityComponent_Data.newFunc = [](){ return new nsGuiWrapper::TVisibilityComponent(); };
    nsGuiWrapper_TVisibilityComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TVisibilityComponent*)p; };
    nsGuiWrapper_TVisibilityComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    datas.push_back(nsGuiWrapper_TVisibilityComponent_Data);
    
    Data nsGuiWrapper_TWindowComponent_Data;
    nsGuiWrapper_TWindowComponent_Data.newFunc = [](){ return new nsGuiWrapper::TWindowComponent(); };
    nsGuiWrapper_TWindowComponent_Data.deleteFunc = [](void* p){ delete (nsGuiWrapper::TWindowComponent*)p; };
    nsGuiWrapper_TWindowComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    datas.push_back(nsGuiWrapper_TWindowComponent_Data);
    
    Data nsLogicWrapper_TGlobalHandlerComponent_Data;
    nsLogicWrapper_TGlobalHandlerComponent_Data.newFunc = [](){ return new nsLogicWrapper::TGlobalHandlerComponent(); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TGlobalHandlerComponent*)p; };
    nsLogicWrapper_TGlobalHandlerComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TGlobalHandlerComponent>();
    
    datas.push_back(nsLogicWrapper_TGlobalHandlerComponent_Data);
    
    Data nsLogicWrapper_TLocalHandlerComponent_Data;
    nsLogicWrapper_TLocalHandlerComponent_Data.newFunc = [](){ return new nsLogicWrapper::TLocalHandlerComponent(); };
    nsLogicWrapper_TLocalHandlerComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TLocalHandlerComponent*)p; };
    nsLogicWrapper_TLocalHandlerComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLocalHandlerComponent>();
    
    datas.push_back(nsLogicWrapper_TLocalHandlerComponent_Data);
    
    Data nsLogicWrapper_TPrefabObjectReferenceComponent_Data;
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.newFunc = [](){ return new nsLogicWrapper::TPrefabObjectReferenceComponent(); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TPrefabObjectReferenceComponent*)p; };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TPrefabObjectReferenceComponent_Data);
    
    Data nsLogicWrapper_TPrefabReferenceComponent_Data;
    nsLogicWrapper_TPrefabReferenceComponent_Data.newFunc = [](){ return new nsLogicWrapper::TPrefabReferenceComponent(); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TPrefabReferenceComponent*)p; };
    nsLogicWrapper_TPrefabReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TPrefabReferenceComponent_Data);
    
    Data nsLogicWrapper_TSceneObjectReferenceComponent_Data;
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.newFunc = [](){ return new nsLogicWrapper::TSceneObjectReferenceComponent(); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSceneObjectReferenceComponent*)p; };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TSceneObjectReferenceComponent_Data);
    
    Data nsLogicWrapper_TSceneReferenceComponent_Data;
    nsLogicWrapper_TSceneReferenceComponent_Data.newFunc = [](){ return new nsLogicWrapper::TSceneReferenceComponent(); };
    nsLogicWrapper_TSceneReferenceComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSceneReferenceComponent*)p; };
    nsLogicWrapper_TSceneReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TSceneReferenceComponent_Data);
    
    Data nsLogicWrapper_TSystemComponent_Data;
    nsLogicWrapper_TSystemComponent_Data.newFunc = [](){ return new nsLogicWrapper::TSystemComponent(); };
    nsLogicWrapper_TSystemComponent_Data.deleteFunc = [](void* p){ delete (nsLogicWrapper::TSystemComponent*)p; };
    nsLogicWrapper_TSystemComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    
    datas.push_back(nsLogicWrapper_TSystemComponent_Data);
    
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
void* TComponentTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TComponentTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TComponentTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
