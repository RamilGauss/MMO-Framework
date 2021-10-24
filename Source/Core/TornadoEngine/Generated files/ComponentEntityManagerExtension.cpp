/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_10_24 23:24:00.315
	
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
    
    Data nsTornadoEngine_TCameraComponent_Data;
    nsTornadoEngine_TCameraComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TCameraComponent*) p)); };
    nsTornadoEngine_TCameraComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TCameraComponent>(eid); };
    nsTornadoEngine_TCameraComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TCameraComponent>(eid, *((nsTornadoEngine::TCameraComponent*) p)); };
    nsTornadoEngine_TCameraComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TCameraComponent>(eid); };
    nsTornadoEngine_TCameraComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TCameraComponent>(eid); };
    auto rtti_nsTornadoEngine_TCameraComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TCameraComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TCameraComponent_Data, nsTornadoEngine_TCameraComponent_Data });
    
    Data nsTornadoEngine_TFocusComponent_Data;
    nsTornadoEngine_TFocusComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TFocusComponent*) p)); };
    nsTornadoEngine_TFocusComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TFocusComponent>(eid); };
    nsTornadoEngine_TFocusComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TFocusComponent>(eid, *((nsTornadoEngine::TFocusComponent*) p)); };
    nsTornadoEngine_TFocusComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TFocusComponent>(eid); };
    nsTornadoEngine_TFocusComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TFocusComponent>(eid); };
    auto rtti_nsTornadoEngine_TFocusComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TFocusComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TFocusComponent_Data, nsTornadoEngine_TFocusComponent_Data });
    
    Data nsTornadoEngine_TGuidComponent_Data;
    nsTornadoEngine_TGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TGuidComponent*) p)); };
    nsTornadoEngine_TGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TGuidComponent>(eid); };
    nsTornadoEngine_TGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TGuidComponent>(eid, *((nsTornadoEngine::TGuidComponent*) p)); };
    nsTornadoEngine_TGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TGuidComponent>(eid); };
    nsTornadoEngine_TGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TGuidComponent>(eid); };
    auto rtti_nsTornadoEngine_TGuidComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TGuidComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TGuidComponent_Data, nsTornadoEngine_TGuidComponent_Data });
    
    Data nsTornadoEngine_TLightComponent_Data;
    nsTornadoEngine_TLightComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TLightComponent*) p)); };
    nsTornadoEngine_TLightComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TLightComponent>(eid); };
    nsTornadoEngine_TLightComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TLightComponent>(eid, *((nsTornadoEngine::TLightComponent*) p)); };
    nsTornadoEngine_TLightComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TLightComponent>(eid); };
    nsTornadoEngine_TLightComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TLightComponent>(eid); };
    auto rtti_nsTornadoEngine_TLightComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TLightComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TLightComponent_Data, nsTornadoEngine_TLightComponent_Data });
    
    Data nsTornadoEngine_TNameComponent_Data;
    nsTornadoEngine_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TNameComponent*) p)); };
    nsTornadoEngine_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TNameComponent>(eid); };
    nsTornadoEngine_TNameComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TNameComponent>(eid, *((nsTornadoEngine::TNameComponent*) p)); };
    nsTornadoEngine_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TNameComponent>(eid); };
    nsTornadoEngine_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TNameComponent>(eid); };
    auto rtti_nsTornadoEngine_TNameComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TNameComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TNameComponent_Data, nsTornadoEngine_TNameComponent_Data });
    
    Data nsTornadoEngine_TParentGuidComponent_Data;
    nsTornadoEngine_TParentGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TParentGuidComponent*) p)); };
    nsTornadoEngine_TParentGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TParentGuidComponent>(eid); };
    nsTornadoEngine_TParentGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TParentGuidComponent>(eid, *((nsTornadoEngine::TParentGuidComponent*) p)); };
    nsTornadoEngine_TParentGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TParentGuidComponent>(eid); };
    nsTornadoEngine_TParentGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TParentGuidComponent>(eid); };
    auto rtti_nsTornadoEngine_TParentGuidComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TParentGuidComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TParentGuidComponent_Data, nsTornadoEngine_TParentGuidComponent_Data });
    
    Data nsTornadoEngine_TPositionComponent_Data;
    nsTornadoEngine_TPositionComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TPositionComponent*) p)); };
    nsTornadoEngine_TPositionComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TPositionComponent>(eid); };
    nsTornadoEngine_TPositionComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TPositionComponent>(eid, *((nsTornadoEngine::TPositionComponent*) p)); };
    nsTornadoEngine_TPositionComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TPositionComponent>(eid); };
    nsTornadoEngine_TPositionComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TPositionComponent>(eid); };
    auto rtti_nsTornadoEngine_TPositionComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TPositionComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TPositionComponent_Data, nsTornadoEngine_TPositionComponent_Data });
    
    Data nsTornadoEngine_TSceneGuidComponent_Data;
    nsTornadoEngine_TSceneGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TSceneGuidComponent*) p)); };
    nsTornadoEngine_TSceneGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TSceneGuidComponent>(eid); };
    nsTornadoEngine_TSceneGuidComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TSceneGuidComponent>(eid, *((nsTornadoEngine::TSceneGuidComponent*) p)); };
    nsTornadoEngine_TSceneGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TSceneGuidComponent>(eid); };
    nsTornadoEngine_TSceneGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TSceneGuidComponent>(eid); };
    auto rtti_nsTornadoEngine_TSceneGuidComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TSceneGuidComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TSceneGuidComponent_Data, nsTornadoEngine_TSceneGuidComponent_Data });
    
    Data nsTornadoEngine_TSizeComponent_Data;
    nsTornadoEngine_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TSizeComponent*) p)); };
    nsTornadoEngine_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TSizeComponent>(eid); };
    nsTornadoEngine_TSizeComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TSizeComponent>(eid, *((nsTornadoEngine::TSizeComponent*) p)); };
    nsTornadoEngine_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TSizeComponent>(eid); };
    nsTornadoEngine_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TSizeComponent>(eid); };
    auto rtti_nsTornadoEngine_TSizeComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TSizeComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TSizeComponent_Data, nsTornadoEngine_TSizeComponent_Data });
    
    Data nsTornadoEngine_TTransformComponent_Data;
    nsTornadoEngine_TTransformComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TTransformComponent*) p)); };
    nsTornadoEngine_TTransformComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TTransformComponent>(eid); };
    nsTornadoEngine_TTransformComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TTransformComponent>(eid, *((nsTornadoEngine::TTransformComponent*) p)); };
    nsTornadoEngine_TTransformComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TTransformComponent>(eid); };
    nsTornadoEngine_TTransformComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TTransformComponent>(eid); };
    auto rtti_nsTornadoEngine_TTransformComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TTransformComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TTransformComponent_Data, nsTornadoEngine_TTransformComponent_Data });
    
    Data nsTornadoEngine_TVisibilityComponent_Data;
    nsTornadoEngine_TVisibilityComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEngine::TVisibilityComponent*) p)); };
    nsTornadoEngine_TVisibilityComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEngine::TVisibilityComponent>(eid); };
    nsTornadoEngine_TVisibilityComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsTornadoEngine::TVisibilityComponent>(eid, *((nsTornadoEngine::TVisibilityComponent*) p)); };
    nsTornadoEngine_TVisibilityComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEngine::TVisibilityComponent>(eid); };
    nsTornadoEngine_TVisibilityComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEngine::TVisibilityComponent>(eid); };
    auto rtti_nsTornadoEngine_TVisibilityComponent_Data = globalTypeIdentifier->type<nsTornadoEngine::TVisibilityComponent>();
    
    m.insert({ rtti_nsTornadoEngine_TVisibilityComponent_Data, nsTornadoEngine_TVisibilityComponent_Data });
    
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
