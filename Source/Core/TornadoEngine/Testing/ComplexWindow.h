/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/Feature.h>
#include <ImGuiWidgets/MainWindow.h>
#include <ImGuiWidgets/Window.h>
#include <ImGuiWidgets/Button.h>
#include <ImGuiWidgets/InputInt.h>
#include <ImGuiWidgets/InputText.h>
#include <ImGuiWidgets/Label.h>
#include <ImGuiWidgets/TreeView.h>
#include <ImGuiWidgets/TreeNode.h>
#include <ImGuiWidgets/CheckBox.h>
#include <ImGuiWidgets/ComboBox.h>
#include <ImGuiWidgets/PopupNode.h>
#include <ImGuiWidgets/PopupMenu.h>

namespace nsTest
{
    struct DllExport TComplexWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TButton mButton;
        nsImGuiWidgets::TInputInt mSpinBox;
        nsImGuiWidgets::TInputText mTextEdit;
        nsImGuiWidgets::TCheckBox mCheckBox;
        nsImGuiWidgets::TComboBox mComboBox;
        nsImGuiWidgets::TLabel mLogLabel;

        nsImGuiWidgets::TTreeNode mTreeNodes[6];
        nsImGuiWidgets::TTreeView mTreeView;

        nsImGuiWidgets::TPopupNode mPopupNodes[6];
        nsImGuiWidgets::TPopupMenu mPopup;

        nsImGuiWidgets::TPopupNode mLabelPopupNodes[3];
        nsImGuiWidgets::TPopupMenu mLabelPopup;

        TComplexWindow(std::string name);
    };
}