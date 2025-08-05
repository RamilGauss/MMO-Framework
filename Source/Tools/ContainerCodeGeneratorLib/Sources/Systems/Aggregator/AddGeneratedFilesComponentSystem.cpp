/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/GeneratedFilesComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/AddGeneratedFilesComponentSystem.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TAddGeneratedFilesComponentSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TProjectConfigComponent>(mEntMng);

        TGeneratedFilesComponent generatedFilesComponent;
        mEntMng->SetComponent(eid, generatedFilesComponent);
    }
}
