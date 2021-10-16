/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockingStuffWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TDockingStuffWindow::TDockingStuffWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({500, 570});
    mWindow.SetPos({20, 20});

    mWindow.mMouseClickCB.Register(this, [&](nsGraphicEngine::TMouseButtonEvent event)
    {
        if (event.button != nsGraphicEngine::MouseButton::RIGHT) {
            return;
        }
        if (event.state != nsGraphicEngine::MouseState::RELEASED) {
            return;
        }

        auto mousePos = ImVec2(event.x, event.y);
        auto under = mWindow.GetChildByGlobalPos(mousePos);
        if (under == &mTextEdit) {
            mPopup.Open();
        }
    });

    mTextEdit.SetTitle("");
    mTextEdit.SetPos({0, 20});
    mTextEdit.SetSize({480, 550});

    mWindow.Add(&mTextEdit);

    mPopupNodes[0].SetTitle("Copy");
    mPopupNodes[1].SetTitle("Paste");
    mPopupNodes[2].SetTitle("Apply");

    mPopup.Add(&mPopupNodes[0]);
    mPopup.Add(&mPopupNodes[1]);
    mPopup.Add(&mPopupNodes[2]);

    mPopupNodes[0].onLeftClick.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = mTextEdit.GetText();
        ImGui::SetClipboardText(logLabelText.c_str());
    });

    mPopupNodes[1].onLeftClick.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = ImGui::GetClipboardText();
        mTextEdit.SetText(logLabelText);
    });
    mPopupNodes[2].onLeftClick.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = mTextEdit.GetText();
        ImGui::LoadIniSettingsFromMemory(logLabelText.c_str(), logLabelText.size());
    });

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mPopup);
}
//--------------------------------------------------------------------------------------------------------
