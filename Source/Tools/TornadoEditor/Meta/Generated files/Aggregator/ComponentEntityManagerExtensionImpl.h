/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 18:14:10.746
	
#pragma once

#include "IEcsComponentExtension.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentEntityManagerExtensionImpl : public nsTornadoEngine::IEcsComponentExtension
    {
        TComponentEntityManagerExtensionImpl();
        virtual ~TComponentEntityManagerExtensionImpl();
        
        void CreateComponent(nsECSFramework::TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation) override;
        void SetComponent(nsECSFramework::TEntityID eid, int rtti, void* p) override;
        const void* ViewComponent(nsECSFramework::TEntityID eid, int rtti) override;
        bool HasComponent(nsECSFramework::TEntityID eid, int rtti) override;
        void RemoveComponent(nsECSFramework::TEntityID eid, int rtti) override;
    };
}
