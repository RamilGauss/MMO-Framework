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
    struct TOgreCfg
    {
        std::string release;
        std::string debug;

        std::string Get()
        {
            return
#ifdef _DEBUG
                debug;
#else
                release;
#endif
        }
    };

#pragma REFLECTION_ATTRIBUTE
    struct TGraphicEngineResources
    {
        std::string terrainPath;
        TOgreCfg pluginsCfg;
        TOgreCfg ogreCfg;
        std::map<std::string, std::list<std::string>> resources;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TGameEngineResources
    {
        std::string sceneManagerContentMapPath;
        std::list<std::string> startScenesGuid;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TFrameworkResources
    {
        TGraphicEngineResources graphicEngine;
        TGameEngineResources gameEngine;
    };
}