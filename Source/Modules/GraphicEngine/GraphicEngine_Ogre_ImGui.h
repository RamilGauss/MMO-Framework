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


#include <SDL2/SDL.h>

//#include "ImGuiRenderControl.h"
//#include "SampleContext.h"

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
        public TSrcEvent /*for generation keyboard and mouse events(unused by GUI)*/
    {
        std::string mPathPluginCfg;
        std::string mPathOgreCfg;

        //TImGuiRenderControl mGuiRender;

        std::shared_ptr<TKeyMouseEventHandler> mKeyMouseEventHandler;

        Ogre::Root* mRoot = nullptr;
        Ogre::Window* mWindow = nullptr;

        Ogre::v1::OverlaySystem* mOverlaySystem = nullptr;;

        SDL_Window* mSdlWindow;
        //SdlInputHandler* mInputHandler;

    public:
        TGraphicEngine_Ogre_ImGui();
        virtual ~TGraphicEngine_Ogre_ImGui();

        bool Init(const std::string& pathPluginCfg, const std::string& pathOgreCfg) override;
        void AddResource(const std::string& name, const std::string& type) override;

        void Work() override;

        Ogre::Root* GetRoot() override;
        Ogre::Window* GetWindow() override;

        Ogre::v1::OverlaySystem* GetOverlaySystem() override;
    private:
        void RegisterHlms();

        void pollEvents();

        void handleWindowEvent(const SDL_Event& evt);
    };
}