/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "SrcEvent.h"
#include "CallBackRegistrator.h"
#include "Events.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreTerrainGroup.h>

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
    class TGE_Impl;

    class DllExport TGraphicEngine_Ogre_ImGui :
        public TSrcEvent /*for generation keyboard and mouse events(unused by GUI)*/
    {
        //TCallBackRegistrator2<const OIS::KeyEvent&, bool> mCBKeyBoard;
        //TCallBackRegistrator3<const OIS::MouseEvent&, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent> mCBMouse;
    public:
        TGraphicEngine_Ogre_ImGui();
        virtual ~TGraphicEngine_Ogre_ImGui();
        /* Order of calls:
           1. InitOGRE, 2. AddResource, 3. InitMyGUI */
        bool InitOGRE(const std::string& pathPluginCfg, const std::string& pathOgreCfg);
        void AddResource(const std::string& name, const std::string& type);
        bool InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin);
        // return false - need exit
        bool Work();

        void GetWindowCaption(std::wstring& _text);
        void SetWindowCaption(const std::wstring& _text);

        size_t GetWindowHandle();

        void SetTimeoutDblClick(int t_ms);

        // например, в шутерах когда мешает GUI для получения события движения мыши
        void SetCenterClippingCursor(bool v);
        bool GetCenterClippingCursor();

        Ogre::Root* GetRoot();
        Ogre::SceneManager* GetSceneManager();
        Ogre::Camera* GetCamera();
        Ogre::RenderWindow* GetWindow();

        Ogre::TerrainGroup* GetTerrainGroup();
        Ogre::TerrainGlobalOptions* GetTerrainGlobals();

        void SetGUIEnableEvent(bool v);
        bool GetGUIEnableEvent();

        void SetUseClipCursor(bool v);
        bool GetUseClipCursor();
    private:
        std::shared_ptr<TGE_Impl> mGE;
    private:
        struct TInfoClick
        {
            unsigned int mTimePrevLastPress;
            unsigned int mTimeLastPress;
            TInfoClick()
            {
                Init();
            }
            void Init()
            {
                mTimePrevLastPress = -1; mTimeLastPress = -1;
            }
            void SetTime(unsigned int t)
            {
                mTimePrevLastPress = mTimeLastPress; mTimeLastPress = t;
            }
            bool IsSecondRelease()
            {
                return mTimePrevLastPress != -1;
            }
        };

        TInfoClick mLClick;
        TInfoClick mRClick;

        int mTimeoutDblClick;
        enum
        {
            eTimeoutDblClick = 350, // ms
        };
    };
}