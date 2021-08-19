/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "TestFeature.h"

#include <ECS/include/Feature.h>

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

#include <imgui.h>

using namespace nsTest;
using namespace nsImGuiWidgets;
using namespace nsTornadoEngine;

TInitWidgets::TInitWidgets()
{

}
//------------------------------------------------------------------------------------------------
void TInitWidgets::Init()
{
    mWindow.SetTitle("Testing");
    mWindow.SetSize({500, 500});
    mWindow.SetPos({10, 10});

    mButton.SetCallback([](nsImGuiWidgets::TButton* p)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mButton.SetTitle("Exit");
    mButton.SetPos({30,30});
    mButton.SetSize({60, 20});

    mSelectionLabel.SetPos({30,60});
    mClickLabel.SetPos({30,90});

    mTreeView.SetPos({30,120});
    mTreeView.SetSize({400, 400});

    mWindow.Push(&mButton);
    mWindow.Push(&mSelectionLabel);
    mWindow.Push(&mClickLabel);
    mWindow.Push(&mTreeView);


    mTreeNodes[0].mId = "0";
    mTreeNodes[0].mLabel = "Scene0";

    mTreeNodes[1].mId = "1";
    mTreeNodes[1].mLabel = "Scene1";

    mTreeNodes[2].mParentId = "0";
    mTreeNodes[2].mId = "2";
    mTreeNodes[2].mLabel = "Camera";

    mTreeNodes[3].mParentId = "0";
    mTreeNodes[3].mId = "3";
    mTreeNodes[3].mLabel = "Light";

    mTreeNodes[4].mParentId = "1";
    mTreeNodes[4].mId = "4";
    mTreeNodes[4].mLabel = "Camera";

    mTreeNodes[5].mParentId = "1";
    mTreeNodes[5].mId = "5";
    mTreeNodes[5].mLabel = "Light";

    for (auto& node : mTreeNodes) {
        mTreeView.AddNode(&node);
    }

    mTreeView.onSelectionEvent.Register(&TInitWidgets::SelectNode, this);
    mTreeView.onClickEvent.Register(&TInitWidgets::ClickNode, this);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
}
//------------------------------------------------------------------------------------------------
void TInitWidgets::SelectNode(TTreeNode* pNode)
{
    if (mSelectionLabel.GetTextLength() > 50) {
        mSelectionLabel.SetText(pNode->mId.c_str());
    } else {
        mSelectionLabel.AppendText(pNode->mId.c_str());
    }
}
//------------------------------------------------------------------------------------------------
void TInitWidgets::ClickNode(const TTreeView::TClickEvent& pClickEvent)
{
    if (mClickLabel.GetTextLength() > 50) {
        mClickLabel.SetText(pClickEvent.pNode->mId.c_str());
    } else {
        mClickLabel.AppendText(pClickEvent.pNode->mId.c_str());
    }
}
//------------------------------------------------------------------------------------------------
void TTestFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    nsECSFramework::TFeature::SetEntMng(entMng);

    Add(&mInitWidgets);
}
//------------------------------------------------------------------------------------------------