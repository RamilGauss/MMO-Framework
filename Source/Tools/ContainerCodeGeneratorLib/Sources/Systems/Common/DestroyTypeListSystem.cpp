/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DestroyTypeListSystem.h"

#include <ECS/include/Helper.h>

#include "Components/TypeListComponent.h"

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