/*
Core Component
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_08_29 09:06:46.286
	
#include "ComponentEntMng.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

std::vector<TComponentEntMng::Data> TComponentEntMng::mRttiVector;

void TComponentEntMng::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsCommonWrapper_TGlobalMatrixComponent_Data;
        nsCommonWrapper_TGlobalMatrixComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TGlobalMatrixComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid, lambda);
    };
    nsCommonWrapper_TGlobalMatrixComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGlobalMatrixComponent*)p)); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TGlobalMatrixComponent>(); };
    auto rtti_nsCommonWrapper_TGlobalMatrixComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TGlobalMatrixComponent_Data, nsCommonWrapper_TGlobalMatrixComponent_Data });
    
    Data nsCommonWrapper_TGuidComponent_Data;
        nsCommonWrapper_TGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGuidComponent*)p)); };
    nsCommonWrapper_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TGuidComponent>(); };
    auto rtti_nsCommonWrapper_TGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TGuidComponent_Data, nsCommonWrapper_TGuidComponent_Data });
    
    Data nsCommonWrapper_TNameComponent_Data;
        nsCommonWrapper_TNameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TNameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNameComponent>(eid, lambda);
    };
    nsCommonWrapper_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNameComponent*)p)); };
    nsCommonWrapper_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNameComponent>(); };
    auto rtti_nsCommonWrapper_TNameComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNameComponent_Data, nsCommonWrapper_TNameComponent_Data });
    
    Data nsCommonWrapper_TNeedDestroyObjectTagComponent_Data;
        nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TNeedDestroyObjectTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid, lambda);
    };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedDestroyObjectTagComponent*)p)); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNeedDestroyObjectTagComponent>(); };
    auto rtti_nsCommonWrapper_TNeedDestroyObjectTagComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TNeedDestroyObjectTagComponent_Data, nsCommonWrapper_TNeedDestroyObjectTagComponent_Data });
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
        nsCommonWrapper_TParentGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TParentGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TParentGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TParentGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TParentGuidComponent*)p)); };
    nsCommonWrapper_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TParentGuidComponent>(); };
    auto rtti_nsCommonWrapper_TParentGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TParentGuidComponent_Data, nsCommonWrapper_TParentGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabGuidComponent_Data;
        nsCommonWrapper_TPrefabGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabGuidComponent*)p)); };
    nsCommonWrapper_TPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabGuidComponent_Data, nsCommonWrapper_TPrefabGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabInstanceGuidComponent_Data;
        nsCommonWrapper_TPrefabInstanceGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabInstanceGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabInstanceGuidComponent*)p)); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabInstanceGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabInstanceGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabInstanceGuidComponent_Data, nsCommonWrapper_TPrefabInstanceGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabOriginalGuidComponent_Data;
        nsCommonWrapper_TPrefabOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabOriginalGuidComponent*)p)); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabOriginalGuidComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabOriginalGuidComponent_Data, nsCommonWrapper_TPrefabOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TPrefabRootComponent_Data;
        nsCommonWrapper_TPrefabRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TPrefabRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TPrefabRootComponent>(eid, lambda);
    };
    nsCommonWrapper_TPrefabRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabRootComponent*)p)); };
    nsCommonWrapper_TPrefabRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabRootComponent>(); };
    auto rtti_nsCommonWrapper_TPrefabRootComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TPrefabRootComponent_Data, nsCommonWrapper_TPrefabRootComponent_Data });
    
    Data nsCommonWrapper_TProjectionToUniverseComponent_Data;
        nsCommonWrapper_TProjectionToUniverseComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TProjectionToUniverseComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid, lambda);
    };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TProjectionToUniverseComponent*)p)); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TProjectionToUniverseComponent>(); };
    auto rtti_nsCommonWrapper_TProjectionToUniverseComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TProjectionToUniverseComponent_Data, nsCommonWrapper_TProjectionToUniverseComponent_Data });
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
        nsCommonWrapper_TSceneGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneGuidComponent*)p)); };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneGuidComponent_Data, nsCommonWrapper_TSceneGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneInstanceGuidComponent_Data;
        nsCommonWrapper_TSceneInstanceGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneInstanceGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneInstanceGuidComponent*)p)); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneInstanceGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneInstanceGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneInstanceGuidComponent_Data, nsCommonWrapper_TSceneInstanceGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneOriginalGuidComponent_Data;
        nsCommonWrapper_TSceneOriginalGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneOriginalGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneOriginalGuidComponent*)p)); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneOriginalGuidComponent>(); };
    auto rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneOriginalGuidComponent_Data, nsCommonWrapper_TSceneOriginalGuidComponent_Data });
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
        nsCommonWrapper_TSceneRootComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TSceneRootComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TSceneRootComponent>(eid, lambda);
    };
    nsCommonWrapper_TSceneRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneRootComponent*)p)); };
    nsCommonWrapper_TSceneRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneRootComponent>(); };
    auto rtti_nsCommonWrapper_TSceneRootComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TSceneRootComponent_Data, nsCommonWrapper_TSceneRootComponent_Data });
    
    Data nsCommonWrapper_TUniverseGuidComponent_Data;
        nsCommonWrapper_TUniverseGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TUniverseGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TUniverseGuidComponent>(eid, lambda);
    };
    nsCommonWrapper_TUniverseGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseGuidComponent*)p)); };
    nsCommonWrapper_TUniverseGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseGuidComponent>(); };
    auto rtti_nsCommonWrapper_TUniverseGuidComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TUniverseGuidComponent_Data, nsCommonWrapper_TUniverseGuidComponent_Data });
    
    Data nsCommonWrapper_TUniverseIndexComponent_Data;
        nsCommonWrapper_TUniverseIndexComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsCommonWrapper::TUniverseIndexComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsCommonWrapper::TUniverseIndexComponent>(eid, lambda);
    };
    nsCommonWrapper_TUniverseIndexComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseIndexComponent*)p)); };
    nsCommonWrapper_TUniverseIndexComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseIndexComponent>(); };
    auto rtti_nsCommonWrapper_TUniverseIndexComponent_Data = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    m.insert({ rtti_nsCommonWrapper_TUniverseIndexComponent_Data, nsCommonWrapper_TUniverseIndexComponent_Data });
    
    Data nsGraphicWrapper_TCameraComponent_Data;
        nsGraphicWrapper_TCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraComponent>(eid, lambda);
    };
    nsGraphicWrapper_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraComponent*)p)); };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraComponent_Data, nsGraphicWrapper_TCameraComponent_Data });
    
    Data nsGraphicWrapper_TCameraTextureTagComponent_Data;
        nsGraphicWrapper_TCameraTextureTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TCameraTextureTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid, lambda);
    };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraTextureTagComponent*)p)); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraTextureTagComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraTextureTagComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraTextureTagComponent_Data, nsGraphicWrapper_TCameraTextureTagComponent_Data });
    
    Data nsGraphicWrapper_TCameraWindowPositionComponent_Data;
        nsGraphicWrapper_TCameraWindowPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TCameraWindowPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid, lambda);
    };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowPositionComponent*)p)); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowPositionComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraWindowPositionComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraWindowPositionComponent_Data, nsGraphicWrapper_TCameraWindowPositionComponent_Data });
    
    Data nsGraphicWrapper_TCameraWindowSizeComponent_Data;
        nsGraphicWrapper_TCameraWindowSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TCameraWindowSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid, lambda);
    };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowSizeComponent*)p)); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowSizeComponent>(); };
    auto rtti_nsGraphicWrapper_TCameraWindowSizeComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TCameraWindowSizeComponent_Data, nsGraphicWrapper_TCameraWindowSizeComponent_Data });
    
    Data nsGraphicWrapper_TGuiCameraTagComponent_Data;
        nsGraphicWrapper_TGuiCameraTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TGuiCameraTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid, lambda);
    };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TGuiCameraTagComponent*)p)); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TGuiCameraTagComponent>(); };
    auto rtti_nsGraphicWrapper_TGuiCameraTagComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TGuiCameraTagComponent_Data, nsGraphicWrapper_TGuiCameraTagComponent_Data });
    
    Data nsGraphicWrapper_TLightComponent_Data;
        nsGraphicWrapper_TLightComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TLightComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TLightComponent>(eid, lambda);
    };
    nsGraphicWrapper_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TLightComponent*)p)); };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TLightComponent>(); };
    auto rtti_nsGraphicWrapper_TLightComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TLightComponent_Data, nsGraphicWrapper_TLightComponent_Data });
    
    Data nsGraphicWrapper_TRenderToTextureCameraComponent_Data;
        nsGraphicWrapper_TRenderToTextureCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TRenderToTextureCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid, lambda);
    };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TRenderToTextureCameraComponent*)p)); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TRenderToTextureCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TRenderToTextureCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TRenderToTextureCameraComponent_Data, nsGraphicWrapper_TRenderToTextureCameraComponent_Data });
    
    Data nsGraphicWrapper_TTextureFromCameraComponent_Data;
        nsGraphicWrapper_TTextureFromCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TTextureFromCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid, lambda);
    };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromCameraComponent*)p)); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TTextureFromCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureFromCameraComponent_Data, nsGraphicWrapper_TTextureFromCameraComponent_Data });
    
    Data nsGraphicWrapper_TTextureFromFileComponent_Data;
        nsGraphicWrapper_TTextureFromFileComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TTextureFromFileComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid, lambda);
    };
    nsGraphicWrapper_TTextureFromFileComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromFileComponent*)p)); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromFileComponent>(); };
    auto rtti_nsGraphicWrapper_TTextureFromFileComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TTextureFromFileComponent_Data, nsGraphicWrapper_TTextureFromFileComponent_Data });
    
    Data nsGraphicWrapper_TUniverseCameraComponent_Data;
        nsGraphicWrapper_TUniverseCameraComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGraphicWrapper::TUniverseCameraComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid, lambda);
    };
    nsGraphicWrapper_TUniverseCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TUniverseCameraComponent*)p)); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TUniverseCameraComponent>(); };
    auto rtti_nsGraphicWrapper_TUniverseCameraComponent_Data = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    m.insert({ rtti_nsGraphicWrapper_TUniverseCameraComponent_Data, nsGraphicWrapper_TUniverseCameraComponent_Data });
    
    Data nsGuiWrapper_TAnchorsComponent_Data;
        nsGuiWrapper_TAnchorsComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TAnchorsComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TAnchorsComponent>(eid, lambda);
    };
    nsGuiWrapper_TAnchorsComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TAnchorsComponent*)p)); };
    nsGuiWrapper_TAnchorsComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TAnchorsComponent>(); };
    auto rtti_nsGuiWrapper_TAnchorsComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TAnchorsComponent_Data, nsGuiWrapper_TAnchorsComponent_Data });
    
    Data nsGuiWrapper_TButtonClickHandlerComponent_Data;
        nsGuiWrapper_TButtonClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TButtonClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonClickHandlerComponent*)p)); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonClickHandlerComponent>(eid); };
    nsGuiWrapper_TButtonClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TButtonClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonClickHandlerComponent_Data, nsGuiWrapper_TButtonClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TButtonComponent_Data;
        nsGuiWrapper_TButtonComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TButtonComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TButtonComponent>(eid, lambda);
    };
    nsGuiWrapper_TButtonComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonComponent*)p)); };
    nsGuiWrapper_TButtonComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TButtonComponent>(); };
    auto rtti_nsGuiWrapper_TButtonComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TButtonComponent_Data, nsGuiWrapper_TButtonComponent_Data });
    
    Data nsGuiWrapper_TColorComponent_Data;
        nsGuiWrapper_TColorComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TColorComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TColorComponent>(eid, lambda);
    };
    nsGuiWrapper_TColorComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TColorComponent*)p)); };
    nsGuiWrapper_TColorComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TColorComponent>(); };
    auto rtti_nsGuiWrapper_TColorComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TColorComponent_Data, nsGuiWrapper_TColorComponent_Data });
    
    Data nsGuiWrapper_TDialogCloseEventHandlerComponent_Data;
        nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TDialogCloseEventHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TDialogCloseEventHandlerComponent*)p)); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TDialogCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TDialogCloseEventHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TDialogCloseEventHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TDialogCloseEventHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TDialogCloseEventHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TDialogCloseEventHandlerComponent_Data, nsGuiWrapper_TDialogCloseEventHandlerComponent_Data });
    
    Data nsGuiWrapper_TDialogComponent_Data;
        nsGuiWrapper_TDialogComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TDialogComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TDialogComponent>(eid, lambda);
    };
    nsGuiWrapper_TDialogComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TDialogComponent*)p)); };
    nsGuiWrapper_TDialogComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TDialogComponent>(); };
    auto rtti_nsGuiWrapper_TDialogComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TDialogComponent_Data, nsGuiWrapper_TDialogComponent_Data });
    
    Data nsGuiWrapper_TFocusComponent_Data;
        nsGuiWrapper_TFocusComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFocusComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFocusComponent>(eid, lambda);
    };
    nsGuiWrapper_TFocusComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFocusComponent*)p)); };
    nsGuiWrapper_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFocusComponent>(); };
    auto rtti_nsGuiWrapper_TFocusComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFocusComponent_Data, nsGuiWrapper_TFocusComponent_Data });
    
    Data nsGuiWrapper_TFrameComponent_Data;
        nsGuiWrapper_TFrameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameComponent*)p)); };
    nsGuiWrapper_TFrameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameComponent>(); };
    auto rtti_nsGuiWrapper_TFrameComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameComponent_Data, nsGuiWrapper_TFrameComponent_Data });
    
    Data nsGuiWrapper_TFrameKeyHandlerComponent_Data;
        nsGuiWrapper_TFrameKeyHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameKeyHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameKeyHandlerComponent*)p)); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameKeyHandlerComponent>(eid); };
    nsGuiWrapper_TFrameKeyHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameKeyHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameKeyHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameKeyHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameKeyHandlerComponent_Data, nsGuiWrapper_TFrameKeyHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseClickHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseClickHandlerComponent*)p)); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseClickHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseClickHandlerComponent_Data, nsGuiWrapper_TFrameMouseClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseMoveHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseMoveHandlerComponent*)p)); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseMoveHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data, nsGuiWrapper_TFrameMouseMoveHandlerComponent_Data });
    
    Data nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data;
        nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TFrameMouseWheelHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameMouseWheelHandlerComponent*)p)); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(eid); };
    nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseWheelHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data, nsGuiWrapper_TFrameMouseWheelHandlerComponent_Data });
    
    Data nsGuiWrapper_TGridComponent_Data;
        nsGuiWrapper_TGridComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TGridComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TGridComponent>(eid, lambda);
    };
    nsGuiWrapper_TGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TGridComponent*)p)); };
    nsGuiWrapper_TGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TGridComponent>(); };
    auto rtti_nsGuiWrapper_TGridComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TGridComponent_Data, nsGuiWrapper_TGridComponent_Data });
    
    Data nsGuiWrapper_THorizontalAlignComponent_Data;
        nsGuiWrapper_THorizontalAlignComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::THorizontalAlignComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::THorizontalAlignComponent>(eid, lambda);
    };
    nsGuiWrapper_THorizontalAlignComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::THorizontalAlignComponent*)p)); };
    nsGuiWrapper_THorizontalAlignComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::THorizontalAlignComponent>(); };
    auto rtti_nsGuiWrapper_THorizontalAlignComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    m.insert({ rtti_nsGuiWrapper_THorizontalAlignComponent_Data, nsGuiWrapper_THorizontalAlignComponent_Data });
    
    Data nsGuiWrapper_TInputTextComponent_Data;
        nsGuiWrapper_TInputTextComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TInputTextComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TInputTextComponent>(eid, lambda);
    };
    nsGuiWrapper_TInputTextComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextComponent*)p)); };
    nsGuiWrapper_TInputTextComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextComponent>(); };
    auto rtti_nsGuiWrapper_TInputTextComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TInputTextComponent_Data, nsGuiWrapper_TInputTextComponent_Data });
    
    Data nsGuiWrapper_TInputTextValueComponent_Data;
        nsGuiWrapper_TInputTextValueComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TInputTextValueComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TInputTextValueComponent>(eid, lambda);
    };
    nsGuiWrapper_TInputTextValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextValueComponent*)p)); };
    nsGuiWrapper_TInputTextValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextValueComponent>(); };
    auto rtti_nsGuiWrapper_TInputTextValueComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TInputTextValueComponent_Data, nsGuiWrapper_TInputTextValueComponent_Data });
    
    Data nsGuiWrapper_TLabelComponent_Data;
        nsGuiWrapper_TLabelComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TLabelComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TLabelComponent>(eid, lambda);
    };
    nsGuiWrapper_TLabelComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelComponent*)p)); };
    nsGuiWrapper_TLabelComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelComponent>(); };
    auto rtti_nsGuiWrapper_TLabelComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TLabelComponent_Data, nsGuiWrapper_TLabelComponent_Data });
    
    Data nsGuiWrapper_TLabelValueComponent_Data;
        nsGuiWrapper_TLabelValueComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TLabelValueComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TLabelValueComponent>(eid, lambda);
    };
    nsGuiWrapper_TLabelValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelValueComponent*)p)); };
    nsGuiWrapper_TLabelValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelValueComponent>(); };
    auto rtti_nsGuiWrapper_TLabelValueComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TLabelValueComponent_Data, nsGuiWrapper_TLabelValueComponent_Data });
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
        nsGuiWrapper_TMainWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMainWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMainWindowComponent>(eid, lambda);
    };
    nsGuiWrapper_TMainWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMainWindowComponent*)p)); };
    nsGuiWrapper_TMainWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMainWindowComponent>(); };
    auto rtti_nsGuiWrapper_TMainWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMainWindowComponent_Data, nsGuiWrapper_TMainWindowComponent_Data });
    
    Data nsGuiWrapper_TMaxSizeComponent_Data;
        nsGuiWrapper_TMaxSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMaxSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMaxSizeComponent>(eid, lambda);
    };
    nsGuiWrapper_TMaxSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMaxSizeComponent*)p)); };
    nsGuiWrapper_TMaxSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMaxSizeComponent>(); };
    auto rtti_nsGuiWrapper_TMaxSizeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMaxSizeComponent_Data, nsGuiWrapper_TMaxSizeComponent_Data });
    
    Data nsGuiWrapper_TMenuNodeClickHandlerComponent_Data;
        nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMenuNodeClickHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMenuNodeClickHandlerComponent*)p)); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMenuNodeClickHandlerComponent>(eid); };
    nsGuiWrapper_TMenuNodeClickHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMenuNodeClickHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TMenuNodeClickHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeClickHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMenuNodeClickHandlerComponent_Data, nsGuiWrapper_TMenuNodeClickHandlerComponent_Data });
    
    Data nsGuiWrapper_TMenuNodeComponent_Data;
        nsGuiWrapper_TMenuNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMenuNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMenuNodeComponent>(eid, lambda);
    };
    nsGuiWrapper_TMenuNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMenuNodeComponent*)p)); };
    nsGuiWrapper_TMenuNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMenuNodeComponent>(); };
    auto rtti_nsGuiWrapper_TMenuNodeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMenuNodeComponent_Data, nsGuiWrapper_TMenuNodeComponent_Data });
    
    Data nsGuiWrapper_TMinDistanceToParentComponent_Data;
        nsGuiWrapper_TMinDistanceToParentComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMinDistanceToParentComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid, lambda);
    };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMinDistanceToParentComponent*)p)); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMinDistanceToParentComponent>(); };
    auto rtti_nsGuiWrapper_TMinDistanceToParentComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMinDistanceToParentComponent_Data, nsGuiWrapper_TMinDistanceToParentComponent_Data });
    
    Data nsGuiWrapper_TMinSizeComponent_Data;
        nsGuiWrapper_TMinSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TMinSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TMinSizeComponent>(eid, lambda);
    };
    nsGuiWrapper_TMinSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMinSizeComponent*)p)); };
    nsGuiWrapper_TMinSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMinSizeComponent>(); };
    auto rtti_nsGuiWrapper_TMinSizeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TMinSizeComponent_Data, nsGuiWrapper_TMinSizeComponent_Data });
    
    Data nsGuiWrapper_TNodeIconComponent_Data;
        nsGuiWrapper_TNodeIconComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TNodeIconComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TNodeIconComponent>(eid, lambda);
    };
    nsGuiWrapper_TNodeIconComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TNodeIconComponent*)p)); };
    nsGuiWrapper_TNodeIconComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TNodeIconComponent>(); };
    auto rtti_nsGuiWrapper_TNodeIconComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TNodeIconComponent_Data, nsGuiWrapper_TNodeIconComponent_Data });
    
    Data nsGuiWrapper_TPaddingComponent_Data;
        nsGuiWrapper_TPaddingComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TPaddingComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPaddingComponent>(eid, lambda);
    };
    nsGuiWrapper_TPaddingComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPaddingComponent*)p)); };
    nsGuiWrapper_TPaddingComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPaddingComponent>(); };
    auto rtti_nsGuiWrapper_TPaddingComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPaddingComponent_Data, nsGuiWrapper_TPaddingComponent_Data });
    
    Data nsGuiWrapper_TPositionComponent_Data;
        nsGuiWrapper_TPositionComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TPositionComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPositionComponent>(eid, lambda);
    };
    nsGuiWrapper_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionComponent*)p)); };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPositionComponent>(); };
    auto rtti_nsGuiWrapper_TPositionComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionComponent_Data, nsGuiWrapper_TPositionComponent_Data });
    
    Data nsGuiWrapper_TPositionInGridComponent_Data;
        nsGuiWrapper_TPositionInGridComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TPositionInGridComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TPositionInGridComponent>(eid, lambda);
    };
    nsGuiWrapper_TPositionInGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionInGridComponent*)p)); };
    nsGuiWrapper_TPositionInGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPositionInGridComponent>(); };
    auto rtti_nsGuiWrapper_TPositionInGridComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TPositionInGridComponent_Data, nsGuiWrapper_TPositionInGridComponent_Data });
    
    Data nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data;
        nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TSelectedTreeNodeGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid, lambda);
    };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSelectedTreeNodeGuidComponent*)p)); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(); };
    auto rtti_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data, nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data });
    
    Data nsGuiWrapper_TSizeComponent_Data;
        nsGuiWrapper_TSizeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TSizeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSizeComponent>(eid, lambda);
    };
    nsGuiWrapper_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeComponent*)p)); };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSizeComponent>(); };
    auto rtti_nsGuiWrapper_TSizeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSizeComponent_Data, nsGuiWrapper_TSizeComponent_Data });
    
    Data nsGuiWrapper_TSizeInGridComponent_Data;
        nsGuiWrapper_TSizeInGridComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TSizeInGridComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSizeInGridComponent>(eid, lambda);
    };
    nsGuiWrapper_TSizeInGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeInGridComponent*)p)); };
    nsGuiWrapper_TSizeInGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSizeInGridComponent>(); };
    auto rtti_nsGuiWrapper_TSizeInGridComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSizeInGridComponent_Data, nsGuiWrapper_TSizeInGridComponent_Data });
    
    Data nsGuiWrapper_TSpacingComponent_Data;
        nsGuiWrapper_TSpacingComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TSpacingComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TSpacingComponent>(eid, lambda);
    };
    nsGuiWrapper_TSpacingComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSpacingComponent*)p)); };
    nsGuiWrapper_TSpacingComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSpacingComponent>(); };
    auto rtti_nsGuiWrapper_TSpacingComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TSpacingComponent_Data, nsGuiWrapper_TSpacingComponent_Data });
    
    Data nsGuiWrapper_TTitleComponent_Data;
        nsGuiWrapper_TTitleComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TTitleComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTitleComponent>(eid, lambda);
    };
    nsGuiWrapper_TTitleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTitleComponent*)p)); };
    nsGuiWrapper_TTitleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTitleComponent>(); };
    auto rtti_nsGuiWrapper_TTitleComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTitleComponent_Data, nsGuiWrapper_TTitleComponent_Data });
    
    Data nsGuiWrapper_TTreeNodeComponent_Data;
        nsGuiWrapper_TTreeNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TTreeNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTreeNodeComponent>(eid, lambda);
    };
    nsGuiWrapper_TTreeNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeNodeComponent*)p)); };
    nsGuiWrapper_TTreeNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeNodeComponent>(); };
    auto rtti_nsGuiWrapper_TTreeNodeComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTreeNodeComponent_Data, nsGuiWrapper_TTreeNodeComponent_Data });
    
    Data nsGuiWrapper_TTreeViewComponent_Data;
        nsGuiWrapper_TTreeViewComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TTreeViewComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TTreeViewComponent>(eid, lambda);
    };
    nsGuiWrapper_TTreeViewComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeViewComponent*)p)); };
    nsGuiWrapper_TTreeViewComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeViewComponent>(); };
    auto rtti_nsGuiWrapper_TTreeViewComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TTreeViewComponent_Data, nsGuiWrapper_TTreeViewComponent_Data });
    
    Data nsGuiWrapper_TVerticalAlignComponent_Data;
        nsGuiWrapper_TVerticalAlignComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TVerticalAlignComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TVerticalAlignComponent>(eid, lambda);
    };
    nsGuiWrapper_TVerticalAlignComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVerticalAlignComponent*)p)); };
    nsGuiWrapper_TVerticalAlignComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TVerticalAlignComponent>(); };
    auto rtti_nsGuiWrapper_TVerticalAlignComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TVerticalAlignComponent_Data, nsGuiWrapper_TVerticalAlignComponent_Data });
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
        nsGuiWrapper_TVisibilityComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TVisibilityComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TVisibilityComponent>(eid, lambda);
    };
    nsGuiWrapper_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVisibilityComponent*)p)); };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TVisibilityComponent>(); };
    auto rtti_nsGuiWrapper_TVisibilityComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TVisibilityComponent_Data, nsGuiWrapper_TVisibilityComponent_Data });
    
    Data nsGuiWrapper_TWindowCloseEventHandlerComponent_Data;
        nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TWindowCloseEventHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid, lambda);
    };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowCloseEventHandlerComponent*)p)); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowCloseEventHandlerComponent>(eid); };
    nsGuiWrapper_TWindowCloseEventHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TWindowCloseEventHandlerComponent>(); };
    auto rtti_nsGuiWrapper_TWindowCloseEventHandlerComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TWindowCloseEventHandlerComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowCloseEventHandlerComponent_Data, nsGuiWrapper_TWindowCloseEventHandlerComponent_Data });
    
    Data nsGuiWrapper_TWindowComponent_Data;
        nsGuiWrapper_TWindowComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiWrapper::TWindowComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiWrapper::TWindowComponent>(eid, lambda);
    };
    nsGuiWrapper_TWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowComponent*)p)); };
    nsGuiWrapper_TWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TWindowComponent>(); };
    auto rtti_nsGuiWrapper_TWindowComponent_Data = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti_nsGuiWrapper_TWindowComponent_Data, nsGuiWrapper_TWindowComponent_Data });
    
    Data nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data;
        nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>(eid, lambda);
    };
    nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent*)p)); };
    nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>(eid); };
    nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>(); };
    auto rtti_nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data, nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_Data });
    
    Data nsLogicWrapper_TPrefabObjectReferenceComponent_Data;
        nsLogicWrapper_TPrefabObjectReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TPrefabObjectReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid, lambda);
    };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabObjectReferenceComponent*)p)); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabObjectReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TPrefabObjectReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TPrefabObjectReferenceComponent_Data, nsLogicWrapper_TPrefabObjectReferenceComponent_Data });
    
    Data nsLogicWrapper_TPrefabReferenceComponent_Data;
        nsLogicWrapper_TPrefabReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TPrefabReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid, lambda);
    };
    nsLogicWrapper_TPrefabReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabReferenceComponent*)p)); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TPrefabReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TPrefabReferenceComponent_Data, nsLogicWrapper_TPrefabReferenceComponent_Data });
    
    Data nsLogicWrapper_TSceneObjectReferenceComponent_Data;
        nsLogicWrapper_TSceneObjectReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TSceneObjectReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid, lambda);
    };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneObjectReferenceComponent*)p)); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneObjectReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TSceneObjectReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneObjectReferenceComponent_Data, nsLogicWrapper_TSceneObjectReferenceComponent_Data });
    
    Data nsLogicWrapper_TSceneReferenceComponent_Data;
        nsLogicWrapper_TSceneReferenceComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TSceneReferenceComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSceneReferenceComponent>(eid, lambda);
    };
    nsLogicWrapper_TSceneReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneReferenceComponent*)p)); };
    nsLogicWrapper_TSceneReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneReferenceComponent>(); };
    auto rtti_nsLogicWrapper_TSceneReferenceComponent_Data = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    m.insert({ rtti_nsLogicWrapper_TSceneReferenceComponent_Data, nsLogicWrapper_TSceneReferenceComponent_Data });
    
    Data nsLogicWrapper_TSystemComponent_Data;
        nsLogicWrapper_TSystemComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsLogicWrapper::TSystemComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsLogicWrapper::TSystemComponent>(eid, lambda);
    };
    nsLogicWrapper_TSystemComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSystemComponent*)p)); };
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
bool TComponentEntMng::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].createFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation);
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
const void* TComponentEntMng::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntMng::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
nsECSFramework::TEntityList TComponentEntMng::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
