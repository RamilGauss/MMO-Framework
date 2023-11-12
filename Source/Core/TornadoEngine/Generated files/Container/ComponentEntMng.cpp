/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_12 12:28:55.765
	
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
    
    std::list<Data> datas;
    
    Data nsCommonWrapper_TGlobalMatrixComponent_Data;
    nsCommonWrapper_TGlobalMatrixComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGlobalMatrixComponent*)p)); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGlobalMatrixComponent>(eid); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TGlobalMatrixComponent>(); };
    nsCommonWrapper_TGlobalMatrixComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    datas.push_back(nsCommonWrapper_TGlobalMatrixComponent_Data);
    
    Data nsCommonWrapper_TGuidComponent_Data;
    nsCommonWrapper_TGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TGuidComponent*)p)); };
    nsCommonWrapper_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TGuidComponent>(eid); };
    nsCommonWrapper_TGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TGuidComponent>(); };
    nsCommonWrapper_TGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TGuidComponent_Data);
    
    Data nsCommonWrapper_TNameComponent_Data;
    nsCommonWrapper_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNameComponent*)p)); };
    nsCommonWrapper_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNameComponent>(eid); };
    nsCommonWrapper_TNameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNameComponent>(); };
    nsCommonWrapper_TNameComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    datas.push_back(nsCommonWrapper_TNameComponent_Data);
    
    Data nsCommonWrapper_TNeedDestroyObjectTagComponent_Data;
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TNeedDestroyObjectTagComponent*)p)); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TNeedDestroyObjectTagComponent>(eid); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TNeedDestroyObjectTagComponent>(); };
    nsCommonWrapper_TNeedDestroyObjectTagComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    datas.push_back(nsCommonWrapper_TNeedDestroyObjectTagComponent_Data);
    
    Data nsCommonWrapper_TParentGuidComponent_Data;
    nsCommonWrapper_TParentGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TParentGuidComponent*)p)); };
    nsCommonWrapper_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TParentGuidComponent>(eid); };
    nsCommonWrapper_TParentGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TParentGuidComponent>(); };
    nsCommonWrapper_TParentGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TParentGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabGuidComponent_Data;
    nsCommonWrapper_TPrefabGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabGuidComponent*)p)); };
    nsCommonWrapper_TPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabGuidComponent>(eid); };
    nsCommonWrapper_TPrefabGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabGuidComponent>(); };
    nsCommonWrapper_TPrefabGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabInstanceGuidComponent_Data;
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabInstanceGuidComponent*)p)); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(eid); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabInstanceGuidComponent>(); };
    nsCommonWrapper_TPrefabInstanceGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabInstanceGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabOriginalGuidComponent_Data;
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabOriginalGuidComponent*)p)); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabOriginalGuidComponent>(); };
    nsCommonWrapper_TPrefabOriginalGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabOriginalGuidComponent_Data);
    
    Data nsCommonWrapper_TPrefabRootComponent_Data;
    nsCommonWrapper_TPrefabRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TPrefabRootComponent*)p)); };
    nsCommonWrapper_TPrefabRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TPrefabRootComponent>(eid); };
    nsCommonWrapper_TPrefabRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TPrefabRootComponent>(); };
    nsCommonWrapper_TPrefabRootComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    datas.push_back(nsCommonWrapper_TPrefabRootComponent_Data);
    
    Data nsCommonWrapper_TProjectionToUniverseComponent_Data;
    nsCommonWrapper_TProjectionToUniverseComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TProjectionToUniverseComponent*)p)); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TProjectionToUniverseComponent>(eid); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TProjectionToUniverseComponent>(); };
    nsCommonWrapper_TProjectionToUniverseComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    
    datas.push_back(nsCommonWrapper_TProjectionToUniverseComponent_Data);
    
    Data nsCommonWrapper_TSceneGuidComponent_Data;
    nsCommonWrapper_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneGuidComponent*)p)); };
    nsCommonWrapper_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneGuidComponent>(eid); };
    nsCommonWrapper_TSceneGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneGuidComponent>(); };
    nsCommonWrapper_TSceneGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneInstanceGuidComponent_Data;
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneInstanceGuidComponent*)p)); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneInstanceGuidComponent>(); };
    nsCommonWrapper_TSceneInstanceGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneInstanceGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneOriginalGuidComponent_Data;
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneOriginalGuidComponent*)p)); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneOriginalGuidComponent>(); };
    nsCommonWrapper_TSceneOriginalGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneOriginalGuidComponent_Data);
    
    Data nsCommonWrapper_TSceneRootComponent_Data;
    nsCommonWrapper_TSceneRootComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TSceneRootComponent*)p)); };
    nsCommonWrapper_TSceneRootComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TSceneRootComponent>(eid); };
    nsCommonWrapper_TSceneRootComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TSceneRootComponent>(); };
    nsCommonWrapper_TSceneRootComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    datas.push_back(nsCommonWrapper_TSceneRootComponent_Data);
    
    Data nsCommonWrapper_TUniverseGuidComponent_Data;
    nsCommonWrapper_TUniverseGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseGuidComponent*)p)); };
    nsCommonWrapper_TUniverseGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseGuidComponent>(eid); };
    nsCommonWrapper_TUniverseGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseGuidComponent>(); };
    nsCommonWrapper_TUniverseGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    datas.push_back(nsCommonWrapper_TUniverseGuidComponent_Data);
    
    Data nsCommonWrapper_TUniverseIndexComponent_Data;
    nsCommonWrapper_TUniverseIndexComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsCommonWrapper::TUniverseIndexComponent*)p)); };
    nsCommonWrapper_TUniverseIndexComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsCommonWrapper::TUniverseIndexComponent>(eid); };
    nsCommonWrapper_TUniverseIndexComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsCommonWrapper::TUniverseIndexComponent>(); };
    nsCommonWrapper_TUniverseIndexComponent_Data.rtti = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    datas.push_back(nsCommonWrapper_TUniverseIndexComponent_Data);
    
    Data nsGraphicWrapper_TCameraComponent_Data;
    nsGraphicWrapper_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraComponent*)p)); };
    nsGraphicWrapper_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraComponent>(eid); };
    nsGraphicWrapper_TCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraComponent>(); };
    nsGraphicWrapper_TCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraComponent_Data);
    
    Data nsGraphicWrapper_TCameraTextureTagComponent_Data;
    nsGraphicWrapper_TCameraTextureTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraTextureTagComponent*)p)); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraTextureTagComponent>(eid); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraTextureTagComponent>(); };
    nsGraphicWrapper_TCameraTextureTagComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraTextureTagComponent_Data);
    
    Data nsGraphicWrapper_TCameraWindowPositionComponent_Data;
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowPositionComponent*)p)); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowPositionComponent>(eid); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowPositionComponent>(); };
    nsGraphicWrapper_TCameraWindowPositionComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraWindowPositionComponent_Data);
    
    Data nsGraphicWrapper_TCameraWindowSizeComponent_Data;
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TCameraWindowSizeComponent*)p)); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TCameraWindowSizeComponent>(eid); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TCameraWindowSizeComponent>(); };
    nsGraphicWrapper_TCameraWindowSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    datas.push_back(nsGraphicWrapper_TCameraWindowSizeComponent_Data);
    
    Data nsGraphicWrapper_TGuiCameraTagComponent_Data;
    nsGraphicWrapper_TGuiCameraTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TGuiCameraTagComponent*)p)); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TGuiCameraTagComponent>(eid); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TGuiCameraTagComponent>(); };
    nsGraphicWrapper_TGuiCameraTagComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    datas.push_back(nsGraphicWrapper_TGuiCameraTagComponent_Data);
    
    Data nsGraphicWrapper_TLightComponent_Data;
    nsGraphicWrapper_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TLightComponent*)p)); };
    nsGraphicWrapper_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TLightComponent>(eid); };
    nsGraphicWrapper_TLightComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TLightComponent>(); };
    nsGraphicWrapper_TLightComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    datas.push_back(nsGraphicWrapper_TLightComponent_Data);
    
    Data nsGraphicWrapper_TRenderToTextureCameraComponent_Data;
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TRenderToTextureCameraComponent*)p)); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TRenderToTextureCameraComponent>(eid); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TRenderToTextureCameraComponent>(); };
    nsGraphicWrapper_TRenderToTextureCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TRenderToTextureCameraComponent_Data);
    
    Data nsGraphicWrapper_TTextureFromCameraComponent_Data;
    nsGraphicWrapper_TTextureFromCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromCameraComponent*)p)); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromCameraComponent>(eid); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromCameraComponent>(); };
    nsGraphicWrapper_TTextureFromCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TTextureFromCameraComponent_Data);
    
    Data nsGraphicWrapper_TTextureFromFileComponent_Data;
    nsGraphicWrapper_TTextureFromFileComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TTextureFromFileComponent*)p)); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TTextureFromFileComponent>(eid); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TTextureFromFileComponent>(); };
    nsGraphicWrapper_TTextureFromFileComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    datas.push_back(nsGraphicWrapper_TTextureFromFileComponent_Data);
    
    Data nsGraphicWrapper_TUniverseCameraComponent_Data;
    nsGraphicWrapper_TUniverseCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGraphicWrapper::TUniverseCameraComponent*)p)); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGraphicWrapper::TUniverseCameraComponent>(eid); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGraphicWrapper::TUniverseCameraComponent>(); };
    nsGraphicWrapper_TUniverseCameraComponent_Data.rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    datas.push_back(nsGraphicWrapper_TUniverseCameraComponent_Data);
    
    Data nsGuiWrapper_TAnchorsComponent_Data;
    nsGuiWrapper_TAnchorsComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TAnchorsComponent*)p)); };
    nsGuiWrapper_TAnchorsComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TAnchorsComponent>(eid); };
    nsGuiWrapper_TAnchorsComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TAnchorsComponent>(); };
    nsGuiWrapper_TAnchorsComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    datas.push_back(nsGuiWrapper_TAnchorsComponent_Data);
    
    Data nsGuiWrapper_TButtonComponent_Data;
    nsGuiWrapper_TButtonComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TButtonComponent*)p)); };
    nsGuiWrapper_TButtonComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TButtonComponent>(eid); };
    nsGuiWrapper_TButtonComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TButtonComponent>(); };
    nsGuiWrapper_TButtonComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    datas.push_back(nsGuiWrapper_TButtonComponent_Data);
    
    Data nsGuiWrapper_TColorComponent_Data;
    nsGuiWrapper_TColorComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TColorComponent*)p)); };
    nsGuiWrapper_TColorComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TColorComponent>(eid); };
    nsGuiWrapper_TColorComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TColorComponent>(); };
    nsGuiWrapper_TColorComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    datas.push_back(nsGuiWrapper_TColorComponent_Data);
    
    Data nsGuiWrapper_TDialogComponent_Data;
    nsGuiWrapper_TDialogComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TDialogComponent*)p)); };
    nsGuiWrapper_TDialogComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TDialogComponent>(eid); };
    nsGuiWrapper_TDialogComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TDialogComponent>(); };
    nsGuiWrapper_TDialogComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    datas.push_back(nsGuiWrapper_TDialogComponent_Data);
    
    Data nsGuiWrapper_TFocusComponent_Data;
    nsGuiWrapper_TFocusComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFocusComponent*)p)); };
    nsGuiWrapper_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFocusComponent>(eid); };
    nsGuiWrapper_TFocusComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFocusComponent>(); };
    nsGuiWrapper_TFocusComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    datas.push_back(nsGuiWrapper_TFocusComponent_Data);
    
    Data nsGuiWrapper_TFrameComponent_Data;
    nsGuiWrapper_TFrameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TFrameComponent*)p)); };
    nsGuiWrapper_TFrameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TFrameComponent>(eid); };
    nsGuiWrapper_TFrameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TFrameComponent>(); };
    nsGuiWrapper_TFrameComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    datas.push_back(nsGuiWrapper_TFrameComponent_Data);
    
    Data nsGuiWrapper_TGridComponent_Data;
    nsGuiWrapper_TGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TGridComponent*)p)); };
    nsGuiWrapper_TGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TGridComponent>(eid); };
    nsGuiWrapper_TGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TGridComponent>(); };
    nsGuiWrapper_TGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    datas.push_back(nsGuiWrapper_TGridComponent_Data);
    
    Data nsGuiWrapper_THorizontalAlignComponent_Data;
    nsGuiWrapper_THorizontalAlignComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::THorizontalAlignComponent*)p)); };
    nsGuiWrapper_THorizontalAlignComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::THorizontalAlignComponent>(eid); };
    nsGuiWrapper_THorizontalAlignComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::THorizontalAlignComponent>(); };
    nsGuiWrapper_THorizontalAlignComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    datas.push_back(nsGuiWrapper_THorizontalAlignComponent_Data);
    
    Data nsGuiWrapper_TInputTextComponent_Data;
    nsGuiWrapper_TInputTextComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextComponent*)p)); };
    nsGuiWrapper_TInputTextComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextComponent>(eid); };
    nsGuiWrapper_TInputTextComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextComponent>(); };
    nsGuiWrapper_TInputTextComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    datas.push_back(nsGuiWrapper_TInputTextComponent_Data);
    
    Data nsGuiWrapper_TInputTextValueComponent_Data;
    nsGuiWrapper_TInputTextValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TInputTextValueComponent*)p)); };
    nsGuiWrapper_TInputTextValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TInputTextValueComponent>(eid); };
    nsGuiWrapper_TInputTextValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TInputTextValueComponent>(); };
    nsGuiWrapper_TInputTextValueComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    datas.push_back(nsGuiWrapper_TInputTextValueComponent_Data);
    
    Data nsGuiWrapper_TLabelComponent_Data;
    nsGuiWrapper_TLabelComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelComponent*)p)); };
    nsGuiWrapper_TLabelComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelComponent>(eid); };
    nsGuiWrapper_TLabelComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelComponent>(); };
    nsGuiWrapper_TLabelComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    datas.push_back(nsGuiWrapper_TLabelComponent_Data);
    
    Data nsGuiWrapper_TLabelValueComponent_Data;
    nsGuiWrapper_TLabelValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TLabelValueComponent*)p)); };
    nsGuiWrapper_TLabelValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TLabelValueComponent>(eid); };
    nsGuiWrapper_TLabelValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TLabelValueComponent>(); };
    nsGuiWrapper_TLabelValueComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    datas.push_back(nsGuiWrapper_TLabelValueComponent_Data);
    
    Data nsGuiWrapper_TMainWindowComponent_Data;
    nsGuiWrapper_TMainWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMainWindowComponent*)p)); };
    nsGuiWrapper_TMainWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMainWindowComponent>(eid); };
    nsGuiWrapper_TMainWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMainWindowComponent>(); };
    nsGuiWrapper_TMainWindowComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    datas.push_back(nsGuiWrapper_TMainWindowComponent_Data);
    
    Data nsGuiWrapper_TMaxSizeComponent_Data;
    nsGuiWrapper_TMaxSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMaxSizeComponent*)p)); };
    nsGuiWrapper_TMaxSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMaxSizeComponent>(eid); };
    nsGuiWrapper_TMaxSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMaxSizeComponent>(); };
    nsGuiWrapper_TMaxSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TMaxSizeComponent_Data);
    
    Data nsGuiWrapper_TMenuNodeComponent_Data;
    nsGuiWrapper_TMenuNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMenuNodeComponent*)p)); };
    nsGuiWrapper_TMenuNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMenuNodeComponent>(eid); };
    nsGuiWrapper_TMenuNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMenuNodeComponent>(); };
    nsGuiWrapper_TMenuNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    datas.push_back(nsGuiWrapper_TMenuNodeComponent_Data);
    
    Data nsGuiWrapper_TMinDistanceToParentComponent_Data;
    nsGuiWrapper_TMinDistanceToParentComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMinDistanceToParentComponent*)p)); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMinDistanceToParentComponent>(); };
    nsGuiWrapper_TMinDistanceToParentComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    datas.push_back(nsGuiWrapper_TMinDistanceToParentComponent_Data);
    
    Data nsGuiWrapper_TMinSizeComponent_Data;
    nsGuiWrapper_TMinSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TMinSizeComponent*)p)); };
    nsGuiWrapper_TMinSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TMinSizeComponent>(eid); };
    nsGuiWrapper_TMinSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TMinSizeComponent>(); };
    nsGuiWrapper_TMinSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TMinSizeComponent_Data);
    
    Data nsGuiWrapper_TNodeIconComponent_Data;
    nsGuiWrapper_TNodeIconComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TNodeIconComponent*)p)); };
    nsGuiWrapper_TNodeIconComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TNodeIconComponent>(eid); };
    nsGuiWrapper_TNodeIconComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TNodeIconComponent>(); };
    nsGuiWrapper_TNodeIconComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    datas.push_back(nsGuiWrapper_TNodeIconComponent_Data);
    
    Data nsGuiWrapper_TPaddingComponent_Data;
    nsGuiWrapper_TPaddingComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPaddingComponent*)p)); };
    nsGuiWrapper_TPaddingComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPaddingComponent>(eid); };
    nsGuiWrapper_TPaddingComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPaddingComponent>(); };
    nsGuiWrapper_TPaddingComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    datas.push_back(nsGuiWrapper_TPaddingComponent_Data);
    
    Data nsGuiWrapper_TPositionComponent_Data;
    nsGuiWrapper_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionComponent*)p)); };
    nsGuiWrapper_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionComponent>(eid); };
    nsGuiWrapper_TPositionComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPositionComponent>(); };
    nsGuiWrapper_TPositionComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    datas.push_back(nsGuiWrapper_TPositionComponent_Data);
    
    Data nsGuiWrapper_TPositionInGridComponent_Data;
    nsGuiWrapper_TPositionInGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TPositionInGridComponent*)p)); };
    nsGuiWrapper_TPositionInGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TPositionInGridComponent>(eid); };
    nsGuiWrapper_TPositionInGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TPositionInGridComponent>(); };
    nsGuiWrapper_TPositionInGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    datas.push_back(nsGuiWrapper_TPositionInGridComponent_Data);
    
    Data nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data;
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSelectedTreeNodeGuidComponent*)p)); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(); };
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    datas.push_back(nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data);
    
    Data nsGuiWrapper_TSizeComponent_Data;
    nsGuiWrapper_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeComponent*)p)); };
    nsGuiWrapper_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeComponent>(eid); };
    nsGuiWrapper_TSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSizeComponent>(); };
    nsGuiWrapper_TSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    datas.push_back(nsGuiWrapper_TSizeComponent_Data);
    
    Data nsGuiWrapper_TSizeInGridComponent_Data;
    nsGuiWrapper_TSizeInGridComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSizeInGridComponent*)p)); };
    nsGuiWrapper_TSizeInGridComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSizeInGridComponent>(eid); };
    nsGuiWrapper_TSizeInGridComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSizeInGridComponent>(); };
    nsGuiWrapper_TSizeInGridComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    datas.push_back(nsGuiWrapper_TSizeInGridComponent_Data);
    
    Data nsGuiWrapper_TSpacingComponent_Data;
    nsGuiWrapper_TSpacingComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TSpacingComponent*)p)); };
    nsGuiWrapper_TSpacingComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TSpacingComponent>(eid); };
    nsGuiWrapper_TSpacingComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TSpacingComponent>(); };
    nsGuiWrapper_TSpacingComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    datas.push_back(nsGuiWrapper_TSpacingComponent_Data);
    
    Data nsGuiWrapper_TTitleComponent_Data;
    nsGuiWrapper_TTitleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTitleComponent*)p)); };
    nsGuiWrapper_TTitleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTitleComponent>(eid); };
    nsGuiWrapper_TTitleComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTitleComponent>(); };
    nsGuiWrapper_TTitleComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    datas.push_back(nsGuiWrapper_TTitleComponent_Data);
    
    Data nsGuiWrapper_TTreeNodeComponent_Data;
    nsGuiWrapper_TTreeNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeNodeComponent*)p)); };
    nsGuiWrapper_TTreeNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeNodeComponent>(eid); };
    nsGuiWrapper_TTreeNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeNodeComponent>(); };
    nsGuiWrapper_TTreeNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    datas.push_back(nsGuiWrapper_TTreeNodeComponent_Data);
    
    Data nsGuiWrapper_TTreeViewComponent_Data;
    nsGuiWrapper_TTreeViewComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TTreeViewComponent*)p)); };
    nsGuiWrapper_TTreeViewComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TTreeViewComponent>(eid); };
    nsGuiWrapper_TTreeViewComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TTreeViewComponent>(); };
    nsGuiWrapper_TTreeViewComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    datas.push_back(nsGuiWrapper_TTreeViewComponent_Data);
    
    Data nsGuiWrapper_TVerticalAlignComponent_Data;
    nsGuiWrapper_TVerticalAlignComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVerticalAlignComponent*)p)); };
    nsGuiWrapper_TVerticalAlignComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVerticalAlignComponent>(eid); };
    nsGuiWrapper_TVerticalAlignComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TVerticalAlignComponent>(); };
    nsGuiWrapper_TVerticalAlignComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    datas.push_back(nsGuiWrapper_TVerticalAlignComponent_Data);
    
    Data nsGuiWrapper_TVisibilityComponent_Data;
    nsGuiWrapper_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TVisibilityComponent*)p)); };
    nsGuiWrapper_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TVisibilityComponent>(eid); };
    nsGuiWrapper_TVisibilityComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TVisibilityComponent>(); };
    nsGuiWrapper_TVisibilityComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    datas.push_back(nsGuiWrapper_TVisibilityComponent_Data);
    
    Data nsGuiWrapper_TWindowComponent_Data;
    nsGuiWrapper_TWindowComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiWrapper::TWindowComponent*)p)); };
    nsGuiWrapper_TWindowComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiWrapper::TWindowComponent>(eid); };
    nsGuiWrapper_TWindowComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiWrapper::TWindowComponent>(); };
    nsGuiWrapper_TWindowComponent_Data.rtti = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    datas.push_back(nsGuiWrapper_TWindowComponent_Data);
    
    Data nsLogicWrapper_TGlobalHandlerComponent_Data;
    nsLogicWrapper_TGlobalHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TGlobalHandlerComponent*)p)); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TGlobalHandlerComponent>(eid); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TGlobalHandlerComponent>(eid); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TGlobalHandlerComponent>(eid); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TGlobalHandlerComponent>(); };
    nsLogicWrapper_TGlobalHandlerComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TGlobalHandlerComponent>();
    
    datas.push_back(nsLogicWrapper_TGlobalHandlerComponent_Data);
    
    Data nsLogicWrapper_TLocalHandlerComponent_Data;
    nsLogicWrapper_TLocalHandlerComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TLocalHandlerComponent*)p)); };
    nsLogicWrapper_TLocalHandlerComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TLocalHandlerComponent>(eid); };
    nsLogicWrapper_TLocalHandlerComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TLocalHandlerComponent>(eid); };
    nsLogicWrapper_TLocalHandlerComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TLocalHandlerComponent>(eid); };
    nsLogicWrapper_TLocalHandlerComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TLocalHandlerComponent>(); };
    nsLogicWrapper_TLocalHandlerComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TLocalHandlerComponent>();
    
    datas.push_back(nsLogicWrapper_TLocalHandlerComponent_Data);
    
    Data nsLogicWrapper_TPrefabObjectReferenceComponent_Data;
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabObjectReferenceComponent*)p)); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabObjectReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabObjectReferenceComponent>(); };
    nsLogicWrapper_TPrefabObjectReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TPrefabObjectReferenceComponent_Data);
    
    Data nsLogicWrapper_TPrefabReferenceComponent_Data;
    nsLogicWrapper_TPrefabReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TPrefabReferenceComponent*)p)); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TPrefabReferenceComponent>(); };
    nsLogicWrapper_TPrefabReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TPrefabReferenceComponent_Data);
    
    Data nsLogicWrapper_TSceneObjectReferenceComponent_Data;
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneObjectReferenceComponent*)p)); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneObjectReferenceComponent>(); };
    nsLogicWrapper_TSceneObjectReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TSceneObjectReferenceComponent_Data);
    
    Data nsLogicWrapper_TSceneReferenceComponent_Data;
    nsLogicWrapper_TSceneReferenceComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSceneReferenceComponent*)p)); };
    nsLogicWrapper_TSceneReferenceComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSceneReferenceComponent>(eid); };
    nsLogicWrapper_TSceneReferenceComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSceneReferenceComponent>(); };
    nsLogicWrapper_TSceneReferenceComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    datas.push_back(nsLogicWrapper_TSceneReferenceComponent_Data);
    
    Data nsLogicWrapper_TSystemComponent_Data;
    nsLogicWrapper_TSystemComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsLogicWrapper::TSystemComponent*)p)); };
    nsLogicWrapper_TSystemComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsLogicWrapper::TSystemComponent>(eid); };
    nsLogicWrapper_TSystemComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsLogicWrapper::TSystemComponent>(); };
    nsLogicWrapper_TSystemComponent_Data.rtti = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    
    datas.push_back(nsLogicWrapper_TSystemComponent_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& d : datas) {
        mRttiVector[d.rtti] = d;
    }
}
//---------------------------------------------------------------------------------------
bool TComponentEntMng::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].setFunc != nullptr;
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
