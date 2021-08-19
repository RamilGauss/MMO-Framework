/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IGraphicEngine_Ogre_ImGui.h"
#include "SrcEvent.h"
#include "CallBackRegistrator.h"

#include "ImGuiRenderControl.h"
#include "SampleContext.h"

#define STR_NAME_GRAPHIC_ENGINE "GE"

/*
  Задачи класса: организация использования кванта времени (через Work()),
  выдача событий клавиатуры и мыши (те что не были поглощены GUI),
  отрисовка окна GUI,
  давать возможность управления камерой,
  добавление и изменение объектов.
*/

namespace nsGraphicEngine
{
    class TKeyMouseEventHandler;
    class DllExport TGraphicEngine_Ogre_ImGui :
        public IGraphicEngine_Ogre_ImGui,
        public OgreBites::SampleContext,
        public TSrcEvent /*for generation keyboard and mouse events(unused by GUI)*/
    {
        std::string mPathPluginCfg;
        std::string mPathOgreCfg;

        TImGuiRenderControl mGuiRender;

        TKeyMouseEventContainer* mKeyMouseEventContainer = nullptr;

        std::shared_ptr<TKeyMouseEventHandler> mKeyMouseEventHandler;
    public:
        TGraphicEngine_Ogre_ImGui();
        virtual ~TGraphicEngine_Ogre_ImGui();
        /* Order of calls:
           1. InitOGRE, 2. AddResource, 3. InitImGui */
        bool InitOGRE(const std::string& pathPluginCfg, const std::string& pathOgreCfg) override;
        void AddResource(const std::string& name, const std::string& type) override;
        bool InitMyGUI() override;
        // return false - need exit
        void Work() override;

        void Close() override;

        int GetModifierKeyBoard() override { return 0; }

        void GetWindowCaption(std::wstring& _text) override;
        void SetWindowCaption(const std::wstring& _text) override;

        size_t GetWindowHandle() override;

        void SetTimeoutDblClick(int t_ms) override;

        // например, в шутерах когда мешает GUI для получения события движения мыши
        void SetCenterClippingCursor(bool v) override;
        bool GetCenterClippingCursor() override;

        Ogre::Root* GetRoot() override;
        Ogre::SceneManager* GetSceneManager() override;
        Ogre::Camera* GetCamera();
        Ogre::RenderWindow* GetWindow() override;

        Ogre::TerrainGroup* GetTerrainGroup() override;
        Ogre::TerrainGlobalOptions* GetTerrainGlobals() override;

        void SetGUIEnableEvent(bool v) override;
        bool GetGUIEnableEvent() override;

        void SetUseClipCursor(bool v) override;
        bool GetUseClipCursor() override;

        void AddRender(IRenderable* p)  override;
        void RemoveRender(IRenderable* p)  override;
        const std::set<IRenderable*>* GetRenders()  override;

        void SetKeyMouseEventContainer(TKeyMouseEventContainer* keyMouseEventContainer) override;
    public:

        void createRoot() override;
        void setup() override;

        bool frameStarted(const Ogre::FrameEvent& evt) override;
        bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
        bool frameEnded(const Ogre::FrameEvent& evt) override;


        void pollEvents() override;
    private:

    };
}