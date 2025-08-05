/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/TextFile.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ReflectionConfigComponent.h"
#include "ReflectionCodeGeneratorLib/Sources/JsonSerializer.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/SaveConfigFileSystem.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TSaveConfigFileSystem::Execute()
    {
        auto reflectionConfigComponent = nsECSFramework::SingleComponent<TReflectionConfigComponent>(mEntMng);

        if (reflectionConfigComponent == nullptr) {
            return;
        }

        std::string content;
        nsJson::TJsonSerializer::Serialize(&reflectionConfigComponent->value, content);

        nsBase::nsCommon::TTextFile::Save(reflectionConfigComponent->absFileName, content);
    }
}