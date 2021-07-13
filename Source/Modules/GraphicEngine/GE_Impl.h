/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <Ogre.h>
#include <OgreTerrainGroup.h>
#include <OgreWindowEventUtilities.h>
#include <OgreOverlaySystem.h>

#ifdef OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
#include <OgreSGTechniqueResolverListener.h>
#endif // INCLUDE_RTSHADER_SYSTEM

#include "CallBackRegistrator.h"
#include "Events.h"
#include "ControlClippingCursor.h"

#include "ImGuiRenderControl.h"


namespace nsGraphicEngine
{
    class TGE_Impl : public Ogre::FrameListener, public Ogre::WindowEventListener
    {
        TImGuiRenderControl mGuiRender;

        TControlClippingCursor mClipCursor;
        bool flgCenterClippingCursor = false;

        bool flgGUIEnableEvent = true;
        bool flgUseClipCursor = true;
    public:
        TGE_Impl();
        virtual ~TGE_Impl();

        bool InitOGRE(const std::string& pathPluginCfg, const std::string& ogreCfg);
        void AddResource(const std::string& name, const std::string& type);
        bool InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin);

        bool Work();

        //void SetCallBackKeyBoard(TCallBackRegistrator2<const OIS::KeyEvent&, bool>* pCB);
        //void SetCallBackMouse(TCallBackRegistrator3<const OIS::MouseEvent&, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>* pCB);

        int GetModifierKeyBoard();

        void GetWindowCaption(std::wstring& _text);
        void SetWindowCaption(const std::wstring& _text);
        size_t GetWindowHandle();

        void SetCenterClippingCursor(bool v);
        bool GetCenterClippingCursor();

        Ogre::SceneManager* GetSceneManager();
        Ogre::Root* GetRoot();
        Ogre::Camera* GetCamera();
        Ogre::RenderWindow* GetWindow();

        Ogre::TerrainGroup* GetTerrainGroup();
        Ogre::TerrainGlobalOptions* GetTerrainGlobals();

        void SetGUIEnableEvent(bool v);
        bool GetGUIEnableEvent();

        void SetUseClipCursor(bool v);
        bool GetUseClipCursor();
    protected:
        void TryClipCursor();
        void ClipCursor();
        void UnclipCursor();

        bool IsWindowFocus();

        //void SetKeyBoardModifier(const OIS::KeyEvent& arg, bool pressed);

        void Done();
        void DestroyGui();

        bool InitialiseRTShaderSystem();

        //virtual bool mouseMoved(const OIS::MouseEvent& arg);
        //virtual bool mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
        //virtual bool mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
        //virtual bool keyPressed(const OIS::KeyEvent& arg);
        //virtual bool keyReleased(const OIS::KeyEvent& arg);
    private:
        virtual bool frameStarted(const Ogre::FrameEvent& _evt);
        virtual bool frameEnded(const Ogre::FrameEvent& _evt);
        virtual void windowMoved(Ogre::RenderWindow* rw);
        virtual void windowResized(Ogre::RenderWindow* _rw);
        virtual void windowClosed(Ogre::RenderWindow* _rw);
        virtual void windowFocusChange(Ogre::RenderWindow* rw);

    private:
        //MyGUI::Gui* mGUI;
        //MyGUI::OgrePlatform* mPlatform;

        Ogre::Root* mRoot = nullptr;
        Ogre::Camera* mCamera = nullptr;
        Ogre::SceneManager* mSceneManager = nullptr;
        Ogre::RenderWindow* mWindow = nullptr;
        Ogre::OverlaySystem* mOverlaySystem = nullptr;  // Overlay system

        Ogre::TerrainGroup* mTerrainGroup = nullptr;
        Ogre::TerrainGlobalOptions* mTerrainGlobals = nullptr;

        Ogre::FileSystemLayer* mFSLayer = nullptr; // File system abstraction layer

#ifdef OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
        Ogre::RTShader::ShaderGenerator* mShaderGenerator = nullptr;
        OgreBites::SGTechniqueResolverListener* mMaterialMgrListener = nullptr; // Shader generator material manager listener.
#endif

        bool mExit = false;

        int mKeyModifier = 0;

        //TCallBackRegistrator2<const OIS::KeyEvent&, bool>* mCBKeyBoard;
        //TCallBackRegistrator3<const OIS::MouseEvent&, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>* mCBMouse;

        bool flgLControl_Press = false;
        bool flgRControl_Press = false;
        bool flgLAlt_Press = false;
        bool flgRAlt_Press = false;
        bool flgLShift_Press = false;
        bool flgRShift_Press = false;
    };
}