/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <fmt/core.h>

#include "Base/Common/TextFile.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/MessageException.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/TryLoadConfigSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/PathsComponent.h"

#include "ContainerCodeGeneratorLib/Sources/GeneratedFiles/JsonSerializer.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TTryLoadConfigSystem::Execute()
    {
        auto projectConfigComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string str;
        nsBase::nsCommon::TTextFile::Load(pathsComponent->absPathJsonFile, str);
        if (str.length() == 0) {
            auto msg = fmt::format("Not loaded file \"{}\"\n", pathsComponent->absPathJsonFile);
            throw MSG_EXCEPTION(msg);
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&projectConfigComponent->value, str, err);
        if (!fillRes) {
            auto msg = fmt::format("Deserilaize error in \"{}\", {}\n", pathsComponent->absPathJsonFile, err);
            throw MSG_EXCEPTION(msg);
        }
    }
}