/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DestroyFileListSystem.h"

#include "ECS/Include/Helper.h"

#include "Components/FileListComponent.h"

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