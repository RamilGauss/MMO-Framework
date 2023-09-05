/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_09_05 10:11:15.980
	
#include "ComponentEntityManagerExtensionImpl.h"

#include "Generated files\Container\ComponentEntMng.h"
#include "TornadoEngine\Generated files\Container\ComponentEntMng.h"

using namespace nsTornadoEditor;

TComponentEntityManagerExtensionImpl::TComponentEntityManagerExtensionImpl()
{

}
//--------------------------------------------------------------------------------------------------
TComponentEntityManagerExtensionImpl::~TComponentEntityManagerExtensionImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TComponentEntityManagerExtensionImpl::CreateComponent(nsECSFramework::TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation)
{
    if (TComponentEntMng::Has(rtti)) {
        TComponentEntMng::CreateComponent(mEntMng, eid, rtti, onAfterCreation);
        return;
    }
    if (nsTornadoEngine::TComponentEntMng::Has(rtti)) {
        nsTornadoEngine::TComponentEntMng::CreateComponent(mEntMng, eid, rtti, onAfterCreation);
        return;
    }
    }
    //--------------------------------------------------------------------------------------------------
    void TComponentEntityManagerExtensionImpl::SetComponent(nsECSFramework::TEntityID eid, int rtti, void* p)
    {
        if (TComponentEntMng::Has(rtti)) {
            TComponentEntMng::SetComponent(mEntMng, eid, rtti, p);
            return;
        }
        if (nsTornadoEngine::TComponentEntMng::Has(rtti)) {
            nsTornadoEngine::TComponentEntMng::SetComponent(mEntMng, eid, rtti, p);
            return;
        }
    }
    //--------------------------------------------------------------------------------------------------
    const void* TComponentEntityManagerExtensionImpl::ViewComponent(nsECSFramework::TEntityID eid, int rtti)
    {
        if (TComponentEntMng::Has(rtti)) {
            return TComponentEntMng::ViewComponent(mEntMng, eid, rtti);
        }
        if (nsTornadoEngine::TComponentEntMng::Has(rtti)) {
            return nsTornadoEngine::TComponentEntMng::ViewComponent(mEntMng, eid, rtti);
        }
        return nullptr;
    }
    //--------------------------------------------------------------------------------------------------
    bool TComponentEntityManagerExtensionImpl::HasComponent(nsECSFramework::TEntityID eid, int rtti)
    {
        if (TComponentEntMng::Has(rtti)) {
            return TComponentEntMng::HasComponent(mEntMng, eid, rtti);
        }
        if (nsTornadoEngine::TComponentEntMng::Has(rtti)) {
            return nsTornadoEngine::TComponentEntMng::HasComponent(mEntMng, eid, rtti);
        }
        return false;
    }
    //--------------------------------------------------------------------------------------------------
    void TComponentEntityManagerExtensionImpl::RemoveComponent(nsECSFramework::TEntityID eid, int rtti)
    {
        if (TComponentEntMng::Has(rtti)) {
            TComponentEntMng::RemoveComponent(mEntMng, eid, rtti);
            return;
        }
        if (nsTornadoEngine::TComponentEntMng::Has(rtti)) {
            nsTornadoEngine::TComponentEntMng::RemoveComponent(mEntMng, eid, rtti);
            return;
        }
    }
    //--------------------------------------------------------------------------------------------------
    