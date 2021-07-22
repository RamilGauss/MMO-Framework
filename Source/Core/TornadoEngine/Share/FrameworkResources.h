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

#pragma REFLECTION_ATTRIBUTE
struct TBaseResources
{
    std::string name;
};

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

using TStrStrListMap = std::map<std::string, std::list<std::string>>;

#pragma REFLECTION_ATTRIBUTE
struct TGameEngineResources : TBaseResources
{
    std::map<std::string, std::list<std::string>> resources;
};

#pragma REFLECTION_ATTRIBUTE
struct TGraphicEngineResources : TBaseResources
{
    std::string terrainPath;
    TOgreCfg pluginsCfg;
    TOgreCfg ogreCfg;
    std::map<std::string, std::list<std::string>> resources;
};

#pragma REFLECTION_ATTRIBUTE
struct TGUIResources : TBaseResources
{
    std::map<std::string, std::list<std::string>> resources;
};

#pragma REFLECTION_ATTRIBUTE
struct TGameResources : TBaseResources
{
    std::map<std::string, std::list<std::string>> resources;
};

#pragma REFLECTION_ATTRIBUTE
struct TFrameworkResources
{
    TGameEngineResources gameEngine;
    TGraphicEngineResources graphicEngine;
    TGUIResources gui;
    TGameResources game;
};