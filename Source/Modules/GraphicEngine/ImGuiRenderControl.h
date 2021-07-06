#pragma once

#include "TypeDef.h"

#include "SdkSample.h"
#include "OgreImGuiOverlay.h"
#include <OgreImGuiInputListener.h>

namespace nsGraphicEngine
{
    class IRenderable;

    class DllExport TImGuiRenderControl : public OgreBites::SdkSample, public Ogre::RenderTargetListener
    {
        std::unique_ptr<OgreBites::ImGuiInputListener> mImguiListener;
        OgreBites::InputListenerChain mListenerChain;

        std::set<nsGraphicEngine::IRenderable*> mRenders;
    public:
        void AddRender(nsGraphicEngine::IRenderable* pRenderable);
        void RemoveRender(nsGraphicEngine::IRenderable* pRenderable);
        const std::set<nsGraphicEngine::IRenderable*>* GetRenders();

        // Basic constructor
        TImGuiRenderControl();
        void preViewportUpdate(const Ogre::RenderTargetViewportEvent& evt);


        bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
        bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
        bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
        bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override;
        bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;
        bool mouseReleased(const OgreBites::MouseButtonEvent& evt) override;
        bool textInput(const OgreBites::TextInputEvent& evt) override;

        void setupContent(void);
        void cleanupContent();

    protected:
        void Render();
    };
}