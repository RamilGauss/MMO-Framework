#include "ImGuiRenderControl.h"
#include "IRenderable.h"

using namespace Ogre;
using namespace OgreBites;
using namespace nsGraphicEngine;

//###
class TMainForm : public IRenderable
{
    char buffer[100];
    bool isShowUserGuide = false;

    bool isFirst = true;
public:
    TMainForm()
    {
        buffer[0] = '\0';
    }
    void Render() override
    {
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Exit", "Alt+F4")) {
                    //mRoot->queueEndRendering();
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit")) {
                if (ImGui::MenuItem("ShowUserGuide", "Ha-ha")) {
                    isShowUserGuide = !isShowUserGuide;
                }
                if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
                ImGui::Separator();
                if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        if (isShowUserGuide) {
            ImGui::Begin("Window");

            if (isFirst) {
                ImVec2 size(500, 500);
                ImGui::SetWindowSize(size);
                ImVec2 pos(10, 10);
                ImGui::SetWindowPos(pos);
                isFirst = false;
            }

            ImVec2 btPos(50, 50);
            ImGui::SetCursorPos(btPos);

            ImVec2 btSize(100, 30);
            if (ImGui::Button("Login", btSize)) {

            }

            ImGui::InputText("ASDASD", buffer, sizeof(buffer));

            ImGui::End();
        }
    }
};
//----------------------------------------------------------------------------------------------
static TMainForm mMainForm;
//###
//----------------------------------------------------------------------------------------------
TImGuiRenderControl::TImGuiRenderControl()
{
    mInfo["Title"] = "Dear ImGui integration";
    mInfo["Description"] = "Overlay ImGui interactions";
    mInfo["Category"] = "Unsorted";
    mInfo["Thumbnail"] = "thumb_imgui.png";
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::preViewportUpdate(const RenderTargetViewportEvent& evt)
{
    if (!evt.source->getOverlaysEnabled()) {
        return;
    }
    if (!mTrayMgr->getTraysLayer()->isVisible()) {
        return;
    }

    ImGuiOverlay::NewFrame();

    Render();
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::Render()
{
    for (auto& render : mRenders) {
        render->Render();
    }
    //###
    mMainForm.Render();

    static bool show = true;
    if (show) {
        ImGui::ShowDemoWindow(&show);
    }
    //###
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::keyPressed(const KeyboardEvent& evt)
{
    return mListenerChain.keyPressed(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::keyReleased(const KeyboardEvent& evt)
{
    return mListenerChain.keyReleased(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::mouseMoved(const MouseMotionEvent& evt)
{
    return mListenerChain.mouseMoved(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::mouseWheelRolled(const MouseWheelEvent& evt)
{
    return mListenerChain.mouseWheelRolled(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::mousePressed(const MouseButtonEvent& evt)
{
    return mListenerChain.mousePressed(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::mouseReleased(const MouseButtonEvent& evt)
{
    return mListenerChain.mouseReleased(evt);
}
//----------------------------------------------------------------------------------------------
bool TImGuiRenderControl::textInput(const TextInputEvent& evt)
{
    return mListenerChain.textInput(evt);
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::setupContent(void)
{
    auto imguiOverlay = new ImGuiOverlay();
    imguiOverlay->setZOrder(300);
    imguiOverlay->show();
    OverlayManager::getSingleton().addOverlay(imguiOverlay); // now owned by overlaymgr

    /*
        NOTE:
        Custom apps will ASSERT on ImGuiOverlay::NewFrame() and not display any UI if they
        have not registered the overlay system by calling mSceneMgr->addRenderQueueListener(mOverlaySystem).
        OgreBites::SampleBrowser does this on behalf of the ImGuiDemo but custom applications will need to
        call this themselves.  See ApplicationContextBase::createDummyScene().
    */
    mWindow->addListener(this);

    mImguiListener.reset(new ImGuiInputListener());
    mListenerChain = InputListenerChain({mTrayMgr.get(), mImguiListener.get(), mCameraMan.get()});

    mTrayMgr->showCursor();
    mCameraMan->setStyle(OgreBites::CS_ORBIT);
    mCameraMan->setYawPitchDist(Degree(0), Degree(0), 15);
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::cleanupContent()
{
    OverlayManager::getSingleton().destroy("ImGuiOverlay");
    mWindow->removeListener(this);
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::AddRender(nsGraphicEngine::IRenderable* pRenderable)
{
    mRenders.insert(pRenderable);
}
//----------------------------------------------------------------------------------------------
void TImGuiRenderControl::RemoveRender(nsGraphicEngine::IRenderable* pRenderable)
{
    mRenders.erase(pRenderable);
}
//----------------------------------------------------------------------------------------------
const std::set<nsGraphicEngine::IRenderable*>* TImGuiRenderControl::GetRenders()
{
    return &mRenders;
}
//----------------------------------------------------------------------------------------------