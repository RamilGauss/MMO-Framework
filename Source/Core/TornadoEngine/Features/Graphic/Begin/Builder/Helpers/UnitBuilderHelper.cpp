/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"

#include "TornadoEngine/Components/Gui/Properties/PositionComponent.h"
#include "TornadoEngine/Components/Gui/Properties/SizeComponent.h"
#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Gui/Properties/LabelValueComponent.h"
#include "TornadoEngine/Components/Gui/Properties/SelectedTreeNodeGuidComponent.h"

#include "TornadoEngine/Components/Gui/Widgets/ButtonComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/MainWindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/TreeViewComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/MenuNodeComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/TreeNodeComponent.h"

using namespace nsGraphicWrapper;

void TUnitBuilderHelper::SetupSize(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TSize* pGeometry)
{
    pGeometry->mOnSizeCB.Register(nullptr, [entMng, eid, pGeometry]()
    {
        nsGuiWrapper::TSizeComponent sizeComponent;
        sizeComponent.x = pGeometry->GetSize().x;
        sizeComponent.y = pGeometry->GetSize().y;
        entMng->SetComponent(eid, sizeComponent);
    });
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupPosition(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TPosition* pGeometry)
{
    pGeometry->mOnPositionCB.Register(nullptr, [entMng, eid, pGeometry]()
    {
        nsGuiWrapper::TPositionComponent positionComponent;
        positionComponent.x = pGeometry->GetPosition().x;
        positionComponent.y = pGeometry->GetPosition().y;
        entMng->SetComponent(eid, positionComponent);
    });
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupWidget(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TWidget* pWidget)
{
    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pWidget->SetTitle(titleComponent->value);

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pWidget->SetPosition({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pWidget->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    if (pWidget->GetSubType() != nsImGuiWidgets::TWidget::SubType::UNIT) {
        return;
    }

    AddWidgetToParent(entMng, parentEid, pWidget);
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupLabel(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TLabel* pLabel)
{
    auto labelValueComponent = entMng->ViewComponent<nsGuiWrapper::TLabelValueComponent>(eid);
    pLabel->SetText(labelValueComponent->value);

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pLabel->SetPosition({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pLabel->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    AddWidgetToParent(entMng, parentEid, pLabel);
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupMenuNode(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TMenuNode* pMenuNode)
{
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pMenuNode->SetTitle(titleComponent->value);

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    auto isMainWindow = entMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (isMainWindow) {
        auto pMainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
        pMainWindowComponent->value->Add(pMenuNode);
        return;
    }
    auto isMenuNode = entMng->HasComponent<nsGuiWrapper::TMenuNodeComponent>(parentEid);
    if (isMenuNode) {
        auto pMenuNodeComponent = entMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(parentEid);
        pMenuNodeComponent->value->Add(pMenuNode);
        return;
    }

    BL_FIX_BUG();
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupTreeNode(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TTreeNode* pTreeNode)
{
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    pTreeNode->mStrId = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid)->value;
    pTreeNode->mParentId = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pTreeNode->SetTitle(titleComponent->value);

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    auto isTreeView = entMng->HasComponent<nsGuiWrapper::TTreeViewComponent>(parentEid);
    if (isTreeView) {
        auto pTreeViewComponent = entMng->ViewComponent<nsGuiWrapper::TTreeViewComponent>(parentEid);
        pTreeViewComponent->value->AddNode(pTreeNode);
        return;
    }

    auto isTreeNode = entMng->HasComponent<nsGuiWrapper::TTreeNodeComponent>(parentEid);
    if (isTreeNode) {
        auto pTreeNodeComponent = entMng->ViewComponent<nsGuiWrapper::TTreeNodeComponent>(parentEid);
        auto pTreeView = pTreeNodeComponent->value->GetTreeView();
        pTreeView->AddNode(pTreeNode);
        return;
    }

    BL_FIX_BUG();
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::SetupTreeView(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TTreeView* pTreeView)
{
    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pTreeView->SetPosition({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pTreeView->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    AddWidgetToParent(entMng, parentEid, pTreeView);

    pTreeView->mOnSelectionEventCB.Register(pTreeView, [eid, entMng](nsImGuiWidgets::TTreeNode* pSelectedTreeNode)
    {
        nsGuiWrapper::TSelectedTreeNodeGuidComponent selectedTreeNodeGuidComponent;
        selectedTreeNodeGuidComponent.value =
            pSelectedTreeNode == nullptr ? nsTornadoEngine::TGuidConstants::NONE : pSelectedTreeNode->mStrId;
        entMng->SetComponent(eid, selectedTreeNodeGuidComponent);
    });
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::AddWidgetToParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID parentEid,
    nsImGuiWidgets::TWidget* pWidget)
{
    auto isFrame = entMng->HasComponent<nsGuiWrapper::TFrameComponent>(parentEid);
    if (isFrame) {
        auto pFrameComponent = entMng->ViewComponent<nsGuiWrapper::TFrameComponent>(parentEid);
        pFrameComponent->value->Add(pWidget);
        return;
    }
    auto isDialog = entMng->HasComponent<nsGuiWrapper::TDialogComponent>(parentEid);
    if (isDialog) {
        auto pDialogComponent = entMng->ViewComponent<nsGuiWrapper::TDialogComponent>(parentEid);
        pDialogComponent->value->Add(pWidget);
        return;
    }
    auto isWindow = entMng->HasComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    if (isWindow) {
        auto pWindowComponent = entMng->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
        pWindowComponent->value->Add(pWidget);
        return;
    }
    auto isMainWindow = entMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (isMainWindow) {
        auto pMainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
        pMainWindowComponent->value->Add(pWidget);
        return;
    }

    BL_FIX_BUG();
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::UnlinkParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid, 
    nsImGuiWidgets::TWidget* pWidget)
{
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);

    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    auto frameComponent = entMng->ViewComponent<nsGuiWrapper::TFrameComponent>(parentEid);
    if (frameComponent) {
        frameComponent->value->Replace(pWidget);
    }
    auto windowComponent = entMng->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    if (windowComponent) {
        windowComponent->value->Replace(pWidget);
    }
    auto dialogComponent = entMng->ViewComponent<nsGuiWrapper::TDialogComponent>(parentEid);
    if (dialogComponent) {
        dialogComponent->value->Replace(pWidget);
    }
    auto mainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (mainWindowComponent) {
        mainWindowComponent->value->Replace(pWidget);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::UnlinkMenuNode(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
    nsImGuiWidgets::TMenuNode* pMenuNode)
{
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);

    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    auto menuNodeComponent = entMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(parentEid);
    if (menuNodeComponent) {
        menuNodeComponent->value->Replace(pMenuNode);
    }
    auto mainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (mainWindowComponent) {
        mainWindowComponent->value->Replace(pMenuNode);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::UnlinkTreeNode(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
    nsImGuiWidgets::TTreeNode* pTreeNode)
{
    auto treeView = pTreeNode->GetTreeView();
    if (treeView) {
        treeView->RemoveNode(pTreeNode->mStrId);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
