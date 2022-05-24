/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <list>

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct TGameEngineResources
    {
        std::string sceneManagerContentMapPath;
        std::list<std::string> startScenesGuid;

        std::string prefabManagerContentMapPath;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TFrameworkResources
    {
        std::map<std::string, std::string> resources;

        TGameEngineResources gameEngine;
    };
}