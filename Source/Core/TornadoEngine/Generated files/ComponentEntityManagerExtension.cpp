/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.3, build 54 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_28 18:22:13.255
	
#include "ComponentEntityManagerExtension.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

std::vector<TComponentEntityManagerExtension::Data> TComponentEntityManagerExtension::mRttiVector;

void TComponentEntityManagerExtension::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsCommonWrapper_TGuidComponent_Data;
        nsCommonWrapper_TGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TGuidComponent_Data, nsCommonWrapper_TGuidComponent_Data });
    
    Data nsCommonWrapper_TNameComponent_Data;
        nsCommonWrapper_TNameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TNameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNameComponent>(eid, lambda);
    };
    nsCommonWrapper_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNameComponent>(eid); };
    auto rtti_nsCommonWrapper_TNameComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNameComponent_Data, nsCommonWrapper_TNameComponent_Data });
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
        nsCommonWrapper_TParentGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TParentGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TParentGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TParentGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TParentGuidComponent_Data, nsCommonWrapper_TParentGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabGuidComponent_Data;
        nsCommonWrapper_TPrefabGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TPrefabGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TPrefabGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabGuidComponent_Data, nsCommonWrapper_TPrefabGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabOriginalGuidComponent_Data;
        nsCommonWrapper_TPrefabOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data, nsCommonWrapper_TPrefabOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabRootComponent_Data;
        nsCommonWrapper_TPrefabRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabRootComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    auto rtti_nsCommonWrapper_TPrefabRootComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabRootComponent_Data, nsCommonWrapper_TPrefabRootComponent_Data });
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
        nsCommonWrapper_TSceneGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneGuidComponent_Data, nsCommonWrapper_TSceneGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneOriginalGuidComponent_Data;
        nsCommonWrapper_TSceneOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data, nsCommonWrapper_TSceneOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
        nsCommonWrapper_TSceneRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneRootComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneRootComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneRootComponent_Data, nsCommonWrapper_TSceneRootComponent_Data });
    
    Data nsCommonWrapper_TTransformComponent_Data;
        nsCommonWrapper_TTransformComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TTransformComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TTransformComponent>(eid, lambda);
    };
    nsCommonWrapper_TTransformComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TTransformComponent>(eid); };
    auto rtti_nsCommonWrapper_TTransformComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TTransformComponent_Data, nsCommonWrapper_TTransformComponent_Data });
    
    Data nsGraphicWrapper_TCameraComponent_Data;
        nsGraphicWrapper_TCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraComponent>(eid, lambda);
    };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    auto rtti_nsGraphicWrapper_TCameraComponent_Data = globalTypeIdentifier->type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraComponent_Data, nsGraphicWrapper_TCameraComponent_Data });
    
    Data nsGraphicWrapper_TLightComponent_Data;
        nsGraphicWrapper_TLightComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TLightComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TLightComponent>(eid, lambda);
    };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    auto rtti_nsGraphicWrapper_TLightComponent_Data = globalTypeIdentifier->type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TLightComponent_Data, nsGraphicWrapper_TLightComponent_Data });
    
    Data nsGuiWrapper_TButtonClickHandlerComponent_Data;
        nsGuiWrapper_TButtonClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TButtonClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    auto rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data, nsGuiWrapper_TButtonClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TButtonComponent_Data;
        nsGuiWrapper_TButtonComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TButtonComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonComponent>(eid, lambda);
    };
    nsGuiWrapper_TButtonComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonComponent>(eid); };
    auto rtti_nsGuiWrapper_TButtonComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonComponent_Data, nsGuiWrapper_TButtonComponent_Data });
    
    Data nsGuiWrapper_TFocusComponent_Data;
        nsGuiWrapper_TFocusComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFocusComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFocusComponent>(eid, lambda);
    };
    nsGuiWrapper_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFocusComponent>(eid); };
    auto rtti_nsGuiWrapper_TFocusComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFocusComponent_Data, nsGuiWrapper_TFocusComponent_Data });
    
    Data nsGuiWrapper_TFrameComponent_Data;
        nsGuiWrapper_TFrameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameComponent>(eid); };
    auto rtti_nsGuiWrapper_TFrameComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameComponent_Data, nsGuiWrapper_TFrameComponent_Data });
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
        nsGuiWrapper_TMainWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMainWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMainWindowComponent>(eid, lambda);
    };
    nsGuiWrapper_TMainWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    auto rtti_nsGuiWrapper_TMainWindowComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMainWindowComponent_Data, nsGuiWrapper_TMainWindowComponent_Data });
    
    Data nsGuiWrapper_TPositionComponent_Data;
        nsGuiWrapper_TPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPositionComponent>(eid, lambda);
    };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    auto rtti_nsGuiWrapper_TPositionComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionComponent_Data, nsGuiWrapper_TPositionComponent_Data });
    
    Data nsGuiWrapper_TSizeComponent_Data;
        nsGuiWrapper_TSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSizeComponent>(eid, lambda);
    };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
    auto rtti_nsGuiWrapper_TSizeComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSizeComponent_Data, nsGuiWrapper_TSizeComponent_Data });
    
    Data nsGuiWrapper_TTitleComponent_Data;
        nsGuiWrapper_TTitleComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TTitleComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTitleComponent>(eid, lambda);
    };
    nsGuiWrapper_TTitleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTitleComponent>(eid); };
    auto rtti_nsGuiWrapper_TTitleComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTitleComponent_Data, nsGuiWrapper_TTitleComponent_Data });
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
        nsGuiWrapper_TVisibilityComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TVisibilityComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TVisibilityComponent>(eid, lambda);
    };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    auto rtti_nsGuiWrapper_TVisibilityComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TVisibilityComponent_Data, nsGuiWrapper_TVisibilityComponent_Data });
    
    Data nsGuiWrapper_TWindowComponent_Data;
        nsGuiWrapper_TWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TWindowComponent>(eid, lambda);
    };
    nsGuiWrapper_TWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowComponent>(eid); };
    auto rtti_nsGuiWrapper_TWindowComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowComponent_Data, nsGuiWrapper_TWindowComponent_Data });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& vt : m) {
        mRttiVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
bool TComponentEntityManagerExtension::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].createFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation);
}
//---------------------------------------------------------------------------------------
const void* TComponentEntityManagerExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntityManagerExtension::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
