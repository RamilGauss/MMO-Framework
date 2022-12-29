/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CheckArgumentsSystem.h"

#include <ECS/include/Helper.h>

#include "MessageException.h"
#include "Components/ArgumentComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig
{
    void TCheckArgumentsSystem::Execute()
    {
        auto argumentComponent = nsECSFramework::SingleComponent<TArgumentComponent>(mEntMng);

        if (argumentComponent->argc == 1) {
            std::string msg = "Not found argument";
            throw TMessageException(msg);
        }
    }
}