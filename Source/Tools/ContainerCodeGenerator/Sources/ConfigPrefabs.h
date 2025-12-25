/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ContainerCodeGeneratorLib/Sources/Configs/CoreConfig.h"
#include "ContainerCodeGeneratorLib/Sources/Configs/ProjectConfig.h"

struct TConfigPrefabs
{
    nsContainerCodeGenerator::TCoreConfig MakeCoreDefault() const;
    nsContainerCodeGenerator::TProjectConfig MakeProjectDefault(const std::string& projectNameSpace) const;
};
