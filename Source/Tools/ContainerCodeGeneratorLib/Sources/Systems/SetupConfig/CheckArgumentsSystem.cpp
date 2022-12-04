/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CheckArgumentsSystem.h"

#include <ECS/include/Helper.h>

#include "Components/InputOutput/ArgumentComponent.h"
#include "Components/InputOutput/ResultComponent.h"

namespace nsContainerCodeGenerator
{
    void TCheckArgumentsSystem::Execute()
    {
        auto argumentComponent = nsECSFramework::SingleComponent<TArgumentComponent>(mEntMng);
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(mEntMng);

        if (argumentComponent->argc == 1) {
            resultComponent->value = "Not found argument";
            throw std::exception();
        }
    }
}