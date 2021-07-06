/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <OgreTerrainGroup.h>
#include <Ogre.h>
#include <OgreWindowEventUtilities.h>
#include "IImGuiRender.h"

#include "InputManagerOIS.h"
#include "CallBackRegistrator.h"
#include "Events.h"
#include "ControlClippingCursor.h"
#include <OgreOverlaySystem.h>

#ifdef OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
#include "OgreSGTechniqueResolverListener.h"
#endif // INCLUDE_RTSHADER_SYSTEM

#include "ImGuiDemo.h"

namespace nsGraphicEngine
{
    class TGE_Impl : public Ogre::FrameListener, public Ogre::WindowEventListener
    {
        Sample_ImGui simple;

        const std::string DIRECTX_9 = "Direct3D9 Rendering Subsystem";
        const std::string DIRECTX_10 = "Direct3D10 Rendering Subsystem";
        const std::string DIRECTX_11 = "Direct3D11 Rendering Subsystem";
        const std::string DIRECTX_12 = "Direct3D12 Rendering Subsystem";
        const std::string OPEN_GL_2 = "";
        const std::string OPEN_GL_3 = "";

        TControlClippingCursor mClipCursor;
        bool flgCenterClippingCursor;

        bool flgGUIEnableEvent = true;
        bool flgUseClipCursor = true;
    public:
        TGE_Impl();
        virtual ~TGE_Impl();

        bool InitOGRE(const std::string& pathPluginCfg, const std::string& ogreCfg);
        void AddResource(const std::string& name, const std::string& type);

        bool Work();

        //void SetCallBackKeyBoard(TCallBackRegistrator2<const OIS::KeyEvent &, bool>* pCB);
        //void SetCallBackMouse(TCallBackRegistrator3<const OIS::MouseEvent &, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>*  pCB);

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

        void AddRenderable(IRenderable* renderable);
        void RemoveRenderable(IRenderable* renderable);
        std::set<IRenderable*>* GetRenderable();
    protected:
        bool InitGui();

        void TryClipCursor();
        void ClipCursor();
        void UnclipCursor();

        bool IsWindowFocus();

        //void SetKeyBoardModifier(const OIS::KeyEvent &arg, bool pressed);

        void Done();
        void DestroyGui();

        bool InitialiseRTShaderSystem();

    private:
        virtual bool frameStarted(const Ogre::FrameEvent& _evt);
        virtual bool frameEnded(const Ogre::FrameEvent& _evt);

        virtual void windowMoved(Ogre::RenderWindow* rw);
        virtual void windowResized(Ogre::RenderWindow* _rw);
        virtual void windowClosed(Ogre::RenderWindow* _rw);
        virtual void windowFocusChange(Ogre::RenderWindow* rw);

    private:
        nsImGuiRenderWrapper::IImGuiRender* mImGuiRender = nullptr;

        Ogre::Root* mRoot = nullptr;
        Ogre::Camera* mCamera = nullptr;
        Ogre::SceneManager* mSceneManager = nullptr;
        Ogre::RenderWindow* mWindow = nullptr;
        Ogre::OverlaySystem* mOverlaySystem = nullptr;

        Ogre::TerrainGroup* mTerrainGroup = nullptr;
        Ogre::TerrainGlobalOptions* mTerrainGlobals = nullptr;
#ifdef OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
        Ogre::RTShader::ShaderGenerator* mShaderGenerator = nullptr;
        OgreBites::SGTechniqueResolverListener* mMaterialMgrListener = nullptr; // Shader generator material manager listener.
#endif


        bool mExit = false;

        int mKeyModifier = 0;

        //TCallBackRegistrator2<const OIS::KeyEvent &, bool>* mCBKeyBoard;
        //TCallBackRegistrator3<const OIS::MouseEvent&,OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>* mCBMouse;

        bool flgLControl_Press = false;
        bool flgRControl_Press = false;
        bool flgLAlt_Press = false;
        bool flgRAlt_Press = false;
        bool flgLShift_Press = false;
        bool flgRShift_Press = false;

        std::set<IRenderable*> mRenderables;
    };
}