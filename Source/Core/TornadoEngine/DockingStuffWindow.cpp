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
    mWindow.SetSize({500, 900});
    mWindow.SetPos({20, 20});

    mWindow.mMouseClickCB.Register([&](nsGraphicEngine::TMouseButtonEvent event)
    {
        if (event.button != nsGraphicEngine::MouseButton::RIGHT) {
            return;
        }
        if (event.state != nsGraphicEngine::MouseState::RELEASED) {
            return;
        }

        auto mousePos = ImVec2(event.x, event.y);
        auto under = mWindow.GetUnderMouseChild(mousePos);
        if (under == &mTextEdit) {
            mPopup.Open();
        }
    });

    mTextEdit.SetTitle("TextEdit");
    mTextEdit.SetPos({30, 120});
    mTextEdit.SetSize({60, 20});

    mWindow.Add(&mTextEdit);

    mPopupNodes[0].mLabel = "Copy";
    mPopupNodes[1].mLabel = "Paste";
    mPopupNodes[2].mLabel = "Apply";

    mPopup.Add(&mPopupNodes[0]);
    mPopup.Add(&mPopupNodes[1]);
    mPopup.Add(&mPopupNodes[2]);

    mPopupNodes[0].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = mTextEdit.GetText();
        ImGui::SetClipboardText(logLabelText.c_str());
    });

    mPopupNodes[1].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = ImGui::GetClipboardText();
        mTextEdit.SetText(logLabelText);
    });
    mPopupNodes[2].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = mTextEdit.GetText();
        ImGui::LoadIniSettingsFromMemory(logLabelText.c_str(), logLabelText.size());
    });

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mPopup);
}
//--------------------------------------------------------------------------------------------------------
