/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/FileListComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyFileListSystem.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TDestroyFileListSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TFileListComponent>(mEntMng);

        if (eid == nsECSFramework::NONE) {
            return;
        }

        mEntMng->RemoveComponent<TFileListComponent>(eid);
    }
}