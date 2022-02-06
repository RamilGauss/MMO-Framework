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


#include "OgreArchiveManager.h"
#include "OgreCamera.h"
#include "OgreConfigFile.h"
#include "OgreRoot.h"
#include "OgreWindow.h"

#include "OgreHlmsManager.h"
#include "OgreHlmsPbs.h"
#include "OgreHlmsUnlit.h"

#include "Compositor/OgreCompositorManager2.h"

#include "OgreWindowEventUtilities.h"


#include <boost/cstdint.hpp>

#include "KeyMouseEventHandler.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#   include "OSX/macUtils.h"
#endif

using namespace nsGraphicEngine;

//OgreBites::Event convert(const SDL_Event& in)
//{
//    OgreBites::Event out;
//
//    out.type = 0;
//
//    switch (in.type) {
//        case SDL_KEYDOWN:
//            out.type = OgreBites::KEYDOWN;
//            OGRE_FALLTHROUGH;
//        case SDL_KEYUP:
//            if (!out.type)
//                out.type = OgreBites::KEYUP;
//            out.key.repeat = in.key.repeat;
//            out.key.keysym.sym = in.key.keysym.sym;
//            out.key.keysym.mod = in.key.keysym.mod;
//            break;
//        case SDL_MOUSEBUTTONUP:
//            out.type = OgreBites::MOUSEBUTTONUP;
//            OGRE_FALLTHROUGH;
//        case SDL_MOUSEBUTTONDOWN:
//            if (!out.type)
//                out.type = OgreBites::MOUSEBUTTONDOWN;
//            out.button.x = in.button.x;
//            out.button.y = in.button.y;
//            out.button.button = in.button.button;
//            out.button.clicks = in.button.clicks;
//            break;
//        case SDL_MOUSEWHEEL:
//            out.type = OgreBites::MOUSEWHEEL;
//            out.wheel.y = in.wheel.y;
//            break;
//        case SDL_MOUSEMOTION:
//            out.type = OgreBites::MOUSEMOTION;
//            out.motion.x = in.motion.x;
//            out.motion.y = in.motion.y;
//            out.motion.xrel = in.motion.xrel;
//            out.motion.yrel = in.motion.yrel;
//            out.motion.windowID = in.motion.windowID;
//            break;
//        case SDL_FINGERDOWN:
//            out.type = OgreBites::FINGERDOWN;
//            OGRE_FALLTHROUGH;
//        case SDL_FINGERUP:
//            if (!out.type)
//                out.type = OgreBites::FINGERUP;
//            OGRE_FALLTHROUGH;
//        case SDL_FINGERMOTION:
//            if (!out.type)
//                out.type = OgreBites::FINGERMOTION;
//            out.tfinger.x = in.tfinger.x;
//            out.tfinger.y = in.tfinger.y;
//            out.tfinger.dx = in.tfinger.dx;
//            out.tfinger.dy = in.tfinger.dy;
//            out.tfinger.fingerId = in.tfinger.fingerId;
//            break;
//        case SDL_TEXTINPUT:
//            out.type = OgreBites::TEXTINPUT;
//            out.text.chars = in.text.text;
//            break;
//        case SDL_CONTROLLERAXISMOTION:
//            out.type = OgreBites::CONTROLLERAXISMOTION;
//            out.axis.which = in.caxis.which;
//            out.axis.axis = in.caxis.axis;
//            out.axis.value = in.caxis.value;
//            break;
//        case SDL_CONTROLLERBUTTONDOWN:
//            out.type = OgreBites::CONTROLLERBUTTONDOWN;
//            OGRE_FALLTHROUGH;
//        case SDL_CONTROLLERBUTTONUP:
//            if (!out.type)
//                out.type = OgreBites::CONTROLLERBUTTONUP;
//            out.cbutton.which = in.cbutton.which;
//            out.cbutton.button = in.cbutton.button;
//            break;
//    }
//
//    return out;
//}
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
bool TGraphicEngine_Ogre_ImGui::Init(const std::string& pathPluginCfg, const std::string& pathOgreCfg)
{
    using namespace Ogre;

    mRoot = OGRE_NEW Root(pathPluginCfg, pathOgreCfg);

    if (!mRoot->showConfigDialog()) {
        return false;
    }

    // Initialize Root
    mRoot->getRenderSystem()->setConfigOption("sRGB Gamma Conversion", "Yes");
    mRoot->initialise(false, "");

    Ogre::ConfigOptionMap& cfgOpts = mRoot->getRenderSystem()->getConfigOptions();

    int width = 1280;
    int height = 720;

    Ogre::ConfigOptionMap::iterator opt = cfgOpts.find("Video Mode");
    if (opt != cfgOpts.end() && !opt->second.currentValue.empty()) {
        //Ignore leading space
        const Ogre::String::size_type start = opt->second.currentValue.find_first_of("012356789");
        //Get the width and height
        Ogre::String::size_type widthEnd = opt->second.currentValue.find(' ', start);
        // we know that the height starts 3 characters after the width and goes until the next space
        Ogre::String::size_type heightEnd = opt->second.currentValue.find(' ', widthEnd + 3);
        // Now we can parse out the values
        width = Ogre::StringConverter::parseInt(opt->second.currentValue.substr(0, widthEnd));
        height = Ogre::StringConverter::parseInt(opt->second.currentValue.substr(
            widthEnd + 3, heightEnd));
    }

    Ogre::NameValuePairList params;
    bool fullscreen = Ogre::StringConverter::parseBool(cfgOpts["Full Screen"].currentValue);

    int screen = 0;
    int posX = SDL_WINDOWPOS_CENTERED_DISPLAY(screen);
    int posY = SDL_WINDOWPOS_CENTERED_DISPLAY(screen);

    if (fullscreen) {
        posX = SDL_WINDOWPOS_UNDEFINED_DISPLAY(screen);
        posY = SDL_WINDOWPOS_UNDEFINED_DISPLAY(screen);
    }

    mSdlWindow = SDL_CreateWindow(
        "",    // window title
        posX,               // initial x position
        posY,               // initial y position
        width,              // width, in pixels
        height,             // height, in pixels
        SDL_WINDOW_SHOWN
        | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0) | SDL_WINDOW_RESIZABLE);

    //Get the native whnd
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);

    if (SDL_GetWindowWMInfo(mSdlWindow, &wmInfo) == SDL_FALSE) {
        OGRE_EXCEPT(Ogre::Exception::ERR_INTERNAL_ERROR,
            "Couldn't get WM Info! (SDL2)",
            "GraphicsSystem::initialize");
    }

    Ogre::String winHandle;
    switch (wmInfo.subsystem) {
#if defined(SDL_VIDEO_DRIVER_WINDOWS)
        case SDL_SYSWM_WINDOWS:
            // Windows code
            winHandle = Ogre::StringConverter::toString((uintptr_t) wmInfo.info.win.window);
            break;
#endif
#if defined(SDL_VIDEO_DRIVER_WINRT)
        case SDL_SYSWM_WINRT:
            // Windows code
            winHandle = Ogre::StringConverter::toString((uintptr_t) wmInfo.info.winrt.window);
            break;
#endif
#if defined(SDL_VIDEO_DRIVER_COCOA)
        case SDL_SYSWM_COCOA:
            winHandle = Ogre::StringConverter::toString(WindowContentViewHandle(wmInfo));
            break;
#endif
#if defined(SDL_VIDEO_DRIVER_X11)
        case SDL_SYSWM_X11:
            winHandle = Ogre::StringConverter::toString((uintptr_t) wmInfo.info.x11.window);
            params.insert(std::make_pair(
                "SDL2x11", Ogre::StringConverter::toString((uintptr_t) &wmInfo.info.x11)));
            break;
#endif
        default:
            OGRE_EXCEPT(Ogre::Exception::ERR_NOT_IMPLEMENTED,
                "Unexpected WM! (SDL2)",
                "GraphicsSystem::initialize");
            break;
    }

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT
    params.insert(std::make_pair("externalWindowHandle", winHandle));
