/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.2, build 53 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_24 08:27:04.725
	
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
    nsCommonWrapper_TGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TGuidComponent*) p, withNotify); };
    nsCommonWrapper_TGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGuidComponent*) p)); };
    nsCommonWrapper_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TGuidComponent>(eid, *((nsCommonWrapper::TGuidComponent*) p)); };
    nsCommonWrapper_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TGuidComponent_Data, nsCommonWrapper_TGuidComponent_Data });
    
    Data nsCommonWrapper_TNameComponent_Data;
    nsCommonWrapper_TNameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TNameComponent*) p, withNotify); };
    nsCommonWrapper_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNameComponent*) p)); };
    nsCommonWrapper_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TNameComponent>(eid, *((nsCommonWrapper::TNameComponent*) p)); };
    nsCommonWrapper_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNameComponent>(eid); };
    auto rtti_nsCommonWrapper_TNameComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNameComponent_Data, nsCommonWrapper_TNameComponent_Data });
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
    nsCommonWrapper_TParentGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TParentGuidComponent*) p, withNotify); };
    nsCommonWrapper_TParentGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TParentGuidComponent*) p)); };
    nsCommonWrapper_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TParentGuidComponent>(eid, *((nsCommonWrapper::TParentGuidComponent*) p)); };
    nsCommonWrapper_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TParentGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TParentGuidComponent_Data, nsCommonWrapper_TParentGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneEditingComponent_Data;
    nsCommonWrapper_TSceneEditingComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TSceneEditingComponent>(eid); };
    nsCommonWrapper_TSceneEditingComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TSceneEditingComponent*) p, withNotify); };
    nsCommonWrapper_TSceneEditingComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneEditingComponent*) p)); };
    nsCommonWrapper_TSceneEditingComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneEditingComponent>(eid); };
    nsCommonWrapper_TSceneEditingComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TSceneEditingComponent>(eid, *((nsCommonWrapper::TSceneEditingComponent*) p)); };
    nsCommonWrapper_TSceneEditingComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneEditingComponent>(eid); };
    nsCommonWrapper_TSceneEditingComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneEditingComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneEditingComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneEditingComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneEditingComponent_Data, nsCommonWrapper_TSceneEditingComponent_Data });
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
    nsCommonWrapper_TSceneGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TSceneGuidComponent*) p, withNotify); };
    nsCommonWrapper_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneGuidComponent*) p)); };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TSceneGuidComponent>(eid, *((nsCommonWrapper::TSceneGuidComponent*) p)); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneGuidComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneGuidComponent_Data, nsCommonWrapper_TSceneGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
    nsCommonWrapper_TSceneRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TSceneRootComponent*) p, withNotify); };
    nsCommonWrapper_TSceneRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneRootComponent*) p)); };
    nsCommonWrapper_TSceneRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TSceneRootComponent>(eid, *((nsCommonWrapper::TSceneRootComponent*) p)); };
    nsCommonWrapper_TSceneRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    auto rtti_nsCommonWrapper_TSceneRootComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneRootComponent_Data, nsCommonWrapper_TSceneRootComponent_Data });
    
    Data nsCommonWrapper_TTransformComponent_Data;
    nsCommonWrapper_TTransformComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsCommonWrapper::TTransformComponent*) p, withNotify); };
    nsCommonWrapper_TTransformComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TTransformComponent*) p)); };
    nsCommonWrapper_TTransformComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsCommonWrapper::TTransformComponent>(eid, *((nsCommonWrapper::TTransformComponent*) p)); };
    nsCommonWrapper_TTransformComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TTransformComponent>(eid); };
    auto rtti_nsCommonWrapper_TTransformComponent_Data = globalTypeIdentifier->type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TTransformComponent_Data, nsCommonWrapper_TTransformComponent_Data });
    
    Data nsGraphicWrapper_TCameraComponent_Data;
    nsGraphicWrapper_TCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGraphicWrapper::TCameraComponent*) p, withNotify); };
    nsGraphicWrapper_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraComponent*) p)); };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGraphicWrapper::TCameraComponent>(eid, *((nsGraphicWrapper::TCameraComponent*) p)); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    auto rtti_nsGraphicWrapper_TCameraComponent_Data = globalTypeIdentifier->type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraComponent_Data, nsGraphicWrapper_TCameraComponent_Data });
    
    Data nsGraphicWrapper_TLightComponent_Data;
    nsGraphicWrapper_TLightComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGraphicWrapper::TLightComponent*) p, withNotify); };
    nsGraphicWrapper_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TLightComponent*) p)); };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGraphicWrapper::TLightComponent>(eid, *((nsGraphicWrapper::TLightComponent*) p)); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    auto rtti_nsGraphicWrapper_TLightComponent_Data = globalTypeIdentifier->type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TLightComponent_Data, nsGraphicWrapper_TLightComponent_Data });
    
    Data nsGuiWrapper_TButtonClickHandlerComponent_Data;
    nsGuiWrapper_TButtonClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TButtonClickHandlerComponent*) p, withNotify); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonClickHandlerComponent*) p)); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid, *((nsGuiWrapper::TButtonClickHandlerComponent*) p)); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    auto rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data, nsGuiWrapper_TButtonClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TButtonComponent_Data;
    nsGuiWrapper_TButtonComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TButtonComponent*) p, withNotify); };
    nsGuiWrapper_TButtonComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonComponent*) p)); };
    nsGuiWrapper_TButtonComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TButtonComponent>(eid, *((nsGuiWrapper::TButtonComponent*) p)); };
    nsGuiWrapper_TButtonComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonComponent>(eid); };
    auto rtti_nsGuiWrapper_TButtonComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonComponent_Data, nsGuiWrapper_TButtonComponent_Data });
    
    Data nsGuiWrapper_TFocusComponent_Data;
    nsGuiWrapper_TFocusComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TFocusComponent*) p, withNotify); };
    nsGuiWrapper_TFocusComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFocusComponent*) p)); };
    nsGuiWrapper_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TFocusComponent>(eid, *((nsGuiWrapper::TFocusComponent*) p)); };
    nsGuiWrapper_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFocusComponent>(eid); };
    auto rtti_nsGuiWrapper_TFocusComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFocusComponent_Data, nsGuiWrapper_TFocusComponent_Data });
    
    Data nsGuiWrapper_TPositionComponent_Data;
    nsGuiWrapper_TPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TPositionComponent*) p, withNotify); };
    nsGuiWrapper_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionComponent*) p)); };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TPositionComponent>(eid, *((nsGuiWrapper::TPositionComponent*) p)); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    auto rtti_nsGuiWrapper_TPositionComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionComponent_Data, nsGuiWrapper_TPositionComponent_Data });
    
    Data nsGuiWrapper_TSizeComponent_Data;
    nsGuiWrapper_TSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TSizeComponent*) p, withNotify); };
    nsGuiWrapper_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeComponent*) p)); };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TSizeComponent>(eid, *((nsGuiWrapper::TSizeComponent*) p)); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
    auto rtti_nsGuiWrapper_TSizeComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSizeComponent_Data, nsGuiWrapper_TSizeComponent_Data });
    
    Data nsGuiWrapper_TTitleComponent_Data;
    nsGuiWrapper_TTitleComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TTitleComponent*) p, withNotify); };
    nsGuiWrapper_TTitleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTitleComponent*) p)); };
    nsGuiWrapper_TTitleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TTitleComponent>(eid, *((nsGuiWrapper::TTitleComponent*) p)); };
    nsGuiWrapper_TTitleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTitleComponent>(eid); };
    auto rtti_nsGuiWrapper_TTitleComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTitleComponent_Data, nsGuiWrapper_TTitleComponent_Data });
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
    nsGuiWrapper_TVisibilityComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TVisibilityComponent*) p, withNotify); };
    nsGuiWrapper_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVisibilityComponent*) p)); };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TVisibilityComponent>(eid, *((nsGuiWrapper::TVisibilityComponent*) p)); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    auto rtti_nsGuiWrapper_TVisibilityComponent_Data = globalTypeIdentifier->type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TVisibilityComponent_Data, nsGuiWrapper_TVisibilityComponent_Data });
    
    Data nsGuiWrapper_TWindowComponent_Data;
    nsGuiWrapper_TWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->CreateComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.applyChangesFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool withNotify){ pEntMng->ApplyChangesComponent(eid, (nsGuiWrapper::TWindowComponent*) p, withNotify); };
    nsGuiWrapper_TWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowComponent*) p)); };
    nsGuiWrapper_TWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsGuiWrapper::TWindowComponent>(eid, *((nsGuiWrapper::TWindowComponent*) p)); };
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
void* TComponentEntityManagerExtension::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].createFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::ApplyChangesComponent(TEntityManager* pEntMng, TEntityID eid, void* p, int rtti, bool withNotify)
{
    Init();
    mRttiVector[rtti].applyChangesFunc(pEntMng, eid, p, withNotify);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, void* p, int rtti)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
void* TComponentEntityManagerExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntityManagerExtension::GetComponent(TEntityManager* pEntMng, TEntityID eid, void*& p, int rtti)
{
    Init();
    return mRttiVector[rtti].getFunc(pEntMng, eid, p);
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
