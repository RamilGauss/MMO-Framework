/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEditor/Sources/Components/ObjectHierarchyWindowRefreshTagComponent.h"

namespace nsTornadoEditor
{
    class DllExport TObjectHierarchyWindowRefreshSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<TObjectHierarchyWindowRefreshTagComponent, TObjectHierarchyWindowRefreshSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const TObjectHierarchyWindowRefreshTagComponent* pC);

    private:

    };
}
