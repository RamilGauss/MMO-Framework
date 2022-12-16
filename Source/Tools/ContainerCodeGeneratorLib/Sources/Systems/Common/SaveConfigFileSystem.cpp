/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SaveConfigFileSystem.h"

#include <TextFile.h>

#include <ECS/include/Helper.h>

#include "Components/ReflectionConfigComponent.h"
#include "ReflectionCodeGeneratorLib/Sources/JsonSerializer.h"

namespace nsContainerCodeGenerator
{
    void TSaveConfigFileSystem::Execute()
    {
        auto reflectionConfigComponent = nsECSFramework::SingleComponent<TReflectionConfigComponent>(mEntMng);

        std::string content;
        nsJson::TJsonSerializer::Serialize(&reflectionConfigComponent->value, content);

        TTextFile::Save(reflectionConfigComponent->absFileName, content);
    }
}