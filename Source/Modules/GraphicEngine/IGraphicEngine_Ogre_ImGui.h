/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <string>

#include <OgreRoot.h>
#include <OgreWindow.h>

namespace nsGraphicEngine
{
    class IRenderable;
    struct TKeyMouseEventContainer;

    class DllExport IGraphicEngine_Ogre_ImGui
    {
    public:
        virtual ~IGraphicEngine_Ogre_ImGui() {}

        virtual bool Init(const std::string& pathPluginCfg, const std::string& ogreCfg) = 0;
        virtual void AddResource(const std::string& name, const std::string& type) = 0;

        virtual void Work() = 0;

        virtual Ogre::Root* GetRoot() = 0;
        virtual Ogre::Window* GetWindow() = 0;
    };
}