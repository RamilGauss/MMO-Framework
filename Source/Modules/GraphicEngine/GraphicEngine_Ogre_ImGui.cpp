/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine_Ogre_ImGui.h"
#include "BL_Debug.h"
#include "SrcEvent_ex.h"
#include "Logger.h"
#include "IRenderable.h"
#include "OgrePlatform.h"

#include <boost/cstdint.hpp>

#include "KeyMouseEventHandler.h"

using namespace nsGraphicEngine;

OgreBites::Event convert(const SDL_Event& in)
{
    OgreBites::Event out;

    out.type = 0;

    switch (in.type) {
        case SDL_KEYDOWN:
            out.type = OgreBites::KEYDOWN;
            OGRE_FALLTHROUGH;
        case SDL_KEYUP:
            if (!out.type)
                out.type = OgreBites::KEYUP;
            out.key.repeat = in.key.repeat;
            out.key.keysym.sym = in.key.keysym.sym;
            out.key.keysym.mod = in.key.keysym.mod;
            break;
        case SDL_MOUSEBUTTONUP:
            out.type = OgreBites::MOUSEBUTTONUP;
            OGRE_FALLTHROUGH;
        case SDL_MOUSEBUTTONDOWN:
            if (!out.type)
                out.type = OgreBites::MOUSEBUTTONDOWN;
            out.button.x = in.button.x;
            out.button.y = in.button.y;
            out.button.button = in.button.button;
            out.button.clicks = in.button.clicks;
            break;
        case SDL_MOUSEWHEEL:
            out.type = OgreBites::MOUSEWHEEL;
            out.wheel.y = in.wheel.y;
            break;
        case SDL_MOUSEMOTION:
            out.type = OgreBites::MOUSEMOTION;
            out.motion.x = in.motion.x;
            out.motion.y = in.motion.y;
            out.motion.xrel = in.motion.xrel;
            out.motion.yrel = in.motion.yrel;
            out.motion.windowID = in.motion.windowID;
            break;
        case SDL_FINGERDOWN:
            out.type = OgreBites::FINGERDOWN;
            OGRE_FALLTHROUGH;
        case SDL_FINGERUP:
            if (!out.type)
                out.type = OgreBites::FINGERUP;
            OGRE_FALLTHROUGH;
        case SDL_FINGERMOTION:
            if (!out.type)
                out.type = OgreBites::FINGERMOTION;
            out.tfinger.x = in.tfinger.x;
            out.tfinger.y = in.tfinger.y;
            out.tfinger.dx = in.tfinger.dx;
            out.tfinger.dy = in.tfinger.dy;
            out.tfinger.fingerId = in.tfinger.fingerId;
            break;
        case SDL_TEXTINPUT:
            out.type = OgreBites::TEXTINPUT;
            out.text.chars = in.text.text;
            break;
        case SDL_CONTROLLERAXISMOTION:
            out.type = OgreBites::CONTROLLERAXISMOTION;
            out.axis.which = in.caxis.which;
            out.axis.axis = in.caxis.axis;
            out.axis.value = in.caxis.value;
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            out.type = OgreBites::CONTROLLERBUTTONDOWN;
            OGRE_FALLTHROUGH;
        case SDL_CONTROLLERBUTTONUP:
            if (!out.type)
                out.type = OgreBites::CONTROLLERBUTTONUP;
            out.cbutton.which = in.cbutton.which;
            out.cbutton.button = in.cbutton.button;
            break;
    }

    return out;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::TGraphicEngine_Ogre_ImGui()
{
    mKeyMouseEventHandler.reset(new TKeyMouseEventHandler());
}
//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::~TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitOGRE(const std::string& pathPluginCfg, const std::string& pathOgreCfg)
{
    mPathPluginCfg = pathPluginCfg;
    mPathOgreCfg = pathOgreCfg;
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
    createRoot();

    if (!oneTimeConfig()) return false;

    if (!mFirstRun) mRoot->setRenderSystem(mRoot->getRenderSystemByName(mNextRenderer));

    setup();

    if (!mFirstRun) recoverLastSample();
    else if (initialSample) runSample(initialSample);

    mRoot->saveConfig();
#else

    initApp();

    loadStartUpSample();
#endif
    if (mRoot->getRenderSystem() == nullptr) {
        return false;
    }

    mRoot->getRenderSystem()->_initRenderTargets();
    return true;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddResource(const std::string& name, const std::string& type)
{
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type);
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::InitMyGUI()
{
    // Load resources
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    mGuiRender._setupTrays(mWindow);

    mGuiRender.testCapabilities(mRoot->getRenderSystem()->getCapabilities());
#ifdef OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
    mGuiRender.setShaderGenerator(mShaderGenerator);
#endif
    mGuiRender._setup(mWindow, mFSLayer, mOverlaySystem);   // start new sample

    mCurrentSample = &mGuiRender;
    return true;
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::frameStarted(const Ogre::FrameEvent& evt)
{
    // manually call sample callback to ensure correct order
    return !isCurrentSamplePaused() ? mCurrentSample->frameStarted(evt) : true;
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    // manually call sample callback to ensure correct order
    return !isCurrentSamplePaused() ? mCurrentSample->frameRenderingQueued(evt) : true;
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::frameEnded(const Ogre::FrameEvent& evt)
{
    // manually call sample callback to ensure correct order
    if (mCurrentSample && !mSamplePaused && !mCurrentSample->frameEnded(evt)) {
        return false;
    }
    // quit if window was closed
    if (mWindow->isClosed()) {
        return false;
    }
    // go into idle mode if current sample has ended
    if (mCurrentSample && mCurrentSample->isDone()) {
        runSample(0);
    }

    return true;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Work()
{
    pollEvents();

    auto renderResult = mRoot->renderOneFrame();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Close()
{
    closeApp();
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_Ogre_ImGui::GetRoot()
{
    return getRoot();
}
//---------------------------------------------------------------------
Ogre::SceneManager* TGraphicEngine_Ogre_ImGui::GetSceneManager()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::Camera* TGraphicEngine_Ogre_ImGui::GetCamera()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::RenderWindow* TGraphicEngine_Ogre_ImGui::GetWindow()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::TerrainGroup* TGraphicEngine_Ogre_ImGui::GetTerrainGroup()
{
    return nullptr;
}
//---------------------------------------------------------------------
Ogre::TerrainGlobalOptions* TGraphicEngine_Ogre_ImGui::GetTerrainGlobals()
{
    return nullptr;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetGUIEnableEvent(bool v)
{
    
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetGUIEnableEvent()
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetUseClipCursor(bool v)
{
    
}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetUseClipCursor()
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::GetWindowCaption(std::wstring& _text)
{
    
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetWindowCaption(const std::wstring& _text)
{

}
//---------------------------------------------------------------------
size_t TGraphicEngine_Ogre_ImGui::GetWindowHandle()
{
    return 0;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetTimeoutDblClick(int t_ms)
{

}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetCenterClippingCursor(bool v)
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::GetCenterClippingCursor()
{
    return false;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::createRoot()
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    mRoot = OGRE_NEW Ogre::Root("");
#else
    mRoot = OGRE_NEW Ogre::Root(mPathPluginCfg, mPathOgreCfg, "ogre.log");
#endif
    mOverlaySystem = OGRE_NEW Ogre::OverlaySystem();
}
//---------------------------------------------------------------------        
void TGraphicEngine_Ogre_ImGui::setup()
{
    mAppName = "MMO-Framework";
    OgreBites::ApplicationContext::setup();
    mWindow = getRenderWindow();
    addInputListener(this);
    //if (mGrabInput) setWindowGrab();
    //else mTrayMgr->hideCursor();

    //Sample* startupSample = loadSamples();

    // create template material for sample thumbnails
    //Ogre::MaterialPtr thumbMat = Ogre::MaterialManager::getSingleton().create("SdkTrays/SampleThumbnail", "Essential");
    //thumbMat->setLightingEnabled(false);
    //thumbMat->setDepthCheckEnabled(false);
    //thumbMat->getTechnique(0)->getPass(0)->createTextureUnitState();

    //setupWidgets();
    windowResized(mWindow);   // adjust menus for resolution

    //// if this is our first time running, and there's a startup sample, run it
    //if (startupSample && mFirstRun) {
    //    runSample(startupSample);
    //}
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddRender(IRenderable* p)
{
    mGuiRender.AddRender(p);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::RemoveRender(IRenderable* p)
{
    mGuiRender.RemoveRender(p);
}
//---------------------------------------------------------------------
const std::set<IRenderable*>* TGraphicEngine_Ogre_ImGui::GetRenders()
{
    return mGuiRender.GetRenders();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::pollEvents()
{
    mKeyMouseEventHandler->ClearEvents();

    if (mWindows.empty()) {
        // SDL events not initialized
        return;
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mRoot->queueEndRendering();
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event != SDL_WINDOWEVENT_RESIZED)
                    continue;

                for (WindowList::iterator it = mWindows.begin(); it != mWindows.end(); ++it) {
                    if (event.window.windowID != SDL_GetWindowID(it->native))
                        continue;

                    Ogre::RenderWindow* win = it->render;
                    win->resize(event.window.data1, event.window.data2);
                    windowResized(win);
                }
                break;
            case SDL_CONTROLLERDEVICEADDED:
                if (auto c = SDL_GameControllerOpen(event.cdevice.which)) {
                    const char* name = SDL_GameControllerName(c);
                    Ogre::LogManager::getSingleton().stream() << "Opened Gamepad: " << (name ? name : "unnamed");
                }
                break;
            default:
                mKeyMouseEventHandler->AddSdl2Event(event);
                _fireInputEvent(convert(event), event.window.windowID);
                break;
        }
    }
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::SetKeyMouseEventContainer(TKeyMouseEventContainer* keyMouseEventContainer)
{
    mKeyMouseEventHandler->SetContainer(keyMouseEventContainer);
}
//---------------------------------------------------------------------
