/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "UnitBuilderHelper.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "PositionComponent.h"
#include "SizeComponent.h"
#include "TitleComponent.h"

#include "MainWindowComponent.h"
#include "WindowComponent.h"
#include "DialogComponent.h"
#include "FrameComponent.h"
#include "MenuNodeComponent.h"

using namespace nsGraphicWrapper;

void TUnitBuilderHelper::SetupWidget(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, nsImGuiWidgets::TWidget* pWidget)
{
    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pWidget->SetTitle(titleComponent->value);

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pWidget->SetPos({(float) posComponent->x,(float) posComponent->y});

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

    auto menuNodeComponent = entMng->ViewComponent<nsGuiWrapper::TMenuNodeComponent>(parentEid);
    if (menuNodeComponent) {
        menuNodeComponent->value->Replace(pMenuNode);
    }
    auto windowComponent = entMng->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    if (windowComponent) {
        windowComponent->value->Replace(pMenuNode);
    }
    auto dialogComponent = entMng->ViewComponent<nsGuiWrapper::TDialogComponent>(parentEid);
    if (dialogComponent) {
        dialogComponent->value->Replace(pMenuNode);
    }
    auto mainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (mainWindowComponent) {
        mainWindowComponent->value->Replace(pMenuNode);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
