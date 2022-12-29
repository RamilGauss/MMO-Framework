/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include <ECS/include/IComponent.h>

namespace nsContainerCodeGenerator
{
    struct TGeneratedFile
    {
        std::string content;
        std::string absPath;
    };

    struct DllExport TGeneratedFilesComponent : nsECSFramework::IComponent
    {
        mutable std::list<TGeneratedFile> value;
    };
}