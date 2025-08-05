/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Base/Common/PathOperations.h"
#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"
#include "ContainerCodeGeneratorLib/Sources/PathValidator.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Core/ValidateConfigSystem.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsCore
{
    void TValidateConfigSystem::Execute()
    {
        // Editor had to create folders 
        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        TPathValidator::ValidateAndThrow("coreConfig.parseDirectory", configComponent->value.coreConfig.parseDirectory);
        TPathValidator::ValidateAndThrow("coreConfig.targetDirectory", configComponent->value.coreConfig.targetDirectory);
    }
}