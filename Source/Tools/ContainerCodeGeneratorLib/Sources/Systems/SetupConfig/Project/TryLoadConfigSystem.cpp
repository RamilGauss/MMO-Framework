/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TryLoadConfigSystem.h"

#include <fmt/core.h>

#include <TextFile.h>

#include <ECS/include/Helper.h>

#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/PathsComponent.h"

#include "Generated files/JsonSerializer.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TTryLoadConfigSystem::Execute()
    {
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string str;
        TTextFile::Load(pathsComponent->absPathJsonFile, str);
        if (str.length() == 0) {
            auto msg = fmt::format("Not loaded file \"{}\"\n", pathsComponent->absPathJsonFile);
            throw TMessageException(msg);
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&projectConfigComponent->value, str, err);
        if (!fillRes) {
            auto msg = fmt::format("Deserilaize error in \"{}\", {}\n", pathsComponent->absPathJsonFile, err);
            throw TMessageException(msg);
        }

        TTextFile::Load(pathsComponent->absPathJsonFile, str);
        if (str.length() == 0) {
            auto msg = fmt::format("Not loaded file \"{}\"\n", pathsComponent->absPathJsonFile);
            throw TMessageException(msg);
        }
    }
}