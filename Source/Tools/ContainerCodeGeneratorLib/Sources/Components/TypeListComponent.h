/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include <ECS/include/IComponent.h>

#include <Parser/Sources/TypeInfo.h>

namespace nsContainerCodeGenerator
{
    struct DllExport TTypeListComponent : nsECSFramework::IComponent
    {
        std::list<nsCppParser::TTypeInfo> value;
    };
}