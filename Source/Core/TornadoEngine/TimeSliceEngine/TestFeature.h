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
#include <ImGuiWidgets/Label.h>
#include <ImGuiWidgets/TreeView.h>
#include <ImGuiWidgets/TreeNode.h>


namespace nsTest
{
    class DllExport TInitWidgets : public nsECSFramework::TInitSystem
    {
        nsImGuiWidgets::TWindow mWindow;
        nsImGuiWidgets::TButton mButton;
        nsImGuiWidgets::TLabel mSelectionLabel;
        nsImGuiWidgets::TLabel mClickLabel;

        nsImGuiWidgets::TTreeView mTreeView;

        nsImGuiWidgets::TTreeNode mTreeNodes[6];

    public:
        TInitWidgets();
        void Init() override;
    private:
        void SelectNode(nsImGuiWidgets::TTreeNode* pNode);
        void ClickNode(const nsImGuiWidgets::TTreeView::TClickEvent& pClickEvent);
    };


    class DllExport TTestFeature : public nsECSFramework::TFeature
    {
        TInitWidgets mInitWidgets;
    public:
        void SetEntMng(nsECSFramework::TEntityManager* entMng) override;
    };
}