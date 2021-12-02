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
void TComponentEntityManagerExtensionImpl::CreateComponent(nsECSFramework::TEntityID eid, int rtti, 
    std::function<void(void*)> onAfterCreation, bool isNotify)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        TComponentEntityManagerExtension::CreateComponent(mEntMng, eid, rtti, onAfterCreation, isNotify);
        return;
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        nsTornadoEngine::TComponentEntityManagerExtension::CreateComponent(mEntMng, eid, rtti, onAfterCreation, isNotify);
        return;
    }
}
//------------------------------------------------------------------------------------------------------------
void TComponentEntityManagerExtensionImpl::SetComponent(nsECSFramework::TEntityID eid, int rtti,
    void* p, bool isNotify)
{
    if (TComponentEntityManagerExtension::Has(rtti)) {
        TComponentEntityManagerExtension::SetComponent(mEntMng, eid, rtti, p, isNotify);
        return;
    }
    if (nsTornadoEngine::TComponentEntityManagerExtension::Has(rtti)) {
        nsTornadoEngine::TComponentEntityManagerExtension::SetComponent(mEntMng, eid, rtti, p, isNotify);
        return;
    }
}
//------------------------------------------------------------------------------------------------------------
const void* TComponentEntityManagerExtensionImpl::ViewComponent(nsECSFramework::TEntityID eid, int rtti)
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
