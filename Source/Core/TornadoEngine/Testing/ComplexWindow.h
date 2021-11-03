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
#include <ImGuiWidgets/include/MainWindow.h>
#include <ImGuiWidgets/include/Window.h>
#include <ImGuiWidgets/include/Button.h>
#include <ImGuiWidgets/include/InputInt.h>
#include <ImGuiWidgets/include/InputMultiText.h>
#include <ImGuiWidgets/include/Label.h>
#include <ImGuiWidgets/include/TreeView.h>
#include <ImGuiWidgets/include/TreeNode.h>
#include <ImGuiWidgets/include/CheckBox.h>
#include <ImGuiWidgets/include/ComboBox.h>
#include <ImGuiWidgets/include/PopupNode.h>
#include <ImGuiWidgets/include/PopupMenu.h>

namespace nsTest
{
    struct DllExport TComplexWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TButton mButton;
        nsImGuiWidgets::TInputInt mSpinBox;
        nsImGuiWidgets::TInputMultiText mTextEdit;
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