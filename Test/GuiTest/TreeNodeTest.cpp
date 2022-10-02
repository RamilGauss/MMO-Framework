/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeTest.h"

using namespace nsImGuiWidgets;

namespace nsTest
{
    void TTreeNodeTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        mWindow.SetTitle("TreeNodeTest");

        mWindow.SetSize({ 200, 200 });
        mWindow.SetPos({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 500, 500 });

        mTreeView.SetLeftAnchor({ true, 10 });
        mTreeView.SetRightAnchor({ true, 10 });
        mTreeView.SetTopAnchor({ true, 40 });
        mTreeView.SetBottomAnchor({ true, 10 });

        mWindow.Add(&mTreeView);

        auto pNode = new TTreeNode();
        pNode->SetTitle("asdasd");
        pNode->mStrId = "0";
        pNode->mParentId = "root";
        pNode->SetColor({1.0f, 0.1f, 0.1f, 1.0f});

        mTreeView.AddNode(pNode);

        pNode = new TTreeNode();
        pNode->SetTitle("asdasd");
        pNode->mStrId = "1";
        pNode->mParentId = "0";
        pNode->SetColor({ 0.1f, 1.0f, 0.1f, 1.0f });

        mTreeView.AddNode(pNode);

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
    void TTreeNodeTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
}