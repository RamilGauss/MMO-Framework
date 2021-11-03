/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSceneHeader
    {
        // Reserved
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentContent
    {
        std::string typeName;
        std::string jsonBody;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TEntityContent
    {
        std::list<TComponentContent> components;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSceneContent
    {
        TSceneHeader header;

        std::list<TEntityContent> entities;
    };
}