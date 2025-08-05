/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ReflectionConfigComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyReflectionConfigSystem.h"

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