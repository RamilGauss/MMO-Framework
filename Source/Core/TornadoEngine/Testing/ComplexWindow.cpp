/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComplexWindow.h"

#include "Modules.h"
#include "GraphicEngineModule.h"
#include "StopAccessor.h"


using namespace nsTest;

TComplexWindow::TComplexWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({500, 900});
    mWindow.SetPos({20, 20});

    mButton.mOnClickCB.Register(this, [](nsImGuiWidgets::TButton* p)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    auto mouseClickFunc = [&](nsGraphicEngine::TMouseButtonEvent event)
    {
        if (event.button != nsGraphicEngine::MouseButton::RIGHT) {
            return;
        }
        if (event.state != nsGraphicEngine::MouseState::RELEASED) {
            return;
        }

        auto mousePos = ImVec2(event.x, event.y);
        auto under = mTreeView.GetChildByGlobalPos(mousePos);
        if (under == &mTreeView) {
            mLogLabel.AppendText("Don't beat me!");
        } else if (under != nullptr) {
            if (under->GetSubType() == nsImGuiWidgets::TWidget::SubType::NODE) {
                mLogLabel.AppendText("Node \"");
                mLogLabel.AppendText(((nsImGuiWidgets::TTreeNode*) under)->GetTitle().c_str());
                mLogLabel.AppendText("\", ");

                mPopup.Open();
            }
        }
    };
    mTreeView.mOnMouseClickCB.Register(this, mouseClickFunc);

    mWindow.mOnMouseClickCB.Register(this, [&](nsGraphicEngine::TMouseButtonEvent event)
    {
        if (event.button != nsGraphicEngine::MouseButton::RIGHT) {
            return;
        }
        if (event.state != nsGraphicEngine::MouseState::RELEASED) {
            return;
        }

        auto mousePos = ImVec2(event.x, event.y);
        auto under = mWindow.GetChildByGlobalPos(mousePos);
        if (under == &mLogLabel) {
            mLabelPopup.Open();
        }
    });

    mButton.SetTitle("Exit");
    mButton.SetPos({30,30});
    mButton.SetSize({60, 20});

    mSpinBox.SetTitle("SpinBox");
    mSpinBox.SetPos({30, 60});
    mSpinBox.SetSize({60, 20});

    mComboBox.SetTitle("ComboBox");
    mComboBox.SetPos({30, 90});
    mComboBox.SetSize({60, 20});
    mComboBox.SetItems({"A", "B", "C"});

    mTextEdit.SetTitle("TextEdit");
    mTextEdit.SetPos({30, 120});
    mTextEdit.SetSize({60, 20});

    mCheckBox.SetTitle("CheckBox");
    mCheckBox.SetPos({30, 150});
    mCheckBox.SetSize({60, 20});

    mTreeView.SetPos({30,180});
    mTreeView.SetSize({150, 120});

    mLogLabel.SetPos({30,300});
    mLogLabel.SetSize({400,400});

    mWindow.Add(&mButton);
    mWindow.Add(&mSpinBox);
    mWindow.Add(&mComboBox);
    mWindow.Add(&mCheckBox);
    mWindow.Add(&mTextEdit);
    mWindow.Add(&mTreeView);
    mWindow.Add(&mLogLabel);

    mTreeNodes[0].mStrId = "0";
    mTreeNodes[0].SetTitle("Scene0");

    mTreeNodes[1].mStrId = "1";
    mTreeNodes[1].SetTitle("Scene1");

    mTreeNodes[2].mParentId = "0";
    mTreeNodes[2].mStrId = "2";
    mTreeNodes[2].SetTitle("Camera");

    mTreeNodes[3].mParentId = "0";
    mTreeNodes[3].mStrId = "3";
    mTreeNodes[3].SetTitle("Light");

    mTreeNodes[4].mParentId = "1";
    mTreeNodes[4].mStrId = "4";
    mTreeNodes[4].SetTitle("Camera");

    mTreeNodes[5].mParentId = "1";
    mTreeNodes[5].mStrId = "5";
    mTreeNodes[5].SetTitle("Light");

    for (auto& node : mTreeNodes) {
        mTreeView.AddNode(&node);
    }

    mTreeView.mOnSelectionEventCB.Register(this, [&](nsImGuiWidgets::TTreeNode* pNode)
    {
        auto str = "S" + pNode->mStrId + ", ";
        if (mLogLabel.GetTextLength() > 1000) {
            mLogLabel.SetText(str.c_str());
        } else {
            mLogLabel.AppendText(str.c_str());
        }
    });

    mPopupNodes[0].SetTitle("Main");
    mPopupNodes[1].SetTitle("Open");
    mPopupNodes[2].SetTitle("Save");

    mPopupNodes[3].SetTitle("Other");
    mPopupNodes[4].SetTitle("Make");

    mPopupNodes[5].SetTitle("Exit");
    mPopupNodes[5].mOnLeftClickCB.Register(this, [](nsImGuiWidgets::TNode* pNode)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mPopupNodes[0].Add(&mPopupNodes[1]);
    mPopupNodes[0].Add(&mPopupNodes[2]);

    mPopupNodes[3].Add(&mPopupNodes[4]);

    mPopup.Add(&mPopupNodes[0]);
    mPopup.Add(&mPopupNodes[3]);
    mPopup.Add(&mPopupNodes[5]);

    mLabelPopupNodes[0].SetTitle("Copy");
    mLabelPopupNodes[0].mOnLeftClickCB.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = mLogLabel.GetText();
        ImGui::SetClipboardText(logLabelText.c_str());
    });

    mLabelPopupNodes[1].SetTitle("Paste");
    mLabelPopupNodes[1].mOnLeftClickCB.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        auto logLabelText = ImGui::GetClipboardText();
        mLogLabel.SetText(logLabelText);
    });
    mLabelPopupNodes[2].SetTitle("Clear");
    mLabelPopupNodes[2].mOnLeftClickCB.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        mLogLabel.SetText("");
    });

    mLabelPopup.Add(&mLabelPopupNodes[0]);
    mLabelPopup.Add(&mLabelPopupNodes[1]);
    mLabelPopup.Add(&mLabelPopupNodes[2]);


    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mPopup);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mLabelPopup);
}
//--------------------------------------------------------------------------------------------------------
