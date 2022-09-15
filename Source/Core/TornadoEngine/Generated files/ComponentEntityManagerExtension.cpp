/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_14 07:41:47.035
	
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
        nsCommonWrapper_TGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGuidComponent*)p), isNotify); };
    nsCommonWrapper_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TGuidComponent>(); };
    auto rtti_nsCommonWrapper_TGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TGuidComponent_Data, nsCommonWrapper_TGuidComponent_Data });
    
    Data nsCommonWrapper_TNameComponent_Data;
        nsCommonWrapper_TNameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNameComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNameComponent*)p), isNotify); };
    nsCommonWrapper_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNameComponent>(); };
    auto rtti_nsCommonWrapper_TNameComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNameComponent_Data, nsCommonWrapper_TNameComponent_Data });
    
    Data nsCommonWrapper_TNeedDestroyObjectTagComponent_Data;
        nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNeedDestroyObjectTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedDestroyObjectTagComponent*)p), isNotify); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNeedDestroyObjectTagComponent>(); };
    auto rtti_nsCommonWrapper_TNeedDestroyObjectTagComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedDestroyObjectTagComponent_Data, nsCommonWrapper_TNeedDestroyObjectTagComponent_Data });
    
    Data nsCommonWrapper_TObjectInMemoryComponent_Data;
        nsCommonWrapper_TObjectInMemoryComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TObjectInMemoryComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TObjectInMemoryComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TObjectInMemoryComponent*)p), isNotify); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TObjectInMemoryComponent>(); };
    auto rtti_nsCommonWrapper_TObjectInMemoryComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TObjectInMemoryComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TObjectInMemoryComponent_Data, nsCommonWrapper_TObjectInMemoryComponent_Data });
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
        nsCommonWrapper_TParentGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TParentGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TParentGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TParentGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TParentGuidComponent*)p), isNotify); };
    nsCommonWrapper_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TParentGuidComponent>(); };
    auto rtti_nsCommonWrapper_TParentGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TParentGuidComponent_Data, nsCommonWrapper_TParentGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabGuidComponent_Data;
        nsCommonWrapper_TPrefabGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TPrefabGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TPrefabGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabGuidComponent*)p), isNotify); };
    nsCommonWrapper_TPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabGuidComponent_Data, nsCommonWrapper_TPrefabGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabInstanceGuidComponent_Data;
        nsCommonWrapper_TPrefabInstanceGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TPrefabInstanceGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabInstanceGuidComponent*)p), isNotify); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabInstanceGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabInstanceGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabInstanceGuidComponent_Data, nsCommonWrapper_TPrefabInstanceGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabOriginalGuidComponent_Data;
        nsCommonWrapper_TPrefabOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TPrefabOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabOriginalGuidComponent*)p), isNotify); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabOriginalGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data, nsCommonWrapper_TPrefabOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabRootComponent_Data;
        nsCommonWrapper_TPrefabRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TPrefabRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabRootComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TPrefabRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabRootComponent*)p), isNotify); };
    nsCommonWrapper_TPrefabRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabRootComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabRootComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabRootComponent_Data, nsCommonWrapper_TPrefabRootComponent_Data });
    
    Data nsCommonWrapper_TProjectionToUniverseComponent_Data;
        nsCommonWrapper_TProjectionToUniverseComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TProjectionToUniverseComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TProjectionToUniverseComponent*)p), isNotify); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TProjectionToUniverseComponent>(); };
    auto rtti_nsCommonWrapper_TProjectionToUniverseComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TProjectionToUniverseComponent_Data, nsCommonWrapper_TProjectionToUniverseComponent_Data });
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
        nsCommonWrapper_TSceneGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TSceneGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneGuidComponent*)p), isNotify); };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneGuidComponent_Data, nsCommonWrapper_TSceneGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneInstanceGuidComponent_Data;
        nsCommonWrapper_TSceneInstanceGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TSceneInstanceGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneInstanceGuidComponent*)p), isNotify); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneInstanceGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneInstanceGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneInstanceGuidComponent_Data, nsCommonWrapper_TSceneInstanceGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneOriginalGuidComponent_Data;
        nsCommonWrapper_TSceneOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TSceneOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneOriginalGuidComponent*)p), isNotify); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneOriginalGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data, nsCommonWrapper_TSceneOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
        nsCommonWrapper_TSceneRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TSceneRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneRootComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TSceneRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneRootComponent*)p), isNotify); };
    nsCommonWrapper_TSceneRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneRootComponent>(); };
    auto rtti_nsCommonWrapper_TSceneRootComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneRootComponent_Data, nsCommonWrapper_TSceneRootComponent_Data });
    
    Data nsCommonWrapper_TTransformComponent_Data;
        nsCommonWrapper_TTransformComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TTransformComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TTransformComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TTransformComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TTransformComponent*)p), isNotify); };
    nsCommonWrapper_TTransformComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TTransformComponent>(eid); };
    nsCommonWrapper_TTransformComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TTransformComponent>(); };
    auto rtti_nsCommonWrapper_TTransformComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TTransformComponent_Data, nsCommonWrapper_TTransformComponent_Data });
    
    Data nsCommonWrapper_TUniverseGuidComponent_Data;
        nsCommonWrapper_TUniverseGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TUniverseGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TUniverseGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TUniverseGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseGuidComponent*)p), isNotify); };
    nsCommonWrapper_TUniverseGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseGuidComponent>(); };
    auto rtti_nsCommonWrapper_TUniverseGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TUniverseGuidComponent_Data, nsCommonWrapper_TUniverseGuidComponent_Data });
    
    Data nsCommonWrapper_TUniverseIndexComponent_Data;
        nsCommonWrapper_TUniverseIndexComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TUniverseIndexComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TUniverseIndexComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TUniverseIndexComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseIndexComponent*)p), isNotify); };
    nsCommonWrapper_TUniverseIndexComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseIndexComponent>(); };
    auto rtti_nsCommonWrapper_TUniverseIndexComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TUniverseIndexComponent_Data, nsCommonWrapper_TUniverseIndexComponent_Data });
    
    Data nsGraphicWrapper_TCameraComponent_Data;
        nsGraphicWrapper_TCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraComponent*)p), isNotify); };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraComponent_Data, nsGraphicWrapper_TCameraComponent_Data });
    
    Data nsGraphicWrapper_TCameraTextureTagComponent_Data;
        nsGraphicWrapper_TCameraTextureTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TCameraTextureTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraTextureTagComponent*)p), isNotify); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraTextureTagComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraTextureTagComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraTextureTagComponent_Data, nsGraphicWrapper_TCameraTextureTagComponent_Data });
    
    Data nsGraphicWrapper_TCameraWindowPositionComponent_Data;
        nsGraphicWrapper_TCameraWindowPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TCameraWindowPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowPositionComponent*)p), isNotify); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowPositionComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraWindowPositionComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraWindowPositionComponent_Data, nsGraphicWrapper_TCameraWindowPositionComponent_Data });
    
    Data nsGraphicWrapper_TCameraWindowSizeComponent_Data;
        nsGraphicWrapper_TCameraWindowSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TCameraWindowSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowSizeComponent*)p), isNotify); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowSizeComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraWindowSizeComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraWindowSizeComponent_Data, nsGraphicWrapper_TCameraWindowSizeComponent_Data });
    
    Data nsGraphicWrapper_TGuiCameraTagComponent_Data;
        nsGraphicWrapper_TGuiCameraTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TGuiCameraTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TGuiCameraTagComponent*)p), isNotify); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TGuiCameraTagComponent>(); };
    auto rtti_nsGraphicWrapper_TGuiCameraTagComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiCameraTagComponent_Data, nsGraphicWrapper_TGuiCameraTagComponent_Data });
    
    Data nsGraphicWrapper_TLightComponent_Data;
        nsGraphicWrapper_TLightComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TLightComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TLightComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TLightComponent*)p), isNotify); };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TLightComponent>(); };
    auto rtti_nsGraphicWrapper_TLightComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TLightComponent_Data, nsGraphicWrapper_TLightComponent_Data });
    
    Data nsGraphicWrapper_TRenderToTextureCameraComponent_Data;
        nsGraphicWrapper_TRenderToTextureCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TRenderToTextureCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TRenderToTextureCameraComponent*)p), isNotify); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TRenderToTextureCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TRenderToTextureCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TRenderToTextureCameraComponent_Data, nsGraphicWrapper_TRenderToTextureCameraComponent_Data });
    
    Data nsGraphicWrapper_TTextureFromCameraComponent_Data;
        nsGraphicWrapper_TTextureFromCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TTextureFromCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromCameraComponent*)p), isNotify); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TTextureFromCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureFromCameraComponent_Data, nsGraphicWrapper_TTextureFromCameraComponent_Data });
    
    Data nsGraphicWrapper_TTextureFromFileComponent_Data;
        nsGraphicWrapper_TTextureFromFileComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TTextureFromFileComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TTextureFromFileComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromFileComponent*)p), isNotify); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromFileComponent>(); };
    auto rtti_nsGraphicWrapper_TTextureFromFileComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureFromFileComponent_Data, nsGraphicWrapper_TTextureFromFileComponent_Data });
    
    Data nsGraphicWrapper_TUniverseCameraComponent_Data;
        nsGraphicWrapper_TUniverseCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TUniverseCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TUniverseCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TUniverseCameraComponent*)p), isNotify); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TUniverseCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TUniverseCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TUniverseCameraComponent_Data, nsGraphicWrapper_TUniverseCameraComponent_Data });
    
    Data nsGuiWrapper_TButtonClickHandlerComponent_Data;
        nsGuiWrapper_TButtonClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TButtonClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonClickHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TButtonClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data, nsGuiWrapper_TButtonClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TButtonComponent_Data;
        nsGuiWrapper_TButtonComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TButtonComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TButtonComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonComponent*)p), isNotify); };
    nsGuiWrapper_TButtonComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TButtonComponent>(); };
    auto rtti_nsGuiWrapper_TButtonComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonComponent_Data, nsGuiWrapper_TButtonComponent_Data });
    
    Data nsGuiWrapper_TDialogCloseEventHandlerComponent_Data;
        nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TDialogCloseEventHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TDialogCloseEventHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TDialogCloseEventHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TDialogCloseEventHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TDialogCloseEventHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TDialogCloseEventHandlerComponent_Data, nsGuiWrapper_TDialogCloseEventHandlerComponent_Data });
    
    Data nsGuiWrapper_TDialogComponent_Data;
        nsGuiWrapper_TDialogComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TDialogComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TDialogComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TDialogComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TDialogComponent*)p), isNotify); };
    nsGuiWrapper_TDialogComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TDialogComponent>(); };
    auto rtti_nsGuiWrapper_TDialogComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TDialogComponent_Data, nsGuiWrapper_TDialogComponent_Data });
    
    Data nsGuiWrapper_TFocusComponent_Data;
        nsGuiWrapper_TFocusComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFocusComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFocusComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFocusComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFocusComponent*)p), isNotify); };
    nsGuiWrapper_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFocusComponent>(); };
    auto rtti_nsGuiWrapper_TFocusComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFocusComponent_Data, nsGuiWrapper_TFocusComponent_Data });
    
    Data nsGuiWrapper_TFrameComponent_Data;
        nsGuiWrapper_TFrameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFrameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFrameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameComponent*)p), isNotify); };
    nsGuiWrapper_TFrameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameComponent>(); };
    auto rtti_nsGuiWrapper_TFrameComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameComponent_Data, nsGuiWrapper_TFrameComponent_Data });
    
    Data nsGuiWrapper_TFrameKeyHandlerComponent_Data;
        nsGuiWrapper_TFrameKeyHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFrameKeyHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameKeyHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameKeyHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameKeyHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameKeyHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameKeyHandlerComponent_Data, nsGuiWrapper_TFrameKeyHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseClickHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseClickHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseClickHandlerComponent_Data, nsGuiWrapper_TFrameMouseClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseMoveHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseMoveHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseMoveHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data, nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseWheelHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseWheelHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseWheelHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data, nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data });
    
    Data nsGuiWrapper_TInputTextComponent_Data;
        nsGuiWrapper_TInputTextComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TInputTextComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TInputTextComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TInputTextComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextComponent*)p), isNotify); };
    nsGuiWrapper_TInputTextComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextComponent>(); };
    auto rtti_nsGuiWrapper_TInputTextComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TInputTextComponent_Data, nsGuiWrapper_TInputTextComponent_Data });
    
    Data nsGuiWrapper_TInputTextValueComponent_Data;
        nsGuiWrapper_TInputTextValueComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TInputTextValueComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TInputTextValueComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TInputTextValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextValueComponent*)p), isNotify); };
    nsGuiWrapper_TInputTextValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextValueComponent>(); };
    auto rtti_nsGuiWrapper_TInputTextValueComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TInputTextValueComponent_Data, nsGuiWrapper_TInputTextValueComponent_Data });
    
    Data nsGuiWrapper_TLabelComponent_Data;
        nsGuiWrapper_TLabelComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TLabelComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TLabelComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TLabelComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelComponent*)p), isNotify); };
    nsGuiWrapper_TLabelComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelComponent>(); };
    auto rtti_nsGuiWrapper_TLabelComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TLabelComponent_Data, nsGuiWrapper_TLabelComponent_Data });
    
    Data nsGuiWrapper_TLabelValueComponent_Data;
        nsGuiWrapper_TLabelValueComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TLabelValueComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TLabelValueComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TLabelValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelValueComponent*)p), isNotify); };
    nsGuiWrapper_TLabelValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelValueComponent>(); };
    auto rtti_nsGuiWrapper_TLabelValueComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TLabelValueComponent_Data, nsGuiWrapper_TLabelValueComponent_Data });
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
        nsGuiWrapper_TMainWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TMainWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMainWindowComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TMainWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMainWindowComponent*)p), isNotify); };
    nsGuiWrapper_TMainWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMainWindowComponent>(); };
    auto rtti_nsGuiWrapper_TMainWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMainWindowComponent_Data, nsGuiWrapper_TMainWindowComponent_Data });
    
    Data nsGuiWrapper_TMenuNodeClickHandlerComponent_Data;
        nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TMenuNodeClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMenuNodeClickHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMenuNodeClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TMenuNodeClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMenuNodeClickHandlerComponent_Data, nsGuiWrapper_TMenuNodeClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TMenuNodeComponent_Data;
        nsGuiWrapper_TMenuNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TMenuNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMenuNodeComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TMenuNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMenuNodeComponent*)p), isNotify); };
    nsGuiWrapper_TMenuNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMenuNodeComponent>(); };
    auto rtti_nsGuiWrapper_TMenuNodeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMenuNodeComponent_Data, nsGuiWrapper_TMenuNodeComponent_Data });
    
    Data nsGuiWrapper_TNodeIconComponent_Data;
        nsGuiWrapper_TNodeIconComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TNodeIconComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TNodeIconComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TNodeIconComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TNodeIconComponent*)p), isNotify); };
    nsGuiWrapper_TNodeIconComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TNodeIconComponent>(); };
    auto rtti_nsGuiWrapper_TNodeIconComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TNodeIconComponent_Data, nsGuiWrapper_TNodeIconComponent_Data });
    
    Data nsGuiWrapper_TPositionComponent_Data;
        nsGuiWrapper_TPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPositionComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionComponent*)p), isNotify); };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPositionComponent>(); };
    auto rtti_nsGuiWrapper_TPositionComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionComponent_Data, nsGuiWrapper_TPositionComponent_Data });
    
    Data nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data;
        nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TSelectedTreeNodeGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSelectedTreeNodeGuidComponent*)p), isNotify); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(); };
    auto rtti_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data, nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data });
    
    Data nsGuiWrapper_TSizeComponent_Data;
        nsGuiWrapper_TSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSizeComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeComponent*)p), isNotify); };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSizeComponent>(); };
    auto rtti_nsGuiWrapper_TSizeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSizeComponent_Data, nsGuiWrapper_TSizeComponent_Data });
    
    Data nsGuiWrapper_TTitleComponent_Data;
        nsGuiWrapper_TTitleComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TTitleComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTitleComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TTitleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTitleComponent*)p), isNotify); };
    nsGuiWrapper_TTitleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTitleComponent>(); };
    auto rtti_nsGuiWrapper_TTitleComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTitleComponent_Data, nsGuiWrapper_TTitleComponent_Data });
    
    Data nsGuiWrapper_TTreeNodeComponent_Data;
        nsGuiWrapper_TTreeNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TTreeNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTreeNodeComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TTreeNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeNodeComponent*)p), isNotify); };
    nsGuiWrapper_TTreeNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeNodeComponent>(); };
    auto rtti_nsGuiWrapper_TTreeNodeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTreeNodeComponent_Data, nsGuiWrapper_TTreeNodeComponent_Data });
    
    Data nsGuiWrapper_TTreeViewComponent_Data;
        nsGuiWrapper_TTreeViewComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TTreeViewComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTreeViewComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TTreeViewComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeViewComponent*)p), isNotify); };
    nsGuiWrapper_TTreeViewComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeViewComponent>(); };
    auto rtti_nsGuiWrapper_TTreeViewComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTreeViewComponent_Data, nsGuiWrapper_TTreeViewComponent_Data });
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
        nsGuiWrapper_TVisibilityComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TVisibilityComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TVisibilityComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVisibilityComponent*)p), isNotify); };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TVisibilityComponent>(); };
    auto rtti_nsGuiWrapper_TVisibilityComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TVisibilityComponent_Data, nsGuiWrapper_TVisibilityComponent_Data });
    
    Data nsGuiWrapper_TWindowCloseEventHandlerComponent_Data;
        nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TWindowCloseEventHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowCloseEventHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TWindowCloseEventHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TWindowCloseEventHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TWindowCloseEventHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowCloseEventHandlerComponent_Data, nsGuiWrapper_TWindowCloseEventHandlerComponent_Data });
    
    Data nsGuiWrapper_TWindowComponent_Data;
        nsGuiWrapper_TWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TWindowComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowComponent*)p), isNotify); };
    nsGuiWrapper_TWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TWindowComponent>(); };
    auto rtti_nsGuiWrapper_TWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowComponent_Data, nsGuiWrapper_TWindowComponent_Data });
    
    Data nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data;
        nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TObjectInstanceEndHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TObjectInstanceEndHandlerComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TObjectInstanceEndHandlerComponent*)p), isNotify); };
    nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TObjectInstanceEndHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TObjectInstanceEndHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TObjectInstanceEndHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TObjectInstanceEndHandlerComponent>(); };
    auto rtti_nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data, nsLogicWrapper_TObjectInstanceEndHandlerComponent_Data });
    
    Data nsLogicWrapper_TPrefabObjectReferenceComponent_Data;
        nsLogicWrapper_TPrefabObjectReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TPrefabObjectReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabObjectReferenceComponent*)p), isNotify); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabObjectReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TPrefabObjectReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TPrefabObjectReferenceComponent_Data, nsLogicWrapper_TPrefabObjectReferenceComponent_Data });
    
    Data nsLogicWrapper_TPrefabReferenceComponent_Data;
        nsLogicWrapper_TPrefabReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TPrefabReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TPrefabReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabReferenceComponent*)p), isNotify); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TPrefabReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TPrefabReferenceComponent_Data, nsLogicWrapper_TPrefabReferenceComponent_Data });
    
    Data nsLogicWrapper_TSceneObjectReferenceComponent_Data;
        nsLogicWrapper_TSceneObjectReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TSceneObjectReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneObjectReferenceComponent*)p), isNotify); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneObjectReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TSceneObjectReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneObjectReferenceComponent_Data, nsLogicWrapper_TSceneObjectReferenceComponent_Data });
    
    Data nsLogicWrapper_TSceneReferenceComponent_Data;
        nsLogicWrapper_TSceneReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TSceneReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSceneReferenceComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TSceneReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneReferenceComponent*)p), isNotify); };
    nsLogicWrapper_TSceneReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TSceneReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneReferenceComponent_Data, nsLogicWrapper_TSceneReferenceComponent_Data });
    
    Data nsLogicWrapper_TSystemComponent_Data;
        nsLogicWrapper_TSystemComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TSystemComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSystemComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TSystemComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSystemComponent*)p), isNotify); };
    nsLogicWrapper_TSystemComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSystemComponent>(); };
    auto rtti_nsLogicWrapper_TSystemComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSystemComponent_Data, nsLogicWrapper_TSystemComponent_Data });
    
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
void TComponentEntityManagerExtension::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation, bool isNotify)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation, isNotify);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p, bool isNotify)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p, isNotify);
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
nsECSFramework::TEntityList TComponentEntityManagerExtension::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
