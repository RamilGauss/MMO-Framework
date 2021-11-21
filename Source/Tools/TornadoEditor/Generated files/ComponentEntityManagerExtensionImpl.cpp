/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComponentEntityManagerExtensionImpl.h"

#include "ComponentEntityManagerExtension.h"
#include "TornadoEngine/Generated files/ComponentEntityManagerExtension.h"

using namespace nsTornadoEditor;

TComponentEntityManagerExtensionImpl::TComponentEntityManagerExtensionImpl()
{

}
//------------------------------------------------------------------------------------------------------------
TComponentEntityManagerExtensionImpl::~TComponentEntityManagerExtensionImpl()
{

}
//------------------------------------------------------------------------------------------------------------
void TComponentEntityManagerExtensionImpl::AddComponent(nsECSFramework::TEntityID eid, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        TComponentEntityManagerExtension::AddComponent(mEntMng, eid, rtti);
        return;
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        nsTornadoEngine::TComponentEntityManagerExtension::AddComponent(mEntMng, eid, rtti);
    }
}
//------------------------------------------------------------------------------------------------------------
void TComponentEntityManagerExtensionImpl::SetComponent(nsECSFramework::TEntityID eid, void* p, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        TComponentEntityManagerExtension::SetComponent(mEntMng, eid, p, rtti);
        return;
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        nsTornadoEngine::TComponentEntityManagerExtension::SetComponent(mEntMng, eid, p, rtti);
    }
}
//------------------------------------------------------------------------------------------------------------
void* TComponentEntityManagerExtensionImpl::ViewComponent(nsECSFramework::TEntityID eid, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        return TComponentEntityManagerExtension::ViewComponent(mEntMng, eid, rtti);
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        return nsTornadoEngine::TComponentEntityManagerExtension::ViewComponent(mEntMng, eid, rtti);
    }
    return nullptr;
}
//------------------------------------------------------------------------------------------------------------
bool TComponentEntityManagerExtensionImpl::GetComponent(nsECSFramework::TEntityID eid, void*& p, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        return TComponentEntityManagerExtension::GetComponent(mEntMng, eid, p, rtti);
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        return nsTornadoEngine::TComponentEntityManagerExtension::GetComponent(mEntMng, eid, p, rtti);
    }
    return false;
}
//------------------------------------------------------------------------------------------------------------
bool TComponentEntityManagerExtensionImpl::HasComponent(nsECSFramework::TEntityID eid, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        return TComponentEntityManagerExtension::HasComponent(mEntMng, eid, rtti);
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        return nsTornadoEngine::TComponentEntityManagerExtension::HasComponent(mEntMng, eid, rtti);
    }
    return false;
}
//------------------------------------------------------------------------------------------------------------
void TComponentEntityManagerExtensionImpl::RemoveComponent(nsECSFramework::TEntityID eid, int rtti)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        TComponentEntityManagerExtension::RemoveComponent(mEntMng, eid, rtti);
        return;
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        nsTornadoEngine::TComponentEntityManagerExtension::RemoveComponent(mEntMng, eid, rtti);
    }
}
//------------------------------------------------------------------------------------------------------------
