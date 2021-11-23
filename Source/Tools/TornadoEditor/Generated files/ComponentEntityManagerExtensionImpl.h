/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IEntityManagerExtension.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentEntityManagerExtensionImpl : public nsTornadoEngine::IEntityManagerExtension
    {
        TComponentEntityManagerExtensionImpl();
        virtual ~TComponentEntityManagerExtensionImpl();

        [[nodiscard("Call ApplyChanges")]]
        void* CreateComponent(nsECSFramework::TEntityID eid, int rtti) override;
        void ApplyChangesComponent(nsECSFramework::TEntityID eid, void* p, int rtti, bool withNotify) override;
        void SetComponent(nsECSFramework::TEntityID eid, void* p, int rtti) override;
        [[nodiscard]]
        void* ViewComponent(nsECSFramework::TEntityID eid, int rtti) override;
        bool GetComponent(nsECSFramework::TEntityID eid, void*& p, int rtti) override;
        bool HasComponent(nsECSFramework::TEntityID eid, int rtti) override;
        void RemoveComponent(nsECSFramework::TEntityID eid, int rtti) override;
    };
}
