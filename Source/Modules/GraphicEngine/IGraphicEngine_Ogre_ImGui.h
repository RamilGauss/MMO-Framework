/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <string>
#include <Ogre.h>
#include <OgreTerrainGroup.h>

namespace nsGraphicEngine
{
    class IRenderable;
    struct TKeyMouseEventContainer;
    class DllExport IGraphicEngine_Ogre_ImGui
    {
    public:
        virtual ~IGraphicEngine_Ogre_ImGui() {}

        virtual bool InitOGRE(const std::string& pathPluginCfg, const std::string& ogreCfg) = 0;
        virtual void AddResource(const std::string& name, const std::string& type) = 0;
        virtual bool InitMyGUI() = 0;

        virtual void Work() = 0;

        virtual void Close() = 0;

        virtual int GetModifierKeyBoard() = 0;

        virtual void GetWindowCaption(std::wstring& _text) = 0;
        virtual void SetWindowCaption(const std::wstring& _text) = 0;
        virtual size_t GetWindowHandle() = 0;

        virtual void SetCenterClippingCursor(bool v) = 0;
        virtual bool GetCenterClippingCursor() = 0;

        virtual void SetTimeoutDblClick(int t_ms) = 0;

        virtual Ogre::SceneManager* GetSceneManager() = 0;
        virtual Ogre::Root* GetRoot() = 0;
        virtual Ogre::Camera* GetCamera() = 0;
        virtual Ogre::RenderWindow* GetWindow() = 0;

        virtual Ogre::TerrainGroup* GetTerrainGroup() = 0;
        virtual Ogre::TerrainGlobalOptions* GetTerrainGlobals() = 0;

        virtual void SetGUIEnableEvent(bool v) = 0;
        virtual bool GetGUIEnableEvent() = 0;

        virtual void SetUseClipCursor(bool v) = 0;
        virtual bool GetUseClipCursor() = 0;

        virtual void AddRender(IRenderable* p) = 0;
        virtual void RemoveRender(IRenderable* p) = 0;
        virtual const std::set<IRenderable*>* GetRenders() = 0;

        virtual void SetKeyMouseEventContainer(TKeyMouseEventContainer* keyMouseEventContainer) = 0;
    };
}