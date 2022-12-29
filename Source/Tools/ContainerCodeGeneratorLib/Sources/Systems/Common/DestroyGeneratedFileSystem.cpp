/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DestroyGeneratedFileSystem.h"

#include <ECS/include/Helper.h>

#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TDestroyGeneratedFileSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TGeneratedFilesComponent>(mEntMng);
        mEntMng->RemoveComponent<TGeneratedFilesComponent>(eid);
    }
}