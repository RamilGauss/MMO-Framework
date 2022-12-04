/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TryLoadConfigSystem.h"

#include <fmt/core.h>

#include <TextFile.h>

#include <ECS/include/ExecuteSystem.h>
#include <ECS/include/Helper.h>

#include "Components/InputOutput/ArgumentComponent.h"
#include "Components/InputOutput/ResultComponent.h"
#include "Components/InputOutput/ConfigComponent.h"
#include "Components/InputOutput/PathsComponent.h"

#include "Generated files/JsonSerializer.h"

namespace nsContainerCodeGenerator
{
    void TTryLoadConfigSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(mEntMng);
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string str;
        TTextFile::Load(pathsComponent->absPathJsonFile, str);
        if (str.length() == 0) {
            resultComponent->value = fmt::format("Not loaded file \"{}\"\n", pathsComponent->absPathJsonFile);
            throw std::exception();
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&configComponent->value, str, err);
        if (!fillRes) {
            resultComponent->value = fmt::format("Deserilaize error in \"{}\", {}\n", pathsComponent->absPathJsonFile, err);
            throw std::exception();
        }
    }
}