#else
    params.insert(std::make_pair("parentWindowHandle", winHandle));
#endif


    params.insert(std::make_pair("title", ""));
    params.insert(std::make_pair("gamma", cfgOpts["sRGB Gamma Conversion"].currentValue));
    if (cfgOpts.find("VSync Method") != cfgOpts.end())
        params.insert(std::make_pair("vsync_method", cfgOpts["VSync Method"].currentValue));
    params.insert(std::make_pair("FSAA", cfgOpts["FSAA"].currentValue));
    params.insert(std::make_pair("vsync", cfgOpts["VSync"].currentValue));
    params.insert(std::make_pair("reverse_depth", "Yes"));

    //initMiscParamsListener(params);

    mWindow = Ogre::Root::getSingleton().createRenderWindow("", width, height, fullscreen, &params);

    mOverlaySystem = OGRE_NEW Ogre::v1::OverlaySystem();

    //### registerHlms();

    return true;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddResource(const std::string& name, const std::string& type)
{
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Work()
{
    Ogre::WindowEventUtilities::messagePump();

    pollEvents();

    auto renderResult = mRoot->renderOneFrame();
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_Ogre_ImGui::GetRoot()
{
    return mRoot;
}
//---------------------------------------------------------------------
Ogre::Window* TGraphicEngine_Ogre_ImGui::GetWindow()
{
    return mWindow;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::pollEvents()
{
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        switch (evt.type) {
            case SDL_WINDOWEVENT:
                handleWindowEvent(evt);
                break;
            case SDL_QUIT:
                //mQuit = true;
                break;
            default:
                break;
        }

        //mInputHandler->_handleSdlEvents(evt);
    }

    //mKeyMouseEventHandler->ClearEvents();

    //if (mWindows.empty()) {
    //    // SDL events not initialized
    //    return;
    //}

    //SDL_Event event;
    //while (SDL_PollEvent(&event)) {
    //    switch (event.type) {
    //        case SDL_QUIT:
    //            mRoot->queueEndRendering();
    //            break;
    //        case SDL_WINDOWEVENT:
    //            if (event.window.event != SDL_WINDOWEVENT_RESIZED)
    //                continue;

    //            for (WindowList::iterator it = mWindows.begin(); it != mWindows.end(); ++it) {
    //                if (event.window.windowID != SDL_GetWindowID(it->native))
    //                    continue;

    //                Ogre::RenderWindow* win = it->render;
    //                mWindow->resize(event.window.data1, event.window.data2);
    //                windowResized(win);
    //            }
    //            break;
    //        case SDL_CONTROLLERDEVICEADDED:
    //            if (auto c = SDL_GameControllerOpen(event.cdevice.which)) {
    //                const char* name = SDL_GameControllerName(c);
    //                Ogre::LogManager::getSingleton().stream() << "Opened Gamepad: " << (name ? name : "unnamed");
    //            }
    //            break;
    //        default:
    //            mKeyMouseEventHandler->AddSdl2Event(event);
    //            //_fireInputEvent(convert(event), event.window.windowID);
    //            break;
    //    }
    //}
}
//---------------------------------------------------------------------
//void TGraphicEngine_Ogre_ImGui::SetKeyMouseEventContainer(TKeyMouseEventContainer* keyMouseEventContainer)
//{
//    mKeyMouseEventHandler->SetContainer(keyMouseEventContainer);
//}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::RegisterHlms()
{
    using namespace Ogre;

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    // Note:  macBundlePath works for iOS too. It's misnamed.
    const String resourcePath = Ogre::macResourcesPath();
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
    const String resourcePath = Ogre::macBundlePath() + "/";
#else
    String resourcePath = "";
#endif

    ConfigFile cf;
    cf.load(resourcePath + "resources2.cfg");

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
    String rootHlmsFolder = macBundlePath() + '/' + cf.getSetting("DoNotUseAsResource", "Hlms", "");
#else
    String rootHlmsFolder = resourcePath + cf.getSetting("DoNotUseAsResource", "Hlms", "");
#endif

    if (rootHlmsFolder.empty())
        rootHlmsFolder = "./";
    else if (*(rootHlmsFolder.end() - 1) != '/')
        rootHlmsFolder += "/";

    // At this point rootHlmsFolder should be a valid path to the Hlms data folder

    HlmsUnlit* hlmsUnlit = 0;
    HlmsPbs* hlmsPbs = 0;

    // For retrieval of the paths to the different folders needed
    String mainFolderPath;
    StringVector libraryFoldersPaths;
    StringVector::const_iterator libraryFolderPathIt;
    StringVector::const_iterator libraryFolderPathEn;

    ArchiveManager& archiveManager = ArchiveManager::getSingleton();

    {
        // Create & Register HlmsUnlit
        // Get the path to all the subdirectories used by HlmsUnlit
        HlmsUnlit::getDefaultPaths(mainFolderPath, libraryFoldersPaths);
        Archive* archiveUnlit =
            archiveManager.load(rootHlmsFolder + mainFolderPath, "FileSystem", true);
        ArchiveVec archiveUnlitLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while (libraryFolderPathIt != libraryFolderPathEn) {
            Archive* archiveLibrary =
                archiveManager.load(rootHlmsFolder + *libraryFolderPathIt, "FileSystem", true);
            archiveUnlitLibraryFolders.push_back(archiveLibrary);
            ++libraryFolderPathIt;
        }

        // Create and register the unlit Hlms
        hlmsUnlit = OGRE_NEW HlmsUnlit(archiveUnlit, &archiveUnlitLibraryFolders);
        Root::getSingleton().getHlmsManager()->registerHlms(hlmsUnlit);
    }

    {
        // Create & Register HlmsPbs
        // Do the same for HlmsPbs:
        HlmsPbs::getDefaultPaths(mainFolderPath, libraryFoldersPaths);
        Archive* archivePbs = archiveManager.load(rootHlmsFolder + mainFolderPath, "FileSystem", true);

        // Get the library archive(s)
        ArchiveVec archivePbsLibraryFolders;
        libraryFolderPathIt = libraryFoldersPaths.begin();
        libraryFolderPathEn = libraryFoldersPaths.end();
        while (libraryFolderPathIt != libraryFolderPathEn) {
            Archive* archiveLibrary =
                archiveManager.load(rootHlmsFolder + *libraryFolderPathIt, "FileSystem", true);
            archivePbsLibraryFolders.push_back(archiveLibrary);
            ++libraryFolderPathIt;
        }

        // Create and register
        hlmsPbs = OGRE_NEW HlmsPbs(archivePbs, &archivePbsLibraryFolders);
        Root::getSingleton().getHlmsManager()->registerHlms(hlmsPbs);
    }

    RenderSystem* renderSystem = Root::getSingletonPtr()->getRenderSystem();
    if (renderSystem->getName() == "Direct3D11 Rendering Subsystem") {
        // Set lower limits 512kb instead of the default 4MB per Hlms in D3D 11.0
        // and below to avoid saturating AMD's discard limit (8MB) or
        // saturate the PCIE bus in some low end machines.
        bool supportsNoOverwriteOnTextureBuffers;
        renderSystem->getCustomAttribute("MapNoOverwriteOnDynamicBufferSRV",
            &supportsNoOverwriteOnTextureBuffers);

        if (!supportsNoOverwriteOnTextureBuffers) {
            hlmsPbs->setTextureBufferDefaultSize(512 * 1024);
            hlmsUnlit->setTextureBufferDefaultSize(512 * 1024);
        }
    }
}
//-------------------------------------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::handleWindowEvent(const SDL_Event& evt)
{
    switch (evt.window.event) {
        /*case SDL_WINDOWEVENT_MAXIMIZED:
            SDL_SetWindowBordered( mSdlWindow, SDL_FALSE );
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
        case SDL_WINDOWEVENT_RESTORED:
            SDL_SetWindowBordered( mSdlWindow, SDL_TRUE );
            break;*/
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            int w, h;
            SDL_GetWindowSize(mSdlWindow, &w, &h);
#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
            mWindow->requestResolution(w, h);
#endif
            mWindow->windowMovedOrResized();
            break;
        case SDL_WINDOWEVENT_RESIZED:
#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
            mWindow->requestResolution(evt.window.data1, evt.window.data2);
#endif
            mWindow->windowMovedOrResized();
            break;
        case SDL_WINDOWEVENT_CLOSE:
            break;
        case SDL_WINDOWEVENT_SHOWN:
            mWindow->_setVisible(true);
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            mWindow->_setVisible(false);
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            mWindow->setFocused(true);
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            mWindow->setFocused(false);
            break;
    }
}
//-------------------------------------------------------------------------------------------------
Ogre::v1::OverlaySystem* TGraphicEngine_Ogre_ImGui::GetOverlaySystem()
{
    return mOverlaySystem;
}
//-------------------------------------------------------------------------------------------------