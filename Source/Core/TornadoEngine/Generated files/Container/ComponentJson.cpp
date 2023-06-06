/*
Core Component
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_06_05 10:37:23.313
	
#include "ComponentJson.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentJson::TypeFunc> TComponentJson::mTypeFuncVector;

void TComponentJson::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsCommonWrapper_TGlobalMatrixComponentTypeFunc;
    _nsCommonWrapper_TGlobalMatrixComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TGlobalMatrixComponent>((nsCommonWrapper::TGlobalMatrixComponent*) p, str);
    };
    _nsCommonWrapper_TGlobalMatrixComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TGlobalMatrixComponent>((nsCommonWrapper::TGlobalMatrixComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TGlobalMatrixComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TGlobalMatrixComponentTypeFunc, _nsCommonWrapper_TGlobalMatrixComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TGuidComponentTypeFunc;
    _nsCommonWrapper_TGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str);
    };
    _nsCommonWrapper_TGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TGuidComponentTypeFunc, _nsCommonWrapper_TGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_THandlerTargetTypeFunc;
    _nsCommonWrapper_THandlerTargetTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::THandlerTarget>((nsCommonWrapper::THandlerTarget*) p, str);
    };
    _nsCommonWrapper_THandlerTargetTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::THandlerTarget>((nsCommonWrapper::THandlerTarget*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_THandlerTargetTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::THandlerTarget>();
    
    m.insert({ rtti__nsCommonWrapper_THandlerTargetTypeFunc, _nsCommonWrapper_THandlerTargetTypeFunc });
    
    TypeFunc _nsCommonWrapper_TNameComponentTypeFunc;
    _nsCommonWrapper_TNameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str);
    };
    _nsCommonWrapper_TNameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TNameComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TNameComponentTypeFunc, _nsCommonWrapper_TNameComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc;
    _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TNeedDestroyObjectTagComponent>((nsCommonWrapper::TNeedDestroyObjectTagComponent*) p, str);
    };
    _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TNeedDestroyObjectTagComponent>((nsCommonWrapper::TNeedDestroyObjectTagComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc, _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TObjectInMemoryComponentTypeFunc;
    _nsCommonWrapper_TObjectInMemoryComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TObjectInMemoryComponent>((nsCommonWrapper::TObjectInMemoryComponent*) p, str);
    };
    _nsCommonWrapper_TObjectInMemoryComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TObjectInMemoryComponent>((nsCommonWrapper::TObjectInMemoryComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TObjectInMemoryComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TObjectInMemoryComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TObjectInMemoryComponentTypeFunc, _nsCommonWrapper_TObjectInMemoryComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TParentGuidComponentTypeFunc;
    _nsCommonWrapper_TParentGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str);
    };
    _nsCommonWrapper_TParentGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TParentGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TParentGuidComponentTypeFunc, _nsCommonWrapper_TParentGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabGuidComponent>((nsCommonWrapper::TPrefabGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabGuidComponent>((nsCommonWrapper::TPrefabGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabGuidComponentTypeFunc, _nsCommonWrapper_TPrefabGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabInstanceGuidComponent>((nsCommonWrapper::TPrefabInstanceGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabInstanceGuidComponent>((nsCommonWrapper::TPrefabInstanceGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc, _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabOriginalGuidComponent>((nsCommonWrapper::TPrefabOriginalGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabOriginalGuidComponent>((nsCommonWrapper::TPrefabOriginalGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc, _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabRootComponentTypeFunc;
    _nsCommonWrapper_TPrefabRootComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabRootComponent>((nsCommonWrapper::TPrefabRootComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabRootComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabRootComponent>((nsCommonWrapper::TPrefabRootComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabRootComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabRootComponentTypeFunc, _nsCommonWrapper_TPrefabRootComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TProjectionToUniverseComponentTypeFunc;
    _nsCommonWrapper_TProjectionToUniverseComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TProjectionToUniverseComponent>((nsCommonWrapper::TProjectionToUniverseComponent*) p, str);
    };
    _nsCommonWrapper_TProjectionToUniverseComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TProjectionToUniverseComponent>((nsCommonWrapper::TProjectionToUniverseComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TProjectionToUniverseComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TProjectionToUniverseComponentTypeFunc, _nsCommonWrapper_TProjectionToUniverseComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc, _nsCommonWrapper_TSceneGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneInstanceGuidComponent>((nsCommonWrapper::TSceneInstanceGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneInstanceGuidComponent>((nsCommonWrapper::TSceneInstanceGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc, _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneOriginalGuidComponent>((nsCommonWrapper::TSceneOriginalGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneOriginalGuidComponent>((nsCommonWrapper::TSceneOriginalGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc, _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneRootComponentTypeFunc;
    _nsCommonWrapper_TSceneRootComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str);
    };
    _nsCommonWrapper_TSceneRootComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneRootComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneRootComponentTypeFunc, _nsCommonWrapper_TSceneRootComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TUniverseGuidComponentTypeFunc;
    _nsCommonWrapper_TUniverseGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TUniverseGuidComponent>((nsCommonWrapper::TUniverseGuidComponent*) p, str);
    };
    _nsCommonWrapper_TUniverseGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TUniverseGuidComponent>((nsCommonWrapper::TUniverseGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TUniverseGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TUniverseGuidComponentTypeFunc, _nsCommonWrapper_TUniverseGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TUniverseIndexComponentTypeFunc;
    _nsCommonWrapper_TUniverseIndexComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TUniverseIndexComponent>((nsCommonWrapper::TUniverseIndexComponent*) p, str);
    };
    _nsCommonWrapper_TUniverseIndexComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TUniverseIndexComponent>((nsCommonWrapper::TUniverseIndexComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TUniverseIndexComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TUniverseIndexComponentTypeFunc, _nsCommonWrapper_TUniverseIndexComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraComponentTypeFunc;
    _nsGraphicWrapper_TCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraComponentTypeFunc, _nsGraphicWrapper_TCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc;
    _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraTextureTagComponent>((nsGraphicWrapper::TCameraTextureTagComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraTextureTagComponent>((nsGraphicWrapper::TCameraTextureTagComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraTextureTagComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraTextureTagComponentTypeFunc, _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc;
    _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraWindowPositionComponent>((nsGraphicWrapper::TCameraWindowPositionComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraWindowPositionComponent>((nsGraphicWrapper::TCameraWindowPositionComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc, _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc;
    _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraWindowSizeComponent>((nsGraphicWrapper::TCameraWindowSizeComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraWindowSizeComponent>((nsGraphicWrapper::TCameraWindowSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc, _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc;
    _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TGuiCameraTagComponent>((nsGraphicWrapper::TGuiCameraTagComponent*) p, str);
    };
    _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TGuiCameraTagComponent>((nsGraphicWrapper::TGuiCameraTagComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TGuiCameraTagComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TGuiCameraTagComponentTypeFunc, _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TLightComponentTypeFunc;
    _nsGraphicWrapper_TLightComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str);
    };
    _nsGraphicWrapper_TLightComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TLightComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TLightComponentTypeFunc, _nsGraphicWrapper_TLightComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc;
    _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TRenderToTextureCameraComponent>((nsGraphicWrapper::TRenderToTextureCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TRenderToTextureCameraComponent>((nsGraphicWrapper::TRenderToTextureCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc, _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc;
    _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TTextureFromCameraComponent>((nsGraphicWrapper::TTextureFromCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TTextureFromCameraComponent>((nsGraphicWrapper::TTextureFromCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TTextureFromCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TTextureFromCameraComponentTypeFunc, _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TTextureFromFileComponentTypeFunc;
    _nsGraphicWrapper_TTextureFromFileComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TTextureFromFileComponent>((nsGraphicWrapper::TTextureFromFileComponent*) p, str);
    };
    _nsGraphicWrapper_TTextureFromFileComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TTextureFromFileComponent>((nsGraphicWrapper::TTextureFromFileComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TTextureFromFileComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TTextureFromFileComponentTypeFunc, _nsGraphicWrapper_TTextureFromFileComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TUniverseCameraComponentTypeFunc;
    _nsGraphicWrapper_TUniverseCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TUniverseCameraComponent>((nsGraphicWrapper::TUniverseCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TUniverseCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TUniverseCameraComponent>((nsGraphicWrapper::TUniverseCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TUniverseCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TUniverseCameraComponentTypeFunc, _nsGraphicWrapper_TUniverseCameraComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TAnchorsComponentTypeFunc;
    _nsGuiWrapper_TAnchorsComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TAnchorsComponent>((nsGuiWrapper::TAnchorsComponent*) p, str);
    };
    _nsGuiWrapper_TAnchorsComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TAnchorsComponent>((nsGuiWrapper::TAnchorsComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TAnchorsComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TAnchorsComponentTypeFunc, _nsGuiWrapper_TAnchorsComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc, _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonComponentTypeFunc;
    _nsGuiWrapper_TButtonComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str);
    };
    _nsGuiWrapper_TButtonComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonComponentTypeFunc, _nsGuiWrapper_TButtonComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TColorComponentTypeFunc;
    _nsGuiWrapper_TColorComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TColorComponent>((nsGuiWrapper::TColorComponent*) p, str);
    };
    _nsGuiWrapper_TColorComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TColorComponent>((nsGuiWrapper::TColorComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TColorComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TColorComponentTypeFunc, _nsGuiWrapper_TColorComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc;
    _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TDialogCloseEventHandlerComponent>((nsGuiWrapper::TDialogCloseEventHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TDialogCloseEventHandlerComponent>((nsGuiWrapper::TDialogCloseEventHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TDialogCloseEventHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc, _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TDialogComponentTypeFunc;
    _nsGuiWrapper_TDialogComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TDialogComponent>((nsGuiWrapper::TDialogComponent*) p, str);
    };
    _nsGuiWrapper_TDialogComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TDialogComponent>((nsGuiWrapper::TDialogComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TDialogComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TDialogComponentTypeFunc, _nsGuiWrapper_TDialogComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFocusComponentTypeFunc;
    _nsGuiWrapper_TFocusComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str);
    };
    _nsGuiWrapper_TFocusComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFocusComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFocusComponentTypeFunc, _nsGuiWrapper_TFocusComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameComponentTypeFunc;
    _nsGuiWrapper_TFrameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameComponent>((nsGuiWrapper::TFrameComponent*) p, str);
    };
    _nsGuiWrapper_TFrameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameComponent>((nsGuiWrapper::TFrameComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameComponentTypeFunc, _nsGuiWrapper_TFrameComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameKeyHandlerComponent>((nsGuiWrapper::TFrameKeyHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameKeyHandlerComponent>((nsGuiWrapper::TFrameKeyHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameKeyHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc, _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseClickHandlerComponent>((nsGuiWrapper::TFrameMouseClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseClickHandlerComponent>((nsGuiWrapper::TFrameMouseClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseMoveHandlerComponent>((nsGuiWrapper::TFrameMouseMoveHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseMoveHandlerComponent>((nsGuiWrapper::TFrameMouseMoveHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseMoveHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseWheelHandlerComponent>((nsGuiWrapper::TFrameMouseWheelHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseWheelHandlerComponent>((nsGuiWrapper::TFrameMouseWheelHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseWheelHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TGridComponentTypeFunc;
    _nsGuiWrapper_TGridComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TGridComponent>((nsGuiWrapper::TGridComponent*) p, str);
    };
    _nsGuiWrapper_TGridComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TGridComponent>((nsGuiWrapper::TGridComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TGridComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TGridComponentTypeFunc, _nsGuiWrapper_TGridComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_THorizontalAlignComponentTypeFunc;
    _nsGuiWrapper_THorizontalAlignComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::THorizontalAlignComponent>((nsGuiWrapper::THorizontalAlignComponent*) p, str);
    };
    _nsGuiWrapper_THorizontalAlignComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::THorizontalAlignComponent>((nsGuiWrapper::THorizontalAlignComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_THorizontalAlignComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    m.insert({ rtti__nsGuiWrapper_THorizontalAlignComponentTypeFunc, _nsGuiWrapper_THorizontalAlignComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TInputTextComponentTypeFunc;
    _nsGuiWrapper_TInputTextComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TInputTextComponent>((nsGuiWrapper::TInputTextComponent*) p, str);
    };
    _nsGuiWrapper_TInputTextComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TInputTextComponent>((nsGuiWrapper::TInputTextComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TInputTextComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TInputTextComponentTypeFunc, _nsGuiWrapper_TInputTextComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TInputTextValueComponentTypeFunc;
    _nsGuiWrapper_TInputTextValueComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TInputTextValueComponent>((nsGuiWrapper::TInputTextValueComponent*) p, str);
    };
    _nsGuiWrapper_TInputTextValueComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TInputTextValueComponent>((nsGuiWrapper::TInputTextValueComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TInputTextValueComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TInputTextValueComponentTypeFunc, _nsGuiWrapper_TInputTextValueComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TLabelComponentTypeFunc;
    _nsGuiWrapper_TLabelComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TLabelComponent>((nsGuiWrapper::TLabelComponent*) p, str);
    };
    _nsGuiWrapper_TLabelComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TLabelComponent>((nsGuiWrapper::TLabelComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TLabelComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TLabelComponentTypeFunc, _nsGuiWrapper_TLabelComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TLabelValueComponentTypeFunc;
    _nsGuiWrapper_TLabelValueComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TLabelValueComponent>((nsGuiWrapper::TLabelValueComponent*) p, str);
    };
    _nsGuiWrapper_TLabelValueComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TLabelValueComponent>((nsGuiWrapper::TLabelValueComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TLabelValueComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TLabelValueComponentTypeFunc, _nsGuiWrapper_TLabelValueComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMainWindowComponentTypeFunc;
    _nsGuiWrapper_TMainWindowComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMainWindowComponent>((nsGuiWrapper::TMainWindowComponent*) p, str);
    };
    _nsGuiWrapper_TMainWindowComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMainWindowComponent>((nsGuiWrapper::TMainWindowComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMainWindowComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMainWindowComponentTypeFunc, _nsGuiWrapper_TMainWindowComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMaxSizeComponentTypeFunc;
    _nsGuiWrapper_TMaxSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMaxSizeComponent>((nsGuiWrapper::TMaxSizeComponent*) p, str);
    };
    _nsGuiWrapper_TMaxSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMaxSizeComponent>((nsGuiWrapper::TMaxSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMaxSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMaxSizeComponentTypeFunc, _nsGuiWrapper_TMaxSizeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMenuNodeClickHandlerComponent>((nsGuiWrapper::TMenuNodeClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMenuNodeClickHandlerComponent>((nsGuiWrapper::TMenuNodeClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc, _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMenuNodeComponentTypeFunc;
    _nsGuiWrapper_TMenuNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMenuNodeComponent>((nsGuiWrapper::TMenuNodeComponent*) p, str);
    };
    _nsGuiWrapper_TMenuNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMenuNodeComponent>((nsGuiWrapper::TMenuNodeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMenuNodeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMenuNodeComponentTypeFunc, _nsGuiWrapper_TMenuNodeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMinDistanceToParentComponentTypeFunc;
    _nsGuiWrapper_TMinDistanceToParentComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMinDistanceToParentComponent>((nsGuiWrapper::TMinDistanceToParentComponent*) p, str);
    };
    _nsGuiWrapper_TMinDistanceToParentComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMinDistanceToParentComponent>((nsGuiWrapper::TMinDistanceToParentComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMinDistanceToParentComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMinDistanceToParentComponentTypeFunc, _nsGuiWrapper_TMinDistanceToParentComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMinSizeComponentTypeFunc;
    _nsGuiWrapper_TMinSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMinSizeComponent>((nsGuiWrapper::TMinSizeComponent*) p, str);
    };
    _nsGuiWrapper_TMinSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMinSizeComponent>((nsGuiWrapper::TMinSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMinSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMinSizeComponentTypeFunc, _nsGuiWrapper_TMinSizeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TNodeIconComponentTypeFunc;
    _nsGuiWrapper_TNodeIconComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TNodeIconComponent>((nsGuiWrapper::TNodeIconComponent*) p, str);
    };
    _nsGuiWrapper_TNodeIconComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TNodeIconComponent>((nsGuiWrapper::TNodeIconComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TNodeIconComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TNodeIconComponentTypeFunc, _nsGuiWrapper_TNodeIconComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TPaddingComponentTypeFunc;
    _nsGuiWrapper_TPaddingComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TPaddingComponent>((nsGuiWrapper::TPaddingComponent*) p, str);
    };
    _nsGuiWrapper_TPaddingComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TPaddingComponent>((nsGuiWrapper::TPaddingComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TPaddingComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TPaddingComponentTypeFunc, _nsGuiWrapper_TPaddingComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TPositionComponentTypeFunc;
    _nsGuiWrapper_TPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str);
    };
    _nsGuiWrapper_TPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TPositionComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TPositionComponentTypeFunc, _nsGuiWrapper_TPositionComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TPositionInGridComponentTypeFunc;
    _nsGuiWrapper_TPositionInGridComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TPositionInGridComponent>((nsGuiWrapper::TPositionInGridComponent*) p, str);
    };
    _nsGuiWrapper_TPositionInGridComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TPositionInGridComponent>((nsGuiWrapper::TPositionInGridComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TPositionInGridComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TPositionInGridComponentTypeFunc, _nsGuiWrapper_TPositionInGridComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc;
    _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSelectedTreeNodeGuidComponent>((nsGuiWrapper::TSelectedTreeNodeGuidComponent*) p, str);
    };
    _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSelectedTreeNodeGuidComponent>((nsGuiWrapper::TSelectedTreeNodeGuidComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc, _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSizeComponentTypeFunc;
    _nsGuiWrapper_TSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str);
    };
    _nsGuiWrapper_TSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSizeComponentTypeFunc, _nsGuiWrapper_TSizeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSizeInGridComponentTypeFunc;
    _nsGuiWrapper_TSizeInGridComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSizeInGridComponent>((nsGuiWrapper::TSizeInGridComponent*) p, str);
    };
    _nsGuiWrapper_TSizeInGridComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSizeInGridComponent>((nsGuiWrapper::TSizeInGridComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSizeInGridComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSizeInGridComponentTypeFunc, _nsGuiWrapper_TSizeInGridComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSpacingComponentTypeFunc;
    _nsGuiWrapper_TSpacingComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSpacingComponent>((nsGuiWrapper::TSpacingComponent*) p, str);
    };
    _nsGuiWrapper_TSpacingComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSpacingComponent>((nsGuiWrapper::TSpacingComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSpacingComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSpacingComponentTypeFunc, _nsGuiWrapper_TSpacingComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTitleComponentTypeFunc;
    _nsGuiWrapper_TTitleComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str);
    };
    _nsGuiWrapper_TTitleComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTitleComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTitleComponentTypeFunc, _nsGuiWrapper_TTitleComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTreeNodeComponentTypeFunc;
    _nsGuiWrapper_TTreeNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTreeNodeComponent>((nsGuiWrapper::TTreeNodeComponent*) p, str);
    };
    _nsGuiWrapper_TTreeNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTreeNodeComponent>((nsGuiWrapper::TTreeNodeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTreeNodeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTreeNodeComponentTypeFunc, _nsGuiWrapper_TTreeNodeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTreeViewComponentTypeFunc;
    _nsGuiWrapper_TTreeViewComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTreeViewComponent>((nsGuiWrapper::TTreeViewComponent*) p, str);
    };
    _nsGuiWrapper_TTreeViewComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTreeViewComponent>((nsGuiWrapper::TTreeViewComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTreeViewComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTreeViewComponentTypeFunc, _nsGuiWrapper_TTreeViewComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TVerticalAlignComponentTypeFunc;
    _nsGuiWrapper_TVerticalAlignComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TVerticalAlignComponent>((nsGuiWrapper::TVerticalAlignComponent*) p, str);
    };
    _nsGuiWrapper_TVerticalAlignComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TVerticalAlignComponent>((nsGuiWrapper::TVerticalAlignComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TVerticalAlignComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TVerticalAlignComponentTypeFunc, _nsGuiWrapper_TVerticalAlignComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TVisibilityComponentTypeFunc;
    _nsGuiWrapper_TVisibilityComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str);
    };
    _nsGuiWrapper_TVisibilityComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TVisibilityComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TVisibilityComponentTypeFunc, _nsGuiWrapper_TVisibilityComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc;
    _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TWindowCloseEventHandlerComponent>((nsGuiWrapper::TWindowCloseEventHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TWindowCloseEventHandlerComponent>((nsGuiWrapper::TWindowCloseEventHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TWindowCloseEventHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc, _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TWindowComponentTypeFunc;
    _nsGuiWrapper_TWindowComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str);
    };
    _nsGuiWrapper_TWindowComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TWindowComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TWindowComponentTypeFunc, _nsGuiWrapper_TWindowComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc;
    _nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>((nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent*) p, str);
    };
    _nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>((nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc, _nsLogicWrapper_TObjectInstantiationCompletionHandlerComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc;
    _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TPrefabObjectReferenceComponent>((nsLogicWrapper::TPrefabObjectReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TPrefabObjectReferenceComponent>((nsLogicWrapper::TPrefabObjectReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc, _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TPrefabReferenceComponentTypeFunc;
    _nsLogicWrapper_TPrefabReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TPrefabReferenceComponent>((nsLogicWrapper::TPrefabReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TPrefabReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TPrefabReferenceComponent>((nsLogicWrapper::TPrefabReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TPrefabReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TPrefabReferenceComponentTypeFunc, _nsLogicWrapper_TPrefabReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc;
    _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSceneObjectReferenceComponent>((nsLogicWrapper::TSceneObjectReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSceneObjectReferenceComponent>((nsLogicWrapper::TSceneObjectReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc, _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSceneReferenceComponentTypeFunc;
    _nsLogicWrapper_TSceneReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSceneReferenceComponent>((nsLogicWrapper::TSceneReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TSceneReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSceneReferenceComponent>((nsLogicWrapper::TSceneReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSceneReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSceneReferenceComponentTypeFunc, _nsLogicWrapper_TSceneReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSystemComponentTypeFunc;
    _nsLogicWrapper_TSystemComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSystemComponent>((nsLogicWrapper::TSystemComponent*) p, str);
    };
    _nsLogicWrapper_TSystemComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSystemComponent>((nsLogicWrapper::TSystemComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSystemComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSystemComponentTypeFunc, _nsLogicWrapper_TSystemComponentTypeFunc });
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->Type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
    TypeFunc _nsTornadoEngine_IPropertyOfTypeFunc;
    _nsTornadoEngine_IPropertyOfTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::IPropertyOf>((nsTornadoEngine::IPropertyOf*) p, str);
    };
    _nsTornadoEngine_IPropertyOfTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::IPropertyOf>((nsTornadoEngine::IPropertyOf*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_IPropertyOfTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    m.insert({ rtti__nsTornadoEngine_IPropertyOfTypeFunc, _nsTornadoEngine_IPropertyOfTypeFunc });
    
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
void TComponentJson::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TGlobalMatrixComponent* p, Jobj& obj)
{
    auto value_o = PUM::AddObject(obj, "value");
    _Serialize(&(p->value), value_o);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TGlobalMatrixComponent* p, const Jobj& obj)
{
    auto value_o0 = POM::FindObject(obj, "value");
    _Deserialize(&(p->value), value_o0);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::THandlerTarget* p, Jobj& obj)
{
    PUM::Push(obj, "handlerTypeName", p->handlerTypeName);
    PUM::Push(obj, "partOfGuid", p->partOfGuid);
    PUM::Push(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::THandlerTarget* p, const Jobj& obj)
{
    POM::PopStr(obj, "handlerTypeName", p->handlerTypeName);
    POM::PopStr(obj, "partOfGuid", p->partOfGuid);
    POM::PopStr(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TObjectInMemoryComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TObjectInMemoryComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TParentGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TParentGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TPrefabGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TPrefabGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TPrefabRootComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TPrefabRootComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TProjectionToUniverseComponent* p, Jobj& obj)
{
    PUM::Push(obj, "guid", p->guid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TProjectionToUniverseComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "guid", p->guid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TSceneGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TSceneGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TSceneRootComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TSceneRootComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TUniverseGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TUniverseGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsCommonWrapper::TUniverseIndexComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsCommonWrapper::TUniverseIndexComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TCameraTextureTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TCameraTextureTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TGuiCameraTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TGuiCameraTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TLightComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TLightComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TTextureFromCameraComponent* p, Jobj& obj)
{
    PUM::Push(obj, "cameraGuid", p->cameraGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TTextureFromCameraComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "cameraGuid", p->cameraGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TTextureFromFileComponent* p, Jobj& obj)
{
    PUM::Push(obj, "resourceGuid", p->resourceGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TTextureFromFileComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "resourceGuid", p->resourceGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGraphicWrapper::TUniverseCameraComponent* p, Jobj& obj)
{
    PUM::Push(obj, "universeGuid", p->universeGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGraphicWrapper::TUniverseCameraComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "universeGuid", p->universeGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TAnchorsComponent* p, Jobj& obj)
{
    PUM::Push(obj, "leftIsUsed", p->leftIsUsed);
    PUM::Push(obj, "leftOffset", p->leftOffset);
    PUM::Push(obj, "rightIsUsed", p->rightIsUsed);
    PUM::Push(obj, "rightOffset", p->rightOffset);
    PUM::Push(obj, "topIsUsed", p->topIsUsed);
    PUM::Push(obj, "topOffset", p->topOffset);
    PUM::Push(obj, "bottomIsUsed", p->bottomIsUsed);
    PUM::Push(obj, "bottomOffset", p->bottomOffset);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TAnchorsComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "leftIsUsed", p->leftIsUsed);
    POM::PopNum(obj, "leftOffset", p->leftOffset);
    POM::PopBool(obj, "rightIsUsed", p->rightIsUsed);
    POM::PopNum(obj, "rightOffset", p->rightOffset);
    POM::PopBool(obj, "topIsUsed", p->topIsUsed);
    POM::PopNum(obj, "topOffset", p->topOffset);
    POM::PopBool(obj, "bottomIsUsed", p->bottomIsUsed);
    POM::PopNum(obj, "bottomOffset", p->bottomOffset);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TButtonClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TButtonClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TColorComponent* p, Jobj& obj)
{
    PUM::Push(obj, "r", p->r);
    PUM::Push(obj, "g", p->g);
    PUM::Push(obj, "b", p->b);
    PUM::Push(obj, "a", p->a);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TColorComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "r", p->r);
    POM::PopNum(obj, "g", p->g);
    POM::PopNum(obj, "b", p->b);
    POM::PopNum(obj, "a", p->a);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TDialogComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TDialogComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFrameComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFrameComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TGridComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TGridComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::THorizontalAlignComponent* p, Jobj& obj)
{
    auto value_c0 = _SerializeEnum(&(p->value));
    PUM::Push(obj, "value", value_c0);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::THorizontalAlignComponent* p, const Jobj& obj)
{
    std::string value_c0;
    POM::PopStr(obj, "value", value_c0);
    _DeserializeEnum(value_c0, &(p->value));
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TInputTextComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TInputTextComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TInputTextValueComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TInputTextValueComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TLabelComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TLabelComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TLabelValueComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TLabelValueComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMainWindowComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMainWindowComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMaxSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMaxSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMenuNodeComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMenuNodeComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMinDistanceToParentComponent* p, Jobj& obj)
{
    PUM::Push(obj, "left", p->left);
    PUM::Push(obj, "right", p->right);
    PUM::Push(obj, "top", p->top);
    PUM::Push(obj, "bottom", p->bottom);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMinDistanceToParentComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "left", p->left);
    POM::PopNum(obj, "right", p->right);
    POM::PopNum(obj, "top", p->top);
    POM::PopNum(obj, "bottom", p->bottom);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TMinSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TMinSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TNodeIconComponent* p, Jobj& obj)
{
    PUM::Push(obj, "width", p->width);
    PUM::Push(obj, "height", p->height);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TNodeIconComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "width", p->width);
    POM::PopNum(obj, "height", p->height);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TPaddingComponent* p, Jobj& obj)
{
    PUM::Push(obj, "left", p->left);
    PUM::Push(obj, "right", p->right);
    PUM::Push(obj, "top", p->top);
    PUM::Push(obj, "bottom", p->bottom);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TPaddingComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "left", p->left);
    POM::PopNum(obj, "right", p->right);
    POM::PopNum(obj, "top", p->top);
    POM::PopNum(obj, "bottom", p->bottom);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TPositionInGridComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TPositionInGridComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TSizeInGridComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TSizeInGridComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TSpacingComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TSpacingComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TTreeNodeComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TTreeNodeComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TTreeViewComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TTreeViewComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TVerticalAlignComponent* p, Jobj& obj)
{
    auto value_c0 = _SerializeEnum(&(p->value));
    PUM::Push(obj, "value", value_c0);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TVerticalAlignComponent* p, const Jobj& obj)
{
    std::string value_c0;
    POM::PopStr(obj, "value", value_c0);
    _DeserializeEnum(value_c0, &(p->value));
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
std::string TComponentJson::_SerializeEnum(nsGuiWrapper::THorizontalAlignComponent::Type* p)
{
    switch (*p) {
        case nsGuiWrapper::THorizontalAlignComponent::Type::CENTER:
            return "CENTER";
        case nsGuiWrapper::THorizontalAlignComponent::Type::LEFT:
            return "LEFT";
        case nsGuiWrapper::THorizontalAlignComponent::Type::RIGHT:
            return "RIGHT";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TComponentJson::_DeserializeEnum(std::string& str, nsGuiWrapper::THorizontalAlignComponent::Type* p)
{
    std::map<std::string, nsGuiWrapper::THorizontalAlignComponent::Type> m;
    m.insert({"CENTER", nsGuiWrapper::THorizontalAlignComponent::Type::CENTER});
    m.insert({"LEFT", nsGuiWrapper::THorizontalAlignComponent::Type::LEFT});
    m.insert({"RIGHT", nsGuiWrapper::THorizontalAlignComponent::Type::RIGHT});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TComponentJson::_SerializeEnum(nsGuiWrapper::TVerticalAlignComponent::Type* p)
{
    switch (*p) {
        case nsGuiWrapper::TVerticalAlignComponent::Type::CENTER:
            return "CENTER";
        case nsGuiWrapper::TVerticalAlignComponent::Type::LEFT:
            return "LEFT";
        case nsGuiWrapper::TVerticalAlignComponent::Type::RIGHT:
            return "RIGHT";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TComponentJson::_DeserializeEnum(std::string& str, nsGuiWrapper::TVerticalAlignComponent::Type* p)
{
    std::map<std::string, nsGuiWrapper::TVerticalAlignComponent::Type> m;
    m.insert({"CENTER", nsGuiWrapper::TVerticalAlignComponent::Type::CENTER});
    m.insert({"LEFT", nsGuiWrapper::TVerticalAlignComponent::Type::LEFT});
    m.insert({"RIGHT", nsGuiWrapper::TVerticalAlignComponent::Type::RIGHT});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* p, Jobj& obj)
{
    PUM::Push(obj, "handlerTypeName", p->handlerTypeName);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "handlerTypeName", p->handlerTypeName);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
    PUM::Push(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
    POM::PopStr(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TPrefabReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TPrefabReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TSceneReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "sceneGuid", p->sceneGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TSceneReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "sceneGuid", p->sceneGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsLogicWrapper::TSystemComponent* p, Jobj& obj)
{
    PUM::Push(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsLogicWrapper::TSystemComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
{
    PUM::Push(obj, "_11", p->_11);
    PUM::Push(obj, "_12", p->_12);
    PUM::Push(obj, "_13", p->_13);
    PUM::Push(obj, "_14", p->_14);
    PUM::Push(obj, "_21", p->_21);
    PUM::Push(obj, "_22", p->_22);
    PUM::Push(obj, "_23", p->_23);
    PUM::Push(obj, "_24", p->_24);
    PUM::Push(obj, "_31", p->_31);
    PUM::Push(obj, "_32", p->_32);
    PUM::Push(obj, "_33", p->_33);
    PUM::Push(obj, "_34", p->_34);
    PUM::Push(obj, "_41", p->_41);
    PUM::Push(obj, "_42", p->_42);
    PUM::Push(obj, "_43", p->_43);
    PUM::Push(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
{
    POM::PopNum(obj, "_11", p->_11);
    POM::PopNum(obj, "_12", p->_12);
    POM::PopNum(obj, "_13", p->_13);
    POM::PopNum(obj, "_14", p->_14);
    POM::PopNum(obj, "_21", p->_21);
    POM::PopNum(obj, "_22", p->_22);
    POM::PopNum(obj, "_23", p->_23);
    POM::PopNum(obj, "_24", p->_24);
    POM::PopNum(obj, "_31", p->_31);
    POM::PopNum(obj, "_32", p->_32);
    POM::PopNum(obj, "_33", p->_33);
    POM::PopNum(obj, "_34", p->_34);
    POM::PopNum(obj, "_41", p->_41);
    POM::PopNum(obj, "_42", p->_42);
    POM::PopNum(obj, "_43", p->_43);
    POM::PopNum(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEngine::IPropertyOf* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEngine::IPropertyOf* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
