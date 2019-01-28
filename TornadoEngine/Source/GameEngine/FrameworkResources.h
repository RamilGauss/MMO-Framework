/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include "ReflectionMacro.h"

REFLECTION_ATTRIBUTE
struct TBaseResources
{
  std::string name;
};

REFLECTION_ATTRIBUTE
struct TGameEngineResources : TBaseResources
{

};

REFLECTION_ATTRIBUTE
struct TGraphicEngineResources : TBaseResources
{

};

REFLECTION_ATTRIBUTE
struct TGUIResources : TBaseResources
{

};

REFLECTION_ATTRIBUTE
struct TGameResources : TBaseResources
{

};

REFLECTION_ATTRIBUTE
struct TFrameworkResources
{
  TGameEngineResources GameEngine;
  TGraphicEngineResources GraphicEngine;
  TGUIResources GUI;
  TGameResources Game;
};