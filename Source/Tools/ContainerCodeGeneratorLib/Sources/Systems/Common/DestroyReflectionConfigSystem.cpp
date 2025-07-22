/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DestroyReflectionConfigSystem.h"

#include "ECS/Include/Helper.h"

#include "Components/ReflectionConfigComponent.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TDestroyReflectionConfigSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TReflectionConfigComponent>(mEntMng);
     
        if (eid == nsECSFramework::NONE) {
            return;
        }

        mEntMng->RemoveComponent<TReflectionConfigComponent>(eid);
    }
}