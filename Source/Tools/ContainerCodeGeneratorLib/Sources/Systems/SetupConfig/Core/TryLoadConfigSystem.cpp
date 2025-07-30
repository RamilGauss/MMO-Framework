/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TryLoadConfigSystem.h"

#include <fmt/core.h>

#include "Base/Common/TextFile.h"

#include "ECS/Include/Helper.h"

#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/PathsComponent.h"

#include "GeneratedFiles/JsonSerializer.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsCore
{
    void TTryLoadConfigSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string str;
        nsBase::nsCommon::TTextFile::Load(pathsComponent->absPathJsonFile, str);
        if (str.length() == 0) {
            auto msg = fmt::format("Not loaded file \"{}\"\n", pathsComponent->absPathJsonFile);
            throw MSG_EXCEPTION(msg);
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&configComponent->value, str, err);
        if (!fillRes) {
            auto msg = fmt::format("Deserilaize error in \"{}\", {}\n", pathsComponent->absPathJsonFile, err);
            throw MSG_EXCEPTION(msg);
        }
    }
}