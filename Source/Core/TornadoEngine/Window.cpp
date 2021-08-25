/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Window.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"


using namespace nsTest;

TWindow::TWindow()
{
    mWindow.SetTitle("Testing");
    mWindow.SetSize({500, 500});
    mWindow.SetPos({10, 10});

    mButton.SetCallback([](nsImGuiWidgets::TButton* p)
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
        auto under = mTreeView.GetUnderMouseChild(mousePos);
        if (under == &mTreeView) {
            mLogLabel.AppendText("Don't beat me!");
        } else if (under != nullptr) {
            if (under->GetSubType() == nsImGuiWidgets::TWidget::SubType::NODE) {
                mLogLabel.AppendText("Node \"");
                mLogLabel.AppendText(((nsImGuiWidgets::TTreeNode*) under)->mLabel.c_str());
                mLogLabel.AppendText("\", ");
            }
        }
    };
    //mWindow.mMouseClickCB.Register(mouseClickFunc);
    mTreeView.mMouseClickCB.Register(mouseClickFunc);

    mButton.SetTitle("Exit");
    mButton.SetPos({30,30});
    mButton.SetSize({60, 20});

    mLogLabel.SetPos({90,30});
    mLogLabel.SetSize({100,20});

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

    mTreeView.SetPos({30,150});
    mTreeView.SetSize({300, 300});


    mWindow.Add(&mButton);
    mWindow.Add(&mSpinBox);
    mWindow.Add(&mComboBox);
    mWindow.Add(&mCheckBox);
    mWindow.Add(&mTextEdit);
    mWindow.Add(&mTreeView);

    mTreeNodes[0].mStrId = "0";
    mTreeNodes[0].mLabel = "Scene0";

    mTreeNodes[1].mStrId = "1";
    mTreeNodes[1].mLabel = "Scene1";

    mTreeNodes[2].mParentId = "0";
    mTreeNodes[2].mStrId = "2";
    mTreeNodes[2].mLabel = "Camera";

    mTreeNodes[3].mParentId = "0";
    mTreeNodes[3].mStrId = "3";
    mTreeNodes[3].mLabel = "Light";

    mTreeNodes[4].mParentId = "1";
    mTreeNodes[4].mStrId = "4";
    mTreeNodes[4].mLabel = "Camera";

    mTreeNodes[5].mParentId = "1";
    mTreeNodes[5].mStrId = "5";
    mTreeNodes[5].mLabel = "Light";

    for (auto& node : mTreeNodes) {
        mTreeView.AddNode(&node);
    }

    mTreeView.onSelectionEvent.Register([&](nsImGuiWidgets::TTreeNode* pNode)
    {
        auto str = "S" + pNode->mStrId + ", ";
        if (mLogLabel.GetTextLength() > 1000) {
            mLogLabel.SetText(str.c_str());
        } else {
            mLogLabel.AppendText(str.c_str());
        }
    });

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
}
