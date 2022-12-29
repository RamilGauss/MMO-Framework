/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AddGeneratedFilesComponentSystem.h"

#include <ECS/include/Helper.h>

#include "Components/ConfigComponent.h"
#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TAddGeneratedFilesComponentSystem::Execute()
    {
        auto eid = nsECSFramework::SingleEntity<TConfigComponent>(mEntMng);

        TGeneratedFilesComponent generatedFilesComponent;
        mEntMng->SetComponent(eid, generatedFilesComponent);
    }
}