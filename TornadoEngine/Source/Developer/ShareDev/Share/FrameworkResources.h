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

#include "ReflectionMacro.h"

REFLECTION_ATTRIBUTE
struct TBaseResources
{
  std::string name;
};

REFLECTION_ATTRIBUTE
struct TOgreCfg
{
  std::string release;
  std::string debug;
};

REFLECTION_ATTRIBUTE
struct TOgreResources
{
  std::map<std::string, std::list<std::string>> release;
};

REFLECTION_ATTRIBUTE
struct TGameEngineResources : TBaseResources
{
  std::string conveyerPath;
};

REFLECTION_ATTRIBUTE
struct TGraphicEngineResources : TBaseResources
{
  std::string terrainPath;
  TOgreCfg pluginsCfg;
  TOgreCfg ogreCfg;
  TOgreResources resources;
};

REFLECTION_ATTRIBUTE
struct TGUIResources : TBaseResources
{
  TOgreResources resources;
};

REFLECTION_ATTRIBUTE
struct TGameResources : TBaseResources
{
  TOgreResources resources;
};

REFLECTION_ATTRIBUTE
struct TFrameworkResources
{
  TGameEngineResources gameEngine;
  TGraphicEngineResources graphicEngine;
  TGUIResources gui;
  TGameResources game;
};