/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_15 07:42:45.471
	
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
    auto rtti_nsCommonWrapper_TNameComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNameComponent_Data, nsCommonWrapper_TNameComponent_Data });
    
    Data nsCommonWrapper_TNeedDestroyPrefabComponent_Data;
        nsCommonWrapper_TNeedDestroyPrefabComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNeedDestroyPrefabComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedDestroyPrefabComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNeedDestroyPrefabComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedDestroyPrefabComponent*)p), isNotify); };
    nsCommonWrapper_TNeedDestroyPrefabComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedDestroyPrefabComponent>(eid); };
    nsCommonWrapper_TNeedDestroyPrefabComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedDestroyPrefabComponent>(eid); };
    nsCommonWrapper_TNeedDestroyPrefabComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedDestroyPrefabComponent>(eid); };
    auto rtti_nsCommonWrapper_TNeedDestroyPrefabComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyPrefabComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedDestroyPrefabComponent_Data, nsCommonWrapper_TNeedDestroyPrefabComponent_Data });
    
    Data nsCommonWrapper_TNeedDestroySceneComponent_Data;
        nsCommonWrapper_TNeedDestroySceneComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNeedDestroySceneComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedDestroySceneComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNeedDestroySceneComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedDestroySceneComponent*)p), isNotify); };
    nsCommonWrapper_TNeedDestroySceneComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedDestroySceneComponent>(eid); };
    nsCommonWrapper_TNeedDestroySceneComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedDestroySceneComponent>(eid); };
    nsCommonWrapper_TNeedDestroySceneComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedDestroySceneComponent>(eid); };
    auto rtti_nsCommonWrapper_TNeedDestroySceneComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroySceneComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedDestroySceneComponent_Data, nsCommonWrapper_TNeedDestroySceneComponent_Data });
    
    Data nsCommonWrapper_TNeedUnloadPrefabComponent_Data;
        nsCommonWrapper_TNeedUnloadPrefabComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNeedUnloadPrefabComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedUnloadPrefabComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNeedUnloadPrefabComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedUnloadPrefabComponent*)p), isNotify); };
    nsCommonWrapper_TNeedUnloadPrefabComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedUnloadPrefabComponent>(eid); };
    nsCommonWrapper_TNeedUnloadPrefabComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedUnloadPrefabComponent>(eid); };
    nsCommonWrapper_TNeedUnloadPrefabComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedUnloadPrefabComponent>(eid); };
    auto rtti_nsCommonWrapper_TNeedUnloadPrefabComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedUnloadPrefabComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedUnloadPrefabComponent_Data, nsCommonWrapper_TNeedUnloadPrefabComponent_Data });
    
    Data nsCommonWrapper_TNeedUnloadSceneComponent_Data;
        nsCommonWrapper_TNeedUnloadSceneComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TNeedUnloadSceneComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedUnloadSceneComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TNeedUnloadSceneComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedUnloadSceneComponent*)p), isNotify); };
    nsCommonWrapper_TNeedUnloadSceneComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedUnloadSceneComponent>(eid); };
    nsCommonWrapper_TNeedUnloadSceneComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedUnloadSceneComponent>(eid); };
    nsCommonWrapper_TNeedUnloadSceneComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedUnloadSceneComponent>(eid); };
    auto rtti_nsCommonWrapper_TNeedUnloadSceneComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedUnloadSceneComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedUnloadSceneComponent_Data, nsCommonWrapper_TNeedUnloadSceneComponent_Data });
    
    Data nsCommonWrapper_TObjectInMemoryComponent_Data;
        nsCommonWrapper_TObjectInMemoryComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TObjectInMemoryComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TObjectInMemoryComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TObjectInMemoryComponent*)p), isNotify); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
    nsCommonWrapper_TObjectInMemoryComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TObjectInMemoryComponent>(eid); };
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
    auto rtti_nsCommonWrapper_TPrefabRootComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabRootComponent_Data, nsCommonWrapper_TPrefabRootComponent_Data });
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
        nsCommonWrapper_TSceneGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsCommonWrapper::TSceneGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneGuidComponent>(eid, lambda, isNotify);
    };
    nsCommonWrapper_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneGuidComponent*)p), isNotify); };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
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
    auto rtti_nsCommonWrapper_TTransformComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TTransformComponent_Data, nsCommonWrapper_TTransformComponent_Data });
    
    Data nsGraphicWrapper_TCameraComponent_Data;
        nsGraphicWrapper_TCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraComponent*)p), isNotify); };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    auto rtti_nsGraphicWrapper_TCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraComponent_Data, nsGraphicWrapper_TCameraComponent_Data });
    
    Data nsGraphicWrapper_TLightComponent_Data;
        nsGraphicWrapper_TLightComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGraphicWrapper::TLightComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TLightComponent>(eid, lambda, isNotify);
    };
    nsGraphicWrapper_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TLightComponent*)p), isNotify); };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    auto rtti_nsGraphicWrapper_TLightComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TLightComponent_Data, nsGraphicWrapper_TLightComponent_Data });
    
    Data nsGuiWrapper_TButtonClickHandlerComponent_Data;
        nsGuiWrapper_TButtonClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TButtonClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonClickHandlerComponent*)p), isNotify); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
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
    auto rtti_nsGuiWrapper_TFrameComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameComponent_Data, nsGuiWrapper_TFrameComponent_Data });
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
        nsGuiWrapper_TMainWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TMainWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMainWindowComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TMainWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMainWindowComponent*)p), isNotify); };
    nsGuiWrapper_TMainWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    auto rtti_nsGuiWrapper_TMainWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMainWindowComponent_Data, nsGuiWrapper_TMainWindowComponent_Data });
    
    Data nsGuiWrapper_TPositionComponent_Data;
        nsGuiWrapper_TPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPositionComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionComponent*)p), isNotify); };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    auto rtti_nsGuiWrapper_TPositionComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionComponent_Data, nsGuiWrapper_TPositionComponent_Data });
    
    Data nsGuiWrapper_TSizeComponent_Data;
        nsGuiWrapper_TSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSizeComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeComponent*)p), isNotify); };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
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
    auto rtti_nsGuiWrapper_TTitleComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTitleComponent_Data, nsGuiWrapper_TTitleComponent_Data });
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
        nsGuiWrapper_TVisibilityComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsGuiWrapper::TVisibilityComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TVisibilityComponent>(eid, lambda, isNotify);
    };
    nsGuiWrapper_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVisibilityComponent*)p), isNotify); };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
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
    auto rtti_nsGuiWrapper_TWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowComponent_Data, nsGuiWrapper_TWindowComponent_Data });
    
    Data nsLogicWrapper_TFeatureComponent_Data;
        nsLogicWrapper_TFeatureComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TFeatureComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TFeatureComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TFeatureComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TFeatureComponent*)p), isNotify); };
    nsLogicWrapper_TFeatureComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TFeatureComponent>(eid); };
    nsLogicWrapper_TFeatureComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TFeatureComponent>(eid); };
    nsLogicWrapper_TFeatureComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TFeatureComponent>(eid); };
    auto rtti_nsLogicWrapper_TFeatureComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TFeatureComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TFeatureComponent_Data, nsLogicWrapper_TFeatureComponent_Data });
    
    Data nsLogicWrapper_TPrefabObjectReferenceComponent_Data;
        nsLogicWrapper_TPrefabObjectReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsLogicWrapper::TPrefabObjectReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid, lambda, isNotify);
    };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabObjectReferenceComponent*)p), isNotify); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
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
    auto rtti_nsLogicWrapper_TSceneReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneReferenceComponent_Data, nsLogicWrapper_TSceneReferenceComponent_Data });
    
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
