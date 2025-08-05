/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/TypeListComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyTypeListSystem.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TDestroyTypeListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TTypeListComponent>(mEntMng);

        if (eid == nsECSFramework::NONE) {
            return;
        }

        mEntMng->RemoveComponent<TTypeListComponent>(eid);
    }
}