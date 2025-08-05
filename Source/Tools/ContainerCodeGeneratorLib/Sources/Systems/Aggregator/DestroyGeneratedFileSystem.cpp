/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/GeneratedFilesComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/DestroyGeneratedFileSystem.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TDestroyGeneratedFileSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TGeneratedFilesComponent>(mEntMng);
        mEntMng->RemoveComponent<TGeneratedFilesComponent>(eid);
    }
}